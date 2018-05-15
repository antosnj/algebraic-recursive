// node.h
// Node header file

#ifndef NODE_H
#define NODE_H

#include <cstddef>
#include <iostream>

using namespace std;

enum node_type{EXPRESSION, VARIABLE, INTEGER};
enum operator_type{PLUS, MINUS, MULT, DIVIDE};

union data_type {
    operator_type op;
    char var;
    int val;
};

class Node {

	public:

		// CONSTRUCTORS
        Node(char var = 'x', Node* parent = NULL);														 // declaring node type Variable
        Node(operator_type op = PLUS, Node* operand1 = NULL, Node* operand2 = NULL, Node* parent = NULL);// declaring node type Expression
        Node(int val = 0, Node* parent = NULL);															 // declaring node type Integer
		// General Contructor (for auxilary nodes)
		Node();

		// MODIFIERS
		void setOperand1(Node* operand1);
		void setOperand2(Node* operand2);
		void setParent(Node* parent);
		void setOperator_type(operator_type);

		// OBSERVERS
		node_type getNode_t();
		data_type getData();
		char getOp() const;
		char getVar() const;
		char getVal() const;
		Node* getOperand1();
		Node* getOperand2();
		Node* getParent();

		// PRINTING METHODS
        string print_prefix();
        string print_infix();
        string print_postfix();		

    private:

        node_type node_t;
        data_type data;
        Node* operand1;
        Node* operand2;
		
		Node* parent;

};

#endif
