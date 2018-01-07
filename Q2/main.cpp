#include <iostream>
using namespace std;

char bomb(char ** s, int nn, int mm);

int main()
{
	//Question num.2
	
	/*
	input :
	4 4
	*...
	....
	.*..
	*/
	int n, m; //n�� m�� ���ڹ�
	int field = 1;
	char ** space;
	
	while (1)
	{

		n = 0; m = 0; space = NULL;

		cin >> n >> m;

		space = new char * [n+2]; //n���� �� �����Ҵ�

		for (int a = 0; a < n+2; a++)
		{
			space[a] = new char[m+2];//a��° �ٿ� m�� �����Ҵ�
		}

		for (int j = 0; j < m + 2; j++)// ��� �迭��� '.'���� ����
		{
			for (int k = 0; k < m + 2; k++)
				space[j][k] = '.';
		}

		for (int b = 1; b < n+1; b++)//n����� b�࿡ ���پ� �Է¹���
		{
			for (int c = 1; c < m+1; c++)
				cin >> space[b][c];
		}

		cout << "Field #" << field << " : " << endl;

		for (int x = 1; x < n+1; x++)
		{
			for (int y = 1; y < m+1; y++)
				cout << bomb(space, x, y) << " ";
			cout << endl;
		}

		for (int c = 0; c < n; c++)
			delete[] space[c];
		delete[] space;

		field++;
	}

}

char bomb(char ** s, int nn, int mm)//s[nn][mm]�ֺ� ��ź ���� ����
{
	int counter = 0; //��ź���� ����

	if (s[nn][mm] == '*')//�ڽ��� ��ź�̸� -1 ������
		return '*';

	if (s[nn - 1][mm - 1] == '*')
		counter++;

	if (s[nn - 1][mm] == '*')
		counter++;

	if (s[nn - 1][mm + 1] == '*')
		counter++;

	if (s[nn + 1][mm - 1] == '*')
		counter++;

	if (s[nn + 1][mm] == '*')
		counter++;

	if (s[nn + 1][mm + 1] == '*')
		counter++;

	if (s[nn][mm - 1] == '*')
		counter++;

	if (s[nn][mm + 1] == '*')
		counter++;

	return counter + '0';
}