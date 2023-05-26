#ifndef CATViewport_H
#define CATViewport_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


// CATIA Version 5 Release 1 Framework VISUALIZATION
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract: 
//------------------------------------------------------------------------------
// Usage:    
//------------------------------------------------------------------------------
// Inheritance: 
//------------------------------------------------------------------------------
// Main Methods:
//------------------------------------------------------------------------------
#include "SGInfra.h"

#include "CATBaseUnknown.h"
/**
 *  Class taht defines the clipping area.
 *
 *
 */
class ExportedBySGInfra CATViewport : public CATBaseUnknown
{
  /** @nodoc */
 CATDeclareClass;

 public:

// Destructor
  /** @nodoc */
   virtual ~CATViewport();

// Operator = 
   /**
    *  Affectation operator.
    *  @param viewport  A reference to the CATViewport we want to copy  into this one.
    *  @return A reference to this CATViewport
    */
   CATViewport & operator = (const CATViewport &viewport);

// Duplicate the viewport
  /**
   *  Duplicate the Viewport.
   *  @return the copy of this CATViewport
   */
   virtual CATViewport * Clone() const = 0;
  /**
   * Duplicate a Viewport.
   * @param iViewport A pointer to the pointer on the CATViewport into wich we want to duplicate this CATViewport.
   * @return A pointer to the Duplicated CATviewport
   */
   virtual CATViewport * Clone(CATViewport **iViewport) const = 0;
  /** @nodoc */
   inline int IsMalloced();
  /** @nodoc */
   inline void IsMalloced(int);   

// Object size
  /** @nodoc */
   virtual int SizeOf() = 0;

  /**
  * Retrieves whether viewport is a three dimensional one or not.
  * @return
  *  <ul>
  *  <li><tt>TRUE</tt>: the viewport is a @href CAT3DViewpoint </li>
  *  <li><tt>FALSE</tt>: The viewport is not a 3D viewport. </li>
  * </ul>
  */
  virtual CATBoolean Is3D();

//------------------------------------------------------------------------------
 protected : 

// Default constructor and copy constructor
  /** @nodoc */
   CATViewport ();
  /** @nodoc */
   CATViewport (const CATViewport &viewport);

 private : 

  /** @nodoc */
    int _IsMalloced;
};

inline int CATViewport::IsMalloced()
{
 return (_IsMalloced);
}

inline void CATViewport::IsMalloced(int n)
{
 _IsMalloced = n;
}

#endif 
