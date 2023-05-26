#ifndef CATElfTypeEncap_H
#define CATElfTypeEncap_H

//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2000
//=============================================================================
//
// Encapsulation des types de base.
//
//=============================================================================

#include "CATELFMathKernel.h"

#include "CATBooleanDef.h"
#include "CATElfInputEnum.h" 
#include "CATElfBasicTypes.h"

class ExportedByCATELFMathKernel CATElfTypeEncap
{

public :

  ~CATElfTypeEncap ();

  CATBoolean IsEmpty ()    const;
  void       PrintType ()  const;
  void       PrintValue () const;
  void       Dump ()       const;

protected :

  static const CATElfTypeEncap EmptyEncap;
  
  CATElfTypeEncap ( const CATElfTypeEncap & iP );
  CATElfTypeEncap & operator = ( const CATElfTypeEncap & iP );

  // ----------------------------------
  // Encapsulation par valeur
  // ----------------------------------

  // encapsulation des entiers (4 octets)
  CATElfTypeEncap ( const int p );
  // encapsulation des reels (4 octets)
  CATElfTypeEncap ( const float p );
  // encapsulation des reels longs (8 octets)
  CATElfTypeEncap ( const double p );
  // encapsulation des chaines de caracteres (recopie du contenu! n octects)
  CATElfTypeEncap ( const char * p );

  // ----------------------------------
  // Encapsulation de l'adresse
  // ----------------------------------

  // encapsulation des pointeurs sur des int (4 octets en 32 bits, 8 en 64 bits)
  CATElfTypeEncap ( int *& p );
  CATElfTypeEncap ( float *& p );
  CATElfTypeEncap ( double *& p );
  CATElfTypeEncap ( char *& p );
  CATElfTypeEncap ( char **& p );
  // encapsulation des pointeurs sur une chaine de caractère (4 octets en 32 bits, 8 en 64 bits)
  //CATElfTypeEncap ( const char **& p );

private :

  // default constructeur inaccessible
  CATElfTypeEncap ();
  
  // types non pris en charge :
  CATElfTypeEncap ( const short p );
  CATElfTypeEncap ( const long p );

protected :

  union CATElfTypeEncapContent
  {
    Real8    _R8;
    void *   _Ptr;
    Real4    _R4;
    Integer4 _I4;
  } _Value;
  // typage de la valeur
  CATElfValue _ValueType;

};

#endif
