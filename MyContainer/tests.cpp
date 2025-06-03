//noamglikman1@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "AscendingOrder.hpp"
#include "DescendingOrder.hpp"
#include "MiddleOutOrder.hpp"
#include "MyContainer.hpp"
#include "Order.hpp"
#include "ReverseOrder.hpp"
#include "SideCrossOrder.hpp"
#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "doctest.h"

using namespace my;

//test cases for MyContainer
TEST_CASE("MyContainer basic operations") {
    MyContainer<int> container;
    container.add(5);
    container.add(10);
    container.add(15);

    CHECK(container.size() == 3);
    CHECK(container.getData() == std::vector<int>({5, 10, 15}));
}
//test cases for MyContainer with empty container
TEST_CASE("MyContainer with empty container") {
    MyContainer<int> container;
    CHECK(container.size() == 0);
    CHECK(container.getData().empty());
}
//test cases for MyContainer with single element
TEST_CASE("MyContainer with single element") {
    MyContainer<int> container;
    container.add(42);

    CHECK(container.size() == 1);
    CHECK(container.getData() == std::vector<int>({42}));
}
//test cases for MyContainer about removing elements
TEST_CASE("MyContainer remove elements") {
    MyContainer<int> container;
    container.add(1);
    container.add(2);
    container.add(3);
    container.remove(2);

    CHECK(container.size() == 2);
    CHECK(container.getData() == std::vector<int>({1, 3}));
}
//test cases for MyContainer removing non-existing element
TEST_CASE("MyContainer remove non-existing element") {
    MyContainer<int> container;
    container.add(1);
    container.add(2);

    CHECK_THROWS_AS(container.remove(3), std::runtime_error);
    CHECK(container.size() == 2); // size should remain unchanged
    CHECK(container.getData() == std::vector<int>({1, 2}));
}
//test cases for MyContainer with "size" method
TEST_CASE("MyContainer size method") {
    MyContainer<int> container;
    CHECK(container.size() == 0); // initially empty

    container.add(1);
    CHECK(container.size() == 1);

    container.add(2);
    CHECK(container.size() == 2);

    container.remove(1);
    CHECK(container.size() == 1);

    container.remove(2);
    CHECK(container.size() == 0); // should be empty again
}

//test cases for AscendingIterator, DescendingIterator, MiddleOutOrder, OrderIterator, ReverseIterator, and SideCrossOrder
// tests for AscendingIterator
TEST_CASE("AscendingIterator basic iteration test") {
    MyContainer<int> container; 
    container.add(7);
    container.add(15);
    container.add(6);
    container.add(1);
    container.add(2);

    auto it = AscendingIterator<int>::begin(container);
    auto end = AscendingIterator<int>::end(container);

    std::vector<int> results;
    for (; it != end; ++it) {
        results.push_back(*it);
    }

    std::vector<int> expected = {1, 2, 6, 7, 15};
    CHECK(results == expected);
}
// tests for AscendingIterator with empty container
TEST_CASE("AscendingIterator with empty container") {
    my::MyContainer<int> container;
    auto it = AscendingIterator<int>::begin(container);
    auto end = AscendingIterator<int>::end(container);

    CHECK(it == end); 
}
// tests for AscendingIterator with single element
TEST_CASE("AscendingIterator with single element") {
    my::MyContainer<int> container;
    container.add(42);

    auto it = AscendingIterator<int>::begin(container);
    auto end = AscendingIterator<int>::end(container);

    CHECK(it != end);
    CHECK(*it == 42);

    ++it;
    CHECK(it == end);
}
// tests for AscendingIterator with duplicate elements
TEST_CASE("AscendingIterator with duplicate elements") {
    my::MyContainer<int> container;
    container.add(3);
    container.add(1);
    container.add(3);
    container.add(2);
    container.add(1);

    std::vector<int> expected = {1, 1, 2, 3, 3};

    std::vector<int> result;
    for (auto it = AscendingIterator<int>::begin(container);
         it != AscendingIterator<int>::end(container); ++it) {
        result.push_back(*it);
    }

    CHECK(result == expected);
}
// tests for AscendingIterator should not modify the original container
TEST_CASE("AscendingIterator should not modify the original container") {
    my::MyContainer<int> container;
    container.add(5);
    container.add(2);
    container.add(9);

    AscendingIterator<int> it(container); 
    std::vector<int> original = container.getData();
    CHECK(original == std::vector<int>{5, 2, 9});
}
// tests for AscendingIterator with strings
TEST_CASE("AscendingIterator with strings") {
    my::MyContainer<std::string> container;
    container.add("banana");
    container.add("apple");
    container.add("cherry");

    std::vector<std::string> result;
    for (auto it = AscendingIterator<std::string>::begin(container);
         it != AscendingIterator<std::string>::end(container); ++it) {
        result.push_back(*it);
    }

    std::vector<std::string> expected = {"apple", "banana", "cherry"};
    CHECK(result == expected);
}
//tests for AscendingIterator with double values
TEST_CASE("AscendingIterator with double values") {
    MyContainer<double> container;
    container.add(3.14);
    container.add(2.71);
    container.add(1.41);

    std::vector<double> result;
    for (auto it = AscendingIterator<double>::begin(container);
         it != AscendingIterator<double>::end(container); ++it) {
        result.push_back(*it);
    }

    std::vector<double> expected = {1.41, 2.71, 3.14};
    CHECK(result == expected);
}






