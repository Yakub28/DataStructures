#include <iostream>
#include <stdexcept>

struct Node{
    int value;
    Node *next;
    Node *prev;
    
    Node(int v):value(v), next(nullptr), prev(nullptr){
        
    }
};

class Deque{
 Node* head;
 Node* tail;
 int elements;
 
 public:
 Deque():head(nullptr),tail(nullptr), elements(0){
     
 }
 
 //copy constructor  
  Deque(const Deque& original):head(nullptr), tail(nullptr){
    if(!original.empty())
    elements=original.elements;
    head=new Node(original.head->value);
    tail=head;
    
    Node *src=original.head->next;
    Node *dst=head;

    while(src!=nullptr){
    dst->next=new Node(src->value);
    tail=dst->next;
    tail->prev=dst;

    dst=dst->next;
    src=src->next;
 }
 }
 bool empty()const{
     if(head==nullptr&&tail==nullptr){
         return true;}
         else{ 
         return false;
     }}
 void push_front(int x){
     if(empty()){
         head=new Node(x);
         tail=head;
     }
     else{
     Node *tmp=new Node(x);
     head->prev=tmp;
     tmp->next=head;
     head=tmp;}
     elements++;
 }
 
 void push_back(int x){
     if(empty()){
         tail=new Node(x);
         head=tail;
     }
     else{
     Node *tmp=new Node(x);
     tail->next=tmp;
     tmp->prev=tail;
     tail=tmp;}
     elements++;
 }
 
 
 void pop_back(){
     if(head!=nullptr&&head==tail)
    {head=nullptr;
     tail=nullptr;}
     else if(empty())
     throw std::runtime_error("called for the empty deque");
     else{
     tail=tail->prev;
     tail->next=nullptr;}
     elements--;
 }
void pop_front(){
    if(empty()){
        throw std::runtime_error("pop_front called for empty deque");
    }
    else if(head!=nullptr&&head==tail){
        head=nullptr;
        tail=nullptr;
    }
    else{
        head=head->next;
        head->prev=nullptr;
    } 
    elements--;
}
void clear(){
    while(not empty())
    pop_back();
}
int front(){
    return head->value;
}

int back(){
    return tail->value;
}
//print the whole deque
void print(){
    if(empty()){
        throw std::runtime_error("print called for the empty");
    }
    Node *tmp=head;
    while(tmp!=nullptr){
        std::cout<<tmp->value<<" ";
        tmp=tmp->next;
    }
    std::cout<<'\n';
}
int size(){
    return elements;
}
//assignment operator
Deque &operator=(Deque cpy){
    clear();
    
    //copy the amount of the elements
    cpy.elements=elements;
    //copy the first value of the original
    cpy.head=new Node(head->value);
    cpy.tail=cpy.head;
    
    Node* src=head->next;
    Node* dst=cpy.head;
    
    while(src!=nullptr){
        dst->next=new Node(src->value);
        cpy.tail=dst->next;
        tail->prev=dst;
        
        dst=dst->next;
        src=src->next;
    }
    return *this;
}

~Deque(){
    clear();
}
};

int main()
{
    Deque c;
    c.push_back(5);
    c.push_front(1);
    c.push_front(5);
    c.push_back(99);
    std::cout<<c.front()<<"\n";
     std::cout<<c.back()<<"\n";
    c.print();
    std::cout<<c.size();
    return 0;
}

