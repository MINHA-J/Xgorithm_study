#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ���� ���̵��: R �� ���̴� �ǹ��� �� + L�� ���̴� �ǹ��� ��
// �� Ǯ���� ������,
// �� ���� �ʾƼ� �ڵ� �����Ͽ� Ǯ����

//+------ First Think --------+//
/*
void R_MaxView(int N, vector<int>& buildings)
{
	vector<int> RightMaxIndexs(N); // ������ ���� ���� ������, ���� ���� ����
	
	RightMaxIndexs[0] = (N - 1);	// (n-1)�ǹ��� �����ʿ��� �ƹ��͵� ����
	RightMaxIndexs[1] = (N - 1);	// (n-2)�ǹ��� n-1 index�� ���� ����
	
	// buildings�� ������ ���� ���캸��
	for (int standard = N-3; standard >= -1; standard--)
	{
		int leftIndex = standard + 1; // ���� ���ؿ��� �������� ���Ұ���
		int standardHeight = buildings[leftIndex];

		for (int i = standard + 2; i < N; i++)
		{
			if (buildings[i] > standardHeight)
			{
				leftIndex = i;
				standardHeight = buildings[i];
				RightMaxIndexs[(N-1) - standard] = leftIndex;
			}
			else break;
		}
	}

	reverse(RightMaxIndexs.begin(), RightMaxIndexs.end());

	// Debug
	cout << "\n�������� ������ �� ���� ���� ���� �ε���\n";
	for (int i = 0; i < N; i++)
		cout << RightMaxIndexs[i] << " ";

	cout << "\n�������� ������ �� ���̴� ���� ��\n";
	for (int i = 0; i < N; i++)
		cout << RightMaxIndexs[i] - i << " ";
}


int main()
{
	int N;
	cin >> N;

	int height;
	vector<int> buildings;

	for (int i = 0; i < N; i++)
	{
		cin >> height;
		buildings.push_back(height);
	}

	R_MaxView(N, buildings);
}*/


//+------ Second Think --------+//

void GetMaxBuildingView(int n, vector<int> &buildings)
{
	vector<int> count(n);

	for (int i = 0; i < n; i++)
	{
		double maxGradient = -1000000000;

		for (int j = i + 1; j < n; j++)
		{
			// �� �ε��� ���� ������ ���� ���ϱ�
			double tempGradient = (double)(buildings[j] - buildings[i]) / (j - i);

			if (tempGradient <= maxGradient)
				continue;

			maxGradient = tempGradient;
			count[i]++; 
			count[j]++;
		}	
	}

	std::cout << *max_element(count.begin(), count.end());
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	cin >> N;

	int height;
	vector<int> buildings;

	for (int i = 0; i < N; i++)
	{
		cin >> height;
		buildings.push_back(height);
	}

	GetMaxBuildingView(N, buildings);
}