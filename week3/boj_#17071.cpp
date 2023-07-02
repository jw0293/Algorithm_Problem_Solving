#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, K, answer;
const int MX = 500000;
int visited[2][MX + 1];

void input(){
	cin >> N >> K;
}

bool isValid(int pos){
	return (0 <= pos && pos <= MX);
}

int getPlusTime(int t){
	return (t * (t+1) / 2);
}

int solution(){
	queue<pair<int, int>> q;

	q.push({N, 0});
	visited[0][N] = 1;

	while(!q.empty()){
		int cur = q.front().first;
		int curTime = q.front().second;
		q.pop();

		if(K + getPlusTime(curTime) > MX) return -1;
		if(visited[curTime % 2][K + getPlusTime(curTime)]) return curTime;

		for(int next : {cur-1, cur+1, cur*2}){
			if(!isValid(next)) continue;
			if(!visited[(curTime+1)%2][next]){
				q.push({next, curTime+1});
				visited[(curTime+1)%2][next] = curTime + 1;
			} 
		}
	}
	return -1;
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;

	return 0;
}