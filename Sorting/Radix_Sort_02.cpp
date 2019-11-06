#include<iostream>
#include<cmath>
#define m 25
using namespace std;

class Radix
{
 public:
	int n, A[m], max, x;

	Radix()
	{
		n=0; max=0; x=0;
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

	int getMax(int A[], int n)
	{
		int temp=A[0];
		for(int i=0; i<n; i++)
		{
			if(A[i]>temp)
			{
				temp = A[i];
			}
		}
		return temp;
	}

	void countsort(int A[], int n,int x)
	{
		int count[10]={0}, i, output[n];

		// Counter Initialized
		// Exponential Game
		for(i=0; i<n; i++)
		{
			count[(A[i]/x)%10]++;
		}

		//Total Count
		for(i=1; i<10; i++)
		{
			count[i]=count[i]+count[i-1];
		}
		
		//Building Output Array
		for(i=n-1; i>=0; i--)
		{
			output[count[(A[i]/x)%10]-1] = A[i];
			count[(A[i]/x)%10]--;
		}
		// Copying the elements
		for(i=0; i<n; i++)
		{
			A[i] = output[i];
		}

	}

	void sort()
	{
		max=getMax(A, n);
		for(x=1; max/x>0; x=x*10)
		{
			cout<<"Pass = ";
			display();
			countsort(A, n, x);
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
};

int main()
{
	Radix r;
	r.getdata();
	r.display();
	r.sort();
	cout<<"Sorted Elements: \n";
	r.display();
	return 0;
}

