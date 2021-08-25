#include <iostream>
using namespace std;
//quick sort algorithms
Partition(int arr[],int s, int e)
{
	int pivot = arr[e];
	int pIndex = s;
	
	for(int i=s;i<e;i++){
		if(arr[i]<pivot){
			int temp=arr[i];
			arr[i]=arr[pIndex];
			arr[pIndex]=temp;
			pIndex++;
		}
	}
	int temp=arr[e];
	arr[e]=arr[pIndex];
	arr[pIndex]=temp;
	
	return pIndex;
}
QuickSort(int arr[],int s,int e)
{
	if(s<e)
	{
		int p=Partition(arr,s,e);
		QuickSort(arr,s,p-1);    //recursion on left hand  side
		QuickSort(arr,p+1,e);    //recursion on right hand side
	}
}


int main()
{
	int size=0;
	cout<<"Enter the size of array: "<<endl;
	cin>>size;
	int myarr[size];
	
	cout<<"Enter "<<size<<" integers in any order: "<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>myarr[i];
	}
	
	cout<<"Before sorting"<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<myarr[i]<<" ";
	}
	cout<<endl;
	QuickSort(myarr,0,(size-1));
	cout<<"After sorting"<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<myarr[i]<<" ";
	}
	return 0;
}
