
#include<iostream>
#define max 100
using namespace std;
class Johnson{
	int a[max],b[max],n,front1,rear1,front2,rear2,S[max],temp1,temp2,data,i,J[max],min1,min2; 
	bool flag;
	
	public:
 Johnson(){
		front1 = 0;
		rear1= -1;
		front2 = n-1;
		rear2 = n;
		flag = 0;
	}
void getdata(){
		cout<<"Enter the no of jobs:";
		cin>>n;
		for(i=0;i<n;i++){
			cout<<"Enter job no:";
			cin>>J[i];
			cout<<"Enter the processing time on first machine:";
			cin>>a[i];
			cout<<"Enter the processing time on second machine:";
			cin>>b[i];
		}
		
	}
	
void l_enqueue(int data){
	
	if(rear1==rear2-1)
			{
				cout<<" Queue is Overflow";
			}
			else
			{
				rear1++;
			//	cout<<"Enter element : "<<endl;
			//	cin>>n;
				S[rear1]=data;
				cout<<S[rear1];
	
			}
}

void l_dequeue(int data){
	
		if(front1>rear1)
			{
				cout<<"Queue is  Underflow";
			}
			else
			{
				
				//cout<<"Deleted element is :"<<S[front1++]<<endl;
				front1--;
			}
}

void r_enqueue(int data){
		if(rear1==rear2-1)
			{
				cout<<" Queue is Overflow";
			}
			else
			{
				rear2--;
			//	cout<<"Enter element : "<<endl;
			//	cin>>n;
				S[rear2]=data;
	
			}

}

void r_dequeue(int data){
	
	if(front2<rear2)
			{
				cout<<" Queue is Underflow";
			}
			else
			{
			//	cout<<"Deleted element is :"<<S[front2--]<<endl;
			front2--;
			}
}
	void Johnson_algo(){
		for (i=0;i<n;i++)
		{
			min1=a[0];
			if(a[i]< min1)//a[i+1])
			{
				min1=a[i];
			}
			cout<<endl<<"temp1"<<min1;
		/*	min=ma[0][0];
   		for (i=0; i<n; i++)
    	{
			for (j=0; j<n1; j++)
        	{   
        	if(ma[i][j]<min)
        	min= ma[i][j];
        }
          }*/
			min2=b[0];
			if(b[i]<min2)
				{
					min2 = b[i];
				}
			cout<<"temp2"<<min2;
				cal();
	}
}
	void cal()
	{
	for(i=0;i<n;i++)
	{
	
		//	if (a[temp1]<b[temp2])
			if(min1 < min2)
			{
				flag = 1;
			}
			else if(min1 > min2)
			{
				flag = 0;
			}
			
			if (flag == 1)
			{
				l_enqueue( min1);
			//	r_enqueue (min2);
			}
			else if(flag==0)
			{
			//	l_enqueue( min1);
				r_enqueue (min2);
			}
			//display();
		}
		display();
}
	
void display(){
		cout<<"Jobs\t"<<"a(i)\t"<<"b(i)\t"<<endl;
		for(i=0;i<n;i++)
		{
			cout<<J[i]<<"\t"<<a[i]<<"\t"<<b[i]<<"\t";
			cout<<endl;
		}
	/*	cout<<"Scheduled time:"<<endl;
	if(rear1<front1 && rear2<front2)
	{
		cout<<"\nUnderflow!";
	}
	else
	{
		int i;
		for(i=front1;i<=front2;i++)
		{
			cout<<S[i]<<" "<<endl;
		}
	}*/
	cout<<endl<<"Queue is :"<<endl;
			for(i=front1;i<=rear1;i++)
			{
				if(front1>rear1)
				{
					cout<<"Queue is empty :"<<endl;
				}
				else
				{
					cout<<S[i]<<" ";
				}
			}
			for(i=rear2;i<=front2;i++)
			{
				if(front2<rear2)
				{
					cout<<"Queue is emepty :"<<endl;
				}
				else
				{
					cout<<S[i]<<" ";
				}
			}
			cout<<endl<<endl;

}
	
};


int main(){
	Johnson j;
	j.getdata();
	j.Johnson_algo();
	j.display();
	
	return 0;
}
