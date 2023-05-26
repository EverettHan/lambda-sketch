

// COPYRIGHT DASSAULT SYSTEMES 2000

#include <stdio.h>
#include "JS0ERROR.h"

// CATCheckMemory : fonction de detection d'erreur sur heap

// Premier  parametre  : un char * sur le message a emettre en cas d'une erreur detectee sur la heap
// Deuxieme parametre : un FILE * ou ecrire le message precedant en cas d'erreur

// Retour :     0 = pas d'erreur detectee sur la heap
//          pas 0 = une erreur sur la heap a ete detecte
// Attention : si la variable d'evironnement "CATCheckMemWithAbort" est definie, alors l'execution est arretee
//             au premier check qui detecte une erreur

ExportedByJS0ERROR int CATCheckMemory(const char *, FILE *);
