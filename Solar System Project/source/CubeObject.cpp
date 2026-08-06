#include "../headers/CubeObject.h"
#include <glm/gtc/type_ptr.hpp>

CubeObject::CubeObject(float s) : size(s) {}

CubeObject::~CubeObject() {
    Cleanup();
}

void CubeObject::SetColor(glm::vec3 col) { 
    color = col; 
}

void CubeObject::GenerateCube() {
    float half = size / 2.0f;
    
    CubeVertex verts[] = {
        {{-half, -half,  half}, {0,0,1}, {0,0}},
        {{ half, -half,  half}, {0,0,1}, {1,0}},
        {{ half,  half,  half}, {0,0,1}, {1,1}},
        {{-half,  half,  half}, {0,0,1}, {0,1}},
        {{-half, -half, -half}, {0,0,-1}, {0,0}},
        {{-half,  half, -half}, {0,0,-1}, {0,1}},
        {{ half,  half, -half}, {0,0,-1}, {1,1}},
        {{ half, -half, -half}, {0,0,-1}, {1,0}},
        {{-half,  half, -half}, {0,1,0}, {0,0}},
        {{-half,  half,  half}, {0,1,0}, {0,1}},
        {{ half,  half,  half}, {0,1,0}, {1,1}},
        {{ half,  half, -half}, {0,1,0}, {1,0}},
        {{-half, -half, -half}, {0,-1,0}, {0,0}},
        {{ half, -half, -half}, {0,-1,0}, {1,0}},
        {{ half, -half,  half}, {0,-1,0}, {1,1}},
        {{-half, -half,  half}, {0,-1,0}, {0,1}},
        {{ half, -half, -half}, {1,0,0}, {0,0}},
        {{ half,  half, -half}, {1,0,0}, {0,1}},
        {{ half,  half,  half}, {1,0,0}, {1,1}},
        {{ half, -half,  half}, {1,0,0}, {1,0}},
        {{-half, -half, -half}, {-1,0,0}, {0,0}},
        {{-half, -half,  half}, {-1,0,0}, {1,0}},
        {{-half,  half,  half}, {-1,0,0}, {1,1}},
        {{-half,  half, -half}, {-1,0,0}, {0,1}}
    };
    
    for(int i = 0; i < 24; i++) {
        vertices.push_back(verts[i]);
    }
    
    unsigned int inds[] = {
        0,1,2, 0,2,3, 4,5,6, 4,6,7,
        8,9,10, 8,10,11, 12,13,14, 12,14,15,
        16,17,18, 16,18,19, 20,21,22, 20,22,23
    };
    
    for(int i = 0; i < 36; i++) {
        indices.push_back(inds[i]);
    }
    
    indexCount = indices.size();
}

bool CubeObject::Initialize(GLuint shader, GLuint texture) {
    shaderID = shader;
    textureID = texture;
    
    GenerateCube();
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &IBO);
    
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(CubeVertex), 
                 vertices.data(), GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), 
                 indices.data(), GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(CubeVertex), (void*)0);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(CubeVertex), 
                          (void*)offsetof(CubeVertex, normal));
    glEnableVertexAttribArray(1);
    
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(CubeVertex), 
                          (void*)offsetof(CubeVertex, texCoord));
    glEnableVertexAttribArray(2);
    
    glBindVertexArray(0);
    
    return true;
}

void CubeObject::Update(float deltaTime) {
    glm::mat4 trans = glm::translate(glm::mat4(1.0f), position);
    glm::mat4 rot = glm::rotate(glm::mat4(1.0f), rotationAngle, rotationAxis);
    glm::mat4 sc = glm::scale(glm::mat4(1.0f), scaleVec);
    transform = trans * rot * sc;
}

void CubeObject::Draw() {
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

void CubeObject::Cleanup() {
    if (IBO) { glDeleteBuffers(1, &IBO); IBO = 0; }
    if (VBO) { glDeleteBuffers(1, &VBO); VBO = 0; }
    if (VAO) { glDeleteVertexArrays(1, &VAO); VAO = 0; }
}

void CubeObject::SetPosition(glm::vec3 pos) { position = pos; }
void CubeObject::SetScale(glm::vec3 scale) { scaleVec = scale; }
void CubeObject::SetRotation(float angle, glm::vec3 axis) { 
    rotationAngle = angle; 
    rotationAxis = axis; 
}