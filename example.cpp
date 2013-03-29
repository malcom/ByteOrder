/*
 * Example program for ByteOrder.
 *
 * The program below display the results of determining ednianess, converting
 * an integer from host byte order to little-endian and big-endian byte order.
 */

#include <stdio.h>

#ifdef __cplusplus
	#include <iostream>
	// hack for inttypes macros in C++
	#define __STDC_FORMAT_MACROS
#endif // __cplusplus

#include <stdint.h>
#include <inttypes.h>

#include "byteorder.h"

int main(int argc, char* argv[]) {

	printf("static byte order = %d\n", BYTE_ORDER);
	printf("static byte order = %s\n", BYTE_ORDER_NAME);
	printf("\n");

	int bo = ByteOrderTest();
	printf("dynamic byte order = %d\n", bo);
	printf("dynamic byte order = %s\n", ByteOrderName(bo, "unknown"));
	printf("\n");


	union {
		uint16_t u16;
		uint32_t u32;
		uint64_t u64;
		uint8_t arr[8];
	} x;

	x.arr[0] = 0x11;
	x.arr[1] = 0x22;
	x.arr[2] = 0x33;
	x.arr[3] = 0x44;
	x.arr[4] = 0x55;
	x.arr[5] = 0x66;
	x.arr[6] = 0x77;
	x.arr[7] = 0x88;


	printf("x.u16 = 0x%" PRIx16 "\n", x.u16);
	printf("htole16(x.u16) = 0x%" PRIx16 "\n", htole16(x.u16));
	printf("htobe16(x.u16) = 0x%" PRIx16 "\n", htobe16(x.u16));
	printf("\n");

	printf("x.u32 = 0x%" PRIx32 "\n", x.u32);
	printf("htole32(x.u32) = 0x%" PRIx32 "\n", htole32(x.u32));
	printf("htobe32(x.u32) = 0x%" PRIx32 "\n", htobe32(x.u32));
	printf("\n");

	printf("x.u64 = 0x%" PRIx64 "\n", x.u64);
	printf("htole64(x.u64) = 0x%" PRIx64 "\n", htole64(x.u64));
	printf("htobe64(x.u64) = 0x%" PRIx64 "\n", htobe64(x.u64));
	printf("\n");


	uint16_t leu16 = 0;
	uint16_t beu16 = 0;

	htole16cpy(&leu16, &x.u16);
	htobe16cpy(&beu16, &x.u16);

	printf("x.u16 = 0x%" PRIx16 "\n", x.u16);
	printf("htole16cpy(x.u16) = 0x%" PRIx16 "\n", leu16);
	printf("htobe16cpy(x.u16) = 0x%" PRIx16 "\n", beu16);
	printf("\n");

	uint32_t leu32 = 0;
	uint32_t beu32 = 0;

	htole32cpy(&leu32, &x.u32);
	htobe32cpy(&beu32, &x.u32);

	printf("x.u32 = 0x%" PRIx32 "\n", x.u32);
	printf("htole32cpy(x.u32) = 0x%" PRIx32 "\n", leu32);
	printf("htobe32cpy(x.u32) = 0x%" PRIx32 "\n", beu32);
	printf("\n");

	uint64_t leu64 = 0;
	uint64_t beu64 = 0;

	htole64cpy(&leu64, &x.u64);
	htobe64cpy(&beu64, &x.u64);

	printf("x.u64 = 0x%" PRIx64 "\n", x.u64);
	printf("htole64cpy(x.u64) = 0x%" PRIx64 "\n", leu64);
	printf("htobe64cpy(x.u64) = 0x%" PRIx64 "\n", beu64);
	printf("\n");


	double d = 1.123456;
	double dle = 0;
	double dbe = 0;

	printf("d = %e\n", d);

	htole64cpy(&dle, &d);
	htobe64cpy(&dbe, &d);

	printf("htole64cpy(d) = %e\n", dle);
	printf("htobe64cpy(d) = %e\n", dbe);

	double dlep = 0;
	double dbep = 0;

	letoh64cpy(&dlep, &dle);
	betoh64cpy(&dbep, &dbe);

	printf("letoh64cpy(d') = %e\n", dlep);
	printf("betoh64cpy(d') = %e\n", dbep);
	printf("\n");


#ifdef __cplusplus

	std::cout.setf(std::ios::hex, std::ios::basefield);
	std::cout.setf(std::ios::showbase);

	std::cout << "x.u16 = " << x.u16 << "\n";
	std::cout << "htole(x.u16) = " << htole(x.u16) << "\n";
	std::cout << "htobe(x.u16) = " << htobe(x.u16) << "\n";
	std::cout << std::endl;
	
	std::cout << "x.u32 = " << x.u32 << "\n";
	std::cout << "htole(x.u32) = " << htole(x.u32) << "\n";
	std::cout << "htobe(x.u32) = " << htobe(x.u32) << "\n";
	std::cout << std::endl;
	
	std::cout << "x.u64 = " << x.u64 << "\n";
	std::cout << "htole(x.u64) = " << htole(x.u64) << "\n";
	std::cout << "htobe(x.u64) = " << htobe(x.u64) << "\n";
	std::cout << std::endl;

	std::cout.setf(std::ios::scientific);

	d = 1.123456;
	dle = htole(d);
	dbe = htobe(d);

	std::cout << "d = " << d << "\n";
	std::cout << "htole(d) = " << dle << "\n";
	std::cout << "htobe(d) = " << dbe << "\n";
	std::cout << "letoh(d') = " << letoh(dle) << "\n";
	std::cout << "betoh(d') = " << betoh(dbe) << "\n";
	std::cout << std::endl;

#endif // __cplusplus

	return 0;
}
