// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATExtIPLMAttrRead.h
// Provide implementation for some methods of interface CATIPLMAttrRead
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//  Feb 2009  virtual added because it is an adapter.
//  Dec 2003  Creation: Code generated by the CAA wizard  jvm
//===================================================================
#ifndef CATExtIPLMAttrRead_H
#define CATExtIPLMAttrRead_H

/**
* @level Protected
* @usage U2
*/

#include "CATPLMImplAdapterClass.h"// ExportedByCATPLMImplAdapterClass

#include "CATPLMAttrReadAdapter.h"

#include "CATPLMOmxCollections.h"

class CATPLMType;
class CATPLMAttribute;
class CATListPtrCATPLMAttribute;
class CATUnicodeString;
class CATListValCATUnicodeString;
class CATString;
class CATListValCATString;
class CATBinary;

//-----------------------------------------------------------------------

/**
*  Adapter for object attributes reading interface. 
*/
class ExportedByCATPLMImplAdapterClass CATExtIPLMAttrRead: public CATPLMAttrReadAdapter
{
public:
  
  // Standard constructors and destructors for an implementation class
  // -----------------------------------------------------------------
  CATExtIPLMAttrRead ();
  CATExtIPLMAttrRead ( CATPLMType * iType);
  virtual ~CATExtIPLMAttrRead ();
  
  // Adapter implementation of some methods of CATIPLMAttrRead
  virtual HRESULT GetStringValue( CATPLMMask iMask, int iAttrIndex, CATUnicodeString ** oValue );
  virtual HRESULT GetStringValue( CATString * iAttributeId, CATUnicodeString ** oValue ); 
  virtual HRESULT GetStringValue( CATPLMAttribute  * iAttribute, CATUnicodeString ** oValue );  
    
  virtual HRESULT GetBinaryValue ( CATPLMMask iMask,int iAttrIndex, CATBinary  **  oValue );
  virtual HRESULT GetBinaryValue ( CATString       *  iAttributeId, CATBinary  **  oValue );
  virtual HRESULT GetBinaryValue ( CATPLMAttribute *  iAttribute, CATBinary  **  oValue );

  virtual HRESULT GetBooleanValue ( CATPLMMask iMask,int iAttrIndex, CATBoolean *  oValue );
  virtual HRESULT GetBooleanValue ( CATString       *  iAttributeId, CATBoolean *  oValue );
  virtual HRESULT GetBooleanValue ( CATPLMAttribute *  iAttribute, CATBoolean *  oValue );

  virtual HRESULT ListAttributes (CATPLMMask iMask  , CATListPtrCATPLMAttribute **  oAttribute ) ;
  virtual HRESULT ListAttributes (CATPLMMask iMask  , CATListValCATString **  oAttributeIdList ) ;
  virtual HRESULT ListAttributes(CATPLMMask iMask, CATPLMAttributeList& oAttributeList);
  virtual HRESULT ListAttributes(CATPLMMask iMask, CATListValCATString& oAttributeIdList);
  virtual HRESULT AttributeCount (CATPLMMask iMask, int *oAttrCount) ;

  virtual CATPLMType* GetType();
protected:  
  CATPLMType                 * _pType;       // The CATPLMType of the Object   
  CATListValCATString        * _pAttrIdList; // The List of Attribute Id. Same size as _pValueList size   
  CATListValCATUnicodeString * _pValueList;  // The List of Attribute Value. Same size as _pAttrIdList size.
  
private:
  // The copy constructor and the equal operator must not be implemented
  // -------------------------------------------------------------------
  CATExtIPLMAttrRead (CATExtIPLMAttrRead &);
  CATExtIPLMAttrRead& operator=(CATExtIPLMAttrRead&);
      
};

//-----------------------------------------------------------------------

#endif