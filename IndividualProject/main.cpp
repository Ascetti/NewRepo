#include "Header.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
	system("chcp 1251");
	system("cls"); //очитска консоли вывода

	string GameRulesOpen; //открытие правил

	cout << "Игра Звездочки" << endl << endl;

	cout << "Если вы хотите ознакомиться с правилами игры введите на клавиатуре \"да\", в ином случае введите любой другой символ.\nВ случае пропуска правил, вы не получите к ним доступ далее, поэтому при первом использовании программы рекомендуется ознакомиться с ними." << endl << endl;
	cout << "Ознакомиться с правилами? - "; cin >> GameRulesOpen;
	
	system("cls");

	if (GameRulesOpen == "да" || GameRulesOpen == "Да" || GameRulesOpen == "дА" || GameRulesOpen == "ДА" || GameRulesOpen == "lf" || GameRulesOpen == "Lf" || GameRulesOpen == "lF" || GameRulesOpen == "LF")
	{
		Rules();
		system("pause");
		system("cls");
	}

	GameStart();
	
	return 0;
}