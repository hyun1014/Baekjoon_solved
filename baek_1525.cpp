#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <math.h>
using namespace std;

int swapNumber(int num, int idx1, int idx2){
	int tempNum = num;
	int tempidx = 9 - idx2;
	while(tempidx>0){
		tempNum /= 10;
		tempidx--;
	}
	int targetNum = tempNum %= 10;

	return num - (targetNum * (int)pow(10, 9-idx2)) + (targetNum * (int)pow(10, 9-idx1)) ;
}

vector<int> bfsSearch(int num){
	vector<int> vec;
	int tempNum = num;
	int idx = 9;
	while(tempNum%10!=0){
		tempNum /= 10;
		idx--;
	}
	if(idx>3)
		vec.push_back(swapNumber(num, idx, idx-3));
	if(idx<7)
		vec.push_back(swapNumber(num, idx, idx+3));
	if(idx%3!=1)
		vec.push_back(swapNumber(num, idx, idx-1));
	if(idx%3!=0)
		vec.push_back(swapNumber(num, idx, idx+1));
	return vec;
}

int main(void) {
	int num = 1, prev = 1, next = 0, lv = 0, cur = 0;
	set<int> numberSet;
	queue<int> que;
	for(int i=0; i<9; i++){
		scanf("%d", &cur);
		num = (num*10) + cur;
	}
	
	que.push(num);
	while(!que.empty()){
		cur = que.front();
		que.pop();
		prev--;
		numberSet.insert(cur);
		if(cur==1123456780)
			break;

		vector<int> vec = bfsSearch(cur);
		for(auto tar : vec){
			if(numberSet.find(tar)==numberSet.end()){
				numberSet.insert(tar);
				que.push(tar);
				next++;
			}
		}
		if(prev==0){
			prev = next;
			next = 0;
			lv++;
		}
	}
	if(cur!=1123456780)
		lv = -1;
	printf("%d\n", lv);

	return 0;
}