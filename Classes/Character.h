
#ifndef CHARACTER_H_

#include "cocos2d.h"

#define CHARACTER_H_

using namespace cocos2d;

class Character : public CCSprite
{
	public:
		virtual void Move(cocos2d::CCPoint postion );
		virtual cocos2d::CCPoint getPotion();

	private:
		cocos2d::CCPoint m_Postion;
		float m_angle;
		float m_speed;
};

#endif /* CHARACTER_H_ */
