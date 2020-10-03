//Worst : O(n^2) [unbalanced splits]
//Best : O(nlogn) [splits in half]
//average : O(nlogn) [all slipt complexities divided by n]
#include <bits/stdc++.h>
using namespace std;
int partition (int arr[], int left,int right);
void quickSort (int arr[], int left, int right) {
    int pivot;
    if (right > left) {
        pivot = partition (arr,left,right);
        quickSort (arr,left,pivot-1);
        quickSort (arr,pivot+1,right);
    }
}
//function to find pivot
int partition (int arr[], int left,int right) {
    int l,r,pivot;
    pivot = arr[left];
    l = left;
    r = right;
    while (l<r) {
        while (arr[l]<=pivot) {
            l++;
        }
        while (arr[r]>pivot) {
            r--;
        }
        if (l<r) {
            int t = arr[l];
            arr[l] = arr[r];
            arr[r] = t;
        }
    }
    arr[left] = arr[r];
    arr[r] = pivot;
    cout<<"current pivot : "<<arr[r]<<endl;
    return r;
}
//driver program
int main () {
    int n;
    cout<<"Enter size : ";
    cin>>n;
    int Arr[n];
    cout<<"Enter array : ";
    for (int i=0;i<n;i++) {
        cin>>Arr[i];
    }
    quickSort (Arr,0,n-1);
    cout<<"Sorted array : ";
    for (int i=0;i<n;i++) {
        cout<<Arr[i]<<" ";
    }
    return 0;
}
