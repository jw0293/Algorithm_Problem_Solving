#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 987654322
#define MOD 1000007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

int n;
int board[1000 + 1][1000 + 1];

void input(){
	cin >> n;
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		for(int j=0;j<s.size();j++){
			if(s[j] == '_') board[i][j] = 0;
			else board[i][j] = 1;
		}
	}
}

pair<int, int> findCore(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			bool flag = false;
			for(int d=0;d<4;d++){
				int ny = i + dy[d];
				int nx = j + dx[d];

				if(!board[ny][nx]) {
					flag = true;
					break;
				}
			}
			if(!flag) return {i, j};
		}
	}
	return {-1, -1};
}

void solution(){
	pair<int, int> core = findCore();
	int leftArm, rightArm, leftLeg, rightLeg, coreLong;
	for(leftArm=1;;leftArm++){
		if(!board[core.first][core.second-leftArm]) break;
	}
	for(rightArm=1;;rightArm++){
		if(!board[core.first][core.second+rightArm]) break;
	}
	for(coreLong=1;;coreLong++){
		if(!board[core.first+coreLong][core.second]) break;
	}
	int sy = core.first + coreLong;
	for(leftLeg=1;;leftLeg++){
		if(!board[sy+leftLeg][core.second-1]) break;
	}
	for(rightLeg=1;;rightLeg++){
		if(!board[sy+rightLeg][core.second+1]) break;
	}
	cout << core.first+1 << " " << core.second+1 << endl;
	cout << leftArm-1 << " " << rightArm-1 << " " << coreLong-1 << " " << leftLeg << " " << rightLeg << endl;
}

int main(){
	fastio;	
	input();
	solution();

	return 0;
}