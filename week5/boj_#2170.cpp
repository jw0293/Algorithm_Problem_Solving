#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// https://www.acmicpc.net/problem/2170

int n;
vector<pair<int,int>> info;

bool cmp(pair<int, int> &lhs, pair<int, int> &rhs){
	if(lhs.first == rhs.first) return lhs.second > rhs.second;
	return lhs.first < rhs.first;
}

void input(){
	cin >> n;
	for(int i = 0; i < n; i++){
		int from, to;
		cin >> from >> to;

		info.push_back({from, to});
	}
}

int solution(){
	sort(info.begin(), info.end(), cmp);

	int pl = info[0].first, pr = info[0].second;
	int ret = pr - pl, tot = 0;

	for(int i=1;i<info.size();i++){
		pair<int, int> cur = info[i];
		if(pl <= cur.first && cur.first <= pr && cur.second <= pr) continue;
		if(pr < cur.first){
			tot += ret;

			pl = cur.first;
			pr = cur.second;
		} else{
			pr = max(pr, cur.second);
		}

		ret = pr - pl;
	}
	return tot + ret;
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;

	return 0;
}