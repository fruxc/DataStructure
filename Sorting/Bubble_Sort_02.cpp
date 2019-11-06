#include<iostream>
#define max 25
using namespace std;


class bubble
{

	int n, A[max],temp,count;

	public:
		bubble()
		{
			n = 0;
			count = 0;
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
			for(int i=0; i<n-1; i++)
			{
				count = 0;
				for(int j=0; j<n-i-1; j++)
				{
					if(A[j]>A[j+1])
					{
						temp = A[j];
						A[j] = A[j+1];
						A[j+1] = temp;
						count++;
					}
				}
				
				cout<<"Pass = ";
				display();
				if(count == 0)
				{
					break;
				}
			}
		}
};

int main()
{

bubble obj;

obj.getdata();
obj.display();
obj.sort();
cout<<"After sort :- ";obj.display();

return 0;
}
