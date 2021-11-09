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


  SharedPtr<int> sp4(( SharedPtr<int>(sp3) ));
  EXPECT_EQ(*(sp4.get()), 5);
  EXPECT_EQ(sp4.use_count(), 3);
  EXPECT_EQ(sp2.use_count(), 3);
  EXPECT_EQ(sp3.use_count(), 3);
}

TEST(Equality, Operator_methods) {
  int* ptr = new int(5);
  SharedPtr<int> sp1(ptr);
  EXPECT_EQ(*(sp1.get()), 5);
  EXPECT_EQ(sp1.use_count(), 1);

  SharedPtr<int> sp2 = sp1;
  EXPECT_EQ(*(sp2.get()), 5);
  EXPECT_EQ(sp2.use_count(), 2);
  EXPECT_EQ(sp1.use_count(), 2);

  SharedPtr<int> sp3 = SharedPtr<int>(sp2);
  EXPECT_EQ(*(sp3.get()), 5);
  EXPECT_EQ(sp3.use_count(), 3);
  EXPECT_EQ(sp1.use_count(), 3);
  EXPECT_EQ(sp2.use_count(), 3);

  EXPECT_EQ(*(sp3),5);
  //TODO: сделать проверку стрелачки
  //EXPECT_EQ(sp3->use_count(),5);
  EXPECT_EQ(bool(sp3),true);

  SharedPtr<int> sp4;
  EXPECT_EQ(bool(sp4),false);
}

TEST(Equality, Reset_swap_methods) {
  int* ptr1 = new int(1);
  SharedPtr<int> sp1(ptr1);

  int* ptr2 = new int(2);
  SharedPtr<int> sp2(ptr2);

  sp1.swap(sp2);
  EXPECT_EQ(*(sp1.get()), 2);
  EXPECT_EQ(sp1.use_count(), 1);
  EXPECT_EQ(*(sp2.get()), 1);
  EXPECT_EQ(sp2.use_count(), 1);

  SharedPtr<int> sp3(sp1);
  sp3.reset();
  EXPECT_EQ(*(sp3.get()), 2);
  EXPECT_EQ(sp3.use_count(), 1);

  //[[maybe_unused]] int* ptr3=new int(3);
  //sp1.reset(ptr3);
  //EXPECT_EQ(*(sp1.get()), 3);
  //EXPECT_EQ(sp1.use_count(), 1);
  //delete ptr3;
}
