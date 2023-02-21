
#include "Link.h"							// Include the link class
#include "Stack.h"							// Declare base stack class

// This is the declaration for LStack
// Linked stack implementation
template <typename E> class LStack: public Stack<E> {
private:
  Link<E>* top;								// Pointer to first element
  int size;									// Number of elements

public:
  LStack(int sz = 0)						// Constructor
  {top = NULL; size = 0;}

  ~LStack() { clear(); }					// Destructor

  void clear() {							// Reinitialize
    while (top != NULL) {					// Delete link nodes
      Link<E>* temp = top;
      top = top->next;
      delete temp;
    }
    size = 0;
  }

  void push(const E& it) {					// Put "it" on stack
    top = new Link<E>(it, top);
    size++;
  }

  E pop() {									// Remove "it" from stack
	  if (top == 0) {
		  cout << "\nLINKED STACK IS EMPTY" << endl << endl;
	  }
	  else {
		  cout << "\nItem has been popped from the LINKED STACK" << endl << endl;
		  E it = top->element;
		  Link<E>* ltemp = top->next;
		  delete top;
		  top = ltemp;
		  size--;
		  return it;
	  }
  }

  const E& topValue() const {				// Return top value
	  if (top == 0) {
		  cout << "\nLINKED STACK IS EMPTY" << endl << endl;
	  }
	  else {
		  cout << "\nItem " << top->element << " is at the top of the LINKED STACK" << endl << endl;
		  return top->element;
	  }
  }

  int length() const { return size; }		// Return length

  // Print list contents
  void print() {
	  if (top == 0) {
		  cout << "\nLINKED STACK IS EMPTY" << endl << endl;
	  }
	  else {	
		  cout << "\nPopping the following items:" << endl;
		  cout << "\t<" << top->element;
		  Link<E>* ltemp = top->next;
		  delete top;
		  top = ltemp;
		  size--;
		  for (int i = size; i > 0; i--) {
			  Link<E>* ltemp = top->next;
			  cout << ", " << top->element;
			  delete top;
			  top = ltemp;
			  size--;
		  }
		  cout << ">" << endl << endl;
	  }
  }
};
