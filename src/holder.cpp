
ostream & operator << (ostream & out, Stack & L);

//Array stack functions

    ArrayStack::ArrayStack(int cap):Stack("Array Stack"), capacity(cap), size(0){
        buf = new string [capacity];
    }
    
    void push(const string & word){
        
    }
    void pop();
    string top();
    bool is_empty();
    bool is_full();
    void print(ostream & out);
    ~ArrayStack();
    