// tests for DescendingIterator
// tests for DescendingIterator basic iteration test
//empty container
TEST_CASE("Empty container") {
    MyContainer<int> c;
    auto it = DescendingIterator<int>::begin(c);
    auto end = DescendingIterator<int>::end(c);
    CHECK(it == end);  
}
//single element container
TEST_CASE("Single element container") {
    MyContainer<int> c;
    c.add(42);
    auto it = DescendingIterator<int>::begin(c);
    auto end = DescendingIterator<int>::end(c);

    CHECK(it != end);
    CHECK(*it == 42);
    ++it;
    CHECK(it == end);
}  
//multiple elements, distinct
TEST_CASE("Multiple elements, distinct") {
    MyContainer<int> c;
    c.add(10);
    c.add(20);
    c.add(5);

    auto it = DescendingIterator<int>::begin(c);
    auto end = DescendingIterator<int>::end(c);

    std::vector<int> results;
    while (it != end) {
        results.push_back(*it);
        ++it;
    }
    
    std::vector<int> expected = {20, 10, 5};
    CHECK(results == expected);
}
//multiple elements, duplicates
TEST_CASE("Multiple elements, duplicates") {
    MyContainer<int> c;
    c.add(5);
    c.add(10);
    c.add(5);
    c.add(20);
    c.add(10);

    auto it = DescendingIterator<int>::begin(c);
    auto end = DescendingIterator<int>::end(c);

    std::vector<int> results;
    while (it != end) {
        results.push_back(*it);
        ++it;
    }
    std::vector<int> expected = {20, 10, 10, 5, 5};
    CHECK(results == expected);
}
//tests for DescendingIterator with double values
TEST_CASE("DescendingIterator with double values") {
    MyContainer<double> c;
    c.add(3.14);
    c.add(2.71);
    c.add(1.41);

    auto it = DescendingIterator<double>::begin(c);
    auto end = DescendingIterator<double>::end(c);

    std::vector<double> results;
    while (it != end) {
        results.push_back(*it);
        ++it;
    }
    
    std::vector<double> expected = {3.14, 2.71, 1.41};
    CHECK(results == expected);
}
//DescendingIterator works with strings
TEST_CASE("DescendingIterator works with strings") {
    MyContainer<std::string> sc;
    sc.add("apple");
    sc.add("orange");
    sc.add("banana");
    sc.add("apple");

    auto it = DescendingIterator<std::string>::begin(sc);
    auto end = DescendingIterator<std::string>::end(sc);

    std::vector<std::string> results;
    while (it != end) {
        results.push_back(*it);
        ++it;
    }
    std::vector<std::string> expected = {"orange", "banana", "apple", "apple"};
    CHECK(results == expected);
}





