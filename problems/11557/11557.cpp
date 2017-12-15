#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	int T;
	scanf("%d",&T);

	for(int i = 0 ; i < T; i++)
	{
		int N;
		string univ;
		string max_univ;	
		int value = 0;	
		int max;

		scanf("%d",&N);

		cin >> max_univ;
		scanf("%d",&max);
		
		for(int j = 1; j < N; j++)
		{
			cin >> univ;
			scanf("%d",&value);
			if (max < value)
			{
				max = value;
				max_univ = univ;
			}	
		}
		cout << max_univ << endl;
	}
}