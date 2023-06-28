#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MX = 50 + 1;

int N, M;
int board[MX + 1][MX + 1];
int visited[MX + 1][MX + 1];
vector<pair<int, int>> pos;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, 1, -1};

bool isValid(int y, int x){
	return (1 <= y && y <= N && 1 <= x && x <= M);
}

void input(){
	cin >> N >> M;
	cin.ignore();
	for(int i=1;i<=N;i++){
		string str;
		getline(cin, str);

		for(int j=0;j<str.size();j++){
			if(str[j] == 'W') board[i][j+1] = 1;
			else {
				board[i][j+1] = 0;
				pos.push_back({i, j+1});
			}
		}
	}
}

int solution(){
	int answer = 1;
	for(auto &p : pos){
		memset(visited, 0, sizeof(visited));

		queue<pair<int, int>> q;
		q.push({p.first, p.second});

		visited[p.first][p.second] = 1;
		while(!q.empty()){
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			answer = max(answer, visited[y][x]);

			for(int i=0;i<4;i++){
				int ny = y + dy[i];
				int nx = x + dx[i];

				if(!isValid(ny, nx)) continue;
				if(!visited[ny][nx] && board[ny][nx] == 0){
					q.push({ny, nx});
					visited[ny][nx] = visited[y][x] + 1;
				}
			}
		}
	}
	return answer-1;
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;

	return 0;
}