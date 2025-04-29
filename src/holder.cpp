
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
LinkedStack::LinkedStack():Stack("Linked Stack"){
    head = nullptr;
}
void LinkedStack::push(const string & word){
    head = new ListNode(word, head);
}
void LinkedStack::pop(){
    //check da size to se if 0 if not then fo the rest of code
    if (size != 0){
        ListNode* old_head = head;
        head = head->next;
        delete old_head;
        --size;
    }

}
string LinkedStack::top(){
    return head->data;
}

bool LinkedStack::is_empty(){
    return head == nullptr;
}

bool LinkedStack::is_full(){
    return false;
}

void LinkedStack::print(ostream & out){
    ListNode* main_node = L;
    for(;main_node!=nullptr;main_node=main_node->next){
        out<<main_node->data<<endl;
    }
}
LinkedStack::~LinkedStack(){
    ListNode::delete_list(head);
}

//arrayqueue functions to im
//QUEU IS FIRST IN FIRST OUT LIKE A FRY ELECTRONICS LINE

ArrayQueue::ArrayQueue(int cap):Queue("Array Queue"), capacity(cap), front(0), rear(0){
    buf = new string[capacity+1];
}
void enq(const string & word){//USES REAR TO MOVE
// check if full first
    buf[rear++] = word;
    rear = rear % capacity;
}
void deq(){//USES front to move
//add error checking 
    front = (front+1)%capacity;
}
string next(){
    return buf[front];
}
bool is_empty(){
    return (front == rear);
}
bool is_full(){
    //check if rear is the last element
    //double check that it isnt capacity-1 since we added one in the befgining
    return (rear ==capacity);
}
void print(ostream & out);
ArrayQueue::~ArrayQueue(){
    delete[] buf;
}