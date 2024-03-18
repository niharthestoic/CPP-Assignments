#include<iostream>
using namespace std;

class CalculateFactorial{
    private:
     int fact =1;

    public:
        int factorial(int x){
            if (x<= 0){
                throw 1;
            }
            else{
                for(int i=1;i<= x; i++){
                    fact = fact*i;
                }
            cout<<"The factorial of "<<x<<"is ="<<fact<<endl;
                
            }
            return 0;
        }
};


int main(){
    CalculateFactorial obj;

    try{
        obj.factorial(-1);
    }

    catch(int e){
        cout<<"Exception Handled"<<endl;
        cout<<"please Provide Valid Number"<<endl;
    }

}