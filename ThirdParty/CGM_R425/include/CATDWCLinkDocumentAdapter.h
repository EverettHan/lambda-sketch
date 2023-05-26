/** WARNING: OTS 16:01:22 SINGLE-CODE 2013x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
//===================================================================
// COPYRIGHT Dassault Systemes 2015/07/23
//===================================================================
// CATDWCLinkDocumentAdapter.cpp
// Header definition of class CATDWCLinkDocumentAdapter
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2015/07/23 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATDWCLinkDocumentAdapter_H
#define CATDWCLinkDocumentAdapter_H

#include "DWCLink.h"
#include "CATBaseUnknown.h"
#include "CATIDWCLinkDocument.h"

//-----------------------------------------------------------------------

class ExportedByDWCLink CATDWCLinkDocumentAdapter: public CATBaseUnknown
{
public:
// Standard constructors and destructors
// -------------------------------------
CATDWCLinkDocumentAdapter ();
virtual ~CATDWCLinkDocumentAdapter ();

  HRESULT ManagePostTreatements (CATIDWCGlobalLinkInfo *iDWCLinkInfo);

private:
// Copy constructor and equal operator
// -----------------------------------
CATDWCLinkDocumentAdapter (CATDWCLinkDocumentAdapter &);
CATDWCLinkDocumentAdapter& operator=(CATDWCLinkDocumentAdapter&);

};

//-----------------------------------------------------------------------

#endif
