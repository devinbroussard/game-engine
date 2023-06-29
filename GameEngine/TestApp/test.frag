#version 440 core

layout (location = 6) uniform vec3 u_SurfaceAmbient;
layout (location = 7) uniform vec3 u_SurfaceDiffuse;
layout (location = 8 ) uniform vec3 u_SurfaceSpecular;
layout(location = 9) uniform vec3 u_ViewPosition;

layout (location = 10) uniform vec4 u_LightAmbient[5];
layout (location = 15) uniform vec4 u_LightDiffuse[5];
layout (location = 20) uniform vec4 u_LightSpecular[5];
layout (location = 25) uniform vec3 u_LightDirection[5];
layout (location = 30) uniform vec3 u_LightPosition[5];


in vec3 v_out_FragPosition;
in vec4 v_out_Color;
out vec4 f_out_Color;
in vec3 v_out_Normal;

void main() {
	vec3 norm = normalize(v_out_Normal);

	vec4 ambient = vec4(0, 0, 0, 0);
	vec4 diffuse = vec4(0, 0, 0, 0);
	vec4 specular = vec4(0, 0, 0, 0);

	for (int i = 0; i < 5; i++)
	{
		vec3 lightDir = normalize(-u_LightDirection[i]);

		if (u_LightDirection[i] == vec3(0.0f, 0.0f, 0.0f))
		{
			lightDir = normalize(u_LightPosition[i] - v_out_FragPosition);
		}
		
		vec3 viewDir = normalize(u_ViewPosition - v_out_FragPosition);
		vec3 reflectDir = reflect(lightDir, -norm);
		
		float diff = max(dot(norm, lightDir), 0.0);


		diffuse += diff * u_LightDiffuse[i] * vec4(u_SurfaceDiffuse, 1);
		ambient += u_LightAmbient[i] * vec4(u_SurfaceAmbient, 1);

		float spec = 0;

		if (diff > 0)
		{
			spec = pow(max(dot(viewDir, reflectDir), 0), 64);
		}

		specular += spec * u_LightSpecular[i] * vec4(u_SurfaceSpecular, 1);
	}

	vec4 result = ambient + diffuse + specular;
	f_out_Color = vec4(result);
}
