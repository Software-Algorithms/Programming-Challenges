#include<iostream>
using namespace std;

int main()
{
	int s;
	char n[9]; // s�� ũ��, n�� ����� ����
	int line = 0;
	char numcode[10][8] =
	{
		"-|| ||-", "  |  | ", "- |-| -", "- |- |-", " ||- | ",
		"-| - |-", "-| -||-", "- |  | ", "-||-||-", "-||- |-"
	}; // numcode[x]�� x�� 7�ڸ� ���� �ڵ� abcdefg

	while (1)
	{
		s = 0;
		for (int i = 0; i < 9; i++) // ���� �迭 �ʱ�ȭ
			n[i] = NULL;


		cin >> s >> n;
		if (!s & !n) // s=n=0�̸� ���α׷� ����
			break;

		line = 1;
		for (int loc = 0; n[loc] != NULL; loc++)
		{
			cout << " "; // 1�� ù�� ����
			for (int i = 0; i < s; i++)// a
				cout << numcode[n[loc]-48][0];
			cout << " "; //1�� �������� ����
			cout << " "; //�� �ڸ� ���� ����
		}
		cout << endl;
		line++; // A�κ� ��

		for (; line < s + 2; line++) // ���µ� �� ������ �ึ�� ���
		{
			for (int loc = 0; n[loc] != NULL; loc++) // ����� ���ڵ� �б�
			{
				cout << numcode[n[loc]-48][1];// b
				for (int i = 0; i < s; i++)
					cout << " ";// 8�� ���� ���׶�� �Ⱥκ� �������� s��
				cout << numcode[n[loc] - 48][2];// c
				cout << " "; // �� �ڸ� ���� ����
			}
			cout << endl; // �ٹٲٰ� line�� 1 ����
		} // B�κ� ��

		for (int loc = 0; n[loc] != NULL; loc++)
		{
			cout << " "; // �߰��� ù�� ����
			for (int i = 0; i < s; i++)// d
				cout << numcode[n[loc] - 48][3];
			cout << " "; //�߰��� �������� ����
			cout << " "; //�� �ڸ� ���� ����
		}
		cout << endl;
		line++; // C�κ� ��

		for (; line < (2 * s + 3); line++) // ������ �� ������ �ึ�� ���
		{
			for (int loc = 0; n[loc] != NULL; loc++) // ����� ���ڵ� �б�
			{
				cout << numcode[n[loc] - 48][4];// e
				for (int i = 0; i < s; i++)
					cout << " ";// 8�� �Ʒ��� ���׶�� �Ⱥκ� �������� s��
				cout << numcode[n[loc] - 48][5];// f
				cout << " "; //�� �ڸ� ���� ����
			}
			cout << endl; // �ٹٲ�
		} // D�κ� ��
		
		for (int loc = 0; n[loc] != NULL; loc++)
		{
			cout << " "; // ���� ù�� ����
			for (int i = 0; i < s; i++)
				cout << numcode[n[loc] - 48][6];//g
			cout << " "; //1�� �������� ����
			cout << " "; //�� �ڸ� ���� ����
		}
		cout << endl;
		line++; // E�κ� ��
	}

	system("pause");

	return 0;
}