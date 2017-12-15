#include<cstdio>

int main(void)
{
    int num;
    scanf("%d",&num);
    
    int total = 0;
    for(int i = 1; i <= num; i++)
    {
        total += i;
    }
    
    printf("%d",total);
}