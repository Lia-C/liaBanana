#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    lia.load("liabanana.jpg");
    ofSetBackgroundAuto(false);
    
    
    ofSetFrameRate(60);
    
    // Set initial values
    pos0 = ofPoint(512, 300);
    pos = ofPoint(600, 200);
    velocity = ofPoint(100, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
    float dt = 1.0 / 60.0; // time step
    float mass = 0.1; // mass of ball
    float rubberLen = 200.0; // segment length
    float k = 0.5; // segment's stiffness
    ofPoint g(0.0, 9.8);  // gravity

    ofPoint delta = pos - pos0;
    float len = delta.length();
    float hookeValue = k * (len - rubberLen);
    delta.normalize();
    ofPoint hookeForce = delta * (-hookeValue);

    ofPoint force = hookeForce + g;
    ofPoint a = force / mass;
    velocity += a * dt;
    pos += velocity * dt;

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    float width = lia.getWidth();
    float height = lia.getHeight();
    int step = 10;
    ofBackground(255);
    lia.draw(0, 0, width, height);
    

    
    for (int x = 0; x < width; x += step) {
        for (int y = 0; y < height; y += step) {
            
           
            
            if (x % (step*13) == 0 && y % (step*12) == 0)
            {
//                ofColor c = lia.getColor(x, y);
//                ofSetColor(c);
                float growRate = sin(ofGetElapsedTimef());
                for (int circle = 0; circle < 5; circle ++) {
                    ofColor c = lia.getColor(x, y);
                    c.setBrightness(100 * circle);
                    ofSetColor(c);
                    ofDrawCircle(x, y, (100-20*circle) * growRate);
                    
                    ofDrawCircle(pos.x, pos.y, 20);
                }
                
            }
            
            
            
    
    
        }
    }
    
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
