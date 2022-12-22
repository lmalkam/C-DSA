#include<iostream>
using namespace std;

struct student{

    int rollno;
    string name;
    string dep;
    string course;
    int year;

};


void year(student a[],int n){

    for(int i=0;i<4;i++){
        if(a[i].year==n){
            cout<<a[i].name<<endl;
        }
    }


}

void rollno(int n,student a[]){
    for(int i=0;i<4;i++){

        if(a[i].rollno==n){
            cout<<a[i].name<<endl;
            cout<<a[i].dep<<endl;
            cout<<a[i].course<<endl;
            cout<<a[i].year<<endl;

        }
    
     }

}

int main(){
      
      student a[4];
    
     for(int i=0;i<4;i++){
         cout<<"Enter the roll number of student"<<" "<<i+1<<" ";
         cin>>a[i].rollno;
         cout<<"Enter the name of the student"<<" "<<i+1<<" ";
         cin>>a[i].name;
        cout<<"Enter the department of student"<<" "<<i+1<<" ";
         cin>>a[i].dep;
         cout<<"Enter the course of student"<<" "<<i+1<<" ";
         cin>>a[i].course;
         cout<<"Enter the year of joining of student "<<i+1<<" ";
         cin>>a[i].year; 
     }

     int yer;
     cout<<"Enter the year of which u want the name of students ";
     cin>>yer;
     
     year(a,yer);

     int roll;
     cout<<"Enter the roll number you want details of : ";
     cin>>roll;

     rollno(roll,a);



     return 0;
}
