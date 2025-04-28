
ostream & operator << (ostream & out, Stack & L);

//Array stack functions
    ArrayStack(int cap = NWORDS);
    void push(const string & word);
    void pop();
    string top();
    bool is_empty();
    bool is_full();
    void print(ostream & out);
    ~ArrayStack();
    