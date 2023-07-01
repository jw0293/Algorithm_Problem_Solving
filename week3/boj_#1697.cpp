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

void input(){
	cin >> N >> K;
}

int solution(){
	queue<int> q;
	fill(visited, visited+100000+1, INF);
	q.push(N);
	visited[N] = 1;

	while(!q.empty()){
		int cur = q.front();
		q.pop();

		if(cur == K) return visited[K] - 1;

		if(cur+1 <= MX && visited[cur] + 1 < visited[cur + 1]){
			visited[cur+1] = visited[cur] + 1;
			q.push(cur+1);
		}
		if(visited[cur] + 1 < visited[cur - 1]){
			visited[cur-1] = visited[cur] + 1;
			q.push(cur-1);
		}
		if(cur * 2 <= MX && visited[cur] + 1 < visited[cur * 2]){
			visited[cur * 2] = visited[cur] + 1;
			q.push(cur * 2);
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