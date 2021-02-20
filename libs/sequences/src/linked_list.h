/*
 * Author: George Vaintrub, MEPHI B19-504.
 *
 * A header file contain a linked list.
 * It is the lowest level of abstraction that organizes data in memory.
*/
#pragma once
#include <iostream>
#include <cstdint>
#include <cstddef> 

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
        //Node_* FindNodeByIndex(uint32_t);
    public:
        //LinkedList(const T*, const uint32_t);
        //LinkedList(const LinkedList<T>&);
        LinkedList();
        // ~LinkedList();
        // Decomposition
        //T GetFirst();
        // T GetLast();
        //T Get(uint32_t);
        //LinkedList<T>* GetSubList(uint32_t, uint32_t);
        //uint32_t GetLength();
        // Operations
        //void Append(T);
        //void Prepend(T item);
        //void InsertAt(T, uint32_t);
        //LinkedList<T>* Concat(LinkedList<T>*);
};
