#include <iostream>
using namespace std;
#include "calculator.h"


int main(){

   cout<<"test add 4+6 = " << add(4,6)<<"\n";
       
    cout<< "test Subtraction 10-4=" << subtract(10, 4) <<"\n";
    cout<< "test Multiplication 6*7=:" << multiply(6, 7) <<"\n";
    cout<< "test Division 15/3=" << divide(15, 3) <<"\n";
    cout<< "test Division by 0: 15/0=" << divide(15, 0) <<"\n";//test for division by 0
    cout<< "test Factorial: " << factorial(5) <<"\n";
    cout << "test GCD: " << gcd(48, 18) <<"\n";
    cout << "test LCM: " << lcm(12, 15) <<"\n";
    cout<< "test Random Number: " << randomNumber(1, 100) <<"\n";
        return 0;
    }