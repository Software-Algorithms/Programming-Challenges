#include <iostream>
using namespace std;

int main()
{
	char  arr[250][250]; // �迭 ����
	arrInit(arr);
	

}

void arrInit(char** arr)
{
	for (int i = 0; i < 250; i++)
		for (int j = 0; j < 250; j++)
			arr[i][j] = NULL; // �迭 NULL�� �ʱ�ȭ
}

void iFunc(int m, int n, char** arr)
{
	arrInit(arr);
	cFunc(m, n, arr);
}

void cFunc (int m, int n, char** arr)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			arr[i][j] = 'O'; // m*n ����� ��� O(white)����
}

void lFunc (int x, int y, char c, char** arr)
{
	arr[x][y] = c;
}

void vFunc(int x, int y1, int y2, int c, char** arr)
{

}
