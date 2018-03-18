/*
 
陸行鳥大賽車
  */
#include<cstdio>
using namespace std;
const int maxn=100000+10;
struct Node
{
	int data;
	Node *next,*prev;
};
Node l[maxn];
Node *head;
void out(int num)
{
	Node *tmp = &l[num];
	if(tmp->next==NULL)
	{
		tmp->prev->next=NULL;
		tmp->prev=NULL;
	}
	else
	{
		tmp->next->prev = tmp->prev;
		tmp->prev->next = tmp->next;
		tmp->next = NULL;
		tmp->prev = NULL;
	}
}
void exceed(int num)
{
	Node *tmp = &l[num];
	if(tmp->prev==head)return;
	Node *front = tmp->prev->prev;
	Node *pre = tmp->prev;
	Node *nex = tmp->next;
	front->next = tmp;
	if(tmp->next==NULL)
	{
		tmp->prev=front;
		tmp->next=pre;
		front->next=tmp;
		pre->prev=tmp;
		pre->next=NULL;
	}
	else
	{
		tmp->prev = front;
		tmp->next = pre;
		pre->prev = tmp;
		pre->next = nex;
		nex->prev = pre;
	}
}
int main()
{
	int N,M,a,b;
	while(scanf("%d %d",&N,&M))
	{
		head = new Node;
		Node *ptr = head;
		for(int i=1;i<=N;i++)
		{
			Node *tmp = &l[i];
			tmp->data = i;
			tmp->prev = ptr;
			ptr->next = tmp;
			ptr = tmp;// previous
		}  
		l[N].next=NULL;
		for(int i=0;i<M;i++)
		{
			scanf("%d %d",&a,&b);
			if(a==0)out(b);
			if(a==1)exceed(b);
		}
		Node *print = head->next;
		if(print!=NULL)
		{
			printf("%d",print->data);
			for(;;)
			{
				if(print->next==NULL)break;
				print = print->next;
				printf(" %d",print->data);
			}
			printf("\n");
		}
	}
	return 0;
}
