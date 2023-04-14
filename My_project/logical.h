#pragma once
#include <iostream>
#include "window_setting.h"
using namespace std;

void tinh_diem(int point)
{
	gotoXY(107, 4);
	cout << point;
}
void do_kho(int dif)
{
	if (dif == 1)
	{
		gotoXY(105, 5);
		cout << "Easy";
	}
	else if (dif == 2)
	{
		gotoXY(105, 5);
		cout << "Medium";
	}
	else if (dif == 3)
	{
		gotoXY(105, 5);
		cout << "Hard";
	}
}
void khoi_tao_ran(int toadox[], int toadoy[], int sl)
{
	int x = 45, y = 13;
	for (int i = 0; i < sl; i++)
	{
		toadox[i] = x;
		toadoy[i] = y;
		x--;
	}
}
void ve_ran(int toadox[], int toadoy[], int &sl)
{
	for (int i = 0; i < sl; i++)
	{
		gotoXY(toadox[i], toadoy[i]);
		if (i == 0)
		{
			SetColor(6);
			cout << "O";
			SetColor(7);
		}
		else
		{
			SetColor(10);
			cout << "o";
			SetColor(7);
		}
	}
	SetColor(7);
}
void xoa_ran(int toadox[], int toadoy[], int &sl)
{
	for (int i = 0; i < sl; i++)
	{
		gotoXY(toadox[i], toadoy[i]);
		cout << " ";
	}
}
void them(int a[], int x, int &sl)
{
	for (int i = sl; i > 0; i--)
	{
		a[i] = a[i - 1];
	}
	a[0] = x;
	sl++;
}
void xoa(int a[], int vt, int &sl)
{
	for (int i = vt; i < sl; i++)
	{
		a[i] = a[i + 1];
	}
	sl--;
}
bool cham_tuong(int x0, int y0)
{
	if (y0 == 1 && (x0 > 5 && x0 < 95))
		return true;
	else if (y0 == 26 && (x0 > 5 && x0 < 95))
		return true;
	else if (x0 == 95 && (y0 > 1 && y0 < 26))
		return true;
	else if (x0 == 5 && (y0 > 1 && y0 < 26))
		return true;
	return false;
}
bool cham_duoi(int toadox[], int toadoy[], int &sl)
{
	for (int i = 1; i < sl; i++)
	{
		if (toadox[0] == toadox[i] && toadoy[0] == toadoy[i])
			return true;
	}
	return false;
}
bool de_qua(int xqua, int yqua, int x[], int y[], int &sl)
{
	for (int i = 0; i < sl; i++)
	{
		if (xqua == x[i] && yqua == y[i])
			return true;
	}
	return false;
}
void tao_qua(int& xqua, int& yqua, int toadox[], int toadoy[], int &sl)
{
	do
	{
		xqua = rand() % (94 - 6 + 1) + 6;
		yqua = rand() % (25 - 2 + 1) + 2;
	} while (de_qua(xqua, yqua, toadox, toadoy, sl) == true);
	SetColor(4);
	gotoXY(xqua, yqua);
	cout << "$";
	SetColor(7);
}
bool an_qua(int xqua, int yqua, int x[], int y[])
{
	if (x[0] == xqua && y[0] == yqua)
	{
		return true;
	}
	return false;
}
void xu_ly_ran(int toadox[], int toadoy[], int x, int y, int& xqua, int& yqua, int &sl, int &point, int highscore)
{
	them(toadox, x, sl);
	them(toadoy, y, sl);
	if (an_qua(xqua, yqua, toadox, toadoy) == false)
	{
		xoa(toadox, sl - 1, sl);
		xoa(toadoy, sl - 1, sl);
	}
	else
	{
		point++; tinh_diem(point);
		if (point > highscore)
		{
			gotoXY(111, 6);
			cout << point;
		}
		tao_qua(xqua, yqua, toadox, toadoy, sl);
	}
	ve_ran(toadox, toadoy, sl);
}