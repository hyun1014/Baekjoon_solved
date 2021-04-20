#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main(void) {
	int N, left, right, total, vec_len, answer;
	scanf("%d", &N);
	vector<bool> isPrime (N+1, true);
	vector<int> prime_vector;
	isPrime[1] = false;
	for(int i=2; i<=N/2; i++){
		if(!isPrime[i])
			continue;
		for(int j=2; i*j<=N; j++)
			isPrime[i*j] = false;
	}
	for(int i=2; i<=N; i++)
		if(isPrime[i])
			prime_vector.push_back(i);
	vec_len = prime_vector.size();
	left = 0;
	right = -1;
	total = 0;
	answer = 0;
	while(true){
		if(total>=N){
			if(total==N)
				answer++;
			total -= prime_vector[left];
			left++;
			if(left==vec_len)
				break;
		} else {
			right++;
			if(right==vec_len)
				break;
			total += prime_vector[right];
		}
	}
	printf("%d\n", answer);
	return 0;
}