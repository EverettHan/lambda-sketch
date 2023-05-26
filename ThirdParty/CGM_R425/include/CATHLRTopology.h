/* -*-C++-*-*/
#ifndef CATHLRTopology_H
#define CATHLRTopology_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRTopology 
//
// DESCRIPTION :
/**
 * Topological object for the HLR.
 */
//
//=============================================================================
// Abstract Class     : Yes
// Inline Functions   : Yes
//=============================================================================
//
// History
//
// Jan. 98 JCH Creation            
// Jun. 99 HKL Added GetBox method
//
//=============================================================================

// For Windows NT 
#include "HLRTopology.h"

// For inheritance
#include "CATHLRObject.h"

// // Simply defines the topology as the objects
// #define CATHLRTopology CATHLRObject
class CATMathBox;

class ExportedByHLRTopology CATHLRTopology : public CATHLRObject
{
public:

//=============================================================================
// ENUMERATIONS
//=============================================================================


//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/**
 * Default constructor
 */
/**
 * Constructor from a Jele, and a container in which it will be included
 */
  inline CATHLRTopology(int iJele, CATHLRContainer * iContainer);

/** Constructor from a CATGeometry
 */
  inline CATHLRTopology(void * iGeometry, CATHLRContainer * iContainer);

/** Default constructor
  */
  inline CATHLRTopology();


/** Gets the cell's box.
 */
  virtual void GetBox(CATMathBox & oBox) const;

/**
 * Destructor
 */
  virtual ~CATHLRTopology();


  //=============================================================================
  // METHODS
  //=============================================================================
  /** Retrieves the topological element's dimension
  */
  virtual int GetDimension()=0;


};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================
inline CATHLRTopology::CATHLRTopology(int iJele, CATHLRContainer * iContainer) : 
  CATHLRObject(iJele, iContainer)
{
}

inline CATHLRTopology::CATHLRTopology(void * iGeometry, CATHLRContainer * iContainer) :
  CATHLRObject(iGeometry, iContainer)
{
}

inline CATHLRTopology::CATHLRTopology() : CATHLRObject(0, (CATHLRContainer*) 0)
{
}


#endif
