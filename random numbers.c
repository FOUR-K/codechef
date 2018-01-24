#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int a[100][4],i,j,n1,n2;
	float dist;
	/*assigning random values to array*/
	for(i=0;i<100;i++)
	{
		for(j=0;j<4;j++)
		{
			a[i][j] = -50+rand()%200;    /*random value function*/
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
	printf("\nenter the two points\n");
	scanf("%d%d",&n1,&n2);
	n1--;
	n2--;
	dist = sqrt(pow((a[n2][0]-a[n1][0]),2) + pow((a[n2][1]-a[n1][1]),2) + pow((a[n2][2]-a[n1][2]),2) + pow((a[n2][3]-a[n1][3]),2));
	printf("The distance is %f",dist);
	return 0;
}

