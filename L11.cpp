#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Stack {
public:
	int size() const;
	bool isEmpty() const;
	const T& top() const {
		if (isEmpty()) throw "Stiva goala\n";
		return v.back();
	}
	void push(const T& ob);
	void pop();
	vector <T> v;
};

template<typename T> bool Stack<T>::isEmpty() const {
	return (v.empty());
}

template<typename T> void Stack<T>::push(const T& ob) {
	v.push_back(ob);
}

template<typename T> void Stack<T>::pop() {
	if (isEmpty()) throw "Stiva goala\n";
	v.pop_back();
}

int main() {
	Stack <int> st;
	for (int i = 1; i <= 5
		; i++)st.push(i);
		while (!st.isEmpty()) {
			cout << st.top() << "\n";
			st.pop();
		}
	return 0;
}