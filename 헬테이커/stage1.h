#pragma once
#include "stageBase.h"
#include "effect.h"

#define WALLMAX 10
#define OBSMAX 4
#define ENEMYMAX 3

class stage1 : public stageBase
{
private:
	
	tagRect obs[OBSMAX];
	tagRect enemy[ENEMYMAX];

	tagRect wall[WALLMAX];
	tagRect inter[INTERSECT];


public:
	stage1() {};
	~stage1() {};


	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void stance();
	void estance();
	void playermove();
	void collision();
	
};

