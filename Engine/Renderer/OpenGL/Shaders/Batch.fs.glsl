#version 460 core

out vec4 color;

in VS_OUT
{
	//vec4 v_Color;
	vec2 v_Texcoord;
	float v_TileState;
} fs_in;

uniform sampler2D s_Empty;
uniform sampler2D s_Wall;
uniform sampler2D s_SnakeHead;
uniform sampler2D s_SnakeBody;
uniform sampler2D s_Food;

void main()
{
	if(int(fs_in.v_TileState) == 0)
		color = texture(s_Empty, fs_in.v_Texcoord);
	else if(int(fs_in.v_TileState) == 1)
		color = texture(s_Wall, fs_in.v_Texcoord);
	else if(int(fs_in.v_TileState) == 2)
		color = texture(s_SnakeHead, fs_in.v_Texcoord);
	else if(int(fs_in.v_TileState) == 3)
		color = texture(s_SnakeBody, fs_in.v_Texcoord);
	else if(int(fs_in.v_TileState) == 4)
		color = texture(s_Food, fs_in.v_Texcoord);
}

