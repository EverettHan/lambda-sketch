 #ifndef CATNotifierTransactionMode_H
 #define CATNotifierTransactionMode_H

// COPYRIGHT DASSAULT SYSTEMES 2000

 #define CATTransactionOn  -1
 #define CATTransactionOff  0 
 //-----------------------------------------------------------------
 // Pour indiquer le debut d'une pseudo-transaction : CATTransactionOn
 // Pour indiquer la fin   d'une pseudo-transaction : CATTransactionOff
 // -> l'appel a CATNotifierTransactionMode(CATTransactionOff) entraine
 // le cleaning si on n'est pas deja dans une transaction
 //-----------------------------------------------------------------
 ExportedByJS0FM int CATNotifierTransactionMode( int iModeOn, int interrogate=0);
 #endif

