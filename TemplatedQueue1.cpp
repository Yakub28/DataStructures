#include <iostream>
#include <stdexcept>
#include <string>
template<class T>
class Queue{
    int capacity;
    T *mem;
    int elements;
    
    int first_pos;
    public:
    Queue():capacity(10), mem(new T[capacity]), elements(0), first_pos(0){
        
    }
    
    bool empty(){
        return elements==0;
    }
    
    Queue(const Queue &other):capacity(other.capacity),mem(new T[capacity]),elements(other.elements), first_pos(other.first_pos){
        
    }
    
    T &operator[](T x){
        return mem[x];
    }
    
    void push(T x){
        if(elements==capacity){
            T *tmp=new T[capacity*2];
            for(int i=0; i<capacity; i++){
                tmp[i]=mem[i];
            }
            delete[] mem;
            mem = tmp;
        }
        
        auto insertion_location=(first_pos+elements)%capacity;
        mem[insertion_location]=x;
        elements++;
    }
    
    void pop(){
        if(empty()){
            throw std::runtime_error("called for empty Queue");
        }else{
            first_pos=(first_pos+1)%capacity;
            elements--;
        }
    }
    
    T front(){
        if(empty())
        throw std::runtime_error("called for empty");
     
        return mem[first_pos];
    }
    ~Queue(){
        delete []mem;
    }
    
};


int main()
{
    Queue<char> qw;
    qw.push('c');
    std::cout<<qw.front()<<"\n";
    return 0;
}

