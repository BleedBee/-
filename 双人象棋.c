#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<math.h>
#include"函数声明-结构体定义.h"

int main()
{
	int choose_num = 0, color = 0;                  // color '0'->红方 '1'->绿方
	int m = 0, n = 0,k,l,king_num=0;
	ChessBoard();
	SetCursorPosition(x, y);
	while (1)
	{
		while (choose_num != 2)
		{
			in:choose_num = MoveCursor(choose_num);
			while ((choose_num==1)&&(JudgeMyChess(color)==0))
			{
				choose_num = 0;
				choose_num = MoveCursor(choose_num);
			}
			if (choose_num == 1)
			{

				m = i, n = j;
			}
			 if((choose_num == 2) && (JudgeEnemyOrSpaceChess(color)== 0))
			{
				 choose_num = 0;
				 goto in;
			}
			if (choose_num == 2)
			{
				if (JudgeLaw(i, j, m, n,color))
				{
					chess[i][j] = chess[m][n];
					chess[m][n] = 0;
					system("cls");
					ChessBoard();
					SetCursorPosition(x, y);
				}
				else
				{
					choose_num = 0;
					goto in;
				}
			}
		}
		choose_num = 0;
		for ( k = 0; k < 10; k++)
		{
			for ( l = 0; l < 9; l++)
			{
				if ((chess[k][l] == 5) || (chess[k][l] == 10))
				{
					king_num++;
				}
			}
		}
		if (king_num != 2)
		{
			x = 15, y = 19;
			SetCursorPosition(x, y);
			if (color == 0)
			{
				printf("RED ARE WIN\n");
			}
			else
			{
				printf("GREEN ARE WIN\n");
			}
			exit(1);
		}
		int red_king_i, red_king_j;
		int green_king_i, green_king_j;
		for (k = 0; k < 10; k++)
		{
			for (l = 0; l < 9; l++)
			{
				if (chess[k][l] == 5)
				{
					green_king_i = k;
					green_king_j = l;
				}
			}
		}
		for (k = 0; k < 10; k++)
		{
			for (l = 0; l < 9; l++)
			{
				if (chess[k][l] == 10)
				{
					red_king_i = k;
					red_king_j = l;
				}
			}
		}
		if (red_king_j == green_king_j)
		{
			int chees_num = 0,x;
			for (x = 1; x < red_king_i - green_king_i; x++)
			{
				if (chess[red_king_i - x][red_king_j] != 0)
				{
					chees_num++;
				}
			}
			if (chees_num == 0)
			{
				x = 15, y = 19;
				SetCursorPosition(x, y);
				if (color == 0)
				{
					printf("GREEN ARE WIN\n");
				}
				else
				{
					printf("RED ARE WIN\n");
				}
				exit(1);
			}
		}
		king_num = 0;
		if (color==0)
		{
			color = 1;
		}
		else
		{
			color = 0;
		}
	}

}

