#include "linked_list.h"

// Constructor: Copies elements from the passed array.
//template<typename T>
//LinkedList<T>::LinkedList(const T* items, const uint32_t count)
//{
//    Node_* node = new Node_(items[0], nullptr, nullptr);
//    // TODO check allocation memory
//    this->first_ = node;
//    this->size_ = count;
//    for (uint32_t i = 1; i < count; i++) {
//        Node_* node_tmp = new Node_(items[i], nullptr, node);
//        node->next = node_tmp;
//        node = node_tmp;
//    }
//    this->last_ = node;
//}

// Constructor: 
template<typename T>
LinkedList<T>::LinkedList()
{
    //this->size_ = 0;
    //this->first_ = nullptr;
    //this->last_ = nullptr;
    int d;
}

// Constructor:
//template<typename T>
//LinkedList<T>::LinkedList(const LinkedList<T>& list)
//{
//    uint32_t list_size = list->size_;
//    this->size_ = list_size;
//    Node_* node = new Node_(list.Get(0), nullptr, nullptr);
//    this->first_ = node;
//    for (uint32_t i = 1; i < list_size; i++) {
//        Node_* node_tmp = new Node_(list.Get(i), nullptr, node);
//        node->next = node_tmp;
//        node = node_tmp;
//    }
//    this->last_ = node;
//}

//template<typename T>
//LinkedList<T>::~LinkedList()
//{
//    //Node_* node = this->first_;
//    //while (node->next != nullptr) {
//
//    //}
//}

// Gives the first element.
/*template<typename T>
T LinkedList<T>::GetFirst()
{
    // TODO Except indexOutOfRange
    return this->first_->item;
}*/

// Gives the last element.
//template<typename T>
//T LinkedList<T>::GetLast()
//{
//    // TODO Except indexOutOfRange
//    return this->last_->item;
//}

// Gives element by index.
//template<typename T>
//T LinkedList<T>::Get(uint32_t index)
//{
//    // TODO Except indexOutOfRange
//    return this->FindNodeByIndex(index)->item; 
//}

// Gives sublist from list.
//template<typename T>
//LinkedList<T>* LinkedList<T>::GetSubList(uint32_t start_idx, uint32_t end_idx)
//{
//    // TODO Except indexOutOfRange
//    uint32_t count = start_idx - end_idx + 1;
//    T items[count];
//    Node_* node = this->FindNodeByIndex(start_idx);
//    uint32_t i = 0;
//    while (start_idx++ != end_idx) {
//        items[i++] = node->item; 
//        node = node->next;
//    }
//    LinkedList<T>* sub_list = new LinkedList(items, count);
//    return sub_list;
//}

//template<typename T>
//typename LinkedList<T>::Node_* LinkedList<T>::FindNodeByIndex(uint32_t index)
//{
//    Node_* node;
//    uint32_t i;
//    // Checking which edge is closer.
//    if (this->size_ - index < index) {
//        i = this->size_;
//        node = this->last_;
//        while (--i != index)
//            node = node->prev;
//    } else {
//        i = 0;
//        node = this->first_;
//        while (i++ != index)
//            node = node->next;
//    }
//    return node;
//}

//template<typename T>
//uint32_t LinkedList<T>::GetLength()
//{
//    return this->size_;
//}

//template<typename T>
//void LinkedList<T>::Append(T item)
//{
//    Node_* node = new Node_(item, nullptr, this->last_);
//    this->last_ = node;
//    this->size_++;
//}

/*template<typename T>
void LinkedList<T>::Prepend(T item)
{
    Node_* node = new Node_(item, this->first_, nullptr);
    this->first_ = node;
    this->size_++;
}*/

//template<typename T>
//void LinkedList<T>::InsertAt(T item, uint32_t index)
//{
//    // TODO indexOutOfRange
//    Node_* old_node = this->FindNodeByIndex(index);
//    Node_* new_node = new Node_(item, old_node, old_node->prev); 
//    old_node->prev = new_node;
//    this->size_++;
//}

//template<typename T>
//LinkedList<T>* LinkedList<T>::Concat(LinkedList<T>* list)
//{
//    LinkedList<T>* new_list = this->GetSubList(0, this->size_);
//    for (uint32_t i = 0; i < list->GetLenght(); i++) {
//        new_list->Append(list->Get(i));
//    }
//    return new_list;
//}
