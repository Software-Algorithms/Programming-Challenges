#include <iostream>
using namespace std;

void aInit(char(*a)[10]);
bool checkmate(const char(*a)[10], bool iswhite, bool * isempty);
bool checkq(const char(*a)[10], int k_x, int k_y, bool iswhite);
bool checkp(const char(*a)[10], int k_x, int k_y, bool iswhite);
bool checkcross(const char(*a)[10], int k_x, int k_y, bool iswhite, char chkwhat);
bool checkdiag(const char(*a)[10], int k_x, int k_y, bool iswhite, char chkwhat);
bool checkn(const char(*a)[10], int k_x, int k_y, bool iswhite);

int main()
{
	int game = 1;
	char a[10][10];
	aInit(a);
	bool isempty = false;
	
	while (1)
	{
		//2���� �迭�� �Է¹���
		for (int i = 1; i < 9; i++)
			cin >> a[i];

		if (checkmate(a, false, &isempty))
			cout << endl << "Game #" << game << ": black king is in check.";
		else if (checkmate(a, true, &isempty))
			cout << endl << "Game #" << game << ": white king is in check.";
		else if (isempty)
			break;
		else cout << endl << "Game #" << game << ": no king is  in check";

		game++;

		aInit(a);
		cout << endl;
	}

	system("pause");
	return 0;
}

void aInit (char (*a)[10])
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			a[i][j] = NULL;
}

//ŷ�� ���忡�� üũ�� �ֳ� �ϳ��� �˻��ϴ� �Լ� �����
bool checkmate(const char(*a)[10], bool iswhite, bool * isempty) 
{
	int k_x = 0, k_y = 0;
	
	//ŷã��
	for (int i = 1; i < 9; i++)
		for (int j = 1; j < 9; j++)
		{
			if (a[i][j] == (char)('k' - (iswhite * 32)))
			{
				k_x = j;
				k_y = i;
				break;
			}
		}

	if (k_x && k_y)
		return (checkq(a, k_x, k_y, iswhite) || checkp(a, k_x, k_y, iswhite) || checkcross(a, k_x, k_y, iswhite, 'R')
			|| checkdiag(a, k_x, k_y, iswhite, 'B') || checkn(a, k_x, k_y, iswhite));
	//��, ��, ��, ���, ����Ʈ ������� �˻�
	
	else cout << "Can't find king! : code " << k_x << k_y << endl;
	*isempty = true;
	return false;
}

bool checkq(const char(*a)[10], int k_x, int k_y, bool iswhite)
{
	return (checkcross(a, k_x, k_y, iswhite, 'Q') || checkdiag(a, k_x, k_y, iswhite, 'Q'));
}

bool checkp(const char(*a)[10], int k_x, int k_y, bool iswhite)
{
	return (a[k_y - 1 + iswhite * 2][k_x - 1] == (char)((int)'P' + (iswhite * 32))
		|| a[k_y - 1 + iswhite * 2][k_x + 1] == (char)((int)'P' + (iswhite * 32)));
	//ŷ�� ���� ��(�Ǵ� �Ʒ�)�� ���� �ִ� ��� or
	//ŷ�� ������ ��(�Ǵ� �Ʒ�)�� ���� �ִ� ��� TRUE ��ȯ
}

