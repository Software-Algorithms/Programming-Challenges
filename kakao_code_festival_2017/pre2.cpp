#include<iostream>
#include<vector>
using namespace std;

int solution(int m, int n, vector<vector<int> > city_map);

const int MOD = 20170805;

int main()
{
	vector<vector<int> > city_map;

	vector<int> element(6, 0);
	for (int i = 0; i < 3; i++)
		city_map.push_back(element);

	int arr[3][6] = { {0, 2, 0, 0, 0, 2},{0, 0, 2, 0, 1, 0},{1, 0, 0, 2, 2, 0} };
	
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 6; j++)
		{
			city_map[i][j] = arr[i][j];
			cout << city_map[i][j];
		}

	cout << endl;
	int answer = solution(3, 6, city_map);

	cout << answer;
	system("pause");
}

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
int solution(int m, int n, vector<vector<int> > city_map) {
	vector<vector<int> > routesV;
	vector<int> elementV(n + 1, 0);
	for (int i = 0; i < m + 1; i++)
		routesV.push_back(elementV);

	vector<vector<int> > routesH;
	vector<int> elementH(n + 1, 0);
	for (int i = 0; i < m + 1; i++)
		routesH.push_back(elementH);

	routesH[1][0] = 1;
	for (int i = 1; i < m + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (city_map[i-1][j-1] == 1)
				continue;

			else if (city_map[i-1][j-1] == 0)
			{
				routesV[i][j] = routesV[i - 1][j] + routesH[i][j - 1];
				routesH[i][j] = routesV[i][j];
			}

			else if (city_map[i-1][j-1] == 2)
			{
				routesV[i][j] = routesV[i - 1][j];
				routesH[i][j] = routesH[i][j - 1];
			}
		}
	}

	return routesH[m][n];
}

/*
���� �߽ɰ��� ������ m �� n ũ���� ���� ��� �迭 city_map���� �־�����. �ڵ����� ������ �Ǵ� �Ʒ� �������� �� ĭ�� �̵� �����ϴ�.

city_map[i][j]���� ������ ��Ȳ�� ��Ÿ���� ���� ����Ǿ� �ִ�.

0�� ��쿡�� �ڵ����� �����Ӱ� ������ �� �ִ�.
1�� ��쿡�� �ڵ��� ������ �����Ǿ� ������ �� ����.
2�� ���� ������ ������ ���� ��ȸ���̳� ��ȸ���� �����ȴ�. (���ʿ��� ���� ���� ���������θ�, ������ ���� ���� �Ʒ������θ� ���� �����ϴ�)
*/