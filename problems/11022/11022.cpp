#include<cstdio>

int main(void)
{
    int counter;
    scanf("%d", &counter);
    
    for(int i = 0; i < counter; i++)
    {
        int a, b;
        scanf("%d %d", &a,&b);
        
        printf("Case #%d: %d + %d = %d\n",i+1,a,b,a+b);
    }
}