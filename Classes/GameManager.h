#include "cocos2d.h"

#ifndef __Game_Manager__
#define __Game_Manager__

class GameManager {
public:
	GameManager();
	virtual ~GameManager();
	static GameManager* sharedInstance();

	bool init();

	inline int getStageId() { return stage_id; };
	inline void setStageId(int a){stage_id = a;};

private:
	int stage_id;
};

#endif /* __Game_Manager__ */
