// test: remove elements from front of list
#include <iostream>
#include "test_helpers.h"
#include "linked_list.h"
using namespace std;

int main(){
  // create linked list
  bool pass;
  // create linked list
  MyList list;
  MyNode* marker = nullptr;

  EXPECT_EQ(list.size(), 0);

  // add item to linked list
  list.add("A", 1);
  marker = list.head();

  EXPECT_EQ(list.size(), 1);
  EXPECT_EQ(marker->name(), "A");
  EXPECT_EQ(marker->score(), 1);
  EXPECT_EQ(marker->next(), nullptr);
  cout << __LINE__ << endl;
  // remove only element
  EXPECT_TRUE(list.remove("A"));
  
  marker = list.head();
  cout << __LINE__ << endl;
  EXPECT_EQ(marker, nullptr);
  cout << __LINE__ << endl;
  // remove from now-empty linked list
  EXPECT_FALSE(list.remove("A"));
  cout << __LINE__ << endl;
}

