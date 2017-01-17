#include <iostream>
using namespace std;

int main() {
    int arr[50];
    int n=0,sum=0,k=0;
    int a=1;
    while(cin>>n && n){
        sum = 0;
        k=0;
        for (int i = 0; i < n; ++i) {
            cin>>arr[i];
            sum+=arr[i];
        }
        int average=sum/n;
        for (int j = 0; j < n ; ++j) {
            if(arr[j]>average) {
                k += (arr[j] - average);
            }
        }
        cout<<"Set #"<<a<<endl;
        cout<<"The minimum number of moves is "<<k<<"."<<endl<<endl;
        a++;

    }
    return 0;
}
