
// First, get the declaration for the base stack class
#include "Stack.h"

// This is the declaration for AStack.
// Array-based stack implementation
template <typename E> class AStack: public Stack<E> {
private:
  int maxSize;										// Maximum size of stack
  int top;											// Index for top element
  E *listArray;										// Array holding stack elements

public:
  AStack(int size = 0)								// Constructor
    { maxSize = size; top = 0; listArray = new E[size]; }

  ~AStack() { delete [] listArray; }				// Destructor

  void clear() { top = 0; }							// Reinitialize

  void push(const E& it) {							// Put "it" on stack
	  if (top == maxSize) {
		  cout << "\nARRAY STACK IS FULL" << endl << endl;
	  }
	  else {
		  listArray[top++] = it;
	  }
  }

  E pop() {											// Pop top element
	  if (top == 0) {
		  cout << "\nARRAY STACK IS EMPTY" << endl << endl;
	  }
	  else {
		  cout << "\nItem has been popped from the ARRAY STACK" << endl << endl;
		  return listArray[--top];
	  }
  }

  const E& topValue() const {						// Return top element
	  if (top == 0) {
		  cout << "\nARRAY STACK IS EMPTY" << endl << endl;
	  }
	  else {
		  cout << "\nItem " << listArray[top - 1] << " is at the top of the ARRAY STACK" << endl << endl;
		  return listArray[top - 1];
	  }
  }

  int length() const { return top; }				// Return length

  void print() {									// Print list contents
	  if (top == 0) {
		  cout << "\nARRAY STACK IS EMPTY"<< endl << endl;
	  }
	  else {
		  	  cout << "\n\t<" << listArray[top-1];
	  for (int i = top-2; i > -1; i--) {
		  cout << ", " << listArray[i];
	  }
	  cout << ">" << endl << endl;
	  }

  }
};
