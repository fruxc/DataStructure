#include<iostream>
using namespace std;
class DFS{
	public:
		int noofnodes;
		int matrix[100][100];
		int queue[100], front, rear;
		int mark[100];
		void init(){
			int n;
			cout<<"Enter no of node : ";
			cin>>n;
			noofnodes=n;
			front=-1;
			rear=-1;
			push(0);
			for(int i=0;i<noofnodes;i++){
				for(int j=0;j<noofnodes;j++){
					matrix[i][j]=0;
				}
				mark[i]=0;
			}
		}
		void insert(){
			int s, e;
			cin>>s>>e;
			matrix[--s][--e]=1;
			matrix[e][s]=1;
		}
		void push(int s){

		}

		int isMarked(int a){
			for(int i=0;i<noofnodes;i++){
				if(mark[i]==a)
					return 1;
			}
			return 0;			
		}
		void morePath()
		{
			int count=0;
			queue[++front]=0;
			mark[0]=1;
			while(count<noofnodes)
			{
				int node = queue[++rear];
				count++;
				cout<<node+1<<endl;
				for(int i=0;i<noofnodes;i++)
				{
					if(matrix[node][i]==1)
						if(mark[i]==0)
						{
							queue[++front]=i;
							mark[i]=1;
						}
				}
			}
		}
		void display(){
			for(int i=0;i<noofnodes;i++){
				for(int j=0;j<noofnodes;j++){
					cout<<matrix[i][j]<<"\t";
				}
				cout<<endl;
			}
		}

		void menu(){
			int task = 0;
			while(task!=10){
				cout<<"1. Init\n2. Insert\n3. Display\n4. Find a Path\n5. Exit\nEnter choice : ";
				cin>>task;
				switch(task){
					case 1:
						init();
						break;
					case 2:
						insert();
						break;
					case 3:
						display();
						break;
					case 4:
						morePath();
						break;
					case 5:
						task = 10;
						break;
					
				}
			}
		}
};
int main(){
	DFS a;
	a.menu();
	return 0;
}

