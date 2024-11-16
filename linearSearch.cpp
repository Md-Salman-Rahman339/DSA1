#include<bits/stdc++.h>
using namespace std;

int linearSearch(int a[],int n,int key){
    for(int i=0;i<n;i++){
        if(a[i]==key){
            return i;
        }
    }
    return -1;
}
int rLinearSearch(int a[],int n,int key){
    if(n==0){
        return -1;
    }
    else if(a[n-1]==key){
        return n-1;
    }
    return rLinearSearch(a,n-1,key);
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
    int result=rLinearSearch(a,n,key);
    if(result!=-1){
        cout<<"Found key" <<key;
    }
    else{
        cout<<"not found";
    }
}