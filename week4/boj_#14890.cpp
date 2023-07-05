#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, L, answer;
const int MX = 100 + 1;
int board[MX][MX], temp[MX][MX];

void input(){
	cin >> N >> L;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin >> board[i][j];
		}
	}

	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			temp[i][j] = board[j][i];
		}
	}
}

int solution(int a[MX][MX]){
	int ret = 0;
	for(int i=1;i<=N;i++){
		int j;
		int cnt = 1;
		for(j=1;j<=N-1;j++){
			if(a[i][j] == a[i][j+1]) cnt++;
			else if(a[i][j] + 1 == a[i][j+1] && cnt >= L) cnt = 1;
			else if(a[i][j] - 1 == a[i][j+1] && cnt >= 0) cnt = -L + 1;
			else break;
		}

		if(j == N && cnt >= 0) ret++;
	}
	return ret;
}

int main(){
	fastio;	
	input();
	answer += solution(board);
	answer += solution(temp);
	cout << answer << endl;

	return 0;
}