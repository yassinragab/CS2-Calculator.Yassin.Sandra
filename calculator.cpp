#include <iostream>
#include "calculator.h"
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
        std::cout << "Error: Division by zero!\n";
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

//bonus
 
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}


queue<string> shuntingYard(string expression) {
    stack<char> opStack;
    queue<string> outputQueue;
    string num = "";

    for (char element : expression) {
        if (isdigit(element)) {
            num += element;
        }
        else {
            if (!num.empty()) {
                outputQueue.push(num);
                num = "";
            }

            if (element == '(') {
                opStack.push(element);
            }
            else if (element == ')') {
                while (!opStack.empty() && opStack.top() != '(') {
                    outputQueue.push(string(1, opStack.top()));
                    opStack.pop();
                }
                opStack.pop();
            }
            else if (precedence(element) > 0) {
                while (!opStack.empty() && precedence(opStack.top()) >= precedence(element)) {
                    outputQueue.push(string(1, opStack.top()));
                    opStack.pop();
                }
                opStack.push(element);
            }
        }
    }

    if (!num.empty()) {
        outputQueue.push(num);
    }

    while (!opStack.empty()) {
        outputQueue.push(string(1, opStack.top()));
        opStack.pop();
    }
    
    return outputQueue;
}


double evaluatePostfix(queue<string> postfix) {
    stack<double> evalStack;

    while (!postfix.empty()) {
        string element = postfix.front();
        postfix.pop();

        if (isdigit(element[0])) {
            evalStack.push(stod(element));
        }
        else {
            double b = evalStack.top(); evalStack.pop();
            double a = evalStack.top(); evalStack.pop();
            double result = 0;

            if (element == "+") result = add(a, b);
            else if (element == "-") result = subtract(a, b);
            else if (element == "*") result = multiply(a, b);
            else if (element == "/") result = divide(a, b);

            evalStack.push(result);
        }
    }
    return evalStack.top();
}

