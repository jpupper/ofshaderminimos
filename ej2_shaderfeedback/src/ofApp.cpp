#include "ofApp.h"
void ofApp::setup() {
	ofSetWindowShape(1024, 768);
	sh.load("", "shaders/sh11.frag");
	render.allocate(1024, 768);

}

void ofApp::update() {
	render.begin();
	sh.begin();
	sh.setUniformTexture("tex0", render.getTexture(), 0);
	sh.setUniform2f("mouse", ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 1), ofMap(ofGetMouseY(), 0, ofGetHeight(), 0, 1));

	ofRect(0, 0, ofGetWidth(), ofGetHeight());
	sh.end();

	render.end();
}
void ofApp::draw() {
	ofSetColor(255);
	render.draw(0, 0);
	//ofSetColor(200, 0, 0);
	//ofRect(ofGetMouseX(), ofGetMouseY(), 40, 50);
}
void ofApp::windowResized(int w, int h) {


	render.clear();
	render.allocate(w, h);

	sh.begin();
	sh.setUniform2f("resolution", ofGetWidth(), ofGetHeight());
	sh.end();
}