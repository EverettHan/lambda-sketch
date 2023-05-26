// COPYRIGHT Dassault Systemes 2012
//===================================================================
//
// CATExtIProfile.h
// Adapter for CATIProfile interface
//
//===================================================================
//
#ifndef CATExtIProfile_H
#define CATExtIProfile_H

#include "CATBaseUnknown.h"
#include "CATAfrItf.h"
#include "CATIProfile.h"

//------------------------------------------------------------------

/**
* Class representing the adaptor of the CATIProfile interface.
* <br>
* Use this adapter to implement CATIProfile interface.
* <br>
* See @href CATIProfile for all explanations on the interface.
*/
class ExportedByCATAfrItf CATExtIProfile: public CATIProfile
{
  CATDeclareClass;
public:

  CATExtIProfile();
  virtual ~CATExtIProfile();

  /** 
  * SetAtt method called when a profile is applied to the sesson
  */
  virtual HRESULT SetAtt ();

};

#endif
