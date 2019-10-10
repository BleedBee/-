#pragma once
int chess[10][9] =
{
	{ 1,2,3,4,5,4,3,2,1 },
	{ 0,0,0,0,0,0,0,0,0 },
	{ 0,6,0,0,0,0,0,6,0 },
	{ 7,0,7,0,7,0,7,0,7 },
	{ 0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0 },
	{ 11,0,11,0,11,0,11,0,11 },
	{ 0,14,0,0,0,0,0,14,0 },
	{ 0,0,0,0,0,0,0,0,0 },
	{ 12,13,8,9,10,9,8,13,12 },
};
int i = 0, j = 0;
unsigned int x = 0, y = 0;
void ChessBoard();
int MoveCursor(int choose_num);
void SetCursorPosition(int x, int y);
int JudgeLaw(int i, int j, int m, int n,int color);
int JudgeMyChess(int color);
int JudgeEnemyOrSpaceChess(int color);
int JudgeEnemyChess(int color);