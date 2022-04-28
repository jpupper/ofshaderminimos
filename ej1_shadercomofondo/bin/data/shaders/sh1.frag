

uniform vec2 resolution;
uniform float time; 
uniform vec2 mouse;
void main(){
	
	vec2 uv = gl_FragCoord.xy / resolution.xy;
	

	vec2 p = vec2(mouse.x,mouse.y) - uv;

	float r = length(p);
	float a = atan(p.x,p.y);

	float e = sin(a*4.+r*10.+time)*.5+.5+sin(r*10.+time*2.);
	float e2 = sin(a*10.+r*2.-time*.5+.5);
	float e3 = sin(a*20.+r*20.)*.5+.5;
	
	gl_FragColor = vec4(e,e2,e3,1.0);

}