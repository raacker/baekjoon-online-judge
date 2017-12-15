#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void)
{
	vector<int> arr(5,0);

	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			int sum = 0;
			scanf("%d", &sum);
			arr[i] += sum;
		}
	}

	int max = arr[0];
	int index = 0;
	for(int i = 1; i < 5; i++)
	{
		if(max < arr[i])
		{
			max = arr[i];
			index = i;
		}
	}

	printf("%d %d\n", index+1, max);
}