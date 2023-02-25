#include "Header.h"
#include <iostream>
#include <ctime>

using namespace std;

//����� ������
void Rules()
{
	cout << "������� ����:\n������ ���������� ������ ������� �������� ���� (������ � ������).\n������� ���� ������������ ����� ������������� ������� � ������� �� ���������� ����� ���������(*).\n� ������ ��������� ����� ���� ���� �� ��������� �������� ���������� �� �������(#).\n������ ���������� ������ ���������� �������� ����������� �������.\n� ����������� �� ���������� ������ ��������� � ������ ����� ������������ ���������� ������.\n�� ������ ������ ��������� ���� �����.\n����� ����������, ���� �� ����� ������� ��� ������, � �����������, ���� � ���� ����������� �����.\n" << endl;
}

//��������� �������� ����
void PlayFieldGeneration(Stars &PlayField)
{
	cout << "��� ������ ���� ���������� ������� ����������� ����." << endl << endl;
	
	cout << "������� ������� �������� ����:\n������ - ������������ ��������(���. ��������: 2, ����. ��������: 20);\n������ - �������������� ��������(���. ��������: 4, ����. ��������: 40)):" << endl << endl;

	cout << "������ = ";
	cin >> PlayField.Height;

	while (PlayField.Height < 2 || PlayField.Height > 20)
	{
		cout << "����� �������� ��� ������ ����������, ��������� ����." << endl << endl;
		cout << "������ = ";
		cin >> PlayField.Height;
	}

	cout << "������ = ";
	cin >> PlayField.Width;

	while (PlayField.Width < 4 || PlayField.Width > 40)
	{
		cout << "����� �������� ��� ������ ����������, ��������� ����." << endl << endl;
		cout << "������ = ";
		cin >> PlayField.Width;
	}
		
	// ���������� ������� *
	for (int i = 0; i < PlayField.Height; i++)
	{
		for (int j = 0; j < PlayField.Width; j++)
		{
			PlayField.Field[i][j] = '*';
		}
	}
}

//���� �� ����� ������ ���������
void Level(Stars& PlayField, int &Lives, int LevelNum)
{
	int RandomHeightIndex, RandomWidthIndex;
	int CurrentHeightIndex, CurrentWidthIndex;

	for (int r = 0; r < PlayField.Height * PlayField.Width; r++)
	{
		PlayFieldFill(PlayField, RandomHeightIndex, RandomWidthIndex);

		system("cls");

		cout << "������� ���������� ������: " << Lives << endl;

		PlayFieldOutPut(PlayField, LevelNum);

		if (LevelNum == 1 || LevelNum == 2 || LevelNum == 3)
			cout << "������� ���������� ����������� �������.\n���� ���������� ����������� � �������� ����� ����� 0, ������� �������� �� ��� �����������, ��� ��������������� 0, �.�. 00 ������� �������� ��� 0, 01 - 1, 02 - 2 � �.�." << endl << endl;
		else
			cout << "������� ���������� ����������� �������.\n��������� ��������� ���������� � 0, �.�. ������ ���������� ����� �������� 0, ������ - 1, ������ - 2 � �.�." << endl << endl;
		
		cout << "���������� �� ��������� = ";
		cin >> CurrentHeightIndex;

		while (CurrentHeightIndex < 0 || CurrentHeightIndex >= PlayField.Height)
		{
			cout << "����� ���������� �� ����������, ��������� ����." << endl << endl;
			cout << "���������� �� ��������� = ";
			cin >> CurrentHeightIndex;
		}

		cout << "���������� �� ������������ = ";
		cin >> CurrentWidthIndex;

		while (CurrentWidthIndex < 0 || CurrentWidthIndex >= PlayField.Width)
		{
			cout << "����� ���������� �� ����������, ��������� ����." << endl << endl;
			cout << "���������� �� ����������� = ";
			cin >> CurrentWidthIndex;
		}

		Check(RandomHeightIndex, RandomWidthIndex, CurrentHeightIndex, CurrentWidthIndex, Lives);

		if (Lives == 0)
		{
			break;
			GameEnd(Lives);
		}
	}

	GameEnd(Lives);
}


