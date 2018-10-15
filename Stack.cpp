#include <iostream>
#include <string>

/*A template implementation of a stack using a linked list. The '<<' operator was also overloaded for a more convenient way of printing the stack*/

//The stack was used in this case to reverse a given string

template <class T>
struct node
{
	T data;
	node* next;

	node(T i)
	{
		data = i;
		next = NULL;
	}
};

template <class T>
class Stack
{
private:
	node<T>* top;

public:
	Stack()
		: top(NULL) {}

	void push(node<T>* n)
	{
		n->next = top;
		top = n;
	}

	node<T>* pop()
	{
		node<T>* n = top;
		top = top->next;
		return n;
	}

	friend std::ostream& operator<< (std::ostream& ostream, const Stack& stack)
	{
		node<T>* ptr = stack.top;
		while (ptr != NULL)
		{
			ostream << ptr->data << std::endl;
			ptr = ptr->next;

		}

		return ostream;
	}
};


int main() {
	Stack<char> st;
	std::string str = "Please reverse this string for me... that would be very kind!";
	//std::cin >> str;
	std::string out;
	int len = str.length();

	for (int i = 0; str[i] != '\0'; i++)
	{
		node<char>* n = new node<char>(str[i]);
		st.push(n);
	}

	std::cout << "The content of the stack is: " << st << std::endl;

	for (int i = 0; str[i] != '\0'; i++)
	{
		out += st.pop()->data;
	}

	std::cout << out << std::endl;
	std::cin.get();
	return 0;
}