#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, K, answer;
const int MX = 100000;
int visited[MX + 1];
int path[MX+1];

void input(){
	cin >> N >> K;
}

bool isValid(int pos){
	return (0 <= pos && pos <= MX);
}

vector<int> getPath(){
	answer = visited[K]-1;
	
	vector<int> ret;
	ret.push_back(K);
	while(path[K] != -1){
		ret.push_back(path[K]);
		K = path[K];
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

void output(vector<int> &ret){
	cout << answer << endl;
	for(auto &r : ret) cout << r << " ";
	cout << endl;
}

void solution(){
	queue<int> q;

	q.push(N);
	visited[N] = 1;
	path[N] = -1;
	while(!q.empty()){
		int cur = q.front();
		q.pop();

		if(cur == K) break;

		for(int next : {cur-1, cur+1, cur*2}){
			if(!isValid(next)) continue;
			if(!visited[next]){
				q.push(next);
				path[next] = cur;
				visited[next] = visited[cur] + 1;
			}
		}
	}
	vector<int> ret = getPath();
	output(ret);
}

int main(){
	fastio;	
	input();
	solution();

	return 0;
}