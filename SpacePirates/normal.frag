#version 330 core
out vec4 FragColor;

struct Material {
    sampler2D diffuse;
    sampler2D specular;
    sampler2D emission;
    float shininess;
}; 

struct DirectionalLight {
    vec3 direction;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

in vec2 TexCoords;
in vec3 FragPos;  
in vec3 Normal;  
  
uniform vec3 viewPos;
uniform Material material;
uniform DirectionalLight dlight;
uniform float time;

void main()
{
    // Get texture values
    vec3 textDiff = texture(material.diffuse, TexCoords).rgb;
    vec3 textSpec = texture(material.specular, TexCoords).rgb;

    // ambient
    vec3 ambient = dlight.ambient * textDiff;
  	
    // diffuse 
    vec3 norm = normalize(Normal);
    //vec3 lightDir = normalize(light.position - FragPos);
    vec3 lightDir = normalize(dlight.direction);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = dlight.diffuse * diff * textDiff;
    
    // specular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = dlight.specular * (spec * textSpec);  

    vec3 textEmit;

    if (textSpec != 0.0) {
        textEmit = vec3(0.0);
    } else {
        textEmit = texture(material.emission, vec2(TexCoords.x, TexCoords.y + time)).rgb;
    }
        
    vec3 result = ambient + diffuse + specular + textEmit;
    FragColor = vec4(result, 1.0);
} 