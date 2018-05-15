// expression.cpp
// Implements expression methods

#include "expression.h"

string prefixString(Node* n) {

	return n->print_prefix();

}

string infixString(Node* n) {
	
	return n->print_infix();

}

string postfixString(Node* n) {
	
	return n->print_postfix();

}

