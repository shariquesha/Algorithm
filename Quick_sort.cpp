//quick sort
#include<stdio.h>

int swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int *a,int l,int r)
{
		int pivote = a[r];
		int i = l-1;
		int j;
		for(j=l;j < r;j++)
		{
			if(a[j] <= pivote )
			{
				i++;
				swap(&a[i],&a[j]);
			}
		}
		swap(&a[i+1],&a[r]);
		
		return (i+1);
}

void quick_sort(int *a, int l , int r)
{
	if( l < r)
	{
		int p = partition(a,l,r);
		quick_sort(a,l,p-1);
		quick_sort(a,p+1,r);
	}
}
int main(void)
{
	int arr[] = {10,-1,5,6,3,2,1};
	int size = sizeof(arr)/sizeof(arr[0]);
	quick_sort(arr,0,size);
	int i = 0;
	for(;i<size;i++)
	printf("%d ",arr[i]);
	
	return 0;
}
