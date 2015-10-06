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
    void fadeIn();
    void fadeOut();
    
    void addCreature();
    
    // DECLARATIONS
//  int frameCount;
    Cam mCam; // camera
    AbyssGUI mAbyssGUI; // helpful GUI (press 'H')
    CreatureManager manager; // class to manage all creatures
    BCIWave mBCIWave1, mBCIWave2; // waveform representation of BCI data

    // FADE VARIABLES
    int fadeTime = 1000;
    float fadeInC = 1.f;
    float fadeOutC = 0.f;
    bool fade_in = false;
    bool fade_inBegin = true;
    bool fade_out = false;
    Rectf r;
    
    bool add_creature = false;
    
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
    
    // FADEs
    r = *new Rectf(0, 0, getWindowWidth(), getWindowHeight());

    // INSTATIATE AND INIT CAMERA
    mCam = *new Cam();
    mCam.init();
    
    //INSTANTIATE AND INIT ABYSSGUI
    mAbyssGUI = *new AbyssGUI();
    mAbyssGUI.init();
    
    // INSTANTIATE MANAGER
    manager = *new CreatureManager();
    
    // INSTANTIATE BCI WAVE REPRESENTATION
    mBCIWave2 = *new BCIWave(9001, "/wave2/", "/trigger2/",getWindowWidth() - 33   , 30.f , 1.f , 480  , false);
    mBCIWave1 = *new BCIWave(9000, "/wave1/", "/trigger1/",33   , 30.f , 1.f , 480  , false);
                          //port  address    offset maxAmp speed size verbose
    }

void TheAbyssApp::update()
{
    // CREATURE MOVEMENT
    manager.update();
    
    // UPDATE BCI REPRESENTATION
    mBCIWave1.update();
    mBCIWave2.update();
    
    addCreature();
    add_creature = false;
    
}

void TheAbyssApp::draw()
{
//    frameCount++;
	// CLEAR BACKGROUND
	gl::clear( Color( 0, 0, 0 ) );
    gl::enableAlphaBlending();
    
    // SET CAMERA
    mCam.setCam();
    
    // CREATURE DRAW
    manager.draw();
    
    // DRAW BCI WAVE REPRESENTATION
    mBCIWave1.draw();
    mBCIWave2.draw();
    
    // DRAW FADES
    fadeIn();
    fadeOut();
    
    // DRAW ABYSSGUI
    mAbyssGUI.draw();
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
    if (event.getChar() == 'w'){
        manager.addWorm();
    }
    if (event.getChar() == 'k'){
        manager.compPlus();
    }
    if (event.getChar() == 'l'){
        manager.compMinus();
    }
    if (event.getChar() == 'i'){
        if(fade_in == false){ fade_in = true; fade_out = false; }
    }
    if (event.getChar() == 'o'){
        if (fade_out == false){fade_out = true; }
    }
    if (event.getChar() == 'b') { // BEGIN
        fade_inBegin = true;
    }
    if (event.getChar() == 'p'){
        //manager.addPXP();
        add_creature = true;
    }
    
}

void TheAbyssApp::addCreature(){
    if(add_creature == true){
        manager.addPXP();
    }
}

void TheAbyssApp::fadeIn(){
    if (fade_inBegin == true && fade_in == false){
        gl::color(0.f, 0.f, 0.f, 1.f);
        gl::drawSolidRect(r);
    }
    if (fade_in == true){
        if (fadeInC > 0.f){
            fadeInC -= 1000.f / getFrameRate() / fadeTime;
            gl::color(0.f, 0.f, 0.f, fadeInC);
            gl::drawSolidRect(r);
        }
        if ( fadeInC <= 0.f ) {
            fade_in = false;
            fade_inBegin = false;
            fadeInC = 1.f;
        }
    }
}

void TheAbyssApp::fadeOut(){
    if (fade_out == true){
        if (fadeOutC < 1.f){
            fadeOutC += 1000.f / getFrameRate() / fadeTime;
            gl::color(0.f, 0.f, 0.f, fadeOutC);
        }
        if ( fadeOutC >= 1.f ) {
            fadeOutC = 1.f;
        }
        gl::drawSolidRect(r);
    }
}

CINDER_APP_NATIVE( TheAbyssApp, RendererGl )
