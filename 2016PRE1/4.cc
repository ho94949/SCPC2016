#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
vector<pair<int,long long> > conn[101010];
long long weight[101010];
long long from[101010];
void tmain()
{
	int N, M, K;
	scanf("%d%d%d",&N,&M,&K);
	for(int i=1; i<=N; i++) conn[i].clear();
	memset(weight, -1, sizeof(weight));
	memset(from, -1, sizeof(from));
	for(int i=0; i<M; i++)
	{
		int a,b;
		long long c;
		scanf("%d%d%lld",&a,&b,&c);
		conn[a].push_back(make_pair(b,c));
		conn[b].push_back(make_pair(a,c));
	}
	#define T_ pair<long long int, pair<int, int> >
	priority_queue<T_,vector<T_>,greater<T_> > Q;//-w, dest,src
	
	for(int i=0; i<K; i++)
	{
		int x;
		scanf("%d",&x);
		Q.push(make_pair(-0LL,make_pair(x,x)));
	}
	//puts("ok");
	while(!Q.empty())
	{
		long long int w = Q.top().first;
		int d = Q.top().second.first;
		int s = Q.top().second.second;
		//printf("%d %d %d\n",w,d,s);
		Q.pop();
		if(from[d]!=-1) continue;
		from[d]=s;
		weight[d]=w;
		for(int i=0; i<conn[d].size();i++)
			Q.push(make_pair(w+conn[d][i].second,make_pair(conn[d][i].first, s)));
	}
	long long s1=0,s2=0;
	for(int i=1; i<=N; i++)
	{
		s1+= weight[i];
		s2+= from[i];
	}
	printf("%lld\n%lld\n",s1,s2);
	return;
}
int main()
{
	int T;
	scanf("%d",&T);
	setbuf(stdout, NULL);
	for(int i=1; i<=T; i++)
	{
		printf("Case #%d\n",i);
		tmain();
	}
}