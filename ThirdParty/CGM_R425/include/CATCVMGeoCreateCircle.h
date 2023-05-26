/* -*-C++-*- */

#ifndef CATCVMGeoCreateCircle_H
#define CATCVMGeoCreateCircle_H

// COPYRIGHT DASSAULT SYSTEMES 2007

//=============================================================================
//=============================================================================
//
// CATCVMGeoCreateCircle : Creation d'un wire circulaire avec 2 aretes
//                         mis dans un body CVM
//
//=============================================================================

//=============================================================================
// Mars  2007  Creation                                                   PRL
//=============================================================================
//=============================================================================


// Derivation
#include "CATCVMGeoOperator.h"
#include "CATCGMNewArray.h"

// CVM
class CATCVMGeoContainer;
class CATCVMComponent;
class CATCVMBody;
#include "ListPOfCATCVMBody.h"
#include "ListPOfCATCVMGeometry.h"

// CGM
class CATTopData;
class CATMathPoint;
class CATMathPlane;
class CATMathVector;
class CATCVMInstancePath;

enum CATCVMCreateCircleType
{
    CATCVMCreateCircleType_NCR,//SetNormal + SetCenter + SetRadius
    CATCVMCreateCircleType_3P_Arc//SetPoint1 + SetPoint2 + SetPoint3 (2 extremities are Point1 & Point2; 3rd point is proj of Point3 on median plane)
};

class ExportedByCATCVMGeoOperators CATCVMGeoCreateCircle : public CATCVMGeoOperator
{

public: 
//===========================================================================================================

  //------------------------------------------------------------------------------
  // Create [Ctor is protected!]
  //------------------------------------------------------------------------------     
  static CATCVMGeoCreateCircle* Create(CATCVMGeoContainer *iCVMGeoContainer,
                                       CATTopData         *iTopData);
  static CATCVMGeoCreateCircle* Create(CATCVMInstancePath *iCVMInstancePath,
                                       CATTopData         *iTopData);

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------     
  virtual ~CATCVMGeoCreateCircle();

  //------------------------------------------------------------------------------
  // Pool allocation
  //------------------------------------------------------------------------------   
  CATCGMNewClassArrayDeclare;        

  //Optional: define the bodies with which the result body will be merged
  void SetBodiesToMerge(ListPOfCATCVMBody & iBodies);

  //Optional: 
  //if iSurfacic is FALSE (default): result is wireframe
  //if iSurfacic is TRUE           : result is surfacic
  void SetSurfacic(CATBoolean iSurfacic);

  //Optional: 
  //if iPreview is FALSE (default): result must be retrieved with GetResultingCVMBody
  //if iPreview is TRUE           : result must be retrieved with GetPreview
  void SetPreview(CATBoolean iPreview);
  //------------------------------------------------------------------------------
  // Set the host component (optional)
  //------------------------------------------------------------------------------
  void SetHostComponent(CATCVMComponent *iComponent);

  //It is mandatory to call this method. iType specifies which arguments must be used
  //to define the circle or arc of circle.
  void SetType(CATCVMCreateCircleType iType);

  //Deprecated-- Do not use -- Use SetNormal
  void SetPlane (const CATMathPlane&     iPlane);     
  void SetNormal(const CATMathVector &   iNormal);     
  void SetCenter(const CATMathPoint&     iCenter);     
  void SetRadius(CATPositiveLength iRadius);  
  void SetPoint1(const CATMathPoint&     iPoint1);     
  void SetPoint2(const CATMathPoint&     iPoint2);     
  void SetPoint3(const CATMathPoint&     iPoint3);

  void SetSmartGeometry(CATBoolean iSmartGeometry = TRUE);

  //------------------------------------------------------------------------------
  // Get the resulting CVM body
  //------------------------------------------------------------------------------
  CATCVMBody *GetResultingCVMBody();
  void GetPreview(CATMathPoint & oCenter, CATMathVector & oNormal, CATMathVector & oAngleReference, 
                  double & oStartAngle, double & oEndAngle, double & oRadius);

  //------------------------------------------------------------------------------
  // if Preview mode : Throw
  // otherwise : - oListEdges contains the circular created edges
  //             - oListVertices contains the resulting vertices associated to
  //               the two points specified with SetPoint1() and SetPoint2()
  //               [this second list is therefore valuated only 
  //                for type CATCVMCreateCircleType_3P_Arc     ]  
  //------------------------------------------------------------------------------
  void GetPertinentResultingCVMGeometries(ListPOfCATCVMGeometry &oListEdges, ListPOfCATCVMGeometry &oListVertices) ;

  //------------------------------------------------------------------------------
  // CGMReplay 
  //------------------------------------------------------------------------------
  static const CATString *GetDefaultOperatorId(); // plutot ds la lettre?

protected :
//===========================================================================================================
    
  //------------------------------------------------------------------------------
	// Constructor
	//------------------------------------------------------------------------------  
  CATCVMGeoCreateCircle(CATCVMGeoContainer   *iCVMGeoContainer,
                        CATTopData           *iTopData,
                        CATCVMGeoOperatorExt *iExtensible);  
  CATCVMGeoCreateCircle(CATTopData           *iTopData,
                        CATCVMGeoOperatorExt *iExtensible);  
  
private:
//===========================================================================================================
  
  //------------------------------------------------------------------------------
  // Juste pour eviter que le compilo ne definisse par lui-meme ces operateurs
  //------------------------------------------------------------------------------    
  CATCVMGeoCreateCircle();
  CATCVMGeoCreateCircle(CATCVMGeoCreateCircle& iObj);
  CATCVMGeoCreateCircle& operator=(const CATCVMGeoCreateCircle & iObj);

  //------------------------------------------------------------------------------
  // CGM Internal Use
  //------------------------------------------------------------------------------
  int RunOperator(); 

};
#endif

// Ne rien ecrire sous cette ligne
//===========================================================================================================

