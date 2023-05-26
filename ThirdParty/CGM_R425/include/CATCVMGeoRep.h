/* -*-C++-*- */

#ifndef CATCVMGeoRep_H
#define CATCVMGeoRep_H

// COPYRIGHT DASSAULT SYSTEMES 2007

//===================================================================
//===================================================================
// CATCVMGeoRep
//
// Class for geometric representations
//===================================================================

//===================================================================
// Nov. 2007    Creation                         Francois Dujardin
//===================================================================

#include "CATCVMGeoObjects.h"
#include "CATCVMSystem.h"
#include "CATCVMDef.h"
#include "CATCGMNewArray.h"

class CATUnicodeString;
class CATCVMGeoContainer;
class CATCVMCopy;
class CAT3DRep;

class ExportedByCATCVMGeoObjects CATCVMGeoRep : public CATCVMSystem
{
  CATDeclareClass;
  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  protected:
  CATCVMGeoRep(CATCVMGeoContainer *iContainer);

  CATCGMNewClassArrayDeclare;

  //------------------------------------------------------------------------------
  // Destructor 
  //TODO: must be made protected when migration on correct AddRef/Release is completed
  //------------------------------------------------------------------------------
  protected:
  virtual ~CATCVMGeoRep();

  //------------------------------------------------------------------------------
  // ReleaseData
  //------------------------------------------------------------------------------
  public:
  virtual void ReleaseData();
  
  //------------------------------------------------------------------------------
  // IsA
  //------------------------------------------------------------------------------
  public:
  CATBoolean IsA(CATCVMObjectType iObjectType);

  //------------------------------------------------------------------------------
  // GetTypeName
  //------------------------------------------------------------------------------
  public:
  virtual CATUnicodeString GetTypeName();
  
  //------------------------------------------------------------------------------
  // GetType
  //------------------------------------------------------------------------------
  public:
  CATCVMObjectType GetType();

  //------------------------------------------------------------------------------
  // Get the CVMGeoContainer
  //------------------------------------------------------------------------------
  public:
  CATCVMGeoContainer *GetCVMGeoContainer();

  //------------------------------------------------------------------------------
  // Create a copy (all data CVM objects are duplicated as well, but not the
  // non-CVM data, e.g. the CATBody under a CATCVMBody is not duplicated)
  //------------------------------------------------------------------------------
  public:
  virtual void IdenticalDataCopy(CATCVMObject * iCVMPrev);
  void LocalDataCopy(CATCVMGeoRep *iCVMPrev);

  //------------------------------------------------------------------------------
  // Get/Set 3DRep
  //------------------------------------------------------------------------------
  public:
  virtual HRESULT Set3DRep (CAT3DRep * iRep);
  virtual CAT3DRep * Get3DRep ();
  
  //------------------------------------------------------------------------------
  // Copy all data
  //------------------------------------------------------------------------------
  protected:
  virtual void CopyAllData(CATCVMObject *iInitialObject,
                           CATCVMCopy   *iCopy=NULL,
                           int           iLight=0);
  
//------------------------------------------------------------------------------
  // Stream/UnStream
  //------------------------------------------------------------------------------
  public :
  virtual void	  UnStream (CATCVMSysStream* Str, CATCVMContainer * iCVMFactory)=0;
  virtual void    Stream   (CATCVMSysStream* CVMStr)=0;

  public :
  virtual void Dump(ostream * iStream=0L, int idecal=0)const =0 ;

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  private:
  CAT3DRep * _3DRep;


};
#endif
