//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2013/04/22
//===================================================================
// CATEAfrSpecialTransition.cpp
// Header definition of class CATEAfrSpecialTransition
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2013/04/22 Creation: ers
//===================================================================

#ifndef CATEAfrSpecialTransition_H
#define CATEAfrSpecialTransition_H

#include "CATIAfrSpecialTransition.h"

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
#include "CATString.h"

//-----------------------------------------------------------------------

class ExportedByCATAfrItf CATEAfrSpecialTransition: public CATBaseUnknown
{
public:

  CATDeclareClass;

  // Standard constructors and destructors
  // -------------------------------------
  CATEAfrSpecialTransition ();
  virtual ~CATEAfrSpecialTransition ();


// CATIAfrSpecialTransition methods
  virtual CATAfrSpecialTransitionMode IsSpecialTransitionSupported();
  virtual int ExecuteSpecialTransition (CATAfrSpecialTransitionMode iMode);


  //Obsolete:
  virtual CATBoolean IsSupported();
  virtual int Execute();


private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATEAfrSpecialTransition (CATEAfrSpecialTransition &);
  CATEAfrSpecialTransition& operator=(CATEAfrSpecialTransition&);

  int DoSpecialTransition (CATString iLateType);
};
#endif
