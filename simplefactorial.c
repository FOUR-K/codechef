#include<stdio.h>
#include<math.h>
int fact(int n)
{
    if(n<=1)
        return 1;
    return(n*fact(n-1));

}
int main()
{
    long double a[100];
    int t,n,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
    scanf("%d",&n);
    a[i] = fact(n);
    }
    for(i=0;i<t;i++)
    {
        printf("%Ld\n",a[i]);
    }
    return 0;
}
