#include<cstdio>

int main(void)
{
    int count;
    
    scanf("%d",&count);
    
    for(int i = 0; i < count; i++)
    {
        for(int j = i; j < count-1; j++)
        {
            printf(" ");       
        }
        for(int k = 0; k <= i; k++)
        {
            printf("*");   
        }
        printf("\n");
    }
}