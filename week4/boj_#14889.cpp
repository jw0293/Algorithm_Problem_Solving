#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

// https://www.acmicpc.net/problem/14889

typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 20 + 1;

int n;
bool visited[MAXN];
int board[MAXN][MAXN];

void input(){
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> board[i][j];
		}
	}
}

int getScore(vector<int> &ps1, vector<int> &ps2){
	int score1 = 0, score2 = 0;
	for(int i=0;i<ps1.size();i++){
		for(int j=0;j<ps1.size();j++){
			if(i==j) continue;
			score1 += board[ps1[i]][ps1[j]];
		}
	}
	for(int i=0;i<ps2.size();i++){
		for(int j=0;j<ps2.size();j++){
			if(i==j) continue;
			score2 += board[ps2[i]][ps2[j]];
		}
	}
	return abs(score1-score2);
}

int solution(){
	int answer = INF;
	for(int i = 0;i < (1 << n);i++){
		if(__builtin_popcount(i) != n / 2) continue;
		vector<int> start, link;
		for(int j=0;j<n;j++){
			if(i & (1 << j)) start.push_back(j);
			else link.push_back(j);
		}
		answer = min(answer, getScore(start, link));
	}

	return answer;
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;

	return 0;
}