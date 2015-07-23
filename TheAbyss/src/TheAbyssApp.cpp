#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Camera.h"
#include "cinder/params/Params.h"

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
    
    // CAMERA VARIABLES
    // for camera related information check file://localhost/Applications/cinder_0.8.6_mac/docs/html/flocking_chapter1.html
    CameraPersp mCam; // the "m" prefix means this is a member variable (in opposition to local variables)
    Vec3f mEye; // where the camera is positioned
    Vec3f mCenter; // where the camera is pointing to
    Vec3f mUp; // what is the upwards direction (in this case the Y axis)
    
    // UI PARAMETERS VARIABLES
    params::InterfaceGlRef mParams; // parameters member variable
    Quatf mSceneRotation; // scene rotation variable
    bool drawParam = false;
    
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
    // INIT CAMERA VARIABLES
    mEye = Vec3f(0.f, 0.f, 500.f);
    mCenter = Vec3f::zero();
    mUp = Vec3f::yAxis();
    mCam.setPerspective(60.f, getWindowAspectRatio(), 5.f, 3000.f);
    
    // INSTANTIATE UI PARAMETERS
    mParams = params::InterfaceGl::create("TheAbyss Parameters", Vec2i(225, 200) ); // (title, size, color)
    mParams->addParam("Scene Rotation", &mSceneRotation); // ("parameter name", target)
    
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
    mCam.lookAt(mEye, mCenter, mUp);
    gl::setMatrices(mCam);
    
    // SHOW UI PARAMETERS
    if (drawParam == true){
        mParams->draw();
    }
    gl::rotate(mSceneRotation);

    
    // CREATURE DRAW
    manager.draw();
}

void TheAbyssApp::keyDown(KeyEvent event){
    // press 'h' to see the parameter UI
    if ( event.getChar() == 'h'){
        drawParam = !drawParam;
    }
    if (event.getChar() == '+') {
        manager.addCreature();
    }
    if (event.getChar() == '-'){
        manager.removeCreature();
    }
}

CINDER_APP_NATIVE( TheAbyssApp, RendererGl )
