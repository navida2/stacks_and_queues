
ostream & operator << (ostream & out, Stack & L){
    L.print(out);
    return out;
}

//Array stack functions

ArrayStack::ArrayStack(int cap):Stack("Array Stack"), capacity(cap), size(0){
    buf = new string [capacity];
}

void ArrayStack::push(const string & word){
    if(size!=capacity){
        buf[size++] = word;
    }
}
void ArrayStack::pop(){
    if(size!=0){
        --size;
    }
}
string ArrayStack::top(){
    //come back and add error if list is empty
    return buf[size-1];
}
bool ArrayStack::is_empty(){
    return (size == 0);
}
bool ArrayStack::is_full(){
    return (size==capacity);
}
void ArrayStack::print(ostream & out){
    for(int i=0;i<size;++i){
        out<<buf[i]<<endl;
    }
}
ArrayStack::~ArrayStack(){
    delete[] buf;
}

//NODE
void ListNode::print(ostream & out, ListNode * L){
    ListNode* main_node = L;
    for(;main_node != nullptr;main_node = main_node->next){
        out<<main_node->data<<endl;
    }
}
void ListNode::delete_list(ListNode * L){
    ListNode* main_node = L;
    for(;main_node != nullptr;){
        ListNode *tmp_node = main_node;
        main_node = main_node->next;
        delete tmp_node;
    }
}

//LINKED STACK FUNCTIONS
LinkedStack();
void push(const string & word);
void pop();
string top();
bool is_empty();
bool is_full();
void print(ostream & out);
~LinkedStack();