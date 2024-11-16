#include<bits/stdc++.h>
using namespace std;


void selection_sort(int array[], int size){
    for(int i = 0; i < size-1; i++){
        int smallest_in = i;

        for(int j = i+1; j < size; j++ ){
            if(array[smallest_in] > array[j]){
                smallest_in = j;
            }
        }

        if(smallest_in != i) {
            swap(array[i], array[smallest_in]);
        }
    }
    cout << "Sorted with Selection Sort" << endl;
}

void insertion_sort(int a[],int n){
    for(int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;

    
    while(key<a[j] && j>=0){
        swap(a[j],a[j+1]);
        j--;

    }
    }
}
void recursiveInsertion(int a[],int n){
    if(n<=1){
        return;
    }
    recursiveInsertion(a,n-1);
    int key=a[n-1];
    int j=n-2;
    while(key<a[j] && j>=0){
        a[j+1]=a[j];
        j--;
    }
    a[j+1]=key;
}








void print_array(int array[], int size){
    for(int i=0; i < size; i++){
        cout << i << ": " << array[i] << endl;
    }
}




void RecursiveBuble(int a[],int n){
    if(n==1){
        return;
    }
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            swap(a[i],a[i+1]);
        }
    }
    RecursiveBuble(a,n-1);
}

int main() {
    int n;
    cin >> n;  // Read size of array
    int a[n];  // Declare the array after reading n
    
    // Input the elements of the array
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Bubble sort implementation
    // for (int i = 0; i < n - 1; i++) {
    //     for (int j = 0; j < n - i - 1; j++) {
    //         // Swap if the current element is greater than the next
    //         if (a[j] > a[j + 1]) {
    //             swap(a[j], a[j + 1]);
    //         }
    //     }
    // }
    
    // RecursiveBuble(a,n);
    // Output the sorted array
    // for (int i = 0; i < n; i++) {
    //     cout << a[i] << " ";  // Added space for better readability
    // }
    // selection_sort(a,n);
    // insertion_sort(a,n);
    recursiveInsertion(a,n);
    print_array(a,n);
    
    return 0;
}
