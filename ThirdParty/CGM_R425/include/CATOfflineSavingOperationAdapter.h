//===================================================================
// COPYRIGHT Dassault Systemes 2015/08/20
//===================================================================
// CATOfflineSavingOperationAdapter.cpp
// Header definition of class CATOfflineSavingOperationAdapter
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2015/08/20 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATOfflineSavingOperationAdapter_H
#define CATOfflineSavingOperationAdapter_H

#include "CATPLMIntegrationInterfaces.h"
#include "CATIOfflineSavingOperation.h"

template<typename T>
class CATOmxSR;
class CATIOmyIncidentCollector;
//-----------------------------------------------------------------------

class ExportedByCATPLMIntegrationInterfaces CATOfflineSavingOperationAdapter: public CATIOfflineSavingOperation
{
public:
// Standard constructors and destructors
// -------------------------------------
CATOfflineSavingOperationAdapter ();
virtual ~CATOfflineSavingOperationAdapter ();

 virtual HRESULT PostOffline(CATOmxSR<CATIOmyIncidentCollector>& ioError);
 virtual HRESULT PostOnline(CATOmxSR<CATIOmyIncidentCollector>& ioError, CATBoolean &oIsOfflineFavorite);
 virtual HRESULT PreOnline(CATOmxSR<CATIOmyIncidentCollector>& ioError, CATBoolean &oIsOfflineFavorite);

private:
// Copy constructor and equal operator
// -----------------------------------
CATOfflineSavingOperationAdapter (CATOfflineSavingOperationAdapter &);
CATOfflineSavingOperationAdapter& operator=(CATOfflineSavingOperationAdapter&);

};

//-----------------------------------------------------------------------

#endif
