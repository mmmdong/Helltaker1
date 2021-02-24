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

	virtual HRESULT init();	//�ʱ�ȭ ���� �Լ�
	virtual void release();	//�޸� ���� �Լ�
	virtual void update();	//���� ����
	virtual void render();	//�׸��� ����

	void setStage(STAGE);
};

