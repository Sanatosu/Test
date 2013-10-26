#include "HelloWorldScene.h"
#include "GameManager.h"

USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	GameManager::sharedInstance()->setStageId(1);
	int stage_id = GameManager::sharedInstance()->getStageId();

	//CCLog("%d", stage_id);
	//CCLayerColor::initWithColor(ccc4(170,220,120, 255));
	CCLayerGradient::initWithColor(ccc4(70,145,15,255),ccc4(255,220,120,255),ccp(0.0f, 1.0f));

    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);
    
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    this->addChild(pLabel, 1);

    //CCSprite* pSprite = CCSprite::create("HelloWorld.png");
    pSprite = CCSprite::create("HelloWorld.png");

    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    //pSprite->runAction(CCWaves::create(10.0f,,10,1.0f,true,true));
    pSprite->runAction(CCTintTo::create(1.0f , 255 , 0 , 0));

    this->addChild(pSprite, 0);

    /*//CCParticleRain
    CCParticleRain* pParticle =
    		CCParticleRain::createWithTotalParticles(1000);

    this->addChild(pParticle);*/

    CCParticleSystemQuad *pPar =
    		CCParticleSystemQuad::create("fl.plist");
    pPar->setPositionX(10.0f);
    this->addChild(pPar);
    

    return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
