#pragma once
#include <iostream>
#include <fstream>
#include "window_setting.h"
using namespace std;

void ve_tuong_tren()
{
	for (int i = 5; i <= 95; i++)
	{
		gotoXY(i, 1);
		cout << "+";
	}
}
void ve_tuong_duoi()
{
	for (int i = 5; i <= 95; i++)
	{
		gotoXY(i, 26);
		cout << "+";
	}
}
void ve_tuong_trai()
{
	for (int i = 1; i <= 26; i++)
	{
		gotoXY(5, i);
		cout << "+";
	}
}
void ve_tuong_phai()
{
	for (int i = 1; i <= 26; i++)
	{
		gotoXY(95, i);
		cout << "+";
	}
}
void ve_tuong()
{
	SetColor(11);
	ve_tuong_tren();
	ve_tuong_duoi();
	ve_tuong_trai();
	ve_tuong_phai();
	SetColor(7);
}
void game_over(int dif, int point, int &highscore)
{
	for (int y = 2; y < 26; y++)
	{
		for (int x = 6; x < 95; x++)
		{
			gotoXY(x, y);
			cout << " ";
		}
	}
	SetColor(6);
	gotoXY(21, 8);  cout << "##########################################################";
	gotoXY(21, 9);  cout << "#                                                        #";
	gotoXY(21, 10); cout << "#     ###    ##  ##   ## ####     ##  #   # #### #  #    #";
	gotoXY(21, 11); cout << "#    #      #  # # # # # #       #  # #   # #    # #     #";
	gotoXY(21, 12); cout << "#    #  ### #### #  #  # ####    #  # #   # #### ##      #";
	gotoXY(21, 13); cout << "#    #   #  #  # #     # #       #  #  # #  #    #       #";
	gotoXY(21, 14); cout << "#     ###   #  # #     # ####     ##    #   #### #       #";
	gotoXY(21, 15); cout << "#                                                        #";
	gotoXY(21, 16); cout << "#                    Point:                              #";
	gotoXY(21, 17); cout << "#               Difficulty:                              #";
	gotoXY(21, 18); cout << "#                                                        #";
	gotoXY(21, 19); cout << "##########################################################";
	gotoXY(49, 16); cout << point;
	if (highscore < point)
	{
		cout << " (New highscore)";
		highscore = point;
	}
	gotoXY(49, 17);
	if (dif == 1)
		cout << "Easy";
	else if (dif == 2)
		cout << "Medium";
	else if (dif == 3)
		cout << "Hard";
	SetColor(7);
}
int choose_dif()
{
	int dif;
	SetColor(12);
	gotoXY(20, 8);  cout << "##############################";
	gotoXY(20, 9);  cout << "#                            #";
	gotoXY(20, 10); cout << "#   Choose difficulty:       #";
	gotoXY(20, 11); cout << "#   1. Easy                  #";
	gotoXY(20, 12); cout << "#   2. Medium                #";
	gotoXY(20, 13); cout << "#   3. Hard                  #";
	gotoXY(20, 14); cout << "#                            #";
	gotoXY(20, 15); cout << "##############################";
	gotoXY(43, 10); cin >> dif;
	SetColor(7);
	return dif;
}
void bang_diem(int highscore)
{
	gotoXY(97, 2); cout << "######################";
	gotoXY(97, 3); cout << "#                    #";
	gotoXY(97, 4); cout << "#  Point:            #";
	gotoXY(97, 5); cout << "#  Dif:              #";
	gotoXY(97, 6); cout << "#  Highscore:        #";
	gotoXY(97, 7); cout << "#                    #";
	gotoXY(97, 8); cout << "######################";
	gotoXY(111, 6); cout << highscore;
}
void pause()
{
	gotoXY(19, 8);  cout << "############################################################";
	gotoXY(19, 9);  cout << "#                                                          #";
	gotoXY(19, 10); cout << "#     ###    ##  ##   ## ###    ###   ##  #  #  ### ###    #";
	gotoXY(19, 11); cout << "#    #      #  # # # # # #      #  # #  # #  # #    #      #";
	gotoXY(19, 12); cout << "#    #  ### #### #  #  # ###    ###  #### #  #  ##  ###    #";
	gotoXY(19, 13); cout << "#    #   #  #  # #     # #      #    #  # #  #    # #      #";
	gotoXY(19, 14); cout << "#     ###   #  # #     # ###    #    #  #  ##  ###  ###    #";
	gotoXY(19, 15); cout << "#                                                          #";
	gotoXY(19, 16); cout << "#             Press any key to continue . . .              #";
	gotoXY(19, 17); cout << "#                                                          #";
	gotoXY(19, 18); cout << "############################################################";
	gotoXY(33, 16); system("pause");
	gotoXY(19, 8);  cout << "                                                            ";
	gotoXY(19, 9);  cout << "                                                            ";
	gotoXY(19, 10); cout << "                                                            ";
	gotoXY(19, 11); cout << "                                                            ";
	gotoXY(19, 12); cout << "                                                            ";
	gotoXY(19, 13); cout << "                                                            ";
	gotoXY(19, 14); cout << "                                                            ";
	gotoXY(19, 15); cout << "                                                            ";
	gotoXY(19, 16); cout << "                                                            ";
	gotoXY(19, 17); cout << "                                                            ";
	gotoXY(19, 18); cout << "                                                            ";
}
