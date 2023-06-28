#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MX = 50 + 1;

int N, M, answer = INF;
int board[MX + 1][MX + 1];
bool visited[MX + 1][MX + 1];
vector<pair<int, int>> chk, home;

void input(){
	cin >> N >> M;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin >> board[i][j];
			if(board[i][j] == 1){
				home.push_back({i, j});
			}
		}
	}
}

int getDist(){
	int d = 0;
	for(auto &h : home){
		int v = INF;
		for(auto &c : chk){
			v = min(v, (abs(c.first - h.first) + abs(c.second - h.second)));
		}
		d += v;
	}
	return d;
}

void solution(int y, int x){
	if(chk.size() == M){
		answer = min(answer, getDist());
		return;
	}

	for(int i=y;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(!visited[i][j] && board[i][j] == 2){
				visited[i][j] = true;
				chk.push_back({i, j});

				solution(i, j);

				visited[i][j] = false;
				chk.pop_back();
			}
		}
	}
}

int main(){
	fastio;	
	input();
	solution(1, 1);
	cout << answer << endl;

	return 0;
}