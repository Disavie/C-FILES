#pragma once

template <typename T>
struct Node{

    T data_;
    Node<T> * next_;

};

template <typename T>
class ForwardList{


    Node<T> * head_;

    public:
        ForwardList(){
            head_ = nullptr;
        }
    
        ForwardList(T data){
            head_ = new Node<T>();
            head_->data_ = data;
            head_->next_ = nullptr;
        }

        bool isEmpty(){
            return head_ == nullptr;
        }

        void clear(){
            Node<T> * temp;
            while(!isEmpty()){
                temp = head_;
                head_ = temp->next_;
                delete temp;
            }
        }

        size_t size(){
            size_t count = 1;
            Node<T> * temp = head_;
            while(temp != nullptr){
                temp = temp->next_;
                count++;
            }
            return count;
        }


        void push_back(T data){
            Node<T> * temp = new Node<T>();
            Node<T> * pointer = head_;
            temp->data_ =data;
            temp->next_ =nullptr;
            if(isEmpty()){
                head_ = temp;
            }else{
                while(pointer->next_ != nullptr){
                    pointer = pointer->next_;
                }
                pointer->next_ = temp;
            }
        }

        T remove(int index){
            Node<T> * temp = head_;
            Node<T> * previous = temp;
            //Special case removing head_
            if(index == 0){
                head_ = head_->next_;
                return temp->data_;
            }
            int count = 0;
            while(count != index){
                previous = temp;
                temp = temp->next_;
                count++;
            }
            previous->next_ = temp->next_;
            T data = temp->data_;
            delete temp;
            return data;
        }


        T at(int index){ 
            int count = 0;
            Node<T> * temp = head_;

            while(count !=index){
                temp = temp->next_;
                count++;
            }
            return temp->data_;
        }


        T operator[](int  index){
            int count = 0;
            Node<T> * temp = head_;

            while(count !=index){
                temp = temp->next_;
                count++;
            }
            return temp->data_;
        }
};
