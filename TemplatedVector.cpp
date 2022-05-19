#include <iostream>
#include <vector>


template<class T>
class Vector{
    int capacity;
    int elements;
    T *mem;
    
public:
    Vector():capacity(10), elements(0), mem(new T[capacity]){}
    void push_back(T x){
        if(capacity==elements){
            T *tmp=new T[capacity*2];
            for(int i=0;i<capacity;i++){
                tmp[i]=mem[i];
            }
            delete [] mem;
            mem=tmp;
            capacity*=2;
        }
        mem[elements]=x;
        elements++;
    }
    bool empty(){
        return elements==0;
    }    
    void pop_back(){
        if(not empty()){
           elements--;
        }
        else
        throw std::runtime_error("Called for the empty");
    }
    
    T back(){
        if(not empty()){
            return mem[elements-1];
        }
        else
        throw std::runtime_error("Called for the empty vector");
    }
    
    ~Vector(){
        delete []mem;
    }
    T &at(int x){
        if(x>elements)
        throw std::runtime_error("Outside of the vector!");
        else
        return mem[x];
    }
    int size(){
        return elements;
    }
    T &operator[](int x){
        return mem[x];
    }
    Vector(const Vector &original):capacity(original.capacity),elements(original.elements),mem(new int[capacity]){
        for(int i=0;i<elements;i++)
        mem[i]=original.mem[i];
    }
    
    Vector &operator=(const Vector &original){
        if(this!=&original){ //guard against self-assignment
            if(mem!=nullptr)
            delete [] mem;
            capacity=original.capacity; //copy fields from the original
            elements=original.elements; 
            mem= new T[capacity];
            for(int i=0; i<elements; i++)
            mem[i]=original.mem[i];
        }
        return *this;
    }
};


int main()
{
    Vector<int> alpha;
    for(int i=0; i<=20; i++)
    alpha.push_back(i*i);
    std::cout<<alpha.back()<<'\n';
     
    Vector<char> betta;
    for(int i='a'; i<'g'; i++)
    betta.push_back(i);
    std::cout<<betta.back();
    return 0;
}
