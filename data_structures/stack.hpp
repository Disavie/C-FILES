#pragma once

template<typename T>
struct Page{
	T data;
	Page<T> * next_;
};

#include <stdexcept>

template <typename T>
class Stack{
	struct Page<T> * top_;

	public:
			
		Stack(){
			top_ = nullptr;
		}


		Stack(T data){
			top_ = new struct Page<T>;
			top_->data = data;
			top_->next_ = nullptr;
		}

		bool isEmpty(){
			return top_ == nullptr;
		}
		
		void  push(T data){
			struct Page<T> * temp = new struct Page<T>();
			temp->data = data;
			temp->next_ = top_;
			top_ = temp;	
		}
		
		T peek(){
			return top_->data;
		}

		T pop(){
			if(isEmpty()){
				throw std::out_of_range("Stack is empty");
			}
			T data = top_->data;
			Page<T> * temp = top_;
			top_ = top_->next_;
			delete temp;
			return data;
		
		}
};
