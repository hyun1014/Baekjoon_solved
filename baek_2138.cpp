#include <stdio.h>

using namespace std;

void click(char* arr, int idx, int len){
	for(int i=idx-1 ; i<idx+2; i++)
		if(i!=-1 && i!=len)
			arr[i] = arr[i]=='0' ? '1' : '0';
}

int main(void) {
	int n, cnt0, cnt1, ans;
	bool flag = true; // target과 일치하게 스위치 조작했을 경우 true, 아님 false
	char arr0[100000];
	char arr1[100000];
	char tar[100000];
	scanf("%d", &n);
	scanf("%s", arr0);
	scanf("%s", tar);
	ans = 200000; // 정답 디폴트값 200000 -> 최대 가능한 값은 100000
	cnt0 = 0; // 맨 앞 스위치 안눌렀을 때
	cnt1 = 1; // 맨 앞 스위치 눌렀을 때

	for(int i=0; i<n; i++)
		arr1[i] = arr0[i];

	click(arr1, 0, n);

	for(int i=1; i<n; i++){
		if(arr0[i-1]!=tar[i-1]){ // 스위치 앞 쪽꺼가 target이랑 다를 경우
			cnt0++;
			click(arr0, i, n);
		}
	}

	for(int i=1; i<n; i++){
		if(arr1[i-1]!=tar[i-1]){
			cnt1++;
			click(arr1, i, n);
		}
	}

	for(int i=0; i<n; i++){
		if(arr0[i]!=tar[i]){
			flag = false;
			break;
		}
	}
	if(flag && (ans>cnt0))
		ans = cnt0;
	flag = true;

	for(int i=0; i<n; i++){
		if(arr1[i]!=tar[i]){
			flag = false;
			break;
		}
	}
	if(flag && (ans>cnt1))
		ans = cnt1;
	
	if(ans==200000) // 정답이 없음
		ans = -1;

	printf("%d\n", ans);

    return 0;
}