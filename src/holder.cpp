#include "holder.h"
#include "Timer.h"
#include <iostream>
#include <fstream>


using namespace std;



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

ArrayQueue::ArrayQueue(int cap):Queue("Array Queue"), capacity(cap+1), front(0), rear(0){
    buf = new string[cap+1];
}
void ArrayQueue::enq(const string & word){//USES REAR TO MOVE
// check if full first
    buf[rear++] = word;
    rear = rear % capacity;
}
void ArrayQueue::deq(){//USES front to move
//add error checking 
    front = (front+1)%capacity;
}
string ArrayQueue::next(){
    return buf[front];
}
bool ArrayQueue::is_empty(){
    return (front == rear);
}
bool ArrayQueue::is_full(){
    //look at ky goodnotes diagram if i get confuded again cux of the last ghost slot
    //double check that it isnt capacity-1 since we added one in the befgining
    return (front == (rear+1)%capacity);
}
void ArrayQueue::print(ostream & out){
    //go from the front to the end printing every element
    for(int i = front;rear!= i; i =(i+1)%capacity){
        out<<buf[i]<<endl;
    }
}
ArrayQueue::~ArrayQueue(){
    delete[] buf;
}

//:LINKED QUEUEU FUNCTIONS
LinkedQueue::LinkedQueue():Queue("Linked Queue"){
    head = nullptr;
    tail = nullptr;
}
void LinkedQueue::enq(const string & word){
    //check if empty next
    //set tail nex to new node
    ListNode* new_elem = new ListNode(word, nullptr);
    if(is_empty()){
        head = new_elem;
        tail = new_elem;
    }
    else{
        tail->next = new_elem;
        tail = new_elem;
    }
}
void LinkedQueue::deq(){
    if (head!=nullptr){
        ListNode* new_head = head->next;
        delete head;
        head = new_head;
    }
}

string LinkedQueue::next(){
    return head->data;
}

bool LinkedQueue::is_empty(){
    return head == nullptr;
}
bool LinkedQueue::is_full(){
    return false;
}
void LinkedQueue::print(ostream & out){
    ListNode* elem = head;
    for(;elem;elem=elem->next){
        out<<elem->data<<endl;
    }
}

LinkedQueue::~LinkedQueue(){
    ListNode::delete_list(head);
    head = nullptr;
    tail = nullptr;
}

void error(string word, string msg);
    cout<<"Error - "<<word<<msg<<endl;

void insert_all_words(int k, string file_name, Holder & L){
    Timer t;
    double eTime;
    ifstream in(file_name);
    int limit = k *NWORDS /10;
    t.start();
    for (string word; (in>>word)&&limit>0; --limit){
        L.find(word);
    }
    t.elapsedUserTime(eTime);
    in.close();
    cout<<"\t\tF = " <<eTime<<endl;
}
void remove_all_words(int k, string file_name, Holder & L){
    Timer t;
    double eTime;
    ifstream in(file_name);
    int limit = k *NWORDS /10;
    t.start();
    for (string word; (in>>word)&&limit>0; --limit){
        L.remove(word);
    }
    t.elapsedUserTime(eTime);
    in.close();
    cout<<"\t\tR = " <<eTime<<endl;
}
void measure_holder(string file_name, Holder & L){
    cout<<L.name<<endl;
    for(int K=1;K<=10;++K){
        cout<<"\tK = "<<K<<endl;
        insert_all_words(K, file_name,L);
        find_all_words(K,file_name,L);
        remove_all_words(K,file_name,L);
        if(!L.is_empty()){
            error(L.name, "is not empty");
        }
    }
}
void measure_holders(string input_file){
    ArrayStack array_stack(NWORDS);
    LinkedStack linked_stack;
    ArrayQueue array_queue(NWORDS);
    LinkedQueue linked_queue;

    measure_holder(input_file, array_stack);
    measure_holder(input_file, linked_stack);
    measure_holder(input_file, array_queue);
    measure_holder(input_file, linked_queue);
}
