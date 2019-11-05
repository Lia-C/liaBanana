#include "ofApp.h"

void Pendulum::setup(ofPoint pos0, ofPoint pos, ofPoint velocity, ofColor color){
    this->pos0 = pos0;
    this->pos = pos;
    this->velocity = velocity;
    this->color = color;
}


void Pendulum::update(){
    float dt = 1.0 / 60.0; // time step
    float mass = 0.1; // mass of ball
    float rubberLen = 0.0; // segment length
    float k = 0.5; // segment's stiffness
    ofPoint g(0.0, 0.0);  // gravity

    ofPoint delta = pos - pos0;
    float len = delta.length();
    float hookeValue = k * (len - rubberLen);
    delta.normalize();
    ofPoint hookeForce = delta * (-hookeValue);

    ofPoint force = hookeForce + g;
    ofPoint a = force / mass;
    this->velocity += a * dt;
    this->velocity *= 0.99;
    this->pos += this->velocity * dt;
    
    
}

void Pendulum::draw(){
    ofSetColor(this->color);
    ofDrawCircle(this->pos.x, this->pos.y, 5);
}


//--------------------------------------------------------------
void ofApp::setup(){
    lia.load("liabanana.jpg");
    ofSetBackgroundAuto(false);
    ofBackground(0);
    float width = lia.getWidth();
    float height = lia.getHeight();
    lia.draw(0, 0, width, height);
    
    
    ofSetFrameRate(60);

    int step = 10;

    for (int x = 0; x < width; x += step) {
        for (int y = 0; y < height; y += step) {
                        
//            if (x % (step*13) == 0 && y % (step*12) == 0){
                
                Pendulum pendy;
                
                ofPoint pos0 = ofPoint(x,y);
                ofPoint pos = ofPoint(x + ofRandom(-20, 20),y + ofRandom(-20, 20)) ;
                ofPoint velocity = ofPoint(100, 0);
                ofColor color = lia.getColor(x, y);
                
                cout << pos0 << endl;
                cout << pos << endl;
                cout << "    " << endl;
                
                
                pendy.setup(pos0, pos, velocity, color);
                pendys.push_back(pendy);
                
//                float growRate = sin(ofGetElapsedTimef());
//                for (int circle = 0; circle < 5; circle ++) {
//                    ofColor c = lia.getColor(x, y);
                
//                    c.setBrightness(100 * circle);
//                    ofSetColor(c);
//                    ofDrawCircle(x, y, (100-20*circle) * growRate);
//
//                    ofDrawCircle(pos.x, pos.y, 20);
//                }
            }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i < pendys.size(); i++){
        pendys[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    for(int i = 0; i < pendys.size(); i++){
        pendys[i].draw();
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
