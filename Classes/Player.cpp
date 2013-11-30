
#include "Player.h"

bool Player::init()
{
	pSprite = CCSprite.create("8.png");

	this->addchild(pSprite, 0);

	return true;
}

void Player::Draw()
{

}

