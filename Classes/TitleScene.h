#ifndef __cocos2d_x_game__TitleScene__
#define __cocos2d_x_game__TitleScene__

#include "cocos2d.h"

class Title : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();

    // a selector callback
    void menuChangeScene(CCObject* pSender);

    // implement the "static node()" method manually
    //LAYER_CREATE_FUNC(Title);
    CREATE_FUNC(Title);
};

#endif /* defined(__cocos2d_x_game__TitleScene__) */
