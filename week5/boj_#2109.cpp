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

void input(){
	cin >> n;
	for(int i=0;i<n;i++){
		int p, d;
		cin >> p >> d;
		infos.push_back({d, p});
	}
}

int solution(){
	int answer = 0;
	sort(infos.begin(), infos.end());
	for(auto &cur : infos){
		pq.push(cur.second);
		if(pq.size() > cur.first) pq.pop();
	}

	while(!pq.empty()){
		answer += pq.top();
		pq.pop();
	}
	
	return answer;
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;
	return 0;
}