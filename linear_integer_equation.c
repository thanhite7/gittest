#include<stdio.h>
int n,m,arr[100];
void generate(int k,int sum)
{
    for(int i=1;i<=m-n+1;i++)
    {
        arr[k] = i;
        sum-=arr[k];
        k++;
        if(k==n)
        {
            if(sum==0)
            {
                for(int j=0;j<k;j++)
                {
                    printf("%d ",arr[j]);
                }
                printf("\n");
                }
        }
        else
        {
            generate(k,sum);
        }
        k--;
        sum+=arr[k];
        
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    int sum = m;
    generate(0,sum);
}