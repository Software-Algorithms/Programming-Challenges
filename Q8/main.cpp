#include<iostream>
using namespace std;

int overfifty(int * result, int cand, int vote_s);
int openvote(int ** vote, int cand, int vote_s);
int * countvote(int cand, int vote_s, int ** vote, bool * fail);
void whofail(int cand, int * result, bool * fail);

int main()
{
	int numCase;
	cin >> numCase;
	

	for (int i = 0; i < numCase; i++)
	{
		//***��ǥ
		char temp[40];
		for (int i = 0; i < 40; i++)
			temp[i] = NULL;
		int cand = 0;

		cin >> cand;

		char(*candName)[80] = new char[cand][80];
		//�ĺ� ����ŭ 80�ھ� �ĺ��̸� �޸� �����Ҵ�

		for (int i = 0; i < cand; i++)
			cin >> candName[i];
		//�ĺ� ����ŭ �ĺ��̸� �Է¹���

		int * vote[1000];//vote�� ��ǥ����� ������ ������
		for (int i = 0; i < 1000; i++)
			vote[i] = NULL;

		int vote_s = 0; //�� ��ǥ�� ���� ������ ����

		cin.ignore();
		while (1)
		{
			cin.getline(temp, 40);

			if (temp[0] == 0)
				break;

			else
			{
				//��ǥ�� ����� �Է¹���
				vote[vote_s] = new int[cand];
				for (int i = 0; i < cand; i++)
					vote[vote_s][i] = temp[2 * i] - 48;
				vote_s++;
			}

			//��ǥ���� 1000���Ѿ�� �ߴ�
			if (vote_s >= 1000)
				break;
		}

		//��ǥ
		int elec = openvote(vote, cand, vote_s);
		if (elec + 1)
			cout << candName[elec] << endl;
		else cout << elec << "multiple cand got same votes" << endl;
	}

	system("pause");
	return 0;
}

int openvote(int ** vote, int cand, int vote_s)
{//vote ��ǥ������ ��ǥ�ؼ� result�� �����ϴ� �Լ��� �漱����� elec�� ��ȯ��

	//Ż�������� true�� �����ϴ� �ĺ� ������ŭ�� bool�迭
	bool * fail = new bool[cand];
	for (int i = 0; i < cand; i++)
		fail[i] = false;

	while(1)
	{
		//����
		int * result = countvote(cand, vote_s, vote, fail);

		//���Ż���ϴ� ��� = �ĺ����� ������ ��� : ��ǥ����
		for (int i = 0; i < cand; i++)
			if (!(fail[i]))
				break;
			else if (i == cand - 1)
				return -1;

		//50�� �̻� �ĺ� �ִ��� �˻��ؼ� ������ ���ⳡ
		int elec = overfifty(result, cand, vote_s);
		if (elec + 1)
			return elec;

		//50�� �̻� �ĺ� ������ Ż����ų �ĺ� �߰���
		whofail(cand, result, fail);
	}
}

int overfifty(int * result, int cand, int vote_s)
{//50�� �Ѵ� �ĺ� ������ �ش��ĺ� �迭��ȣ��, ������ -1 ��ȯ
	for (int i = 0; i < cand; i++)
		if (result[i] > vote_s * 0.5)
			return i;
	return -1;
}

int * countvote(int cand, int vote_s, int ** vote, bool * fail)
{
	//��ȯ�� ��� ������ ����
	int * result = new int [cand];
	for (int i = 0; i < cand; i++)
		result[i] = 0;

	//�� ǥ�� ��ǥ
	for (int i = 0; i < vote_s; i++)
	{
		for (int r = 0; r < cand; r++)
			if (fail[vote[i][r]]) //r���� �ĺ��� Ż���ڸ� ���� ������
				continue;
			else
			{//Ż���� �ƴϸ� result�� �ݿ��ϰ� break
				result[vote[i][r] - 1]++; 
				break;
			}
	}
	return result;
}

void whofail(int cand, int * result, bool * fail)
{
	//���� ���� ��ǥ���� ������ fff����
	int fff;
	for (int i = 0; i < cand; i++)
		if (!fail[i])
		{
			fff = result[i];
			break;
		}

	//���� ���� ��ǥ���� ã�´�
	for (int i = 0; i < cand; i++)
		if (!fail[i] && fff < result[i])
			fff = result[i];

	//���� ���� ��ǥ���� ���� �ĺ����� �ݺ������� ã�� Ż����Ŵ
	for (int i = 0; i < cand; i++)
		if (result[i] == fff)
			fail[i] = true;
}


