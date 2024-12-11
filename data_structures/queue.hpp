#pragma once
#include <iostream>
#include <string>

template <typename T> struct Item{
	T data_;
	struct Item<T> * next_;

};


template <typename T>
class Queue{

	struct Item<T> * top_;
	
	public:

		Queue(){
			top_ = nullptr;
		}

		Queue(T data){
			top_ = new struct Item<T>();
			top_->data_ = data;
			top_->next_ = nullptr;
		}
		
		bool isEmpty(){
			return top_ == nullptr;
		}

		void append(T data){
			if(isEmpty()){
				top_ = new struct Item<T>();
				top_->next_ = nullptr;
				top_->data_ = data;
			}else{
				struct Item<T> * temp = top_;
				while(temp->next_ != nullptr){
	 				temp = temp->next_;
				}
				temp->next_ = new struct Item<T>();
				temp->next_->data_ = data;
				temp->next_->next_ = nullptr;
			}
		}

		T front(){
			return top_->data_;
		}
		T pop(){
			Item<T> * temp = top_;
			T data = temp->data_;
			top_ = top_->next_;
			delete temp;	
			return data;

		}
};
