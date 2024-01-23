#include "ofApp.h"
#include <vector>

float speed = 3.0;

struct Star {
    double x,y;
    double z, pz;
    ofColor color;
    Star() {
        reset();
    }
    
    void reset() {
        x = ofRandom(-ofGetWidth()/2, ofGetWidth()/2);
        y = ofRandom(-ofGetHeight()/2, ofGetHeight()/2);
        z = pz = ofRandom(1, 2000);
        color.setHex(ofRandom(0xffffff));
    }
    
    void update() {
        pz = z;
        z-=speed;
        if (z < 1.0) z=pz=ofRandom(1,2000);
    }
    
    void show() {
        ofSetColor(color);
        ofDrawLine(ofMap(x/z, -1, 1, -ofGetWidth()/2, ofGetWidth()/2),
                   ofMap(y/z, -1, 1, -ofGetHeight()/2, ofGetHeight()/2),
                   ofMap(x/pz, -1, 1, -ofGetWidth()/2, ofGetWidth()/2),
                   ofMap(y/pz, -1, 1, -ofGetHeight()/2, ofGetHeight()/2));
                   
    }
};

std::vector<Star> stars;

//--------------------------------------------------------------
void ofApp::setup(){
    stars.clear();
    stars.resize(5000);
}

//--------------------------------------------------------------
void ofApp::update(){
    for (auto &s : stars) s.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    for (auto &s : stars) s.show();
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    speed=ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 10);
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
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    setup();
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
