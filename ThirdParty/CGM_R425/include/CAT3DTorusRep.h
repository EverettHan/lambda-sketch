// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// CAT3DTorusRep.h
// Header definition of CAT3DTorusRep
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jan 2011  Creation: Code generated by the CAA wizard  pam
//===================================================================
#ifndef CAT3DTorusRep_H
#define CAT3DTorusRep_H

#include "SGInfra.h"
#include "CAT3DCurvedPipeRep.h"

#include "CATMathConstant.h"

class CATGraphicPrimitive;
class CATMathAxis;
//-----------------------------------------------------------------------

/**
* Describe your class here.
* <p>
* Using this prefered syntax will enable mkdoc to document your class.
*/
class ExportedBySGInfra CAT3DTorusRep: public CAT3DCurvedPipeRep
{
  CATDeclareClass;

public:

  // This constructor creates a torus
  static CAT3DTorusRep* CreateRep(const CATMathAxis &iAxisSystem,
                          double iMajorRadius,
                          double iMinorRadius,
                          CATAngle iMajorStartAngle = 0.0,
                          CATAngle iMajorEndAngle = CAT2PI,
                          double iSag=0.0);

protected:

  virtual ~CAT3DTorusRep ();

protected:
  /** @deprecated R417 : Use CreateRep instead.*/
  CAT3DTorusRep(const CATMathAxis& iAxisSystem,
    double iMajorRadius,
    double iMinorRadius,
    CATAngle iMajorStartAngle = 0.0,
    CATAngle iMajorEndAngle = CAT2PI,
    double iSag = 0.0);


  CATGraphicPrimitive * BuildGP(const CATMathAxis &iAxisSystem,
                                double iMajorRadius,
                                double iMinorRadius,
                                CATAngle iMajorStartAngle,
                                CATAngle iMajorEndAngle,
                                double iSag);

private:

  // Standard constructors and destructors
  // -------------------------------------
  CAT3DTorusRep(); 
  
  // Copy constructor and equal operator
  // -----------------------------------
  CAT3DTorusRep (CAT3DTorusRep &);
  CAT3DTorusRep& operator=(CAT3DTorusRep&);

};

#endif
