#include "../headers/Application.h"
#include "../headers/Shader.h"
#include "../headers/SphereObject.h"
#include "../headers/CubeObject.h"
#include <glm/gtc/type_ptr.hpp>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <iostream>
#include <memory>

static Application* g_App = nullptr;
static std::unique_ptr<Shader> gPlanetShader;

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
    if (g_App) {
        static float lastX = 400, lastY = 300;
        static bool firstMouse = true;
        if (firstMouse) { lastX = (float)xpos; lastY = (float)ypos; firstMouse = false; }
        float xoffset = (float)xpos - lastX;
        float yoffset = lastY - (float)ypos;
        lastX = (float)xpos;
        lastY = (float)ypos;
        g_App->ProcessMouseMovement(xoffset, yoffset);
    }
}

static unsigned int LoadTexture(const char* path) {
    unsigned int textureID = 0;
    glGenTextures(1, &textureID);
    int width = 0, height = 0, nrComponents = 0;
    unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);
    if (!data) {
        std::cout << "Failed: " << path << std::endl;
        return textureID;
    }
    GLenum format = (nrComponents == 1) ? GL_RED : (nrComponents == 3 ? GL_RGB : GL_RGBA);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    stbi_image_free(data);
    std::cout << "Loaded: " << path << std::endl;
    return textureID;
}

Application::Application() : camera(glm::vec3(0.0f, 18.0f, 45.0f)) {
    g_App = this;
}

Application::~Application() {
    Shutdown();
}

void Application::ProcessMouseMovement(float xoffset, float yoffset) {
    camera.ProcessMouseMovement(xoffset, yoffset);
}

bool Application::Initialise(int width, int height, const char* title) {
    windowWidth = width;
    windowHeight = height;
    if (!glfwInit()) {
        std::cout << "Failed to initialize GLFW" << std::endl;
        return false;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window) {
        std::cout << "Failed to create window" << std::endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return false;
    }
    glEnable(GL_DEPTH_TEST);
    glViewport(0, 0, width, height);
    gPlanetShader = std::make_unique<Shader>("shaders/planet.vert", "shaders/planet.frag");
    gPlanetShader->use();
    glUniform1i(glGetUniformLocation(gPlanetShader->ID, "ourTexture"), 0);
    shaderProgram = gPlanetShader->ID;
    CreateScene();
    std::cout << "Initialization complete!" << std::endl;
    return true;
}

void Application::CreateScene() {
    std::cout << "Loading textures..." << std::endl;
    sunTexture = LoadTexture("textures/sun.jpg");
    mercuryTexture = LoadTexture("textures/mercury.jpg");
    venusTexture = LoadTexture("textures/venus.jpg");
    earthTexture = LoadTexture("textures/earth.jpg");
    marsTexture = LoadTexture("textures/mars.jpg");
    moonTexture = LoadTexture("textures/moon.jpg");

    auto floor = std::make_unique<CubeObject>(2.0f);
    floor->Initialize(shaderProgram, 0);
    floor->SetPosition(glm::vec3(0.0f, -6.0f, 0.0f));
    floor->SetScale(glm::vec3(70.0f, 0.2f, 70.0f));
    graphicsObjects.push_back(std::move(floor));

    auto sunObj = std::make_unique<SphereObject>(2.5f, 48, 24);
    sunObj->Initialize(shaderProgram, sunTexture);
    sunObj->SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));
    sunObj->SetSpinSpeed(0.5f);
    sun = sunObj.get();
    graphicsObjects.push_back(std::move(sunObj));

    auto merObj = std::make_unique<SphereObject>(1.0f, 24, 12);
    merObj->Initialize(shaderProgram, mercuryTexture);
    merObj->SetOrbitCenter(glm::vec3(0.0f, 0.0f, 0.0f));
    merObj->SetOrbitRadius(8.0f);
    merObj->SetOrbitSpeed(1.2f);
    mercury = merObj.get();
    graphicsObjects.push_back(std::move(merObj));

    auto venObj = std::make_unique<SphereObject>(1.2f, 24, 12);
    venObj->Initialize(shaderProgram, venusTexture);
    venObj->SetOrbitCenter(glm::vec3(0.0f, 0.0f, 0.0f));
    venObj->SetOrbitRadius(12.0f);
    venObj->SetOrbitSpeed(0.9f);
    venus = venObj.get();
    graphicsObjects.push_back(std::move(venObj));

    auto earthObj = std::make_unique<SphereObject>(1.4f, 36, 18);
    earthObj->Initialize(shaderProgram, earthTexture);
    earthObj->SetOrbitCenter(glm::vec3(0.0f, 0.0f, 0.0f));
    earthObj->SetOrbitRadius(16.5f);
    earthObj->SetOrbitSpeed(0.7f);
    earth = earthObj.get();
    graphicsObjects.push_back(std::move(earthObj));

    auto marObj = std::make_unique<SphereObject>(1.2f, 24, 12);
    marObj->Initialize(shaderProgram, marsTexture);
    marObj->SetOrbitCenter(glm::vec3(0.0f, 0.0f, 0.0f));
    marObj->SetOrbitRadius(21.0f);
    marObj->SetOrbitSpeed(0.5f);
    mars = marObj.get();
    graphicsObjects.push_back(std::move(marObj));

    auto moonObj = std::make_unique<SphereObject>(0.7f, 24, 12);
    moonObj->Initialize(shaderProgram, moonTexture);
    moonObj->SetParent(earth);
    moonObj->SetOrbitRadius(3.0f);
    moonObj->SetOrbitSpeed(2.0f);
    moon = moonObj.get();
    graphicsObjects.push_back(std::move(moonObj));
}

