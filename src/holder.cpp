
ostream & operator << (ostream & out, Stack & L);

//Array stack functions

    ArrayStack::ArrayStack(int cap):Stack("Array Stack"), capacity(cap), size(0){
        buf = new string [capacity];
    }
    
    void ArrayStack::push(const string & word){
        
    }
    void pop();
    string top(){
        //come back and add error if list is empty
        return buf[size-1];
    }
    bool is_empty(){
        return (size == 0);
    }
    bool is_full(){
        return (size==capacity);
    }
    void print(ostream & out){
        for(int i=0;i<size;++i){
            out<<buf[i]<<endl;
        }
    }
    ~ArrayStack();
    