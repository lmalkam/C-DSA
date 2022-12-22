#include<iostream>
using namespace std;

string tenmultiples(int n){
    string words[]={"","TWENTY ","THIRTY ","FORTY ","FIFTY ","SIXTY ","SEVENTY ","EIGHTY ","NINETY "};
    
    return words[n];
}

string tillnineteen(int n){
    string words[19]={"ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE","TEN","ELEVEN","TWELEVE","THRIDTEEN","FOURTEEN","FIFTHTEEN","SIXTEEN","SEVENTEEN","EIGHTEEN","NINETEEN"};

    return words[n];
}

void convert(int n,string final){
     
     if(n==0){
     cout<<final;
     return;
     }

     if(n>999){
         final+=tillnineteen((n/1000)%100-1);
         return convert(n-((n/1000)%100)*1000,final+=" THOUSAND ");
     }

     if(n>99){
         final+=tillnineteen((n/100)%10-1);
         return convert(n-((n/100)%10)*100,final+=" HUNDRED ");
     }
     
     if(n<=19){
        return convert(n/100,final+=tillnineteen(n-1));
    }
    else{
        final+=tenmultiples((n%100)/10-1);
        return convert(n/100,final+=tillnineteen(n%10-1));
    }

}

int main(){

    int n;
    cin>>n;
    string final;

    convert(n,final);
      
     return 0;
}