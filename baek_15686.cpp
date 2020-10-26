#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> com;
vector<vector<int>> comtable;
vector<pair<int,int>> home;
vector<pair<int,int>> chick;
int n, m, tmp, homesize, chicksize, comtablesize;

void combi(int n){
    com.push_back(n);
    if(com.size()==m){
        comtable.push_back(com);
        com.pop_back();
        return;
    }
    for(int i=n+1; i<chick.size(); i++){
        combi(i);
    }
    com.pop_back();
}

int main(void){
    int ans = 99999, tmp = 99999, dis = 0, tmpans = 0;
    pair<int,int> curhome, curchick;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &tmp);
            if(tmp==1)
                home.push_back(make_pair(i,j));
            else if(tmp==2){
                chick.push_back(make_pair(i,j));
            }
        }
    }
    homesize = home.size();
    chicksize = chick.size();
    for(int i=0; i<chicksize; i++){
        combi(i);
    }
    comtablesize = comtable.size();
    for(int i=0; i<comtablesize; i++){
        tmpans = 0;
        for(int j=0; j<homesize; j++){
            tmp = 99999;
            curhome = home[j];
            for(int k=0; k<m; k++){
                curchick = chick[comtable[i][k]];
                dis = abs(curchick.first - curhome.first) + abs(curchick.second - curhome.second);
                tmp = min(tmp, dis);
            }
            tmpans += tmp;
        }
        ans = min(ans, tmpans);
    }
    printf("%d\n", ans);
    return 0;
}