//���������� ������� #
void PlayFieldFill(Stars &PlayField, int& RandomHeightIndex, int& RandomWidthIndex)
{
	srand(time(NULL));
	
	RandomHeightIndex = rand() % PlayField.Height;
	RandomWidthIndex = rand() % PlayField.Width;

	while (PlayField.Field[RandomHeightIndex][RandomWidthIndex] == '#')
	{
		RandomHeightIndex = rand() % PlayField.Height;
		RandomWidthIndex = rand() % PlayField.Width;
	}
	
	PlayField.Field[RandomHeightIndex][RandomWidthIndex] = '#';
}

// �������� ��������� ���������
void Check(int RandomHeightIndex, int RandomWidthIndex, int CurrentHeightIndex, int CurrentWidthIndex, int& Lives)
{
	if (RandomHeightIndex == CurrentHeightIndex && RandomWidthIndex == CurrentWidthIndex)
		Lives += 0;
	else
	{
		Lives -= 1;
		cout << "\n�� ����� ������������ ���������� � �������� 1 �����." << endl << endl;
		system("pause");
	}
}

// ��������� ����
void GameEnd(int Lives)
{
	system("cls");
	if (Lives == 0)
		cout << "���� ��������.\n�� ���������, ��� ��� � ��� �� �������� ������." << endl << endl;
	else
		cout << "���� ��������.\n�� ��������, ��� ��� �� ����� ��� ���������� ���������!!!" << endl << endl;

}

// ����� �������� ����
void PlayFieldOutPut(Stars PlayField, int LevelNum)
{
	// ���������� ������� �������
	cout << endl << "    ";
	if (LevelNum == 1 || LevelNum == 2 || LevelNum == 3)
	{
		for (int j = 0; j < PlayField.Width; j++)
		{
			if (j < 10)
				cout << "0" << j << " ";
			else
				cout << j << " ";
		}
	}
	cout << endl << "   ";
	for (int j = 0; j < PlayField.Width * 3 + 2; j++)
		cout << "-";
	cout << endl;

	// ����������� ����
	for (int i = 0; i < PlayField.Height; i++)
	{
		if (LevelNum == 1 || LevelNum == 2 || LevelNum == 3)
		{
			if (i < 10)
			{
				cout << "0" << i << "|  ";
				for (int j = 0; j < PlayField.Width; j++)
				{
					cout << PlayField.Field[i][j] << "  ";
				}
			}
			else
			{
				cout << i << "|  ";
				for (int j = 0; j < PlayField.Width; j++)
				{
					cout << PlayField.Field[i][j] << "  ";
				}
			}
		}
		else
		{
			cout << "  |  ";
			for (int j = 0; j < PlayField.Width; j++)
			{
				cout << PlayField.Field[i][j] << "  ";
			}
		}
		cout << "|" << endl;
	}

	//���������� ������ �������
	cout << "   ";
	for (int j = 0; j < PlayField.Width * 3 + 2; j++)
		cout << "-";
	cout << endl << endl;
}

//������ �������� ��������
void GameStart()
{
	system("cls");

	Stars PlayField; //������ ����

	PlayFieldGeneration(PlayField);

	system("cls");

	cout << "�������� ������� ���������:\n1 �������: ������ ���� ������� ���������� ��������, ���������� ������: 3\n2 �������: ������ ���� ������� ���������� ��������, ���������� ������: 2\n3 �������: ������ ���� ������� ���������� ��������, ���������� ������: 1\n4 �������: ������ ���� �� ������� ���������� ��������, ���������� ������: 1" << endl << endl;

	int LevelNum;
	int Lives;

	cout << "������� ";
	cin >> LevelNum;

	while (LevelNum <= 0 || LevelNum > 4)
	{
		cout << "������ ������ ��������� �� ����������, ��������� ����." << endl << endl;
		cout << "������� ";
		cin >> LevelNum;
	}

	if (LevelNum == 3 || LevelNum == 4)
		Lives = 1;
	if (LevelNum == 1)
		Lives = 3;
	if (LevelNum == 2)
		Lives = 2;

	Level(PlayField, Lives, LevelNum);

	int choice;

	cout << "������ �� �� ������ ���� ������ ��� ��������� ���������?" << endl;

	cout << "����� ������ ���� ������ ������� 1, ����� ��������� ���� ������� 2" << endl << endl;

	cout << "��� �����: ";
	cin >> choice;

	while (choice <= 0 || choice > 2)
	{
		cout << "������� ������������ ��������, ��������� ����." << endl << endl;
		cout << "��� �����: ";
		cin >> choice;
	}

	if (choice == 1)
		GameStart();
	exit(0);
}