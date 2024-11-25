#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }

    int target;
    cout<<"Enter the target :"<<endl;
    cin>>target;


    int s=0, e=n-1;
   

    while(s<=e){
         int mid= s+ (e-s)/2;
        if(arr[mid] == target){
            cout<<"Element found at index "<<mid<<endl;
            return 0;
        }

        if(arr[mid] < target){
            e = mid-1;
          }

        else{
            s=mid+1;
        }
    }
    cout<<"Element not found";

    return 0;
}