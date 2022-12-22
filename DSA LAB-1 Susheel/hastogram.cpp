#include <iostream>
using namespace std;
int main()
{
    int A[6]={2,4};
    int maxa=0;
    for(int i=0;i<2;i++){
        if(A[i]<A[i+1]){
            if(maxa<2*(A[i])){
                maxa=2*(A[i]);
            }
        }
        else{
            if(maxa<2*(A[i+1])){
                maxa=2*(A[i+1]);
            }
        }
        
    }
    cout<<maxa;
    return 0;
}
