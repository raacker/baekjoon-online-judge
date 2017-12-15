#include<cstdio>
#include<vector>

using namespace::std;

int check[1000000];
void dfs(int x);
int square(int x, int y);
int length(int a, int p, int cnt);

int main(void)
{
	int a, p;

	scanf("%d %d", &a, &p);

	printf("%d",length(a,p,1));
}

int length(int a, int p, int cnt)
{
	if(check[a] != 0)
			return check[a]-1;

	check[a] = cnt;
	int b = square(a,p);
	return length(b, p, cnt+1);
}

int square(int x, int y)
{
		int result = 0;
		while(x > 0)
		{
				int mult = 1;
				for(int i = 0; i < y; i++)
						mult *= x%10;
				result += mult;
				x /= 10;
		}

		return result;
}