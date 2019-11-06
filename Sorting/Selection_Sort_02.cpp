#include<iostream>
#define max 25
using namespace std;


class SelectionSort
{

	int n, A[max], temp, i, j, t, m;

	public:
		SelectionSort()
		{
			n = 0;
			m = 0;
			t = 0;
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
			for(i=0; i<n-1; i++)
			{
				m = A[i];
				t = i;
				for(j=i+1; j<n; j++)
				{
					if(m>A[j])
					{
						m = A[j];
						t = j;
					}
				}

				cout<<"Pass = ";
				display();
				cout<<endl;
				temp = A[i];
				A[i] = A[t];
				A[t] = temp;
			}
			
		}
};

int main()
{

SelectionSort ss;
ss.getdata();
ss.display();
ss.sort();
ss.display();

return 0;
}
