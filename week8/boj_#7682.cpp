#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 987654322
#define MOD 1000007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

string str;
int board[4][4];
int x_cnt, o_cnt;

const int dy[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dx[] = {0, -1, 0, 1, -1, 1, -1, 1};

void makeBoard(){
	x_cnt = 0, o_cnt = 0;
	for(int i=0;i<str.size();i++){
		if(str[i]=='X') {
			x_cnt++;
			board[(i/3)+1][(i%3)+1] = 0;
		}
		else if(str[i]=='O'){
			o_cnt++;
			board[(i/3)+1][(i%3)+1] = 1;
		} else{
			board[(i/3)+1][(i%3)+1] = -1;
		}
	}
}

bool isValid(int y, int x){
	return (1 <= y && y <= 3 && 1 <= x && x <= 3);
}

bool isCanWin(int y, int x, int c){
	for(int d=0;d<8;d++){
		int cnt = 0;
		for(int i=0;i<3;i++){
			int ny = y + dy[d] * i;
			int nx = x + dx[d] * i;
			if(!isValid(ny, nx) || board[ny][nx] != c) break;
			cnt++;
		}
		if(cnt==3) return true;
	}
	return false;
}

bool isWin(int t){
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			if(board[i][j]==t){
				if(isCanWin(i, j, t)) return true;
			}
		}
	}
	return false;
}

void input(){
	while(1){
		cin >> str;
		if(str == "end") break;
		makeBoard();
		bool _x = isWin(0);
		bool _o = isWin(1);

		if((_x && !_o)){
			if(x_cnt == o_cnt+1){
				cout << "valid\n";
				continue;
			}
		}
		if((_o && !_x)){
			if(x_cnt == o_cnt){
				cout << "valid\n";
				continue;
			}
		}
		if((!_o && !_x)){
			if(x_cnt==5 && o_cnt==4) {
				cout << "valid\n";
				continue;
			}
		}

		cout << "invalid\n";
	}
}

int main(){
	fastio;	
	input();

	return 0;
}