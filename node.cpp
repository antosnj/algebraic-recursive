// node.cpp
// Implements Node class

#include "node.h"

// CONSTRUCTORS
Node::Node(char var, Node* parent) {
	this->node_t = VARIABLE;
	this->data.var = var;
	this->operand1 = NULL;
	this->operand2 = NULL;
	this->parent = parent;
}

Node::Node(operator_type op, Node* operand1, Node* operand2, Node* parent) {
	this->node_t = EXPRESSION;
	this->data.op = op;
	this->operand1 = operand1;
	this->operand2 = operand2;
	this->parent = parent;
}

Node::Node(int val, Node* parent) {
	this->node_t = INTEGER;
	this->data.val = val;
	this->operand1 = NULL;
	this->operand2 = NULL;
	this->parent = parent;
}

Node::Node() {
	this->node_t = VARIABLE;
	this->data.var = 'x';
	this->operand1 = NULL;
	this->operand2 = NULL;
	this->parent = NULL;
}

// MODIFIERS
void Node::setOperand1(Node* operand1) {
	this->operand1 = operand1;
}

void Node::setOperand2(Node* operand2) {
	this->operand2 = operand2;
}

void Node::setParent(Node* parent) {
	this->parent = parent;
}

void Node::setOperator_type(operator_type op) {
	this->data.op = op;
}


// OBSERVERS
node_type Node::getNode_t() {
	if (this->node_t == EXPRESSION)
		return EXPRESSION;
	if (this->node_t == VARIABLE)
		return VARIABLE;
	if (this->node_t == INTEGER)
		return INTEGER;
}

data_type Node::getData() {
	return this->data;
}

char Node::getOp() const {
	char op;

	if (this->data.op == PLUS)
		op = '+';
	else if (this->data.op == MINUS)
		op = '-';
	else if (this->data.op == MULT)
		op = '*';
	else if (this->data.op == DIVIDE)
		op = '/';

	return op;
}

char Node::getVar() const {
	char var;

	var = this->data.var;

	return var;
}

char Node::getVal() const {
	char val;

	val = this->data.val + '0';

	return val;
}

Node* Node::getOperand1() {
	return this->operand1;
}

Node* Node::getOperand2() {
	return this->operand2;
}

Node* Node::getParent() {
	return this->parent;
}


// PRINTING METHODS
string Node::print_prefix() {

	string prefix("");

	if (this->node_t == INTEGER)
		prefix += this->data.val + '0';
	else if (this->node_t == VARIABLE)
		prefix += this->data.var;
	else if (this->node_t == EXPRESSION) {
		prefix += this->getOp();
		prefix += this->getOperand1()->print_prefix();
		prefix += this->getOperand2()->print_prefix();
	}

	return prefix;

}

string Node::print_postfix() {

	string postfix("");

	if (this->node_t == EXPRESSION) {
		postfix += this->getOperand1()->print_postfix();
		postfix += this->getOperand2()->print_postfix();
		postfix += this->getOp();
	}
	else if (this->node_t == INTEGER)
		postfix += this->data.val + '0';
	else if (this->node_t == VARIABLE)
		postfix += this->data.var;

	return postfix;

}

string Node::print_infix() {

	string infix("");

	if (this->node_t == EXPRESSION) {
		infix += '(';
		infix += this->getOperand1()->print_infix();
		infix += this->getOp();
		infix += this->getOperand2()->print_infix();
		infix += ')';
	}
	else if (this->node_t == INTEGER)
		infix += this->data.val + '0';
	else if (this->node_t == VARIABLE)
		infix += this->data.var;
	
	return infix;

}


