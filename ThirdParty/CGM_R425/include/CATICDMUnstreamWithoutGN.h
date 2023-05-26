//===================================================================
// COPYRIGHT [!output company] 2010/12/07
//===================================================================
// CATICDMUnstreamWithoutGN.h
// Header definition of class CATICDMUnstreamWithoutGN
//===================================================================

// Internal use: this interface is dedicated to debug, test-objects or CGMReplays done by CGM, with minimal prerequisite
// Unstream a CDM model that was streamed without Generic Naming

//===================================================================
// Notes: The input stream must have been generated without GN labels (by CATCDMBaseServices::StreamCDMModelWithoutGN or CATCDMBaseServicesStreamUtilities::StreamCDMWithoutGN)
// The only component that adheres to that interface is CDMManager

// A typical use is as follows (no need to prereq CDMInterfaces nor CDMModel, but CATInstantiateComponent which is in System)

/*
   CATCDMBaseServices * BaseServices = 0;
   CATBaseUnknown     * CDMManager = 0;
   HRESULT hr = CATInstantiateComponent("CDMManager", IID_CATBaseUnknown, (void**)(&CDMManager));      // check hr
   CATICDMUnstreamWithoutGN_var CDMUnstreamer = CDMManager; // invokes query-interface which loads CDMModel.dll if required
   hr = (! CDMUnstreamer) ? E_FAIL : CDMUnstreamer->CDMUnstreamWithoutGN(My_CDM_Stream, BaseServices, Factory); // check hr
   CDMUnstreamer = NULL_var; // not mandatory (done at the end of the scope), unless the CDM model has to be deleted before to get more memory space

   ... use BaseServices

   delete BaseServices; // this will also delete all linked CDM objects
*/

//===================================================================
//  2010/12/07 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef CATICDMUnstreamWithoutGN_H
#define CATICDMUnstreamWithoutGN_H

#include "CATCDMBaseInterfaces.h"
#include "CATBaseUnknown.h"

class CATMathStream;
class CATCDMBaseServices;
class CATGeoFactory;

extern ExportedByCATCDMBaseInterfaces  IID IID_CATICDMUnstreamWithoutGN ;

class ExportedByCATCDMBaseInterfaces CATICDMUnstreamWithoutGN: public CATBaseUnknown
{
CATDeclareInterface;

public:

  // Unstream a CDM model streamed wityhout GN 
  // The created object oBaseServices is the only owner of the CDM model, and must be deleted when no longer used
  virtual HRESULT CDMUnstreamWithoutGN(CATMathStream & iCDMStream, CATCDMBaseServices *& oBaseServices, CATGeoFactory * iFactory, double* iScaleFactor) = 0;

};

// Enable handlers
CATDeclareHandler (CATICDMUnstreamWithoutGN, CATBaseUnknown);

//-----------------------------------------------------------------------
#endif