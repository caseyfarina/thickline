#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGlutWindow.h"

//========================================================================
int main( ){
    
    ofAppGlutWindow window; // create a window
    
    // THIS IS THE IMPORTANT PART:
    window.setGlutDisplayString("rgba alpha double stencil samples>=8");
    
    
    // set width, height, mode (OF_WINDOW or OF_FULLSCREEN)
    ofSetupOpenGL(&window, 1024, 768, OF_WINDOW);
    ofRunApp(new ofApp()); // start the app
    
    /*
    
    ofAppGlutWindow window;
    window.setGlutDisplayString("rgba double samples>=4 depth");
    ofSetupOpenGL(&window, 1024,768, OF_WINDOW);			// <-------- setup the GL context
    
    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
    // pass in width and height too:
    ofRunApp( new ofApp());
     */
}