#include <iostream>
using namespace std;
int n,m;
int e[100][100];
int book[100];
void bfs(int *p,int head,int tail)
{
	while(head < tail && tail <= n)
	{
		int cur = p[head];
		for(int i = 1;i <= n;i++)
		{
			if(e[cur][i] == 1 && book[i] == 0)
			{
				p[tail++] = i;
				book[i] = 1;
			}
			if(tail > n) break;
		}
		head ++;
	}
	for(int i = 0;i < tail;i++)
		cout<<p[i]<<" ";
}
int main()
{
	int que[100],head,tail;
	cout<<"请输入边的个数和点的个数"<<endl;
	cin>>n>>m;
	int a,b;
	cout<<"请输入边的信息"<<endl;
	for(int i = 0;i < m;i++)
	{
		cin>>a>>b;
		e[a][b] = 1;
		e[b][a] = 1;
	}
	head = 0;
	tail = 0;
	que[tail++] = 1;
	book[1] = 1;
	cout<<"遍历的顺序为：";
	bfs(que,head,tail);
	
	cout<<endl;
	return 0;
}