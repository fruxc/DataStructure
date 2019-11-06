#include<iostream>
using namespace std;

class heapTree{
	int arr[100];
	int length;
public:
	heapTree(int l)
	{
		length=l;
		for(int i=0;i<100;i++) // Initializing all elements to a random initial value
		{
			arr[i]=-2431;
		}
	}
	bool sorted=false;
	int parent;
	int parent_loc=0; // Initial parent location is 0
	int parent_loc_dup=0; /*Creating a parent duplicate node. This is used for setting parent back to original node when
						  *Parents are changed while replacing the elements during insertion*/
	void input()
	{
			for(int i=0;i<length;i++) // Running till all elements are inserted
			{
				if(i==0)
				{
					cout<<"Enter value "; /*If element is first element, then directly take it and move to next iteration
										   *as first element has no parent
										  */
					cin>>arr[i];
					continue;
				}
				if(((2*parent_loc)+1<=length)&&((2*parent_loc+2)<=length) && (arr[(2*parent_loc)+1]!=-2431 && arr[(2*parent_loc)+2]!=-2431))
				{
					/*This if condition is for changing parent.
					*Parents are changed when both the child locations are empty, and child location positions
					*dont exceed the maximum array length
					*/
					parent=arr[i];
					parent_loc++; //new parent location will always be a +1 to the original location, i.e. next location always become parent
					parent_loc_dup++;; //Parent dupe is made to copy parent, as it is a duplicate of parent
					cout<<"Parent = "<<arr[parent_loc]<<endl;
				}
				if((arr[(2*parent_loc)+1])==-2431) //If left child of a parent is empty, then this condition
				{
					cout<<"Enter value ";
					cin>>arr[(2*parent_loc)+1]; //Taking into left child position, the new value
					int x=(2*parent_loc)+1; //X variable stores the position of the child. Will be used later in the following while loop
					while(true)
					{
						cout<<arr[x]<<" (>) "<<arr[parent_loc]<<"parent_loc = "<<parent_loc<<" ? "<<endl;//A debugging statement.
						if(arr[x]>arr[parent_loc]) //If value stored in child node is greater than that of the parent node.
						{
							int temp;
							temp=arr[parent_loc];
							arr[parent_loc]=arr[x]; //Swap the locations of parent and child node.
							arr[x]=temp;
							cout<<"replaced "<<arr[parent_loc]<<" with "<<temp<<endl; //Simple debug statement
							x=parent_loc; /*the new value of x is now the parent location, as the original child value is now on
										   *parent's place and is the one that needs to be compared with the upper parent now
										  */
							if(parent_loc%2!=0) 
							{
								/* Finding the new parent position. New parnet position, in case the previous parent position is 
								*an odd number is parent location-1/2. Since child position is, position=(2i+1), then i=(position-1)/2
								*An odd number always represents left child.
								*/
								parent_loc=(parent_loc-1)/2;
							}
							else
							{
								/* Finding the new parent position. New parnet position, in case the previous parent position is 
								*an even number is parent location-2/2. Since child position is, position=(2i+2), then i=(position-1)/2
								*An even number always represents left child.
								*/
								parent_loc=(parent_loc-2)/2;
							}
							if(parent_loc<0)
							{
								break;
							}
						} //Loop is repeated till the child < parent (max heap)
						else
						{
							break; //loop is broken if parent > child
						}
					}
					parent_loc=parent_loc_dup; //Parent is reset using duplicate variable
				}
				else if((arr[2*(parent_loc)+2])==-2431) //All comments are same as above. This is just a repeated part, but for the right child.
				{
					cout<<"Enter value ";
					cin>>arr[(2*parent_loc)+2];
					int x=(2*parent_loc)+2;
					while(true)
					{
						cout<<arr[x]<<" > "<<arr[parent_loc]<<"parent_loc = "<<parent_loc<<" ? "<<endl;
						if(arr[x]>arr[parent_loc])
						{
							int temp;
							temp=arr[parent_loc];
							arr[parent_loc]=arr[x];
							arr[x]=temp;
							cout<<"replaced "<<arr[parent_loc]<<" with "<<temp<<endl;
							x=parent_loc;
							if(parent_loc%2!=0)
							{
								parent_loc=(parent_loc-1)/2;
							}
							else
							{
								parent_loc=(parent_loc-2)/2;
							}
							if(parent_loc<0)
							{
								break;
							}
						}
						else
						{
							break;
						}
					}
					parent_loc=parent_loc_dup;
				}
			}//end of for loop
			cout<<"After insertion ";
			for(int i=0;i<length;i++) //Just for displaying the final array values after insertion
			{
				cout<<arr[i]<<" ";
			}
			cout<<endl;
			cout<<endl;
	}

