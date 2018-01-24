#include<stdio.h>
#include<math.h>
#include<time.h>

int iter=0;
int maxitr;

struct mean
{
    float x,y;
    int points;
} mean[40];
struct point
{
    float x,y;
    int cluster;
} point[10000];

void kmeans(int k,int num)
{
    int n,i,j,p=0,q=1,it;
    float dist,y;
    int rd = num/k;
    for(i=0; i<k; i++)
    {
        mean[i].x=point[i*rd].x;
        mean[i].y=point[i*rd].y;
        mean[i].points=1;
    }
    for(i=0; i<k; i++)
        printf("\n%.1f\t%.1f\t%d\n",mean[i].x,mean[i].y,mean[i].points);
    printf("\n flag---------------\n");


    for(i=0; i<num; i++)
    {
        int pt;
        float min=999999;
        printf("\n open---------------\n");
        for(j=0; j<k; j++)
        {

            dist=sqrt(pow((point[i].x-mean[j].x),2) + pow((point[i].y-mean[j].y),2));
            printf("%.1f\t",dist);

            if(dist<min)
            {
                pt=j;
                min=dist;
            }

        }
        printf("\n flag---------------\n");

        point[i].cluster=pt;


        mean[pt].points=mean[pt].points+1;
        for(it = 0; it < k; it++)
        {
            float totalX = 0;
            float totalY = 0;
            int totalInCluster = 0;
            for(j = 0; j < num; j++)
            {
                if(point[j].cluster == it)
                {
                    totalX += point[j].x;
                    totalY += point[j].y;
                    totalInCluster++;
                }
            }
            mean[it].points=totalInCluster;
            if(totalInCluster > 0)
            {
                mean[it].x=(totalX /totalInCluster);
                mean[it].y=(totalY /totalInCluster);
            }
        }

        for(j=0; j<k; j++)
            printf("%d\t",mean[j].points);
        printf("\n close---------------\n");
        iter++;

    }

    for(i=0; i<k; i++)
        printf("\n%.1f\t%.1f\t%d\n",mean[i].x,mean[i].y,mean[i].points);

    printf("\n flag---------------\n");

    int isStillmoving=1;
    while(isStillmoving ==1|iter>maxitr)
    {
        for(it = 0; it < k; it++)
        {
            float totalX = 0;
            float totalY = 0;
            int totalInCluster = 0;
            for(j = 0; j < num; j++)
            {
                if(point[j].cluster == it)
                {
                    totalX += point[j].x;
                    totalY += point[j].y;
                    totalInCluster++;
                }
            }
            mean[it].points=totalInCluster;
            if(totalInCluster > 0)
            {
                mean[it].x=(totalX /totalInCluster);
                mean[it].y=(totalY /totalInCluster);
            }
        }
        isStillmoving = 0;

        for(i = 0; i < num; i++)
        {
            float min = 99999;
            int pt;
            for(j=0; j<k; j++)
            {

                dist=sqrt(pow((point[i].x-mean[j].x),2) + pow((point[i].y-mean[j].y),2));
                printf("%.1f\t",dist);

                if(dist<min)
                {
                    pt=j;
                    min=dist;
                }

            }

            if(point[i].cluster!=pt)
            {
                point[i].cluster=pt;
                isStillmoving = 1;
            }
        }
        iter++;

    }
    for(i=0; i<k; i++)
        printf("\n%.1f\t%.1f\t%d\n",mean[i].x,mean[i].y,mean[i].points);
    printf("\n%d\n",iter);


}


int main()
{
    int n,i,j,num;
    printf("enter no of points\n");
    scanf("%d",&n);
    printf("enter the range\n");
    scanf("%d",&num);
    float pts[n][2];
    for(i=0;i<n;i++)
    {
        pts[i][0]=rand()%num;
        pts[i][1]=rand()%num;
    }

    FILE *fp;
    fp = fopen("C:\\Users\\naveen84\\Desktop\\PROJECT\\input.txt","w");
    fprintf(fp,"%d\n",n);
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%.1f,%.1f\n",pts[i][0],pts[i][1]);
    }
    fclose(fp);

    char ch;
    //FILE *fp;
    fp =fopen("C:\\Users\\naveen84\\Desktop\\PROJECT\\input.txt","r");

    int k;

    //printf("enter the no of points\n");
    fscanf(fp,"%d\n",&n);
    //printf("enter the points\n");
    for(i=0; i<n; i++)
    {
        fscanf(fp,"%f,%f",&point[i].x,&point[i].y);
        point[i].cluster=-1;
    }
    fclose(fp);
    printf("enter k value\n");
    scanf("%d",&k);

    printf("Enter  max iterations\n");
    scanf("%d",&maxitr);

    if(k>=40)
    {
        printf("k value is too large");
        return 0;
    }
    kmeans(k,n);
    fp = fopen("C:\\Users\\naveen84\\Desktop\\PROJECT\\output1.txt","w");
    for(i=0; i<n; i++)
        fprintf(fp,"%d\t%.1f\t%.1f\t%d\n",i,point[i].x,point[i].y,point[i].cluster);

    fclose(fp);

    fp = fopen("C:\\Users\\naveen84\\Desktop\\PROJECT\\output2.txt","w");
    for(i=0; i<k; i++)
    {
        fprintf(fp,"\ncluster %d includes\n",i);
        for(j=0; j<n; j++)
        {
            if(point[j].cluster==i)
                fprintf(fp,"( %.1f,%.1f )\n",point[j].x,point[j].y);
        }
    }

    fprintf(fp,"final centroids are at\n");
    for(i=0; i<k; i++)
        fprintf(fp,"( %.1f,%.1f ) with %d points\n",mean[i].x,mean[i].y,mean[i].points);

    fprintf(fp,"\ntotal iterations = %d",iter);

    fclose(fp);

    for(i=0; i<k; i++)
    {
        printf("\ncluster %d includes\n",i);
        for(j=0; j<n; j++)
        {
            if(point[j].cluster==i)
                printf("%.1f,%.1f\n",point[j].x,point[j].y);
        }
    }

    printf("final centroids are at\n");
    for(i=0; i<k; i++)
        printf("%.1f,%.1f\n",mean[i].x,mean[i].y);
    printf("\n%d\n",iter);
    return 0;
}





