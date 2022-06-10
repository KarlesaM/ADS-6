// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
 private:
T mas[100];
int first;
int last;

 public:
TPQueue() : first(0), last(0) {}
void push(T vel1) {
if (last - first >= size) {
throw "Full!";
} else {
int vel2 = last - 1;
while ((vel2 >= first) && (mas[vel2 % size].prior <
vel1.prior)) {
mas[(vel2 + 1) % size] = mas[vel2 % size];
vel2--;
}
mas[(vel2 + 1) % size] = vel1;
last++;
}
}
T front() {
return mas[first % size];
}
T back() {
return mas[(last - 1) % size];
}
T pop() {
return mas[(first++) % size];
}
};

struct SYM {
char ch;
int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
