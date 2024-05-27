//Write a program to perform the analysis of Binary Search

#include<iostream>
#include<vector>
using namespace std;

void binarysearch(int arr[],int size, int target){
    
    int low=0;
    int high=size-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target){ 
            cout<<"The target was found at index: "<<mid<<endl;
            return ;
        }
        else if(arr[mid]<target){
            low= mid + 1;
        }
        else{
            high= mid - 1;
        }
    }
    cout<<"The target was not found in the array"<<endl;
}
    


int main(){
    int arr[]={1,2,3,4,5};
    int size=sizeof(arr);
    int target;
    int nums[5]={1,2,3,4,5};
    cout<<"The Array is: ";
    for(int n:arr){
        cout<<n<<" ";
    }
    cout<<"\nEnter the number you want to search in the Array: "<<endl;
    cin>>target;
    binarysearch(arr,size,target);
    return 0;
}
