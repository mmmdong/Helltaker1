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
	IMAGEMANAGER->addImage("��Ʈ", "obstacle/effect.bmp", 740, 200, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����", "obstacle/rock.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����", "item/keybox.bmp", 96, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����", "item/key.bmp", 87, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������ �⺻", "hero/idle_right.bmp", 1200, 100, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("���� �⺻", "hero/idle_left.bmp", 1200, 100, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������ �뽬", "hero/dash_right.bmp", 600, 100, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("���� �뽬", "hero/dash_left.bmp", 600, 100, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������ ű", "hero/kick_right.bmp", 1200, 100, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("���� ű", "hero/kick_left.bmp", 1200, 100, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�ذ� ������ �⺻", "obstacle/skeleton_right.bmp", 1200, 100, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�ذ� ���� �⺻", "obstacle/skeleton_left.bmp", 1200, 100, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�ذ� ������ ��Ʈ", "obstacle/skeleton_right_hit.bmp", 600, 100, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�ذ� ���� ��Ʈ", "obstacle/skeleton_left_hit.bmp", 600, 100, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("���� ��", "obstacle/thorn_up.bmp", 600, 100, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("���� �ٿ�", "obstacle/thorn_down.bmp", 600, 100, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������1", "heroine/pandemonica.bmp", 1200, 100, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������2", "heroine/azazel.bmp", 1200, 100, 12, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������3", "heroine/lucifer.bmp", 1200, 100, 12, 1, true, RGB(255, 0, 255));



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
	//================ ���� �ǵ��� ���� ==============================


	TIMEMANAGER->render(getMemDC());

	_sb->render();
	//================= �Ʒ��� �ǵ��� ���� ==============================
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

