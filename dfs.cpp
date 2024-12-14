#include <iostream>
using namespace std;
int n,m;
int e[10][10],book[10];
int sum;
void dfs(int cur)
{
	cout<<cur;
	cout<<" "; 
	sum++;
	if(sum == n) return;
	for(int i = 1;i <= n;i++)
	{
		if(cur == i) continue;
		if(e[cur][i] == 1 && book[i] == 0)
		{
			book[i] = 1;
			dfs(i);
		}
	}
}
int main()
{
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
	book[1] = 1;
	cout<<"遍历的顺序为：";
	dfs(1);
	cout<<endl;
	return 0;
}
/*
5 5
1 2
1 3
1 5
2 4
3 5

*/