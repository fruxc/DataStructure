#include<stdio.h>
#define ML(t) while(t--)
int main()
{
	int n,t,i,j;
	scanf("%d",&t);					// Number of test because i wanted to submit it on codechef.
	ML(t)
	{
		scanf("%d",&n);
		int singer[n][3];                     ///////Singer[n][0] for lower cord, Singer[n][1] for upper cord, Singer [n][2] for score
		for(i=0; i<n; i++)
		{
			for(j=0; j<2; j++)
			{
				scanf("%d",&singer[i][j]);	//lower limit then upper limit
				singer[i][2]=0;
			}
			
		}
	
		for(i=0; i<n; i++)
        	{
        	        for(j=0; j<n; j++)
        	        {
				if(i==j)			//so it'll not compare with same singer
				{continue;}
        	                if(singer[j][0]<singer[j][1] && singer[i][0]<singer[i][1])
				{
					if(singer[j][0]==singer[i][0] && singer[j][1]==singer[i][1])
					{
						singer[i][2]++;				//if its equal increment score by 1
						singer[j][2]++;
					}else {if(singer[i][0]<singer[j][0])
						{
							if(singer[i][1]>=singer[j][1])
							{
								singer[i][2] = singer[i][2] + 2; // if upper limit is greater then increment score by 2
							}
						}
					}
				}
			}
        	        
        	}
		for(i=0; i<n; i++)
		{
			printf("%d\t",singer[i][2]);
		}
	}
}
