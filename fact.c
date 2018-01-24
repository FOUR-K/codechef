#include<stdio.h>
int main()
{
	int fact=1,i,n,m,j;
	scanf("%d",&m);
	for(j=0;j<m;j++)
    {
        scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
	fact = fact*i;
    }
	printf("%d\n",fact);
    }
	return 0;
}
