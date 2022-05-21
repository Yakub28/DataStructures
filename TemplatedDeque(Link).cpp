#include <iostream>
#include <stdexcept>

template<class T>
struct Node{
    T value;
    Node<T> *next;
    Node<T> *prev;
    
    Node<T>(T _value, Node<T> *_next=nullptr, Node<T> *_prev=nullptr):value(_value), next(_next), prev(_prev){
        
    }
};

template<class T>
class Deque{
 Node<T>* head;
 Node<T>* tail;
 int elements;
 
 public:
 Deque():head(nullptr),tail(nullptr), elements(0){
     
 }
 
 //copy constructor  
  Deque(const Deque& original):head(nullptr), tail(nullptr){
    if(!original.empty())
    elements=original.elements;
    head=new Node<T>(original.head->value);
    tail=head;
    
    Node<T> *src=original.head->next;
    Node<T> *dst=head;

    while(src!=nullptr){
    dst->next=new Node<T>(src->value);
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
 void push_front(T x){
     if(empty()){
         head=new Node<T>(x);
         tail=head;
     }
     else{
     Node<T> *tmp=new Node<T>(x);
     head->prev=tmp;
     tmp->next=head;
     head=tmp;}
     elements++;
 }
 
 void push_back(T x){
     if(empty()){
         tail=new Node<T>(x);
         head=tail;
     }
     else{
     Node<T> *tmp=new Node<T>(x);
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
T front(){
    return head->value;
}

T back(){
    return tail->value;
}
//print the whole deque
void print(){
    if(empty()){
        throw std::runtime_error("print called for the empty");
    }
    Node<T> *tmp=head;
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
    cpy.head=new Node<T>(head->value);
    cpy.tail=cpy.head;
    
    Node<T>* src=head->next;
    Node<T>* dst=cpy.head;
    
    while(src!=nullptr){
        dst->next=new Node<T>(src->value);
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
    Deque<int> c;
    c.push_back(5);
    c.push_front(1);
    c.push_front(5);
    c.push_back(99);
    std::cout<<c.front()<<"\n";
     std::cout<<c.back()<<"\n";
    c.print();
    std::cout<<c.size()<<'\n';
    
    
    Deque<double> d;
    d.push_back(2.3);
    d.push_front(3.2);
    d.push_front(5.5);
    std::cout<<d.front()<<'\n';
    std::cout<<d.back()<<'\n';
    d.print();
    
    Deque<char> ch;
    ch.push_back('c');
    ch.push_front('d');
    ch.push_front('k');
    std::cout<<ch.front()<<'\n';
    std::cout<<ch.back()<<'\n';
    ch.print();
    return 0;
}

