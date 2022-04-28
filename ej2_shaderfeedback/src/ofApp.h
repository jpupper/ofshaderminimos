#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void draw();
	void update();
	void windowResized(int w, int h);
	ofImage img;
	ofShader sh;

	ofPlanePrimitive plane;
	ofFbo render;
};
