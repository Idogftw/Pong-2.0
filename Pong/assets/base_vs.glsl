#version 330 core
layout (location = 0) in vec2 aVertex;
layout (location = 1) in vec3 aColor;

out vec3 outColor;

uniform mat4 model;
uniform mat4 projection;

void main()
{
    gl_Position = projection * model * vec4(aVertex, 0.0, 1.0);
	outColor = aColor;
}