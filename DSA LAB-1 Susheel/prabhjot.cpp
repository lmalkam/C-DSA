#include <iostream>
#include<string>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	while(n--) // 2 INBY BYBY
	{
	 int count=0;   
	 string s;
	 cin>>s;
	 string ar[s.length()-1];
 	 int a=s.length();
 	 for(int i=0;i<a-1;i++)
 	 {
 	     string si="";
 	     si+=s[i];
         si+=s[i+1];
 	     ar[i]=si;
 	 }
 	
	 for(int i=0;i<a-1;i++)
	 {
	    for(int j=0;j<a-1;j++)
	    {
	        if(ar[i]==ar[j] && i!=j)
	        {
	            count++;
	        }
	    }
	 }

	 cout<<a-1-(count/2)<<endl;
	}	
	return 0;
}