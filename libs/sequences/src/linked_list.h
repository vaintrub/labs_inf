/*
 * Author: George Vaintrub, MEPHI B19-504.
 *
 * A header file contain a linked list.
 * It is the lowest level of abstraction that organizes data in memory.
*/
#pragma once
#include <cstdint>
#include <cstddef> 
#include <stdexcept>

using std::uint32_t;
using std::int32_t;

//Linked List.
//Example:
//int A[] = {1, 2, 3, 4, 5};
//LinkedList<int> linked_list(A, 5);
//linked_list.Append(6);
//linked_list.Prepend(0);
//std::cout << linked_list.GetFirst() << " " << linked_list.GetLast(); 0 6 will be printed.
template<typename T>
class LinkedList
{
    private:
        struct Node_ {
            T item;
            Node_* next;
            Node_* prev;
        };
        Node_* first_;
        Node_* last_;
        uint32_t size_;
        Node_* FindNodeByIndex(uint32_t);
    public:
        LinkedList(const T*, const uint32_t);
        LinkedList(const LinkedList<T>&);
        LinkedList();
        ~LinkedList();
        // Decomposition
        T GetFirst();
        T GetLast();
        T Get(uint32_t);
        LinkedList<T>* GetSubList(uint32_t, uint32_t);
        uint32_t GetLength();
        // Operations
        // replace (operator)
        // remove
        void Append(T);
        void Prepend(T item);
        void InsertAt(T, uint32_t);
        LinkedList<T>* Concat(LinkedList<T>*);
};

// Constructor: Copies elements from the passed array.
template<typename T>
LinkedList<T>::LinkedList(const T* items, const uint32_t count)
{
    Node_* node = new Node_;
    node->item = items[0];
    node->next = nullptr;
    node->prev = nullptr;
    // TODO check allocation memory
    this->first_ = node;
    this->size_ = count;
    for (uint32_t i = 1; i < count; i++) {
        Node_* node_tmp = new Node_;
        node_tmp->item = items[i];
        node_tmp->next = nullptr;
        node_tmp->prev = node;
        node->next = node_tmp;
        node = node_tmp;
    }
    this->last_ = node;
}

// Constructor: 
template<typename T>
LinkedList<T>::LinkedList()
{
    this->size_ = 0;
    this->first_ = nullptr;
    this->last_ = nullptr;
}

// Constructor:
template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list)
{
    this->size_ = list.size_;
    if (this->size_ != 0) {
        Node_* new_node = new Node_;
        Node_* old_node = list.first_;
        new_node->item = list.first_->item;
        new_node->next = nullptr;
        new_node->prev = nullptr;
        this->first_ = new_node;
        while (old_node->next != nullptr) {
            Node_* node_tmp = new Node_;
            old_node = old_node->next;
            node_tmp->item = old_node->item;
            node_tmp->next = nullptr;
            node_tmp->prev = new_node;
            new_node->next = node_tmp;
            new_node = node_tmp;
        }
        this->last_ = new_node;
    }
}

#include <iostream>
template<typename T>
LinkedList<T>::~LinkedList()
{
    Node_* node = this->first_;
    Node_* node_tmp;
    while (node && node->next) {
        node_tmp = node;
        node = node->next;
        delete node_tmp;
    }
}

// Gives the first element.
template<typename T>
T LinkedList<T>::GetFirst()
{
    // TODO Except indexOutOfRange
    if (!this->first_) {
        throw std::out_of_range ("Out of range");
    }
    return this->first_->item;
}

// Gives the last element.
template<typename T>
T LinkedList<T>::GetLast()
{
    // TODO Except indexOutOfRange
    if (!this->last_) {
        throw std::out_of_range ("Out of range");
    }
    return this->last_->item;
}

// Gives element by index.
template<typename T>
T LinkedList<T>::Get(uint32_t index)
{
    // TODO Except indexOutOfRange
    if (index >= this->size_ || index < 0) {
        throw std::out_of_range ("Out of range");
    }
    return this->FindNodeByIndex(index)->item; 
}

// Gives sublist from list.
template<typename T>
LinkedList<T>* LinkedList<T>::GetSubList(uint32_t start_idx, uint32_t end_idx)
{
    // TODO Except indexOutOfRange
    if (start_idx >= this->size_ || start_idx < 0 || end_idx < start_idx || end_idx >= this->size_) {
        throw std::out_of_range ("Out of range");
    }

    int count = end_idx - start_idx + 1;
    T items[count]; 
    Node_* node = this->FindNodeByIndex(start_idx);
    uint32_t i = 0;
    while (start_idx++ != end_idx + 1) {
        items[i++] = node->item; 
        node = node->next;
    }
    LinkedList<T>* sub_list = new LinkedList(items, count);
    return sub_list;
}

template<typename T>
typename LinkedList<T>::Node_* LinkedList<T>::FindNodeByIndex(uint32_t index)
{
    Node_* node;
    uint32_t i;
    // Checking which edge is closer.
    if (this->size_ - index < index) {
        i = this->size_ - 1;
        node = this->last_;
        while (i-- != index)
            node = node->prev;
    } else {
        i = 0;
        node = this->first_;
        while (i++ != index)
            node = node->next;
    }
    return node;
}

template<typename T>
uint32_t LinkedList<T>::GetLength()
{
    return this->size_;
}

template<typename T>
void LinkedList<T>::Append(T item)
{
    Node_* node = new Node_;
    node->item = item;
    node->next = nullptr;
    node->prev = this->last_;

    if (this->last_ != nullptr)
        this->last_->next = node;
    this->last_ = node;
    if (this->size_ == 0)
        this->first_ = node;
    this->size_++;
}

template<typename T>
void LinkedList<T>::Prepend(T item)
{
    Node_* node = new Node_;
    node->item = item;
    node->next = this->first_;
    node->prev = nullptr;

    if (this->first_ != nullptr)
        this->first_->prev = node;
    this->first_ = node;
    if (this->size_ == 0)
        this->last_ = node;
    this->size_++;
}

template<typename T>
void LinkedList<T>::InsertAt(T item, uint32_t index)
{
    if (index >= this->size_ || index < 0) {
        throw std::out_of_range ("Out of range");
    }
    Node_* old_node = this->FindNodeByIndex(index);
    old_node->item = item;
}

template<typename T>
LinkedList<T>* LinkedList<T>::Concat(LinkedList<T>* list)
{
    LinkedList<T>* new_list = this->GetSubList(0, this->size_ - 1);
    Node_* node_tmp = list->first_;
    while (node_tmp->next) {
        new_list->Append(node_tmp->item);
        node_tmp = node_tmp->next;
    }
    new_list->Append(node_tmp->item);
    return new_list;
}
