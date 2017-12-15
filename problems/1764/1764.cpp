#include<iostream>
#include<set>
#include<cstdio>
#include<algorithm>

using namespace std;

int main(void)
{
	int n, m;
	scanf("%d %d",&n,&m);

	set<string> nset;
	set<string> mset;
	set<string> result;

	for(int i = 0; i < n; i++)
	{
		string c;
		cin >> c;
		nset.insert(c);
	}
	for(int i = 0; i < m; i++)
	{
		string c;
		cin >> c;
		pair<set<string>::iterator, bool> pr;
		if((pr = nset.insert(c)).second == false)
			result.insert(c);
	}
	
	vector<string> res(result.begin(), result.end());
	sort(res.begin(), res.end());
	cout << res.size() << endl;
	for(int i = 0; i < res.size(); i++)
	{
		cout << res[i] << endl;
	}
}