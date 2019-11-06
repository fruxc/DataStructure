#include<iostream>
#include<cmath>
#define max 100

using namespace std;

class hashing
{

	public:
	int a[max],b[max];
	int i,j,k,n,n1,c,m,len,c1,rem,d,s,sum,num,num1,l_num1,rev,digit,p,ans,num3,num2,num4,ch;
	int t;

	void menu()
	{
		ch=0;
		while(ch!=3)
		{

		cout<<endl<<endl;

		cout<<"1.Display"<<endl;

		cout<<"2.Fold Boundary"<<endl;

		cout<<"3.Exit"<<endl;

		cout<<"Enter options "<<endl;

		cin>>ch;
		switch(ch)

		{
			case 1:display();
			break;
			case 2:foldb();
			break;
			default:
				cout<<"invalid choice"<<endl;

		}
		}

	}

	void getdata()
	{
		cout<<"Enter the size of array "<<endl;
		cin>>n;
		cout<<"Enter the element of array "<<endl;
		for(i=0;i<n;i++)
		{
			cin>>a[i];

		}
		cout<<"Enter size of location "<<endl;

		cin>>n1;
		for(i=0;i<n1;i++)
		{
			b[i]=0;
		}
// display();
		menu();
//s foldf();
	}

	void display()
	{
		cout<<"Elements are :"<<endl;
		for(i=0;i<n;i++)
		{
			cout<<a[i]<<" ";
		}
//foldf();
	}

	int length(int l)
	{
		j=0;
		while(c>0)
		{
			c=c/10;
			j++;
		}
	return j;
	}

	int reverse(int r)
	{
		int rem,rev=0;
		while(r>0)
		{
			rem=r%10;
			r=r/10;
			rev=(rev*10)+rem;
		}

		return rev;
	}

	int foldb()
	{
		for(i=0;i<n;i++)
		{
			k=a[i];
			num=k;
			int p=0;
			while(k>0)
			{
				k=k/10;
				p++;
			}

			c=n1-1;

			c1=length(c);

			t=(p/ c1) + ((p % c1)!= 0);

			d=1;

			sum=0;
			while(num>0)
			{

				s=pow(10,c1);
				num1=num %s;

				num2=num1;

				m=0;

				while(num1>0)

				{

					num1=num1/10;

					m++;

				}

				if(m==1)

				{

				sum=sum+(num2*10);

				break;

				}

				if(d==1 || d==t)

				{

				num3=reverse(num2);

				sum=sum+num3;

				}
				else
				{

				sum=sum+num2;

				}

				num=num/pow(10,c1);

				d=d+1;

				}

				if(sum>n1)

				{

					sum=sum%n1;

				}

				while(sum<n1)

				{
					if(b[sum]==0)

					{
						b[sum]=a[i];
						cout<<endl<<a[i]<<"is placed at location "<<sum<<endl;
						break;
					}
					else
					{
						sum++;
					}
					if(sum==n1)
					sum=0;

					}

					}

	}
};

int main()
{

hashing h;
h.getdata();

return 0;

}
