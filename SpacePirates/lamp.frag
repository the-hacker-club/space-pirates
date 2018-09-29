#version 330 core
out vec4 FragColor;

in vec4 vertexColor;
in vec2 texCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform vec4 lightColor;

void main()
{
    FragColor = lightColor;
} 