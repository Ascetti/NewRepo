#pragma once
#define HeightMax 20
#define WidthMax 40

//��������� �������� ����
struct Stars
{
	char Field[HeightMax][WidthMax]; //����
	int Height, Width; //������
};

void Rules();
void GameStart();
void PlayFieldGeneration(Stars &PlayField);
void Level(Stars& PlayField, int &Lives, int LevelNum);
void PlayFieldFill(Stars &PlayField, int &RandomHeightIndex, int &RandomWidthIndex);
void PlayFieldOutPut(Stars PlayField, int LevelNum);
void Check(int RandomHeightIndex, int RandomWidthIndex, int CurrentHeightIndex, int CurrentWidthIndex, int &Lives);
void GameEnd(int Lives);

