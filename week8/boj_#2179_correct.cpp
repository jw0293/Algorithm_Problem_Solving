#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 987654322
#define MOD 1000007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
string str;
vector<string> strs;

void input(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> str;
		strs.push_back(str);
	}
}

void solution(){
	int ret = -1, len = 0;
	string temp1, temp2;
	for(int i=0;i<strs.size();i++){
		for(int j=0;j<strs.size();j++){
			if(i==j) continue;
			len = 0;
			for(int l=0;l<min(strs[i].size(), strs[j].size());l++){
				if(strs[i][l] != strs[j][l]) break;
				len++;
			}
			if(ret < len){
				ret = len;
				temp1 = strs[i], temp2 = strs[j];
			}
		}
	}
	cout << temp1 << endl << temp2 << endl;
}

int main(){
	fastio;	
	input();
	solution();

	return 0;
}