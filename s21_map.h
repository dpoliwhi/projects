#ifndef SRC_S21_MAP_H_
#define SRC_S21_MAP_H_

#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include "s21_BinaryTree.h"

namespace s21 {

template <class Key, class T>
class map : public BinaryTree<Key, T> {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;
  using Node = _NodeRBT<Key, T> *;
  typedef typename BinaryTree<Key, T>::iterator iterator;
  // typedef typename BinaryTree<Key, T>::const_iterator const_iterator;

  map();                                                                                        // done
  map(std::initializer_list<value_type> const &items);
  map(const map &m);
  // map(map &&m);
  ~map();
  // map<value_type> &operator=(map<value_type> &&m);
  // map<value_type> &operator=(map<value_type> &m);

  // element access
  T &at(const Key &key);
  T &operator[](const Key &key);

  // iterators
  iterator begin();
  iterator end();

  // capacity
  bool empty();                                                                                 // done
  size_type size();
  size_type max_size();

  // modifiers
  void clear();
  std::pair<iterator, bool> insert(const value_type &value);
  std::pair<iterator, bool> insert(const Key &key, const T &obj);
  std::pair<iterator, bool> insert_or_assign(const Key &key, const T &obj);
  void erase(iterator pos);
  void swap(map &other);
  void merge(map &other);

  // lookup
  bool contains(const Key &key);
};

template <class Key, class T>
map<Key, T>::map() : BinaryTree<Key, T>::BinaryTree() {}

template <class Key, class T>
map<Key, T>::map(const map &m) {}


template <class Key, class T>
map<Key, T>::map(std::initializer_list<value_type> const &items) : BinaryTree<Key, T>::BinaryTree(items) {}

template <class Key, class T>
map<Key, T>::~map() {}

template <class Key, class T>
bool map<Key, T>::empty() {return BinaryTree<Key, T>::empty();}

template <class Key, class T>
size_t map<Key, T>::size() {return BinaryTree<Key, T>::size();}

}  // namespace s21

#endif  //    SRC_S21_MAP_H_