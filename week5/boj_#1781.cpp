#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
vector<pair<int, int>> infos;
priority_queue<int, vector<int>, greater<>> pq;

bool cmp(pair<int, int> &lhs, pair<int, int> &rhs){
	if(lhs.first == rhs.first) return lhs.second > rhs.second;
	return lhs.first < rhs.first;
}

void input(){
	cin >> n;
	for(int i=0;i<n;i++){
		int deadline, cost;
		cin >> deadline >> cost;

		infos.push_back({deadline, cost});
	}
}

int getResult(){
	int ret = 0;
	while(!pq.empty()){
		ret += pq.top();
		pq.pop();
	}
	return ret;
}

int solution(){
	sort(infos.begin(), infos.end(), cmp);
	for(auto &cur : infos){
		pq.push(cur.second);
		if(pq.size() > cur.first) pq.pop();
	}
	return getResult();
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;

	return 0;
}