#include<cstdio>
#include<algorithm>
#include<vector>

using namespace::std;
int main(void)
{
    vector<int> arr;
    int a,b,c;
    scanf("%d %d %d", &a,&b,&c);
    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);
    
    sort(arr.begin(), arr.end());
    printf("%d", arr[1]);
}