
#ifndef CATLogBaseLOG_h
#define CATLogBaseLOG_h

// COPYRIGHT DASSAULT SYSTEMES 2000

/* ----------------------------------------------------------------- */
/*                                                                   */
/*    fonction : journaling                                          */
/*    usage    : CATIA et autres                                     */
/*    responsble: JHN                                                */
/*                                                                   */
/* ----------------------------------------------------------------- */
/*                                                                   */
/*    description :                                                  */
/*                                                                   */
/* ----------------------------------------------------------------- */
/*                                                                   */
/*    historique  :                                                  */
/*                                                                   */
/*           numero de modif : 00                                    */
/*           raison          : creation                              */
/*           date            : 06/12/96                              */
/*           explication     : design                                */
/*                                                                   */
/* ----------------------------------------------------------------- */

#include "CATDataExtendable.h"
#include "JS0LOGRP.h"

class ExportedByJS0LOGRP CATILogTransaction : public CATBaseUnknown
{
  public :
    static void LogInit();
    static void LogYes();
    static void LogNo();
}
;

# endif
