#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int cnt[1010];
pair<pair<int, int>, int> work[1010];
bool cmp(pair<pair<int, int>,int> a,pair<pair<int, int>,int> b)
{
	return a.first.second-a.second < b.first.second-b.second;
}
bool tmain()
{
	int N, K;
	scanf("%d%d",&N,&K);
	for(int i=0;i<N; i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		work[i].first.first=a;
		work[i].first.second=b;
		work[i].second=c;
	}
	memset(cnt, 0, sizeof(cnt));
	for(int i=0; i<K; i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int j=a; j<b; j++) cnt[j]++;
	}
	for(int time = 0; time < 1000; time++)
	{
		sort(work, work+N, cmp);
		for(int i=0; i<N; i++)
		{
			if(work[i].first.first<=time && time < work[i].first.second && work[i].second > 0 && cnt[time]>0)
			{
				cnt[time]--;
				work[i].second--;
			}
		}
	}
	for(int i=0; i<N; i++)
	{
		if(work[i].second !=0)  return false;
	}
	return true;
}
int main()
{
	int T;
	setbuf(stdout,NULL);
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		printf("Case #%d\n%d\n",i,tmain());
	}
}