#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, depth;
int temp[100 + 1][100 + 1];
int board[100 + 1][100 + 1];
bool visited[100 +1][100 + 1];

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, 1, -1};

bool isValid(int y, int x){
	return (1 <= y && y <= n && 1 <= x && x <= n);
}

void copy(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(board[i][j]) temp[i][j] = 1;
		}
	}
}

void makeMap(int d){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(board[i][j] <= d) {
				temp[i][j] = 0;
			}
		}
	}
}

int findHole(){
	int cnt = 0;
	queue<pair<int, int>> q;
	memset(visited, false, sizeof(visited));

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(!visited[i][j] && temp[i][j] == 1){
				cnt++;
				visited[i][j] = true;
				q.push({i, j});

				while(!q.empty()){
					int y = q.front().first;
					int x = q.front().second;
					q.pop();

					for(int k=0;k<4;k++){
						int ny = y + dy[k];
						int nx = x + dx[k];

						if(!temp[ny][nx]) continue;
						if(isValid(ny, nx) && !visited[ny][nx]){
							visited[ny][nx] = true;
							q.push({ny, nx});
						}
					}
				}
			}
		}
	}

	return cnt;
}

int solution(){
	int answer = 1;
	for(int d = 1; d < depth; d++){
		memset(temp, 0, sizeof(temp));
		copy();
		makeMap(d);

		answer = max(answer, findHole());
	}
	return answer;
}

void input(){
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> board[i][j];
			depth = max(depth, board[i][j]);
		}
	}
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;
	
	return 0;
}