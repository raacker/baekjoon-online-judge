#include<iostream>
#include<cstdio>
using namespace std;

int main(void)
{
	int T;
	scanf("%d",&T);
	for(int i = 0; i < T; i++)
	{
		int n;
		scanf("%d",&n);
		int* arr = new int[n];
		int total = 0;
		for(int j = 0; j < n; j++)
		{
			scanf("%d",&arr[j]);
			total += arr[j];
		}
		double average = total / n;
		int count = 0;
		for(int j = 0; j < n; j++)
		{
			if(arr[j] > average)
				count++;
		}
		printf("%.3lf\%\n", (((double)count / n) * 100.0));
	}
}