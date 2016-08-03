//
//  fatline.h
//  
//
//  Created by Casey Farina on 8/2/16.
//
//

#ifndef ____fatline__
#define ____fatline__

#include "ofMain.h"

class fatline{
    public:
        void setup();
        void update();
        void draw(float thickness);
        
    
    
    vector < ofVec2f > thickness;
    ofPolyline line;
    //ofPath _curvedPath;
   // ofMesh meshy;
    
};

#endif /* defined(____fatline__) */
