#include<iostream>
#include<cmath>
using namespace std;

class cons{
	public:
	int add(int a,int b){//parameters in function definiton
	    int c=a+b ;
	    return c;
	}
	
	float add(float x,float  y ,float z){
	    float  s=x+y+z;
	    return s;
	    }


	
};




int main(){
	cons a,b;
 cout<<"for two parameter : "<<a.add(10,20)<<endl;//arguements in function calling
 cout<<"for three paarameters : "<<b.add(10,20,30)<<endl;


 return 0 ;
}
