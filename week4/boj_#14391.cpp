#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int MX = 4 + 1;

int N, M;
int board[MX][MX];

void input(){
	cin >> N >> M;
	for(int i=0;i<N;i++){
		string str;
		cin >> str;
		for(int j=0;j<str.size();j++){
			board[i][j] = str[j]-'0';
		}
	}
}

int solution(){
	int sum = 0, v;
	int answer = -1;

	for(int s=0;s<(1 << (N * M));s++){
		sum = 0;
		for(int i=0;i<N;i++){
			int cur = 0;
			for(int j=0;j<M;j++){
				v = i * M + j;
				if(!(s & (1 << v))){
					cur = cur * 10 + board[i][j];
				} else{
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}

		for(int i=0;i<M;i++){
			int cur = 0;
			for(int j=0;j<N;j++){
				v = j * M + i;
				if((s & (1 << v)) != 0){
					cur = cur * 10 + board[j][i];
				} else{
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}
		answer = max(answer, sum);
	}
	return answer;
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;

	return 0;
}