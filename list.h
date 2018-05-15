// list.h
// Linked list header file

#include <cassert>
#include <cstdlib>
#include <cstring> // strcmp

#include "node.h"

using namespace std;

class List {

	public:

		// CONSTRUCTOR
		List(string Algebraic);
		
		// OBSERVER
		Node* getFirst();

	private:

		Node* first; // pointer to first node

};

