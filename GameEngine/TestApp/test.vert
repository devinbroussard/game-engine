#version 440 core

layout (location = 0) uniform mat4 u_Model;
layout (location = 1) uniform mat4 u_View;
layout (location = 2) uniform mat4 u_Projection;

layout (location = 3) in vec3 v_in_Position;
layout (location = 4) in vec4 v_in_Color; 
layout (location = 5) in vec3 v_in_Normal;

out vec3 v_out_FragPosition;
out vec4 v_out_Color;
out vec3 v_out_Normal;

void main() {
	gl_Position = u_Projection * u_View * u_Model * vec4(v_in_Position, 1.0f);
	v_out_FragPosition = vec3(u_Model * vec4(v_in_Position, 1.0f));
	v_out_Color = v_in_Color;
	v_out_Normal = v_in_Normal;
}