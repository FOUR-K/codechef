#include<stdio.h>

int main()
{
    int n,i,j,g,flag=0;
    char ch[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&g);
        for(j=0;j<g;j++)
        {
            scanf("%c",&ch[j]);
        }
        for(i=0;i<g;i++)
        {
            if(ch[i]=='Y')
            {
                printf("NOT INDIAN\n");
                flag =1;
                goto FLAG;
            }
            else if(ch[i]=='I')
            {
                printf("INDIAN\n");
                flag = 2;
                goto FLAG;
            }
        }
        FLAG:if(flag==0)
            printf("NOT SURE\n");
    }
    return 0;
}
