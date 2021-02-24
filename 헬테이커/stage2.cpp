#include "stdafx.h"
#include "stage2.h"


HRESULT stage2::init()
{
	clear = false;
	reset = false;
	if (clear == false || reset == false)
	{
		stance();
		estance();
		
		_hit = new effect;
		_hit->init(IMAGEMANAGER->findImage("히트"), 148, 200, 1, 0.35f);
	
	
		player.direction = OBJ_RIGHT_IDLE;
		//벽
		for (int i = 0; i < WALLMAX; i++)
		{
			wall[0].rc = RectMakeCenter(WINSIZEX / 2 - 100, WINSIZEY / 2 - 475, 300, 100);
			wall[1].rc = RectMakeCenter(WINSIZEX / 2 - 300, WINSIZEY / 2 - 325, 100, 200);
			wall[2].rc = RectMakeCenter(WINSIZEX / 2 - 400, WINSIZEY / 2 - 175, 100, 100);
			wall[3].rc = RectMakeCenter(WINSIZEX / 2 - 300, WINSIZEY / 2 + 25, 100, 300);
			wall[4].rc = RectMakeCenter(WINSIZEX / 2 - 100, WINSIZEY / 2 + 275, 300, 200);
			wall[5].rc = RectMakeCenter(WINSIZEX / 2 + 150, WINSIZEY / 2 + 425, 200, 100);
			wall[6].rc = RectMakeCenter(WINSIZEX / 2 + 300, WINSIZEY / 2 + 325, 100, 100);
			wall[7].rc = RectMakeCenter(WINSIZEX / 2 + 400, WINSIZEY / 2 + 225, 100, 100);
			wall[8].rc = RectMakeCenter(WINSIZEX / 2 + 300, WINSIZEY / 2 + 125, 100, 100);
			wall[9].rc = RectMakeCenter(WINSIZEX / 2 + 400, WINSIZEY / 2 + 25, 100, 100);
			wall[10].rc = RectMakeCenter(WINSIZEX / 2 + 250, WINSIZEY / 2 - 75, 200, 100);
			wall[11].rc = RectMakeCenter(WINSIZEX / 2 + 100, WINSIZEY / 2 - 275, 100, 300);
			wall[12].rc = RectMakeCenter(WINSIZEX / 2 - 100, WINSIZEY / 2 + 25, 100, 100);
		}

		heroine.img = IMAGEMANAGER->findImage("히로인2");
		//키,박스
		box.img = IMAGEMANAGER->findImage("상자");
		key.img = IMAGEMANAGER->findImage("열쇠");

		for (int i = 0; i < OBSMAX; i++)
		{
			obs[i].img = IMAGEMANAGER->findImage("바위");
		}
		for (int i = 0; i < ENEMYMAX; i++)
		{
			enemy[i].direction = OBJ_RIGHT_IDLE;
			enemy[i].ani2 = new animation;
			enemy[i].ani2->init(1200, 100, 100, 100);
			enemy[i].ani2->setDefPlayFrame(false, true);
			enemy[i].ani2->setFPS(1);


			enemy[i].ani3 = new animation;
			enemy[i].ani3->init(600, 100, 100, 100);
			enemy[i].ani3->setDefPlayFrame(false, false);
			enemy[i].ani3->setFPS(1);

			enemy[i].ani = enemy[i].ani2;
		
		}



		player.ani2 = new animation;
		player.ani2->init(1200, 100, 100, 100);
		player.ani2->setDefPlayFrame(false, true);
		player.ani2->setFPS(1);

		player.ani3 = new animation;
		player.ani3->init(600, 100, 100, 100);
		player.ani3->setDefPlayFrame(false, false);
		player.ani3->setFPS(2);

		player.ani4 = new animation;
		player.ani4->init(1200, 100, 100, 100);
		player.ani4->setDefPlayFrame(false, false);
		player.ani4->setFPS(1);
		player.ani = player.ani2;

		heroine.ani = new animation;
		heroine.ani->init(1200, 100, 100, 100);
		heroine.ani->setDefPlayFrame(false, true);
		heroine.ani->setFPS(1);

		player.x = WINSIZEX / 2 - 100;
		player.y = WINSIZEY / 2 - 375;

		key.x = WINSIZEX / 2;
		key.y = WINSIZEY / 2 - 175;

		box.x = WINSIZEX / 2 + 100;
		box.y = WINSIZEY / 2 + 225;

		heroine.x = WINSIZEX / 2 + 200;
		heroine.y = WINSIZEY / 2 + 325;
		heroine.rc = RectMakeCenter(heroine.x, heroine.y, 80, 80);


		enemy[0].x = WINSIZEX / 2 - 200;
		enemy[0].y = WINSIZEY / 2 + 25;

		enemy[1].x = WINSIZEX / 2 + 200;
		enemy[1].y = WINSIZEY / 2 + 125;



		obs[0].x = WINSIZEX / 2 - 200;
		obs[0].y = WINSIZEY / 2 - 275;

		obs[1].x = WINSIZEX / 2 - 100;
		obs[1].y = WINSIZEY / 2 - 275;

		obs[2].x = WINSIZEX / 2;
		obs[2].y = WINSIZEY / 2 - 275;

		obs[3].x = WINSIZEX / 2 - 100;
		obs[3].y = WINSIZEY / 2 - 75;

		obs[4].x = WINSIZEX / 2;
		obs[4].y = WINSIZEY / 2 + 25;

		obs[5].x = WINSIZEX / 2 + 100;
		obs[5].y = WINSIZEY / 2 + 25;

		obs[6].x = WINSIZEX / 2;
		obs[6].y = WINSIZEY / 2 + 125;

		obs[7].x = WINSIZEX / 2 + 200;
		obs[7].y = WINSIZEY / 2 + 225;

		


		movecount = 40;
	}
	

	return S_OK;
}

