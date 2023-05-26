/* -*-C++-*-*/
#ifndef CATHLRObject_H
#define CATHLRObject_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRObject 
//
// DESCRIPTION :
/**
 * This class is made to handle all the objects used for the HLR.
 * <BR>Thus objects can be in reality V4 implementations or CGM implementations
 */
//
//=============================================================================
// Abstract Class     : No
// Inline Functions   : Yes
//=============================================================================
//
// History
//
// Jan. 1998 JCH Creation            
// Mar. 2000 HKL Ajout de GetContainer
//
//=============================================================================

// For Windows NT
#include "HLRModele.h"

#include "CATHLRModeldentificator.h"

/** @c++ansi fbq 2004-08-05.10:18:26 [Replace forward declaration by #include <iosfwd.h>] **/
#ifdef _CAT_ANSI_STREAMS
#include <iosfwd.h>
#else
class ostream;
#endif
class CATGeometry;
class CATHLRContainer;

class ExportedByHLRModele CATHLRObject
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/**
 * Constructor from a Jele, and a container in which it will be included
 */
  CATHLRObject(int               iJele,
	       CATHLRContainer * iContainer);

/** Constructor from a CATGeometry
 */
  CATHLRObject(void            * iGeometry,
	       CATHLRContainer * iContainer);

/**
 * Destructor
 */
  virtual ~CATHLRObject();

//------------------------------------------------------------
// Static functions of comparison (for a HashTable)
//------------------------------------------------------------
  static int IsDifferent(CATHLRObject     * iFirstCompared,
			 CATHLRObject     * iSecondCompared);

  static unsigned int GetKey(CATHLRObject * iObjectToHash);

//=============================================================================
// METHODS
//=============================================================================
/** Gets the model identificator of the object
 */
  void GetModelIdentificator(CATHLRModeldentificator & oIdentificator) const;


 /** Gets an identifier for the object. (default implementation -> may be derivated)
 */
  virtual CATINTPTR GetIdentificationTAG() const;

/** Retrieves the object's container
 */
  inline CATHLRContainer * GetContainer();
  
//=============================================================================
// FOR DEBUG
//=============================================================================
// Dumping the object with different depth of dumping . The first depth ( =0)
// just displays the type of the object on the current output
  virtual void Dump(int iDepth =0);

//------------------------------------------------------------
// This method dumps the object in a stream
//------------------------------------------------------------
  virtual void DumpStream(ostream & oOutput, int iDepth = 0);

//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:
// Identificator of the object
  CATHLRModeldentificator  _Identificator;
  CATHLRContainer        * _Container;

};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================

inline CATHLRContainer * CATHLRObject::GetContainer()
{
  return _Container;
}



#endif
