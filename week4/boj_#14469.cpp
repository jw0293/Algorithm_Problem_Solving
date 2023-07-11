#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
vector<pair<int, int>> ps;

void input(){
	cin >> n;
	for(int i=0;i<n;i++){
		int arrive, ing;
		cin >> arrive >> ing;

		ps.push_back({arrive, ing});
	}
}

int solution(){
	int start = 0;
	sort(ps.begin(), ps.end());
	for(auto &p : ps){
		if(start <= p.first){
			start = p.first + p.second;
		} else{
			start = start + p.second;
		}
	}
	return start;
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;

	return 0;
}