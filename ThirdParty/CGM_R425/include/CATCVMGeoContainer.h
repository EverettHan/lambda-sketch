/* -*-C++-*- */

#ifndef CATCVMGeoContainer_H
#define CATCVMGeoContainer_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMGeoContainer
//
// Collaborative Variational Modelling (CVM) Container class
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// June 2006    Creation                         Alex State
//===================================================================
#include "CATCVMGeoObjects.h"

#include "CATBoolean.h"
#include "CATCVMContainer.h"
#include "CATCVMDef.h"
#include "CATCVMGeoDef.h"
#include "CATICGMObject.h"
#include "ListPOfCATBody.h"
#include "CATCGMNewArray.h"
#include "ListPOfCATCVMGeoMesh.h"


class CATGeoFactory;
class CATCVMSysStream;
class CATCVMGeoStream;
class CATCVMVersionDefinition;
class CATCVMApplicationData;
class CATICVMApplicationData;
class CATTolerance;
class CATCVMReference;

class ExportedByCATCVMGeoObjects CATCVMGeoContainer : public CATCVMContainer
{
  //------------------------------------------------------------------------------
  // Create a container
  //------------------------------------------------------------------------------
  public:
  static CATCVMGeoContainer *CreateContainer(CATCVMReference *iFederator = NULL);

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  protected:
  CATCVMGeoContainer(CATGeoFactory   *iGeoFactory,
                     CATCVMReference *iFederator = NULL);
  CATCGMNewClassArrayDeclare; // Pool allocation

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  protected:
  virtual ~CATCVMGeoContainer();

  //------------------------------------------------------------------------------
  // Create new container of same type as this, i.e. a CATCVMGeoContainer
  //------------------------------------------------------------------------------
  public:
  CATCVMContainer *CreateNewContainerOfSameType(CATCVMReference *iFederator);

  //------------------------------------------------------------------------------
  // Session scale management
  // Possible values:
  // iSessionScale == 1. //for standard scale
  // iSessionScale == 100. //for large scale
  //------------------------------------------------------------------------------
  public:
  static HRESULT SetSessionScale(double iSessionScale);

  //------------------------------------------------------------------------------
  // Set validity rule for topology
  // CATCVMGeoTopoRule_Standard: same as CATIA V5
  // CATCVMGeoTopoRule_NonManifold: allow edge full
  //------------------------------------------------------------------------------
  void SetTopoRule(CATCVMGeoTopoRule iTopoRule);
  CATCVMGeoTopoRule GetTopoRule();

  //------------------------------------------------------------------------------
  // Get GeoFactory
  //------------------------------------------------------------------------------
  public:
  CATGeoFactory *GetGeoFactory();
  CATGeoFactory *GetImplicitGeoFactory();

  public:
  double GetDistanceTolerance();

  public:
  double GetAngleTolerance();

  public:
  const double GetEpsgForLengthTest();
  const double GetLargeEpsgForLengthTest();
  const double GetModelSize();

  public:
  const CATTolerance& GetToleranceObject();

  //------------------------------------------------------------------------------
  // IsA
  //------------------------------------------------------------------------------
  public:
  virtual CATBoolean IsA(CATCVMObjectType iObjectType);
  virtual CATCVMObjectType GetType();

  //------------------------------------------------------------------------------
  // For Debug 
  //------------------------------------------------------------------------------
  public :
	CATBoolean Compare (CATCVMGeoContainer *iRef);
  //------------------------------------------------------------------------------
  // Internal Use only
  //------------------------------------------------------------------------------
  public :
  static CATCVMGeoContainer *CreateContainer(CATGeoFactory   *iGeoFactory,
                                             CATCVMReference *iFederator = NULL);
  //------------------------------------------------------------------------------
  // Set GeoFactory
  //------------------------------------------------------------------------------
  public:
  void  SetGeoFactory(CATGeoFactory *iGeoFactory);
  //------------------------------------------------------------------------------
  // Dump 
  //------------------------------------------------------------------------------
  public:
  void Dump(ostream * iStream=0L) const;
  //------------------------------------------------------------------------------
  // Check (returns S_OK if check is OK, E_FAIL otherwise)
  //------------------------------------------------------------------------------
  public:
  // HRESULT Check();  
  void CheckUp ( int iPurgeUndo = 0 );
  int  CheckUpCGMBodyLinks (ListPOfCATBody * oCGMBodyList=NULL );
  
  //------------------------------------------------------------------------------
  // Stream/Unstream
  //------------------------------------------------------------------------------
  public:

  virtual void    Stream( CATCVMSysStream* Str, CATBoolean iDebug=FALSE);
  virtual void    UnStream(CATCVMSysStream* Str, CATBoolean iSuppressMainComponent=FALSE,
                                                 CATBoolean iKarcherIsolatedVertices=FALSE);
  CATBoolean IsUnStreamed ();
  CATBoolean IsEmpty();

  void GetLinkedGeometry (CATCVMSysStream* iCVMStr);

  void AddApplicationData (CATICVMApplicationData *idata);
  CATBaseUnknown *GetApplicationData ();

  //------------------------------------------------------------------------------
private :
  virtual CATCVMObject * CreateObjectfromType (int iType);
  virtual CATCVMAttrRef * CreateAttrRefFromType (CATULONG32 iType);
  
  static CATGeoFactory * CreateFactory();
  static CATBoolean CheckFactory(CATGeoFactory * iFactory);

  CATGeoFactory * ReadGeometryV5(CATCGMStream* Str, CATLISTP(CATICGMObject)& CGMLinkedObjectList);
  void ReadCVMData (CATCVMGeoStream* Str, CATBoolean iSuppressMainComponent);
  void ReadApplicationData (CATCVMGeoStream* Str);

  void WriteGeometryV5(CATCGMStream *iCGMStr, CATLISTP(CATICGMObject)& CGMLinkedObjectList);
  void WriteCVMData (CATCVMGeoStream* Str);
  void WriteApplicationData (CATCVMGeoStream* Str, CATBoolean iDebug);

  void SetIsUnStreamed ();

  void WriteStreamVersion (CATCVMGeoStream* Str);
  void ReadStreamVersion  (CATCVMGeoStream* Str);
  CATBaseUnknown *CreateApplicationData ();
  CATBaseUnknown *CreateDEBUGApplicationData ();
  CATBaseUnknown *CreateExternalDatafromType (int iType);
  CATBaseUnknown *CreateExternalDataFromStream (CATCVMSysStream* Str);

  
  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  private:
    CATGeoFactory *   _GeoFactory;
    CATBoolean        _IsUnStreamed;
    CATCVMGeoTopoRule _TopoRule;
    CATBaseUnknown * _ApplicationData;
};
#endif
