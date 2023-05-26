//===================================================================
// COPYRIGHT Dassault Systemes 2009
//===================================================================
/**
* @level Private
* @usage U3
*/

//-- [chd:11.03.2014] VPMIDicImplementation devient un VPMIDicElement (et non plus un CATBaseUnknown)

#ifndef VPMIDicImplementation_H
#define VPMIDicImplementation_H

#include "VPMIDicInterfaces.h"
#include "VPMIDicElement.h"

#include "CATString.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByVPMIDicInterfaces IID IID_VPMIDicImplementation;
#else
extern "C" const IID IID_VPMIDicImplementation ;
#endif

//------------------------------------------------------------------

class ExportedByVPMIDicInterfaces VPMIDicImplementation: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Return the source file Location of this Impelementation . The location is the relative Path of the EKL or PLMQL file in the RuntimeView
  * @param oFileLocation
  */
  virtual HRESULT getFileLocation ( CATString & oFileLocation ) = 0;

  /**
  * Return the language of the implementation (String “EKL” or “PLMQL”)
  * @param oLanguage
  */
  virtual HRESULT getLanguage ( CATString & oLanguage ) = 0;

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};
CATDeclareHandler (  VPMIDicImplementation, VPMIDicElement );
//------------------------------------------------------------------

#endif
