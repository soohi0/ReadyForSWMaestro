#include <iostream>
#include <vector>

using namespace std;
int N;
int * orange;
int main()
{
	cin >> N;
	orange = new int[N];
	vector<int> v;
	int yangsoo = 0;
	bool wasyangsoo = false;
	int rank;

	for (int i = 0; i < N; i++)
	{
		cin >> rank;
		orange[i] = rank;
		if (rank < 0)
		{
			if (wasyangsoo)
			{
				v.push_back(yangsoo);
			}
			v.push_back(rank);
			yangsoo = 0;
			wasyangsoo = false;
		}
		else
		{
			yangsoo += rank;
			if (i == N - 1)
			{
				v.push_back(yangsoo);
			}
			wasyangsoo = true;
		}
	}
	int leMidRi = -2; // le -1, mid : 0, right L 1
	
	//�� ������ ����� ã�´�.
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	//�ѹ������� Ž���Ͽ� �ִ밪�� �� ���� idx�� Ž��
	//�ش� idx�� ���� �����Ͽ� �� ���� ����
	// ���� �� ���� ������� return �� ����
	//������ ����/ ������ �����ư��鼭 ���Ұ�
	//���ʿ��� ����� ���ϰ� ������ �ϴ� �迭�� ���� �� ����
	//�����ʿ���
	/*
	7
	-7 7 1 -6 4 9 8
	*/

}