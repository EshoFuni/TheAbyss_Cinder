#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "Cam.h"
#include "AbyssGUI.h"
#include "CreatureManager.h"

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
    AbyssGUI mAbyssGUI;
    
    
    // MANAGER DECLARATION
    CreatureManager manager;
    
    // CREATURE DECLARATION
    TACreatureExample theCreature;
};

void TheAbyssApp::prepareSettings(Settings *settings){
    
    settings->setWindowSize(640, 480);
    settings->setFrameRate(60.0f);
    settings->setTitle("TheAbyss"); // added the naming (menu feedback)

}

void TheAbyssApp::setup()
{
    // WINDOW NAMING
    ci::app::getWindow()->setTitle("TheAbyss"); // added

    // INSTATIATE AND INIT CAMERA
    mCam = *new Cam();
    mCam.init();
    
    //INSTANTIATE AND INIT ABYSSGUI
    mAbyssGUI = *new AbyssGUI();
    mAbyssGUI.init();
    
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
    gl::enableAlphaBlending();
    
    // SET CAMERA
    mCam.setCam();
    // DRAW ABYSSGUI
    mAbyssGUI.draw();
    
    // CREATURE DRAW
    manager.draw();
}

// KEYBOARD SHORTCUTS
void TheAbyssApp::keyDown(KeyEvent event){
    // press 'h' to see the parameter UI
    if ( event.getChar() == 'h'){
        mAbyssGUI.showAbyssGUI = !mAbyssGUI.showAbyssGUI;
    }
    if (event.getChar() == '+') {
        manager.addRandomCreature();
    }
    if (event.getChar() == '-'){
        manager.removeLastCreature();
    }
}

CINDER_APP_NATIVE( TheAbyssApp, RendererGl )
