#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "Cam.h"
#include "AbyssGUI.h"
#include "CreatureManager.h"
#include "BCIWave.h"

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
    
    // DECLARATIONS
    
    Cam mCam; // camera
    AbyssGUI mAbyssGUI; // helpful GUI (press 'H')
    CreatureManager manager; // class to manage all creatures
    BCIWave mBCIWave; // waveform representation of BCI data
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
    
    // INSTANTIATE BCI WAVE REPRESENTATION
    mBCIWave = *new BCIWave(9000, true); //arg1 = port, arg2 = verbose
    }

void TheAbyssApp::update()
{
    // CREATURE MOVEMENT
    manager.update();
    
    // UPDATE BCI REPRESENTATION
    mBCIWave.update();
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
    
    // DRAW BCI WAVE REPRESENTATION
    mBCIWave.draw();
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
