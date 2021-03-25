#include <stdio.h>
#include <queue>

using namespace std;

bool board[1001][1001];
bool visited_break[1001][1001];
bool visited_unbreak[1001][1001];
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

int main(void) {
	int n, m;
	int prev=1, next=0, lv=1;
	char str[1001];
	queue<pair<int, bool>> queue;
	scanf("%d %d", &n, &m);

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			visited_break[i][j] = false;
			visited_unbreak[i][j] = false;
		}
	}

	for(int i=0; i<n; i++){
		scanf("%s", str);
		for(int j=0; j<m; j++)
		board[i+1][j+1] = str[j]=='0' ? true : false;
	}

	queue.push(make_pair(10001, true));

	while(!queue.empty()){
		pair<int,bool> cur = queue.front();
		queue.pop();
		if(cur.first==(n*10000+m))
			break;
		int curx = cur.first/10000, cury = cur.first%10000;
		for(int i=0; i<4; i++){
			int tarx = curx+dx[i], tary = cury+dy[i];
			if(tarx>=1 && tarx<=n && tary>=1 && tary<=m){
				if(board[tarx][tary]){
					if(cur.second && !visited_unbreak[tarx][tary]){
						visited_unbreak[tarx][tary] = true;
						queue.push(make_pair(tarx*10000+tary, true));
						next++;
					} else if (!cur.second && !visited_break[tarx][tary]){
						visited_break[tarx][tary] = true;
						queue.push(make_pair(tarx*10000+tary, false));
						next++;
					}
				} else if (cur.second && !visited_break[tarx][tary]){
					visited_break[tarx][tary] = true;
					queue.push(make_pair(tarx*10000+tary, false));
					next++;
				}
			}
		}
		prev--;
		if(prev==0){
			prev = next;
			next = 0;
			lv++;
		}
	}

	if(!(visited_break[n][m] || visited_unbreak[n][m]))
		lv = -1;
	printf("%d\n", lv);

	return 0;
}