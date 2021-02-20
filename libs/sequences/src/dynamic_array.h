/*
 * Author: George Vaintrub, MEPHI B19-504
 *
 * A header file contain a dynamic array class. 
 * It is the lowest level of abstraction that organizes data in memory.
*/
#pragma once
#include <cstdint>

using std::uint32_t;
using std::int32_t;

// Dynamic array class.
// Example:
// int A[] = {1, 2, 3, 4, 5};
// DynamicArray<int> dyn_arr(A, 5);
// dyn_arr.Set(5, 6); 
// std::cout << dyn_arr.Get(5); 6 will be printed.
template<typename T>
class DynamicArray
{
    private:
        T* A;
        uint32_t size_;
        uint32_t capacity_;
    public:
        DynamicArray(int32_t);
        DynamicArray(T*, int32_t);
        DynamicArray(const DynamicArray<T>&);
        ~DynamicArray();
        // Decomposition
        T Get(uint32_t);
        uint32_t GetSize();
        // Operations
        void Set(int32_t, T);
        void Resize(int32_t);
};
