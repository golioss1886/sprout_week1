/* 
 大善人老闆救濟東南亞兒童
 */
#include<cstdio>
using namespace std;
const int N=100000+10;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int B[N];
		int station[N];
		int n;
		scanf("%d",&n);			 
		for(int i=0;i<n;i++)
			scanf("%d",&B[i]);
		int A=1,top=0,bptr=0;
		for(int i=0;i<n;i++)
		{
			station[++top]=A++;
		//	printf("i %d top %d \n",i,top);
			while(station[top]==B[bptr]&&top)
			{
			//	printf("%d %d\n",station[top],B[bptr]);
				top--,bptr++;
			//	printf("::top %d \n",top);
			}
		}
		if(!top)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}

