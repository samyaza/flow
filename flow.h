#include <iostream>

using namespace std;

template<class T>
class Node{
    private:
        Node* next;
        T data;
    public:
        Node();
        Node(T,Node<T>*);
        T getData(){return data;}
        void setData(T data){this->data = data;}
        Node* getNext(){return next;}
        void setNext(Node *next){this->next = next;}
};
template<class T> Node<T>::Node(){
}
template<class T> Node<T>::Node(T data, Node<T>* next){
    this->data = data;
    this->next = next;
}
template<class T>
class BaseQueue{    
    private:
        Node<T>* front;
        Node<T>* back;
        int _size;
    public:
        BaseQueue();
        ~BaseQueue();
        virtual T get();
        virtual void put(T data);
        bool isEmpty(){return (this->_size == 0)? true :  false;}
        int size(){return this->_size;}        
};
template<class T> BaseQueue<T>::BaseQueue(){
//    front = new Node<T>();
//    front->setData(0);
//    front->setNext(front);
//    back = front;
    _size = 0;
}
template<class T> BaseQueue<T>::~BaseQueue(){
    while(_size>0 && this->get());
}
template<class T> void BaseQueue<T>::put(T data){
    if(this->isEmpty()){
        front = new Node<T>(data,back);
        back = front;
    } 
    else{
        back->setNext(new Node<T>(data,0));
        back = back->getNext();
    }
    _size++;
}
template<class T> T BaseQueue<T>::get(){
    while(_size==0);
    T ret = front->getData();
    Node<T>* temp = front;
    front = front->getNext();
    delete temp;
    _size--;
    return ret;
}