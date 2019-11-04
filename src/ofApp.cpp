#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    lia.load("liabanana.jpg");
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update(){

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
