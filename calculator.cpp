#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        std::cerr << "Error: Division by zero!\n";
        return 0;
    }
    return a / b;
}

long long factorial(int n) {
    if (n < 0) return -1;
    long long fact = 1;
    for (int i = 2; i <= n; ++i) fact *= i;
    return fact;
}

int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int randomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}


int main(){
    return 0;
}
