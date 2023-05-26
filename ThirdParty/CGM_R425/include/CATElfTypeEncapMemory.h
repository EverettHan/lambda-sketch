#ifndef CATElfTypeEncapMemory_H
#define CATElfTypeEncapMemory_H

//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2000
//=============================================================================
//
// Encapsulation des types de base pour la gestion des parametres d'erreur.
//
//=============================================================================

// derivation
#include "CATErrorDef.h"
#include "CATElfTypeEncap.h"

class ExportedByCATELFMathKernel CATElfTypeEncapMemory : public CATElfTypeEncap
{

public :

  CATElfTypeEncapMemory ( int *&    p );
  CATElfTypeEncapMemory ( float *&  p );
  CATElfTypeEncapMemory ( double *& p );
  CATElfTypeEncapMemory ( char *&   p );
  CATElfTypeEncapMemory ( char **&  p );
  
  CATElfTypeEncapMemory ( const CATElfTypeEncapMemory & p );

  ~CATElfTypeEncapMemory() ;

  operator char ** () const;
  int GetElfiniSizeOfPointedType () const;

  static const CATElfTypeEncapMemory EmptyEncapMem;

  static HRESULT Test ();

private :

  CATElfTypeEncapMemory ();

};

#endif