void ChessBoard()
{
	/*规定：0->|，1->車，2-->馬，3->象，4->士，5->将，6->炮，7->卒，8->相，9->仕，10->帥，11->兵*/
	system("color");
	int i, j;
	for (i = 0; i < 5; i++)
	{
		if (i == 0)
		{
			for (j = 0; j < 8; j++)
			{
				switch (chess[i][j])
				{
				case 0:printf("|----"); break;
				case 1:printf("\033[40;32m車\033[0m---"); break;
				case 2:printf("\033[40;32m馬\033[0m---"); break;
				case 3:printf("\033[40;32m象\033[0m---"); break;
				case 4:printf("\033[40;32m士\033[0m---"); break;
				case 5:printf("\033[40;32m将\033[0m---"); break;
				case 6:printf("\033[40;32m炮\033[0m---"); break;
				case 7:printf("\033[40;32m卒\033[0m---"); break;
				case 8:printf("\033[40;31m相\033[0m---"); break;
				case 9:printf("\033[40;31m仕\033[0m---"); break;
				case 10:printf("\033[40;31m帥\033[0m---"); break;	
				case 11:printf("\033[40;31m兵\033[0m---"); break;
				case 12:printf("\033[40;31m車\033[0m---"); break;
				case 13:printf("\033[40;31m馬\033[0m---"); break;
				case 14:printf("\033[40;31m炮\033[0m---"); break;
				default:
					break;
				}
			}
			switch (chess[i][j])
			{
			case 0:printf("|"); break;
			case 1:printf("\033[40;32m車\033[0m"); break;
			case 2:printf("\033[40;32m馬\033[0m"); break;
			case 3:printf("\033[40;32m象\033[0m"); break;
			case 4:printf("\033[40;32m士\033[0m"); break;
			case 5:printf("\033[40;32m将\033[0m"); break;
			case 6:printf("\033[40;32m炮\033[0m"); break;
			case 7:printf("\033[40;32m卒\033[0m"); break;
			case 8:printf("\033[40;31m相\033[0m"); break;
			case 9:printf("\033[40;31m仕\033[0m"); break;
			case 10:printf("\033[40;31m帥\033[0m"); break;
			case 11:printf("\033[40;31m兵\033[0m"); break;
			case 12:printf("\033[40;31m車\033[0m"); break;
			case 13:printf("\033[40;31m馬\033[0m"); break;
			case 14:printf("\033[40;31m炮\033[0m"); break;
			default:
				break;
			}
			printf("\n");
			continue;
		}
		for (j = 0; j < 8; j++)
		{
			printf("|    ");
		}
		printf("|    \n");
		for (j = 0; j < 8; j++)
		{
			switch (chess[i][j])
			{
			case 0:printf("|----"); break;
			case 1:printf("\033[40;32m車\033[0m---"); break;
			case 2:printf("\033[40;32m馬\033[0m---"); break;
			case 3:printf("\033[40;32m象\033[0m---"); break;
			case 4:printf("\033[40;32m士\033[0m---"); break;
			case 5:printf("\033[40;32m将\033[0m---"); break;
			case 6:printf("\033[40;32m炮\033[0m---"); break;
			case 7:printf("\033[40;32m卒\033[0m---"); break;
			case 8:printf("\033[40;31m相\033[0m---"); break;
			case 9:printf("\033[40;31m仕\033[0m---"); break;
			case 10:printf("\033[40;31m帥\033[0m---"); break;
			case 11:printf("\033[40;31m兵\033[0m---"); break;
			case 12:printf("\033[40;31m車\033[0m---"); break;
			case 13:printf("\033[40;31m馬\033[0m---"); break;
			case 14:printf("\033[40;31m炮\033[0m---"); break;
			default:
				break;
			}
		}
		switch (chess[i][j])
		{
		case 0:printf("|"); break;
		case 1:printf("\033[40;32m車\033[0m"); break;
		case 2:printf("\033[40;32m馬\033[0m"); break;
		case 3:printf("\033[40;32m象\033[0m"); break;
		case 4:printf("\033[40;32m士\033[0m"); break;
		case 5:printf("\033[40;32m将\033[0m"); break;
		case 6:printf("\033[40;32m炮\033[0m"); break;
		case 7:printf("\033[40;32m卒\033[0m"); break;
		case 8:printf("\033[40;31m相\033[0m"); break;
		case 9:printf("\033[40;31m仕\033[0m"); break;
		case 10:printf("\033[40;31m帥\033[0m"); break;
		case 11:printf("\033[40;31m兵\033[0m"); break;
		case 12:printf("\033[40;31m車\033[0m"); break;
		case 13:printf("\033[40;31m馬\033[0m"); break;
		case 14:printf("\033[40;31m炮\033[0m"); break;
		default:
			break;
		}
		printf("\n");
	}
	printf("|     楚     河            汉     界    |\n");
	for (; i < 9; i++)
	{
		for (j = 0; j < 8; j++)
		{
			switch (chess[i][j])
			{
			case 0:printf("|----"); break;
			case 1:printf("\033[40;32m車\033[0m---"); break;
			case 2:printf("\033[40;32m馬\033[0m---"); break;
			case 3:printf("\033[40;32m象\033[0m---"); break;
			case 4:printf("\033[40;32m士\033[0m---"); break;
			case 5:printf("\033[40;32m将\033[0m---"); break;
			case 6:printf("\033[40;32m炮\033[0m---"); break;
			case 7:printf("\033[40;32m卒\033[0m---"); break;
			case 8:printf("\033[40;31m相\033[0m---"); break;
			case 9:printf("\033[40;31m仕\033[0m---"); break;
			case 10:printf("\033[40;31m帥\033[0m---"); break;
			case 11:printf("\033[40;31m兵\033[0m---"); break;
			case 12:printf("\033[40;31m車\033[0m---"); break;
			case 13:printf("\033[40;31m馬\033[0m---"); break;
			case 14:printf("\033[40;31m炮\033[0m---"); break;
			default:
				break;
			}
		}
		switch (chess[i][j])
		{
		case 0:printf("|"); break;
		case 1:printf("\033[40;32m車\033[0m"); break;
		case 2:printf("\033[40;32m馬\033[0m"); break;
		case 3:printf("\033[40;32m象\033[0m"); break;
		case 4:printf("\033[40;32m士\033[0m"); break;
		case 5:printf("\033[40;32m将\033[0m"); break;
		case 6:printf("\033[40;32m炮\033[0m"); break;
		case 7:printf("\033[40;32m卒\033[0m"); break;
		case 8:printf("\033[40;31m相\033[0m"); break;
		case 9:printf("\033[40;31m仕\033[0m"); break;
		case 10:printf("\033[40;31m帥\033[0m"); break;
		case 11:printf("\033[40;31m兵\033[0m"); break;
		case 12:printf("\033[40;31m車\033[0m"); break;
		case 13:printf("\033[40;31m馬\033[0m"); break;
		case 14:printf("\033[40;31m炮\033[0m"); break;
		default:
			break;
		}
		printf("\n");
		for (j = 0; j < 8; j++)
		{
			printf("|    ");
		}
		printf("|    \n");
	}
	for (j = 0; j < 8; j++)
	{
		switch (chess[i][j])
		{
		case 0:printf("|----"); break;
		case 1:printf("\033[40;32m車\033[0m---"); break;
		case 2:printf("\033[40;32m馬\033[0m---"); break;
		case 3:printf("\033[40;32m象\033[0m---"); break;
		case 4:printf("\033[40;32m士\033[0m---"); break;
		case 5:printf("\033[40;32m将\033[0m---"); break;
		case 6:printf("\033[40;32m炮\033[0m---"); break;
		case 7:printf("\033[40;32m卒\033[0m---"); break;
		case 8:printf("\033[40;31m相\033[0m---"); break;
		case 9:printf("\033[40;31m仕\033[0m---"); break;
		case 10:printf("\033[40;31m帥\033[0m---"); break;
		case 11:printf("\033[40;31m兵\033[0m---"); break;
		case 12:printf("\033[40;31m車\033[0m---"); break;
		case 13:printf("\033[40;31m馬\033[0m---"); break;
		case 14:printf("\033[40;31m炮\033[0m---"); break;
		default:
			break;
		}
	}
	switch (chess[i][j])
	{
	case 0:printf("|"); break;
	case 1:printf("\033[40;32m車\033[0m"); break;
	case 2:printf("\033[40;32m馬\033[0m"); break;
	case 3:printf("\033[40;32m象\033[0m"); break;
	case 4:printf("\033[40;32m士\033[0m"); break;
	case 5:printf("\033[40;32m将\033[0m"); break;
	case 6:printf("\033[40;32m炮\033[0m"); break;
	case 7:printf("\033[40;32m卒\033[0m"); break;
	case 8:printf("\033[40;31m相\033[0m"); break;
	case 9:printf("\033[40;31m仕\033[0m"); break;
	case 10:printf("\033[40;31m帥\033[0m"); break;
	case 11:printf("\033[40;31m兵\033[0m"); break;
	case 12:printf("\033[40;31m車\033[0m"); break;
	case 13:printf("\033[40;31m馬\033[0m"); break;
	case 14:printf("\033[40;31m炮\033[0m"); break;
	default:
		break;
	}
	printf("\n");
}

