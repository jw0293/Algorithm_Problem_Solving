#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, k;
vector<int> info;
bool visited[100 + 1];

void input(){
	cin >> k >> n;
	info = vector<int>(n,0);
	for(int i=0;i<n;i++){
		cin >> info[i];
	}
}

int solution(){
	int ret = 0;
	vector<int> v;
	for(int i=0;i<n;i++){
		if(!visited[info[i]]){
			if(v.size() == k){
				int last_idx = 0, pos;
				for(int nxt : v){
					int nxtIdx = INF;
					for(int j=i+1;j<n;j++){
						if(nxt == info[j]){
							nxtIdx = j;
							break;
						}
					}
					if(last_idx < nxtIdx){
						last_idx = nxtIdx;
						pos = nxt;
					}
				}
				ret++;
				visited[pos] = 0;
				v.erase(find(v.begin(), v.end(), pos));
			}
			v.push_back(info[i]);
			visited[info[i]] = true;
		}
	}
	return ret;
}

int main(){
	fastio;	
	input();
	cout << solution() << endl;

	return 0;
}