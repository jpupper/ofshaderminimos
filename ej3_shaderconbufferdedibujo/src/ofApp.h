#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void draw();
	void update();
	void windowResized(int w, int h);
	void dibujarCirculos();

	void keyPressed(int key);

	ofImage img;
	ofShader sh;

	ofFbo render;
	ofFbo fbo_circulos;
};
