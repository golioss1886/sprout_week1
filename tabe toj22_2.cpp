/*
 ÂfÂc¨T¤ô¶Ç»¡
 */
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1000000+10;
int input[maxn],c[maxn],stack[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N;
		scanf("%d",&N);
		for(int i=1;i<=N;i++)
			scanf("%d",&input[i]);
		long long ans=0;//1 1 1 .... 1 1 10^6  boom
		int ptr=1;
		stack[1]=input[1];
		c[1]=1;
		for(int i=2;i<=N;i++)
		{
			while(input[i]>stack[ptr]&&ptr!=0)
			{
				ans += c[ptr--];
			//	printf("i %d >ans%d\n",i,ans);
			}
			if(stack[ptr]==input[i])
			{
				if(ptr!=1)ans++; // 3 3 3   
				ans += c[ptr];
			//	printf("i %d ==ans%d\n",i,ans);
				c[ptr]++;
			}
			else
			{
				if(ptr!=0)ans++;
			//	printf("i %d ><ans%d\n",i,ans);
				c[++ptr]=1;
				stack[ptr]=input[i];
			}
		}
		printf("%lld\n",ans);
		fill(c,c+maxn,0);
		fill(stack,stack+maxn,0);
	}
	return 0;
}
