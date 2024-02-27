#version 400 core
layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCoord;

out vec2 v_TexCoord;

uniform mat4 u_VP;
uniform mat4 u_Model;

void main()
{
	//vec4 t_position = position * u_Scale;
	gl_Position = u_VP * u_Model * position;
	v_TexCoord = texCoord;
};