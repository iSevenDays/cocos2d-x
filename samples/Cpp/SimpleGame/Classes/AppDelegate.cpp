#include "AppDelegate.h"
#include "HelloWorldScene.h"

USING_NS_CC;


AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = EGLView::createWithSize("Simple Game", Size(900,640));
        director->setOpenGLView(glview);
    }

    auto screenSize = glview->getFrameSize();
    auto designSize = Size(480, 320);
    std::vector<std::string> searchPaths;
    
    if (screenSize.height > 320)
    {
        searchPaths.push_back("hd");
        searchPaths.push_back("sd");
        director->setContentScaleFactor(640.0f/designSize.height);
    }
    else
    {
        searchPaths.push_back("sd");
        director->setContentScaleFactor(320.0f/designSize.height);
    }
    
    FileUtils::getInstance()->setSearchPaths(searchPaths);
    
    glview->setDesignResolutionSize(designSize.width, designSize.height, ResolutionPolicy::NO_BORDER);

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    auto scene = HelloWorld::scene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // CocosDenshion::SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}