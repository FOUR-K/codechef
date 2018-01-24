#include<stdio.h>

int main()
{
	int a[100][4],i,j,n=100,num,m,ptr[100];
	float dist[100][100],unsortdist[100];



	/*assigning random values to array*/
	for(i=0;i<100;i++)
	{
		for(j=0;j<4;j++)
		{
			a[i][j] = -50+rand()%100;    //random value function
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

    printf("\nenter the value of point\n");
    scanf("%d",&num);
    printf("enter the number of points\n");
    scanf("%d",&n);

    for(i=0;i<100;i++)
    {
        unsortdist[i] = dist[num-1][i];  //copying unsorted point array
    }

    for(i=0;i<100;i++)
    {
        qsort(dist[i],n,sizeof(int),compare);     //sorting
    }



    for(i=0;i<n;i++)
    {
        //ptr[i] = BinarySearch(unsortdist,0,sizeof(unsortdist)/sizeof(unsortdist[0]),dist[num-1][i]);
        ptr[i] = search(unsortdist,dist[num-1][i+1]);
        printf("%d\n",ptr[i]);
    }
    float x=0,y=0,dx,Dx;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
    {
        x = x + dist[ptr[i]][ptr[j]];
    }
    }
    printf("\n%f\n",x);

    for(i=0;i<n;i++)
    {
        y = y + dist[num-1][i+1];
    }
    dx = y/n;
    Dx = x/(n*(n-1));
    printf("dx = %f Dx = %f\n",dx,Dx);
    printf("LDOF = %f",dx/Dx);


return 0;
}
