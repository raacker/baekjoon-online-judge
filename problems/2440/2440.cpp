#include<cstdio>

int main(void)
{
    int count;
    
    scanf("%d", &count);
    
    for(int i = count; i > 0; i--)
    {
        for(int j = i; j > 0; j--)
        {
            printf("*");
        }
        printf(" \n");  
    }
}