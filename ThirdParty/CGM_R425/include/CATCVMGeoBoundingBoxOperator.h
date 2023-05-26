/* -*-C++-*- */

#ifndef CATCVMGeoBoundingBoxOperator_H
#define CATCVMGeoBoundingBoxOperator_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMGeoBoundingBoxOperator
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// Feb. 2007    Creation                         AAD
//===================================================================

#include "CATCVMGeoOperators.h"
#include "CATCVMSysOperator.h"
#include "CATBoolean.h"
#include "ListPOfCATCVMObject.h"
#include "CATMathBox.h"

class CATCVMContainer;
class CATCVMBody;
class CATCVMGeometry;
class CATCVMComponent;
class CATCVMInstancePath;
class CATCVMInstance;
class CATCVMGeoMesh;
class CATMathSetOfPoints;

class ExportedByCATCVMGeoOperators CATCVMGeoBoundingBoxOperator : public CATCVMSysOperator
{
public:
  static CATCVMGeoBoundingBoxOperator *Create(CATCVMContainer *iContainer);
  static CATCVMGeoBoundingBoxOperator *Create(CATCVMInstancePath *iCVMInstancePath);
  virtual ~CATCVMGeoBoundingBoxOperator();

  /**
   *Currently supported objects: CATCVMComponent, CATCVMBody, CATCVMGeometry
   */
  void SetObjects(ListPOfCATCVMObject & iObjects);
  void Run();
  void GetResult(CATMathBox & oBox);

  static void ComputeTransformedBox(CATMathBox            &iBox,
                                    CATMathTransformation &iTransformation,
                                    CATMathBox            &oBox,
                                    CATMathSetOfPoints    *oPoints = NULL);

protected:
  CATCVMGeoBoundingBoxOperator(CATCVMContainer *iContainer);
  CATCVMGeoBoundingBoxOperator();

private:
  CATCVMGeoBoundingBoxOperator(const CATCVMGeoBoundingBoxOperator &);//Necessary to prevent unwanted automatic creation by compiler
  void operator = (const CATCVMGeoBoundingBoxOperator &);

  HRESULT RunObject(CATCVMObject * iObject, CATMathBox & oBox);
  HRESULT RunBody(CATCVMBody * iObject, CATMathBox & oBox);
  HRESULT RunGeoMesh(CATCVMGeoMesh * iObject, CATMathBox & oBox);
  HRESULT RunGeometry(CATCVMGeometry * iObject, CATMathBox & oBox);
  HRESULT RunComponent(CATCVMComponent * iObject, CATMathBox & oBox);
  HRESULT RunReference(CATCVMReference * iObject, CATMathBox & oBox);
  HRESULT RunInstance(CATCVMInstance * iObject, CATMathBox & oBox);
  HRESULT RunInstancePath(CATCVMInstancePath * iObject, CATMathBox & oBox);

  // private Data :
  ListPOfCATCVMObject _Objects;
  CATMathBox _Box;
};
#endif
