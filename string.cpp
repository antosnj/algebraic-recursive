// string.cpp
// Implements main function

// ASKS THE USER FOR INPUT STRING AND IMPLEMENTS A LIST FOR
// THAT STRING USING THE NODE CLASS AND GETS THE FIRST NODE
// AND THEN OUTPUTS THE RESULT OF THE PREFIX, POSTFIX AND
// INFIX EXPRESSIONS

#include "string.h"

using namespace std;

int main() {

    string Algebraic;
	string prefix;
    Node* first;
	int i;

    cout << "\nInsert an expression: \n" << endl;
    cin >> Algebraic;
    
    List List(Algebraic);
    first = List.getFirst();

    cout << "\nPrefix expression: " << endl;
    cout << prefixString(first) << endl;

    cout << "\nPostfix expression: " << endl;
    cout << postfixString(first) << endl;

    cout << "\nInfix expression: " << endl;
    cout << infixString(first) << endl;
	cout << "\n";

    return 0;

}
