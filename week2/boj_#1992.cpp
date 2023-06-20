#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
string answer = "";
char board[64 + 1][64 + 1];

void input(){
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> board[i][j];
		}
	}
}

bool isCheck(int sy, int sx, int ey, int ex){
	char x = board[sy][sx];
	for(int i=sy;i<ey;i++){
		for(int j=sx;j<ex;j++){
			if(board[i][j] != x) return false;
		}
	}
	return true;
}

void func(int startY, int startX, int areaY, int areaX){
	if(isCheck(startY, startX, startY + areaY, startX + areaX)) {
		answer += board[startY][startX];
		return;
	}

	answer += "(";
	func(startY, startX, areaY/2, areaX/2);
	func(startY, startX+areaX/2, areaY/2, areaX/2);
	func(startY+areaY/2, startX, areaY/2, areaX/2);
	func(startY+areaY/2, startX+areaX/2, areaY/2, areaX/2);
	answer += ")";
}

int main(){
	fastio;	
	input();
	func(1, 1, n, n);

	cout << answer << endl;
	
	return 0;
}