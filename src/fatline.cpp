//
//  fatline.cpp
//  
//
//  Created by Casey Farina on 8/2/16.
//
//

#include "fatline.h"

void fatline::setup() {
    randomNoiseOffset = ofRandom(500.000);
    
}





void fatline::update() {
    
    
    
    
    
    
    
}

void fatline::draw(float thickness,float noiseScale, float lineNoise) {
    ofMesh meshy;
    meshy.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    
    float time = ofGetElapsedTimef();
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
        float w = ofMap(
                        ofNoise(
                                line.getVertices()[i].x * noiseScale + (time*0.023),
                                line.getVertices()[i].y * noiseScale + (time*0.242))
                                ,0,1,-thickness,thickness);
        
        //float w = ofMap(dist, 0, 5, 3, .1, true);
        /*
        float lnX = ofMap(
                        ofNoise(
                                line.getVertices()[i].x * noiseScale,
                                line.getVertices()[i].y * noiseScale)
                        ,0,1,-lineNoise,lineNoise);
        
        float lnY = ofMap(
                          ofNoise(
                                  line.getVertices()[i].y * noiseScale,
                                  line.getVertices()[i].x * noiseScale)
                          ,0,1,-lineNoise,lineNoise);
        
        //NEED TO ADD THESE lnY and X to the actual line values
*/
        
        //widthSmooth = 0.9f * widthSmooth + w ;
        
        if (i == 0 || i == line.getVertices().size() - 1) widthSmooth = 0;
        else{
            widthSmooth = 0.9 * widthSmooth + w;
        }
        
        
        
        ofPoint offset;
        offset.x = cos(angleSmooth + PI/2) * widthSmooth;
        offset.y = sin(angleSmooth + PI/2) * widthSmooth;
        
        
        
        meshy.addVertex(  line.getVertices()[i] +  offset + (w));
        meshy.addVertex(  line.getVertices()[i] -  offset + (w));
        
        
        
    }
    
    ofSetColor(0,randomNoiseOffset*0.3);
    meshy.draw();

    
}


