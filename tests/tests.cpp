// Copyright 2021 Your Name <your_email>

#include <stdexcept>

#include <gtest/gtest.h>

#include <sharedptr.hpp>

TEST(Equality, Constructor_methods) {
  SharedPtr<int> sp1;
  EXPECT_EQ(sp1.get(), nullptr);
  EXPECT_EQ(sp1.use_count(), 0);

  int* ptr = new int(5);
  SharedPtr<int> sp2(ptr);
  EXPECT_EQ(*(sp2.get()), 5);
  EXPECT_EQ(sp2.use_count(), 1);

  SharedPtr<int> sp3(sp2);
  EXPECT_EQ(*(sp3.get()), 5);
  EXPECT_EQ(sp3.use_count(), 2);
  EXPECT_EQ(*(sp2.get()), 5);
  EXPECT_EQ(sp2.use_count(), 2);


  SharedPtr<int> sp4(SharedPtr<int> sp_tmp());
  //EXPECT_EQ(sp4.get(), nullptr);
  //EXPECT_EQ(sp4.use_count(), 0);
}
