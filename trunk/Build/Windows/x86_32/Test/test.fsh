#version 430 core

layout(location = 0) out vec4 fragColor;

//in vec3 TexCoords;

//uniform samplerCube skybox;

void main()
{    

   // fragColor = texture(skybox, TexCoords);
fragColor  = vec4(1.0,0.0,0.0,1.0);
}