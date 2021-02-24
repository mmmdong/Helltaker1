#include "stdafx.h"
#include "playGround.h"



playGround::playGround()
{
}


playGround::~playGround()
{
}

HRESULT playGround::init()
{
	gameNode::init(true);
	IMAGEMANAGER->addImage("stage1", "map/stage_1.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("stage2", "map/stage_2.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("stage3", "map/stage_3.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("히트", "obstacle/effect.bmp", 740, 200, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("바위", "obstacle/rock.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("상자", "item/keybox.bmp", 96, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("열쇠", "item/key.bmp", 87, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("오른쪽 기본", "hero/idle_right.bmp", 1200, 100, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("왼쪽 기본", "hero/idle_left.bmp", 1200, 100, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("오른쪽 대쉬", "hero/dash_right.bmp", 600, 100, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("왼쪽 대쉬", "hero/dash_left.bmp", 600, 100, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("오른쪽 킥", "hero/kick_right.bmp", 1200, 100, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("왼쪽 킥", "hero/kick_left.bmp", 1200, 100, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("해골 오른쪽 기본", "obstacle/skeleton_right.bmp", 1200, 100, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("해골 왼쪽 기본", "obstacle/skeleton_left.bmp", 1200, 100, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("해골 오른쪽 히트", "obstacle/skeleton_right_hit.bmp", 600, 100, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("해골 왼쪽 히트", "obstacle/skeleton_left_hit.bmp", 600, 100, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("가시 업", "obstacle/thorn_up.bmp", 600, 100, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("가시 다운", "obstacle/thorn_down.bmp", 600, 100, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("히로인1", "heroine/pandemonica.bmp", 1200, 100, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("히로인2", "heroine/azazel.bmp", 1200, 100, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("히로인3", "heroine/lucifer.bmp", 1200, 100, 12, 1, true, RGB(255, 0, 255));



	setStage(stg1);


	return S_OK;
}


void playGround::release()
{
	gameNode::release();

	SAFE_DELETE(_sb);
}

void playGround::update()
{
	gameNode::update();
	
	
	if (_sb->getClear())
	{
		switch (nowstg)
		{
		case stg1:
			setStage(stg2);
			break;
		case stg2:
			setStage(stg3);
			break;
		case stg3:
			setStage(stg1);
			break;
		}
	}
	if (_sb->getReset())
	{
		switch (nowstg)
		{
		case stg1:
			setStage(stg1);
			break;
		case stg2:
			setStage(stg2);
			break;
		case stg3:
			setStage(stg3);
			break;
		}
	}
	_sb->update();
	
}


void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//================ 위에 건들지 마라 ==============================


	TIMEMANAGER->render(getMemDC());

	_sb->render();
	//================= 아래도 건들지 마라 ==============================
	_backBuffer->render(getHDC());
}


void playGround::setStage(STAGE stg)
{
	nowstg = stg;
	switch (stg)
	{
	case stg1:
		_sb = new stage1;
		_sb->init();
		break;
	case stg2:
		_sb = new stage2;
		_sb->init();
		break;
	case stg3:
		_sb = new stage3;
		_sb->init();
		break;
	}
}

