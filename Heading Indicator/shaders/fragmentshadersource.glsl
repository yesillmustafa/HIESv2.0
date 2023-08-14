#version 100
precision mediump float;

varying vec2 texCoord;

uniform bool useTexture;
uniform sampler2D ourTexture;
uniform vec3 color;

void main()
{
    if (useTexture)
    {
        gl_FragColor = texture2D(ourTexture, texCoord);
    }
    else
    {
        gl_FragColor = vec4(color, 1.0);
    }
}
