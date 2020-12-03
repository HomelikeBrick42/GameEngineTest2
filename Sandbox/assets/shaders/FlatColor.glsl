// Flat Color Shader

#type vertex
#version 330 core

layout(location = 0) in vec4 a_Position;

uniform mat4 u_Model = mat4(1.0);
uniform mat4 u_ViewProjection = mat4(1.0);

void main()
{
	gl_Position = u_ViewProjection * u_Model * a_Position;
}

#type fragment
#version 330 core

layout(location = 0) out vec4 o_Color;

uniform vec4 u_Color = vec4(1.0);

void main()
{
	o_Color = u_Color;
}