	void sort()
	{
		bool sorted=false;
		int arr_dup[length]; /* A duplicate array is taken with same length as our original array. This is taken because this array
							 *serves as input for original array in sorting. As sorting involves same procedure by repeatedly inserting elements
							 *and after insertions are complete, replacing first and last element of array and taken out the last element, the entire
							 *previous code is copied, with only parts that are removed are debug statements. Just additional step is
							 *performed at the end where the first and last positions are swapped and last position is taken out
							 *Also array duplicate is replaced again by the new array at the end.
							 * see this below.
							 */
		for(int i=0;i<length;i++)
		{
			arr_dup[i]=arr[i]; //Initializing duplicate array with inserted array values
		}
		for(int i=0;i<100;i++)
		{
			arr[i]=-2431;//Resetting initial array.
		}
		while(!sorted) //loop is repeated till the sorted flag is set, which is set when length of new array reaches 0.
		{
			parent_loc=0; //parent locations are reset.
			parent_loc_dup=0; //Parent duplicate is reset as well.
			for(int i=0;i<length;i++) // same conditions as above
			{
				if(i==0)
				{
					//cout<<"Enter value "<<arr_dup[i];
					arr[i]=arr_dup[i];
					//cout<<endl;
					continue;
				}
				if(((2*parent_loc)+1<=length)&&((2*parent_loc+2)<=length) && (arr[(2*parent_loc)+1]!=-2431 && arr[(2*parent_loc)+2]!=-2431))
				{
					parent=arr[i];
					parent_loc++;
					parent_loc_dup++;;
					//cout<<"Parent = "<<arr[parent_loc]<<endl;
				}
				if((arr[(2*parent_loc)+1])==-2431)
				{
					//cout<<"Enter value "<<arr_dup[i];
					arr[(2*parent_loc)+1]=arr_dup[i];
					//cout<<endl;
					int x=(2*parent_loc)+1;
					while(true)
					{
						//cout<<arr[x]<<" (>) "<<arr[parent_loc]<<"parent_loc = "<<parent_loc<<" ? "<<endl;
						if(arr[x]>arr[parent_loc])
						{
							int temp;
							temp=arr[parent_loc];
							arr[parent_loc]=arr[x];
							arr[x]=temp;
							//cout<<"replaced "<<arr[parent_loc]<<" with "<<temp<<endl;
							x=parent_loc;
							if(parent_loc%2!=0)
							{
								parent_loc=(parent_loc-1)/2;
							}
							else
							{
								parent_loc=(parent_loc-2)/2;
							}
							if(parent_loc<0)
							{
								break;
							}
						}
						/*if(arr[x]>arr[parent_loc])
						{
							int temp;
							temp=arr[parent_loc];
							arr[parent_loc]=arr[(2*parent_loc)+1];
							arr[(2*parent_loc)+1]=temp;
							cout<<"replaced "<<arr[parent_loc]<<" with "<<temp<<endl;
							x=parent_loc;
							parent_loc=((parent_loc-1)/2);
						}*/
						else
						{
							break;
						}
					}
					parent_loc=parent_loc_dup;
				}
				else if((arr[2*(parent_loc)+2])==-2431)
				{
					//cout<<"Enter value "<<arr_dup[i];
					arr[(2*parent_loc)+2]=arr_dup[i];
					//cout<<endl;
					int x=(2*parent_loc)+2;
					while(true)
					{
						//cout<<arr[x]<<" > "<<arr[parent_loc]<<"parent_loc = "<<parent_loc<<" ? "<<endl;
						if(arr[x]>arr[parent_loc])
						{
							int temp;
							temp=arr[parent_loc];
							arr[parent_loc]=arr[x];
							arr[x]=temp;
							//cout<<"replaced "<<arr[parent_loc]<<" with "<<temp<<endl;
							x=parent_loc;
							if(parent_loc%2!=0)
							{
								parent_loc=(parent_loc-1)/2;
							}
							else
							{
								parent_loc=(parent_loc-2)/2;
							}
							if(parent_loc<0)
							{
								break;
							}
						}
						else
						{
							break;
						}
					}
					parent_loc=parent_loc_dup;
				}
			} //end of for loop
			int temp;
			temp=arr[0];
			arr[0]=arr[length-1]; //Swapping first and last element and then displaying the last element.
			arr[length-1]=temp;
			cout<<arr[length-1]<<" ";
			length--; //REducing length by 1 as the last element is now removed from the array and from further processing.
			for(int i=0;i<length;i++)
			{
				arr_dup[i]=arr[i]; //Duplicate array is now the newly inserted array with one less location. it now again serves as input.
			}
			for(int i=0;i<100;i++)
			{
				arr[i]=-2431; //NEwly inserted array is now reset again.
			}
			if(length==0) //Sorted flag is set and entire loop is now broken once the length reaches 0.
			{
				sorted=true;
			}
		}
	}
	void mininput()
	{
			for(int i=0;i<length;i++) // Running till all elements are inserted
			{
				if(i==0)
				{
					cout<<"Enter value "; /*If element is first element, then directly take it and move to next iteration
										   *as first element has no parent
										  */
					cin>>arr[i];
					continue;
				}
				if(((2*parent_loc)+1<=length)&&((2*parent_loc+2)<=length) && (arr[(2*parent_loc)+1]!=-2431 && arr[(2*parent_loc)+2]!=-2431))
				{
					/*This if condition is for changing parent.
					*Parents are changed when both the child locations are empty, and child location positions
					*dont exceed the maximum array length
					*/
					parent=arr[i];
					parent_loc++; //new parent location will always be a +1 to the original location, i.e. next location always become parent
					parent_loc_dup++;; //Parent dupe is made to copy parent, as it is a duplicate of parent
					cout<<"Parent = "<<arr[parent_loc]<<endl;
				}
				if((arr[(2*parent_loc)+1])==-2431) //If left child of a parent is empty, then this condition
				{
					cout<<"Enter value ";
					cin>>arr[(2*parent_loc)+1]; //Taking into left child position, the new value
					int x=(2*parent_loc)+1; //X variable stores the position of the child. Will be used later in the following while loop
					while(true)
					{
						cout<<arr[x]<<" (>) "<<arr[parent_loc]<<"parent_loc = "<<parent_loc<<" ? "<<endl;//A debugging statement.
						if(arr[x]<arr[parent_loc]) //If value stored in child node is less than that of the parent node.
						{
							int temp;
							temp=arr[parent_loc];
							arr[parent_loc]=arr[x]; //Swap the locations of parent and child node.
							arr[x]=temp;
							cout<<"replaced "<<arr[parent_loc]<<" with "<<temp<<endl; //Simple debug statement
							x=parent_loc; /*the new value of x is now the parent location, as the original child value is now on
										   *parent's place and is the one that needs to be compared with the upper parent now
										  */
							if(parent_loc%2!=0) 
							{
								/* Finding the new parent position. New parnet position, in case the previous parent position is 
								*an odd number is parent location-1/2. Since child position is, position=(2i+1), then i=(position-1)/2
								*An odd number always represents left child.
								*/
								parent_loc=(parent_loc-1)/2;
							}
							else
							{
								/* Finding the new parent position. New parnet position, in case the previous parent position is 
								*an even number is parent location-2/2. Since child position is, position=(2i+2), then i=(position-1)/2
								*An even number always represents left child.
								*/
								parent_loc=(parent_loc-2)/2;
							}
							if(parent_loc<0)
							{
								break;
							}
						} //Loop is repeated till the child < parent (max heap)
						else
						{
							break; //loop is broken if parent > child
						}
					}
					parent_loc=parent_loc_dup; //Parent is reset using duplicate variable
				}
				else if((arr[2*(parent_loc)+2])==-2431) //All comments are same as above. This is just a repeated part, but for the right child.
				{
					cout<<"Enter value ";
					cin>>arr[(2*parent_loc)+2];
					int x=(2*parent_loc)+2;
					while(true)
					{
						cout<<arr[x]<<" > "<<arr[parent_loc]<<"parent_loc = "<<parent_loc<<" ? "<<endl;
						if(arr[x]<arr[parent_loc])
						{
							int temp;
							temp=arr[parent_loc];
							arr[parent_loc]=arr[x];
							arr[x]=temp;
							cout<<"replaced "<<arr[parent_loc]<<" with "<<temp<<endl;
							x=parent_loc;
							if(parent_loc%2!=0)
							{
								parent_loc=(parent_loc-1)/2;
							}
							else
							{
								parent_loc=(parent_loc-2)/2;
							}
							if(parent_loc<0)
							{
								break;
							}
						}
						else
						{
							break;
						}
					}
					parent_loc=parent_loc_dup;
				}
			}//end of for loop
			cout<<"After insertion ";
			for(int i=0;i<length;i++) //Just for displaying the final array values after insertion
			{
				cout<<arr[i]<<" ";
			}
			cout<<endl;
			cout<<endl;
	}

