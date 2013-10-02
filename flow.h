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
    template<class U> friend class FlowQueue;
};
template<class T> Node<T>::Node(){
}
template<class T> Node<T>::Node(T data, Node<T>* next){
    this->data = data;
    this->next = next;
}
template<class T>class FlowQueue{  
    template<class U> friend class FlowProducer;
    private:
        Node<T>* front;
        Node<T>* back;
        int _size;
        T get();
        void put(T data);
    public:
        FlowQueue();
        ~FlowQueue();
        bool isEmpty(){return (this->_size == 0)? true :  false;}
        int size(){return this->_size;}        
};
template<class T> FlowQueue<T>::FlowQueue(){
    _size = 0;
}
template<class T> FlowQueue<T>::~FlowQueue(){
    while(_size>0)
        this->get();
}
template<class T> void FlowQueue<T>::put(T data){
    if(this->isEmpty()){
        front = new Node<T>(data,back);
        back = front;
    } 
    else{
        back->next = new Node<T>(data,0);
        back = back->next;
    }
    _size++;
}
template<class T> T FlowQueue<T>::get(){
    while(_size==0);
    T ret = front->data;
    Node<T>* temp = front;
    front = front->next;
    delete temp;
    _size--;
    return ret;
}

template<class T> class FlowProducer{
    private:
        FlowQueue* master;
    public:
         FlowProducer(FlowQueue*);
         void put(T data);
};

template<class T> void FlowProducer<T>::put(T data){
    master->put(data);
}