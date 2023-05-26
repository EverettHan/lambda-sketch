#ifndef _CATIGenTrac_h
#define _CATIGenTrac_h


// COPYRIGHT DASSAULT SYSTEMES 2000

#include "JS0LOGRP.h"
#include "CATICallTrac2.h"

// creation d un item de journal pour le journaling
// cet item de journal ne contient pas de methode, il faut le remplir
extern ExportedByJS0LOGRP CATICallTrac2 * GenTrac();

// A partir d'un objet appartenant aux objets exposables on cree un
// item de journal permettant de creer cet objet (i.e. via une methode)
// A noter que l'implementation du CATBaseDispatch (en parametre de GiveTrace)
// et de l objet
// CATIGenTrac doivent etre les memes ou pas
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByJS0LOGRP IID IID_CATIGenTrac;
#else
extern "C" const IID IID_CATIGenTrac;
#endif

class ExportedByJS0LOGRP CATIGenTrac : public CATBaseUnknown
{
    CATDeclareInterface;
  public :
    virtual CATICallTrac2 * GiveTrace(CATBaseDispatch * lulu)=0;
}
;

#endif

