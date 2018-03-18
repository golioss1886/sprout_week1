/*
 ¤¤°ê¤H±Æ¶¤°ÝÃD
 */

#include<cstdio>
#include<iostream>
#include<queue>
#include<list>
#include<cstring>
using namespace std;

const int maxn=1000+10;
int q_fnum[1000000+10];//respective in the team ,find team num
//queue<int>q;//team queue
queue<int>q1[1000+10];
queue<int>border;//?S???š¯
list<int>ls;
int a;
int k=1;
int top;
int tmp;//??X??

void ENQUEUE()
{
	int enq;
	scanf("%d",&enq);
	int num=q_fnum[enq];
	if(num)
	{
		if(q1[num].empty())
		{
			q1[num].push(enq);
			ls.push_back(num);
		}
		else
			q1[num].push(enq);
	}
	else //QQ
	{
		ls.push_back(0);	
		border.push(enq);
	}
}

void DEQUEUE()
{
	top=ls.front();
	if(top!=0)
	{
		if(!ls.empty())
			tmp=ls.front();
		if(!q1[tmp].empty())
		{
			printf("%d\n",q1[tmp].front());
			q1[tmp].pop();
			if(q1[tmp].empty())//!!
				ls.pop_front();
		}
	}
	else //if(!border.empty()&&top==0)
	{
		printf("%d\n",border.front());
		border.pop();
		ls.pop_front();
		tmp=ls.front();
	}
}

int main()
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		printf("Line #%d\n",k++);
		int aa;
		for(int i=1;i<=N;i++)
		{
			scanf("%d",&a);
			for(int j=1;j<=a;j++)
			{
				scanf("%d",&aa);
				q_fnum[aa]=i;
			}
		}
		for(;;)
		{
			char c[10];
			scanf("%s",c);
			if(c[0]=='S')
				break;
			else if(c[0]=='E')
				ENQUEUE();
			else if(c[0]=='D')
				DEQUEUE();
		}

		for(int i=0;i<=1000;i++)
			q1[i]=queue<int>();
		border=queue<int>();
	//	memset(q_fnum,0,sizeof(q_fnum));//!!
			fill(q_fnum,q_fnum+1000000,0);//
		//	fill(in_team,in_team+1000,0);//!!!!!!!!!!!!!!!!
		ls.clear();
	//	tmp=0;
	//	top=0;

	}
	return 0;
}
