#include<iostream>

using namespace std;

int arr[41] = {0,};
int zero_count[41] = {0,};
int one_count[41] = {0,};

int zero = 0;
int one = 0;

int fibo(int n)
{
	if(n == 0)
	{
		zero++;
		return 0;
	}
	if(n == 1)
	{
		one++;
		return 1;
	}
	if(arr[n-1] == 0)
	{
		arr[n-1] = fibo(n-1);
		zero_count[n-1] = zero;
		one_count[n-1] = one;
	}
	else{
		zero += zero_count[n-1];
		one += one_count[n-1];
	}
	if(arr[n-2] == 0)
	{
		arr[n-2] = fibo(n-2);
		zero_count[n-2] = zero;
		one_count[n-2] = one;
	}	
	else	
	{
		zero += zero_count[n-2];
		one += one_count[n-2];
	}
		
	return arr[n-1] + arr[n-2];

}
int main(void)
{
	int N;
	scanf("%d",&N);

	for(int i = 0; i < N; i++)
	{
		int test;
		scanf("%d",&test);		
		zero = 0;
		one = 0;
		fibo(test);
		
		zero_count[test] = zero;
		one_count[test] = one;
		printf("%d %d\n",zero, one);
	}
}