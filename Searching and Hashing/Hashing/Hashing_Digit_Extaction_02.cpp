#include<iostream>
#define max 100
using namespace std;

int ncount = 0;
class Hashings
{
	public:
	long int A[max], n, count;
	Hashings()
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
		int res = 0, kcount = 0, te[max], digit = 0, s = 0;
		cout<<"\nEnter the number of the digits you want to extract !\n";
		cin>>digit;

		int ndigit[digit];
		
		for(int i = 0; i<digit; i++)
		{
			cin>>ndigit[i];
		}
		
		int l = key;

		for(int i=0; l>0; i++)
		{
			te[i] = l % 10;
			l = l / 10;
			s++;		
		}
		int kel[s];

		for(int j=s-1, k = 0; j>=0; j--, k++)
		{
			kel[k] = te[j];
		}
		
		int c=1;
		for(int i = 0; i<digit; i++)
		{
			res = res + kel[ndigit[i]-1]*c;
			c=c*10;
		}
		
		res = res % n;

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
	Hashings h;
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
