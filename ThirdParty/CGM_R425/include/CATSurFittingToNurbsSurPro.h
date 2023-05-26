#ifndef CATSurFittingToNurbsSurPro_H
#define CATSurFittingToNurbsSurPro_H

// COPYRIGHT DASSAULT SYSTEMES  2011


#include "CATSurFittingToNurbsSur.h"

#include "CATIACGMLevel.h"
#include "CATCGMVirtual.h"


class CATSurFittingToNurbsSurPro : public CATSurFittingToNurbsSur
{
//  CATCGMVirtualDeclareClass(CATSurFittingToNurbsSurPro);
  public :


           CATSurFittingToNurbsSurPro(CATGeoFactory *iFactory):CATSurFittingToNurbsSur(iFactory) {;}
  virtual ~CATSurFittingToNurbsSurPro(){;};

  /**
   * Defines whether the result NURBS representation can be rational.
   * <br>To call in <tt>ADVANCED</tt> mode before the <tt>Run</tt> method.
   * @param iAllowRational
   * <tt>1</tt> if the result surface can be rational (default value when the method is not called), 
   * <tt>0</tt> if the result surface must not be rational.
   */
  virtual void SetSpecificUnfoldResult()=0;
  }
;
#endif
