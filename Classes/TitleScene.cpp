#include "TitleScene.h"
//#include "SimpleAudioEngine.h"
#include "HelloWorldScene.h"

using namespace cocos2d;
//using namespace CocosDenshion;

CCScene* Title::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();

    // 'layer' is an autorelease object
    Title *layer = Title::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Title::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    /////////////////////////////
    // 2. add a menu item with change scene
    CCMenuItemImage *pChangeSceneItem = CCMenuItemImage::create(
                                                                "CloseNormal.png",
                                                                "CloseSelected.png",
                                                                this,
                                                                menu_selector(Title::menuChangeScene) );
    pChangeSceneItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pChangeSceneItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // ask director the window size
    CCSize size = CCDirector::sharedDirector()->getWinSize();


    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("title.png");

    // position the sprite on the center of the screen
    pSprite->setPosition( ccp(size.width/2, size.height/2) );

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);

    return true;
}

void Title::menuChangeScene(CCObject *pSender)
{
    CCDirector::sharedDirector()->replaceScene( HelloWorld::scene());
}
