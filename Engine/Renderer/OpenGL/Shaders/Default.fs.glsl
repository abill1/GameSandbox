#version 440 core

out vec4 color;

in VS_OUT
{
	vec4 v_color;
} fs_in;

void main()
{
	color = fs_in.v_color;
}

