#include "linked_list.h"
#include <iostream>

int main()
{
    LinkedList<int> l;
    l.Append(1);
    l.Append(2);
    l.Prepend(3);
    std::cout << l.GetFirst() << std::endl;
    std::cout << l.GetLast() << std::endl;
    std::cout << l.Get(0) << std::endl;
    return 0;
}
