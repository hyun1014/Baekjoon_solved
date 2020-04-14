#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	string str;
	int t;
	scanf("%d", &t);
	getchar();
	for(int i=0 ; i<t ; i++){
		char s[1001];
		scanf("%[^\n]", s);
	    getchar();
		str = s;
		int len = str.length();
		int sidx = 0;
		for(int j=0 ; j<len ; j++){
			if(str[j]==' '){
				reverse(&str[sidx], &str[j]);
				sidx = j+1;
			}
		}
		reverse(&str[sidx], &str[len]);
		cout<<str<<"\n";
	}
	return 0;
}