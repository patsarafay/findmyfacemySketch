#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    cameraWidth  = 640;
    cameraHeight  = 480;
    
    camera.setDeviceID(0);
    camera.setDesiredFrameRate(30);
    camera.initGrabber(cameraWidth, cameraHeight);
    
   //camera2.setDeviceID(0);
   //camera2.setDesiredFrameRate(60);
   //camera2.initGrabber(200, 200);

    finder.setup("haarcascade_frontalface_default.xml");
    
     image1.load("apple.png");
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    camera.update();
   // camera2.update();
    
    if(camera.isFrameNew()){
        image.setFromPixels(camera.getPixelsRef());
    
    finder.findHaarObjects(image);
    }
    
   
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    camera.draw(0, 0, cameraWidth, cameraHeight);
    //camera2.draw(500, 200, -cameraWidth, cameraHeight);
    
    ofNoFill();
    for(unsigned int i = 0; i < finder.blobs.size(); i++) {
        ofRectangle cur = finder.blobs[i].boundingRect;
        //ofDrawRectangle(cur.x, cur.y, cur.width, cur.height);
        image1.draw(cur.x+20, cur.y, cur.width/1.1, cur.height/1.1);
        
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
