#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void swap(int *p1,int *p2);
int print(int a[],int len);
void bubbleSort(int a[],int len);
void selectionSort(int a[],int len);
void insertionSort(int a[],int len);
void merging(int a[],int beg,int mid,int end);
void mergeSort(int a[],int beg,int end);
int partition(int a[],int start,int end);
void quickSort(int a[],int start,int end);
int getMaxNum(int a[],int n);
void countingSort(int a[],int n);
void countingSortForRadix(int a[],int n,int place);
void radixSort(int a[],int n);
void shellSort(int a[],int len);
void heapify(int a[],int n,int i);
void heapSort(int a[],int n);
int main()
{
	int len;
	
	int array1[]={23,45,12,34,7,40,5,0,19,11};
	len=sizeof(array1)/4;
	printf("Array before sorting: ");
	print(array1,len);
	bubbleSort(array1,len);
	printf("Array after bubble sort: ");
	print(array1,len);
	
	int array2[]={23,45,12,34,7,40,5,0,19,11};
	len=sizeof(array2)/4;
	printf("\nArray before sorting: ");
	print(array2,len);
	selectionSort(array2,len);
	printf("Array after selection sort: ");
	print(array2,len);
	
	int array3[]={23,45,12,34,7,40,5,0,19,11};
	len=sizeof(array3)/4;
	printf("\nArray before sorting: ");
	print(array3,len);
	selectionSort(array3,len);
	printf("Array after insertion sort: ");
	print(array3,len);
	
	int array4[]={45,23,12,34,7,40,5,0,19,11};
	len=sizeof(array4)/4;
	printf("\nArray before sorting: ");
	print(array4,len);
	mergeSort(array4,0,len-1);
	printf("Array after merge sort: ");
	print(array4,len);
	
	int array5[]={7,5,8,3,11,18,4,9,25,6,15};
	len=sizeof(array5)/4;
	printf("\nArray before sorting: ");
	print(array5,len);
	quickSort(array5,0,len-1);
	printf("Array after quick sort: ");
	print(array5,len);
	
	int array6[]={2,5,7,2,8,1,0,5,1,7,3,8,2,5,1};
	len=sizeof(array6)/4;
	printf("\nArray before sorting: ");
	print(array6,len);
	countingSort(array6,len);
	printf("Array after counting sort: ");
	print(array6,len);
	
	int array7[]={348,12,208,87,4818,49881,497,2674,29};
	len=sizeof(array7)/4;
	printf("\nArray before sorting: ");
	print(array7,len);
	radixSort(array7,len);
	printf("Array after radix sort: ");
	print(array7,len);
	
	int array8[]={45,23,12,34,40,7,5,0,19,11};
	len=sizeof(array8)/4;
	printf("\nArray before sorting: ");
	print(array8,len);
	shellSort(array8,len);
	printf("Array after shell sort: ");
	print(array8,len);
	
	int array9[]={45,23,12,34,40,7,5,0,19,11};
	len=sizeof(array9)/4;
	printf("\nArray before sorting: ");
	print(array9,len);
	heapSort(array9,len);
	printf("Array after heap sort: ");
	print(array9,len);
	return 0;
}
void swap(int *p1,int *p2)
{
	int temp=*p1;
	*p1=*p2;
	*p2=temp;
}
int print(int a[],int len)
{
	static int i=0;
	if (i==len){
		printf("\n");
		i=0;
		return 0;
	}
	printf("%d  ",a[i++]);
	print(a,len);
}
void bubbleSort(int a[],int len)
{
	int i,j;
	for (i=0;i<len-1;i++){
		for (j=0;j<len-1-i;j++){
			if (a[j]>a[j+1])
				swap(&a[j],&a[j+1]);
		}
	}
}
void selectionSort(int a[],int len)
{
	int i,j,min_index;
	for (i=0;i<len-1;i++){
		min_index=i;
		for (j=i+1;j<len;j++){
			if (a[j]<a[min_index])
				min_index=j;
		}
		swap(&a[i],&a[min_index]);
	}
}
void insertionSort(int a[],int len)
{
	int i,j,key;
	for (i=1;i<len;i++){
		j=i-1;
		key=a[i];
		while (key<a[j] && j>=0){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}
void merge(int a[],int beg,int mid,int end)
{
	int i=beg,j=mid+1,b[end],index=beg;
	while(i<=mid && j<=end){
		if(a[i]<=a[j])
			b[index++]=a[i++];
		else
			b[index++]=a[j++];
	}
	while(j<=end)
		b[index++]=a[j++];
	while(i<=mid)
		b[index++]=a[i++];
	for(i=beg;i<=end;i++)
		a[i]=b[i];	
}
void mergeSort(int a[],int beg,int end)
{
	if(beg<end){
		int mid=(beg+end)/2;
		mergeSort(a,beg,mid);
		mergeSort(a,mid+1,end);
		merge(a,beg,mid,end);
	}
}
int partition(int a[],int start,int end)
{
	int i,j,pivot;
	i=start;
	j=end;
	pivot=a[i];
	while(i<j)
	{
		while(a[i]<=pivot)
			i++;
		while(a[j]>pivot)
			j--;
		if(i<j)
			swap(&a[i],&a[j]);
	}
	swap(&a[start],&a[j]);  //a[start]=pivot
	return j;
}
void quickSort(int a[],int start,int end)
{
	if (start<end){
		int p=partition(a,start,end);
		quickSort(a,start,p-1);
		quickSort(a,p+1,end);
	}
}
int getMaxNum(int a[],int n)
{
	int i=0,max=a[0];
	for(i=1;i<n;i++){
		if(a[i]>max)
			max=a[i];
	}
	return max;
}
void countingSort(int a[],int n)
{
	int m=getMaxNum(a,n)+1;
	int count[m];
	int i,temp[n];
	for (i=0;i<m;i++)
		count[i]=0;
	for (i=0;i<n;i++)
		++count[a[i]];
	for(i=1;i<m;i++)
		count[i]=count[i-1]+count[i];
	for(i=n-1;i>=0;i--)
		temp[--count[a[i]]]=a[i];
	for (i=0;i<n;i++)
		a[i]=temp[i];
}
void countingSortForRadix(int a[],int n,int place)
{
	int count[10]={0};
	int i,temp[n];
	for (i=0;i<n;i++)
		++count[(a[i]/place)%10];
	for (i=1;i<10;i++)
		count[i]+=count[i-1];
	for (i=n-1;i>=0;i--)
		temp[--count[(a[i]/place)%10]]=a[i];
	for (i=0;i<n;i++)
		a[i]=temp[i];
}
void radixSort(int a[],int n)
{
	int max=getMaxNum(a,n),place;
	for (place=1;max/place>0;place*=10)
		countingSortForRadix(a,n,place);
}
void shellSort(int a[],int len)
{
	int gap,j,i;
	for (gap=len/2;gap>0;gap/=2){
		for (j=gap;j<len;j++){
			for (i=j-gap;i>=0;i-=gap){
				if (a[i+gap]>a[i])
					break;
				else
					swap(&a[i+gap],&a[i]);
			}
		}
	}
}
void heapify(int a[],int n,int i)
{
	int big,lc,rc;
	big=i;
	lc=2*i+1;
	rc=2*i+2;
	if (lc<n && a[lc]>a[big])
		big=lc;
	if (rc<n && a[rc]>a[big])
		big=rc;
	if (big!=i){
		swap(&a[i],&a[big]);
		heapify(a,n,big);
	}
}
void heapSort(int a[],int n)
{
	int i;
	for (i=n/2-1;i>=0;i--)  //for building Maxheap
		heapify(a,n,i);
	for (i=n-1;i>0;i--){    //for deleting and getting elements in ascending order
		swap(&a[0],&a[i]);
		heapify(a,i,0);
	}
}