#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetWindowShape(600, 600);
	sh.load("", "shaders/sh1.frag"); //CARGO MI SHADERS
	fbo.allocate(ofGetWidth(), ofGetHeight());

}



//--------------------------------------------------------------
void ofApp::update(){
	//sh.setUniform1f("time", ofGetElapsedTimef());
	//sh.setUniform2f("resolution", ofGetWindowWidth(), ofGetWindowHeight());
}

void ofApp::draw(){
	
	ofSetColor(255,255);
	fbo.begin();
	sh.begin();
	sh.setUniform1f("time", ofGetElapsedTimef());
	sh.setUniform2f("resolution", ofGetWindowWidth(), ofGetWindowHeight());
	float mx = ofMap(mouseX,0,ofGetWindowWidth(),0,1);
	float my = ofMap(mouseY, 0, ofGetWindowHeight(), 0, 1);
	sh.setUniform2f("mouse", mx,my);
	ofRect(0, 0, ofGetWidth(), ofGetHeight());
	sh.end();
	fbo.end();
	
	fbo.draw(0,0,ofGetWidth(),ofGetHeight());


	ofSetColor(0, 200, 0);
	ofDrawEllipse(ofGetMouseX(), ofGetMouseY(), 20, 20);
}




//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (key == 'r') {
		sh.load("", "shaders/sh1.frag"); //CARGO MI SHADERS
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
