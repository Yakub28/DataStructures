#include <iostream>
#include <stdexcept>

class Vector{
    int capacity;
    int elements;
    int *mem;
    public:
    Vector():capacity(10),elements(0),mem(new int[capacity])
    {
        
    }   
    bool empty(){
        if(elements==0)
            throw std::runtime_error("Called for empty vector");
    }
    void push_back(int x){
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
        elements++;
    }
    void pop_back(){
        if(not empty())
        elements--;
        else
        empty();
    }
    int back(){
        if(not empty())
        return mem[elements-1];
        else
        empty();
    }
    
    ~Vector(){
        delete []mem;
    }
    
    int &at(int x){
       if(x>elements){
           throw std::runtime_error("Outside of a vector");
       }
       else 
       return mem[x];
    }
    
    int size(){
        return elements;
    }
    
    int &operator[](int x){
        return mem[x];
    }
    
    Vector(const Vector& original):
    capacity(original.capacity),elements(original.elements),mem(new int[capacity]){
        for(int i=0; i<elements; i++){
            mem[i]=original.mem[i];
        }
}
        
        Vector &operator=(const Vector& original){
            if(this!=&original){  //guard against self assignment a=a
                if(mem!=nullptr)  
                    delete []mem;//if mem is allocated, delete it
                capacity=original.capacity; //copy fields from the original
                elements=original.elements;
                mem=new int[capacity]; //allocate a new array
                for(int i=0;i<elements; i++){
                    mem[i]=original.mem[i];
                }
            }
            return *this; //always return a reference
        }
};

void do_something(Vector gamma){
    std::cout<<gamma[0];
}

int main()
{
    Vector alpha;
    for(int i=0;i<20;i++){
        alpha.push_back(i*i);
    }
    Vector beta;
    for(int i=0;i<20;i++)
    {beta.push_back(-i*i);}
    alpha=beta;
    

    return 0;
}
