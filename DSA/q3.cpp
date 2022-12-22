#include<iostream>
using namespace std;

struct part
{
    char serial[3];
    int year;
    char material[10];
    int quantity;
};

void retrive(part a[]){

    for(int i)

}


int main(){

    part a[324];

     for(int i=0;i<324;i++){
         cout<<"Enter serial number :";
         cin>>a[i].serial;
         cout<<"Enter the year : ";
         cin>>a[i].year;
         cout<<"Enter the material : ";
         cin>>a[i].material;
         cout<<"Enter the material : ";
         cin>>a[i].material;
     }

     retrive(a);


      


     return 0;
}