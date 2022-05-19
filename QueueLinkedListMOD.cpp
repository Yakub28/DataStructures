#include <iostream>
#include <stdexcept>

struct Node{
  int value;
  Node* next;
  
  Node(int _value,Node* _next=nullptr):value(_value),next(_next){
      
  }
};

class Queue{
    Node *head;
    Node *tail;
    int elements=0;

    public:
    //constructor
    Queue():head(nullptr), tail(nullptr){};

    void push(int x){
        if(empty()){
            head=new Node(x);
            tail=head;
        }
        else{
            tail->next=new Node(x);
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
    int back() const{
        if(empty()){
            throw std::runtime_error("called ont the empty queue");
        }
        return tail->value;
    } 
    int front()const{
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
        Node* tmp=head;
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
         head=new Node(original.head->value);
         tail=head;

         Node* src=original.head->next;
         Node* dst=head;

         while(src!=nullptr){
             //crate a new node with the value from the src and save its pointer to dst->next
             dst->next=new Node(src->value);
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
        cpy.head=new Node(head->value);
        cpy.tail=cpy.head;

        Node* src=head->next;
        Node* dst=cpy.head;

        while(src!=nullptr){
            dst->next=new Node(src->value);
            cpy.tail=dst->next;

            //moving both the pointers
            dst=dst->next;
            src=src->next;
        }
       return *this; 
    }
    void operator+(int x){
        head=new Node(x, head);
        elements++;
    }
};


int main()
{
    
    
    return 0;
}

