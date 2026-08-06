#include "../headers/SphereObject.h"
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

SphereObject::SphereObject(float r, int sectors, int stacks) 
    : radius(r), sectors(sectors), stacks(stacks) {
    sphere = new Sphere(r, sectors, stacks, true, 3);
}

SphereObject::~SphereObject() {
    Cleanup();
    delete sphere;
}

bool SphereObject::Initialize(GLuint shader, GLuint texture) {
    shaderID = shader;
    textureID = texture;
    
    const float* vertices = sphere->getInterleavedVertices();
    int vertexCount = sphere->getInterleavedVertexCount();
    const unsigned int* indicesPtr = sphere->getIndices();
    indexCount = sphere->getIndexCount();
    
    int stride = 8 * sizeof(float);
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &IBO);
    
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertexCount * stride, vertices, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(unsigned int), indicesPtr, GL_STATIC_DRAW);
    
    // Position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void*)0);
    glEnableVertexAttribArray(0);
    
    // Normal
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    
    // TexCoord
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, stride, (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
    
    glBindVertexArray(0);
    
    return true;
}

void SphereObject::UpdateTransform(float deltaTime) {
    orbitAngle += orbitSpeed * deltaTime;
    spinAngle += spinSpeed * deltaTime;
    
    glm::vec3 finalPosition;
    
    if (parent != nullptr) {
        glm::vec3 parentPos = parent->GetPosition();
        float orbitX = orbitRadius * cosf(orbitAngle);
        float orbitZ = orbitRadius * sinf(orbitAngle);
        finalPosition = parentPos + glm::vec3(orbitX, 0.0f, orbitZ);
    } else {
        float orbitX = orbitCenter.x + orbitRadius * cosf(orbitAngle);
        float orbitZ = orbitCenter.z + orbitRadius * sinf(orbitAngle);
        finalPosition = glm::vec3(orbitX, 0.0f, orbitZ);
    }
    
    glm::mat4 translation = glm::translate(glm::mat4(1.0f), finalPosition);
    glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), spinAngle, glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(radius));
    
    transform = translation * rotation * scale;
}

void SphereObject::Update(float deltaTime) {
    UpdateTransform(deltaTime);
}

void SphereObject::Draw() {
    glUseProgram(shaderID);
    
    if (textureID != 0) {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, textureID);
    }
    
    GLint modelLoc = glGetUniformLocation(shaderID, "model");
    if (modelLoc != -1) {
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(transform));
    }
    
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void SphereObject::Cleanup() {
    if (IBO) { glDeleteBuffers(1, &IBO); IBO = 0; }
    if (VBO) { glDeleteBuffers(1, &VBO); VBO = 0; }
    if (VAO) { glDeleteVertexArrays(1, &VAO); VAO = 0; }
}

void SphereObject::SetOrbitCenter(glm::vec3 center) { orbitCenter = center; }
void SphereObject::SetOrbitRadius(float radius) { orbitRadius = radius; }
void SphereObject::SetOrbitSpeed(float speed) { orbitSpeed = speed; }
float SphereObject::GetOrbitSpeed() const { return orbitSpeed; }

void SphereObject::SetSpinSpeed(float speed) { spinSpeed = speed; }
float SphereObject::GetSpinSpeed() const { return spinSpeed; }

void SphereObject::SetPosition(glm::vec3 pos) { orbitCenter = pos; orbitRadius = 0; }

glm::vec3 SphereObject::GetPosition() const { 
    if (parent != nullptr) {
        glm::vec3 parentPos = parent->GetPosition();
        float x = parentPos.x + orbitRadius * cosf(orbitAngle);
        float z = parentPos.z + orbitRadius * sinf(orbitAngle);
        return glm::vec3(x, 0.0f, z);
    } else {
        float x = orbitCenter.x + orbitRadius * cosf(orbitAngle);
        float z = orbitCenter.z + orbitRadius * sinf(orbitAngle);
        return glm::vec3(x, 0.0f, z);
    }
}

void SphereObject::SetParent(SphereObject* p) { parent = p; }