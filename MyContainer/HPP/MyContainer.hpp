
// noamglikman1@gmail.com

#ifndef MY_CONTAINER_H
#define MY_CONTAINER_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <type_traits>
#include <iostream>

namespace my {

/**
 * @brief A generic container class that holds elements of type T.
 * 
 * This class provides basic container functionality such as adding, removing,
 * and accessing elements, while internally using a std::vector to store the data.
 * 
 * @tparam T The type of elements stored in the container. Defaults to int.
 */
template <typename T = int>
class MyContainer {
    // static_assert(std::is_copy_constructible<T>::value, "T must be copy constructible");
    // static_assert(std::is_copy_assignable<T>::value, "T must be copy assignable");
    // static_assert(
    //     std::is_convertible<decltype(std::declval<T>() < std::declval<T>()), bool>::value,
    //     "T must support operator< for sorting"
    // );
    // static_assert(
    //     std::is_convertible<decltype(std::declval<std::ostream&>() << std::declval<T>()), std::ostream&>::value,
    //     "T must support operator<< for printing"
    // );
private:
    std::vector<T> data; ///< Internal storage of elements

public:
    
    /**
     * @brief Adds a new element to the container.
     * 
     * @param value The element to add.
     */
    void add(const T& value) {
        data.push_back(value);
    }

    /**
     * @brief Removes all occurrences of a given element from the container.
     * 
     * If the element is not found, throws a std::runtime_error.
     * 
     * @param value The element to remove.
     * @throws std::runtime_error if the element is not found in the container.
     */
    void remove(const T& value) {
        auto oldSize = data.size();
        // Moves all elements equal to value to the end and erases them physically
        data.erase(std::remove(data.begin(), data.end(), value), data.end());
        if (data.size() == oldSize) {
            throw std::runtime_error("Error: element not found in container.");
        }
    }

    /**
     * @brief Returns the number of elements currently stored in the container.
     * 
     * @return int The container size.
     */
    int size() const {
        return static_cast<int>(data.size());
    }

    /**
     * @brief Outputs the container's size and elements to the given output stream.
     * 
     * Format: "Size: N, Elements: [elem1, elem2, ...]"
     * 
     * @param os The output stream.
     * @param container The container to output.
     * @return std::ostream& The output stream after writing.
     */
    friend std::ostream& operator<<(std::ostream& os, const MyContainer<T>& container) {
        os << "Size: " << container.data.size() << ", Elements: [";
        for (size_t i = 0; i < container.data.size(); ++i) {
            os << container.data[i];
            if (i < container.data.size() - 1) os << ", ";
        }
        os << "]";
        return os;
    }

    /**
     * @brief Provides const access to the internal data vector.
     * 
     * Used primarily by iterators or other helper classes to read container data.
     * 
     * @return const std::vector<T>& Reference to the internal data vector.
     */
    const std::vector<T>& getData() const {
        return data;
    }

};

} // namespace my

#endif // MY_CONTAINER_H
