#version 440 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 color;
layout(location = 2) in vec2 texCoord;

// Consider changing so the calculation is done CPU side.
//uniform mat4 uTranslation;
//uniform mat4 uRotation;
//uniform mat4 uScaled;
uniform mat4 uTRS;
uniform mat4 uProjection;

out VS_OUT{
	vec4 v_color;
} vs_out;

void main()
{
	//vec4 scale = vec4(1.5f, 1.5f, 0.0f, 1.0f);
	//mat4 TRS = (uTranslation * uRotation * uScaled);
	gl_Position = uProjection * uTRS * position;
	vs_out.v_color = color;

}

