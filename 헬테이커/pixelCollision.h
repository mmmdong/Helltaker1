#pragma once
#include "gameNode.h"

class pixelCollision : public gameNode
{
private:
	image* _mountain;	//����ƾ������ ��� ��� �̹���
	image* _ball;		//��� ���� ��

	RECT _rc;			//���� ���� ��Ʈ
	float _x, _y;		//���� x, y
	int _probeY;		//Y Ž���� 

public:
	pixelCollision() {};
	~pixelCollision() {};

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};

