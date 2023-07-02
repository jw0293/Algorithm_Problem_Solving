#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MX = 20 + 1;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, 1, -1};

int N, M, answer;
char board[MX][MX];
bool alpha[26 + 1];
bool visited[MX][MX];

void input(){
	cin >> N >> M;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cin >> board[i][j];
		}
	}
}

void init(){
	visited[1][1] = true;
	alpha[board[1][1]-'A'] = true;
}

bool isValid(int y, int x){
	return (1 <= y && y <= N && 1 <= x && x <= M);
}

bool isCanGo(int y, int x){
	for(int i=0;i<4;i++){
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(!isValid(ny, nx)) continue;
		if(!visited[ny][nx] && !alpha[board[ny][nx]-'A']) return true;
	}
	return false;
}

void solution(int y, int x, int cnt){
	if(!isCanGo(y, x)){
		answer = max(answer, cnt);
		return;
	}

	for(int i=0;i<4;i++){
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(!isValid(ny, nx)) continue;
		if(!visited[ny][nx] && !alpha[board[ny][nx] - 'A']){
			visited[ny][nx] = true;
			alpha[board[ny][nx]-'A'] = true;

			solution(ny, nx, cnt+1);

			visited[ny][nx] = false;
			alpha[board[ny][nx]-'A'] = false;
		}
	}
}

int main(){
	fastio;	
	input();
	solution(1, 1, 1);
	cout << answer << endl;

	return 0;
}