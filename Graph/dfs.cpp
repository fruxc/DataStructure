#include<iostream>
using namespace std;

class Dfs
{
 public:
	int a[100][100], stack[100], top, n, e, e1, e2, op[10];
	
	void menu()
	{
		int ch;
		do
		{
			cout<<"Select a option: \n1.Insert\n2.Display\n3.Exit\n";
			cin>>ch;
			
			switch(ch)
			{
				case 1:
					insert();
					break;
				case 2:
					display();
					break;
				case 3:
					break;
				default:
					cout<<"Invalid Choice. Pls select a new one.\n";
					break;
			}
		}while(ch!=3);
	}
	
	void insert()
	{
		cout<<"Enter total number of nodes: ";
		cin>>n;

		cout<<"Enter number of edges: ";
		cin>>e;
		
		for(int i=0; i<e; i++)
		{
			cout<<"Enter edge: \n";
			cin>>e1>>e2;
			cout<<endl;
			
			a[e1][e2]=1;
			a[e2][e1]=1;
		}

		dispMatrix();
	}


	void display()
	{
		cout<<"\n\n\nPath is: \n";
		for(int i=0; i<n; i++)
			cout<<op[i]<<endl;
	}

	void dispMatrix()
	{
		cout<<"\nAdjacency Matrix is: \n";
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				cout<<a[i][j]<<"\t";
			}
			cout<<endl;
		}
	}

	int ifExists(int d)
	{
		for(int i=0; i<top; i++)
		{
			if(d==stack[i])
				return 0;
		}
		return 1;
	}
};

int main()
{
	Dfs d;
	d.menu();
	
	return 0;
}
