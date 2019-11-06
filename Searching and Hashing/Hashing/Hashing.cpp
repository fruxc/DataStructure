#include<iostream>
#define max 1000000
using namespace std;

class Hashing
{
	public:
	long int A[max], n, count;
	Hashing()
	{
		n = 0;
		count = 0;
	}

	void getdata()
	{
		cout<<"Enter the number of elements"<<endl;
		cin>>n;
		for(int i=0; i<n; i++)
		{
			A[i]=0;
		}

		// Digit counter for total locations in the array
		int ncount = 0, t = n;
		while(t != 0)
		{
			t = t / 10;
			ncount++;
		}
	}

	void display()
	{
		for(int i=0; i<n; i++)
		{
			cout<<A[i]<<"\t";
		}
		cout<<endl;
	}

	void insert(int key)
	{
		//Digit counter for Key
		int kcount = 0, res = 0, t = 0;
		int l = key * key;
		int tk = l;
		t = l;	
		while(tk != 0)
		{
			tk = tk / 10;
			++kcount;
		}
		int k[kcount];
		
		
		for(int i=kcount-1; i>=0; i--)
		{
			int k = t % 10;
			k[i] = k ;
			t = t / 10;
		}
		
		for(int i = 0; i<kcount; i++)
		{
			cout<<"\t"<<k[i];
		}
		cout<<endl;

		int temp = isEmpty(res);
		if(temp != 100)
		{
			A[temp] = key;
		}
		else
		{
			cout<<"Array is full"<<endl;
		}
	}
	
	int isEmpty(int res)
	{
		
		for (int i = res; i<n; i++)	
		{
			if(A[i] == 0)
			{
				return i;
				break;
			}
			else
			{
				count = n;
			}
		}
		if(count == n)
		{
			for(int i = 0; i<res; i++)
			{
				if(A[i] == 0)
				{
					return i;
					break;
				}
			}
		}
		return 100;
	}

};

int main()

{
int x,i;
Hashing h;
h.getdata();
h.display();
for(;;)
{
	cout<<"Options :- "<<endl;
	cout<<"\n 1. Insert.\n 2. Display \n 9. Exit"<<endl;
	cin>>x;
	if(x == 9)
	{
		cout<<"Bye!!!"<<endl;
		break;
	}
	switch(x)
	{
		case 1:
			cout<<"Enter Element to Insert:"<<endl;
			cin>>i;
			h.insert(i);
			break;
		case 2:
			cout<<"Displaying Array : "<<endl;
			h.display();
			break;
		default:
			cout<<"Invalid Options"<<endl;
			break;
	}
}
return 0;
}
