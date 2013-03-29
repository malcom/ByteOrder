# ByteOrder #

Portable tools to determine endianness (compile and run time), efficient and
optimized swapping byte order, and convert values between host and
little-/big-endian byte order.


## Determine endianness ##

ByteOrder library defines some useful macros and functions to determine byte
ordering at compile-time and run-time.

Constants specify the possible types of byte order:
```c
#define LITTLE_ENDIAN	1234
#define BIG_ENDIAN		4321
```

Constants specify the name of the possible types of byte order:
```c
#define LITTLE_ENDIAN_NAME	"litte endian"
#define BIG_ENDIAN_NAME		"big endian"
```


### Compile-time ###

Determining endianness at compile-time is the most popular method.
ByteOrder header defines two macros to stores host byte order information.

```c
BYTE_ORDER
```
The host byte order. It can be either `LITTLE_ENDIAN` or `BIG_ENDIAN`.

```c
BYTE_ORDER_NAME
```
The host byte order name. It can be either `LITTLE_ENDIAN_NAME` or `BIG_ENDIAN_NAME`.


### Run-time ###

Similarly to compile-time, library defines two functions to detect
host byte order information.

```c
intByteOrderTest();
```
Dynamically tests the byte order, returns the integer value representing the
ednianess, which can be either `LITTLE_ENDIAN` or `BIG_ENDIAN`.

```c
const char* ByteOrderName(intbo, const char* unknown = NULL);
```
Converts integer value representing the ednianess according to `bo` argument to
its name. If ‘bo’ is not a valid value (`LITTLE_ENDIAN` or `BIG_ENDIAN`), will
return the string passed to `unknown` argument or `NULL`.


## Swap bytes ##

This library defines efficient function to swap bytes in 16/32/64-bit value.

Implementations of these functions, take advantage of the operating system,
platform and compiler (assembler inserts, built-in intrinsics and compiler
extensions) to provide efficient and optimized tools to convert byte order.

The number `NN` in the name of each function indicates the size of integer/data
handled by the function, either 16, 32, or 64 bits.

```c
uintNN_t bswapNN(uintNN_t n);
```

Reverses the byte order of 16/32/64-bit integer. These functions are provided
toconvert value between little-endian and big-endian format.


## Convert byte order ##

This library defines function to convert data and values between host and
little-/big-endian byte order in a simple way.

The number `NN` in the name of each function indicates the size of integer/data
handled by the function, either 16, 32, or 64 bits.

The functions which names start from:
 - `htobe` converts from host byte order to big-endian order
 - `htole` converts from host byte order to little-endian order
 - `betoh` converts from big-endian order to host byte order
 - `letoh` converts from little-endian order to host byte order


### Convert values between host and little-/big-endian byte order ###

```c
uintNN_t htoleNN(uintNN_t n);
uintNN_t letohNN(uintNN_t n);
uintNN_t htobeNN(uintNN_t n);
uintNN_t betohNN(uintNN_t n);
```

These functions convert byte encoding of integer values from the byte
order that the current CPU (the "host") uses, to and from little-endian and
big-endian byte order.

Similar functions are present on Linux and BSD, where the required
header file is `<endian.h>` or `<sys/endian.h>.` For more info see
[ENDIAN(3)](http://www.kernel.org/doc/man-pages/online/pages/man3/endian.3.html).

The only difference is the naming convention, functions in this header have
followed the original OpenBSD naming convention for these functions
(the number indicating the size of integer handled by the function always
appears at the end of the function name).


### Copy and convert data between host and little-/big-endian byte order ###

```c
void htoleNNcpy(void* dest, const void* src);
void letohNNcpy(void* dest, const void* src);
void htobeNNcpy(void* dest, const void* src);
void betohNNcpy(void* dest, const void* src);
```

These functions copy data from `src` to `dest` with convertingbyte encoding of
data from the byte order that the current CPU (the "host") uses, to and from
little-endian and big-endian byte order.


### C++ template version ###

This library defines also some special C++ template functions to convert byte
encoding of any types. The choice of implementation of appropriate function is
made in regard to size of type deduced by the compiler at compile time.

```c++
template<typename T> inline T htole(T n);
template<typename T> inline T letoh(T n);
template<typename T> inline T htobe(T n);
template<typename T> inline T betoh(T n);
```

These functions convert byte encoding of any type of 16/32/64-bit values
from the byte order that the current CPU (the "host") uses, to and from
little-endian and big-endian byte order.
