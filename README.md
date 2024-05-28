# Vladutz C Library

Welcome to the Vladutz C Library! This library provides a collection of essential utilities and data structures for C programming, including memory management, threading, string manipulation, networking, and cryptography.

### Features

* **Memory Management:** Custom memory allocation functions.
* **Threading:** Lightweight threading and synchronization primitives.
* **String Manipulation:** Functions for string operations.
* **Networking:** Basic socket programming utilities.
* **Cryptography:** Implementation of AES encryption and other cryptographic operations.
* **Date/Time Manipulation:** Functions for working with dates and times.
* **Input/Output:** Custom implementations for file and console I/O.

### Installation
***Prerequisites***

 - CMake 3.27.4 or higher 
 - A C compiler (GCC, Clang, etc.)

***Building the Library***
1. Clone the repository:
    ```
    git clone https://github.com/yourusername/vladutz_clib.git
    cd vladutz_clib
    ```
   
2. Create a build directory and navigate into it:
    ```
    mkdir build
    cd build
    ```
 
3. Configure the project with CMake:
    ```
    cmake ..
    ```
   
4. Build the library:
    ```
    make -j$(nproc)
    ```

### Usage
***Including the Library***

In your C projects, include the header files from the include directory:

```#include "vladutz_lib.h"```

### Issues

If you encounter any issues or have any questions, please create an issue in the repository.
