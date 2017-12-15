#include<iostream>

using namespace std;
int main(void)
{
  int cheatsheet[10][4] = {0,10,10,10,
						1,1,1,1,
						6,2,4,8,
						1,3,9,7,
						6,4,6,4,
						5,5,5,5,
						6,6,6,6,
						1,7,9,3,
						6,8,4,2,
						1,9,1,9};
	int T;
	scanf("%d",&T);
	
	for(int i = 0; i < T; i++)
	{
		int a=0, b=0;
		scanf("%d %d",&a,&b);

		printf("%d\n",cheatsheet[a%10][b%4]);
	}
}