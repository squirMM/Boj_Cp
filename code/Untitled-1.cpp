#include <iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
bool check[51][51];
int ground[51][51];
int times,M,N;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

bool check_range(int y , int x) {
	if (x < 0 || y < 0 || x >= M || y >= N)return false;
	else return true;
}

bool dfs(int y, int x) {
	if (check[y][x])return false;
	check[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (check_range(ny, nx)&& ground[ny][nx]==1)dfs(ny, nx);
	}
	return true;
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
			v.push_back(make_pair(x, y));
		}
		int cnt = 0;
		for (int i = 0; i < v.size(); i++) {
			int cx = v[i].first;
			int cy = v[i].second;
			if (ground[cy][cx] == 1 && !check[cy][cx]) {
				if (dfs(cy, cx)) {cnt++; }
			}
		}
		cout << cnt << endl;

	}
}
