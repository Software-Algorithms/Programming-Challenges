#include <iostream>
using namespace std;

const int SIZE = 252; 
// x, y�� 1~250�� ������ ���´�
// ��� �𼭸��� �� �پ� NULL�� ��ҷ� ���� boundary ����

void arrInit(char(*arr)[SIZE]);
void iFunc(int m, int n, char(*arr)[SIZE]);
void cFunc(int m, int n, char(*arr)[SIZE], char c);
void lFunc(int x, int y, char c, char(*arr)[SIZE]);
void vFunc(int x, int y1, int y2, char c, char(*arr)[SIZE]);
void hFunc(int x1, int x2, int y, char c, char(*arr)[SIZE]);
void kFunc(int x1, int x2, int y1, int y2, char c, char(*arr)[SIZE]);
void fFunc(int x, int y, char c, char(*arr)[SIZE]);
void sFunc(char* name, int m, int n, char(*arr)[SIZE]);
void fill(int x, int y, char bc, char c, char(*arr)[SIZE]);
void color(int tempX, int tempY, char bc, char c, char(*arr)[SIZE]);

int main()
{
	char arr[SIZE][SIZE]; // �迭 ����
	arrInit(arr);

	char order = NULL;
	int sizeX = 0, sizeY = 0;

	while (order != 'X')
	{ // ��� ���ñ�
		cin >> order;

		if (order == 'I')
		{
			cin >> sizeX >> sizeY;
			iFunc(sizeX, sizeY, arr);
		}

		if (order == 'C')
		{
			char c = NULL;
			cin >> c;
			cFunc(sizeX, sizeY, arr, c);
		}

		if (order == 'L')
		{
			int x = 0, y = 0;
			char c = NULL;
			cin >> x >> y >> c;
			lFunc(x, y, c, arr);
		}

		if (order == 'V')
		{
			int x = 0, y1 = 0, y2 = 0;
			char c = NULL;
			cin >> x >> y1 >> y2 >> c;
			vFunc(x, y1, y2, c, arr);
		}

		if (order == 'H')
		{
			int x1 = 0, x2 = 0, y = 0;
			char c = NULL;
			cin >> x1 >> x2 >> y >> c;
			hFunc(x1, x2, y, c, arr);
		}

		if (order == 'K')
		{
			int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
			char c = NULL;
			cin >> x1 >> y1 >> x2 >> y2 >> c;
			kFunc(x1, x2, y1, y2, c, arr);
		}

		if (order == 'F')
		{
			int x = 0, y = 0;
			char c = NULL;
			cin >> x >> y >> c;
			fFunc(x, y, c, arr);
		}

		if (order == 'S')
		{
			char name[10];
			cin >> name;
			sFunc(name, sizeX, sizeY, arr);
		}

		if (order == 'X')
			break;
	}

	return 0;
}

void arrInit(char (*arr)[SIZE]) // �迭 ����� NULL�� �ʱ�ȭ
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			arr[i][j] = NULL;
}

void iFunc(int m, int n, char(*arr)[SIZE]) // �迭 �ʱ�ȭ �� m, n ���ڷ� cFunc ȣ��
{
	arrInit(arr);
	cFunc(m, n, arr, 'O');
}

void cFunc (int m, int n, char(*arr)[SIZE], char c) // m*n ����� ��� O(white)����
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			arr[i][j] = c;
}

void lFunc (int x, int y, char c, char(*arr)[SIZE]) // x, y �ȼ��� c�� ĥ�ϱ�
{
	arr[y][x] = c;
}

void vFunc(int x, int y1, int y2, char c, char(*arr)[SIZE]) // x���� y1��~y2����� c�� ĥ�ϱ�
{
	for (int i = y1; i <= y2; i++)
		arr[i][x] = c;
}

void hFunc(int x1, int x2, int y, char c, char(*arr)[SIZE]) // y���� x1��~x2������ c�� ĥ�ϱ�
{
	for (int i = x1; i <= x2; i++)
		arr[y][i] = c;
}

void kFunc(int x1, int x2, int y1, int y2, char c, char(*arr)[SIZE]) // x1~x2, y1~y2 ���簢�� c�� ĥ�ϱ�
{
	for (int i = x1; i <= x2; i++)
		for (int j = y1; j <= y2; j++)
			arr[j][i] = c;
}

void fFunc(int x, int y, char c, char(*arr)[SIZE]) // x, y�������� c�� �� ä���
{
	char bc = arr[y][x]; // (x, y)�� ���� bc�� ����
	arr[y][x] = c;
	fill(x, y, bc, c, arr);
}

void sFunc(char* name, int m, int n, char(*arr)[SIZE]) // ���ϸ� name�� m*n �������� ��ü �迭��Ҹ� ���
{
	cout << name << ".bmp" << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cout << arr[i][j];
		cout << endl;
	}
}

void fill(int x, int y, char bc, char c, char(*arr)[SIZE])
// x, y �������� �ð����(��-����-�Ʒ�-��)���� ���鼭 color�� ȣ���Ų��
{
	int tempX = x, tempY = y - 1; // �� ĭ �� �ȼ�
	color(tempX, tempY, bc, c, arr);

	tempX = x + 1, tempY = y; // �� ĭ ������ �ȼ�
	color(tempX, tempY, bc, c, arr);

	tempX = x, tempY = y + 1; // �� ĭ �Ʒ� �ȼ�
	color(tempX, tempY, bc, c, arr);

	tempX = x - 1, tempY = y; // �� ĭ ���� �ȼ�
	color(tempX, tempY, bc, c, arr);
}

void color(int tempX, int tempY, char bc, char c, char(*arr)[SIZE])
// tempX, tempY�� bc�� �������̸� c�� ĥ�ϰ�, fill�� ȣ���� tempX, tempY�� �������� �ٽ� �ð�������� ������(���)
{
	if (arr[tempY][tempX] == bc) // bc�� ���� �ȼ��� ���������� �˻�
	{
		arr[tempY][tempX] = c; // ������ c�� �� �ٲٰ�
		fill(tempX, tempY, bc, c, arr); // ���� �ȼ��� �������� fill ȣ���� �ð�������� �ٽ� ������
	}
}