#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
int mat[10][10],i,j,k,n,stk[10],top,v,visit[10],visited[10];
 
int main()
{
int m;
cout <<"enterno of vertices";
cin >> n;
cout <<"ente no of edges";
cin >> m;
cout <<"\nEDGES \n";
for(k=1;k<=m;k++)
{
cin >>i>>j;
mat[i][j]=1;
}

cout <<"enter initial vertex";
cin >>v;
cout <<"ORDER OF VISITED VERTICES";
cout << v <<" ";
visited[v]=1;
k=1;
while(k<n)
{
for(j=n;j>=1;j--)
if(mat[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
{
visit[j]=1;
stk[top]=j;
top++;
}
v=stk[--top];
cout<<v << " ";
k++;
visit[v]=0; visited[v]=1;
}
cout<<endl;
cout<<"--------------------Adjacency Matrix--------------------"<<endl;
cout<<endl;
for(int i = 0; i < n; i++)
{
	for(int j = 0; j < n; j++)
	{
		cout<<mat[i][j]<<"\t";
	}
	cout<<"\n";
}
}
