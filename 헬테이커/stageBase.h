#pragma once
#include "gameNode.h"

#define INTERSECT 4


enum DIRECTION
{
	OBJ_LEFT_IDLE,
	OBJ_RIGHT_IDLE,
	OBJ_LEFT_DASH,
	OBJ_RIGHT_DASH,
	OBJ_LEFT_KICK,
	OBJ_RIGHT_KICK
};

enum THORNDIRECTION
{
	UP,
	DOWN
};



struct tagKey
{
	RECT rc;
	float x, y;
	image* img;
};

struct tagThorn
{
	image* img;
	THORNDIRECTION td;
	RECT rc;
	animation* ani;
	animation* ani2;
	float x, y;
};

struct tagRect
{
	image* img;
	DIRECTION direction;
	RECT rc;
	animation* ani;
	animation* ani2;
	animation* ani3;
	animation* ani4;
	float accel;
	float movepower;
	float x, y;
	bool leftmove;
	bool rightmove;
	bool downmove;
	bool upmove;

};

class stageBase : public gameNode
{
private:

protected:
	int movecount;

	bool getkey;

	effect* _hit;

	tagRect player;
	tagRect heroine;

	tagKey key;
	tagRect box;
	RECT temp;

	bool reset;
	bool clear;
public:
	stageBase() {};
	~stageBase() {};

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	

	
	BOOL getClear() { return clear; }
	BOOL getReset() { return reset; }
};

