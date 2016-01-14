#version 120
varying vec3 outColor;
void main()
{    
  gl_FragColor = vec4(outColor, 1.0);
   // fragColor = texture(skybox, TexCoords);
}