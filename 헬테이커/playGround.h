#pragma once
#include "gameNode.h"
#include "stage1.h"
#include "stage2.h"
#include "stage3.h"

enum STAGE
{
	stg1,
	stg2,
	stg3,
};



class playGround : public gameNode
{
private:

	STAGE nowstg;
	stageBase* _sb;

public:
	playGround();
	~playGround();

	virtual HRESULT init();	//초기화 전용 함수
	virtual void release();	//메모리 해제 함수
	virtual void update();	//연산 전용
	virtual void render();	//그리기 전용

	void setStage(STAGE);
};

