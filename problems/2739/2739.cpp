#include<cstdio>

int main(void)
{
    int count;
    scanf("%d",&count);
    
    for(int i = 1; i <= 9 ;i++)
    {
        printf("%d * %d = %d\n", count, i, count*i);
    }
}