#include<stdio.h>
#include<math.h>
float x0,y00,x1,y11,x,y;
float r;
int ans[100000],n,i=0;
float square(float x,float y)
{
    return sqrt(x*x+y*y);
}
float max(float a, float b)
{
    if(a>b)
        return a;
    return b;
}
float min(float a, float b)
{
    if(a>b)
        return b;
    return a;
}
void check()
{
    scanf("%f %f %f %f",&x0,&y00,&x1,&y11);
    scanf("%f %f %f",&x,&y,&r);
    int check = 1;
    if(x-max(x1,x0)>r || -x+min(x1,x0)>r|| min(y11,y00)-y>r||y-max(y11,y00)>r)
    {
        check=0;
    }
    else if ((y<min(y11,y00) && x>max(x1,x0) && square(max(x1,x0)-x,min(y00,y11)-y)>r) || (y>max(y11,y00)&& x>max(x1,x0)&& square(max(x1,x0)-x,max(y11,y00)-y)>r)|| (y<min(y00,y11)&& x<min(x1,x0)&& square(min(x1,x0)-x,min(y00,y11)-y)>r)|| (y>max(y11,y00)&& x<min(x1,x0) && square(min(x0,x1)-x,max(y11,y00-y))>r))
    {
        check =0;
    }
    else if(y-min(y11,y00)>r && max(y11,y00)-y>r && x-min(x1,x0)>r && max(x1,x0)-x>r)
    {
        check=1;
    }
    ans[i] = check;
    i++; 
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        check();
    }
    for(int j=0;j<i;j++)
    {
        printf("%d\n",ans[j]);
    }
}