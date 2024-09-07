#version 460 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 color;
layout(location = 2) in vec2 texcoord;

uniform mat4 uProjection;

layout(binding = 0, std430) buffer transforms
{
	mat4 mTRS[];
};

layout(binding = 1, std430) buffer tileStates
{
	int tileState[];
};


out VS_OUT{
	//vec4 v_Color;
	vec2 v_Texcoord;
	float v_TileState;
} vs_out;

void main()
{
	gl_Position =  uProjection * mTRS[gl_InstanceID] * position;
	//vs_out.v_Color = tileColors[gl_InstanceID];
	vs_out.v_Texcoord = texcoord;
	vs_out.v_TileState = float(tileState[gl_InstanceID]);
}

