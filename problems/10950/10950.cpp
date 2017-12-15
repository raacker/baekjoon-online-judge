#include<cstdio>

int main(void)
{
    int counter;
    
    scanf("%d",&counter);
    
    for(int i = 0; i < counter; i++)
    {
         int a, b;
        scanf("%d %d",&a,&b);
        printf("%d\n",a+b);
    }
    
}