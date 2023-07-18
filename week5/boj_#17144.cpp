#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, m, t;
pair<int, int> up, down;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, 1, -1};
int board[50 + 1][50 + 1], temp[50 + 1][50 + 1];

void input(){
	cin >> n >> m >> t;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> board[i][j];
			if(board[i][j] == -1){
				if(up.first == 0 && up.second == 0) {
					up.first = i;
					up.second = j;
				} else{
					down.first = i;
					down.second = j;
				}
			}
		}
	}
}

bool isValid(int y, int x){
	return (1 <= y && y <= n && 1 <= x && x <= m);
}

queue<pair<pair<int, int>, int>> getVirus(){
	queue<pair<pair<int, int>, int>> q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(board[i][j] > 0){
				q.push({{i, j}, board[i][j]});
			}
		}
	}
	return q;
}

void spreadVirus(){
	queue<pair<pair<int, int>, int>> q = getVirus();
	while(!q.empty()){
		int y = q.front().first.first;
		int x = q.front().first.second;
		int val = q.front().second;
		q.pop();

		val /= 5;
		int cnt = 0;
		for(int i=0;i<4;i++){
			int ny = y + dy[i];
			int nx = x + dx[i];

			if(!isValid(ny, nx) || board[ny][nx] == -1) continue;
			cnt++;
			board[ny][nx] += val;
		}

		board[y][x] -= (val * cnt);
	}
}

void copy(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			temp[i][j] = board[i][j];
		}
	}
}

void reverseClock(){
	copy();
	for(int i=2;i<=m;i++) {
		if(i-1 == up.second) {
			board[up.first][i] = 0;
			continue;
		}
		board[up.first][i] = temp[up.first][i-1];
	}

	for(int i=up.first-1;i>=1;i--){
		board[i][m] = temp[i+1][m];
	}

	for(int i=m-1;i>=1;i--){
		board[1][i] = temp[1][i+1];
	}

	for(int i=2;i<=up.first-1;i++){
		board[i][up.second] = temp[i-1][up.second];
	}
}

void goClock(){
	copy();
	for(int i=2;i<=m;i++) {
		if(i-1 == down.second){
			board[down.first][i] = 0;
			continue;
		}
		board[down.first][i] = temp[down.first][i-1];
	}

	for(int i=down.first+1;i<=n;i++){
		board[i][m] = temp[i-1][m];
	}

	for(int i=m-1;i>=1;i--){
		board[n][i] = temp[n][i+1];
	}

	for(int i=n-1;i>down.first;i--){
		board[i][down.second] = temp[i+1][down.second];
	}
}

int getResult(){
	int ret = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(board[i][j] <= 0) continue;
			ret += board[i][j];
		}
	}
	return ret;
}

int solution(){
	while(t--){
		spreadVirus();
		goClock();
		reverseClock();
	}
	return getResult();
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;
	return 0;
}