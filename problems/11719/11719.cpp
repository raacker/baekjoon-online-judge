#include<iostream>
#include<cstdio>

using namespace std;

int main(void){
	char c[100];
	while(fgets(c, 100, stdin)){
		cout << c;
	}
}