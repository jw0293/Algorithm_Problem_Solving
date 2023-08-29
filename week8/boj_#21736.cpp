#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 987654322
#define MOD 1000007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, m;
pair<int, int> pos;
int board[600 + 1][600 + 1];
bool visited[600 + 1][600 + 1];

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

void input(){
	cin >> n >> m;
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		for(int j=0;j<s.size();j++){
			if(s[j]=='O') board[i][j] = 0;
			else if(s[j]=='X') board[i][j] = -1;
			else if(s[j]=='I') {
				pos = {i,j};
				visited[i][j] = true;
			}
			else if(s[j]=='P') board[i][j] = 1;
		}
	}
}

bool isValid(int y, int x){
	return (0 <= y && y < n && 0 <= x && x < m);
}

void solution(){
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push(pos);
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for(int i=0;i<4;i++){
			int ny = y + dy[i];
			int nx = x + dx[i];

			if(!isValid(ny, nx) || visited[ny][nx] || board[ny][nx] == -1) continue;
			if(board[ny][nx]) cnt++;
			q.push({ny, nx});
			visited[ny][nx] = true;
		}
	}
	if(!cnt) cout << "TT" << endl;
	else cout << cnt << endl;
}

int main(){
	fastio;	
	input();
	solution();

	return 0;
}