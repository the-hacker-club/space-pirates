
add_library(
    WarpEngine
    Camera.h
    Camera.cpp
    GameWindow.h
    GameWindow.cpp
    glad.c
    glslLoader.h
    glslLoader.cpp
    Level.h
    Level.cpp
    ObjectMesh.h
    ObjectMesh.cpp
    Shader.h
    Shader.cpp
    stb_image.h
    stb_image.cpp
    targetver.h
    vAttribute.h
    vAttribute.cpp
    VertexData.h
    VertexData.cpp
    WarpEngine.h
    WarpEngine.cpp
    GLFW/glfw3.h
    GLFW/glfw3native.h
    )

target_include_directories(WarpEngine PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/WarpEngine/GLFW"
    "${CMAKE_CURRENT_SOURCE_DIR}/WarpEngine/glad"
    )
