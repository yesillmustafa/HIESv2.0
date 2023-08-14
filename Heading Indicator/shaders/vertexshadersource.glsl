#version 100
attribute vec3 inPosition;
attribute vec2 inTexCoord;

uniform mat4 model;

varying vec2 texCoord;

void main()
{
    gl_Position = model * vec4(inPosition, 1.0);
    texCoord = inTexCoord;
}
