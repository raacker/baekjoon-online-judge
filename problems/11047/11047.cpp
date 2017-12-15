#include<iostream>

using namespace std;

int arr[11] = {0,};
int res = 0;

void calculate(int K, int index)
{
	if(index == -1)
		return;
	res += K / arr[index];
	calculate(K%arr[index], index-1);
}

int main(void)
{
	int N, K;
	scanf("%d %d",&N, &K);
	
	int index = 0;
	for(int i = 0; i < N; i++)
	{
		scanf("%d",&arr[i]);
		if(K/arr[i] != 0)
			index = i;
	}
	if (K == 1)
		res = 1;
	else
		calculate(K, index);
	printf("%d\n",res);
}