#include "ofApp.h"




//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(100.0f);
    ofSetCurveResolution(5);
    
    newfat.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    
    float tempX = ofMap(ofNoise(ofGetFrameNum()*0.02f),0,1,0,ofGetWidth());
    float tempY = ofMap(ofNoise(ofGetFrameNum()*0.021f+3000),0,1,0,ofGetHeight());

    float tempX1 = ofMap(ofNoise(ofGetFrameNum()*0.03f),0,1,0,ofGetWidth());
    float tempY1 = ofMap(ofNoise(ofGetFrameNum()*0.031f+3000),0,1,0,ofGetHeight());
    
    newfat.line.curveTo(ofPoint(tempX1,tempY1));
    if(newfat.line.size() > 10){
        while (newfat.line.size()>400) {
            newfat.line.getVertices().erase(newfat.line.getVertices().begin());
        }
        
    }
    
    
    newfat.update();

    line.addVertex(ofPoint(tempX,tempY));
    if(line.size() > 30){
        line.getVertices().erase(line.getVertices().begin());
        //line.getVertices().resize(30);
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255, 255, 255);
    newfat.draw(.4);
    
    ofMesh meshy;
    meshy.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    
    
    float widthSmooth = 5;
    float angleSmooth;
    
    for (int i = 0;  i < line.getVertices().size(); i++){
        
        
        int me_m_one = i-1;
        int me_p_one = i+1;
        if (me_m_one < 0) me_m_one = 0;
        if (me_p_one ==  line.getVertices().size()) me_p_one =  line.getVertices().size()-1;
        
        ofPoint diff = line.getVertices()[me_p_one] - line.getVertices()[me_m_one];
        float angle = atan2(diff.y, diff.x);
        
        if (i == 0) angleSmooth = angle;
        else {
            
            angleSmooth = ofLerpDegrees(angleSmooth, angle, 1.0);
            
        }
        
        
        float dist = diff.length();
        //ofSeedRandom(4);
        float w = ofMap(ofNoise(ofGetFrameNum()*0.002f,i*0.01),0,1,0,0.8);
        
        //float w = ofMap(dist, 0, 5, 3, .1, true);
        
        
        
        //widthSmooth = 0.9f * widthSmooth + w ;
        
        if (i == 0 || i == line.getVertices().size()) widthSmooth = 0;
        else{
            widthSmooth = 0.9 * widthSmooth + w;
        }
        
        
        
        ofPoint offset;
        offset.x = cos(angleSmooth + PI/2) * widthSmooth;
        offset.y = sin(angleSmooth + PI/2) * widthSmooth;
        
        
        
        meshy.addVertex(  line.getVertices()[i] +  offset + (w *3));
        meshy.addVertex(  line.getVertices()[i] -  offset + (w*3));
        
        
        
    }
    
    ofSetColor(0,0,0);
    meshy.draw();
    //ofSetColor(100,100,100);
    //meshy.drawWireframe();
    
   
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'f') ofToggleFullscreen();
    
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    line.curveTo(ofPoint(x,y));
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    line.clear();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
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