	void minsort()
	{
		bool sorted=false;
		int arr_dup[length]; /* A duplicate array is taken with same length as our original array. This is taken because this array
							 *serves as input for original array in sorting. As sorting involves same procedure by repeatedly inserting elements
							 *and after insertions are complete, replacing first and last element of array and taken out the last element, the entire
							 *previous code is copied, with only parts that are removed are debug statements. Just additional step is
							 *performed at the end where the first and last positions are swapped and last position is taken out
							 *Also array duplicate is replaced again by the new array at the end.
							 * see this below.
							 */
		for(int i=0;i<length;i++)
		{
			arr_dup[i]=arr[i]; //Initializing duplicate array with inserted array values
		}
		for(int i=0;i<100;i++)
		{
			arr[i]=-2431;//Resetting initial array.
		}
		while(!sorted) //loop is repeated till the sorted flag is set, which is set when length of new array reaches 0.
		{
			parent_loc=0; //parent locations are reset.
			parent_loc_dup=0; //Parent duplicate is reset as well.
			for(int i=0;i<length;i++) // same conditions as above
			{
				if(i==0)
				{
					//cout<<"Enter value "<<arr_dup[i];
					arr[i]=arr_dup[i];
					//cout<<endl;
					continue;
				}
				if(((2*parent_loc)+1<=length)&&((2*parent_loc+2)<=length) && (arr[(2*parent_loc)+1]!=-2431 && arr[(2*parent_loc)+2]!=-2431))
				{
					parent=arr[i];
					parent_loc++;
					parent_loc_dup++;;
					//cout<<"Parent = "<<arr[parent_loc]<<endl;
				}
				if((arr[(2*parent_loc)+1])==-2431)
				{
					//cout<<"Enter value "<<arr_dup[i];
					arr[(2*parent_loc)+1]=arr_dup[i];
					//cout<<endl;
					int x=(2*parent_loc)+1;
					while(true)
					{
						//cout<<arr[x]<<" (>) "<<arr[parent_loc]<<"parent_loc = "<<parent_loc<<" ? "<<endl;
						if(arr[x]<arr[parent_loc])
						{
							int temp;
							temp=arr[parent_loc];
							arr[parent_loc]=arr[x];
							arr[x]=temp;
							//cout<<"replaced "<<arr[parent_loc]<<" with "<<temp<<endl;
							x=parent_loc;
							if(parent_loc%2!=0)
							{
								parent_loc=(parent_loc-1)/2;
							}
							else
							{
								parent_loc=(parent_loc-2)/2;
							}
							if(parent_loc<0)
							{
								break;
							}
						}
						/*if(arr[x]>arr[parent_loc])
						{
							int temp;
							temp=arr[parent_loc];
							arr[parent_loc]=arr[(2*parent_loc)+1];
							arr[(2*parent_loc)+1]=temp;
							cout<<"replaced "<<arr[parent_loc]<<" with "<<temp<<endl;
							x=parent_loc;
							parent_loc=((parent_loc-1)/2);
						}*/
						else
						{
							break;
						}
					}
					parent_loc=parent_loc_dup;
				}
				else if((arr[2*(parent_loc)+2])==-2431)
				{
					//cout<<"Enter value "<<arr_dup[i];
					arr[(2*parent_loc)+2]=arr_dup[i];
					//cout<<endl;
					int x=(2*parent_loc)+2;
					while(true)
					{
						//cout<<arr[x]<<" > "<<arr[parent_loc]<<"parent_loc = "<<parent_loc<<" ? "<<endl;
						if(arr[x]<arr[parent_loc])
						{
							int temp;
							temp=arr[parent_loc];
							arr[parent_loc]=arr[x];
							arr[x]=temp;
							//cout<<"replaced "<<arr[parent_loc]<<" with "<<temp<<endl;
							x=parent_loc;
							if(parent_loc%2!=0)
							{
								parent_loc=(parent_loc-1)/2;
							}
							else
							{
								parent_loc=(parent_loc-2)/2;
							}
							if(parent_loc<0)
							{
								break;
							}
						}
						else
						{
							break;
						}
					}
					parent_loc=parent_loc_dup;
				}
			} //end of for loop
			int temp;
			temp=arr[0];
			arr[0]=arr[length-1]; //Swapping first and last element and then displaying the last element.
			arr[length-1]=temp;
			cout<<arr[length-1]<<" ";
			length--; //REducing length by 1 as the last element is now removed from the array and from further processing.
			for(int i=0;i<length;i++)
			{
				arr_dup[i]=arr[i]; //Duplicate array is now the newly inserted array with one less location. it now again serves as input.
			}
			for(int i=0;i<100;i++)
			{
				arr[i]=-2431; //NEwly inserted array is now reset again.
			}
			if(length==0) //Sorted flag is set and entire loop is now broken once the length reaches 0.
			{
				sorted=true;
			}
		}
	}
};

int main()
{
    int size;
    cout<<"Enter size ";
    cin>>size;
    int choice=0;
    heapTree ht(size);
    while(choice!=-1)
    {
        cout<<"Enter "<<endl<<"1.Input to max heap"<<endl<<"2.Input to min heap"<<endl<<"3. Max heap sort"<<endl<<"4.Min heap sort"<<endl<<"-1 to exit";
        cin>>choice;
        if(choice==1)
        {
            ht.input();
        }
        if(choice==2)
        {
            ht.mininput();
        }
        if(choice==3)
        {
            ht.sort();
        }
        if(choice==4)
        {
            ht.minsort();
        }
    }
}
