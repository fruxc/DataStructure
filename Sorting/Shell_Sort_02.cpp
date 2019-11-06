#include<iostream>
#include<cmath>
#define max 25
using namespace std;


class ShellSort
{

	int n, A[max], temp, i, j;

	public:
		ShellSort()
		{
			n = 0;
			i = 0;
			j = 0;
			temp = 0;
		}

		void getdata()
		{
			cout<<"Enter the size of the Array"<<endl;
			cin>>n;
			A[n];
			cout<<"Enter the values of the Array"<<endl;
			for(int i=0; i<n; i++)
			{
				cin>>A[i];
			}
		}

		void display()
		{
			cout<<endl;
			for(int i=0; i<n; i++)
			{
				cout<<A[i]<<"\t";
			}
			cout<<endl;
		}

		void sort()
		{
			for(i=ceil(n/2); i>0; i=ceil(i/2))
			{
				cout<<"Pass :-";
				display();
				for(j=i; j<n; j++)
				{
					for(int k=j-i; k >= 0; k = k-i)
					{
						if(A[k+i] <= A[k] )
						{
							temp = A[k];
							A[k] = A[k+i];
							A[k+i] = temp;
						}
						else
						{	break; }
					}
				}
			}
				
		}
};

int main()
{

ShellSort ss;
ss.getdata();
ss.display();
ss.sort();
ss.display();

return 0;
}
