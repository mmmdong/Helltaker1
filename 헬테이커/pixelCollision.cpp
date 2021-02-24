#include "stdafx.h"
#include "pixelCollision.h"

HRESULT pixelCollision::init()
{
	IMAGEMANAGER->addImage("���", "mountain.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	_ball = IMAGEMANAGER->addImage("ball", "ball.bmp", 100, 100, true, RGB(255, 0, 255));

	_x = WINSIZEX / 2 - 100;
	_y = WINSIZEY / 2 + 100;

	_rc = RectMakeCenter(_x, _y, _ball->getWidth(), _ball->getHeight());

	_probeY = _y + _ball->getHeight() / 2;

	return S_OK;
}

void pixelCollision::release()
{

}

void pixelCollision::update()
{


	//Y Ž������ ���� �Ʒ��κп� �����Ѵ�
	_probeY = (int)_y + _ball->getHeight() / 2;

	//
	for (int i = _probeY - 50; i < _probeY + 50; ++i)
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("���")->getMemDC(), _x, i);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		//���࿡ ������ Į���� ����Ÿ�� �ƴϸ�
		if (!(r == 255 && g == 0 && b == 255))
		{
			//���� Y���� �ش� �ȼ������� ���� ��������ŭ ����
			_y = i - _ball->getHeight() / 2;
			break;
		}
	}

	_rc = RectMakeCenter(_x, _y, _ball->getWidth(), _ball->getHeight());

}

void pixelCollision::render()
{
	IMAGEMANAGER->findImage("���")->render(getMemDC());
	_ball->render(getMemDC(), _rc.left, _rc.top);
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), _rc);
	}
}