int MoveCursor(int choose_num)
{

	char direction1, direction2;
	direction1 = getch();
	while (1)
	{
		if (direction1 == 13)
		{
			choose_num++;
			return choose_num;
		}
		switch (direction2 = getch())
		{
		case 72:								//↑
			if (y != 0)
			{
				y -= 2;
				i--;
			}
			SetCursorPosition(x, y);
			break;
		case 80:								//↓	
			if (y < 18)
			{
				y += 2;
				i++;
			}
			SetCursorPosition(x, y);
			break;
		case 75:								//←
			if (x != 0)
			{
				x -= 5;
				j--;
			}
			SetCursorPosition(x, y);
			break;
		case 77:								//→
			if (x < 40)
			{
				x += 5;
				j++;
			}
			SetCursorPosition(x, y);
			break;
		default:
			if ((direction2 == 13) || (direction1 == 13))
			{
				choose_num++;
				return choose_num;
			}
			break;
		}
	}
}

void SetCursorPosition(int x, int y)
{
	COORD position = { x,y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, position);
}

int JudgeLaw(int i, int j, int m, int n,int color)
{
	switch (chess[m][n])
	{
	case 1:
		if ((i == m) || (j == n))
		{
			int path_chess = 0, k;
			if (i == m)
			{
				for (k = 1; k < abs(j - n); k++)
				{
					if ((j - n) < 0)
					{
						if (chess[m][n - k] != 0)
						{
							path_chess++;
						}
					}
					else
					{
						if (chess[m][n + k] != 0)
						{
							path_chess++;
						}
					}
				}
				if (path_chess == 0)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
			else
			{
				for (k = 1; k < abs(i - m); k++)
				{
					if ((i - m) < 0)
					{
						if (chess[m - k][n] != 0)
						{
							path_chess++;
						}
					}
					else
					{
						if (chess[m + k][n] != 0)
						{
							path_chess++;
						}
					}
				}
				if (path_chess == 0)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
		}
		else
		{
			return 0;
		}
	case 2:
		if (((i==m-2)&&(j==n+1)) || ((i==m-1)&&(j==n+2)) || ((i==m+1)&&(j==n+2)) || ((i==m+2)&&(j==n+1)) || ((i==m+2)&&(j==n-1)) || ((i==m+1)&&(j==n-2)) || ((i==m-1)&&(j==n-2)) || ((i==m-2)&&(j==n-1)))
		{
			if (((i==m-1)&&(j==n+2))||((i==m+1)&&(j==n+2)))
			{
				if (chess[m][n + 1] != 0)
				{
					return 0;
				}
				else
				{
					return 1;
				}
			}
			if (((i == m + 2) && (j == n + 1))|| ((i == m + 2) && (j == n - 1)))
			{
				if (chess[m + 1][n] != 0)
				{
					return 0;
				}
				else
				{
					return 1;
				}
			}
			if (((i == m + 1) && (j == n - 2)) || ((i == m - 1) && (j == n - 2)))
			{
				if (chess[m][n - 1] != 0)
				{
					return 0;
				}
				else
				{
					return 1;
				}
			}
			if (((i == m - 2) && (j == n - 1))|| ((i == m - 2) && (j == n + 1)))
			{
				if (chess[m - 1][n] != 0)
				{
					return 0;
				}
				else
				{
					return 1;
				}
			}
		}
		else
		{
			return 0;
		}
	case 3:
		if (i < 5)
		{
			if (((i == m - 2) && (j == n + 2))||((i == m + 2) && (j == n + 2))||((i == m + 2) && (j == n - 2))||((i == m - 2) && (j == n - 2)))
			{
				if ((i == m - 2) && (j == n + 2))
				{
					if (chess[m - 1][n + 1] != 0)
					{
						return 0;
					}
					else
					{
						return 1;
					}
				}
				if ((i == m + 2) && (j == n + 2))
				{
					if (chess[m + 1][n + 1] != 0)
					{
						return 0;
					}
					else
					{
						return 1;
					}
				}
				if ((i == m + 2) && (j == n - 2))
				{
					if (chess[m+1][n-1]!=0)
					{
						return 0;
					}
					else
					{
						return 1;
					}
				}
				if ((i == m - 2) && (j == n - 2))
				{
					if (chess[m - 1][n - 1] != 0)
					{
						return 0;
					}
					else
					{
						return 1;
					}
				}
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	case 4:
		if (((i == 0) && (j == 3)) || ((i == 0) && (j == 5)) || ((i == 1) && (j == 4)) || ((i == 2) && (j == 3)) || ((i == 2) && (j == 5)))
		{
			if (((i == m - 1) && (j == n - 1)) || ((i == m - 1) && (j == n + 1)) || ((i == m + 1) && (j == n + 1)) || ((i == m + 1) && (j == n - 1)))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	case 5:
		if (((i == 0) || (i == 1) || (i == 2)) && ((j == 3) || (j == 4) || (j == 5)))
		{
			if (((i == m - 1) && (j == n)) || ((i == m + 1) && (j == n)) || ((i == m) && (j == n - 1)) || ((i == m) && (j == n + 1)))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	case 6:
		if ((i == m) || (j == n))
		{
			int path_chess = 0, k;
			if (i == m)
			{
				for (k = 1; k < abs(j - n); k++)
				{
					if ((j - n) < 0)
					{
						if (chess[m][n - k] != 0)
						{
							path_chess++;
						}
					}
					else
					{
						if (chess[m][n + k] != 0)
						{
							path_chess++;
						}
					}
				}
				if (path_chess == 0)
				{
					return 1;
				}
				else
				{
					if (path_chess == 1)
					{
						if (JudgeEnemyChess(color) == 1)
						{
							return 1;
						}
						else
						{
							return 0;
						}
					}
					else
					{
						return 0;
					}
				}
			}
			else
			{
				for (k = 1; k < abs(i - m); k++)
				{
					if ((i - m) < 0)
					{
						if (chess[m - k][n] != 0)
						{
							path_chess++;
						}
					}
					else
					{
						if (chess[m + k][n] != 0)
						{
							path_chess++;
						}
					}
				}
				if (path_chess == 0)
				{
					return 1;
				}
				else
				{
					if (path_chess == 1)
					{
						if (JudgeEnemyChess(color) == 1)
						{
							return 1;
						}
						else
						{
							return 0;
						}
					}
					else
					{
						return 0;
					}
				}
			}
		}
		else
		{
			return 0;
		}
	case 7:
		if(m<=4)
		{
			if ((j == n) && (i == m + 1))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			if (((i == m + 1) && (j == n)) || ((i == m) && (j == n - 1)) || ((i == m) && (j == n + 1)))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	case 8:
		if (i >= 5)
		{
			if (((i == m - 2) && (j == n + 2)) || ((i == m + 2) && (j == n + 2)) || ((i == m + 2) && (j == n - 2)) || ((i == m - 2) && (j == n - 2)))
			{
				if ((i == m - 2) && (j == n + 2))
				{
					if (chess[m - 1][n + 1] != 0)
					{
						return 0;
					}
					else
					{
						return 1;
					}
				}
				if ((i == m + 2) && (j == n + 2))
				{
					if (chess[m + 1][n + 1] != 0)
					{
						return 0;
					}
					else
					{
						return 1;
					}
				}
				if ((i == m + 2) && (j == n - 2))
				{
					if (chess[m + 1][n - 1] != 0)
					{
						return 0;
					}
					else
					{
						return 1;
					}
				}
				if ((i == m - 2) && (j == n - 2))
				{
					if (chess[m - 1][n - 1] != 0)
					{
						return 0;
					}
					else
					{
						return 1;
					}
				}
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	case 9:
		if (((i == 9) && (j == 3)) || ((i == 9) && (j == 5)) || ((i == 8) && (j == 4)) || ((i == 7) && (j == 3)) || ((i == 7) && (j == 5)))
		{
			if (((i == m - 1) && (j == n - 1)) || ((i == m - 1) && (j == n + 1)) || ((i == m + 1) && (j == n + 1)) || ((i == m + 1) && (j == n - 1)))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	case 10:
		if (((i == 7) || (i == 8) || (i == 9)) && ((j == 3) || (j == 4) || (j == 5)))
		{
			if (((i == m - 1) && (j == n)) || ((i == m + 1) && (j == n)) || ((i == m) && (j == n - 1)) || ((i == m) && (j == n + 1)))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	case 11:
		if (m >= 5)
		{
			if ((j == n) && (i == m - 1))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			if (((i == m - 1) && (j == n)) || ((i == m) && (j == n - 1)) || ((i == m) && (j == n + 1)))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	case 12:
		if ((i == m) || (j == n))
		{
			int path_chess = 0, k;
			if (i == m)
			{
				for (k = 1; k < abs(j - n); k++)
				{
					if ((j - n) < 0)
					{
						if (chess[m][n - k] != 0)
						{
							path_chess++;
						}
					}
					else
					{
						if (chess[m][n + k] != 0)
						{
							path_chess++;
						}
					}
				}
				if (path_chess == 0)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
			else
			{
				for (k = 1; k < abs(i - m); k++)
				{
					if ((i - m) < 0)
					{
						if (chess[m - k][n] != 0)
						{
							path_chess++;
						}
					}
					else
					{
						if (chess[m + k][n] != 0)
						{
							path_chess++;
						}
					}
				}
				if (path_chess == 0)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
		}
		else
		{
			return 0;
		}
	case 13:
		if (((i == m - 2) && (j == n + 1)) || ((i == m - 1) && (j == n + 2)) || ((i == m + 1) && (j == n + 2)) || ((i == m + 2) && (j == n + 1)) || ((i == m + 2) && (j == n - 1)) || ((i == m + 1) && (j == n - 2)) || ((i == m - 1) && (j == n - 2)) || ((i == m - 2) && (j == n - 1)))
		{
			if (((i == m - 1) && (j == n + 2)) || ((i == m + 1) && (j == n + 2)))
			{
				if (chess[m][n + 1] != 0)
				{
					return 0;
				}
				else
				{
					return 1;
				}
			}
			if (((i == m + 2) && (j == n + 1)) || ((i == m + 2) && (j == n - 1)))
			{
				if (chess[m + 1][n] != 0)
				{
					return 0;
				}
				else
				{
					return 1;
				}
			}
			if (((i == m + 1) && (j == n - 2)) || ((i == m - 1) && (j == n - 2)))
			{
				if (chess[m][n - 1] != 0)
				{
					return 0;
				}
				else
				{
					return 1;
				}
			}
			if (((i == m - 2) && (j == n - 1)) || ((i == m - 2) && (j == n + 1)))
			{
				if (chess[m - 1][n] != 0)
				{
					return 0;
				}
				else
				{
					return 1;
				}
			}
		}
		else
		{
			return 0;
		}
	case 14:
		if ((i == m) || (j == n))
		{
			int path_chess = 0, k;
			if (i == m)
			{
				for (k = 1; k < abs(j - n); k++)
				{
					if ((j - n) < 0)
					{
						if (chess[m][n - k] != 0)
						{
							path_chess++;
						}
					}
					else
					{
						if (chess[m][n + k] != 0)
						{
							path_chess++;
						}
					}
				}
				if (path_chess == 0)
				{
					return 1;
				}
				else
				{
					if (path_chess == 1)
					{
						if (JudgeEnemyChess(color) == 1)
						{
							return 1;
						}
						else
						{
							return 0;
						}
					}
					else
					{
						return 0;
					}
				}
			}
			else
			{
				for (k = 1; k < abs(i - m); k++)
				{
					if ((i - m) < 0)
					{
						if (chess[m - k][n] != 0)
						{
							path_chess++;
						}
					}
					else
					{
						if (chess[m + k][n] != 0)
						{
							path_chess++;
						}
					}
				}
				if (path_chess == 0)
				{
					return 1;
				}
				else
				{
					if (path_chess == 1)
					{
						if (JudgeEnemyChess(color) == 1)
						{
							return 1;
						}
						else
						{
							return 0;
						}
					}
					else
					{
						return 0;
					}
				}
			}
		}
		else
		{
			return 0;
		}
	default:
		break;
	}
}

int JudgeMyChess(int color)
{
	if (color == 1)                              
	{
		switch (chess[i][j])
		{
		case 1:return 1; break;
		case 2:return 1; break;
		case 3:return 1; break;
		case 4:return 1; break;
		case 5:return 1; break;
		case 6:return 1; break;
		case 7:return 1; break;
		default:
			return 0;
			break;
		}
	}
	else
	{
		switch (chess[i][j])
		{
		case 8:return 1; break;
		case 9:return 1; break;
		case 10:return 1; break;
		case 11:return 1; break;
		case 12:return 1; break;
		case 13:return 1; break;
		case 14:return 1; break;
		default:
			return 0;
			break;
		}
	}
}

int JudgeEnemyOrSpaceChess(int color)
{
	if (color == 0)                             
	{
		switch (chess[i][j])
		{
		case 0:return 1; break;
		case 1:return 1; break;
		case 2:return 1; break;
		case 3:return 1; break;
		case 4:return 1; break;
		case 5:return 1; break;
		case 6:return 1; break;
		case 7:return 1; break;
		default:
			return 0;
			break;
		}
	}
	else
	{
		switch (chess[i][j])
		{
		case 0:return 1; break;
		case 8:return 1; break;
		case 9:return 1; break;
		case 10:return 1; break;
		case 11:return 1; break;
		case 12:return 1; break;
		case 13:return 1; break;
		case 14:return 1; break;
		default:
			return 0;
			break;
		}
	}
}

int JudgeEnemyChess(int color)
{
	if (color == 0)
	{
		switch (chess[i][j])
		{
		case 1:return 1; break;
		case 2:return 1; break;
		case 3:return 1; break;
		case 4:return 1; break;
		case 5:return 1; break;
		case 6:return 1; break;
		case 7:return 1; break;
		default:
			return 0;
			break;
		}
	}
	else
	{
		switch (chess[i][j])
		{
		case 8:return 1; break;
		case 9:return 1; break;
		case 10:return 1; break;
		case 11:return 1; break;
		case 12:return 1; break;
		case 13:return 1; break;
		case 14:return 1; break;
		default:
			return 0;
			break;
		}
	}
}

