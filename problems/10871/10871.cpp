#include<cstdio>
#include<algorithm>
#include<vector>    

using namespace::std;

int main(void)
{
    int n, x;
    
    vector<int> arr;
    scanf("%d %d", &n, &x);
    
    for(int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d",&temp);
        arr.push_back(temp);
    }
    
    for(int i = 0; i < n; i++)
    {
        if(arr[i] < x)
           printf("%d ",arr[i]);
    }   
}
