#include <iostream>
#include <stdexcept>

struct Node{
  int value;
  Node* next;
  
  Node(int _value,Node* _next=nullptr):value(_value),next(_next){
      
  }
};

class Stack{
    Node *head;
    public:
    Stack():head(nullptr){}
    
    void push(int x){
        // Node *tmp=new Node;
        // tmp->next=head;   if we  dont have constructor
        // head=tmp;
        head=new Node(x, head);
    }
    bool empty()constexpr{
        return(head==nullptr);
    }
    int top()const{
        if(empty()){
            throw std::runtime_error("called on an empty");
        }
        return head->value;
    }
    void pop(){
        if(empty()){
            throw std::runtime_error("called on an empty");
        }
        // Node *tmp=head;
        // head=head->next;
        // delete tmp;
        pop_unsafe();
    }
    void clear(){
        while(!empty()){
            // pop();
            pop_unsafe();
        }
    }
    ~Stack(){
        clear();
    }
    
    // Stack(const Stack &original):head(nullptr){
    //     if(original.empty()){
    //         //copy the first value
    //         head=new Node(original.head->value);
    //         //iteration through both stacks
    //         Node *dst=head;
    //         Node *src=original.head->next;
    //         while(src!=nullptr){
    //             //copies all but the first element
    //             dst->next=new Node(src->value);
    //             //move src and dst pointers to next elements
    //             src=src->next;
    //             dst=dst->next;
    //         }
    //     }
    // }
    Stack(const Stack &original):head(nullptr){
        Node *src=original.head;
        Node **dst=&head;
        
        while(src!=nullptr){
                //copies all but the first element
                (*dst)->next=new Node(src->value);
                //move src and dst pointers to next elements
                src=src->next;
                dst=&((*dst)->next);
    }
    Stack &operator=(Stack cpy){
        std::swap(cpy.head, head);
        return *this;
    }
    
    private:
    void pop_unsafe(){
        Node *tmp=head;
        head=head->next;
        delete tmp;
    }
};

int main()
{
    // Node* head=nullptr;
    // head->next=1;
    
    // head->next=new Node;
    // head->next->value=2;
    
    
    
    // Node* head=nullptr;
    // for(int i=4;i>=1;i--)
    // {
    //     Node *tmp=new Node;
    //     tmp->value=i;
    //     tmp->next=head;
    //     head=tmp;
    // }
    // //insertion
    // std::cout<<head->value<<std::endl;
    // Node *tmp=head;
    // while(tmp!=nullptr){
    //     std::cout<<tmp->value<<", ";
    //     tmp=tmp->next;
    // }
    // //poping at the head
    // if(head!=nullptr)    
    // {
    // Node *tmp=head;
    // head=head->next;
    // delete tmp;
    // }
    // while(head!=nullptr)    
    // {
    // Node *tmp=head;
    // head=head->next;
    // delete tmp;
    // }
    
    return 0;
}
