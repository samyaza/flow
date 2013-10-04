#include <mutex>

template<class T>
class Node{
    private:
        Node* next;
        T data;
    public:
        Node(){};
        Node(T,Node<T>*);
    template<class U> friend class FlowQueue;
    template<class U> friend class FlowProducer;
    template<class U> friend class FlowConsumer;
};
template<class T> Node<T>::Node(T data, Node<T>* next){
    this->data = data;
    this->next = next;
}

template<class T> class FlowConsumer{
    private:
        int* _size;
		Node<T>** front;
		std::mutex* front_lock;
    public:
         FlowConsumer(int* size,Node<T>** queue_front,std::mutex* lock):_size(size), front(queue_front),front_lock(lock){};
         T get();
};

template<class T> T FlowConsumer<T>::get(){
	front_lock->lock();
    while(*_size==0);
	T ret = (*front)->data;
    Node<T>* temp = *front;	
    *front = (*front)->next;
	(*_size)--;	
	front_lock->unlock();
    delete temp;	    
    return ret;
}

template<class T> class FlowProducer{
    private:
        int* _size;
		Node<T>** back;
		std::mutex* back_lock;
    public:
         FlowProducer(int* size,Node<T>** queue_back,std::mutex* lock):_size(size),back(queue_back),back_lock(lock){};
         void put(T data);
};

template<class T> void FlowProducer<T>::put(T data){
	back_lock->lock();
    (*back)->data = data;
    (*back)->next = new Node<T>();
    *back = (*back)->next;	
    (*_size)++;	
	back_lock->unlock();
}
template<class T>class FlowQueue{     
    private:
        Node<T>* front;
        Node<T>* back;
        int _size;
		std::mutex front_lock;
		std::mutex back_lock;
    public:
        FlowQueue();
        ~FlowQueue();
        bool isEmpty(){return (this->_size == 0)? true : false;}
        int size(){return this->_size;}  
        FlowProducer<T> get_producer(){return FlowProducer<T>(&_size,&back,&back_lock);}
        FlowConsumer<T> get_consumer(){return FlowConsumer<T>(&_size,&front,&front_lock);}
};
template<class T> FlowQueue<T>::FlowQueue(){
    _size = 0;
    front = new Node<T>();
    back = front;
}
template<class T> FlowQueue<T>::~FlowQueue(){
    while(_size>=0){
        Node<T>* temp = front;			
        front = front->next;
		delete temp;
        _size--;
    }	
}