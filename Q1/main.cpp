#include<iostream>
using namespace std;

int cycleLength(int w);

int main()
{
	cout << "Hello World!" << endl;

	//�Է� (i, j)
	//�ݺ����� ����� ������ ���� ����
	//����Ŭ ���̸� ���ϴ� �Լ��� i���� 1�� ������Ű�� n���� �ݺ�
		//i�� Ȧ¦ �Ǻ�
		//Ȧ¦�� ���� ����
		//��� ����
	//�ִ� ����Ŭ ���� ���

	int i = 0, j = 0;
	
	while (i >= 0)
	{
		while (1)
		{
			cin >> i >> j;
			if (i * j)
				break;
			cout << "Input Error!" << endl;
		}	
		int ii = i;
		int jj = j;
		if (ii > jj)//i>j�� ���� �ԷµǾ����� �ٲ��־�� ��
		{
			int temp = ii;
			ii = jj;
			jj = temp;
		}
		int maxCycle = 0;
		while (ii < jj)
		{
			if (cycleLength(ii) > maxCycle)
				maxCycle = cycleLength(ii);
			ii++;
		}

		cout << i << " " << j << " " << maxCycle << endl;
	}

	system("pause");
	return 0;
}

int cycleLength(int i)
{
	int w = i;
	int length = 1;
	while (w != 1)
	{
		if (w % 2)
			w = 3 * w + 1;
		else
			w = w / 2;
		length++;
	}
	return length;
}