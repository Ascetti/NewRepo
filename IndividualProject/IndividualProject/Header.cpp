#include "Header.h"
#include <iostream>
#include <ctime>

using namespace std;

//вывод правил
void Rules()
{
	cout << "Правила игры:\nИгроку необходимо ввести размеры игрового поля (высоту и ширину).\nИгровое поле представляет собой прямоугольную таблицу и состоит из некоторого числа звездочек(*).\nС каждым следующим шагом игры одна из звездочек случайно заменяется на решетку(#).\nИгроку необходимо ввести координаты текущего измененного символа.\nВ зависимости от выбранного уровня сложности у игрока будет определенное количество жизней.\nЗа каждую ошибку снимается одна жизнь.\nИгрок выигрывает, если он сумел угадать все замены, и проигрывает, если у него закончились жизни.\n" << endl;
}

//генерация игрового поля
void PlayFieldGeneration(Stars &PlayField)
{
	cout << "Для начала игры необходимо выбрать размерность поля." << endl << endl;
	
	cout << "Введите размеры игрового поля:\nВысота - вертикальный параметр(мин. значение: 2, макс. значение: 20);\nШирина - горизонтальный параметр(мин. значение: 4, макс. значение: 40)):" << endl << endl;

	cout << "Высота = ";
	cin >> PlayField.Height;

	while (PlayField.Height < 2 || PlayField.Height > 20)
	{
		cout << "Такой параметр для высоты недопустим, повторите ввод." << endl << endl;
		cout << "Высота = ";
		cin >> PlayField.Height;
	}

	cout << "Ширина = ";
	cin >> PlayField.Width;

	while (PlayField.Width < 4 || PlayField.Width > 40)
	{
		cout << "Такой параметр для ширины недопустим, повторите ввод." << endl << endl;
		cout << "Ширина = ";
		cin >> PlayField.Width;
	}
		
	// заполнение массива *
	for (int i = 0; i < PlayField.Height; i++)
	{
		for (int j = 0; j < PlayField.Width; j++)
		{
			PlayField.Field[i][j] = '*';
		}
	}
}

//игра на любом уровне сложности
void Level(Stars& PlayField, int &Lives, int LevelNum)
{
	int RandomHeightIndex, RandomWidthIndex;
	int CurrentHeightIndex, CurrentWidthIndex;

	for (int r = 0; r < PlayField.Height * PlayField.Width; r++)
	{
		PlayFieldFill(PlayField, RandomHeightIndex, RandomWidthIndex);

		system("cls");

		cout << "Текущее количество жизней: " << Lives << endl;

		PlayFieldOutPut(PlayField, LevelNum);

		if (LevelNum == 1 || LevelNum == 2 || LevelNum == 3)
			cout << "Введите координаты измененного символа.\nЕсли координата однозначная и содержит перед собой 0, следует записать ее как однозначную, без предшествующего 0, т.е. 00 следует записать как 0, 01 - 1, 02 - 2 и т.д." << endl << endl;
		else
			cout << "Введите координаты измененного символа.\nНумерация координат начинается с 0, т.е. первая координата имеет значение 0, вторая - 1, третья - 2 и т.д." << endl << endl;
		
		cout << "Координата по вертикали = ";
		cin >> CurrentHeightIndex;

		while (CurrentHeightIndex < 0 || CurrentHeightIndex >= PlayField.Height)
		{
			cout << "Такая координата не существует, повторите ввод." << endl << endl;
			cout << "Координата по вертикали = ";
			cin >> CurrentHeightIndex;
		}

		cout << "Координата по горизонатали = ";
		cin >> CurrentWidthIndex;

		while (CurrentWidthIndex < 0 || CurrentWidthIndex >= PlayField.Width)
		{
			cout << "Такая координата не существует, повторите ввод." << endl << endl;
			cout << "Координата по горизонтали = ";
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


//заполнение массива #
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

// проверка введенных координат
void Check(int RandomHeightIndex, int RandomWidthIndex, int CurrentHeightIndex, int CurrentWidthIndex, int& Lives)
{
	if (RandomHeightIndex == CurrentHeightIndex && RandomWidthIndex == CurrentWidthIndex)
		Lives += 0;
	else
	{
		Lives -= 1;
		cout << "\nВы ввели неправильные координаты и потеряли 1 жизнь." << endl << endl;
		system("pause");
	}
}

// окончание игры
void GameEnd(int Lives)
{
	system("cls");
	if (Lives == 0)
		cout << "Игра окончена.\nВы проиграли, так как у вас не осталось жизней." << endl << endl;
	else
		cout << "Игра окончена.\nВы выиграли, так как вы ввели все координаты правильно!!!" << endl << endl;

}

// вывод игрового поля
void PlayFieldOutPut(Stars PlayField, int LevelNum)
{
	// оформление верхней границы
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

	// центральный блок
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

	//оформление нижней границы
	cout << "   ";
	for (int j = 0; j < PlayField.Width * 3 + 2; j++)
		cout << "-";
	cout << endl << endl;
}

//запуск игрового процесса
void GameStart()
{
	system("cls");

	Stars PlayField; //игрвое поле

	PlayFieldGeneration(PlayField);

	system("cls");

	cout << "Выберите уровень сложности:\n1 уровень: Вокруг поля указаны координаты символов, количество жизней: 3\n2 уровень: Вокруг поля указаны координаты символов, количество жизней: 2\n3 уровень: Вокруг поля указаны координаты символов, количество жизней: 1\n4 уровень: Вокруг поля не указаны координаты символов, количество жизней: 1" << endl << endl;

	int LevelNum;
	int Lives;

	cout << "Уровень ";
	cin >> LevelNum;

	while (LevelNum <= 0 || LevelNum > 4)
	{
		cout << "Такого уровня сложности не существует, повторите ввод." << endl << endl;
		cout << "Уровень ";
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

	cout << "Хотите ли вы начать игру заново или завершить программу?" << endl;

	cout << "Чтобы начать игру заново введите 1, чтобы закончить игру введите 2" << endl << endl;

	cout << "Ваш выбор: ";
	cin >> choice;

	while (choice <= 0 || choice > 2)
	{
		cout << "Введено некорректное значение, повторите ввод." << endl << endl;
		cout << "Ваш выбор: ";
		cin >> choice;
	}

	if (choice == 1)
		GameStart();
	exit(0);
}