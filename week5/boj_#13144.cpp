#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, e;
vector<int> ps;
int cnt[100000 + 1];

void input(){
	cin >> n;
	ps = vector<int>(n,0);
	for(int i=0;i<n;i++){
		cin >> ps[i];
	}
}

ll solution(){
	ll answer = 0;
	for(int s=0;s<n;s++){
		while(e < n){
			if(cnt[ps[e]]) break;
			cnt[ps[e++]]++;
		}
		answer += (e - s);
		cnt[ps[s]]--;
	}
	
	return answer;
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;

	return 0;
}