#include<iostream>
#define max 50

using namespace std;
class InsertionSort
{
	int n, i, j, t, A[max];

	public:
		InsertionSort()
		{
			n = 0;
			i = 0;
			j = 0;
			t = 0;
		}

		int getdata()
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
			for(i=0; i<n; i++)
			{
				t = A[i];
				j = i-1;
				while((t<A[j]) && (j>=0))
				{
					A[j+1] = A[j];
					j = j-1;
				}
				A[j+1]=t;
				for(int k=0; k<=i; k++)
				{
					cout<<A[k]<<"\t";
				}
				cout<<endl;
			}
		}

};

int main()
{

InsertionSort is;

is.getdata();
is.display();
is.sort();
is.display();

return 0;
}

