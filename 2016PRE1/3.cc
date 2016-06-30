#include<cstdio>
#include<vector>
using namespace std;
int deg[1010];
int nodeg[1010];
bool on[1010];
bool chan[1010];
vector<int> conn[1010];
int tmain()
{
	int K, L, N, M;
	scanf("%d%d%d%d",&K,&L,&N,&M);
	for(int i=1; i<=N; i++)
	{
		deg[i]=0;
		nodeg[i]=N-1;
		conn[i].clear();
		on[i]=true;
	}
	for(int i=0;i<M;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		conn[a].push_back(b);
		conn[b].push_back(a);
		deg[a]++;
		deg[b]++;
		nodeg[a]--;
		nodeg[b]--;
	}
	bool change=true;
	int ans=0;
	while(change)
	{
		change = false;
		for(int i=1; i<=N; i++)
		{
			if(!on[i]) continue;
			if(deg[i]<K || nodeg[i]<L)
			{
			//	printf("%d %d %d\n",i,deg[i],nodeg[i]);
				for(int ii=1; ii<=N; ii++) chan[ii]=false;
				change=true;
				ans+=i;
				on[i]=false;
				for(int j=0; j<conn[i].size();j++)
				{
					chan[conn[i][j]]=true;
					deg[conn[i][j]]--;
				}
				for(int j=1; j<=N; j++)
					if(!chan[j]) nodeg[j]--;
			}				
		}
	}
	return ans;
}
int main()
{
	int T;
	setbuf(stdout, NULL);
	scanf("%d",&T);
	for(int i=1; i<=T; i++)
		printf("Case #%d\n%d\n",i,tmain());
}