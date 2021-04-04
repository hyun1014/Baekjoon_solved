#include <stdio.h>

using namespace std;

int main(void) {
	int tcase = 1;
	int len;
	// 문자열
	char arr[2000];
	while(true){
		len = 0;
		char stk[2000]; // 스택
		int stlen=0; // 스택 길이
		int left=0, right=0; // 스택 안 괄호 개수
		scanf("%s", arr);
		if(arr[0]=='-')
			break;
		while(arr[len]!=0)
			len++;

		for(int i=0; i<len; i++){
			if(arr[i]=='{')
				stk[stlen++] = '{';
			else {
				if(stlen==0)
					stk[stlen++] = '}';
				else {
					if(stk[stlen-1]=='{')
						stk[stlen--] = 0; // 짝을 만났으니 스택 pop
					else
						stk[stlen++] = '}'; 
				}
			}
		}
		while(right<stlen && stk[right]=='}')
			right++;
		left = stlen - right;
		printf("%d. %d\n", tcase, (left+1)/2 + (right+1)/2);
		tcase++;
	}

    return 0;
}