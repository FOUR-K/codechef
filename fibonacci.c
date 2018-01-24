#include<stdio.h>
int main()
{
	int a=0,b=1,c,i,n;
	printf("enter the number of terms\n");
	scanf("%d",&n);
	printf("%d %d",a,b);
	for(i=0;i<n;i++)
	{
		c = a+b;
		a = b;
		b = c;
		printf(" %d",c);
	}
	return 0;
}
