#include <iostream>
#include <stdexcept>
template<class T>
struct Node{
  T value;
  Node<T>* next;
  
  Node(T _value,Node<T>* _next=nullptr):value(_value),next(_next){
      
  }
};
template<class T>
class Queue{
    Node<T> *head;
    Node<T> *tail;
    int elements;

    public:
    //constructor
    Queue():head(nullptr), tail(nullptr), elements(0){};

    void push(T x){
        if(empty()){
            head=new Node<T>(x);
            tail=head;
        }
        else{
            tail->next=new Node<T>(x);
            tail=tail->next;
        }
            elements++;
    }
    bool empty() const{
        if(head==nullptr&&tail==nullptr){
            return true;
        }
        else{
            return false;
        }
    }
    T back() const{
        if(empty()){
            throw std::runtime_error("called ont the empty queue");
        }
        return tail->value;
    } 
    T front()const{
        if(empty()){
            throw std::runtime_error("called on teh empty queue");
        }
        return head->value;
    }

    void pop(){
        if(empty()){
            throw std::runtime_error("pop is called for the empty queue");
        }
        elements--;
    }
    //prints the whole queue
    void print(){
        if(empty()){
            throw std::runtime_error("print called for the empty ");
        }
        Node<T>* tmp=head;
        while(tmp!=nullptr){
            std::cout<<tmp->value<<" ";
            tmp=tmp->next;
        }
        std::cout<<std::endl;
    }
    //returns the number of the elements
    int size(){
        return elements;
    }
    void clear(){
        while(!empty()){
            pop();
        }
    }
     ~Queue(){
         clear();
     }

     Queue(const Queue& original):head(nullptr), tail(nullptr){
         if(!original.empty())
         elements=original.elements;

         //copy the first value of the original if it exists
         head=new Node<T>(original.head->value);
         tail=head;

         Node<T>* src=original.head->next;
         Node<T>* dst=head;

         while(src!=nullptr){
             //crate a new node with the value from the src and save its pointer to dst->next
             dst->next=new Node<T>(src->value);
             tail=dst->next;
            
            //move both pointers
            dst=dst->next;
            src=src->next;
         }
     }
    //assignment operator 
    Queue& operator=(Queue cpy){
        clear();
        //copying the number of the elements
        cpy.elements=elements;

        //copy the first value of the original if it is exists
        cpy.head=new Node<T>(head->value);
        cpy.tail=cpy.head;

        Node<T>* src=head->next;
        Node<T>* dst=cpy.head;

        while(src!=nullptr){
            dst->next=new Node<T>(src->value);
            cpy.tail=dst->next;

            //moving both the pointers
            dst=dst->next;
            src=src->next;
        }
       return *this; 
    }
    void operator+(int x){
        head=new Node<T>(x, head);
        elements++;
    }
};


int main()
{
    
    
    return 0;
}