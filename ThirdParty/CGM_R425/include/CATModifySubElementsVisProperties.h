//===================================================================
// COPYRIGHT Dassault Systemes 2016/10/25
//===================================================================
// CATModifySubElementsVisProperties.h
//===================================================================

#ifndef CATModifySubElementsVisProperties_H
#define CATModifySubElementsVisProperties_H

// Visualization Interfaces
#include "CATVisItf.h"
#include "CATModifyVisProperties.h"
#include "CATVisPropertiesValues.h"
#include "CATVisGeomType.h"
#include "CATVisPropertyType.h"

// System
#include "CATLISTV_CATBaseUnknown.h"

//-----------------------------------------------------------------------

class ExportedByCATVisItf CATModifySubElementsVisProperties : public CATModifyVisProperties
{
  CATDeclareClass;

public:

  CATModifySubElementsVisProperties(CATBaseUnknown* iObject, const CATPathElement &iPathElt, CATVisGeomType iGeomType, CATVisPropertyType iPropertyType, const CATVisPropertiesValues &iPropertyValue);
  virtual ~CATModifySubElementsVisProperties();

  // CLONE
  CATModelNotification* Clone();

  // ADD
  HRESULT AddElement(const CATBaseUnknown_var &iElt) { _listElts.Append(iElt); return S_OK; }

  // REMOVE
  HRESULT RemoveElement(const CATBaseUnknown_var &iElt) { _listElts.RemoveValue(iElt); return S_OK; }

  // GET
  HRESULT GetElements(CATListValCATBaseUnknown_var  &oElts) const { oElts = _listElts; return S_OK; }

	// SET
	HRESULT SetElements(CATListValCATBaseUnknown_var  &iElts) { _listElts = iElts; return S_OK; }

  // SET OBJECT
  HRESULT SetObject(CATBaseUnknown* iObject);


private:
  
  CATModifySubElementsVisProperties (CATModifySubElementsVisProperties &);
  CATModifySubElementsVisProperties& operator=(CATModifySubElementsVisProperties&);

  CATListValCATBaseUnknown_var _listElts;

};

//-----------------------------------------------------------------------

#endif
