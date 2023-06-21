#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, m, k;
int pl, pr;
vector<int> ps;

void input(){
	cin >> n >> m;
	pl = 1, pr = m;
	
	cin >> k;
	ps = vector<int>(k, 0);
	for(int i=0;i<k;i++){
		cin >> ps[i];
	}
}

int solution(){
	int answer = 0;
	for(auto p : ps){
		if(pl <= p && p <= pr) continue;
		if(p < pl) {
			answer += abs(p - pl);
			pl = p;
			pr = pl + m - 1;
		} else{
			answer += abs(p - pr);
			pr = p;
			pl = pr - m + 1;
		}
	}
	return answer;
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;
	
	return 0;
}