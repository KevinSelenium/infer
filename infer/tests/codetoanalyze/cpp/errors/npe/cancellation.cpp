/*
 * Copyright (c) 2017 - present Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */
namespace cancellation_test {

struct Test {
  int x, sz;

  int begin() const { return x; }
  int end() const { return x + sz; }
  int end2() const { return x - sz; }
};

bool is_size_zero(const Test& t) { return t.begin() == t.end(); }
bool is_size_zero2(const Test& t) { return t.begin() == t.end2(); }

void size_zero_no_deref_ok() {
  int* p = nullptr;
  Test t{1, 0};
  if (!is_size_zero(t))
    *p = 42;
}

void size_zero_deref_bad() {
  int* p = nullptr;
  Test t{1, 0};
  if (is_size_zero(t))
    *p = 42;
}

void size_nonzero_no_deref2_ok() {
  int* p = nullptr;
  Test t{1, 1};
  if (is_size_zero(t))
    *p = 42;
}

void size_nonzero_deref2_bad() {
  int* p = nullptr;
  Test t{1, 1};
  if (!is_size_zero(t))
    *p = 42;
}

void size_zero_no_deref2_ok() {
  int* p = nullptr;
  Test t{1, 0};
  if (!is_size_zero(t))
    *p = 42;
}

void size_zero_deref2_bad() {
  int* p = nullptr;
  Test t{1, 0};
  if (is_size_zero(t))
    *p = 42;
}

void size_nonzero_no_deref_ok() {
  int* p = nullptr;
  Test t{1, 1};
  if (is_size_zero(t))
    *p = 42;
}

void size_nonzero_deref_bad() {
  int* p = nullptr;
  Test t{1, 1};
  if (!is_size_zero(t))
    *p = 42;
}
} // namespace cancellation_test
