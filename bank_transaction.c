#include<stdio.h>
#include<string.h>
#include<stdbool.h>
char start[100000][15],end[100000][15],time[100],atm[20],temp[15],temp1[15],listsort[100000][15],check2[10000][15],len = 0;
int price[100000],i=0,n,ans[100000],k=0,check1 = 0;
char op1[100] = "?number_transactions",op2[100] = "?total_money_transaction",op3[100] ="?list_sorted_accounts",op4[100] = "?total_money_transaction_from",op5[100] = "?inspect_cycle";
int check_list(char name[])
{
    for(int i=0;i<k;i++)
    {
        if(strcmp(listsort[i],name)==0)
        {
            return 0;
        }
    }    
    return 1;
}

void sort_list()
{
    for(int l=0;l<k-1;l++)
    {
        for(int j=i+1;j<k;j++)
        {
            if(strlen(listsort[l])>strlen(listsort[j]))
            {
                char temp2[100];
                strcpy(temp2,listsort[l]);
                strcpy(listsort[l],listsort[j]);
                strcpy(listsort[j],temp2);
            }
            else if(strlen(listsort[l])==strlen(listsort[j]))
            {
                int count = 0,f = 0;
                while(count<strlen(listsort[l])&&f==0 )
                {
                    if(listsort[l][count]>listsort[j][count])
                    {
                        char temp2[100];
                        strcpy(temp2,listsort[l]);
                        strcpy(listsort[l],listsort[j]);
                        strcpy(listsort[j],temp2);
                        f=1;
                    }
                    count++;
                    
                }
            }
        }
    }
}

int check_duplicate(char name[])
{
    for(int g=0;g<len;g++)
    {
        if(strcmp(check2[g],name)==0)
        {
            return 0;
        }
    }
    return 1;
}
void check(char name[],int k)
{
    for(int i=0;i<n;i++)
    {
        if(strcmp(start[i],name)==0 &&check_duplicate(start[i])==1)
        {
            k--;
            strcmp(check2[len],start[i]);
            len++;
            if(k==0)
            {
                if(strcmp(end[i],temp)==0)
                {
                    check1=1;
                }
                
            }
            else
            {
                    check(end[i],k);
            }
            len--;
            k++;
        }
    }
}
int main()
{
    
    do
    {
        fflush(stdin);
        scanf("%s",temp);
        if(strcmp(temp,"#")==0)
        {
            break;
        }
        strcpy(start[i],temp);
        scanf("%s %d %s %s",end[i],&price[i],time,atm);
        i++;
    } while (strcmp(temp,"#")!=0);
    n=i;
    i=0;
    do
    {
        fflush(stdin);
        scanf("%s",temp1);
        if(strcmp(temp1,"#")==0)
        {
            break;
        }
        else if(strcmp(temp1,op1)==0)
        {
            ans[i] = n;
            i++;
        }
        else if(strcmp(temp1,op2)==0)
        {
            int sum = 0;
            for(int i=0;i<n;i++)
            {
                sum+=price[i];
            }
            ans[i] =  sum;
            i++;
        }
        else if(strcmp(temp1,op3)==0)
        {
            ans[i] = 20102003;
            for(int j=0;j<n;j++)
            {
                if(check_list(start[j])==1)
                {
                    strcpy(listsort[k],start[j]) ;
                    k++;
                }
                if(check_list(end[j])==1)
                {
                    strcpy(listsort[k],end[j]) ;
                    k++;
                }
            }
            sort_list();
            i++;
        }
        else if(strcmp(temp1,op4)==0)
        {
            int sum = 0;
            scanf("%s",temp1);
            for(int j=0;j<n;j++)
            {
                if(strcmp(start[j],temp1)==0)
                {
                    sum+=price[j];
                }
            }
            ans[i]  = sum;
            i++;
        }
        else if(strcmp(temp1,op5)==0)
        {
            int h;
            scanf(" %s %d",temp,&h);
            check(temp,h);
            ans[i] = check1;
            i++;
        }
    } while (strcmp(temp1,"#")!=0);
    
        for(int j=0;j<i;j++)
        {
            if(ans[j]==20102003)
            {
                for(int l=0;l<k;l++)
                {
                    printf("%s ",listsort[l]);
                }
                printf("\n");
            }
            else
            {
                printf("%d\n",ans[j]);
            }
        
        
    }
    
}