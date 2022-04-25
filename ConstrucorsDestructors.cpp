#include <iostream>

struct floatArray{
    float size;
    float *data;
    
    floatArray(float _size):size(_size),data(new int[size])
    {
        
    }
    floatArray(const floatArray &other):size(other.size),data(new int [size])
    {
        for(int i=0;i<size; i++){
            data[i]=other.data[i];
        }
    }
    ~floatArray(){
        delete [] data;
    }
};

int main()
{
    

    return 0;
}
