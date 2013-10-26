#include "GameManager.h"

static GameManager* s_GameManager = NULL;

GameManager::GameManager(){

}

GameManager::~GameManager() {

}

GameManager* GameManager::sharedInstance(){
	if(!s_GameManager){
		s_GameManager = new GameManager();
		s_GameManager->init();
	}
	return s_GameManager;
}

bool GameManager::init(){
	stage_id = 4;

	return true;
}
