/**
 * @quickReview TPG 01:07:24
 */
/* -*-C++-*-*/
#ifndef CATHLRModeldentificator_H
#define CATHLRModeldentificator_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRModeldentificator 
//
// DESCRIPTION :
/**
 * Class used to identity an object in all the models.
 */
//
//=============================================================================
// Abstract Class     : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Jan. 98   Jose CHILLAN (jch)    Creation            
// Jan. 2000 ABT inline
// Jan. 2004 TPD passage en 64 bits
//
//=============================================================================

// For Windows NT
#include "HLRModele.h"

#include "CATGeometry.h"

class ExportedByHLRModele CATHLRModeldentificator
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/** Constructor from a jele
 */
  CATHLRModeldentificator(CATINTPTR iIdentificator );

/** Constructor from a pointer on an object
 */
  CATHLRModeldentificator(void * iPointerGeometry);

//=============================================================================
// METHODS
//=============================================================================
/** Reads the identificator of the object.
 */
  inline CATINTPTR GetIdentificator( ) const;

/** Gets the reference for a CGM object
 */
  inline CATGeometry * GetGeometry() const;

/** Gets the value to compute a key for a hash-table
 */
  inline CATUINTPTR GetKey() const;

protected:
// Datas
  union 
  {
    CATINTPTR     _Identificator;
    void        * _PointerGeometry; 
    CATGeometry * _CGMGeometry;
  };

  // Key for the hash tables
  CATUINTPTR     _HashKey;

};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================
inline CATINTPTR CATHLRModeldentificator::GetIdentificator() const
{
  return _Identificator;
}

inline CATGeometry * CATHLRModeldentificator::GetGeometry() const
{
  return (CATGeometry *) _PointerGeometry;
}

inline CATUINTPTR CATHLRModeldentificator::GetKey() const
{
  return _HashKey;
}



#endif
