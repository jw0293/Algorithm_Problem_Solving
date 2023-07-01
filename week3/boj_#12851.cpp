#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, K;
const int MX = 100000;
int visited[MX + 1];
int cnt[MX+1];

void input(){
	cin >> N >> K;
}

void solution(){
	queue<int> q;
	q.push(N);
	cnt[N] = 1;
	visited[N] = 1;

	while(!q.empty()){
		int cur = q.front();
		q.pop();

		if(cur == K) break;

		for(int next : {cur-1, cur+1, cur*2}){
			if(0 <= next && next <= MX){
				if(!visited[next]){
					q.push(next);
					visited[next] = visited[cur] + 1;
					cnt[next] += cnt[cur];
				} else if(visited[next] == visited[cur] + 1){
					cnt[next] += cnt[cur];
				}
			}
		}
	}
	cout << visited[K]-1 << endl << cnt[K] << endl;
}

int main(){
	fastio;	
	input();
	solution();

	return 0;
}