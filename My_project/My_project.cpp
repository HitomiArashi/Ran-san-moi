#include <iostream>
#include <fstream>
#include "window_setting.h"
#include "Printer.h"
#include "logical.h"
#define pb push_back
#define MAX 10000
using namespace std;
int sl = 4;
int point = 0;
int dif = 1;
int main()
{
	dif = choose_dif();
	int highscore1, highscore2, highscore3, highscore_special;
	ifstream take_highscore;
	take_highscore.open("highscore.txt");
	take_highscore >> highscore1;
	take_highscore >> highscore2;
	take_highscore >> highscore3;
	take_highscore >> highscore_special;
	take_highscore.close();
	system("cls");
	ShowCur(false);
	srand(time(NULL));
	bool gameover = false;
	int x = 45, y = 13;
	int sl = 4;
	int color = 10;
	int direct = 2;
	int toadox[MAX], toadoy[MAX];
	int xqua = 0, yqua = 0;
	int speed;
	ve_tuong();
	if (dif == 1)
	{
		bang_diem(highscore1);
		speed = 200;
	}
	else if (dif == 2)
	{
		bang_diem(highscore2);
		speed = 150;
	}
	else if (dif == 3)
	{
		bang_diem(highscore3);
		speed = 100;
	}
	else if (dif == 1907)
	{
		bang_diem(highscore_special);
		speed = 0;
	}
	tinh_diem(point); do_kho(dif);
	khoi_tao_ran(toadox, toadoy, sl);
	tao_qua(xqua, yqua, toadox, toadoy, sl);
	ve_ran(toadox, toadoy, sl);
	while (gameover == false)
	{
		xoa_ran(toadox, toadoy, sl);
		if (direct == 0)
		{
			y++;
			if (y == 26)
				y = 2;
		}
		else if (direct == 1)
		{
			y--;
			if (y == 1)
				y = 25;
		}
		else if (direct == 2)
		{
			x++;
			if (x == 95)
				x = 6;
		}
		else if (direct == 3)
		{
			x--;
			if (x == 5)
				x = 94;
		}
		if (_kbhit())
		{
			char kytu = _getch();
			if (kytu == -32)
			{
				kytu = _getch();
				if (kytu == 72 && direct != 0)
					direct = 1;
				else if (kytu == 80 && direct != 1)
					direct = 0;
				else if (kytu == 75 && direct != 2)
					direct = 3;
				else if (kytu == 77 && direct != 3)
					direct = 2;
			}
			if (kytu == 'w' && direct != 0)
				direct = 1;
			else if (kytu == 's' && direct != 1)
				direct = 0;
			else if (kytu == 'd' && direct != 3)
				direct = 2;
			else if (kytu == 'a' && direct != 2)
				direct = 3;
			else if (kytu == ' ')
			{
				pause();
			}
		}
		if (dif == 1)
			xu_ly_ran(toadox, toadoy, x, y, xqua, yqua, sl, point, highscore1);
		else if (dif == 2)
			xu_ly_ran(toadox, toadoy, x, y, xqua, yqua, sl, point, highscore2);
		else if (dif == 3)
			xu_ly_ran(toadox, toadoy, x, y, xqua, yqua, sl, point, highscore3);
		else if (dif == 1907)
			xu_ly_ran(toadox, toadoy, x, y, xqua, yqua, sl, point, highscore_special);
		if (cham_duoi(toadox, toadoy, sl) == true || cham_tuong(toadox[0], toadoy[0]))
			gameover = true;
		Sleep(speed);
	}
	if (gameover == true)
	{
		if (dif == 1)
			game_over(dif, point, highscore1);
		else if (dif == 2)
			game_over(dif, point, highscore2);
		else if (dif == 3)
			game_over(dif, point, highscore3);
		else if (dif == 1907)
			game_over(dif, point, highscore_special);
	}
	ofstream save_highscore;
	save_highscore.open("highscore.txt");
	save_highscore << highscore1 << endl << highscore2 << endl << highscore3 << endl << highscore_special;
	save_highscore.close();
	Sleep(100000);
}