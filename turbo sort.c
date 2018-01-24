#include<stdio.h>
#include<stdlib.h>

int main()
{
    int j,i,temp,n,p,a[100];
    scanf("%d",&n);
    p=n;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(j=0;j<n;j++,n--)

    {
        for(i=0;i<n-1;i++)
    {
        if(a[i]>a[i+1])
        {
            temp=a[i+1];
            a[i+1]=a[i];
            a[i]=temp;
        }
    }
    }

    for(i=0;i<p;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}
