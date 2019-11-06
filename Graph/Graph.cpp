#include<iostream>
using namespace std;
#define max 100

class Graph{
	public:
	int a[max][max],i,n,k ;
	char c[max],st[max],visited[max],ele;
	int top;
	
	Graph()
	{
		top = -1;
	}
	
	int isEmpty(char x)
	{
		for(int i=0; i<n; i++)
		{
			if(st[i] == x)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	
	void DFS()
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j<n; j++)
			if(a[i][j] == 1 && isEmpty(c[i]) == 0)
			{
				push(c[i]);
			}
		}
		cout<<endl<<"A";
		for(int i = 0; i<n; i++)
		{
			cout<<"\t"<<visited[i];
		}
	}
	
	void getdata()
	{
		cout<<"Enter the number of vertices :-\n";
		cin>>n;
		cout<<"Enter each alphabets/digits :-\n";
		c[n],visited[n];
		for(int i = 0; i < n; i++)
		{
			cin>>c[i];
		}
		a[n][n];
		for(int i = 0; i < n; i++)
		{
			visited[i] = '\0';
			for(int j = 0; j < n; j++)
			{
				a[i][j] = 0;
			}
		}
	}
	
	void matrixdata()
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(i==j)
				{
					continue;
				}
				else
				{
					cout<<"Enter matrix data for "<<c[i]<<" x "<<c[j]<<" :-";
					cin>>a[i][j];
				}
			}
		}
	}
	
	void display()
	{
		cout<<"--------------------Adjacency Matrix--------------------"<<endl;
		for(int i=0; i<n; i++)
		{
			cout<<"\t"<<c[i];
		}
		cout<<endl;
		for(int i = 0; i < n; i++)
		{
			cout<<c[i]<<"\t";
			for(int j = 0; j < n; j++)
			{
				cout<<a[i][j]<<"\t";
			}
			cout<<"\n";
		}
	}
	
	
	
	
	void push(char x){
					ele=x;
					
					if(top>n-1)
					{
						cout<<"Overflow condition ";
						
					}
					
					else
					{
						top++;
						k=0;
						st[top] = visited[i] = ele;
						cout<<"Element "<<ele<<" inserted at:"<<top;
						k++;
					}
					cout<<endl; 
				}
		
	int pop(){
					if (top==-1)
					{
						cout<<"Underflow condition";				
					}
	
					else
					{
						cout<<"The popped element is"<<st[top]<<endl;
						top--;
					}
			}
};


int main()
{
	int ch;
	Graph g;
	while(ch!=5)
		{
		
			cout<<"Enter the options \n1.Set Nodes \n2.Set Matrix Data \n3.Display \n4.DFS \n5.Exit "<<endl;
			cout<<"Enter your choice";
			cin>>ch;
		
			switch(ch)
			{
				case 1: g.getdata();
						break;
				case 2: g.matrixdata();
						break;
				case 3: g.display();
						break;
				case 4: g.DFS();
						break;
				case 5: exit(0);
						break;
				default : cout<<"Invalid choice"<<endl;
				
			}
		
		}
		return 0;
}