void stage2::release()
{
	stageBase::release();
	SAFE_DELETE(player.img);
	SAFE_DELETE(heroine.img);
	SAFE_DELETE(key.img);
	SAFE_DELETE(box.img);
	for (int i = 0; i < OBSMAX; i++)
	{
		SAFE_DELETE(obs[i].img);
	}
	for (int i = 0; i < ENEMYMAX; i++)
	{
		SAFE_DELETE(enemy[i].img);
	}
}

void stage2::update()
{
	//movecount가 0보다 작아지면 다시시작
		if (movecount < 0 || KEYMANAGER->isOnceKeyDown('R'))
		{
			getkey = false;
			reset = true;
		}
	if (clear == false || reset == false)
	{
		
		stance();
		estance();
		collision();


		playermove();

		player.ani->resume();
		heroine.ani->resume();
		for (int i = 0; i < ENEMYMAX; i++)
		{
			enemy[i].rc = RectMakeCenter(enemy[i].x, enemy[i].y, 80, 80);
			enemy[i].ani->resume();
			enemy[i].ani2->frameUpdate(TIMEMANAGER->getElapsedTime() * 20);
			enemy[i].ani3->frameUpdate(TIMEMANAGER->getElapsedTime() * 20);
		}


		player.ani2->frameUpdate(TIMEMANAGER->getElapsedTime() * 20);
		player.ani3->frameUpdate(TIMEMANAGER->getElapsedTime() * 15);
		player.ani4->frameUpdate(TIMEMANAGER->getElapsedTime() * 20);

		heroine.ani->frameUpdate(TIMEMANAGER->getElapsedTime() * 20);

		inter[0].x = player.x - 100;
		inter[0].y = player.y;
		inter[0].rc = RectMakeCenter(inter[0].x, inter[0].y, 10, 10);		//좌

		inter[1].x = player.x + 100;
		inter[1].y = player.y;
		inter[1].rc = RectMakeCenter(inter[1].x, inter[1].y, 10, 10);		//우

		inter[2].x = player.x;
		inter[2].y = player.y - 100;
		inter[2].rc = RectMakeCenter(inter[2].x, inter[2].y, 10, 10);		//상

		inter[3].x = player.x;
		inter[3].y = player.y + 100;
		inter[3].rc = RectMakeCenter(inter[3].x, inter[3].y, 10, 10);		//하

		for (int i = 0; i < OBSMAX; i++)
		{
			obs[i].rc = RectMakeCenter(obs[i].x, obs[i].y, 80, 80);
		}



		box.rc = RectMakeCenter(box.x, box.y, 80, 80);
		key.rc = RectMakeCenter(key.x, key.y, 80, 80);
		player.rc = RectMakeCenter(player.x, player.y, 100, 100);
		_hit->update();
	}

	

	//히로인 앞에 도착하면 클리어

	for (int i = 0; i < INTERSECT; i++)
	{
		if (IntersectRect(&temp, &inter[i].rc, &heroine.rc))
		{
			clear = true;
		}
	}

}

