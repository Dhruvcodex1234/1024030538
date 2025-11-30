#include <iostream>
using namespace std;
int m,n;
int temp;
int arr[100][100];
int arr2[100][100];
void transpose();
int main(){
	cout<<"Enter number of rows of the array: ";
	cin>>m;
	cout<<"Enter number of columns of the array: ";
	cin>>n;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<"Enter element with row index "<<i<<" and colun index "<<j<<": ";
			cin>>arr[i][j];
		}
	}
	cout<<"Array before transpose: "<<endl;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	transpose();
	cout<<"Array after transpose: "<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<arr2[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
void transpose(){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			arr2[j][i]=arr[i][j];
		}
	}
}
