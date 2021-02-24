#pragma once
#include "stageBase.h"
#include "effect.h"

#define WALLMAX 13
#define OBSMAX 8
#define ENEMYMAX 2



class stage2 : public stageBase
{
private:

	tagRect obs[OBSMAX];
	tagRect enemy[ENEMYMAX];

	tagRect wall[WALLMAX];
	tagRect inter[INTERSECT];




public:
	stage2() {};
	~stage2() {};


	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void stance();
	void estance();
	void playermove();
	void collision();

};

