uniform sampler2DRect tex0;
uniform vec2 resolution;
uniform vec2 mouse;

float cir(vec2 uv,vec2 p, float s,float d);
void main()
{	
	vec2 uv = gl_FragCoord.xy / resolution;

	vec2 coords = gl_FragCoord.xy ;
	//coords.y = resolution.y -coords.y;
	vec4 texture =  texture2DRect(tex0, coords);
	
	
	gl_FragColor = texture;
	
	
	//vec4 fin = vec4(e);
	float e = cir(uv,mouse,0.01,0.1);
	gl_FragColor = vec4(e,e,e,1.0)+texture*0.99; 
}
float cir(vec2 uv,vec2 p,float s, float d){
	
	vec2 p2 = p - uv;
	float a = atan(p2.x,p2.y);
	float r = length(p2);
	
	float e = 1.-smoothstep(s,s+d,r);
	return e;
}


