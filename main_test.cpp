#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "queue.hpp"

using namespace strukdat::priority_queue;

TEST_CASE("membuat queue baru", "[case_1]") {
  auto q = new_queue<int>();
  REQUIRE(sizeof(q) == sizeof(Queue<int>));
}

TEST_CASE("memasukkan data berdasarkan prioritas", "[case_2]") {
  auto q = new_queue<int>();
  enqueue(q, 1, 5);
  REQUIRE(top(q) == 1);

  enqueue(q, 2, 3);
  REQUIRE(top(q) == 1);

  enqueue(q, 3, 7);
  REQUIRE(top(q) == 3);

  enqueue(q, 4, 5);
  REQUIRE(top(q) == 3);

  enqueue(q, 5, 1);
  REQUIRE(top(q) == 3);
}

TEST_CASE("menghapus data berdasarkan urutan queue", "[case_3]") {
  auto q = new_queue<int>();
  enqueue(q, 1, 5);
  enqueue(q, 2, 3);
  enqueue(q, 3, 7);
  enqueue(q, 4, 5);
  enqueue(q, 5, 1);

  dequeue(q);
  REQUIRE(top(q) == 1);

  dequeue(q);
  REQUIRE(top(q) == 4);

  dequeue(q);
  REQUIRE(top(q) == 2);

  dequeue(q);
  REQUIRE(top(q) == 5);
}
