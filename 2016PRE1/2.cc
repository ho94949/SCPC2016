#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MOD = 1000000009;
long long dp[98763];
long long dpe[98763][101];
bool mine[98763];
int tmain()
{
	int N, L, K;
	memset(dp, 0, sizeof(dp));
	memset(dpe, 0, sizeof(dpe));
	memset(mine, 0, sizeof(mine));
	scanf("%d%d%d",&N,&K,&L);
	for(int i=0; i<L; i++)
	{
		int t;
		scanf("%d",&t);
		mine[t] = true;
	}
	dp[0]=1;
	dpe[0][0]=1;
	for(int i=1; i<=N; i++)
	{
		if(mine[i]) continue;
		for(int j=max(0,i-K); j<i; j++)
		{
			dp[i] += MOD + dp[j] - dpe[j][i-j];
			dpe[i][i-j] = (MOD + dp[j] - dpe[j][i-j])%MOD;
			dp[i]%=MOD;
		}
	}
	return dp[N];
}
int main()
{
	int T;
	scanf("%d",&T);
	setbuf(stdout, NULL);
	for(int i=1; i<=T; i++)
	{
		printf("Case #%d\n",i);
		printf("%d\n",tmain());
	}
}