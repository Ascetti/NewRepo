#include "Header.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
	system("chcp 1251");
	system("cls"); //������� ������� ������

	string GameRulesOpen; //�������� ������

	cout << "���� ���������" << endl << endl;

	cout << "���� �� ������ ������������ � ��������� ���� ������� �� ���������� \"��\", � ���� ������ ������� ����� ������ ������.\n� ������ �������� ������, �� �� �������� � ��� ������ �����, ������� ��� ������ ������������� ��������� ������������� ������������ � ����." << endl << endl;
	cout << "������������ � ���������? - "; cin >> GameRulesOpen;
	
	system("cls");

	if (GameRulesOpen == "��" || GameRulesOpen == "��" || GameRulesOpen == "��" || GameRulesOpen == "��" || GameRulesOpen == "lf" || GameRulesOpen == "Lf" || GameRulesOpen == "lF" || GameRulesOpen == "LF")
	{
		Rules();
		system("pause");
		system("cls");
	}

	GameStart();
	
	return 0;
}