#ifndef CATTessDiagnostic_H 
#define CATTessDiagnostic_H 


// COPYRIGHT DASSAULT SYSTEMES 1999

// Diagnostics de maillage
// CATTessDiagnostic : 0 : CATTessOK            = Tout c'est bien passe, On rend tout
//                     1 : CATTessNoResult      = il n'y a rien a rendre = OK
//                     2 : CATTessPartialResult = on rend un resultat partiel
//                     3 : CATTessKO            = on ne rend rien, gros probleme
//                     4 : CATTessNoMoreMemory  = on ne rend rien, plus de memoire
typedef enum { CATTessOK = 0, CATTessNoResult, CATTessPartialResult, CATTessKO, CATTessNoMoreMemory }

CATTessDiagnostic;


#endif
