#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MX = 8 + 1;

int n, m, result;
int board[MX][MX], temp[MX][MX];
bool visited[MX][MX];
vector<pair<int, int>> virus;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

bool isValid(int y, int x){
	return (1 <= y && y <= n && 1 <= x && x <= m);
}

void input(){
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> board[i][j];
			if(board[i][j] == 2){
				virus.push_back({i, j});
			}
		}
	}
}

void copy(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			temp[i][j] = board[i][j];
		}
	}
}

int countingSafety(){
	int cnt = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(temp[i][j] == 0) {
				cnt++;
			}
		}
	}
	return cnt;
}

int spreadVirus(){
	queue<pair<int, int>> q;
	memset(visited, false, sizeof(visited));
	for(auto t : virus){
		visited[t.first][t.second] = true;
		q.push(t);
	}

	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for(int i=0;i<4;i++){
			int ny = y + dy[i];
			int nx = x + dx[i];

			if(!isValid(ny, nx)) continue;
			if(!visited[ny][nx] && temp[ny][nx] == 0){
				visited[ny][nx] = true;
				q.push({ny, nx});
				temp[ny][nx] = 2;
			}
		}
	}

	return countingSafety();
}

void solution(int cnt){
	if(cnt == 3){
		copy();
		result = max(result, spreadVirus());
		return;
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(board[i][j] == 0){
				board[i][j] = 1;
				
				solution(cnt+1);

				board[i][j] = 0;
			}
		}
	}
}

int main(){
	fastio;	
	input();
	solution(0);
	cout << result << endl;

	return 0;
}
