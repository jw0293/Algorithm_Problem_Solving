#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9 + 3
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;


string input(){
	string s;
	cin >> s;
	return s;
}

string solution(string s){
	int i=0;
	while(i < s.size()){
		if(s[i] == 'p' || s[i] == 'k' || s[i] == 'c'){
			if(s[i] == 'p' && i+2 <= s.size()){
				if(s.substr(i, 2) != "pi") return "NO";
				i += 2;
			}
			else if(s[i] == 'k' && i+2 <= s.size()){
				if(s.substr(i, 2) != "ka") return "NO";
				i += 2;
			}
			else if(s[i] =='c' && i+3 <= s.size()){
				if(s.substr(i, 3) != "chu") return "NO";
				i += 3;
			}
			else{
				return "NO";
			}
		} else{
			return "NO";
		}
	}
	return "YES";
}

int main(){
	fastio;	
	cout << solution(input()) << endl;

	return 0;
}