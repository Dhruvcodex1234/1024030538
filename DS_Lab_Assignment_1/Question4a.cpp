#include<iostream>
using namespace std;

int arr[1000];
int n;
void reverse();
int main(){
	cout<<"Enter the number of elements in the array: ";
	cin>>n;
	for (int i=0;i<n;i++){
		cout<<"Enter element number "<<i+1<<": ";
		cin>>arr[i];
	}
	reverse();
	cout<<"The array after reversing: ";
	for (int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	
}
void reverse(){
	int temp;
	for (int i=0;i<n/2;i++){
		temp=arr[i];
		arr[i]=arr[n-i-1];
		arr[n-i-1]=temp;
	}
}
