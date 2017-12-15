#include<iostream>
#include<algorithm>

using namespace std;

int main(void)
{
    int arr[501][501];
    int volume;
    int result = 0;
    scanf("%d",&volume);

    for(int i = 1; i <= volume; i++)
    {
        for(int j = 1; j<= i; j++)
        {
            int num;
            scanf("%d",&num);
            arr[i][j] = max(arr[i-1][j-1], arr[i-1][j]) + num;
            result = max(arr[i][j], result);            
        }
    }
    printf("%d",result);
}