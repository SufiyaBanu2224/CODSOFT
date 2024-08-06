#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char op;
	int ch=1;
    while(ch!=0)
    {
	    cout << "Enter first number: ";
	    cin >> num1;
	    if(num1==0)
	    	exit(0);
	    cout << "Enter an operator (+, -, *, /): ";
	    cin >> op;
	    cout << "Enter second number: ";
	    cin >> num2;
		
	    switch (op) {
	        case '+':
	            cout << "Result: " << num1 + num2 << endl;
	            break;
	        case '-':
	            cout << "Result: " << num1 - num2 << endl;
	            break;
	        case '*':
	            cout << "Result: " << num1 * num2 << endl;
	            break;
	        case '/':
	            if (num2 != 0)
	                cout << "Result: " << num1 / num2 << endl;
	            else
	                cout << "******Error: Division by zero is not Possible\n";
	            break;
	        default:
	            cout << "*******Error: Invalid operator.\n";
	    }
	    cout<<"\nPress 0 for exit \n\tor\n";
	    
	}

    return 0;
}