bool checkcross(const char(*a)[10], int k_x, int k_y, bool iswhite, char chkwhat)
{//�����¿쿡 chkwhat�� �ֳ� �˻�, �� ĭ�� ����, chkwhat�� üũ �� ���� �빮��
	for (int i = 1; k_x + i < 9; i++)
	{// ŷ ������ chkwhat �ִ��� �˻�
		if (a[k_y][k_x + i] == '.')
			continue;
		else if (a[k_y][k_x + i] == (char)((int)chkwhat + (iswhite) * 32))
			return 1;
	}

	for (int i = 1; k_x - i > 0; i++)
	{// ŷ ���ʿ� chkwhat �ִ��� �˻�
		if (a[k_y][k_x - i] == '.')
			continue;
		else if (a[k_y][k_x - i] == (char)((int)chkwhat + (iswhite) * 32))
			return 1;
	}

	for (int i = 1; k_y + i < 9; i++)
	{// ŷ ���ʿ� chkwhat �ִ��� �˻�
		if (a[k_y + i][k_x] == '.')
			continue;
		else if (a[k_y + i][k_x] == (char)((int)chkwhat + (iswhite) * 32))
			return 1;
	}

	for (int i = 1; k_y - i > 0; i++)
	{// ŷ ���ʿ� chkwhat �ִ��� �˻�
		if (a[k_y - i][k_x] == '.')
			continue;
		else if (a[k_y - i][k_x] == (char)((int)chkwhat + (iswhite) * 32))
			return 1;
	}

	return 0; // üũ ���� ����
}

bool checkdiag(const char(*a)[10], int k_x, int k_y, bool iswhite, char chkwhat)
{//�밢�� �˻�
	for (int i = 1; k_x + i < 9 || k_y + i < 9; i++)
	{// ŷ ������ ���� chkwhat �ִ��� �˻�
		if (a[k_y + i][k_x + i] == '.')
			continue;
		else if (a[k_y + i][k_x + i] == (char)((int)chkwhat + (iswhite) * 32))
			return 1;
	}

	for (int i = 1; k_x - i > 0 || k_y + i < 9; i++)
	{// ŷ ���� ���� chkwhat �ִ��� �˻�
		if (a[k_y + i][k_x - i] == '.')
			continue;
		else if (a[k_y + i][k_x - i] == (char)((int)chkwhat + (iswhite) * 32))
			return 1;
	}

	for (int i = 1; k_x + i < 9 || k_y - i > 0; i++)
	{// ŷ ������ �Ʒ��� chkwhat �ִ��� �˻�
		if (a[k_y - i][k_x + i] == '.')
			continue;
		else if (a[k_y - i][k_x + i] == (char)((int)chkwhat + (iswhite) * 32))
			return 1;
	}

	for (int i = 1; k_x - i > 0 || k_y - i > 0; i++)
	{// ŷ ���� �Ʒ��� chkwhat �ִ��� �˻�
		if (a[k_y - i][k_x - i] == '.')
			continue;
		else if (a[k_y - i][k_x - i] == (char)((int)chkwhat + (iswhite) * 32))
			return 1;
	}

	return 0; // üũ ���� ����
}

bool checkn(const char(*a)[10], int k_x, int k_y, bool iswhite)
{//����Ʈ�� üũ �ڸ� 8�ڸ� �˻�
	if (k_y < 8 && (a[k_y + 2][k_x + 1] == (char)((int)'N' + (iswhite) * 32)))
		return 1;

	else if (k_y < 8 && (a[k_y + 2][k_x - 1] == (char)((int)'N' + (iswhite) * 32)))
		return 1;

	else if (k_y > 1 && (a[k_y - 2][k_x + 1] == (char)((int)'N' + (iswhite) * 32)))
		return 1;

	else if (k_y > 1 && (a[k_y - 2][k_x - 1] == (char)((int)'N' + (iswhite) * 32)))
		return 1;

	else if (k_x < 8 && (a[k_y + 1][k_x + 2] == (char)((int)'N' + (iswhite) * 32)))
		return 1;

	else if (k_x > 1 && (a[k_y + 1][k_x - 2] == (char)((int)'N' + (iswhite) * 32)))
		return 1;

	else if (k_x < 8 && (a[k_y - 1][k_x + 2] == (char)((int)'N' + (iswhite) * 32)))
		return 1;

	else if (k_x > 1 && (a[k_y - 1][k_x - 2] == (char)((int)'N' + (iswhite) * 32)))
		return 1;

	else return 0;
}

