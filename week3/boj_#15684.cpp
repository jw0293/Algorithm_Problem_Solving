#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, M, H, answer = INF;
bool visited[300], isCan;
bool link[30 + 1][10 + 1][10 + 1];
vector<pair<int, int>> unlink, temp;

void input(){
	cin >> N >> M >> H;
	for(int i=0;i<M;i++){
		int a, b;
		cin >> a >> b;
		link[a][b][b+1] = true;
		link[a][b+1][b] = true;
	}
}

void getUnlinkBridge(){
	for(int i=1;i<=H;i++){
		for(int j=1;j<N;j++){
			if(!link[i][j][j+1]){
				unlink.push_back({i, j});
			}
		}
	}
}

void go(int depth, int start, int pos){
	if(depth > H){
		if(start == pos) isCan = true;
		return;
	}

	if(link[depth][pos][pos+1] || link[depth][pos][pos-1]) {
		if(link[depth][pos][pos+1]) go(depth+1, start, pos+1);
		else go(depth+1, start, pos-1);
	} else{
		go(depth+1, start, pos);
	}
}

bool isComplete(){
	for(int i=1;i<=N;i++){
		isCan = false;
		go(1, i, i);
		if(!isCan) return false;
	}
	return true;
}

void getLinkBridge(int cnt, int start, int purpose){
	if(cnt == purpose){
		if(isComplete()) answer = min(answer, purpose);
		return;
	}

	for(int i=start;i<unlink.size();i++){
		if(!visited[i]){
			visited[i] = true;
			link[unlink[i].first][unlink[i].second][unlink[i].second+1] = true;
			link[unlink[i].first][unlink[i].second+1][unlink[i].second] = true;

			getLinkBridge(cnt+1, i+1, purpose);

			visited[i] = false;
			link[unlink[i].first][unlink[i].second][unlink[i].second+1] = false;
			link[unlink[i].first][unlink[i].second+1][unlink[i].second] = false;
		}
	}
}

void solution(){
	if(isComplete()) {
		answer = 0;
		return;
	}

	for(int i=1;i<=3;i++){
		getLinkBridge(0, 0, i);	
	}
	if(answer == INF) answer = -1;
}

int main(){
	fastio;	
	input();
	getUnlinkBridge();
	solution();
	cout << answer << endl;

	return 0;
}