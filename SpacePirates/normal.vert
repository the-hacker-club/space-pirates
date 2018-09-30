#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 normal;

out vec3 Normal;
out vec3 FragPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    // calculate the fragment position in world coordinates
    FragPos = vec3(model * vec4(aPos, 1.0));
    Normal = mat3(transpose(inverse(model))) * normal;
	gl_Position = projection * view * model * vec4(aPos, 1.0);
}