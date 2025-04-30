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




