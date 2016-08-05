#pragma once

#include "ofMain.h"
#include "ofxShivaVGRenderer.h"
#include "fatline.h"
#include "ofxGui.h"




class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofxPanel gui;
    
    int lineNumber = 60;
    
    ofParameter<float> timeScale;
    ofParameter<float> noiseScaleLine;
    ofParameter<float> thickness;
    ofPolyline line;
    ofPath _curvedPath;
    
    vector < fatline > newfats;
    
};