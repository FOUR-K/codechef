#include<stdio.h>
int main()
{
    int n,k,m,x=0,i;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&m);
        if(m%k==0)
        {
            x++;
        }
    }
    printf("%d",x);
    return 0;
}
