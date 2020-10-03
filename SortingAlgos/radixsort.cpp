//O(d*(n+b))
//d=digits,n=input size,b=base
#include <bits/stdc++.h>
using namespace std;

//count sort to sort array acc to digits
void countSort (int arr[], int n, int num) {
    int output[n];
    int count[10] = {0};
    //to store count of occurence of digits
    for (int i=0;i<n;i++) {
        count[(arr[i]/num)%10]++;
    }
    //for storing positions of next digits acc to prev digits
    for (int i=1;i<10;i++) {
        count[i] += count[i-1];
    }
    //building output array
    //positon according to count array
    //value acc to original array
    for (int i=n-1;i>=0;i--) {
        output[count[(arr[i]/num)%10]-1] = arr[i];
        count[(arr[i]/num)%10]--;
    }
    //copying generated array in original
    cout<<"current : ";
    for (int i=0;i<n;i++) {
        cout<<output[i]<<" ";
        arr[i] = output[i];
    }
    cout<<endl;
}

//main radix sort
void radixSort (int arr[], int n) {
    int m = *max_element(arr, arr + n);
    //counting sort for every digit
    for (int num=1; m/num>0 ; num*=10) {
        countSort (arr,n,num);
    }
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
    radixSort (Arr,n);
    cout<<"Sorted array : ";
    for (int i=0;i<n;i++) {
        cout<<Arr[i]<<" ";
    }
    return 0;
}
