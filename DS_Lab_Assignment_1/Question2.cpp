#include <iostream>
using namespace std;
int arr1[1000];
int n;
void duplicate();
int main(){
	cout<<"Enter size of the array:";
	cin>>n;
	cout<<"Enter elements of the array (Including duplicate elements):"<<endl;
	for(int i=0;i<n;i++){
		cout<<"Enter element number "<<i+1<<": ";
		cin>>arr1[i];
	}
	duplicate();
	cout<<"The modified array after deletion of duplicate elements is:"<<endl;
	for(int i=0;i<n;i++){
		cout<<arr1[i]<<" ";
	}
}
void duplicate(){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if (arr1[i]==arr1[j]){
				for(int k=j;k<n-1;k++){
					arr1[k]=arr1[k+1];
				}
			n--;
			j--;	
			}
		}
	}
}
