// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template <typename T, int size>
class TPQueue {
 private:
    T arr[100];
    int first, last;
 public:
    TPQueue() : first(0), last(0) {}
    void push(T num) {
      if (last - first >= size) {
      throw std::string("Full!");
      } else {
      int con = last++;
      while ((--con >= first) && (arr[con % size].prior < num.prior)) {
        arr[(con + 1) % size] = arr[con % size];
      }
      arr[(con + 1) % size] = num;
      }
      }
    T pop() {
    return arr[(first++) % size];
  }
};

struct sum {
 char ch;
 int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
