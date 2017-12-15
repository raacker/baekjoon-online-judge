#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>

using namespace::std;

int main(void)
{
	string s;
	int len;
	vector<string> prefix;
	
	cin >> s;
	len = s.length();
	
	for(int i = 0; i < s.length(); i++)
	{
		prefix.push_back(s.substr(i,s.length()));
	}

	sort(prefix.begin(), prefix.end());

	for(int i = 0; i < prefix.size(); i++)
	{
		cout << prefix.at(i) << endl;
	}
}