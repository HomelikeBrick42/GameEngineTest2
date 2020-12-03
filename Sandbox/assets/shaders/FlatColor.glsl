// Flat Color Shader

#type vertex
#version 330 core

layout(location = 0) in vec4 a_Position;
layout(location = 1) in vec3 a_Normal;
layout(location = 2) in vec2 a_TexCoord;

uniform mat4 u_Model = mat4(1.0);
uniform mat4 u_ViewProjection = mat4(1.0);

out vec3 v_Normal;
out vec2 v_TexCoord;

void main()
{
	gl_Position = u_ViewProjection * u_Model * a_Position;
	v_Normal = normalize((mat3(transpose(inverse(u_Model))) * normalize(a_Normal)).xyz);
	v_TexCoord = a_TexCoord;
}

#type fragment
#version 330 core

layout(location = 0) out vec4 o_Color;

uniform vec4 u_Color = vec4(1.0);

in vec3 v_Normal;
in vec2 v_TexCoord;

void main()
{
	float dirLight = max(dot(normalize(v_Normal), normalize(vec3(0.4, 1.0, -0.6))), 0.0) * 0.7;
	float ambLight = 0.3;
	o_Color = vec4(u_Color.xyz * (dirLight + ambLight), u_Color.w);
}