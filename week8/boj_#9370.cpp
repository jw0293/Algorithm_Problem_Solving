#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 987654322
#define MOD 1000007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, m, t, s, g, h;

int dist[2000 + 1];
vector<int> candi;
vector<pair<int, int>> adj[2000 + 1];

struct cmp{
	bool operator()(pair<int, int> &lhs, pair<int, int> &rhs){
		return lhs.second < rhs.second;
	}
};

void init(){
	candi.clear();
	for(int i=1;i<=n;i++){
		dist[i] = INF;
		adj[i].clear();
	}
}

void initStart(priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> &pq){
	pq.push({s, 0});
	dist[s] = 0;
}


void recordDist(priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> &pq){
	while(!pq.empty()){
		int cur = pq.top().first;
		int d = pq.top().second;
		pq.pop();

		if(dist[cur] != d) continue;
		for(auto &nxt : adj[cur]){
			if(nxt.second + dist[cur] < dist[nxt.first]){
				dist[nxt.first] = nxt.second + dist[cur];
				pq.push({nxt.first, dist[nxt.first]});
			}
		}
	}
}

void solution(){
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	initStart(pq);
	recordDist(pq);
	sort(candi.begin(), candi.end());
	for(auto &chk : candi){
		if(dist[chk] % 2 == 1) cout << chk << " ";
	}
	cout << endl;
}

void input(){
	int testCase;
	cin >> testCase;
	while(testCase--){
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		init();
		for(int i=0;i<m;i++){
			int from, to, cost;
			cin >> from >> to >> cost;

			cost *= 2;
			if((from == g && to == h) || (from == h && to == g)) cost--;

			adj[from].push_back({to, cost});
			adj[to].push_back({from, cost});
		}
		for(int i=0;i<t;i++){
			int x; cin >> x;
			candi.push_back(x);
		}
		solution();
	}
}

int main(){
	fastio;	
	input();

	return 0;
}