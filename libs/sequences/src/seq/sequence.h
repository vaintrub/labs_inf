#pragma once

namespace adt {

    template<typename T>
    class Sequence
    {
        private:
        public:
            T GetFirst();
            T GetLast();
            T Get(int index);
            Sequence<T>* GetSubsequence(int startIndex, int endIndex);
            int GetLenght();
            void Append(T item);
            void Prepend(T item);
            void InsertAt(T item, int index);
            Sequence<T>* Concat(Sequence<T> *list);
    };
}
