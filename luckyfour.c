#include<stdio.h>

int main()
{
    int n,i,num;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int res=0;
        scanf("%d",&num);
        while(num>0)
        {
            if((num%10)==4)
                res++;
            num/=10;
        }
        printf("%d\n",res);
    }
    return 0;
}
