//noamglikman1@gmail.com
#include <iostream>
#include "MyContainer.hpp"
#include "AscendingOrder.hpp"
#include "DescendingOrder.hpp"
#include "ReverseOrder.hpp"  
#include "Order.hpp"
#include "MiddleOutOrder.hpp"
#include "SideCrossOrder.hpp"

using namespace my;

int main() {
    // Create a container of type MyContainer holding int elements
    MyContainer<int> container;
    container.add(7);
    container.add(15);
    container.add(6);
    container.add(1);
    container.add(2);

    // Print the size of the container
    std::cout << container << std::endl;

    // Create an iterator for ascending order traversal of the container
    auto it = AscendingIterator<int>::begin(container);
    auto end = AscendingIterator<int>::end(container);

    std::cout << "Ascending order: ";
    // Loop through the container from begin to end and print elements
    for (; it != end; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Create an iterator for descending order traversal of the container
    auto it2 = DescendingIterator<int>::begin(container);
    auto end2 = DescendingIterator<int>::end(container);

    std::cout << "Descending order: ";
    // Print elements in descending order
    for (; it2 != end2; ++it2) {
        std::cout << *it2 << " ";
    }
    std::cout << std::endl;

    // Create an iterator for a custom order traversal defined by OrderIterator
    auto it4 = OrderIterator<int>::begin(container);
    auto end4 = OrderIterator<int>::end(container);

    std::cout << "Side Cross order: ";
    // Create an iterator for SideCrossOrder traversal (alternating smallest/largest)
    auto it5 = SideCrossOrder<int>::begin(container);
    auto end5 = SideCrossOrder<int>::end(container);
    for (; it5 != end5; ++it5) {
        std::cout << *it5 << " ";
    }
    std::cout << std::endl;

    // Create an iterator for MiddleOutOrder traversal (middle element first, then left/right alternating)
    auto it6 = MiddleOutOrder<int>::begin(container);
    auto end6 = MiddleOutOrder<int>::end(container);

    // Create an iterator for reverse traversal (from last to first element)
    auto it3 = ReverseIterator<int>::begin(container);
    auto end3 = ReverseIterator<int>::end(container);

    std::cout << "Reverse order: ";
    for (; it3 != end3; ++it3) {
        std::cout << *it3 << " ";
    }
    std::cout << std::endl;

    std::cout << "Order order: ";
    // Print elements in the order defined by OrderIterator
    for (; it4 != end4; ++it4) {
        std::cout << *it4 << " ";
    }
    std::cout << std::endl;

    std::cout << "Middle Out order: ";
    // Print elements in MiddleOutOrder traversal order
    for (; it6 != end6; ++it6) {
        std::cout << *it6 << " ";
    }
    std::cout << std::endl;

    return 0;
}
