//
//  fatline.cpp
//  
//
//  Created by Casey Farina on 8/2/16.
//
//

#include "fatline.h"

void fatline::setup() {
    
}





void fatline::update() {
    
    
    
    
    
    
    
}

void fatline::draw(float thickness) {
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
        float w = ofMap(ofNoise(ofGetFrameNum()*0.02f,i*0.01),0,1,0,thickness);
        
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

    
}


