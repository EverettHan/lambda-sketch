/* -*-C++-*- */

#ifndef CATCVMInstancePath_H
#define CATCVMInstancePath_H

// COPYRIGHT DASSAULT SYSTEMES 2007

//===================================================================
//===================================================================
//
// CATCVMInstancePath
//
// class for Collaborative Variational Modelling (CVM) instance paths
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// Dec. 2007    Creation                         Alex State
//===================================================================
#include "CATCVMSysObjects.h"
#include "CATCVMObject.h"
#include "CATCVMDef.h"
#include "CATDataType.h"
#include "ListPOfCATCVMInstance.h"
#include "CATCGMNewArray.h"

class CATCVMContainer;
class CATCVMPSContainer;
class CATCVMSysStream;
class CATCVMReference;
class CATCVMOccurrence;
class CATMathTransformation;
class CATCVMPSContainer;
class CATUnicodeString;
class CATMathPoint;
class CATMathVector;
class CATMathAxis;
class CATMathLine;
class CATMathCircle;
class CATMathPlane;

class ExportedByCATCVMSysObjects CATCVMInstancePath : public CATCVMObject
{

	public:
  CATDeclareClass;
  //------------------------------------------------------------------------------
  // Create InstancePath
  //------------------------------------------------------------------------------
  public:
  static CATCVMInstancePath *Create(CATCVMPSContainer *iContainer);

  //------------------------------------------------------------------------------
  // Old Create InstancePath - deprecated!
  //------------------------------------------------------------------------------
  public:
  static CATCVMInstancePath *Create(CATCVMContainer *iContainer);

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  protected:
  CATCVMInstancePath(CATCVMPSContainer *iContainer);
  CATCGMNewClassArrayDeclare;

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  protected:
  virtual ~CATCVMInstancePath();

  //------------------------------------------------------------------------------
  // CleanUp
  //------------------------------------------------------------------------------
  private:
  void CleanUp();
  
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
  CATCVMObjectType GetType();
  
  //------------------------------------------------------------------------------
  // Lock management of Instance Transformatin
  //------------------------------------------------------------------------------
  public:
  CATBoolean IsInstanceTransformationLocked();
  void LockInstanceTransformation();
  
  //------------------------------------------------------------------------------
  // Create a copy (all data CVM objects are duplicated as well, but not the
  // non-CVM data, e.g. the CATBody under a CATCVMBody is not duplicated)
  //------------------------------------------------------------------------------
  public:
  CATCVMObject *CreateCopy(CATCVMCopy *iCopy);

  //------------------------------------------------------------------------------
  // UndoRedo method
  //------------------------------------------------------------------------------
  void  UndoRedoDataSwapping (CATCVMObject *iCVMObject, int iCVMEvent);

  //------------------------------------------------------------------------------
  // Forget copy information
  //------------------------------------------------------------------------------
  //public:
  //virtual void ForgetCopy(CATCVMCopy *iCopy);

  //------------------------------------------------------------------------------
  // Copy all data
  //------------------------------------------------------------------------------
  virtual void CopyAllData(CATCVMObject *iInitialObject,
                           CATCVMCopy   *iCopy=NULL,
                           int           iLight=0);

  //------------------------------------------------------------------------------
  // GetTypeName
  //------------------------------------------------------------------------------
  public:
  virtual CATUnicodeString GetTypeName();

  //------------------------------------------------------------------------------
  // Dump 
  //------------------------------------------------------------------------------
  public:
  void Dump(ostream * iStream=0L) const;
  
  //------------------------------------------------------------------------------
  // Add instance
  //------------------------------------------------------------------------------
  public:
  HRESULT AddInstance(CATCVMInstance *iInstance);
  
  //------------------------------------------------------------------------------
  // Remove last instance
  //------------------------------------------------------------------------------
  public:
  HRESULT RemoveLastInstance();
  
  //------------------------------------------------------------------------------
  // Get the sequence of instances
  //------------------------------------------------------------------------------
  public:
  HRESULT GetInstanceList(ListPOfCATCVMInstance &oInstanceList);

