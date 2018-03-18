/*
   丟過去丟回來一定可以
   */
/*更不能輸給暴風雨*/

#include<cstdio>
#include<stack>
using namespace std;
stack<int>s1,s2;
void solve(int N,int order[])
{
	for(int i=1;i<=N;i++)
	{
		push_train();
		s1.push(i);
	}
	for(int i=0;i<N;i++)
	{
		for(;;)
		{
		//	printf("? %d \n",i);
			if(s1.empty()) break;
			if(!s2.empty())
				if(order[i]==s2.top())
				{
						pop_train();
		//			printf("a %d\n",i);
					s2.pop();
				}
			if(s1.empty()) break;
			move_station_1_to_2();
			s2.push(s1.top());
			s1.pop();
		}
		for(;;)
		{
		//	printf("! %d \n",i);
			if(s2.empty()) break;
			if(!s2.empty())
				if(order[i]==s2.top())
				{
		//			printf("a %d\n",i);
						pop_train();
					s2.pop();
				}
			if(s2.empty()) break;
			move_station_2_to_1();
			s1.push(s2.top());
			s2.pop();
		}
	}
}
/*
int main()
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		int a[5005];
		for(int i=0;i<N;i++)
			scanf("%d",&a[i]);
		solve(N,a);
	}
	return 0;
}
*/


