// simple toon vertex shader
// www.lighthouse3d.com

varying vec3 normal, lightDir;
varying vec4 diffuse;

void main()
{
	float nDotL;

	lightDir = normalize(vec3(gl_LightSource[0].position));
	normal = normalize(gl_NormalMatrix * gl_Normal);

	nDotL = max(dot(normal,lightDir),0.0);

	diffuse = gl_FrontMaterial.diffuse * gl_LightSource[0].diffuse;
	gl_FrontColor = nDotL * diffuse/* + 0.25*/;

	gl_Position = ftransform();
}
