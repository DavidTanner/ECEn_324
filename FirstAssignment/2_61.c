#include <stdio.h>
#include <limits.h> // defines INT_MIN and INT_MAX


#define TEST_SIZE 10

int any_bit_one(int x) {
    
	return x || x;
}

int any_bit_zero(int x) {
	return ~x || ~x;
}

int lsb_one(int x) {
    int temp = (x & 0x000000FF);
	return temp || temp;
}

int msb_zero(int x) {
    int temp = (~x) & 0xFF000000;
	return temp || temp;
}

int main(void) {
	int x;
	// Test all integer values
	for (x = INT_MIN; x <= INT_MAX; x++) {
		if (any_bit_one(x) != (x != 0)) {
			printf("Any bit in x equal to 1	FAILED!\n");
			break;
		}
		if (any_bit_zero(x) != (x != -1)) {
			printf("Any bit in x equal to 0 FAILED!\n");
			break;
		}
		if (lsb_one(x) != ((char) x != 0)) {
			printf(
                   "Any bit in least significant byte in x equal to 1 FAILED!\n");
			break;
		}
		if (msb_zero(x) != (*((char*) &x + 3) != -1)) {
			printf(
                   "Any bit in most significant byte in x equal to 0 FAILED!\n");
			break;
		}
        
		// Print out something so you know that stuff is happening
		if (x % 100000000 == 0) {
			printf("%d\n", x);
		}
        
		// Have to have a way to break out before we loop around to INT_MIN
		if (x == INT_MAX) {
			printf("All tests passed!\n");
			break;
		}
	}
    
    int test_all[TEST_SIZE] = {0,1,-1,INT_MAX,INT_MIN,0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF, 0x01010101};
    
	// Enter the numbers you want to test
    int i;
	for (i = 0; i < TEST_SIZE; i++) {
		printf("any_bit_one(0x%08x) = %d\n", test_all[i],
               any_bit_one(test_all[i]));
               
		printf("any_bit_zero(0x%08x) = %d\n", test_all[i],
               any_bit_zero(test_all[i]));
               
		printf("lsb_one(0x%08x) = %d\n", test_all[i],
               lsb_one(test_all[i]));
               
		printf("msb_zero(0x%08x) = %d\n", test_all[i],
               msb_zero(test_all[i]));
        
        printf("\n");
	}
}




//-2100000000
//-2000000000
//-1900000000
//-1800000000
//-1700000000
//-1600000000
//-1500000000
//-1400000000
//-1300000000
//-1200000000
//-1100000000
//-1000000000
//-900000000
//-800000000
//-700000000
//-600000000
//-500000000
//-400000000
//-300000000
//-200000000
//-100000000
//0
//100000000
//200000000
//300000000
//400000000
//500000000
//600000000
//700000000
//800000000
//900000000
//1000000000
//1100000000
//1200000000
//1300000000
//1400000000
//1500000000
//1600000000
//1700000000
//1800000000
//1900000000
//2000000000
//2100000000
//All tests passed!
//
//any_bit_one(0x00000000) = 0
//any_bit_zero(0x00000000) = 1
//lsb_one(0x00000000) = 0
//msb_zero(0x00000000) = 1
//
//any_bit_one(0x00000001) = 1
//any_bit_zero(0x00000001) = 1
//lsb_one(0x00000001) = 1
//msb_zero(0x00000001) = 1
//
//any_bit_one(0xffffffff) = 1
//any_bit_zero(0xffffffff) = 0
//lsb_one(0xffffffff) = 1
//msb_zero(0xffffffff) = 0
//
//any_bit_one(0x7fffffff) = 1
//any_bit_zero(0x7fffffff) = 1
//lsb_one(0x7fffffff) = 1
//msb_zero(0x7fffffff) = 1
//
//any_bit_one(0x80000000) = 1
//any_bit_zero(0x80000000) = 1
//lsb_one(0x80000000) = 0
//msb_zero(0x80000000) = 1
//
//any_bit_one(0xff000000) = 1
//any_bit_zero(0xff000000) = 1
//lsb_one(0xff000000) = 0
//msb_zero(0xff000000) = 0
//
//any_bit_one(0x00ff0000) = 1
//any_bit_zero(0x00ff0000) = 1
//lsb_one(0x00ff0000) = 0
//msb_zero(0x00ff0000) = 1
//
//any_bit_one(0x0000ff00) = 1
//any_bit_zero(0x0000ff00) = 1
//lsb_one(0x0000ff00) = 0
//msb_zero(0x0000ff00) = 1
//
//any_bit_one(0x000000ff) = 1
//any_bit_zero(0x000000ff) = 1
//lsb_one(0x000000ff) = 1
//msb_zero(0x000000ff) = 1
//
//any_bit_one(0x01010101) = 1
//any_bit_zero(0x01010101) = 1
//lsb_one(0x01010101) = 1
//msb_zero(0x01010101) = 1


