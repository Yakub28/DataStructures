#include <iostream>
#include <stdexcept>

class Queue{
    int capacity;
    int *mem;
    int elements;
    
    int first;
    
    public:
    Queue():capacity(10),mem(new int[capacity]),elements(0),first(0){
        
    }
    bool empty(){
        return elements==0;
    }
    Queue(const Queue &other):capacity(other.capacity),mem(new int[capacity]), elements(other.elements), first(other.first){
        
    }
    int &operator[](int x){
        return mem[x];
    }
    
    void push(int x){
        if(elements==capacity){
            int *tmp=new int[capacity*2];
         for(int i=0;i<capacity;i++){
             tmp[i]=mem[i];
         }
        
        delete[] mem;
        mem=tmp;
        capacity*=2;
        first=0;}
        int insertion_location=(first+elements)%capacity;
        mem[insertion_location]=x;
        elements++;
    }
    void pop(){
        if(empty()){
            throw std::runtime_error("called for empty");}
        else{first=(first+1)%capacity;
        elements--;}
        
    }
    int front(){
        if(empty())
        throw std::runtime_error("called for empty");
        return mem[first];
    }
    
    ~Queue(){
        delete []mem;
    }
};

int main()
{
    Queue q;
    
    q.push(5);
    q.push(9);
    std::cout<<q.front()<<std::endl;
    q.pop();
    q.push(8);
    std::cout<<q.front();
    return 0;
}
