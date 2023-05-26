/*=======================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1996                                      */
/*=======================================================================*/
/*                                                                       */
/*  CATRetryMode                                                         */
/*                                                                       */
/*  Usage Notes: set of function to manager abend recovery               */
/*                                                                       */
/*=======================================================================*/
/*  Creation Octobre 1996                                       sgt      */
/*=======================================================================*/
#ifndef CATRetryMode_H
#define CATRetryMode_H
#include "JS0ERROR.h"

//-------------------------------------------------------------
ExportedByJS0ERROR int GetRetryMode();
ExportedByJS0ERROR int SetRetryMode(int iMode);
ExportedByJS0ERROR int RetryAuthorized();

#define ErrModeSTANDARD       0 
#define ErrModeIGNORE         1
#define ErrModeABORT          2
#define ErrModeImmediateAbort 3

#endif
