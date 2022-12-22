#include<iostream>
using namespace std;

string tillnineteen(int n){
    string words[19]={"ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE","TEN","ELEVEN","TWELEVE","THRIDTEEN","FOURTEEN","FIFTHTEEN","SIXTEEN","SEVENTEEN","EIGHTEEN","NINETEEN"};

    return words[n];
}

string tillten(int n){
    string words[]={"ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};

    return words[n];
}

string tenmultiples(int n){
    string words[]={"","TWENTY ","THIRTY ","FORTY ","FIFTY ","SIXTY ","SEVENTY ","EIGHTY ","NINETY "};
    
    return words[n];
}

int main(){

    int n;
    cin>>n;
    string final;

    int copy=n;

    //first represent thousands
    int dig=(copy/1000)%100;
    
        final+=tillten(dig-1);
        final+=" THOUSAND ";

    //THEN WE WILL PRINT HUNDREDS

    dig=(copy/100)%10;
    final+=tillten(dig-1);
    final+=" HUNDRED ";

    //THEN WE WILL PRINT THE NAME OF LAST TWO DIGITS

    dig=copy%100;

    if(dig<=19){
        final+=tillnineteen(dig-1);
    }
    else{
        final+=tenmultiples(dig/10-1);
        final+=tillten(dig%10-1);
    }
    
    
    cout<<final;  
      
     return 0;
}