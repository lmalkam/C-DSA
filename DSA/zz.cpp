#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

string printmonth(int n){
    string month[]={"January", "February","March","April" ," May" , "June" , "July","August","September" ,"October" ,"Novemeber","December"};

    return (month[n]);
}

int main(){
      
      for(int i=0;i<12;i++){

          string mon= printmonth(i);

          cout<<"----------"<<mon<<"------------"<<endl;

          cout<<"MO TU WE TH FR SA SU"<<endl;

          int z=5;
          // for 2022 the year started from saturday;

          int limit;

          int remaining,space;
          /*if(i>=1){
          
          if(limit==31){
              remaining=31-z;
              space=remaining%5;
              z=space;
          }
          else if(limit==30){
              remaining=30-z;
              space=remaining%5;
              z=space;
          }
          else if(limit==28){
              remaining=28-z;
              space=remaining%5;
              z=space;
          } 
          }*/

          cout<<setw(3*z+1);

          if(i==0 || i==2 || i==4 || i==6 || i==7 || i==9 || i==11){
              limit=31;
          }
          else if(i==3 || i==5 || i==8 || i==10 ){
              limit=30;
          }
          else if(i=1){
              limit=28;
          }

          

          int day=1;

          while(day<=limit){
              if(z%7==0)
              cout<<endl;
              if(day<=9)
              cout<<day++<<"  ";
              else
              cout<<day++<<" ";
              z++;
          }

        cout<<endl;
      }


     return 0;
}
