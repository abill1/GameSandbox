#version 440 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 color;
layout(location = 2) in vec2 texCoord;

out VS_OUT{
	vec4 v_color;
} vs_out;

void main()
{
	gl_Position = position;
	vs_out.v_color = color;

}

