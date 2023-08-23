#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define MOD 1000007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
int board[100 + 1][100 + 1];
vector<int> dragon[4][11];

const int dy[] = {0, -1, 0, 1};
const int dx[] = {1, 0, -1, 0};

void makeDragon(){
	for(int i=0;i<4;i++){
		dragon[i][0].push_back(i);
		dragon[i][1].push_back((i+1)%4);
		for(int j=2;j<=10;j++){
			int n = dragon[i][j-1].size();
			for(int k=n-1;k>=0;k--){
				dragon[i][j].push_back((dragon[i][j-1][k]+1)%4);
			}

			for(int k=0;k<n;k++){
				dragon[i][j].push_back(dragon[i][j-1][k]);
			}
		}
	}
}

void go(int x, int y, int d, int g){
	board[x][y] = 1;
	for(int i=0;i<=g;i++){
		for(int dir : dragon[d][i]){
			x += dx[dir];
			y += dy[dir];
			board[x][y] = 1;
		}
	}
}

void input(){
	cin >> n;
	makeDragon();
	for(int i=0;i<n;i++){
		int x, y, dir, deg;
		cin >> x >> y >> dir >> deg;
		go(x, y, dir, deg);
	}
}

bool isValid(int y, int x){
	return (0 <= y && y <= 100 && 0 <= x && x <= 100 && (y+1) <= 100 && (x+1) <= 100);
}

int solution(){
	int ret = 0;
	for(int i=0;i<=100;i++){
		for(int j=0;j<=100;j++){
			if(!isValid(i, j)) continue;
			if(board[i][j] == 1 && board[i+1][j] == 1 && board[i][j+1] == 1 && board[i+1][j+1] == 1){
				ret++;
			}
		}
	}
	return ret;
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;

	return 0;
}