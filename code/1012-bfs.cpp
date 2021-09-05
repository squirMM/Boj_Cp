#include <iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<utility>
#include<queue>
using namespace std;
bool check[51][51];
int ground[51][51];
queue<pair<int,int> >q;
int times,M,N,cnt;
int dx[4] = { 0, 0, 1, -1 };int dy[4] = { 1, -1, 0, 0 };

bool check_range(int y , int x) {
	if (x < 0 || y < 0 || x >= M || y >= N)return false;
	else return true;
}

void bfs(int y , int x){
    q.push(make_pair(y,x));
    while(q.size()){
        pair<int,int> tmp= q.front();
        q.pop();
        if(ground[tmp.first][tmp.second]!=1 || check[tmp.first][tmp.second])continue;
        check[tmp.first][tmp.second]=true;
        for(int i=0 ; i<4 ; i++){
            int nx= tmp.second+dx[i];
            int ny= tmp.first+dy[i];
            if(check_range(ny,nx))q.push(make_pair(ny,nx));
        }
    }
   
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cin >> times;
	int K,x,y;
	while (times--) {
		//초기화
		memset(check, false, sizeof(check));
		memset(ground, 0, sizeof(ground));
		vector<pair<int, int> >v;
		cin >> M >> N >> K;
		while (K--) {
			cin >> x >> y;
			ground[y][x] = 1;
			v.push_back(make_pair(y, x));
		}
		cnt = 0;
		for (int i = 0; i < v.size(); i++) {
			int cx = v[i].second;
			int cy = v[i].first;
			if (ground[cy][cx] == 1 && !check[cy][cx]) {
				bfs(cy,cx);
                cnt++;
			}
		}

		cout << cnt << endl;

	}
}
