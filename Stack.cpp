#include <iostream>
#include <stack>
#include <stdexcept>

class Stack{
    int capcity;
    int *mem;
    int elements;
    
    public: 
    Stack():capcity(10),mem(new int[capacity]), elements(0){
        
    }
    void push(int x){
        if(capacity==elements){
            int *tmp=new int[capacity*2];
            
            for(int i=0;i<capacity; i++){
                tmp[i]=mem[i];
            }
            delete [] mem;
            mem=tmp;
            capacity*=2;
        }
        mem[elements]=x;
        elements++
        
    }
    int top(){
        if(elements==0)
            throw std::runtime_error("top() called when stack is empty");
        return mem[elements-1];
    }
    
    void pop(){
        if(elements==0)
            throw std::runtime_error("pop called when empty");
        elements--;
    }
    
    ~Stack(){
        delete [] mem;
    }
}

int main()
{
    

    return 0;
}
