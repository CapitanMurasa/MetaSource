#include "shapes.h"

Vertex square[] = {
    // Face 1: Front
    { glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f) },
    { glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 0.0f) },
    { glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 1.0f) },
    { glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 1.0f) },
    { glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 1.0f) },
    { glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f) },

    // Face 2: Back
    { glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 0.0f) },
    { glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(1.0f, 0.0f) },
    { glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(1.0f, 1.0f) },
    { glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(1.0f, 1.0f) },
    { glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 1.0f) },
    { glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 0.0f) },

    // Face 3: Left
    { glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 0.0f) },
    { glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 1.0f) },
    { glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 1.0f) },
    { glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 1.0f) },
    { glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f) },
    { glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 0.0f) },

    // Face 4: Right
    { glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec2(1.0f, 0.0f) },
    { glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec2(1.0f, 1.0f) },
    { glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec2(0.0f, 1.0f) },
    { glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec2(0.0f, 1.0f) },
    { glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec2(0.0f, 0.0f) },
    { glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec2(1.0f, 0.0f) },

    // Face 5: Top
    { glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(0.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f) },
    { glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec3(0.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f) },
    { glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec3(0.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f) },
    { glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec3(0.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f) },
    { glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(0.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f) },
    { glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(0.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f) },

    // Face 6: Bottom
    { glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 0.0f, 1.0f), glm::vec2(0.0f, 1.0f) },
    { glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 0.0f, 1.0f), glm::vec2(1.0f, 1.0f) },
    { glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec3(1.0f, 0.0f, 1.0f), glm::vec2(1.0f, 0.0f) },
    { glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec3(1.0f, 0.0f, 1.0f), glm::vec2(1.0f, 0.0f) },
    { glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(1.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f) },
    { glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 0.0f, 1.0f), glm::vec2(0.0f, 1.0f) }
};