#include <iostream>
using namespace std;

int main() {
    int arr[50];
    int n=0,sum=0;
    cin>>n;
    while(n){
        for (int i = 0; i < n; ++i) {
            cin>>arr[i];
            sum+=arr[i];
        }
        int average=sum/n;
        int k=0;
        for (int j = 0; j < n ; ++j) {
            if(arr[j]>average) {
                k += arr[j] - average;
            }
        }
        cout<<"The minimum number of moves is "<<k<<endl;
        k=0;
        sum=0;
        cin>>n;

    }
    return 0;
}