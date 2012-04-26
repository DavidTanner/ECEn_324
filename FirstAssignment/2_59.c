#include <stdio.h>


int main() 
{
    unsigned x,y,z;
    int done;
    
    done = 0;
    printf("Enter 0 for both x and y to quit\n");
    while (!done)
    {
	// output prompt and get value of x
	printf("Input (hex) value of x: ");
	scanf("%x",&x);
	printf("Input (hex) value of y: ");
	scanf("%x",&y);

	// you add code here to compute z consisting of least
	// significant byte of x and remaining bytes of y
    z = (x & 0x000000FF) | (y & 0xFFFFFF00);

	

	// now output result
	printf("Result = 0x%.8x [Input values were 0x%.8x (x) and 0x%.8x (y)]\n",
	       z,x,y);
	if (x == 0 && y == 0)
	    done = 1;
    }
}
