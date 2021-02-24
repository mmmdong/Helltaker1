#pragma once
#include "stageBase.h"
#include "effect.h"

#define WALLMAX 11
#define OBSMAX 5
#define ENEMYMAX 3



class stage3 : public stageBase
{
private:
	
	tagRect obs[OBSMAX];
	tagRect enemy[ENEMYMAX];

	tagRect wall[WALLMAX];
	tagRect inter[INTERSECT];


public:
	stage3() {};
	~stage3() {};


	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void stance();
	void estance();
	void playermove();
	void collision();

};