// tests for MiddleOutOrderIterator
// tests for MiddleOutOrderIterator basic tests
//empty container
TEST_CASE("Empty container") {
    MyContainer<int> c;
    auto it = MiddleOutOrder<int>::begin(c);
    auto end = MiddleOutOrder<int>::end(c);
    CHECK(it == end);  
}
//single element container
TEST_CASE("Single element container") {
    MyContainer<int> c;
    c.add(42);
    auto it = MiddleOutOrder<int>::begin(c);
    auto end = MiddleOutOrder<int>::end(c);

    CHECK(it != end);
    CHECK(*it == 42);
    ++it;
    CHECK(it == end);
}
//multiple elements, distinct
TEST_CASE("Multiple elements, distinct") {
    MyContainer<int> c;
    c.add(10);
    c.add(20);
    c.add(5);

    auto it = MiddleOutOrder<int>::begin(c);
    auto end = MiddleOutOrder<int>::end(c);

    std::vector<int> results;
    while (it != end) {
        results.push_back(*it);
        ++it;
    }
    
    std::vector<int> expected = {20, 10, 5};
    CHECK(results == expected);
}
//multiple elements, duplicates
TEST_CASE("Multiple elements, duplicates") {
    MyContainer<int> c;
    c.add(5);
    c.add(10);
    c.add(5);
    c.add(20);
    c.add(10);

    auto it = MiddleOutOrder<int>::begin(c);
    auto end = MiddleOutOrder<int>::end(c);

    std::vector<int> results;
    while (it != end) {
        results.push_back(*it);
        ++it;
    }
    std::vector<int> expected = {5, 10, 20, 5, 10};
    CHECK(results == expected);
}
// tests for MiddleOutOrderIterator with double values
TEST_CASE("MiddleOutOrderIterator with double values") {
    MyContainer<double> c;
    c.add(3.14);
    c.add(2.71);
    c.add(1.41);

    auto it = MiddleOutOrder<double>::begin(c);
    auto end = MiddleOutOrder<double>::end(c);

    std::vector<double> results;
    while (it != end) {
        results.push_back(*it);
        ++it;
    }
    
    std::vector<double> expected = {2.71, 3.14, 1.41};
    CHECK(results == expected);
}
//MiddleOutOrderIterator works with strings
TEST_CASE("MiddleOutOrderIterator works with strings") {
    MyContainer<std::string> sc;
    sc.add("apple");
    sc.add("orange");
    sc.add("banana");
    sc.add("apple");

    auto it = MiddleOutOrder<std::string>::begin(sc);
    auto end = MiddleOutOrder<std::string>::end(sc);

    std::vector<std::string> results;
    while (it != end) {
        results.push_back(*it);
        ++it;
    }
    std::vector<std::string> expected = {"banana","orange", "apple","apple"};
    CHECK(results == expected);
}







