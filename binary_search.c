
#include <stdio.h>
#include <stdlib.h>
int arr[1000000],a[1000000];
int n,q,count=0;
int check(int n,int t)
{
    int left = 0,right = n-1;
    while(left<=right)
    {
        int j = (left+right)/2;
        if(arr[j]==t)
        {
            return j;
        }
        else if(arr[j]>t)
        {
            right = j-1;
        }
        else
        {
            left = j+1;
        }
    }
    return -1;
        
}
void quickSort(int left, int right) {
	int i = left, j = right;
	int pivot = arr[left + rand() % (right - left)];
	while (i <= j) {
		while (arr[i] < pivot) ++i;
		while (arr[j] > pivot) --j;

		if (i <= j) {
			int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
			++i;
			--j;
		}
	}
	if (left < j) quickSort( left, j);
	if (i < right) quickSort( i, right);
}
int main()
{
    scanf("%d %d",&n,&q);
    for (int  i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    quickSort(0,n-1);
    for(int i=0;i<n;i++)
    {
        int j = check(n,q-arr[i]);
        if(j>i)
        {
            count++;
        }
    }
    printf("%d",count); 
    
}