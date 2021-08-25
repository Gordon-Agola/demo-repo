#include <iostream>
using namespace std;

void linearSearch(int a[],int n)
{
	int temp=-1;
	for(int i = 0;i<5;i++){
		if(a[i]==n){
			cout<<"Element found at location: "<<i<<endl;
			temp=0;
		}
		
	}
	if(temp==-1){
		cout<<"No Element found"<<endl;
	}
}
int main()
{
	int arr[5];
	cout<<"Please enter five element of the array";
	for(int i=0;i<5;i++){
		cin>>arr[i];
	}
	cout<<"Enter an element to search"<<endl;
	int num;
	cin>>num;
	
	linearSearch(arr,num);
	
}
