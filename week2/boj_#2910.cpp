#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, c;
vector<int> num;
map<int, pair<int, int>> cache;

typedef struct Info{
	int number;
	int seq;
	int count;
}Info;

struct cmp{
	bool operator()(Info lhs, Info rhs){
		if(lhs.count == rhs.count) return lhs.seq > rhs.seq;
		return lhs.count < rhs.count;
	}
};

void input(){
	int ps = 1;
	cin >> n >> c;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;

		if(cache[x].first == 0){
			cache[x].first = ps++;
			num.push_back(x);
		} 
		cache[x].second++;
	}
}

void solution(){
	priority_queue<Info, vector<Info>, cmp> pq;
	for(auto x : num){
		Info info;
		info.number = x;
		info.seq = cache[x].first;
		info.count = cache[x].second;

		pq.push(info);
	}

	while(!pq.empty()){
		Info topInfo = pq.top();
		pq.pop();

		for(int i=0;i<topInfo.count;i++) {
			cout << topInfo.number << " ";
		}
	}
	cout << '\n';
}

int main(){
	fastio;	
	input();
	solution();
	
	return 0;
}