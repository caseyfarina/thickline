//
//  fatline.h
//  
//
//  Created by Casey Farina on 8/2/16.
//
//

#ifndef ____fatline__
#define ____fatline__

#include "ofApp.h"

class fatline{
    public:
        void setup();
        void update();
        void draw();
    
    

    ofPolyline line;
    ofPath _curvedPath;
    
};

#endif /* defined(____fatline__) */
