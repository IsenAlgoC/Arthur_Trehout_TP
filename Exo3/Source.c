#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <conio.h>
#include <ctype.h>

#define NBMAXNOTES 30

void echanger_float(float* a, float* b)
{
	float tmp = *b;
	*b = *a;
	*a = tmp;
}

void echanger_int(int* a, int* b)
{
	int tmp = *b;
	*b = *a;
	*a = tmp;
}

void permutation_fTab(float table[], int i, int j)

{
	echanger_float(&table[i], &table[j]);
}

void permutation_iTab(int table[], int i, int j)
// echanger valeur aux positions i et j
{
	echanger_int(&table[i], &table[j]);
}


void main()
{
	int nbNotesValides = 0;
	float sommeNotesValides = 0;
	float moyenneNotes = 0;
	int nbAbsences = 0;
	float noteMin = 0;
	float noteMax = 0;

	float note[NBMAXNOTES];
	for (int p = 0; p < NBMAXNOTES; p++)
		note[p] = -2;

	char compteurNotesSasies = 0;
	char arreterLaSaisie = 0;

	while (arreterLaSaisie == 0 && compteurNotesSasies != NBMAXNOTES)
	{
		printf("Entrer la note numero %d : ", compteurNotesSasies + 1);
		float noteTmp;
		scanf_s("%f", &noteTmp);

		if (noteTmp < 0.0 || noteTmp > 20.0)
		{
			printf("Eleve absent ? ou voulez - vous	arreter la saisie des notes ? A / O / N\n\n");
			int bonneLettreSaisie = 0;
			while (bonneLettreSaisie == 0)
			{
				int ch;
				ch = _getch();
				ch = toupper(ch);
				switch (ch)
				{
				case('A'): 
					bonneLettreSaisie = 1;
					compteurNotesSasies += 1;
					nbAbsences += 1;
					note[compteurNotesSasies] = -1;
					break;
				case('O'): 
					bonneLettreSaisie = 1;
					arreterLaSaisie = 1;
					break;
				case('N'):	
					bonneLettreSaisie = 1;
					printf("Resaisir la note.\n\n");
					break;
				default:
					printf("Merci de saisir uniquement A, O ou N.\n\n");
					break;
				}
			}
		}
		else  // La note saisie est bien comprise entre 0 et 20
		{
			note[compteurNotesSasies] = noteTmp;
			compteurNotesSasies += 1;
			nbNotesValides += 1;
			sommeNotesValides += noteTmp;
			noteMin = min(noteTmp, noteMin);
			noteMax = max(noteTmp, noteMax);
		}
	}


	moyenneNotes = sommeNotesValides / nbNotesValides;
	double somme = 0.0;
	for (int p = 0; p < NBMAXNOTES; p++)
		somme += pow((note[p] >= 0) ? (note[p] - moyenneNotes) : 0, 2);

	double ecartType = sqrtl(somme / (nbNotesValides - 1.0));


//Tri des valeurs
	float copieNote[NBMAXNOTES];
	for (int i = 0; i < NBMAXNOTES; i++) copieNote[i] = note[i];

	int indexTab[NBMAXNOTES];
	for (int i = 0; i < NBMAXNOTES; i++) indexTab[i] = i;

// tri a bulle
	for (int i = NBMAXNOTES - 1; i > 2; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (copieNote[j] > copieNote[j + 1])
			{
				permutation_fTab(copieNote, j, j + 1);
				permutation_iTab(indexTab, j, j + 1);
			}
		}
	}


// Bilan
	printf("La moyenne des %d notes est %.2f.\n\n", nbNotesValides, moyenneNotes);
	printf("Il y a %d abscence(s).\n", nbAbsences);
	printf("La plus petite note est %.2f, la plus grande est %.2f..\n", noteMin, noteMax);
	printf("L'ecart type vaut : %f\n", ecartType);
	printf("\tNo note Valeur note\n");
	int p = 0;
	while (p < nbAbsences + nbNotesValides)
	{
		if (note[p] == -1) // Eleve absent
			printf("%d\tAbs.\n", p + 1);
		else
			printf("\t%d\t%.2f\n", p + 1, note[p]);
		p += 1;
	}
	printf("\n");

	printf("\tRang:  No note        Valeur note\n");
	p = 0;
	while (p < nbAbsences + nbNotesValides)
	{
		if (note[p] == -1) // Eleve absent
			printf("\t%d\t%d\t\tAbs.\n", p + 1, indexTab[NBMAXNOTES - 1 - p]);
		else
			printf("\t%d\t%d\t\t%.2f\n", p + 1, indexTab[NBMAXNOTES - 1 - p], copieNote[NBMAXNOTES - 1 - p]);
		p += 1;
	}
	printf("\nBye !\n\n");
<<<<<<< HEAD
}
=======
}
>>>>>>> 5133f5587d0528a6aecc91371cd49bfa0ecc76e5
