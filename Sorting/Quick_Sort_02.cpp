#include<iostream>
#define max 25
using namespace std;


class QuickSort
{

	int n, A[max], lower, upper, temp, l, u, i;

	public:
		QuickSort()
		{
			n = 0;
			temp = 0;
			l = 0;
			u = 0;
			i = 0;
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
		return n;
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


		void sort(int lower, int upper)
		{
			if ( lower < upper )
			{
				int i = part ( A, lower, upper ) ;
				cout<<"Pass :-";
				display();
				sort ( lower, i - 1 ) ;
				sort ( i + 1, upper ) ;
			}
		}

		int part ( int *a, int lower, int upper )
		{ 
			l = lower + 1 ;
			u = upper ;
			i = a[lower] ;
			while ( u >= l )
			{
				while ( a[l] < i )
				{
					l++ ;
				}
				while ( a[u] > i )
				{
					u-- ;
				}
				if ( u > l )
				{
					temp = a[l] ;
					a[l] = a[u] ;
					a[u] = temp ;
				}
			}
			temp = a[lower] ;
			a[lower] = a[u] ;
			a[u] = temp ;
			return u ;
		}
};

int main()
{

QuickSort qs;
int x = qs.getdata();
qs.display();
qs.sort(0, x-1);
cout<<"Sorted :";
qs.display();

return 0;
}	
