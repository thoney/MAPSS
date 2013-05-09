#version 110
uniform sampler2D position;
uniform sampler2D velocity;
uniform float dt;

void main()
{	
	vec4 vPos			= texture2D( position, gl_TexCoord[0].st );
	
	vec4 vVel			= texture2D( velocity, gl_TexCoord[0].st );
	
	vec3 pos			= vPos.xyz + ( ( vVel.xyz ) * ( vVel.a * 0.05 ) * dt );
	
	gl_FragColor.rgb	= pos;
	gl_FragColor.a		= vPos.a;
}