#include "ofApp.h"
void ofApp::setup() {
	ofSetWindowShape(1024, 768);
	sh.load("", "shaders/sh1.frag");
	render.allocate(ofGetWindowWidth(), ofGetWindowHeight());

	fbo_circulos.allocate(ofGetWindowWidth(), ofGetWindowHeight());
}

void ofApp::update() {

	fbo_circulos.begin();
	dibujarCirculos();
	fbo_circulos.end();



	render.begin();
	sh.begin();
	sh.setUniformTexture("tex0", fbo_circulos.getTexture(), 0);
	sh.setUniform2f("mouse", ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 1), ofMap(ofGetMouseY(), 0, ofGetHeight(), 0, 1));
	sh.setUniform1f("time", ofGetElapsedTimeMillis() * 0.001);
	ofRect(0, 0, ofGetWidth(), ofGetHeight());
	sh.end();
	render.end();
}
void ofApp::draw() {
	ofSetColor(255);
	render.draw(0, 0);
	//ofSetColor(200, 0, 0);
	//ofRect(ofGetMouseX(), ofGetMouseY(), 40, 50);
	//fbo_circulos.draw(0,0);
}
void ofApp::windowResized(int w, int h) {


	render.clear();
	render.allocate(w, h);

	sh.begin();
	sh.setUniform2f("resolution", ofGetWidth(), ofGetHeight());
	sh.end();
}
void ofApp::dibujarCirculos() {

	ofSetColor(0);
	ofRect(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
	int cnt1 = 10;
	int cnt2 = 15;

	ofColor c1 = ofColor(255, 100, 100);
	ofColor c2 = ofColor(200, 200, 50);
	for (int i = 0; i < cnt1; i++) {
		for (int k = 0; k < cnt2; k++) {

			float angle = ofMap(i, 0, cnt1, 0, TWO_PI * 3.);
			float amp = ofMap(k, 0, cnt2, 0, ofGetWindowWidth() / 2);
			float idxcolor = ofMap(k, 0, cnt2 - 1, 0, 1);
			float size = ofMap(k, 0, cnt2, 30, 15);
			ofSetColor(0, 255, 0);

			//float idxcolor = ofMap(i, 0, cnt1, 0, 1);
			ofColor c3 = c1.getLerped(c2, idxcolor);
			ofSetColor(c3, 200);
			float x = ofGetWindowWidth() / 2 + sin(angle + ofGetElapsedTimeMillis() * 0.0001) * amp;
			float y = ofGetWindowHeight() / 2 + cos(angle + ofGetElapsedTimeMillis() * 0.0001) * amp;
			ofDrawEllipse(x, y, size, size);
		}
	}
}
void ofApp::keyPressed(int key) {
	if (key == 'r') {
		cout << "KEYPRESSED" ;
		sh.load("", "shaders/sh1.frag");
		//sh.load("", "shaders/sh1.frag");
		
		//fbo_circulos.allocate(ofGetWindowWidth(), ofGetWindowHeight());
	}
}