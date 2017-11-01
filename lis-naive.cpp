//lis- naive approach

#include<iostream>
void lis(int arr[],int start,int end,int* l)
{
	if(end == 0) *l = 0;
	if(start == end) return ;
	int count = 1;
	int i = start;
	int p = start;
	for(;i < end ; i++)
	{
		if(arr[i] > arr[p])
		{
			p = i;
			count++;
		}
	}
	
	if(*l < count)
	*l = count;
	lis(arr,start+1,end,l);
}
int main()
{
	int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
	int n = sizeof(arr)/sizeof(arr[0]);
	int l = 1;
	lis( arr,0,n,&l);
	printf("Length of lis is %d\n",l);
	return 0;
}
