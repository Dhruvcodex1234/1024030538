#include <iostream>
using namespace std;
int arr[100][100];
int m,n;
void rowsum();
void columnsum();
int main(){
	cout<<"Enter number of rows in the 2D array: ";
	cin>>m;
	cout<<"Enter number of columns in the 2D array: ";
	cin>>n;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<"Enter element present at row index "<<i<<" and column index "<<j<<": ";
			cin>>arr[i][j];
		}
	}
	rowsum();
	columnsum();
	return 0;
}
void rowsum(){
	int r_sum;
	for(int i=0;i<m;i++){
		r_sum=0;
		for(int j=0;j<n;j++){
			r_sum=r_sum+arr[i][j];
		}
		cout<<"Sum of elements of row "<<i<<" is:"<<r_sum<<endl;
	}
}
void columnsum(){
	int c_sum;
	for(int j=0;j<n;j++){
		c_sum=0;
		for(int i=0;i<m;i++){
			c_sum=c_sum+arr[i][j];
		}
		cout<<"Sum of elements of column "<<j<<" is:"<<c_sum<<endl;
	}
}
