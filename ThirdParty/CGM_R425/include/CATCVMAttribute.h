#ifndef CATCVMAttribute_h
#define CATCVMAttribute_h

#include "CATCVMAttributeDef.h"
#include "CATCVMSysObjects.h"
#include "CATCVMAttrRef.h"
#include "CATCVMSysStream.h"
#include "CATCGMNewArray.h"
#include "CATErrorDef.h"
class CATCVMObject;
class CATCVMAttrRef;

class ExportedByCATCVMSysObjects CATCVMAttribute
{

//public:
//  static CATCVMAttribute * CATCVMAttribute::CreateCVMAttribute(CATCVMAttributeType iType, CATCVMObject * iObject);

public:
  CATCVMAttribute (CATCVMObject * iOwner);
  CATCGMNewClassArrayDeclare;
  virtual ~CATCVMAttribute();

  // Attribute reference
  void SetAttrRef(CATCVMAttrRef * iRef);
  CATCVMAttrRef * GetAttrRef();

  // Manage chain of attributes
  CATCVMObject * GetOwner();
//  HRESULT LinkInChain (CATCVMAttribute * iAttrToLinkWithMe);
  HRESULT IsolateFromChain ();
//  CATCVMAttribute *  GetNextInChain ();
//  CATCVMAttribute *  GetPrevInChain ();
  int GetType();

  // Copy
  virtual CATCVMAttribute * CopyCVMAttribute(CATCVMObject * iOwner) = 0;

  // Stream/Unstream
  virtual void Stream(CATCVMSysStream * iStream) = 0;
  virtual void Unstream(CATCVMSysStream * iStream) = 0; 

protected:
  //	CATCVMAttribute(CATCVMAttribute&);
  //	void operator =(CATCVMAttribute&);

  CATCVMAttributeType _Type;
  CATCVMObject * _Owner;
  CATCVMAttribute * _NextInChain;
  CATCVMAttribute * _PrevInChain;

private:
  CATCVMAttrRef * _Ref;

};
#endif

