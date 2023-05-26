/* -*-C++-*- */

#ifndef CATCVMBody_H
#define CATCVMBody_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMObject
//
// class for Collaborative Variational Modelling (CVM) bodies
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// Mar. 2006    Creation                         Alex State
//===================================================================
#include "CATCVMGeoObjects.h"
#include "CATCVMGeoRep.h"
#include "CATCVMDef.h"
#include "CATCVMLog.h"
#include "CATCGMNewArray.h"

#include "CATICGMObject.h"
#include "CATCGMHashTableWithAssoc.h"

#ifdef _CAT_ANSI_STREAMS
#include <iosfwd.h>
#else
class ostream;
#endif

class CATBody;
class CATGeometry;
class CATCGMJournalList;
class CATCGMOutput;
class CATISpecObject;
class CATUnicodeString;
class CATVirtualInfraObject;

class CATCVMGeometry;
class CATCVMGeoContainer;
class CATCVMCopy;

class CATCVMTexture;
class CATMathTransformation;


class ExportedByCATCVMGeoObjects CATCVMBody : public CATCVMGeoRep
{
  //------------------------------------------------------------------------------
  // Component declaration
  //------------------------------------------------------------------------------
  CATDeclareClass;
  //------------------------------------------------------------------------------
  // CreateBody
  //------------------------------------------------------------------------------
  public:
  static CATCVMBody *Create(CATCVMGeoContainer *iContainer);

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  protected:
  CATCVMBody(CATCVMGeoContainer *iContainer);
  CATCGMNewClassArrayDeclare;

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  protected:
  virtual ~CATCVMBody();

  //------------------------------------------------------------------------------
  // IsA
  //------------------------------------------------------------------------------
  public:
  CATBoolean IsA(CATCVMObjectType iObjectType);
  CATCVMObjectType GetType();

  //------------------------------------------------------------------------------
  // Set the CGM body
  //------------------------------------------------------------------------------
  public:
  void SetCGMBody(CATBody *iCGMBody , int iForceToDelete=0);

  //------------------------------------------------------------------------------
  // Get the CGM body
  //------------------------------------------------------------------------------
  public:
  CATBody *GetCGMBody();

  //------------------------------------------------------------------------------
  // CheckUp the CVM body
  //------------------------------------------------------------------------------
  public:
  HRESULT CheckUp(int iCVMEvent=CVMLogEvent_Modify);

  //------------------------------------------------------------------------------
  // Find the CVM geometry that points to a given CGM geometry
  //------------------------------------------------------------------------------
  public:
  CATCVMGeometry *FindGeometry(CATGeometry *iCGMGeometry);

  //------------------------------------------------------------------------------
  // Create allowed attribute
  //------------------------------------------------------------------------------
  public:
  CATCVMAttribute * CreateAttribute (CATCVMAttributeType iType);

  //------------------------------------------------------------------------------
  // Textures and colors
  //------------------------------------------------------------------------------
  private:
  void UpdateTexturePosition(CATCVMObject    *iInitialObject,
                             CATCVMAttribute *iNewTextureAttribute); 
  public:
  void UpdateTexturePosition(CATMathTransformation &iTransformation);

  //------------------------------------------------------------------------------
  // Update
  //------------------------------------------------------------------------------
  public:
  void Update(CATBody           *iNewCGMBody,
              CATCGMJournalList *iJournalList,
              CATCVMLog         *iCVMLog);
/*
  //------------------------------------------------------------------------------
  // Set infrastructure object
  //------------------------------------------------------------------------------
  public:
  void SetInfraObject(CATVirtualInfraObject *iInfraObject,
                      CATBoolean             iSetNameOnInfraObject = TRUE);

  //------------------------------------------------------------------------------
  // Get infrastructure object
  //------------------------------------------------------------------------------
  public:
  CATVirtualInfraObject *GetInfraObject();

  //------------------------------------------------------------------------------
  // Set name on infrastructure object
  //------------------------------------------------------------------------------
  public:
  void SetNameOnInfraObject();

  //------------------------------------------------------------------------------
  // Get name from infrastructure object
  //------------------------------------------------------------------------------
  public:
  void GetNameFromInfraObject();
*/
  //------------------------------------------------------------------------------
  // Create a copy (all data CVM objects are duplicated as well, but not the
  // non-CVM data, e.g. the CATBody under a CATCVMBody is not duplicated)
  //------------------------------------------------------------------------------
  public:
  CATCVMObject *CreateCopy(CATCVMCopy *iCopy=NULL);
  void IdenticalDataCopy(CATCVMObject * iCVMPrev);
  void LocalDataCopy(CATCVMBody * iCVMPrev);
  
  //------------------------------------------------------------------------------
  // Swap Definition from CVMPhoto for Undo / Redo Treatment
  //------------------------------------------------------------------------------
  void UndoRedoDataSwapping(CATCVMObject *iCVMObject, int iCVMEvent);
  
  //------------------------------------------------------------------------------
  // Copy all data
  //------------------------------------------------------------------------------
  protected:
  void CopyAllData(CATCVMObject *iInitialObject, CATCVMCopy *iCopy=NULL, int  iLight=0);
                          
  //------------------------------------------------------------------------------
  // GetTypeName
  //------------------------------------------------------------------------------
  public:
  virtual CATUnicodeString GetTypeName();
/*
  //------------------------------------------------------------------------------
  // Is the body shown?
  //------------------------------------------------------------------------------
  public:
  CATBoolean IsShown();

  //------------------------------------------------------------------------------
  // Show the body
  //------------------------------------------------------------------------------
  public:
  void Show(CATBoolean iShow);
*/
//  virtual HRESULT LaunchEventForDemo ();
  //------------------------------------------------------------------------------
  // Reverse Link methods
  //------------------------------------------------------------------------------
  public:
  void       ReverseLinkActivation();
  CATBoolean ReverseLinkDeactivation();
  private:
  void       ReverseLinkCreation();
 //------------------------------------------------------------------------------
  // Dump 
  //------------------------------------------------------------------------------
  public :
  virtual void Dump(ostream * iStream, int idecal) const;
  void Dump(ostream * iStream) const;

  //------------------------------------------------------------------------------
  // Stream/UnStream
  //------------------------------------------------------------------------------
  public :
  virtual void	  UnStream (CATCVMSysStream* Str, CATCVMContainer * iCVMFactory);
  virtual void    Stream   (CATCVMSysStream* CVMStr);
  
  virtual void GetLinkedGeometry (CATCVMSysStream* iCVMStr);
  virtual void CleanIsStreamed ();


  //------------------------------------------------------------------------------
  // For Debug 
  //------------------------------------------------------------------------------
  public :
  virtual CATBoolean Compare (CATCVMObject *iRef);

  //------------------------------------------------------------------------------
  // Release data
  //------------------------------------------------------------------------------
  public:
  virtual void ReleaseData();

  //------------------------------------------------------------------------------
  // CleanUp
  //------------------------------------------------------------------------------
  private:
  void CleanUp();

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  private:
  CATBody                  * _CGMBody;
  int                        _ReverseLinkActivation ;
  CATCGMHashTableWithAssoc * _ReverseLinkHashTab;
  

//  CATVirtualInfraObject *_InfraObject;
};
#endif
