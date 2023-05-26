#ifndef CATElfTypeEncapError_H
#define CATElfTypeEncapError_H


//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2000
//=============================================================================
//
// Encapsulation des types de base pour la gestion des parametres d'erreur.
//
//=============================================================================


#include "CATCollec.h"
#include "CATElfTypeEncap.h"

class ExportedByCATELFMathKernel CATElfTypeEncapError : public CATElfTypeEncap
{

public :

  CATElfTypeEncapError ( const int    p );
  CATElfTypeEncapError ( const double p );
  CATElfTypeEncapError ( const char * p );

  CATElfTypeEncapError ( const CATElfTypeEncapError & p );

  ~CATElfTypeEncapError ();

  void AddParameterInList ( CATListOfInt & ioI4ParmError,
                            CATListOfDouble & ioR8ParmError,
                            CATListOfCATUnicodeString & ioUSParmError ) const ;
  
  static const CATElfTypeEncapError EmptyEncapEr;

private :

  CATElfTypeEncapError ();

  // types non pris en charge par rapport a CATElfTypeEncap :
  CATElfTypeEncapError ( const float p );

};

#endif
