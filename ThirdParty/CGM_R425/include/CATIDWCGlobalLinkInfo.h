/** WARNING: OTS 16:01:22 SINGLE-CODE 2013x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
//===================================================================
// COPYRIGHT Dassault Systemes 2015/07/22
//===================================================================
// CATIDWCGlobalLinkInfo.cpp
// Header definition of class CATIDWCGlobalLinkInfo
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2015/07/22 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef CATIDWCGlobalLinkInfo_H
#define CATIDWCGlobalLinkInfo_H

#include "DWCLink.h"
#include "CATBaseUnknown.h"

class CATUnicodeString;
class PLMIOmbVirtualObjectDescriptor_var;


extern ExportedByDWCLink  IID IID_CATIDWCGlobalLinkInfo ;


class ExportedByDWCLink CATIDWCGlobalLinkInfo : public CATBaseUnknown
{
CATDeclareInterface;

public:

  /**
    Add MfInput pointed information and store it under an ordered form to current global info object
  */
  virtual HRESULT AddMfInputPostTreatment(CATUnicodeString &iPointingElementAlias, PLMIOmbVirtualObjectDescriptor_var &ispPointedVODescriptor) = 0;

  /**
    Deprecated
    Do not use !!
  */
  virtual HRESULT AddMfInputToCtxInputPostTreatment(CATUnicodeString &iPointingElementAlias, PLMIOmbVirtualObjectDescriptor_var &ispPointedImportVODescriptor, PLMIOmbVirtualObjectDescriptor_var &ispPointedContextVODescriptor) = 0;

  /**
    Generate XML file based on current global info object and all its associated information
    Directory is passed as input parameter
    File name is always "DownwardCompatibility_LinkInformation.xml"
  */
  virtual HRESULT GenerateXMLFile(CATUnicodeString iReportDirectory) = 0;

  /**
    Set current document to the path passed as input parameter
    Any post treatment to come will then be added to this document (thru AddMfInputPostTreatment)
  */
  virtual HRESULT SetCurrentDocInfo(CATUnicodeString iFilePath) = 0;

  /**
    Reset current document to no document
  */
  virtual HRESULT ResetCurrentDocInfo() = 0;
};

//-----------------------------------------------------------------------
CATDeclareHandler( CATIDWCGlobalLinkInfo, CATBaseUnknown );


#endif
