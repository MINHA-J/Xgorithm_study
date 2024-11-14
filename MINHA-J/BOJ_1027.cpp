#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 기존 아이디어: R 편에 보이는 건물의 수 + L편에 보이는 건물의 수
// 로 풀려고 했지만,
// 잘 되지 않아서 코드 참고하여 풀었음

//+------ First Think --------+//
/*
void R_MaxView(int N, vector<int>& buildings)
{
	vector<int> RightMaxIndexs(N); // 오른편 기준 가장 가까이, 가장 높은 빌딩
	
	RightMaxIndexs[0] = (N - 1);	// (n-1)건물의 오른쪽에는 아무것도 없음
	RightMaxIndexs[1] = (N - 1);	// (n-2)건물은 n-1 index가 가장 높음
	
	// buildings의 오른편 부터 살펴보자
	for (int standard = N-3; standard >= -1; standard--)
	{
		int leftIndex = standard + 1; // 현재 기준에서 오른쪽을 비교할거임
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
	cout << "\n오른쪽을 보았을 때 가장 높은 빌딩 인덱스\n";
	for (int i = 0; i < N; i++)
		cout << RightMaxIndexs[i] << " ";

	cout << "\n오른쪽을 보았을 때 보이는 빌딩 수\n";
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
			// 두 인덱스 사이 빌딩의 기울기 구하기
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