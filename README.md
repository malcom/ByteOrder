ByteOrder
=========

Portable tools to determine endianness (compile and run time), efficient and
optimized swapping byte order, and convert values between host and
little-/big-endian byte order.


## Overview ##

Microprocessor’s architectures commonly use two different methods and conventions
to store data in memory, referred as "byte ordering". Some computers put the most
significant byte within a word as a first one ("big-endian" order), and others put
it as a last one ("little-endian" order).

Most of the time, the endianness can be ignored, the programmer does not need to
worry about which format is used, but in some certain situations, it becomes
important. While implementing some binary file format, network library or protocol,
or transferring binary data between different computer, you need to be concerned
about byte order issues.

Currently, it doesn't exist any standard specifying common and portable interface
or libraries containing functions for maintaining endiandess and conversion
between types of byte order (POSIX defines only network functions changing byte
order of `ntoh*` and `hton*` family). Therefore this library was created.

The **ByteOrder** library (one header library) provides simple, portable tools
and API to manage endianness, determine byte order, swap bytes, and convert value
between host and little-/big-endian byte order.

Implementations take advantage of the operating system, platform and compiler
(assembler inserts, built-in intrinsics and compiler extensions) in order to
provide efficient and optimized tools to convert byte order.


## Documentation ##

Documentation is available [here](http://github.com/malcom/ByteOrder/blob/master/docs.md).


## Example Usage ##

Simple example of usage is available [here](http://github.com/malcom/ByteOrder/blob/master/example.cpp).


## Portability ##

**ByteOrder** works on popular platforms like Unix and BSD systems, Linux,
Windows and MacOS. Should be compiled without any problems on any modern
C and C++ compiler (C99, C11, C++98, C++11).


## License ##

Released under the [MIT License](http://opensource.org/licenses/MIT).


## Links ##
* [ByteOrder at projects.malcom.pl](http://projects.malcom.pl/libs/byteorder.xhtml) [pl]
* [ByteOrder at MalDevBlog](http://blog.malcom.pl/2013/03/29/byteorder-kolejnosc-bajtow/) [pl]
