#include<bits/stdc++.h>

int main()
{
    int t,i,n,m,a[50000];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        m=99999;
        for(i=0;i<n;i++)
        {
            if(a[i]<m)
                m=a[i];
        }
        printf("%d\n",(m*(n-1)))
    }
    return 0;
}
