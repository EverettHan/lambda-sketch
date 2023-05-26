/* -*-C++-*- */

#ifndef CATCVMGeoMesh_H
#define CATCVMGeoMesh_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMObject
//
// class for Collaborative Variational Modelling (CVM) GeoMesh
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// Nov. 2007    Creation                         Edwige Morawska
//===================================================================
#include "CATCVMGeoObjects.h"
#include "CATCVMGeoRep.h"
#include "CATCVMDef.h"
#include "CATCGMNewArray.h"
#include "CATMathPoint.h"


#ifdef _CAT_ANSI_STREAMS
#include <iosfwd.h>
#else
class ostream;
#endif

class CATCGMOutput;
class CATUnicodeString;

class CATCVMGeoContainer;
class CATCVMCopy;


class CATCVMVisu;
class CATRep;

class CATILockBytes2;
class CATMathPointf;

class ExportedByCATCVMGeoObjects CATCVMGeoMesh : public CATCVMGeoRep
{
  //------------------------------------------------------------------------------
  // Component declaration
  //------------------------------------------------------------------------------
  CATDeclareClass;
  //------------------------------------------------------------------------------
  // CreateGeoMesh
  //------------------------------------------------------------------------------
  public:
  static CATCVMGeoMesh *Create(CATCVMGeoContainer *iContainer);

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  protected:
  CATCVMGeoMesh(CATCVMGeoContainer *iContainer);
  CATCGMNewClassArrayDeclare;

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  protected:
  virtual ~CATCVMGeoMesh();

  //------------------------------------------------------------------------------
  // IsA
  //------------------------------------------------------------------------------
  public:
  CATBoolean IsA(CATCVMObjectType iObjectType);
  CATCVMObjectType GetType();

  //------------------------------------------------------------------------------
  // Set the CGM GeoMesh
  //------------------------------------------------------------------------------
  public:
  //void SetRep (CATBaseUnknown * iRep);
  CATCVMVisu * GetVisu ();
  void SetVisu (CATCVMVisu * iVisu);

  CATRep * GetRep ();
  
  void SetPath   (const CATUnicodeString & iFileName);
  CATUnicodeString &GetPath ();

  void SetBuffer (CATILockBytes2 * iBuffer, int iForceToDelete=0);
  CATILockBytes2 * GetBuffer ();

 // void SetBoundingSphere (const  CATMathPointf  &center,  const  double  radius);
 // void GetBoundingSphere (CATMathPointf  &center,  double &radius);
  void SetBoundingBox (const  CATMathPoint  &Min,  const  CATMathPoint  &Max);
  void GetBoundingBox (CATMathPoint  &Min,  CATMathPoint  &Max);



 
  //------------------------------------------------------------------------------
  // Find the CVM geometry that points to a given CGM geometry
  //------------------------------------------------------------------------------
  //public:
  // CATCVMGeometry *FindGeometry(CATGeometry *iCGMGeometry);
  //------------------------------------------------------------------------------
  // Create allowed attribute
  //------------------------------------------------------------------------------
  //public:
  //CATCVMAttribute * CreateAttribute (CATCVMAttributeType iType);
  // void UpdateTexturePosition(CATMathTransformation &iTransformation);

  //------------------------------------------------------------------------------
  // Create a copy (all data CVM objects are duplicated as well, but not the
  // non-CVM data, e.g. the CATGeoMesh under a CATCVMGeoMesh is not duplicated)
  //------------------------------------------------------------------------------
  public:
  CATCVMObject *CreateCopy(CATCVMCopy *iCopy);
  void IdenticalDataCopy(CATCVMObject * iCVMPrev);
  
  void LocalDataCopy(CATCVMGeoMesh *iCVMPrev);

  //------------------------------------------------------------------------------
  // Copy all data
  //------------------------------------------------------------------------------
  protected:
  virtual void CopyAllData(CATCVMObject *iInitialObject,
                           CATCVMCopy   *iCopy=NULL,
                           int           iLight=0);


  CATCVMVisu * GetDuplicatedCVMVisu ();

  //------------------------------------------------------------------------------
  // GetTypeName
  //------------------------------------------------------------------------------
  public:
  virtual CATUnicodeString GetTypeName();

  //------------------------------------------------------------------------------
  // Get the CVMGeoContainer
  //------------------------------------------------------------------------------
  public:
  CATCVMGeoContainer *GetCVMGeoContainer();

  //------------------------------------------------------------------------------
  // Dump 
  //------------------------------------------------------------------------------
  public :
  virtual void Dump(ostream * iStream=0L, int idecal=0) const;

  //------------------------------------------------------------------------------
  // Stream/UnStream
  //------------------------------------------------------------------------------
  public :
  virtual void	  UnStream (CATCVMSysStream* Str, CATCVMContainer * iCVMFactory);
  virtual void    Stream   (CATCVMSysStream* CVMStr);
  
  virtual void GetLinkedGeometry (CATCVMSysStream* iCVMStr);
  void  CleanIsStreamed ();

  //------------------------------------------------------------------------------
  // For Debug 
  //------------------------------------------------------------------------------
  public :
  virtual CATBoolean Compare (CATCVMObject *iRef);

  //------------------------------------------------------------------------------
  //------------------------------------------------------------------------------

  public:
    virtual HRESULT ComputeBoundingBox();


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
    CATUnicodeString     _Path;
   // CATBaseUnknown      *_Rep;

    CATCVMVisu * _Visu;

    CATMathPoint  _Min;
    CATMathPoint  _Max;

  //  CATMathPointf        _center;  
  //  double               _radius;  

    // CATULONG32           _BufferSize;
    // CATILockBytes2 *   _Buffer;
    // CATVirtualInfraObject *_InfraObject;
};
#endif
