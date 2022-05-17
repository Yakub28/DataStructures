#include <iostream>

template<class T>
struct Node{
    T value;
    Node<T> *next;
    
    Node<T>(T v, Node<T> *n=nullptr):
    value(v), next(n){}
};

template<class T>
class Stack{
    Node<T> *head;
    public:
    Stack():head(nullptr){}

    bool empty(){
        return (head==nullptr);
    }
    
    void push(T v){
        head=new Node<T>(v, head);
    }
    void pop(){
        Node<T> *tmp=head;
        head=head->next;
        delete tmp;
    }
    T top(){
        return head->value;
    }
    
    ~Stack(){
        while(!empty()){
            pop();
        }
    }
};



int main()
{ 
    Stack<int> stack_of_ints;
    Stack<double> stack_of_doubles;
    
    stack_of_doubles.push(2);
    std::cout<<stack_of_doubles.top()<<std::endl;
    
    Stack<char> stack_of_char;
    stack_of_char.push('s');
    std::cout<<stack_of_char.top();
     
    return 0;
}
