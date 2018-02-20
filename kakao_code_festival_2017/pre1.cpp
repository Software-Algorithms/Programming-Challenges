#include <iostream>
#include <vector>

using namespace std;

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
vector<int> solution(int m, int n, vector< vector <int> > picture)
{
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	//area�� area ũ�� ������ ���� ����, area[0]�� ��ĥ���� ���� ���̴�.
	vector <int> areas;
	areas.push_back(0);
	//area�� ��ȣ�� ������ �� m*n ������ ��(?) ����
	//vector< vector <int> > picture_a(m, vector<int>(n, NULL));
	vector<vector<int> > picture_a;
	for (int i = 0; i < m; i++)
	{
		vector<int> element;
		element.resize(n);
		for (int j = 0; j < n; j++)
			element[j] = 0;
		picture_a.push_back(element);
	}


	//area�� �ű�� ��ȣ ������ �� ����
	int area_n = 0;

	 for (int tm = 0; tm < m; tm++)
		 for (int tn = 0; tn < n; tn++)
		 {
			 int color = picture[tm][tn];

			 if (color == 0)
				 continue;

			 //��, ���� picture �˻��ؼ� ���� �����̸� �ش��ϴ� area ��ȣ�� �Ȱ��� �Ű��ش�. 
			 //��
			 else if (tm > 0 && picture[tm - 1][tn] == color)
				 picture_a[tm][tn] = picture_a[tm - 1][tn];

			 //��
			 else if (tn > 0 && picture[tm][tn - 1] == color)
				 picture_a[tm][tn] = picture_a[tm][tn - 1];
			 
			 //��, ���ʿ� ��� ���� ���� �������� ���ο� ���� �Ҵ��Ѵ�. 1�� 1���� �� ��쿡 ���Եȴ�.
			 else
			 {
				 area_n++;
				 picture_a[tm][tn] = area_n;
				 areas.push_back(0);
			 }

			 //�ش� ���� ��ȣ�� ���� ũ�⸦ 1 ������Ŵ
			 areas[picture_a[tm][tn]]++;
		 }

	 //area �� ���ϱ�
	 number_of_area = area_n;

	 //max_area ���� ���ϱ�
	 for (int i = 1; i <= area_n; i++)
		 if (areas[i] > max_size_of_one_area)
			 max_size_of_one_area = areas[i];
		 
	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}

int main()
{
	vector<vector<int> > picture;
	{
		vector<int> element;
		element.resize(4);
		picture.push_back(element);
	}

	picture = { { 1, 1, 1, 0 },{ 1, 2, 2, 0 },{ 1, 0, 0, 1 },{ 0, 0, 0, 1 },{ 0, 0, 0, 3 },{ 0, 0, 0, 3 } };

	vector<int> answer = solution(6, 4, picture);
	cout << answer[0] << endl;
	cout << answer[1] << endl;

	system("pause");
	return 0;
}