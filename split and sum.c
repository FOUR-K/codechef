#include<stdio.h>
int main()
{
	int n,rem,sum=0;
	printf("enter the number\n");
	scanf("%d",&n);
	while(n>0)
	{
		rem=n%10;
		sum=sum+rem;
		n=n/10;
	}
	printf("the sum is %d ",sum);
	return 0;
}