// tests for OrderIterator
TEST_CASE("Order basic iteration test") {
    MyContainer<int> container; 
    container.add(7);
    container.add(15);
    container.add(6);
    container.add(1);
    container.add(2);

    auto it = OrderIterator<int>::begin(container);
    auto end = OrderIterator<int>::end(container);

    std::vector<int> results;
    for (; it != end; ++it) {
        results.push_back(*it);
    }

    std::vector<int> expected = {7,15,6,1,2};
    CHECK(results == expected);
}
// tests for OrderIterator with empty container
TEST_CASE("Order with empty container") {
    my::MyContainer<int> container;
    auto it = OrderIterator<int>::begin(container);
    auto end = OrderIterator<int>::end(container);

    CHECK(it == end); 
}
// tests for OrderIterator with single element
TEST_CASE("Order with single element") {
    my::MyContainer<int> container;
    container.add(42);

    auto it = OrderIterator<int>::begin(container);
    auto end = OrderIterator<int>::end(container);

    CHECK(it != end);
    CHECK(*it == 42);

    ++it;
    CHECK(it == end);
}
// tests for OrderIterator with duplicate elements
TEST_CASE("Order with duplicate elements") {
    my::MyContainer<int> container;
    container.add(3);
    container.add(1);
    container.add(3);
    container.add(2);
    container.add(1);

    std::vector<int> expected = {3,1,3,2,1};

    std::vector<int> result;
    for (auto it = OrderIterator<int>::begin(container);
         it != OrderIterator<int>::end(container); ++it) {
        result.push_back(*it);
    }

    CHECK(result == expected);
}
// tests for OrderIterator should not modify the original container
TEST_CASE("Order should not modify the original container") {
    my::MyContainer<int> container;
    container.add(5);
    container.add(2);
    container.add(9);

    OrderIterator<int> it(container); 
    std::vector<int> original = container.getData();
    CHECK(original == std::vector<int>{5, 2, 9});
}
//test for OrderIterator with double values
TEST_CASE("Order with double values") {
    MyContainer<double> container;
    container.add(3.14);
    container.add(2.71);
    container.add(1.41);

    std::vector<double> result;
    for (auto it = OrderIterator<double>::begin(container);
         it != OrderIterator<double>::end(container); ++it) {
        result.push_back(*it);
    }

    std::vector<double> expected = {3.14, 2.71, 1.41};
    CHECK(result == expected);
}
// tests for OrderIterator with strings
TEST_CASE("Order with strings") {
    my::MyContainer<std::string> container;
    container.add("banana");
    container.add("apple");
    container.add("cherry");

    std::vector<std::string> result;
    for (auto it = OrderIterator<std::string>::begin(container);
         it != OrderIterator<std::string>::end(container); ++it) {
        result.push_back(*it);
    }

    std::vector<std::string> expected = {"banana", "apple", "cherry"};
    CHECK(result == expected);
}






// tests for ReverseIterator
TEST_CASE("Reverse basic iteration test") {
    MyContainer<int> container; 
    container.add(7);
    container.add(15);
    container.add(6);
    container.add(1);
    container.add(2);

    auto it = ReverseIterator<int>::begin(container);
    auto end = ReverseIterator<int>::end(container);

    std::vector<int> results;
    for (; it != end; ++it) {
        results.push_back(*it);
    }

    std::vector<int> expected = {2, 1, 6, 15, 7};
    CHECK(results == expected);
}
// tests for ReverseIterator with empty container
TEST_CASE("Reverse with empty container") {
    my::MyContainer<int> container;
    auto it = ReverseIterator<int>::begin(container);
    auto end = ReverseIterator<int>::end(container);

    CHECK(it == end); 
}
// tests for ReverseIterator with single element
TEST_CASE("Reverse with single element") {
    my::MyContainer<int> container;
    container.add(42);

    auto it = ReverseIterator<int>::begin(container);
    auto end = ReverseIterator<int>::end(container);

    CHECK(it != end);
    CHECK(*it == 42);

    ++it;
    CHECK(it == end);
}
// tests for ReverseIterator with duplicate elements
TEST_CASE("Reverse with duplicate elements") {
    my::MyContainer<int> container;
    container.add(3);
    container.add(1);
    container.add(3);
    container.add(2);
    container.add(1);

    std::vector<int> expected = {1,2,3,1,3};

    std::vector<int> result;
    for (auto it = ReverseIterator<int>::begin(container);
         it != ReverseIterator<int>::end(container); ++it) {
        result.push_back(*it);
    }

    CHECK(result == expected);
}
// tests for ReverseIterator should not modify the original container
TEST_CASE("Reverse should not modify the original container") {
    my::MyContainer<int> container;
    container.add(5);
    container.add(2);
    container.add(9);

    ReverseIterator<int> it(container); 
    std::vector<int> original = container.getData();
    CHECK(original == std::vector<int>{5,2,9});
}
// tests for ReverseIterator with double values
TEST_CASE("Reverse with double values") {
    MyContainer<double> container;
    container.add(3.14);
    container.add(2.71);
    container.add(1.41);

    std::vector<double> result;
    for (auto it = ReverseIterator<double>::begin(container);
         it != ReverseIterator<double>::end(container); ++it) {
        result.push_back(*it);
    }

    std::vector<double> expected = {1.41, 2.71, 3.14};
    CHECK(result == expected);
}
// tests for ReverseIterator with strings
TEST_CASE("Reverse with strings") {
    my::MyContainer<std::string> container;
    container.add("banana");
    container.add("apple");
    container.add("cherry");

    std::vector<std::string> result;
    for (auto it = ReverseIterator<std::string>::begin(container);
         it != ReverseIterator<std::string>::end(container); ++it) {
        result.push_back(*it);
    }

    std::vector<std::string> expected = {"cherry", "apple", "banana"};
    CHECK(result == expected);
}





