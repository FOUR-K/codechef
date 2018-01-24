#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int compare(const int *a,const int *b)    //comparing function
{
    return(*(int*)a - *(int*)b);

}
int main()
{
	int a[100][4],i,j,n=100;
	float dist[100][100];
	/*assigning random values to array*/
	for(i=0;i<100;i++)
	{
		for(j=0;j<4;j++)
		{
			a[i][j] = -100+rand()%200;    //random value function
		}
	}
	/*printing the point values*/
	for(i=0;i<100;i++)
	{
		printf("\nPoint %d = (",i+1);
		for(j=0;j<4;j++)
		{
			printf(" %d ,",a[i][j]);
		}
		printf(")");
	}
	for(i=0;i<100;i++)
    {
        for(j=0;j<100;j++)
        {
            dist[i][j] = sqrt(pow((a[j][0]-a[i][0]),2) + pow((a[j][1]-a[i][1]),2) + pow((a[j][2]-a[i][2]),2) + pow((a[j][3]-a[i][3]),2));
        }
    }
    for(i=0;i<100;i++)
    {
        qsort(dist[i],n,sizeof(int),compare);     //sorting
    }
    /*sum of distance and minimum */
    int num,k;
    float sum,min=99999999;
    printf("\nEnter no\n");
    scanf("%d",&num);
    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=0;j<num+1;j++)
        {
            sum=sum+dist[i][j];

        }
        printf("\nSum of %d is %0.2f",i+1,sum);
        if(min>sum)
        {
            min=sum;
            k=i+1;
        }
    }
    printf("\nmin sum is= %f and point is %d\n",min,k);
return 0;
}

