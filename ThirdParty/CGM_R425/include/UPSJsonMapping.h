
#ifndef UPSJsonMapping_H
#define UPSJsonMapping_H

#include "ExportedByCoexUPSJsonMapping.h"
#include "CATStdIO.h"
#include "CATUnicodeString.h"
#include "CATOmxArray.h"
#include "CATOmxJsonArray.h"
#include "CATOmxJsonObject.h"
#include "CATOmxOHMap.h"
#include "CATBoolean.h"
#include "CATOmxKeyString.h"
//#include "UPSJsonObject.h"


#define _XCADID "xCADId"
#define _CESTAMP "CEStamp"
#define _3DEXPID "3DExpId"
#define _ISLOCAL "IsLocal"
#define _SYNCHROSTAMP "XCADSynchroStamp"
#define _ISSETXSS "IsSetXSS"



class UPSJsonInstance;
class UPSJsonReference;

template <> ExportedByCoexUPSJsonMapping CATOmxCollecManager& CATOmxDefaultCollecManager<UPSJsonReference*>::manager();
template <> ExportedByCoexUPSJsonMapping CATOmxCollecManager& CATOmxDefaultCollecManager<UPSJsonInstance*>::manager();

class ExportedByCoexUPSJsonMapping UPSJsonMapping
{
private:

  UPSJsonMapping& operator=(const UPSJsonMapping&);
  UPSJsonMapping(const UPSJsonMapping&);

public:
  UPSJsonMapping();
  UPSJsonMapping(const CATUnicodeString& iCUS);
  ~UPSJsonMapping();

  HRESULT GetAllReferences(CATOmxArray<UPSJsonReference*>& oUPSJsonReferences);
  HRESULT GetAllInstances(CATOmxArray<UPSJsonInstance*>& oUPSJsonInstances);



  // to be used by XPDM only
  // iISRoot == TRUE , implies iISLocal = FALSE
  //iISLocal = TRUE means Embedded comp ref
  //CCY1 Note: This on only manage V7... for any newer version of the V_PSMappingTable, this signature will have to be modified
  HRESULT CreateReference(const CATUnicodeString& iXCADID, const CATUnicodeString& iCEStamp,
    const CATUnicodeString& i3DExpID, CATBoolean iIsLocal = FALSE, CATBoolean iIsRoot = FALSE);

  //CCY1 Note: introduced a new service that directly takes the Json object to get rid of the dependency on the version
  HRESULT CreateReference(const CATOmxJsonObject& iJSonRef);

  //***WARN*** ensure that create instance is called insequence for under same owner ref 
  HRESULT CreateInstance(const CATUnicodeString& iXCADID, const CATUnicodeString& iOwnerXCADID, const CATUnicodeString& iRefXCADID,
    const CATUnicodeString& iCEStamp, const CATUnicodeString& i3DExpID,
    const CATUnicodeString& iDocID);

  HRESULT CreateEmbeddedCompInstance(const CATUnicodeString& iXCADID, const CATUnicodeString& iOwnerXCADID, const CATUnicodeString& iRefXCADID,
    const CATUnicodeString& iCEStamp, const CATUnicodeString& i3DExpID);


  HRESULT GetVersion(int& oVersion);
  HRESULT SetVersion(const int& iVersion);
  //finalization 
  HRESULT IsMappingValid(CATBoolean& oBool);

  HRESULT Stringify(CATUnicodeString& oCUS);// json object ToString();



private:
  // to convert our  "in-memory" model to json objects
  HRESULT StreamToJSONMappingObj();
  HRESULT ReadInstancesToJSON(UPSJsonReference*& ipRefObj, CATOmxJsonArray& oInstancesJSONArr);
  HRESULT CreateRefAsJSONObj(UPSJsonReference*& ipRefObj, CATOmxJsonObject& oRefJSONObj);

  // convert json to in memor model 
  HRESULT PreparePSFromJsonObject();
  HRESULT ConvertRefsJsonToPS(CATOmxJsonArray& REFarrayValue);
  HRESULT ConvertInstancesJsonToPS(CATUnicodeString& iOwnerRefxCADId, CATOmxJsonArray& iInstances);

  int _version;


  CATOmxJsonObject _jsonUPSMapping;
  UPSJsonReference* _pCurrentRef;

  CATOmxArray<UPSJsonReference*> _ArrUPSJsonReferences;
  CATOmxArray<UPSJsonInstance*> _ArrUPSJsonInstances;





};






#endif
