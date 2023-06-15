#include <iostream>
#include <string>

using namespace std;

class program {
private:
	string stack_array[5];
	int top;

public:
	program() {
		top = -1;
	}

	string push(string element) {
		if (top == 4) {
			cout << "Stack Full" << endl;
			return "";
		}

		top++;
		stack_array[top] = element;
		cout << endl;
		cout << element << "Ditambahkan(pushed)." << endl;

		return element;
	}

	void pop() {
		if (empty()) {
			cout << "\nStack Is Empty. Cannot POP." << endl;
			return;
		}
		cout << "\nThe POPed Elemenet Is: " << stack_array[top] << endl;
		top--;
	}

	bool empty() {
		return (top == -1);
	}

	void display() {
		if (empty()) {
			cout << "\nStack Is Empty." << endl;
		}
		else {
			for (int tmp = top; tmp >= 0; tmp--) {
				cout << stack_array[tmp] << endl;
			}
		}
	}
};

int main() {
	program s;
	
	while (true) {
		cout << endl;
		cout << "\n***Stack Menu***\n";
		cout << "1. Push\n";
		cout << "2. POP\n";
		cout << "3. Display\n";
		cout << "4. Exit\n";
		cout << "\nEnter Yout Choice: ";
		string input;
		getline(cin, input);
		char ch = (input.empty() ? '0' : input[0]);
		switch (ch) {
		case '1': {
			cout << "\nEnter an Element: ";
			string element;
			getline(cin, element);
			s.push(element);
			break;
		}
		case '2':
			if (s.empty()) {
				cout << "\nStack Is Empty" << endl;
				break;
			}
			s.pop();
			break;
		case '3':
			s.display();
			break;
		case '4':
			return 0;
		default:
			cout << "\nInvalid Choice." << endl;
			break;
		}

	}
}