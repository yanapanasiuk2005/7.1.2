#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** y, const int rowCount, const int colCount, const int Low,
	const int High, int i, int j)
{
	y[i][j] = Low + rand() % (High - Low + 1);
	if (j < colCount - 1)
		Create(y, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount - 1)
			Create(y, rowCount, colCount, Low, High, i + 1, 0);
}
void Print(int** y, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << y[i][j];
	if (j < colCount - 1)
		Print(y, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(y, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}
void Change(int** y, const int row1, const int row2, const int colCount, int
	j)
{
	int tmp;
	tmp = y[row1][j];
	y[row1][j] = y[row2][j];
	y[row2][j] = tmp;
	if (j < colCount - 1)
		Change(y, row1, row2, colCount, j + 1);
}
void Sort(int** y, const int rowCount, const int colCount, int i0, int i1)
{
	if ((y[i1][0] > y[i1 + 1][0])
		||
		(y[i1][0] == y[i1 + 1][0] &&
			y[i1][1] > y[i1 + 1][1])
		||
		(y[i1][0] == y[i1 + 1][0] &&
			y[i1][1] == y[i1 + 1][1] &&
			y[i1][3] > y[i1 + 1][3]))
		Change(y, i1, i1 + 1, colCount, 0);
	if (i1 < rowCount - i0 - 1 - 1)
		Sort(y, rowCount, colCount, i0, i1 + 1);
	else
		if (i0 < rowCount - 1 - 1)
			Sort(y, rowCount, colCount, i0 + 1, 0);
}
void Calc(int** y, const int rowCount, const int colCount, int& S, int& k,
	int i, int j)
{
	if (y[i][j] % 2 != 0 || !(y[i][j] % 3 == 0))
	{
		S += y[i][j];
		k++;
		y[i][j] = 0;
	}
	if (j < colCount - 1)
		Calc(y, rowCount, colCount, S, k, i, j + 1);
	else
		if (i < rowCount - 1)
			Calc(y, rowCount, colCount, S, k, i + 1, 0);
}
int main()
{
	srand((unsigned)time(NULL));
	int i;
	int j;
	int Low = 11;
	int High = 64;
	int rowCount = 8;
	int colCount = 5;
	int tmp;
	int** y = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		y[i] = new int[colCount];
	Create(y, rowCount, colCount, Low, High, 0, 0);
	Print(y, rowCount, colCount, 0, 0);
	Sort(y, rowCount, colCount, 0, 0);
	Print(y, rowCount, colCount, 0, 0);
	int S = 0;
	int k = 0;
	Calc(y, rowCount, colCount, S, k, 0, 0);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	Print(y, rowCount, colCount, 0, 0);
	for (int i = 0; i < rowCount; i++)
		delete[] y[i];
	delete[] y;
	return 0;
}
