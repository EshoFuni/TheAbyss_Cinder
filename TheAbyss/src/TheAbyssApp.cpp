#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "Cam.h"
#include "Help.h"
#include "CreatureManager.h"
#include "TACreatureExample.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class TheAbyssApp : public AppNative {
  public:
    void prepareSettings(Settings *settings);
    void setup();
	void update();
	void draw();
    void keyDown(KeyEvent event);
    
    Cam mCam;
    Help mHelp;
    
    
    // MANAGER DECLARATION
    CreatureManager manager;
    
    // CREATURE DECLARATION
    TACreatureExample theCreature;
};

void TheAbyssApp::prepareSettings(Settings *settings){
    
    settings->setWindowSize(640, 480);
    settings->setFrameRate(60.0f);
}

void TheAbyssApp::setup()
{
    // INSTATIATE AND INIT CAMERA
    mCam = *new Cam();
    mCam.init();
    
    //INSTANTIATE AND INIT HELP
    mHelp = *new Help();
    mHelp.init();
    
    // INSTANTIATE MANAGER
    manager = *new CreatureManager();
}

void TheAbyssApp::update()
{
    // CREATURE MOVEMENT
    manager.update();
}

void TheAbyssApp::draw()
{
	// CLEAR BACKGROUND
	gl::clear( Color( 0, 0, 0 ) );
    
    // SET CAMERA
    mCam.setCam();
    // DRAW HELP
    mHelp.draw();
    
    // CREATURE DRAW
    manager.draw();
}

// KEYBOARD SHORTCUTS
void TheAbyssApp::keyDown(KeyEvent event){
    // press 'h' to see the parameter UI
    if ( event.getChar() == 'h'){
        mHelp.showHelp = !mHelp.showHelp;
    }
    if (event.getChar() == '+') {
        manager.addCreature();
    }
    if (event.getChar() == '-'){
        manager.removeCreature();
    }
}

CINDER_APP_NATIVE( TheAbyssApp, RendererGl )
