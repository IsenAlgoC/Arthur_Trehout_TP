#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iso646.h> 


// Renvoie la notation decimale par point du masque, ou number_of_one
// represente le nombre de 1 en partant de la gauche dans la representation
// binaire naturel sur 32 bit.

unsigned int* dot_decimal_mask(unsigned int number_of_one)
{
	static int dd_mask[4] = { 0 };
	int quotient = (int)(number_of_one / 8);
	for (int i = 0; i < quotient; i++)
		dd_mask[i] = 255;
	int remainder = number_of_one % 8;
	if (remainder != 0 && (number_of_one <= 31))
		for (int p = 8; p > 0; p--)
			dd_mask[quotient] += (int)pow(2, p);
	return dd_mask;
}

void main()
{
	// adr IPv4 : w.x.y.z/n
	unsigned int MyAddress_w = 192;
	unsigned int MyAddress_x = 168;
	unsigned int MyAddress_y = 129;
	unsigned int MyAddress_z = 10;

	unsigned int IPv4MaskLength = 24;

	unsigned int* mask = dot_decimal_mask(IPv4MaskLength);
	unsigned int mask_w = mask[0];
	unsigned int mask_x = mask[1];
	unsigned int mask_y = mask[2];
	unsigned int mask_z = *(mask + 3); 

	//for (int i = 0; i < 4; i++) {
	//	dot_decimal_mask(IPv4MaskLength);
	//  printf("%d ", *(mask + i));
	//}

	// Adresse reseau 
	unsigned int netAddress_w = MyAddress_w & mask_w,
		netAddress_x = MyAddress_x & mask_x,
		netAddress_y = MyAddress_y & mask_y,
		netAddress_z = MyAddress_z & mask_z;

	// Adresse broascast 
	unsigned int bcastAddress_w = netAddress_w | compl(mask_w),
		bcastAddress_x = netAddress_x | compl(mask_x),
		bcastAddress_y = netAddress_y | compl(mask_y),
		bcastAddress_z = netAddress_z | compl(mask_z);


	printf("Adresse du   IPv4 : %u.%u.%u.%u / %d\n", MyAddress_w, MyAddress_x, MyAddress_y,
		MyAddress_z, IPv4MaskLength);
	printf("Adresse du reseau : %u.%u.%u.%u / %d\n", netAddress_w, netAddress_x, netAddress_y,
		netAddress_z, IPv4MaskLength);
	printf("Adresse broadcast : %u.%u.%u.%u\n", bcastAddress_w, bcastAddress_x, bcastAddress_y,
		bcastAddress_z);
}
