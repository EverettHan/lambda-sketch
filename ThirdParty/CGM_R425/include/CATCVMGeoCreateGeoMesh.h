/* -*-C++-*- */

#ifndef CATCVMGeoCreateGeoMesh_H
#define CATCVMGeoCreateGeoMesh_H

// COPYRIGHT DASSAULT SYSTEMES 2007

//===================================================================
//===================================================================
//
// CATCVMGeoCreateGeoMesh
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// November 2007    Creation                         JMA
//===================================================================

#include "CATCVMGeoOperators.h"
#include "CATCVMGeoOperator.h"
#include "CATBoolean.h"
#include "ListPOfCATCVMGeometry.h"

class CATCVMGeoContainer;
class CATCVMGeoMesh;
class CATMathPoint;
class CATCVMComponent;
class CATILockBytes2;
class CATCVMInstancePath;

class ExportedByCATCVMGeoOperators CATCVMGeoCreateGeoMesh : public CATCVMGeoOperator
{
  //------------------------------------------------------------------------------
  // Create a CreateGeoMesh operator
  //------------------------------------------------------------------------------
  public:
  static CATCVMGeoCreateGeoMesh* Create(CATCVMGeoContainer *iCVMGeoContainer,
                                     CATTopData         *iTopData);
  static CATCVMGeoCreateGeoMesh* Create(CATCVMInstancePath *iCVMInstancePath,
                                     CATTopData         *iTopData);

  //------------------------------------------------------------------------------
	// Constructor
	//------------------------------------------------------------------------------
  protected:
    CATCVMGeoCreateGeoMesh(CATCVMGeoContainer   *iCVMGeoContainer,
                        CATTopData           *iTopData,
                        CATCVMGeoOperatorExt *iExtensible);
    CATCVMGeoCreateGeoMesh(CATTopData           *iTopData,
                           CATCVMGeoOperatorExt *iExtensible);

	//------------------------------------------------------------------------------
	// Destructor
	//------------------------------------------------------------------------------
  public:
	virtual ~CATCVMGeoCreateGeoMesh();

 //------------------------------------------------------------------------------
  // Set LocalPath (pointing a file with mesh or zip)
  //------------------------------------------------------------------------------
  public:
  void SetLocalPath(CATUnicodeString &iPath);
  void GetLocalPath(CATUnicodeString &oPath);

  void SetLocalBuffer(CATILockBytes2 *iBuffer);
  void GetLocalBuffer(CATILockBytes2 *&oBuffer);

  CATCVMGeoMesh *GetResultingGeoMesh();

  //------------------------------------------------------------------------------
  // Set the host component (optional)
  //------------------------------------------------------------------------------
  public:
  virtual void SetHostComponent(CATCVMComponent *iComponent);

 
  //------------------------------------------------------------------------------
  // CGM Internal Use
  //------------------------------------------------------------------------------
  private:
    //virtual int RunOperator();
  
  public:
    static const CATString *GetDefaultOperatorId();
};
#endif
