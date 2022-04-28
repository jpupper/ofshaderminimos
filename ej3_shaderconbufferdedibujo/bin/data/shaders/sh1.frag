//#version 330

uniform sampler2DRect tex0;
uniform vec2 resolution;
uniform vec2 mouse;
uniform float time;
float cir(vec2 uv,vec2 p, float s,float d);
void main()
{	
	vec2 uv = gl_FragCoord.xy / resolution;

	vec2 coords = gl_FragCoord.xy ;
	//coords.y = resolution.y -coords.y;
	
	coords*=resolution.xy;
	coords.x+=sin(coords.x*10.+time);
	coords/=resolution.xy;
	
	vec4 tx =  texture2DRect(tex0, coords);
	tx.r = sin(tx.r*100.+time);
	gl_FragColor = tx; 
}
