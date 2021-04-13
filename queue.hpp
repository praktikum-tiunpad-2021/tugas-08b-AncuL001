#pragma once

namespace strukdat {

namespace priority_queue {

/**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
template <typename T>
struct Element {
  int data;
  int priority;
  Element<T> *next;
};

template <typename T>
using ElementPtr = Element<T> *;

/**
 * @brief implemetasi struct untuk queue.
 */
template <typename T>
struct Queue {
  ElementPtr<T> Head;
  ElementPtr<T> Tail;
};

/**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
template <typename T>
Queue<T> new_queue() {
  Queue<T> q;
  q.Head = nullptr;
  q.Tail = nullptr;
  return q;
}

/**
 * @brief mengetahui apakah queue kosong
 *
 * @return 1 jika kosong, 0 jika tidak
 */
template <typename T>
bool is_empty(Queue<T> q){
  return q.Head == nullptr;
}

/**
 * @brief memasukan data sesuai priority elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param priority  prioritas elemen yang menentukan urutan.
 */
template <typename T>
void enqueue(Queue<T> &q, const T &value, int priority) {
  ElementPtr<T> newElement = new Element<T>;
  newElement->data = value;
  newElement->priority = priority;
  newElement->next = nullptr;

  if (is_empty(q)){
    q.Head = newElement;
    q.Tail = newElement;
  }
  else {
    ElementPtr<T> tempPrev = nullptr;
    ElementPtr<T> temp = q.Head;
    while (temp->priority <= newElement->priority){
      if (temp->next == nullptr) break;
      tempPrev = temp;
      temp = temp->next;
    }

    if (temp == q.Head && newElement->priority < temp->priority){
      newElement->next = temp;
      q.Head = newElement;
    }
    else if (temp == q.Tail && newElement->priority > temp->priority){
      temp->next = newElement;
      q.Tail = newElement;
    }
    else {
      tempPrev->next = newElement;
      newElement->next = temp;
    }
  }
}

/**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
template <typename T>
T top(const Queue<T> &q) {
  return q.Head->data;
}

/**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
template <typename T>
void dequeue(Queue<T> &q) {
  ElementPtr<T> delPtr;
  if (is_empty(q)){
    delPtr = nullptr;
  }
  else if (q.Head->next == nullptr){
    delPtr = q.Head;
    q.Head = nullptr;
    q.Tail = nullptr;
    delete delPtr;
  }
  else {
    delPtr = q.Head;
    q.Head = q.Head->next;
    delete delPtr;
  }
}

}  // namespace priority_queue

}  // namespace strukdat
