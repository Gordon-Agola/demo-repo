#include <iostream>
using namespace std;

void bubbleSort(int arr[]){
	for(int i = 0; i<5;i++)
	{
		for(int j=0; j<5-i-1;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

int main()
{
	int myarr[5];
	cout<<"Enter 5 random elements you want to sort"<<endl;
	
	for(int i = 0;i<5;i++)
	{
		cin>>myarr[i];
	}
	
	cout<<"BEFORE SORTED: "<<endl;
	
	for(int i = 0;i<5;i++)
	{
		cout<<myarr[i]<<" ";
	}
	
	bubbleSort(myarr);
	
	cout<<"AFTER SORTED: "<<endl;
	
	for(int i = 0;i<5;i++)
	{
		cout<<myarr[i]<<" ";
	}
	return 0;
}
