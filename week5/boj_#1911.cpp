#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

// https://www.acmicpc.net/problem/1931

typedef long long ll;
typedef unsigned long long ull;

int n, l;
vector<pair<int,int>> hole;

bool cmp(pair<int, int> &lhs, pair<int, int> &rhs){
	if(lhs.first == rhs.first) return lhs.second > rhs.second;
	return lhs.first < rhs.first;
}

void input(){
	cin >> n >> l;
	for(int i=0;i<n;i++){
		int start, end;
		cin >> start >> end;
		hole.push_back({start, end});
	}
}

int solution(){
	int cnt = 0, endPoint = 0;
	sort(hole.begin(), hole.end(), cmp);

	int v,m;
	for(auto &p : hole){
		if(p.second <= endPoint) continue;

		if(endPoint <= p.first){
			v = (p.second - p.first) / l;
			m = (p.second - p.first) % l;

			if(!m) {
				cnt += v;
				endPoint = p.first + v * l;
			} else{
				cnt += v+1;
				endPoint = p.first + (v+1) * l;
			}
		} 
		else if(p.first < endPoint){
			v = (p.second - endPoint) / l;
			m = (p.second - endPoint) % l;

			if(!m) {
				cnt += v;
				endPoint += v * l;
			} else{
				cnt += v+1;
				endPoint += (v+1) * l;
			}
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