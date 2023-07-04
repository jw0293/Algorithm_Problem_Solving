#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, answer = INF;
int cost[10 + 1];
bool chk[10 + 1];
bool visited[10 + 1];
int adj[10 + 1][10 + 1];

void link(){
	for(int i=1;i<=N;i++){
		int cnt;
		cin >> cnt;
		for(int j=0;j<cnt;j++){
			int link;
			cin >> link;

			adj[i][link] = 1;
			adj[link][i] = 1;
		}
	}
}

void input(){
	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> cost[i];
	}
	link();
}

void bfs(queue<int> &q, bool flag){
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		chk[cur] = true;

		for(int i=1;i<=N;i++){
			if(adj[cur][i]){
				if(visited[i] == flag && !chk[i]){
					chk[i] = true;
					q.push(i);
				}
			}
		}
	}
}

bool isValid(){
	queue<int> q1, q2;
	bool first = false, second = false;
	memset(chk, false, sizeof(chk));

	for(int i=1;i<=N;i++){
		if(!first && !visited[i]){
			first = true;
			q1.push(i);
		}
		if(!second && visited[i]){
			second = true;
			q2.push(i);
		}
		if(first && second) break;
	}

	bfs(q1, visited[q1.front()]);
	bfs(q2, visited[q2.front()]);
	
	for(int i=1;i<=N;i++){
		if(!chk[i]) return false;
	}
	return true;
}

int getCost(){
	int tot1 = 0, tot2 = 0;
	for(int i=1;i<=N;i++){
		if(visited[i]) tot1 += cost[i];
		if(!visited[i]) tot2 += cost[i];
	}
	return abs(tot1 - tot2);
}

void solution(int index, int cur, int cnt){
	if(cur == cnt){
		if(isValid()) answer = min(answer, getCost());
		return;
	}
	
	for(int i=index;i<=N;i++){
		if(!visited[i]){
			visited[i] = true;

			solution(i+1, cur+1, cnt);

			visited[i] = false;
		}
	}
}

int main(){
	fastio;	
	input();
	for(int i=1;i<N;i++) {
		solution(1, 0, i);
	}
	if(answer == INF) answer = -1;
	cout << answer << endl;

	return 0;
}