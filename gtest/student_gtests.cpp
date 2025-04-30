#include <gtest/gtest.h>

#include "Timer.h"
#include "holder.h"
#include "is_balanced.h"



TEST(ArrayStack, Push) {
  ArrayStack hi(2);
  hi.push("drake");
  EXPECT_TRUE(hi.size == 1);
}

TEST(ArrayStack, Pop) {
  ArrayStack hi(2);
  hi.push("drake");
  hi.push("drake2");
  hi.pop();
  EXPECT_TRUE(hi.top()=="drake");
}

TEST(ArrayStack, top) {
  ArrayStack hi(2);
  hi.push("drake");
  hi.push("drake2");
  EXPECT_TRUE(hi.top()=="drake2");
}

TEST(ArrayStack, is_empty) {
  ArrayStack hi(2);
  EXPECT_TRUE(hi.is_empty());
}

TEST(ArrayStack, is_full) {
  ArrayStack hi(2);
  hi.push("drake");
  hi.push("drake2");
  EXPECT_TRUE(hi.is_full());
}

TEST(LinkedStack,Push){
  LinkedStack hi2);
  hi2.push("hola");
  EXPECT_TRUE(hi2.top()=="hola");
}
TEST(LinkedStack,Pop){
  LinkedStack hi2;
  hi2.push("hola");
  hi2.push("nope")
  EXPECT_TRUE(hi2.top()=="hola");
}
TEST(LinkedStack,top){
  LinkedStack hi2;
  hi2.push("hola");
  EXPECT_TRUE(hi2.top()=="hola");
}
TEST(LinkedStack,is_empty){
  LinkedStack hi2;
  EXPECT_TRUE(hi2.is_empty());
}
TEST(LinkedStack,is_full){
  LinkedStack hi2;
  EXPECT_TRUE(!hi2.is_full());
}

TEST(ArrayQueue,enq){
  ArrayQueue hi3(2);
  hi3.enq("ye");
  EXPECT_TRUE(hi3.next()=="ye");
}

TEST(ArrayQueue,deq){
  ArrayQueue hi3(2);
  hi3.enq("ye");
  hi3.deq();
  EXPECT_TRUE(hi3.size == 0);
}

TEST(ArrayQueue,next){
  ArrayQueue hi3(2);
  hi3.enq("drake");
  EXPECT_TRUE(hi3.next()=="drake");
}

TEST(ArrayQueue,is_full){
  ArrayQueue hi3(2);
  hi3.enq("ye");
  hi3.enq("ILOVEYOU")
  EXPECT_TRUE(hi3.is_full());
}

TEST(ArrayQueue,is_empty){
  ArrayQueue hi3(1);
  EXPECT_TRUE(hi3.is_empty())
}

TEST(LinkedQueue,enq){
  LinkedQueue hi4;
  hi4.enq("drake");
  EXPECT_TRUE(hi4.next()=="drake");
}

TEST(LinkedQueue,deq){
  LinkedQueue hi4;
  hi4.enq("drake");
  hi4.enq("ye");
  EXPECT_TRUE(hi4.next()=="drake");
}

TEST(LinkedQueue,next){
  
}
TEST(LinkedQueue,is_empty){
  
}
TEST(LinkedQueue,is_full){
  
}