  //------------------------------------------------------------------------------
  // Get the last instance
  //------------------------------------------------------------------------------
  public:
  HRESULT GetLastInstance(CATCVMInstance *&oLastInstance);

  //------------------------------------------------------------------------------
  // Get the last reference, i.e. the reference of the last
  // instance (or else the root reference)
  //------------------------------------------------------------------------------
  public:
  CATCVMReference *GetLastReference();

  //------------------------------------------------------------------------------
  // Compute the complete transformation
  //------------------------------------------------------------------------------
  public:
  HRESULT ComputeCompleteTransformation(CATMathTransformation &oTransformation,
                                        CATBoolean             iInverse = FALSE);

  //------------------------------------------------------------------------------
  // Transform an input point by multiplying it with the
  // inverted complete transformation
  //------------------------------------------------------------------------------
  public:
  HRESULT TransformInput(CATMathPoint &ioPoint, CATBoolean iInverse = TRUE);

  //------------------------------------------------------------------------------
  // Transform an input vector by multiplying it with the
  // inverted complete transformation
  //------------------------------------------------------------------------------
  public:
  HRESULT TransformInput(CATMathVector &ioVector, CATBoolean iInverse = TRUE);

  //------------------------------------------------------------------------------
  // Transform an input math line by multiplying it with the
  // inverted complete transformation
  //------------------------------------------------------------------------------
  public:
  HRESULT TransformInput(CATMathLine &ioLine, CATBoolean iInverse = TRUE);

  //------------------------------------------------------------------------------
  // Transform an input math plane by multiplying it with the
  // inverted complete transformation
  //------------------------------------------------------------------------------
  public:
  HRESULT TransformInput(CATMathPlane &ioPlane, CATBoolean iInverse = TRUE);

  //------------------------------------------------------------------------------
  // Transform an input math circle by multiplying it with the
  // inverted complete transformation
  //------------------------------------------------------------------------------
  public:
  HRESULT TransformInput(CATMathCircle &ioCircle, CATBoolean iInverse = TRUE);

  //------------------------------------------------------------------------------
  // Transform an input length by multiplying it with the
  // inverted complete transformation
  //------------------------------------------------------------------------------
  public:
  HRESULT TransformInput(double &ioLength, CATBoolean iInverse = TRUE);

  //------------------------------------------------------------------------------
  // Transform an input axis by multiplying it with the
  // inverted complete transformation
  //------------------------------------------------------------------------------
  public:
  HRESULT TransformInput(CATMathAxis &ioAxis, CATBoolean iInverse = TRUE);

  //------------------------------------------------------------------------------
  // Transform an input transformation by multiplying it with the
  // inverted complete transformation
  //------------------------------------------------------------------------------
  public:
  HRESULT TransformInput(CATMathTransformation &ioTransformation, CATBoolean iInverse = TRUE);

  //------------------------------------------------------------------------------
  // Get the product structure container (from the instance path)
  //------------------------------------------------------------------------------
  public:
  CATCVMPSContainer *GetPSContainer();

  //------------------------------------------------------------------------------
  // transfer an object from its current contaienr to a new container
  //------------------------------------------------------------------------------
  public :
  void Transfer(CATCVMContainer     *iTargetContainer,
                ListPOfCATCVMObject &ioObjectsToTransfer);

  //------------------------------------------------------------------------------
  // Stream/UnStream
  //------------------------------------------------------------------------------
  public :
  virtual void	  UnStream (CATCVMSysStream* Str, CATCVMContainer * iCVMFactory);
  virtual void    Stream   (CATCVMSysStream* CVMStr);
  private :
  virtual void    GetLinkedGeometry (CATCVMSysStream* CVMStr); 

  //------------------------------------------------------------------------------
  // Compare
  //------------------------------------------------------------------------------
  public:
  virtual CATBoolean Compare (CATCVMObject *iRef);

  //------------------------------------------------------------------------------
  // Compare instance lists
  //------------------------------------------------------------------------------
  private:
  CATBoolean CompareInstanceLists(CATCVMInstancePath *iRefInstancePath);

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  private:
  ListPOfCATCVMInstance  _InstanceList;
  CATBoolean             _TransformationHasBeenLocked;

};
#endif
