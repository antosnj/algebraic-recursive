// list.cpp
// Implements class List

#include "list.h"

using namespace std;

// CONSTRUCTOR
List::List(string algebraic) {

	int i;

	Node* current;

	Node* expr = new Node(PLUS, NULL, NULL, NULL);
	this->first = expr;		// first node
	current = expr;			// current

	for (i=1; i<algebraic.length(); i++) {

		if (algebraic[i] == '(') {
			Node* expr = new Node(PLUS, NULL, NULL, current);	// sets operator_type and both operands to default, and parent to current
			if (current->getOperand1() == NULL)
				current->setOperand1(expr);
			else if (current->getOperand2() == NULL)
				current->setOperand2(expr);
			current = expr;
		}


		else if (algebraic[i] == '+') {			// set Operator type to PLUS
			current->setOperator_type(PLUS);
		}
		else if (algebraic[i] == '-') {			// set Operator type to MINUS
			current->setOperator_type(MINUS);
		}
		else if (algebraic[i] == '*') {			// set Operator type to MULT
			current->setOperator_type(MULT);
		}
		else if (algebraic[i] == '/') {			// set Operator type to DIVIDE
			current->setOperator_type(DIVIDE);
		}

		else if (algebraic[i] == 'x') {
			Node *var = new Node(algebraic[i], current);	// new Node type Variable
			current->setOperand1(var);	// always in operand 1
		}

		else if ((algebraic[i] >= '0') && (algebraic[i] <= '9')) {
			int number = algebraic[i] - '0';	// pass from char to int
			Node *val = new Node(number, current);			// new Node type Integer
			current->setOperand2(val);	// always in operand 2
		}


		else if (algebraic[i] == ')') {
			current = current->getParent();
		}

	}

}

// OBSERVER
Node* List::getFirst() {
	return this->first;
}
