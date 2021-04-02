#include <stdio.h>
#include <vector>

using namespace std;

int main(void) {
	int t, fibo, a, b, tmp, n;
	vector<int> vec;
	scanf("%d", &t);
	for(int tcase=0; tcase<t; tcase++){
		vec.clear();
		scanf("%d", &fibo);
		while(fibo>0){
			a = 0;
			b = 1;
			while(b<=fibo){
				tmp = b;
				b += a;
				a = tmp;
			}
			fibo -= a;
			vec.push_back(a);
		}
		int vsize = vec.size();
		for(int i=vsize-1; i>=0; i--)
			printf("%d ", vec[i]);
		printf("\n");
	}
    return 0;
}