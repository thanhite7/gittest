#include<stdio.h>
#include<string.h>
int main()
{
    int n,sum = 0,sum1=0,check = 0,mul =1;
    char s[100000];
    scanf("%[^\n]",s);
    for(int i=strlen(s)-1;i>=0;i--)
    {
        if(s[i]=='+')
        {
            if(check==0 || i==0)
            {
                printf("NOT_CORRECT");
                break;
            }
            else
            {
                sum+=sum1;
                sum1 = 0;
                mul=1;
            }
        }
        else if(s[i]>='0'&& s[i]<='9')
        {
            check = 1;
            sum1 = sum1+(s[i]-'0')*mul;
            mul*=10;
            if(i==0)
            {
                sum+=sum1;
                sum1 = 0;
                mul =1;
            }
        }
    }
    if(check==1)
    {
        printf("%d",sum);
    }
    
    
    
}