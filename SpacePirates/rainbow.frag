#version 330 core
out vec4 FragColor;

in vec4 vertexColor;
in vec2 texCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform vec4 lightColor;

void main()
{
    float ambientStrength = 0.1;
    vec4 ambient = ambientStrength * lightColor;

    vec4 lighting = ambient * vertexColor;
    vec4 textureColor = mix(texture(texture1, texCoord), texture(texture2, texCoord), 0.2);

    FragColor = lighting * textureColor;
} 