// tests for SideCrossOrder
TEST_CASE("SideCross iteration test") {
    MyContainer<int> container; 
    container.add(7);
    container.add(15);
    container.add(6);
    container.add(1);
    container.add(2);

    auto it = SideCrossOrder<int>::begin(container);
    auto end = SideCrossOrder<int>::end(container);

    std::vector<int> results;
    for (; it != end; ++it) {
        results.push_back(*it);
    }

    std::vector<int> expected = {1,15,2,7,6};
    CHECK(results == expected);
}
// tests for SideCrossOrder with empty container
TEST_CASE("SideCross with empty container") {
    my::MyContainer<int> container;
    auto it = SideCrossOrder<int>::begin(container);
    auto end = SideCrossOrder<int>::end(container);

    CHECK(it == end); 
}
// tests for SideCrossOrder with single element
TEST_CASE("SideCross with single element") {
    my::MyContainer<int> container;
    container.add(42);

    auto it = SideCrossOrder<int>::begin(container);
    auto end = SideCrossOrder<int>::end(container);

    CHECK(it != end);
    CHECK(*it == 42);

    ++it;
    CHECK(it == end);
}
// tests for SideCrossOrder with duplicate elements
TEST_CASE("SideCross with duplicate elements") {
    my::MyContainer<int> container;
    container.add(3);
    container.add(1);
    container.add(3);
    container.add(2);
    container.add(1);

    std::vector<int> expected = {1,3,1,3,2};

    std::vector<int> result;
    for (auto it = SideCrossOrder<int>::begin(container);
         it != SideCrossOrder<int>::end(container); ++it) {
        result.push_back(*it);
    }
    CHECK(result == expected);
    
}
// tests for SideCrossOrder should not modify the original container
TEST_CASE("SideCross should not modify the original container") {
    my::MyContainer<int> container;
    container.add(5);
    container.add(2);
    container.add(9);

    SideCrossOrder<int> it(container); 
    std::vector<int> original = container.getData();
    CHECK(original == std::vector<int>{5,2,9});
}
// tests for SideCrossOrder with double values
TEST_CASE("SideCross with double values") {
    MyContainer<double> container;
    container.add(3.14);
    container.add(2.71);
    container.add(1.41);

    std::vector<double> result;
    for (auto it = SideCrossOrder<double>::begin(container);
         it != SideCrossOrder<double>::end(container); ++it) {
        result.push_back(*it);
    }

    std::vector<double> expected = {1.41, 3.14, 2.71};
    CHECK(result == expected);
}
// tests for SideCrossOrder with strings
TEST_CASE("SideCross with strings") {
    my::MyContainer<std::string> container;
    container.add("banana");
    container.add("apple");
    container.add("cherry");

    std::vector<std::string> result;
    for (auto it = SideCrossOrder<std::string>::begin(container);
         it != SideCrossOrder<std::string>::end(container); ++it) {
        result.push_back(*it);
    }

    std::vector<std::string> expected = {"apple", "cherry","banana"};
    CHECK(result == expected);
}
