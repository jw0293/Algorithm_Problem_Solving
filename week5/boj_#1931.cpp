#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

// https://www.acmicpc.net/problem/1931

typedef long long ll;
typedef unsigned long long ull;

int n;
vector<pair<int,int>> plan;

bool cmp(pair<int, int> &lhs, pair<int, int> &rhs){
	if(lhs.second == rhs.second) return lhs.first > rhs.first;
	return lhs.second < rhs.second;
}

void input(){
	cin >> n;
	for(int i=0;i<n;i++){
		int from, to;
		cin >> from >> to;
		plan.push_back({from, to});
	}
}

int solution(){
	sort(plan.begin(), plan.end(), cmp);

	int cnt = 0, end = 0;
	for(auto &p : plan){
		if(end <= p.first){
			cnt++;
			end = p.second;
		}
	}
	return cnt;
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;

	return 0;
}