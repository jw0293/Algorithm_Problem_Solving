#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int MX = 50 + 1;

int N, M;
int cnt, maxArea, answer;
int board[MX][MX], visited[MX][MX], area[MX];

const int dy[] = {0, -1, 0, 1};
const int dx[] = {-1, 0, 1, 0};

bool isValid(int y, int x){
	return (1 <= y && y <= M && 1 <= x && x <= N);
}

void input(){
	cin >> N >> M;
	for(int i=1;i<=M;i++){
		for(int j=1;j<=N;j++){
			cin >> board[i][j];
		}
	}
}

int dfs(int y, int x, int number){
	if(visited[y][x]) return 0;
	visited[y][x] = number;
	int ret = 1;
	for(int i=0;i<4;i++){
		if(!(board[y][x] & (1 << i))){
			int ny = y + dy[i];
			int nx = x + dx[i];
			ret += dfs(ny, nx, number);
		}
	}
	return ret;
}

void solution(){
	int first, second;
	for(int i=1;i<=M;i++){
		for(int j=1;j<=N;j++){
			if(!visited[i][j]){
				cnt++;
				area[cnt] = dfs(i, j, cnt);
				maxArea = max(maxArea, area[cnt]);
			}
		}
	}

	for(int i=1;i<=M;i++){
		for(int j=1;j<=N;j++){
			if(i + 1 <= M){
				first = visited[i+1][j];
				second = visited[i][j];

				if(first != second){
					answer = max(answer, area[first] + area[second]);
				}
			}

			if(j + 1 <= N){
				first = visited[i][j+1];
				second = visited[i][j];

				if(first != second){
					answer = max(answer, area[first] + area[second]);
				}
			}
		}
	}
}

int main(){
	fastio;	
	input();
	solution();
	cout << cnt << endl << maxArea << endl << answer << endl;

	return 0;
}