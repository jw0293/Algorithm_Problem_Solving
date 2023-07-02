#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MX = 10 + 1;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, 1, -1};

int N, answer = INF;
int board[MX][MX];
bool visited[MX][MX], chk[MX][MX];
vector<pair<int, int>> temp;

void input(){
	cin >> N;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin >> board[i][j];
		}
	}
}

bool isValid(int y, int x){
	return (1 <= y && y <= N && 1 <= x && x <= N);
}

bool isOk(int y, int x){
	memset(chk, false, sizeof(chk));

	for(auto &t : temp){
		int cy = t.first;
		int cx = t.second;
		chk[cy][cx] = true;

		for(int i=0;i<4;i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if(!isValid(ny, nx) || chk[ny][nx]) return false;
			chk[ny][nx] = true;
		}
	}

	for(int i=0;i<4;i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		chk[y][x] = true;

		if(!isValid(ny, nx) || chk[ny][nx]) return false;
		chk[ny][nx] = true;
	}
	return true;
}

int getCost(){
	int ret = 0;
	for(auto &t : temp){
		ret += board[t.first][t.second];
		for(int i=0;i<4;i++){
			ret += board[t.first + dy[i]][t.second + dx[i]];
		}
	}
	return ret;
}

void solution(int y, int cnt){
	if(cnt == 3){
		answer = min(answer, getCost());
		return;
	}

	for(int i=y;i<N;i++){
		for(int j=2;j<N;j++){
			if(!visited[i][j] && isOk(i, j)){
				visited[i][j] = true;
				temp.push_back({i, j});

				solution(i, cnt+1);

				visited[i][j] = false;
				temp.pop_back();
			}
		}
	}
}

int main(){
	fastio;	
	input();
	solution(2, 0);
	cout << answer << endl;

	return 0;
}