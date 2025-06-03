noamglikman1@gmail.com
---

## Compilation & Execution

The project uses a standard `Makefile`. Run the following commands from the project root:

| Command         | Description                                |
| `make demo_run`     | Compile and run the demo program           |
| `make test_run`     | Compile and run unit tests with doctest    |
| `make valgrind` | Run memory checks with valgrind            |
| `make clean`    | Remove build files and executables         |

---

## Class: MyContainer

The `MyContainer` class is a dynamic container supporting any comparable type.

### Key Methods:
- `void add(const T& element)` — Add an element to the container.
- `void remove(const T& element)` — Remove **all** occurrences of an element. Throws an exception if not found.
- `size_t size() const` — Return the current size of the container.
- `friend std::ostream& operator<<` — Print the container contents.

### Template Support:
The class is templated to support types like `int`, `double`, `std::string`, etc.

---

## Iterators

Each iterator supports `begin()` and `end()` methods and overloads `*`, `++`, `==`, `!=`.

* **Project stracture:**
```bash
.
├── HPP
│   ├── AscendingOrder.hpp
│   ├── DescendingOrder.hpp
│   ├── MiddleOutOrder.hpp
│   ├── MyContainer.hpp
│   ├── Order.hpp
│   ├── ReverseOrder.hpp
│   ├── SideCrossOrder.hpp
│   └── doctest.h
├── OBJ
│   └── tests.o
├── ReadME.md
├── demo.cpp
├── makefile
├── tests
└── tests.cpp
```
### Supported Iterators:

| Name               | Description |
|--------------------|-------------|
| `AscendingOrder`   | Sorts in increasing order. E.g., `[1, 2, 6, 7, 15]` |
| `DescendingOrder`  | Sorts in decreasing order. E.g., `[15, 7, 6, 2, 1]` |
| `SideCrossOrder`   | Alternates smallest, largest, next smallest, next largest... E.g., `[1, 15, 2, 7, 6]` |
| `ReverseOrder`     | Reverses the original insertion order. E.g., `[2, 1, 6, 15, 7]` |
| `Order`            | Keeps original insertion order. E.g., `[7, 15, 6, 1, 2]` |
| `MiddleOutOrder`   | Starts from the middle, alternating left and right. E.g., `[6, 15, 1, 7, 2]` |

---

## Unit Testing

The project uses [doctest]

- All member functions of `MyContainer`
- Edge cases (e.g., removing non-existing elements)
- All iterators and their traversal logic

---

## Memory Safety

Run `make valgrind` to ensure no memory leaks exist. All dynamic allocations are properly managed.

---

## Dependencies

- C++17 or higher
- `doctest` (included in test files)
- `valgrind` for memory analysis (Linux/macOS)

---

## Notes

- All iterator logic is encapsulated and reusable.
- Namespace used: `my` (update to your actual namespace).
- Code is split into `.hpp` and `.cpp` files as per standard practice oll iterator is in `.hpp`.
---

## Contact

For any questions or suggestions, please contact:  
_[noamglikman1@gmail.com]_

---
