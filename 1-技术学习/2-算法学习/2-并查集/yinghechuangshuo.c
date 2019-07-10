#include <stdio.h>

int *node;
int *size;
int find(int x)
{
	int q;
	if(node[x] != x)
	{
	   q = find(node[x]);			
	}else
		return x;
	return q;
}

int main()
{
	int c;
	scanf("%d",&c);
	
	node = (int*)malloc(sizeof(int) * c);
	size = (int*)malloc(sizeof(int) * c);
	for(int i = 0;i < c;i++)
	{
		node[i] = i;
		size[i] = 1;
	}
	
	int flatM =1;
	int x,y;
	int p,q;
	do
{	
	scanf("%d",&x);
	scanf("%d",&y);
	p = find(node[x]);
	q = find(node[y]);
	if(q != p && flatM == 1)
	{
		node[p] = q;
		size[q] += size[p];
		printf("size[%d]:%d size[%d]:%d",p,size[p],q,size[q]);
	}
	if(q == p)
	{
		printf("the same list,dis:%d\n",size[x] - size[y]);
	}
}while(x > 0&&y>0);
	return 0;
}
