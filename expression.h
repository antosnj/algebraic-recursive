// expression.h
// expression methods header file

#include <string>
#include <iostream>
#include <cstdlib>
#include <cassert>

#include "list.h"

using namespace std;

string prefixString(Node* n);
string infixString(Node* n);
string postfixString(Node* n);
