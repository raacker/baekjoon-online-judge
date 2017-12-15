#include<cstdio>

int main(void)
{
    int a,b;
    scanf("%d %d", &a,&b);
    
    printf("%.25Lf",(long double)a/b);
}