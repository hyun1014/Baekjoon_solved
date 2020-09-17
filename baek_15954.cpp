#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;

int main(void){
    long double n, k, m, b, result;
    result = 9999999999;
    scanf("%Lf %Lf", &n, &k);
    vector<long double> dolls (n,0);
    for(int i=0; i<n; i++)
        scanf("%Lf", &dolls[i]);
    for(int i=k; i<=n; i++){
        for(int j=0; j<n-i+1; j++){
            m = 0, b = 0;
            for(int l=j; l<j+i; l++)
                m += dolls[l];
            m /= i;
            for(int l=j; l<j+i; l++)
                b += (dolls[l] - m) * (dolls[l] - m);
            b /= i;
            b = sqrt(b);
            if(b < result)
                result = b;
        }
    }
    printf("%Lf\n", result);
    return 0;
}