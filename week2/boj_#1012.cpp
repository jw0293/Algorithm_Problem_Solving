#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, m, k;
int board[50 + 1][50 + 1];
bool visited[50 +1][50 + 1];

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, 1, -1};

bool isValid(int y, int x, int n, int m){
	return (0 <= y && y < n && 0 <= x && x < m);
}

int solution(int n, int m){
	int answer = 0;
	queue<pair<int, int>> q;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(board[i][j] == 1 && !visited[i][j]){
				answer++;
				q.push({i, j});
				visited[i][j] = true;

				while(!q.empty()){
					int y = q.front().first;
					int x = q.front().second;
					q.pop();

					for(int k=0;k<4;k++){
						int ny = y + dy[k];
						int nx = x + dx[k];

						if(!board[ny][nx]) continue;
						if(isValid(ny, nx, n, m) && !visited[ny][nx]){
							visited[ny][nx] = 1;
							q.push({ny, nx});
						}
					}
				}
			}
		}
	}
	return answer;
}

void solve(){
	int tc;
	cin >> tc;

	while(tc--){
		int y, x;
		cin >> n >> m >> k;
		memset(board, 0, sizeof(board));
		memset(visited, false, sizeof(visited));

		for(int i=0;i<k;i++){
			cin >> y >> x;
			board[y][x] = 1;
		}

		cout << solution(n, m) << endl;
	}
}

int main(){
	fastio;	
	solve();
	
	return 0;
}