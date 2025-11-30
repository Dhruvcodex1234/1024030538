#include <iostream>
using namespace std;

int arr[1000];
int len=0;
void create();
void display();
void insert();
void del();
void linear_search();
int main(){
	while(true){
	int choice;
	cout<<"Enter choice:\n";
	cout<<"1. 1 to create an array\n2. 2 to diplay the current array\n3. 3 to insert an element into the array\n4. 4 to delete an element from the array\n5. 5 to perform linear search for an element in the array\n6. 6 to exit from the menu"<<endl;
	cin>>choice;
	bool goodbye=false;
	
	switch(choice){
		
		case 1:
			create();
			break;
		case 2:
			display();
			break;
		case 3:
		    insert();
		    break;
		case 4:
		    del();
		    break;
		case 5:
		    linear_search();
		    break;
		case 6:
		    goodbye=true;
		    cout<<"You have successfully exited from the menu!";
		    break;
		default:
			cout<<"Please enter a valid choice!"<<endl;
	}
	if (goodbye){
	    break;
	}
}
	
	return 0;
}
void create(){
	cout<<"Enter length of array:";
	cin>>len;
	for(int i=0;i<len;i++){
		cout<<"Enter element number "<<i+1<<":";
		cin>>arr[i];
	}
	
}
void display(){
	if (len==0){
		cout<<"Please create an array first!"<<endl;
	}
	else{
	    cout<<"The current array is: ";
		for(int i=0;i<len;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
}
void insert(){
    if (len==0){
        cout<<"Please create an array first!"<<endl;
	}
	else{
	    int num,ind;
	    cout<<"Enter element which needs to be inserted:";
	    cin>>num;
	    cout<<"Enter index at which the element needs to be inserted:";
	    cin>>ind;
	    len++;
	    for(int i=len-1;i>ind;i--){
	        arr[i]=arr[i-1];
		}
		arr[ind]=num;
	}
}
void del(){
     if (len==0){
        cout<<"Please create an array first!"<<endl;
	}
	else{
	    int num;
	    cout<<"Enter the element which needs to be deleted:";
	    cin>>num;
	    bool found = false;
	    for(int i=0;i<len;i++){
	        if(arr[i]==num){
	            for(int j=i;j<len-1;j++){
	                arr[j]=arr[j+1];          
	                found=true;
	            }
	            len--;
	        }
	        
		}
		if(!found){
		    cout<<"Element not found in the array!"<<endl;
		}
	}
}
void linear_search(){
    if (len==0){
        cout<<"Please create an array first!"<<endl;
	}
	else{
	    int num;
	    cout<<"Enter the element which needs to be searched:";
	    cin>>num;
	    bool found=false;
	    for(int i=0;i<len;i++){
	        if(arr[i]==num){
	            cout<<"Element "<<num<<" found at index number "<<i<<endl;
	            found=true;
	        }
	    }
	    if(!found){
	        cout<<"Element "<<num<<"not found in the current array!";
	    }
	}
}

