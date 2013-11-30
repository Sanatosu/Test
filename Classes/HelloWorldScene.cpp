#include "HelloWorldScene.h"
#include "GameManager.h"

USING_NS_CC;

typedef enum
{
	kTileMapTag = 99
} myNodeTag;

CCScene* HelloWorld::scene()
{
    CCScene *scene = CCScene::create();
    
    HelloWorld *layer = HelloWorld::create();

    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	GameManager::sharedInstance()->setStageId(1);
	int stage_id = GameManager::sharedInstance()->getStageId();

	//CCLog("%d", stage_id);
	CCLayerColor::initWithColor(ccc4(170,220,120, 255));
	//CCLayerGradient::initWithColor(ccc4(70,145,15,255),ccc4(255,220,120,255),ccp(0.0f, 1.0f));

    if ( !CCLayer::init() )
    {
        return false;
    }

    this->setTouchMode(kCCTouchesOneByOne);
    //マルチタッチモード
    //this->setTouchMode(kCCTouchesAllAtOnce);
    //タッチを有効にする
    this->setTouchEnabled(true);

    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
    //タイルマップ宣言
    CCTMXTiledMap* pTileMap = CCTMXTiledMap::create("map.tmx");
    this->addChild(pTileMap);
    pTileMap->setTag(kTileMapTag);

	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);
    
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    this->addChild(pLabel, 1);

    pSprite = CCSprite::create("HelloWorld.png");

    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    pSprite->runAction(CCTintTo::create(1.0f , 255 , 0 , 0));

    /*CCParticleSystemQuad *pPar =
    		CCParticleSystemQuad::create("fl.plist");
    pPar->setPosition(ccp(500,300));
    this->addChild(pPar);*/

    CCSetIterator it;
    CCTouch* touch;

    pPlayer = (Player*)Player::create("ab2c61d1.png");
    pPlayer->setPosition(ccp(200, 300));
    this->addChild(pPlayer, 0);

    return true;
}

void HelloWorld::update(float dt)
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	CCTMXTiledMap* pTileMap = (CCTMXTiledMap*)this->getChildByTag(kTileMapTag);

	CCPoint point = pTileMap->getPosition();

	CCPoint pDelta = ccp(m_pDelta.x * dt, m_pDelta.y * dt );

	point = ccp( point.x + pDelta.x, point.y + pDelta.y );

	CCSize mapSize = pTileMap->getContentSize();
	point.x = MAX(point.x, size.width - mapSize.width);
	point.x = MIN(point.x, 0);
	point.y = MAX(point.y, size.height - mapSize.height);
	point.y = MIN(point.y, 0);

	pTileMap->setPosition(point);

	/*this->addChild(pTileMap);
	pTileMap->setTag(kTileMapTag);*/
}

bool HelloWorld::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	m_pStartPoint = this->convertToWorldSpace(
			this->convertTouchToNodeSpace(pTouch));
	this->scheduleUpdate();

	return true;
}

void HelloWorld::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint touchPoint = this->convertToWorldSpace(
			this->convertTouchToNodeSpace(pTouch));

	m_pDelta = ccp(m_pStartPoint.x - touchPoint.x,
			m_pStartPoint.y - touchPoint.y);


}

void HelloWorld::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
	this->unscheduleUpdate();
}

void HelloWorld::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{
	this->unscheduleUpdate();
}

void HelloWorld::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
	CCSetIterator it;
	CCTouch* touch;

	for( it = pTouches->begin(); it != pTouches->end(); it++ )
	{
		touch = (CCTouch*)(*it);

		if(!touch) break;

		CCPoint location = touch->getLocationInView();
		location = CCDirector::sharedDirector()->convertToGL(location);

		CCLog("touch begin!");
	}
}

void HelloWorld::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent)
{
	CCLog("touch moved!");
}

void HelloWorld::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
	CCLog("touch ended!");
}

void HelloWorld::ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent)
{
	CCLog("touch cancelled!");
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
