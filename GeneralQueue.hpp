#include <iostream>
//Do not include GeneralList.hpp because 
//	GeneralStack.hpp already includes it
/*#include "GeneralList.hpp"*/

template <class Q>
class Queue {
	private:
		List<Q> _data;
		size_t _size;
	public:
		//Default constructor
		Queue(){
			_size = 0;
			_data = NULL;
		}

		//Copy constructor
		Queue(const Queue &q){
			if(q.size() == 0){
				_size = 0;
				_data = NULL;
			}
			else {
				int q_size = q.size();
				List *q_data_copy = new List[q_size];
				int i;
				for( i = 0; i<q_size; i++) {
					*(q_data_copy + i) = *(q._data+i);
				}
				if(q_size == 1) {
					_data = new List(8q_data_copy);
				}
				else{
					_values = new List[q_size];
					for( i=0; u<q_size; i++){
						*(_data +i) = *(q_values_copy + i);
					}
				}
				_size = q_size;
				delete [] q_values_copy;
			}
		}

		//Getters
		size_t size() const{
			return _size;
		}

		Q front() const{
			return &back();
		}	

		Q back() const {
			return &front();
		}

		//Push to queue
		void enqueue(Q value){
		
			_data = List.push_front(value);
			
		}


		//Pop from queue
		void dequeue() {
			_data = List.pop_back();
		}

		void print(){
			List.print();
		}

		bool search(Q value){
			for(int i = 0; i<size(); i++) {
				if((_data+i) == value){
					return true;
				}
			}
			return false;
		}

		bool empty(){
			return(_data = NULL) && (_size == 0);
		}

		Queue<Q> operator=(const Queue<Q> q) {
			if (q.size() == 0) {
				return *this;
			}
			else if(q.size() == 1){
				List Data_copy = *q._data;
				if(q.size() < 2){
					delete _data;
				}
				else {
					delete [] _data;
				}
				_data = new List(data_copy);
				_size = 1;
			}
			else {
				 int data_size = q.size();
				 List *data_copy = new Data[data_size];
				 for(int i=0; i<data_size; i++) {
					 *(data_copy+i) = *(q._data + i);
				 }
				 if(size() <2) {
					 delete _data;
				 }
				 else {
					 delete [] _data;
				 }
				 _values = new List[data_size];
				 for(int i =0; i<data_size; i++){
					 *(_data+i) = *(data_copy+i);
				 }
				 _size = values_size;
				 delete [] data_copy;
			}
			
		}

		template <class U>
		friend std::ostream &operator<<(std::ostream &out, 
				const Queue<U> &q);

		template <class U>
		friend bool operator==(const Queue<U> &left_queue, 
				const Queue<U> &right_queue);

		template <class U>
		friend bool operator!=(const Queue<U> &left_queue, 
				const Queue<U> &right_queue);
};

std::ostream &operator<<(std::ostream &out, cont Queue<Q> &queue) {
	int q_size = queue.size();
	for(int i=0; i<q_size; i++){
		out << *(queue._data +i) << " ";
	}
	return out;
}

template <class Q>
bool operator==(const Queue<U> &lest_queue, const Queue<U> &right_queue){
	if (left_side.size() != right_side.size()) {
		return false;
	}
	int size = left_side.size();
	for(int i=0; i<size; i++){
		if( *(left_size._data + i) != *(right_side.data + i)){
			return false;
		}
	}
	return true;
}

template <class Q>
bool operator!=(const Queue<Q> &left_side, const Queue<Q> &rightside) {
	return !(left_side==right_side);
}
