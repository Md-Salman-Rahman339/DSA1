#include<bits/stdc++.h>
using namespace std;

int binarySearch(int a[],int n, int key){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==key){
            return mid;
        }
        else if(a[mid]<key){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
    
}
int RbinarySearch(int a[],int low,int high,int key){
    if(high>=low){
        int mid=low+(high-low)/2;
    
    if(a[mid]==key){
        return mid;
    }
    else if(a[mid]<key){
        RbinarySearch(a,mid+1,high,key);
    }
    else{
        RbinarySearch(a,low,mid-1,key);
    }
    }

}

int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    int key;
    cin>>key;

    // int result = linearSearch(a, n, key);
    // int result=binarySearch(a,n,key);
    int result=RbinarySearch(a,0,n-1,key);
    if(result!=-1){
        cout<<"Found key at index " <<result <<"the key is :" <<key;
    }
    else{
        cout<<"not found";
    }
}