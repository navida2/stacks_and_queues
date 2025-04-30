#include <gtest/gtest.h>

#include "Timer.h"
#include "holder.h"
#include "is_balanced.h"

TEST(Replace, Me) {
  EXPECT_TRUE(false);
}

TEST(ArrayStack, Push) {
  
}

TEST(ArrayStack, Pop) {
  
}

TEST(ArrayStack, top) {
  
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




