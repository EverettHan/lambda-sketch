#ifndef CATTopReflectLineCx_H
#define CATTopReflectLineCx_H
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2012
//=============================================================================
//
#include "BODYNOPE.h"
#include "CATTopReflectLine.h"

class ExportedByBODYNOPE CATTopReflectLineCx : public CATTopReflectLine
{
  public :
 /**
 * @nodoc
 * Constructor. Do not use. Use the <tt>CATCreateTopReflectLine</tt> global function to create a
 * CATTopReflectLine operator.
 */
  CATTopReflectLineCx (CATGeoFactory* iContainer, CATTopData* iData);
  virtual              ~CATTopReflectLineCx ()          ;
    
  /** @nodoc */
  // @nocgmitf
  void ExtractIsoCurves();

  /** @nodoc */
  // @nocgmitf
  void EnableSurfaceSolutions();

protected:
  CATBoolean _EnableSurfaceSolutions;
  CATBoolean _ExtractIsoCurves;
};
#endif


