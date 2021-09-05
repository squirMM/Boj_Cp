#include<iostream>
using namespace std;
typedef long long int64;
#define MAX 1001
#define MOD 10007
int64 dp[MAX] = { 0 };
int main() {
    ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	int N;
	cin >> N;
	dp[1] = 1; dp[2] = 3; 
	for (int i = 3; i <= N; i++) {
		dp[i]=(dp[i-2]*2+dp[i-1])%MOD;
	}
	cout << dp[N];
}