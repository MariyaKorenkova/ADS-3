// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t cur = num, max = num;
  while (cur != 1) {
    if (cur % 2 == 0) {
      cur = cur / 2;
    } else {
      cur = 3 * cur + 1;
    }
    if (cur > max) max = cur;
  }
  return max;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int len = 1;
  uint64_t cur = num;
  while (cur != 1) {
    if (cur % 2 == 0) {
      cur = cur / 2;
    } else {
      cur = 3 * cur + 1;
    }
    len++;
  }
  return len;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
  uint64_t max = 1, maxnum = 1;
  for (uint64_t i = lbound; i < rbound; i++) {
    unsigned int len = collatzLen(i);
    if (len > max) {
      max = len;
      maxnum = i;
    }
  }
  *maxlen = max;
  return maxnum;
}
