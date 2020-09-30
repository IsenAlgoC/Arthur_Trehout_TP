#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define NBMAXNOTES 30

float note = 0;
float allnote[NBMAXNOTES];
int comp = 0;
int i = 0;
char rep = 'e';
char fin = 'N';
float nb_abs = 0;
float sum = 0;
float petit = 20;
float grand = 0;



int main() {
	for (i = 0; i < NBMAXNOTES; i++)
		allnote[NBMAXNOTES] = -2;
	while ((comp < NBMAXNOTES) && (fin != 'O')) {
		printf("\nEntrer la note numero %d : ", comp);
		scanf_s("%f", &note);
		if ((note < 0 || note>20)) {
			printf("Eleve absent ? ou voulez-vous arreter la saisie des notes ? A/O/N");
			rep = 'e';
			while (rep != 'a' && rep != 'A' && rep != 'o' && rep != 'O' && rep != 'n' && rep != 'N') {
				scanf_s("%c", &rep);
			}
			switch (rep) {
			case 'a':
				allnote[comp] = -1;
				nb_abs++;
				comp++;
				break;
			case 'A':
				allnote[comp] = -1;
				comp++;
				nb_abs++;
				break;
			case 'o':
				fin = 'O';
				break;
			case 'O':
				fin = 'O';
				break;
			case 'n':
				fin = 'N';
				break;
			case 'N':
				fin = 'N';
				break;
			}
		}
		else {
			if (note > grand) {
				grand = note;
			}
			if (note < petit) {
				petit = note;
			}
			sum = sum + note;
			allnote[comp] = note;
			comp++;
		}


	}
	
	sum =(float)(sum / (comp - nb_abs));
	printf("la moyenne est de %.2f\n", sum);
	printf("la note la plus grande est %.2f\n", grand);
	printf("la note la plus petit est %.2f\n", petit);
	printf("Le nombre d'abscence est de %f\n", nb_abs);
	
	system("pause");
	
}

