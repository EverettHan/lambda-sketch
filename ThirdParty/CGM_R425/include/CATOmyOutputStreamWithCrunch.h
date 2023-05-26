// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// PLMMaintenancePLMQLFromOutputStream.h
//
// Accumule le plmql arrivant via l'interface CATIComSidlOutputStream le plmql est ensuite
// 'crunche' (via un coup de SHA) et envoye sous forme de binaire dans l'output stream
// donne.
//
// Si aucun output stream n'est donne au constructeur, les donnees crunches sont recuperables
// par GetCrunchedData.
//
// La partie VPLMSession n'est pas stockee ni crunchee (comme PLMMaintenancePLMQLFromOutputStream)
//
#ifndef CATOmyOutputStreamWithCrunch_H
#define CATOmyOutputStreamWithCrunch_H

#include "CATOMYCommunication.h"
#include "PLMMaintenancePLMQLFromOutputStream.h"
#include "CATUnicodeString.h"
#include "CATIComSidlOutputStream.h"

//-----------------------------------------------------------------------
class ExportedByCATOMYCommunication CATOmyOutputStreamWithCrunch: public PLMMaintenancePLMQLFromOutputStream

{
  CATDeclareClass;
public:
  CATOmyOutputStreamWithCrunch(CATIComSidlOutputStream * iOutputForCrunchedData = NULL);
  ~CATOmyOutputStreamWithCrunch();

  HRESULT CompareCrunchedData(CATOmyOutputStreamWithCrunch * iReference);
  CATUnicodeString GetCrunchedData();

protected:
  HRESULT DoEndStream ();
  CATIComSidlOutputStream_var _OutputForCrunchedData;
};
#endif