void stage2::render()
{
	if (clear == false || reset == false)
	{
		IMAGEMANAGER->findImage("stage2")->render(getMemDC());

		box.img->render(getMemDC(), box.rc.left - 8, box.rc.top - 8);
		key.img->render(getMemDC(), key.rc.left, key.rc.top);
		player.img->aniRender(getMemDC(), player.rc.left, player.rc.top, player.ani);
		heroine.img->aniRender(getMemDC(), heroine.rc.left - 10, heroine.rc.top - 10, heroine.ani);

		for (int i = 0; i < OBSMAX; i++)
		{
			obs[i].img->render(getMemDC(), obs[i].rc.left - 10, obs[i].rc.top - 10);
		}
		for (int i = 0; i < ENEMYMAX; i++)
		{
			enemy[i].img->aniRender(getMemDC(), enemy[i].rc.left - 10, enemy[i].rc.top - 10, enemy[i].ani);
		}


		if (KEYMANAGER->isToggleKey(VK_TAB))
		{
			Rectangle(getMemDC(), box.rc);
			Rectangle(getMemDC(), key.rc);
			Rectangle(getMemDC(), heroine.rc);
			Rectangle(getMemDC(), player.rc);


			for (int i = 0; i < WALLMAX; i++)
			{
				Rectangle(getMemDC(), wall[i].rc);
			}
			for (int i = 0; i < OBSMAX; i++)
			{
				Rectangle(getMemDC(), obs[i].rc);
			}
			for (int i = 0; i < ENEMYMAX; i++)
			{
				Rectangle(getMemDC(), enemy[i].rc);
			}
			for (int i = 0; i < INTERSECT; i++)
			{
				Rectangle(getMemDC(), inter[i].rc);
			}


		}
		HBRUSH brush = CreateSolidBrush(RGB(0, 255, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(getMemDC(), brush);
		HFONT myFont = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, "궁서체");
		HFONT oldFont = (HFONT)SelectObject(getMemDC(), myFont);
		char str[256];
		sprintf_s(str, "남은 이동횟수 : %d", movecount);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		TextOut(getMemDC(), WINSIZEX / 2 - 600, WINSIZEY / 2 - 300, str, strlen(str));
		SelectObject(getMemDC(), oldFont);
		DeleteObject(myFont);
		SelectObject(getMemDC(), oldBrush);
		DeleteObject(brush);

		_hit->render();
	}
}

void stage2::stance()
{
	switch (player.direction)
	{
	case OBJ_LEFT_IDLE:
		player.img = IMAGEMANAGER->findImage("왼쪽 기본");
		player.ani = player.ani2;
		break;
	case OBJ_RIGHT_IDLE:
		player.img = IMAGEMANAGER->findImage("오른쪽 기본");
		player.ani = player.ani2;
		break;
	case OBJ_LEFT_KICK:
		player.img = IMAGEMANAGER->findImage("왼쪽 킥");
		player.ani = player.ani4;
		if (player.ani4->isPlay() == false)
		{
			player.ani4->stop();
		}
		break;
	case OBJ_RIGHT_KICK:
		player.img = IMAGEMANAGER->findImage("오른쪽 킥");
		player.ani = player.ani4;
		if (player.ani4->isPlay() == false)
		{
			player.ani4->stop();
		}
		break;
	case OBJ_LEFT_DASH:
		player.img = IMAGEMANAGER->findImage("왼쪽 대쉬");
		player.ani = player.ani3;
		if (player.ani3->isPlay() == false)
		{
			player.ani3->stop();
		}
		break;
	case OBJ_RIGHT_DASH:
		player.img = IMAGEMANAGER->findImage("오른쪽 대쉬");
		player.ani = player.ani3;
		if (player.ani3->isPlay() == false)
		{
			player.ani3->stop();
		}
		break;
	}
}

void stage2::estance()
{
	for (int i = 0; i < ENEMYMAX; i++)
	{
		switch (enemy[i].direction)
		{
		case OBJ_LEFT_IDLE:
			enemy[i].img = IMAGEMANAGER->findImage("해골 왼쪽 기본");
			enemy[i].ani = enemy[i].ani2;
			break;
		case OBJ_RIGHT_IDLE:
			enemy[i].img = IMAGEMANAGER->findImage("해골 오른쪽 기본");
			enemy[i].ani = enemy[i].ani2;
			break;
		case OBJ_LEFT_DASH:
			enemy[i].img = IMAGEMANAGER->findImage("해골 왼쪽 히트");
			enemy[i].ani = enemy[i].ani3;
			if (enemy[i].ani3->isPlay() == false)
			{
				enemy[i].ani3->stop();
			}
			break;
		case OBJ_RIGHT_DASH:
			enemy[i].img = IMAGEMANAGER->findImage("해골 오른쪽 히트");
			enemy[i].ani = enemy[i].ani3;
			if (enemy[i].ani3->isPlay() == false)
			{
				enemy[i].ani3->stop();
			}
			break;
		}
	}
}


void stage2::playermove()
{


	//플레이어의 왼쪽 이동 및 왼쪽 킥
	if (player.movepower == 0 && KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		movecount--;
		for (int i = 0; i < OBSMAX; ++i)
		{

			if (IntersectRect(&temp, &obs[i].rc, &inter[0].rc))
			{
				_hit->startEffect(player.x - 70, player.y);
				player.direction = OBJ_LEFT_KICK;
				obs[i].movepower = 20;
				obs[i].accel = 2.225f;
				obs[i].leftmove = true;
				player.leftmove = false;
				player.movepower = 0;
				break;
			}
	
			if (IntersectRect(&temp, &enemy[i].rc, &inter[0].rc))
			{
				_hit->startEffect(player.x - 70, player.y);
				player.direction = OBJ_LEFT_KICK;
				enemy[i].direction = OBJ_RIGHT_DASH;
				enemy[i].movepower = 20;
				enemy[i].accel = 2.225f;
				enemy[i].leftmove = true;
				player.leftmove = false;
				player.movepower = 0;
				break;
			}

			else
			{
				player.leftmove = true;
				player.movepower = 20;
				player.accel = 2.225f;
			}
		}

	}

	if (player.leftmove)
	{
		player.direction = OBJ_LEFT_DASH;
		player.x -= player.movepower;
		player.movepower -= player.accel;

		if (player.movepower <= 0)
		{
			player.leftmove = false;
			player.movepower = 0;
			player.accel = 0;
			player.direction = OBJ_LEFT_IDLE;

		}
	}

	//플레이어의 오른쪽이동 및 오른쪽 킥
	if (player.movepower == 0 && KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		movecount--;
		for (int i = 0; i < OBSMAX; ++i)
		{
			RECT temp;
			if (IntersectRect(&temp, &obs[i].rc, &inter[1].rc))
			{
				_hit->startEffect(player.x + 70, player.y);
				player.direction = OBJ_RIGHT_KICK;
				obs[i].movepower = 20;
				obs[i].accel = 2.225f;
				obs[i].rightmove = true;
				player.rightmove = false;
				player.movepower = 0;
				break;
			}
			if (IntersectRect(&temp, &enemy[i].rc, &inter[1].rc))
			{
				_hit->startEffect(player.x + 70, player.y);
				player.direction = OBJ_RIGHT_KICK;
				enemy[i].direction = OBJ_LEFT_DASH;
				enemy[i].movepower = 20;
				enemy[i].accel = 2.225f;
				enemy[i].rightmove = true;
				player.rightmove = false;
				player.movepower = 0;
				break;
			}

			else
			{
				player.rightmove = true;
				player.movepower = 20;
				player.accel = 2.225f;
			}
		}

	}

	if (player.rightmove)
	{
		player.direction = OBJ_RIGHT_DASH;
		player.x += player.movepower;
		player.movepower -= player.accel;

		if (player.movepower <= 0)
		{
			player.rightmove = false;
			player.movepower = 0;
			player.accel = 0;
			player.direction = OBJ_RIGHT_IDLE;

		}
	}



	//플레이어의 위쪽 이동 및 위쪽 킥
	if (player.movepower == 0 && KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		movecount--;
		for (int i = 0; i < OBSMAX; ++i)
		{
			RECT temp;
			if (IntersectRect(&temp, &obs[i].rc, &inter[2].rc))
			{
				_hit->startEffect(player.x, player.y - 70);
				if (player.direction == OBJ_RIGHT_IDLE) player.direction = OBJ_RIGHT_KICK;
				if (player.direction == OBJ_LEFT_IDLE) player.direction = OBJ_LEFT_KICK;

				obs[i].movepower = 20;
				obs[i].accel = 2.225f;
				obs[i].upmove = true;
				player.upmove = false;
				player.movepower = 0;
				break;
			}
			if (IntersectRect(&temp, &enemy[i].rc, &inter[2].rc))
			{
				_hit->startEffect(player.x, player.y - 70);
				if (player.direction == OBJ_RIGHT_IDLE)
				{
					player.direction = OBJ_RIGHT_KICK;
					enemy[i].direction = OBJ_LEFT_DASH;
				}
				if (player.direction == OBJ_LEFT_IDLE)
				{
					player.direction = OBJ_LEFT_KICK;
					enemy[i].direction = OBJ_RIGHT_DASH;
				}
				enemy[i].movepower = 20;
				enemy[i].accel = 2.225f;
				enemy[i].upmove = true;
				player.upmove = false;
				player.movepower = 0;
				break;
			}
			else
			{
				player.upmove = true;
				player.movepower = 20;
				player.accel = 2.225f;
			}
		}
	}

	if (player.upmove)
	{
		if (player.direction == OBJ_RIGHT_IDLE) player.direction = OBJ_RIGHT_DASH;
		if (player.direction == OBJ_LEFT_IDLE) player.direction = OBJ_LEFT_DASH;
		player.y -= player.movepower;
		player.movepower -= player.accel;

		if (player.movepower <= 0)
		{
			player.upmove = false;
			player.movepower = 0;
			player.accel = 0;
			if (player.direction == OBJ_RIGHT_DASH) player.direction = OBJ_RIGHT_IDLE;
			if (player.direction == OBJ_LEFT_DASH) player.direction = OBJ_LEFT_IDLE;

		}
	}

	//플레이어의 아래 이동 및 아래쪽 킥
	if (player.movepower == 0 && KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		movecount--;
		for (int i = 0; i < OBSMAX; ++i)
		{
			RECT temp;
			if (IntersectRect(&temp, &obs[i].rc, &inter[3].rc))
			{
				_hit->startEffect(player.x, player.y + 70);
				if (player.direction == OBJ_RIGHT_IDLE) player.direction = OBJ_RIGHT_KICK;
				if (player.direction == OBJ_LEFT_IDLE) player.direction = OBJ_LEFT_KICK;
				obs[i].movepower = 20;
				obs[i].accel = 2.225f;
				obs[i].downmove = true;
				player.downmove = false;
				player.movepower = 0;
				break;
			}
			if (IntersectRect(&temp, &enemy[i].rc, &inter[3].rc))
			{
				_hit->startEffect(player.x, player.y + 70);
				if (player.direction == OBJ_RIGHT_IDLE)
				{
					player.direction = OBJ_RIGHT_KICK;
					enemy[i].direction = OBJ_LEFT_DASH;
				}
				if (player.direction == OBJ_LEFT_IDLE)
				{
					player.direction = OBJ_LEFT_KICK;
					enemy[i].direction = OBJ_RIGHT_DASH;
				}
				enemy[i].movepower = 20;
				enemy[i].accel = 2.225f;
				enemy[i].downmove = true;
				player.downmove = false;
				player.movepower = 0;
				break;
			}
			else
			{
				player.downmove = true;
				player.movepower = 20;
				player.accel = 2.225f;
			}
		}

	}

	if (player.downmove)
	{
		if (player.direction == OBJ_RIGHT_IDLE) player.direction = OBJ_RIGHT_DASH;
		if (player.direction == OBJ_LEFT_IDLE) player.direction = OBJ_LEFT_DASH;

		player.y += player.movepower;
		player.movepower -= player.accel;

		if (player.movepower <= 0)
		{
			player.downmove = false;
			player.movepower = 0;
			player.accel = 0;
			if (player.direction == OBJ_RIGHT_DASH) player.direction = OBJ_RIGHT_IDLE;
			if (player.direction == OBJ_LEFT_DASH) player.direction = OBJ_LEFT_IDLE;

		}
	}


}

void stage2::collision()
{
	//키를 먹었다
	if (IntersectRect(&temp, &player.rc, &key.rc))
	{
		getkey = true;
		if (getkey)
		{
			key.x = 50000;
		}
	}


	for (int i = 0; i < OBSMAX; i++)
	{
		//돌
		//오른쪽에서 왼쪽으로 킥을 날렸을 떄
		if (obs[i].leftmove)
		{
			if (obs[i].movepower <= 0)
			{
				obs[i].movepower = 0;
				obs[i].accel = 0;
				obs[i].leftmove = false;
				player.direction = OBJ_LEFT_IDLE;
			}

			obs[i].x -= obs[i].movepower;
			obs[i].movepower -= obs[i].accel;
		}


		//왼쪽에서 오른쪽으로 킥을 갈길 때
		if (obs[i].rightmove)
		{
			if (obs[i].movepower <= 0)
			{
				obs[i].movepower = 0;
				obs[i].accel = 0;
				obs[i].rightmove = false;
				player.direction = OBJ_RIGHT_IDLE;
			}

			obs[i].x += obs[i].movepower;
			obs[i].movepower -= obs[i].accel;
		}



		//아래에서 위로 킥을 날길 때
		if (obs[i].upmove)
		{
			if (obs[i].movepower <= 0)
			{
				obs[i].movepower = 0;
				obs[i].accel = 0;
				obs[i].upmove = false;
				if (player.direction == OBJ_RIGHT_KICK) player.direction = OBJ_RIGHT_IDLE;
				if (player.direction == OBJ_LEFT_KICK) player.direction = OBJ_LEFT_IDLE;
			}

			obs[i].y -= obs[i].movepower;
			obs[i].movepower -= obs[i].accel;
		}

		//위에서 아래로 킥을 갈길 때
		if (obs[i].downmove)
		{
			if (obs[i].movepower <= 0)
			{
				obs[i].movepower = 0;
				obs[i].accel = 0;
				obs[i].downmove = false;
				if (player.direction == OBJ_RIGHT_KICK) player.direction = OBJ_RIGHT_IDLE;
				if (player.direction == OBJ_LEFT_KICK) player.direction = OBJ_LEFT_IDLE;
			}

			obs[i].y += obs[i].movepower;
			obs[i].movepower -= obs[i].accel;
		}

		//해골
		//오른쪽에서 왼쪽으로 킥을 날렸을 떄
		if (enemy[i].leftmove)
		{
			if (enemy[i].movepower <= 0)
			{
				enemy[i].movepower = 0;
				enemy[i].accel = 0;
				enemy[i].leftmove = false;
				player.direction = OBJ_LEFT_IDLE;
				enemy[i].direction = OBJ_RIGHT_IDLE;
			}

			enemy[i].x -= enemy[i].movepower;
			enemy[i].movepower -= enemy[i].accel;
		}


		//왼쪽에서 오른쪽으로 킥을 갈길 때
		if (enemy[i].rightmove)
		{
			if (enemy[i].movepower <= 0)
			{
				enemy[i].movepower = 0;
				enemy[i].accel = 0;
				enemy[i].rightmove = false;
				player.direction = OBJ_RIGHT_IDLE;
				enemy[i].direction = OBJ_LEFT_IDLE;
			}

			enemy[i].x += enemy[i].movepower;
			enemy[i].movepower -= enemy[i].accel;
		}



		//아래에서 위로 킥을 날길 때
		if (enemy[i].upmove)
		{
			if (enemy[i].movepower <= 0)
			{
				enemy[i].movepower = 0;
				enemy[i].accel = 0;
				enemy[i].upmove = false;
				if (player.direction == OBJ_RIGHT_KICK) player.direction = OBJ_RIGHT_IDLE;
				if (player.direction == OBJ_LEFT_KICK) player.direction = OBJ_LEFT_IDLE;
				if (enemy[i].direction == OBJ_RIGHT_DASH) enemy[i].direction = OBJ_RIGHT_IDLE;
				if (enemy[i].direction == OBJ_LEFT_DASH) enemy[i].direction = OBJ_LEFT_IDLE;

			}

			enemy[i].y -= enemy[i].movepower;
			enemy[i].movepower -= enemy[i].accel;
		}

		//위에서 아래로 킥을 갈길 때
		if (enemy[i].downmove)
		{
			if (enemy[i].movepower <= 0)
			{
				enemy[i].movepower = 0;
				enemy[i].accel = 0;
				enemy[i].downmove = false;
				if (player.direction == OBJ_RIGHT_KICK) player.direction = OBJ_RIGHT_IDLE;
				if (player.direction == OBJ_LEFT_KICK) player.direction = OBJ_LEFT_IDLE;


				if (enemy[i].direction == OBJ_RIGHT_DASH) enemy[i].direction = OBJ_RIGHT_IDLE;
				if (enemy[i].direction == OBJ_LEFT_DASH) enemy[i].direction = OBJ_LEFT_IDLE;

			}

			enemy[i].y += enemy[i].movepower;
			enemy[i].movepower -= enemy[i].accel;
		}

		//상자
		//오른쪽에서 왼쪽으로 킥을 날렸을 떄
		if (box.leftmove)
		{
			if (box.movepower <= 0)
			{
				box.movepower = 0;
				box.accel = 0;
				box.leftmove = false;
				player.direction = OBJ_LEFT_IDLE;
				box.direction = OBJ_RIGHT_IDLE;
			}

			box.x -= 0;
			box.movepower -= 0;
		}


		//왼쪽에서 오른쪽으로 킥을 갈길 때
		if (box.rightmove)
		{
			if (box.movepower <= 0)
			{
				box.movepower = 0;
				box.accel = 0;
				box.rightmove = false;
				player.direction = OBJ_RIGHT_IDLE;
				box.direction = OBJ_LEFT_IDLE;
			}

			box.x += 0;
			box.movepower -= 0;
		}



		//아래에서 위로 킥을 날길 때
		if (box.upmove)
		{
			if (box.movepower <= 0)
			{
				box.movepower = 0;
				box.accel = 0;
				box.upmove = false;
				if (player.direction == OBJ_RIGHT_KICK) player.direction = OBJ_RIGHT_IDLE;
				if (player.direction == OBJ_LEFT_KICK) player.direction = OBJ_LEFT_IDLE;
				if (box.direction == OBJ_RIGHT_DASH) box.direction = OBJ_RIGHT_IDLE;
				if (box.direction == OBJ_LEFT_DASH) box.direction = OBJ_LEFT_IDLE;

			}

			box.y -= 0;
			box.movepower -= 0;
		}

		//위에서 아래로 킥을 갈길 때
		if (box.downmove)
		{
			if (box.movepower <= 0)
			{
				box.movepower = 0;
				box.accel = 0;
				box.downmove = false;
				if (player.direction == OBJ_RIGHT_KICK) player.direction = OBJ_RIGHT_IDLE;
				if (player.direction == OBJ_LEFT_KICK) player.direction = OBJ_LEFT_IDLE;


				if (box.direction == OBJ_RIGHT_DASH) box.direction = OBJ_RIGHT_IDLE;
				if (box.direction == OBJ_LEFT_DASH) box.direction = OBJ_LEFT_IDLE;

			}

			box.y += 0;
			box.movepower -= 0;
		}
	}


	//맵밖으로 나가지 않도록 함
	for (int i = 0; i < WALLMAX; i++)
	{
		for (int j = 0; j < INTERSECT; j++)
		{
			if (IntersectRect(&temp, &inter[j].rc, &box.rc))
			{
				if (box.leftmove)
				{
					box.x = wall[i].rc.right + 110;
				}
				if (box.rightmove)
				{
					box.x = wall[i].rc.left - 110;
				}
				if (box.upmove)
				{
					box.y = wall[i].rc.bottom + 110;
				}
				if (box.downmove)
				{
					box.y = wall[i].rc.top - 110;
				}
				break;
			}
		}


		//돌이 맵밖으로 못나감
		for (int j = 0; j < OBSMAX; j++)
		{
			if (IntersectRect(&temp, &wall[i].rc, &obs[j].rc))
			{
				if (obs[j].leftmove)
				{
					obs[j].x = wall[i].rc.right + 110;
				}
				if (obs[j].rightmove)
				{
					obs[j].x = wall[i].rc.left - 110;
				}
				if (obs[j].upmove)
				{
					obs[j].y = wall[i].rc.bottom + 110;
				}
				if (obs[j].downmove)
				{
					obs[j].y = wall[i].rc.top - 110;
				}
				break;
			}

		}

		//돌과 돌이 부딪히면 원위치
		for (int i = 0; i < OBSMAX; i++)
		{
			for (int j = 0; j < OBSMAX; j++)
			{
				if (i == j) continue;
				if (IntersectRect(&temp, &obs[i].rc, &obs[j].rc))
				{
					if (obs[i].leftmove)
					{
						obs[i].x = obs[j].rc.right + 110;
					}
					if (obs[i].rightmove)
					{
						obs[i].x = obs[j].rc.left - 110;
					}
					if (obs[i].upmove)
					{
						obs[i].y = obs[j].rc.bottom + 110;
					}
					if (obs[i].downmove)
					{
						obs[i].y = obs[j].rc.top - 110;
					}
					break;

				}
			}
		}
		//돌과 해골 또는 히로인이 부딪히면 원위치
		for (int i = 0; i < OBSMAX; i++)
		{
			for (int j = 0; j < ENEMYMAX; j++)
			{
				if (IntersectRect(&temp, &obs[i].rc, &enemy[j].rc))
				{
					if (obs[i].leftmove)
					{
						obs[i].x = enemy[j].rc.right + 110;
					}
					if (obs[i].rightmove)
					{
						obs[i].x = enemy[j].rc.left - 110;
					}
					if (obs[i].upmove)
					{
						obs[i].y = enemy[j].rc.bottom + 110;
					}
					if (obs[i].downmove)
					{
						obs[i].y = enemy[j].rc.top - 110;
					}
					break;
				}
			}
			if (IntersectRect(&temp, &obs[i].rc, &heroine.rc))
			{
				if (obs[i].leftmove)
				{
					obs[i].x = heroine.rc.right + 110;
				}
				if (obs[i].rightmove)
				{
					obs[i].x = heroine.rc.left - 110;
				}
				if (obs[i].upmove)
				{
					obs[i].y = heroine.rc.bottom + 110;
				}
				if (obs[i].downmove)
				{
					obs[i].y = heroine.rc.top - 110;
				}
				break;
			}
		}

		//돌과 상자가 부딪히면 원위치
		for (int i = 0; i < OBSMAX; i++)
		{
			if (IntersectRect(&temp, &obs[i].rc, &box.rc))
			{
				if (obs[i].leftmove)
				{
					obs[i].x = box.rc.right + 110;
				}
				if (obs[i].rightmove)
				{
					obs[i].x = box.rc.left - 110;
				}
				if (obs[i].upmove)
				{
					obs[i].y = box.rc.bottom + 110;
				}
				if (obs[i].downmove)
				{
					obs[i].y = box.rc.top - 110;
				}
				break;

			}
		}


		//해골이 상자에 부딪히면 없어짐
		for (int j = 0; j < ENEMYMAX; j++)
		{
			if (IntersectRect(&temp, &box.rc, &enemy[j].rc))
			{
				if (enemy[j].leftmove)
				{
					enemy[j].x = 50000;
				}
				if (enemy[j].rightmove)
				{
					enemy[j].x = 50000;
				}
				if (enemy[j].upmove)
				{
					enemy[j].y = 50000;
				}
				if (enemy[j].downmove)
				{
					enemy[j].y = 50000;
				}
				break;
			}
		}
		//해골이 벽에 부딪히면 없어짐
		for (int j = 0; j < ENEMYMAX; j++)
		{
			if (IntersectRect(&temp, &wall[i].rc, &enemy[j].rc))
			{
				if (enemy[j].leftmove)
				{
					enemy[j].x = 50000;
				}
				if (enemy[j].rightmove)
				{
					enemy[j].x = 50000;
				}
				if (enemy[j].upmove)
				{
					enemy[j].y = 50000;
				}
				if (enemy[j].downmove)
				{
					enemy[j].y = 50000;
				}
				break;
			}
		}

		//해골이 히로인에 부딪히면 없어짐
		for (int j = 0; j < ENEMYMAX; j++)
		{
			if (IntersectRect(&temp, &heroine.rc, &enemy[j].rc))
			{
				if (enemy[j].leftmove)
				{
					enemy[j].x = 50000;
				}
				if (enemy[j].rightmove)
				{
					enemy[j].x = 50000;
				}
				if (enemy[j].upmove)
				{
					enemy[j].y = 50000;
				}
				if (enemy[j].downmove)
				{
					enemy[j].y = 50000;
				}
				break;
			}
		}

		//해골이 돌에 부딪히면 없어짐
		for (int i = 0; i < ENEMYMAX; i++)
		{
			for (int j = 0; j < OBSMAX; j++)
			{
				if (IntersectRect(&temp, &enemy[i].rc, &obs[j].rc))
				{
					if (enemy[i].leftmove)
					{
						enemy[i].x = 50000;
					}
					if (enemy[i].rightmove)
					{
						enemy[i].x = 50000;
					}
					if (enemy[i].upmove)
					{
						enemy[i].y = 50000;
					}
					if (enemy[i].downmove)
					{
						enemy[i].y = 50000;
					}
					break;

				}
			}
		}

		//해골과 해골이 부딪히면 움직이는 해골이 없어짐
		for (int i = 0; i < ENEMYMAX; i++)
		{
			for (int j = 0; j < ENEMYMAX; j++)
			{
				if (i == j) continue;
				if (IntersectRect(&temp, &enemy[i].rc, &enemy[j].rc))
				{
					if (enemy[i].leftmove)
					{
						enemy[i].x = 50000;
					}
					if (enemy[i].rightmove)
					{
						enemy[i].x = 50000;
					}
					if (enemy[i].upmove)
					{
						enemy[i].y = 50000;
					}
					if (enemy[i].downmove)
					{
						enemy[i].y = 50000;
					}
					break;

				}
			}
		}

		//플레이어가 맵밖으로 못나감
		if (IntersectRect(&temp, &wall[i].rc, &inter[0].rc))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
			{
				player.movepower = 0;
				player.accel = 0;
			}
		}
		if (IntersectRect(&temp, &wall[i].rc, &inter[1].rc))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
			{
				player.movepower = 0;
				player.accel = 0;
			}
		}
		if (IntersectRect(&temp, &wall[i].rc, &inter[2].rc))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_UP))
			{
				player.movepower = 0;
				player.accel = 0;
			}
		}
		if (IntersectRect(&temp, &wall[i].rc, &inter[3].rc))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
			{
				player.movepower = 0;
				player.accel = 0;
			}
		}


		//상자가 안 움직임
		if (!getkey)
		{
			if (IntersectRect(&temp, &box.rc, &inter[0].rc))
			{
				if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
				{
					player.movepower = 0;
					player.accel = 0;
				}
			}
			if (IntersectRect(&temp, &box.rc, &inter[1].rc))
			{
				if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
				{
					player.movepower = 0;
					player.accel = 0;
				}
			}
			if (IntersectRect(&temp, &box.rc, &inter[2].rc))
			{
				if (KEYMANAGER->isOnceKeyDown(VK_UP))
				{
					player.movepower = 0;
					player.accel = 0;
				}
			}
			if (IntersectRect(&temp, &box.rc, &inter[3].rc))
			{
				if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
				{
					player.movepower = 0;
					player.accel = 0;
				}
			}
		}
		else
		{
			if (IntersectRect(&temp, &box.rc, &inter[0].rc))
			{
				if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
				{
					movecount--;
					box.x = 50000;
					player.leftmove = true;
					player.movepower = 20;
					player.accel = 2.225f;
				}
			}
			if (IntersectRect(&temp, &box.rc, &inter[1].rc))
			{
				if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
				{
					movecount--;
					box.x = 50000;
					player.rightmove = true;
					player.movepower = 20;
					player.accel = 2.225f;
				}
			}
			if (IntersectRect(&temp, &box.rc, &inter[2].rc))
			{
				if (KEYMANAGER->isOnceKeyDown(VK_UP))
				{
					movecount--;
					box.x = 50000;
					player.upmove = true;
					player.movepower = 20;
					player.accel = 2.225f;
				}
			}
			if (IntersectRect(&temp, &box.rc, &inter[3].rc))
			{
				if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
				{
					movecount--;
					box.x = 50000;
					player.downmove = true;
					player.movepower = 20;
					player.accel = 2.225f;
				}
			}

		}


	}


}



