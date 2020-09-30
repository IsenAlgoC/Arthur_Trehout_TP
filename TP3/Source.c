#include <stdlib.h>
#include <stdio.h>
#define carre(x) (x) * (x)

int main() {
	int Nb = 5;
	printf("Valeur 5x5 : %d\n", carre(Nb));

	//La macro ne respecte pas les priorités opératoires on a donc rajouté des parenthèses au sein de la macro
	//On obtient le calcul suivant sans les parentheses 5+(5*1)+1=11
	printf("Valeur 6x6 : %d\n", carre(Nb + 1));
	system("pause");
}