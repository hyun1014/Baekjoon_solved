#include <stdio.h>

using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);
	for(int tcase=0; tcase<n; tcase++){
		int len=0, left=0, right=0;
		int left2=-1, right2=-1; // 오른쪽 꺼에서 뺄 경우
		int flag = 0;
		char arr[100000];
		scanf("%s", arr);
		while(arr[len]!=0)
			len++;
		left = 0;
		right = len-1;

		while(left<=right){
			if(arr[left]==arr[right]){
				left++;
				right--;
			} else {
				if(arr[left+1]==arr[right]){
					if(arr[left]==arr[right-1] && flag==0){ // 왼쪽거를 빼도 회문, 오른쪽 꺼를 빼도 회문
						left2 = left; // 이 경우 이따 오른쪽 거를 뺀 경우에 회문이 되는지 추가로 알아봐야 함.
						right2 = right; // 우선 왼쪽거를 빼고 진행
					}
					flag++;
					left++;
					if(flag==2)
						break;
				} else if (arr[left]==arr[right-1]){
					flag++;
					right--;
					if(flag==2)
						break;
				} else {
					flag = 2;
					break;
				}
			}
		}
		if(left2!=-1 && right2!=-1 && flag==2){ // 왼쪽꺼 뺐는데 회문이 아님. 오른쪽꺼를 한번 빼보자.
			flag = 1;
			right2--;
			while(left2<=right2){
				if(arr[left2]==arr[right2]){
					left2++;
					right2--;
				} else {
					flag++;
					break;
				}
			}
		}
		printf("%d\n", flag);
	}

    return 0;
}