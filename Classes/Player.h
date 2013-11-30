
#ifndef PLAYER_H_
#include "Character.h"
#define PLAYER_H_

class Player : public Character
{
public:
	void Move(){};
private:

	cocos2d::CCPoint a;
};

#endif /* PLAYER_H_ */
