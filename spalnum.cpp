#include<iostream>
#include<cstdio>
bool isPalindrome(int n)
{
    int i,j=0;
    int v[6];
    while(n>0)
    {
        v[j]=n%10;
        n/=10;
        j++;
    }
    i=0;
    j=j-1;
    while(i!=j)
    {
        if(v[i]!=v[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int main()
{
    int n,i,l,r,ptr,s[100000];
    scanf("%d",&n);
    s[0]=0;
    for(i=1;i<100000;i++)
    {
        s[i]=s[i-1];
        if(isPalindrome(i))
            s[i]+=i;
    }

    for(i=0;i<n;i++)
    {
        int sum=0;
        scanf("%d%d",&l,&r);
        sum = s[r]-s[l-1];
        printf("%d\n",sum);
    }
    return 0;
}
