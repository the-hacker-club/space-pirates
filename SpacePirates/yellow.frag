#version 330 core
out vec4 FragColor;

uniform vec4 ourColor;

in vec4 vertexColor;

void main()
{
//    FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);
    // FragColor = vertexColor;
    FragColor = ourColor;
} 
