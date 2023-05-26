/* -*-C++-*- */

#ifndef CATCVMGeometry_H
#define CATCVMGeometry_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMObject
//
// class for Collaborative Variational Modelling (CVM) geometries
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
#include "CATCVMAtom.h"
#include "CATCVMDef.h"
#include "CATCVMGeoDef.h"
#include "CATCVMAttributeDef.h"
#include "CATDataType.h"

#include "CATICGMObject.h"

#ifdef _CAT_ANSI_STREAMS
#include <iosfwd.h>
#else
class ostream;
#endif

class CATCVMSystem;  
class CATGeometry;
class CATUnicodeString;
class CATCVMCopy;
class CATCVMBody;
class CATCell;
class CATVolume;
class CATFace;
class CATEdge;
class CATVertex;
class CATCVMGeoContainer;
class CATCVMAttribute;

class ExportedByCATCVMGeoObjects CATCVMGeometry : public CATCVMAtom
{
  CATDeclareClass;
  //------------------------------------------------------------------------------
  // CreateGeometry
  //------------------------------------------------------------------------------
  public:
  static CATCVMGeometry *Create(CATCVMGeoContainer *iContainer);

  //------------------------------------------------------------------------------
  // Constructors
  //------------------------------------------------------------------------------
  private:
  CATCVMGeometry(CATCVMGeoContainer *iContainer);

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  protected:
  virtual ~CATCVMGeometry();

  //------------------------------------------------------------------------------
  // Get CVMGeoContainer
  //------------------------------------------------------------------------------
  public:
  CATCVMGeoContainer *GetCVMGeoContainer();

  //------------------------------------------------------------------------------
  // IsA
  //------------------------------------------------------------------------------
  public:
  CATBoolean IsA(CATCVMObjectType iObjectType);
  CATCVMObjectType GetType();

  //------------------------------------------------------------------------------
  // Return TRUE if this points to a valid CGMGeometry; FALSE otherwise.
  //------------------------------------------------------------------------------
  public:
  CATBoolean IsCGMGeometry();

  //------------------------------------------------------------------------------
  // Set CGM geometry
  //------------------------------------------------------------------------------
  public:
  void SetCGMGeometry(CATGeometry *iCGMGeometry, CATBoolean RemoveIfPossible=FALSE);

  //------------------------------------------------------------------------------
  // Get CGM geometry
  //------------------------------------------------------------------------------
  public:
  CATGeometry *GetCGMGeometry();

  //------------------------------------------------------------------------------
  // Get CGM cell
  //------------------------------------------------------------------------------
  public:
  CATCell *GetCGMCell();

  //------------------------------------------------------------------------------
  // Get CGM Volume if possible (returns NULL if it's not a Volume)
  //------------------------------------------------------------------------------
  public:
  CATVolume *GetCGMVolume();

  //------------------------------------------------------------------------------
  // Get CGM Face if possible (returns NULL if it's not a Face)
  //------------------------------------------------------------------------------
  public:
  CATFace *GetCGMFace();

  //------------------------------------------------------------------------------
  // Get CGM Edge if possible (returns NULL if it's not an Edge)
  //------------------------------------------------------------------------------
  public:
  CATEdge *GetCGMEdge();

  //------------------------------------------------------------------------------
  // Get CGM Vertex if possible (returns NULL if it's not a Vertex)
  //------------------------------------------------------------------------------
  public:
  CATVertex *GetCGMVertex();

/*
  public:
  CATCVMCanonicity GetCanonicity();
*/
  //------------------------------------------------------------------------------
  // Create a copy
  //------------------------------------------------------------------------------
  public:
  CATCVMObject *CreateCopy(CATCVMCopy   *iCopy);
  void IdenticalDataCopy (CATCVMObject *iCVMPrev);
  void LocalDataCopy (CATCVMGeometry *iCVMPrev);
 
  //------------------------------------------------------------------------------
  // GetTypeName
  //------------------------------------------------------------------------------
  public:
  virtual CATUnicodeString GetTypeName();

  //------------------------------------------------------------------------------
  // Transfer all links coming from other CVMGeometry 
  //------------------------------------------------------------------------------
  public:
  void TransferLinks (CATCVMGeometry *iCVMGeometryToTransfer);
  
  //------------------------------------------------------------------------------
  // Get body
  //------------------------------------------------------------------------------
  public:
  CATCVMBody *GetBody();

  //------------------------------------------------------------------------------
  // Dump 
  //------------------------------------------------------------------------------
  public:
  void Dump(ostream * iStream=0L) const;

  virtual void ExtendedDump(CATUnicodeString & oExtendedDump) const;

  //------------------------------------------------------------------------------
  // Create allowed attribute
  //------------------------------------------------------------------------------
  virtual CATCVMAttribute * CreateAttribute (CATCVMAttributeType iType);

  //------------------------------------------------------------------------------
  // Update texture position
  //------------------------------------------------------------------------------
  protected:
  void UpdateTexturePosition(CATCVMObject    *iInitialObject,
                             CATCVMAttribute *iNewTextureAttribute,
                             CATCVMCopy      *iCopy=NULL );

  //------------------------------------------------------------------------------
  // Update texture position
  //------------------------------------------------------------------------------
  private:
  void UpdateTexturePosition(CATGeometry     *iInitialGeometry,
                             CATCVMAttribute *iNewTextureAttribute,
                             CATCVMCopy      *iCopy=NULL );

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  protected:
  CATGeometry *_CGMGeometry;
  //------------------------------------------------------------------------------
  // Stream/UnStream
  //------------------------------------------------------------------------------
  public :
  virtual void	  UnStream (CATCVMSysStream* Str, CATCVMContainer * iCVMFactory);
  virtual void    Stream (CATCVMSysStream* CVMStr);
  virtual void    GetLinkedGeometry (CATCVMSysStream* CVMStr);

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


//  HRESULT LaunchEventForDemo ();
};
#endif
