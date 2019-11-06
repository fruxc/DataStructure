#include<iostream>
#include<stdlib.h>
#define max 100
using namespace std;
class hashtechniques
{
	public:
	int n,nl,a1[max],a2[max],i,j,k,ch,res,co,ea,dig,div,pos;
	void getdata()
	{
		cout<<endl<<"Enter array size :";

		cin>>n;
		cout<<endl<<"Enter the Elements :";
		for(i=0;i<n;i++)
		cin>>a1[i];
		cout<<endl<<"Enter Number of location :";
		cin>>nl;
		for(i=0;i<nl;i++)
		a2[i]=0;
		//menu();
		//MidSquare();
	}
	void menu()
	{
		cout<<"\n 1.To perform MIDSQUARE Hashing"<<endl<<"2.Exit";
		cin>>ch;
		switch(ch)
		{
			case 1: getdata();
				midsqr();
				break;
			case 2:cout<<"Bye !!!";
				break;

			default:
				cout<<"\n Enter Proper choice:";
			menu();
		}
	}

	void select()
	{
		cout<<"\n Press 1. to countinue "<<endl<<"press 2.To Exit";
		cin>>res;
		if(res==1)
		{
			menu();
		}
		else
		{
			exit(0);
		}
	}

	void midsqr()
	{
		for(i=0;i<n;i++)
		{
			k=a1[i]*a1[i];
			int num=k;
			int flag=0;
			int div=1;
			int dig=0;
			while(num>0)
			{
				num=num/10;
				dig++;
				div=div*10;
			}
			div=div/100;
			while(flag==0)
			{
				while(k>=0&&k<nl)
				{
					if(a2[k]==0)
					{
						a2[k]=a1[i];
						cout<<endl<<a1[i]<<" is placed at location "<<k;
						flag=1;
						break;
					}
					else
					{
						k=k+1;
					}
				}
				if(flag==0)
				{
					if(k>99)
					{
						k=k/10;
						k=k%div;
						div=div/10;
					}
					else
					{
						k=k%10;
					}
				}

			}

		}
		select();
	}
};


int main()
{
	hashtechniques h;
	h.menu();
	return 0;
}
