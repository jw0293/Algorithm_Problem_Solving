#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 987654322
#define MOD 1000007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int k;
string str;
map<char, int> mp;

int getLenth(int idx, char ch){
	int cnt = 1;
	for(int i=idx+1;i<str.size();i++){
		if(str[i]==ch) cnt++;
		if(cnt==k) return i;
	}
	return -1;
}

pair<int,int> findLength(vector<char> &ch){
	int mv = INF, MV = -INF, st, en;
	for(auto &c : ch){
		for(int i=0;i<str.size();i++){
			if(str[i]==c){
				en = getLenth(i, c);
				if(en==-1) continue;
				mv = min(mv, (en-i+1));
				MV = max(MV, (en-i+1));
			}
		}
	}
	return {mv,MV};
}

void init(){
	mp.clear();
	for(auto &c : str) mp[c]++;
}

vector<char> findChar(){
	vector<char> ch;
	for(auto it : mp){
		if(it.second >= k){
			ch.push_back(it.first);
		}
	}
	return ch;
}

void input(int tc){
	while(tc--){
		cin >> str;
		cin >> k;

		init();
		vector<char> ch = findChar();
		
		if(ch.empty()) {
			cout << -1 << endl;
			continue;
		}
		if(k==1){
			cout << 1 << " " << 1 << endl;
			continue;
		}

		pair<int, int> ans = findLength(ch);
		cout << ans.first << " "  << ans.second << endl;
	}
}

int main(){
	fastio;	
	int testCase;
	cin >> testCase;
	input(testCase);

	return 0;
}