void Application::ProcessInput(float dt) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) camera.ProcessKeyboard(FORWARD, dt);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) camera.ProcessKeyboard(BACKWARD, dt);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) camera.ProcessKeyboard(LEFT, dt);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) camera.ProcessKeyboard(RIGHT, dt);
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS && sun) {
        float newSpeed = sun->GetSpinSpeed() + 0.5f * dt;
        if (newSpeed > 5.0f) newSpeed = 5.0f;
        sun->SetSpinSpeed(newSpeed);
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS && sun) {
        float newSpeed = sun->GetSpinSpeed() - 0.5f * dt;
        if (newSpeed < 0) newSpeed = 0;
        sun->SetSpinSpeed(newSpeed);
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS && moon) {
        float newSpeed = moon->GetOrbitSpeed() + 0.5f * dt;
        if (newSpeed > 8.0f) newSpeed = 8.0f;
        moon->SetOrbitSpeed(newSpeed);
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS && moon) {
        float newSpeed = moon->GetOrbitSpeed() - 0.5f * dt;
        if (newSpeed < 0) newSpeed = 0;
        moon->SetOrbitSpeed(newSpeed);
    }
}

void Application::Update(float dt) {
    for (auto& obj : graphicsObjects) obj->Update(dt);
}

void Application::Render() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    gPlanetShader->use();
    glm::mat4 view = camera.GetViewMatrix();
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)windowWidth / windowHeight, 0.1f, 100.0f);
    int viewLoc = glGetUniformLocation(gPlanetShader->ID, "view");
    int projLoc = glGetUniformLocation(gPlanetShader->ID, "projection");
    int modelLoc = glGetUniformLocation(gPlanetShader->ID, "model");
    int lightDirLoc = glGetUniformLocation(gPlanetShader->ID, "lightDir");
    int texLoc = glGetUniformLocation(gPlanetShader->ID, "ourTexture");
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
    glm::vec3 lightDir = glm::vec3(-0.5f, -1.0f, -0.3f);
    glUniform3fv(lightDirLoc, 1, &lightDir[0]);
    glUniform1i(texLoc, 0);
    for (auto& obj : graphicsObjects) {
        glm::mat4 model = obj->GetTransform();
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        obj->Draw();
    }
}

void Application::Run() {
     
    while (!glfwWindowShouldClose(window)) {
        float currentFrame = (float)glfwGetTime();
        float deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        ProcessInput(deltaTime);
        Update(deltaTime);
        Render();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Application::Shutdown() {
    for (auto& obj : graphicsObjects) obj->Cleanup();
    graphicsObjects.clear();
    if (sunTexture) glDeleteTextures(1, &sunTexture);
    if (mercuryTexture) glDeleteTextures(1, &mercuryTexture);
    if (venusTexture) glDeleteTextures(1, &venusTexture);
    if (earthTexture) glDeleteTextures(1, &earthTexture);
    if (marsTexture) glDeleteTextures(1, &marsTexture);
    if (moonTexture) glDeleteTextures(1, &moonTexture);
    gPlanetShader.reset();
    if (window) glfwDestroyWindow(window);
    glfwTerminate();
}