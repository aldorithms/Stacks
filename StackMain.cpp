#include <cstdlib>					// EXIT_SUCCESS
#include <cctype>					// toupper
#include <stdio.h>					//
#include <string>
#include "Stack.h"
#include "AStack.h"
#include "LStack.h"

// Prototype functions
void insertTestData(AStack<int> &, AStack<double> &, AStack<char> &, LStack<int> &, LStack<double> &, LStack<char> &);
void promptLoop(AStack<int> &, AStack<double> &, AStack<char> &, LStack<int> &, LStack<double> &, LStack<char> &);
template <typename E>
void stackChoice(Stack<E> &, char&, string &);


int main() {
	const int NUM_STACK = 10;
	AStack<int> AS1(NUM_STACK);
	AStack<double> AS2(NUM_STACK);
	AStack<char> AS3(NUM_STACK);

	LStack<int> LS1(NUM_STACK);
	LStack<double> LS2(NUM_STACK);
	LStack<char> LS3(NUM_STACK);

	insertTestData(AS1, AS2, AS3, LS1, LS2, LS3);
	promptLoop(AS1, AS2, AS3, LS1, LS2, LS3);

	return EXIT_SUCCESS;
}

void insertTestData(AStack<int> &AS1, AStack<double> &AS2, AStack<char> &AS3, LStack<int> &LS1, LStack<double> &LS2, LStack<char> &LS3) {
	AS1.push(240);
	AS1.push(260);
	AS1.push(280);
	AS1.push(210);
	AS1.push(220);
	AS1.push(1200);
	
	AS2.push(201);
	AS2.push(203.50);
	AS2.push(205);
	AS2.push(205.8);
	AS2.push(206);
	AS2.push(206.5);
	
	AS3.push('a');
	AS3.push('b');
	AS3.push('C');
	AS3.push('A');
	AS3.push('B');
	AS3.push('C');
	AS3.push('x');
	AS3.push('y');
	AS3.push('z');

	LS1.push(240);
	LS1.push(260);
	LS1.push(280);
	LS1.push(210);
	LS1.push(220);
	LS1.push(1200);

	LS2.push(201);
	LS2.push(203.50);
	LS2.push(205);
	LS2.push(205.8);
	LS2.push(206);
	LS2.push(206.5);

	LS3.push('a');
	LS3.push('b');
	LS3.push('C');
	LS3.push('A');
	LS3.push('B');
	LS3.push('C');
	LS3.push('x');
	LS3.push('y');
	LS3.push('z');

	cout << "--------------- AS1 and LS1 Stack ---------------";
	AS1.print();
	cout << "--------------- AS2 and LS2 Stack ---------------";
	AS2.print();
	cout << "--------------- AS3 and LS3 Stack ---------------";
	AS3.print();	
}

void promptLoop(AStack<int> &AS1, AStack<double> &AS2, AStack<char> &AS3, LStack<int> &LS1, LStack<double> &LS2, LStack<char> &LS3) {
	char response = '\0';
	string answer = "";
	do {
		cout << "\n\t- Make a Stack Type Choice -" << endl;
		cout << "(1) <int> Array Stack" << endl;
		cout << "(2) <double> Array Stack" << endl;
		cout << "(3) <char> Array Stack" << endl;
		cout << "(4) <int> Linked Stack" << endl;
		cout << "(5) <double> Linked Stack" << endl;
		cout << "(6) <char> Linked Stack" << endl;
		cout << "(Q) QUIT" << endl;
		cin >> response;

		switch (toupper(response)) {
		case '1':
			answer = "<int> ARRAY STACK";
			stackChoice(AS1, response, answer);
			break;
		case '2':
			answer = "<double> ARRAY STACK";
			stackChoice(AS2, response, answer);
			break;
		case '3':
			answer = "<char> ARRAY STACK";
			stackChoice(AS3, response, answer);
			break;
		case '4':
			answer = "<int> LINKED STACK";
			stackChoice(LS1, response, answer);
			break;
		case '5':
			answer = "<double> LINKED STACK";
			stackChoice(LS2, response, answer);
			break;
		case '6':
			answer = "<char> LINKED STACK";
			stackChoice(LS3, response, answer);
			break;
		case 'Q':
			break;
		default:
			cerr << "\nIllegal command. Please try again." << endl;
			break;
		}
	} while (toupper(response) != 'Q');
}

template <typename E>
void stackChoice(Stack<E> &typeSelected, char &response, string &answer) {
	int integerNumber = 0;
	double doubleNumber = 0.0;
	char charLetter = '\0';
	char charChoice = response;

	do {
		cout << "\t- " << answer << " Member Function Menu -" << endl;
		cout << "(C) Clear" << endl;
		cout << "(U) Push" << endl;
		cout << "(P) Pop" << endl;
		cout << "(T) Top" << endl;
		cout << "(L) Length" << endl;
		cout << "(I) Print " << answer << endl;
		cout << "(B) BACK" << endl;
		cin >> response;
		switch (toupper(response)) {
		case 'C':
			typeSelected.clear();
			cout << "\n" << answer << " is cleared" << endl << endl;;
			break;
		case 'U':
			if (charChoice == '1' || charChoice == '4') {
				cout << "\nEnter an integer type to push" << endl;
				cin >> integerNumber;
				while (1) {
					if (cin.fail()) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "That is not an integer type. Please try again" << endl;
						cin >> integerNumber;
					}
					if (!cin.fail())
						break;
				}
				typeSelected.push(integerNumber);
			}
			else if (charChoice == '2' || charChoice == '5') {
				cout << "\nEnter a double type to push" << endl;
				cin >> doubleNumber;
				while (1) {
					if (cin.fail()) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "That is not a double type. Please try again" << endl;
						cin >> doubleNumber;
					}
					if (!cin.fail())
						break;
				}
				typeSelected.push(doubleNumber);
			}
			else if (charChoice == '3' || charChoice == '6') {
				cout << "\nEnter a char type to push" << endl;
				cin >> charLetter;
				while (!(charLetter >= 65 && charLetter <= 122)) {
					cout << "That is not a char type. Please try again" << endl;
					cin >> charLetter;
				}
				typeSelected.push(charLetter);			
			}
			break;
		case 'P':
			typeSelected.pop();
			break;
		case 'T':
			typeSelected.topValue();
			break;
		case 'L':
			integerNumber = typeSelected.length();
			cout << "\nThe length of the " << answer << " is " << integerNumber << endl << endl;
			break;
		case 'I':
			typeSelected.print();
			break;
		case 'B':
			cout << "\nReturning to previous menu" << endl;
			break;
		default:
			cerr << "\nIllegal command. Please try again." << endl;
			break;
		}
	} while (toupper(response) != 'B');
}