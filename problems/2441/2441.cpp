#include<cstdio>

int main(void)
{
    int count;
    scanf("%d",&count);
    
    for(int i = 0; i < count; i++)
    {
        for(int j = 0; j < i; j++)
            printf(" ");
        for(int j = i; j < count; j++)
            printf("*");
        printf(" \n");
    }
}