#include <iostream>
#include "GeneralList.hpp"

template <class T>
class Stack {
	private:
		List<T> _data; //does this need to be a pointer??
		size_t _size;
		
	public:
		//Default constructor
		Stack() {
			_size = 0;
			_data = NULL;
		}	

		//Default copy constructor
		Stack(const Stack &stack) {
			size_t stack_size = stack.size();
			if (stack_size == 0) {
				_size = 0;
				_data = NULL;
			}
			else {
				List *data_copy = new List[stack_size];
				int i;
				for(i=0; i<stack_size; i++) {
					*(data_copy + i) = *(stack._data +i);
				}
				if(stack_size == 1) { 
					_data = new List ( *data_copy );
				}
				else {
					_data = new List[stack_size];
					for(i=0; i<stack_size; i++) {
						_data + i = *(data_copy +i); //if data is a ptr this add *(...) around _data +i
					}
				}
				_size = s_size;
				delete [] data_copy;
			}
		}
		//Getters
		T top() const {
			return (List.&front);
		}

		size_t size() const {
			return _size;
		}

		//Adding data to the data structure
		void push(T value){
			if (empty()) {
				_data = List.push_back(value);
				_size++;
			}
			else {
				List.push_back(value);
			}
		}

		//Removing data from the data structure
		void pop(){
			if(empty()) {
				std::cout << "Could not pop an empty stack" << std::endl;
				return;
			}
			else if (size()  == 1) {
				delete _data;
				_data = NULL;
				_size = 0;
			}
			else {	
				List.pop_back();
			}
		}		
				
		void search(T value) {
			size_t stack_size = sise();
			for(int i=0; i < stack_size; i++){
				if (_data + i == value) {
					return true;
				}
			}
			return false;
		}


		bool empty() const{
			return(_data == NULL) && (_size = 0);

		void print(){
			List.print();
		}

		//This overloaded operator is empty, please implement
		Stack<T> operator=(const Stack<T> &stack) {
			size_t stack_size = stack.size();
			if(stack_size == 0) {
				while(!empty()) {
					pop();
				}
			}
			else if (stack.size == 1) {
				List data_copy = stack._data;
				if(size() < 2) {
					delete _data;
				}
				else {
					delete [] _data;
					_values = new List(data_copy);
					_size = 1;
				}
			}
			else {
				List *data_copy = new List[stack_size];
				for(int i=0; i<stack_size; i++){
					*(data_copy + i)  = *(stack._data + i);
				}
				if(size() < 2){
					delete _data;
				}
				else {
					delete [] _data;
				}
				_data = new List[stack_size];
				for(int i=0; i<stack_size; i++){
					*(_data + i) = *(data_copy +1);
				}
				size = stack_size;
				delete [] data_copy;
			}
			return *this;
		}

		template <class S>
		friend std::ostream &operator<<(std::ostream &out, const Stack<S> &stack);
		template <class S>
		friend bool operator==(const Stack<S> &left_side, const Stack<S> &right_side);
		template <class S>
		friend bool operator!=(const Stack<S> &left_side, const Stack<S> &right_side);

};


template <class S>
bool operator==(const Stack<S> &left_side, const Stack<S> &right_side) {
	if(left_side.size() != right_side.size()) {
		return false;
	}
	size_t s_size = right_side.size();
	for(int i=0; i<s_size; i++){
		if (left_side._data[i] != right_side._data[i] ){
			return false;
		}
	}
	return true;
}

template <class S>
bool operator!=(const Stack<S> &left_side, const Stack<S> &right_side) {
	return !(left_side == right_side);
}

