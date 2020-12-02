#include <stdlib.h>
#include <stdio.h>


int main() {
	unsigned int valeur = 2868838400;
	printf("le nombre d'octets pour coder la variable : %d\n", sizeof(valeur));
	printf("le nombre de bits pour coder la variable : %d\n", sizeof(valeur) * 8);
	{
	// on verifie si le i-eme bit de n vaut 1.
	for (int i = 0; i < sizeof(valeur) * 8; i++) {
		if (i < 10) {
			if (valeur & (1 << i)) {
				printf("Bit  %d : ON\n", i);
			}
			else {
				printf("Bit  %d : OFF\n", i);
			}
		}
		else {
			if (valeur & (1 << i)) {
				printf("Bit %d : ON\n", i);
			}
			else {
				printf("Bit %d : OFF\n", i);
			}
		}

	}

}
	printf("Bye !");
	system("pause");
}

