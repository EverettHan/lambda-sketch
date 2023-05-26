// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATIPLMClientCorePath.h
// Define the CATIPLMClientCorePath interface
//
//===================================================================
//
// Usage notes:
//   This interface exposes functions to manipulate the concept of path in the PLM Model as implemented in CATPLMClientCore.
//
//===================================================================
//
//  Dec 2008  Creation: Code generated by the CAA wizard  XVI
//===================================================================

/**
 * @level Protected
 * @usage U1
 */

#ifndef CATIPLMClientCorePath_H
#define CATIPLMClientCorePath_H

#include "CATPLMComponentInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATOmxSR.h"

class CATListPtrCATBaseUnknown;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMComponentInterfaces IID IID_CATIPLMClientCorePath;
#else
extern "C" const IID IID_CATIPLMClientCorePath;
#endif

//------------------------------------------------------------------

/**
* A list of CATBaseUnknown
* Use it if forced else use CATOmxList<CATBaseUnknown> or CATListValCATBaseUnknown_var
* You can create an object implementing this interface using CATIPLMClientCorePath::Create
* You have no reason to implement this interface
*/
class ExportedByCATPLMComponentInterfaces CATIPLMClientCorePath : public CATBaseUnknown
{
  CATDeclareInterface;
public:
  /**
   * create an object implementing this interface
   */
  static CATOmxSR<CATIPLMClientCorePath> Create();

    /**
  * This function adds an element at the end of the path.
  * @param ipElement
  *		is a pointer to the element to add.
  * @return
  * An HRESULT value.
  * <br>Legal values</br>:
  * <dl>
  * <dt>S_OK</dt>
  * <dd>The element is at the end of the path.</dd>
  * <dt>E_INVALIDRG</dt>
  * <dd>The input parameter is invalid.</dd>
  * </dl>
  */
  virtual HRESULT AddElement(CATBaseUnknown* ipElement) = 0;

  /**
  * This function empties the path.
  * @return S_OK
  */
  virtual HRESULT EmptyPath() = 0;

  /**
  * This function returns a pointer to the last element of the path.
  * @param opElement [out, CATBaseUnknown#Release]
  *	is a pointer to CATBaseUnknown.
  * @return
  *	An HRESULT value.
  * <br>Legal values</br>:
  * <dl>
  *	<dt>S_OK</dt>
  * <dd>The ouput parameter is a pointer to the last element and must be released by caller.</dd>
  * <dt>E_FAIL</dt>
  * <dd>The function failed.</dd>
  * </dl>
  */
  virtual HRESULT GetLast(CATBaseUnknown* &opElement) = 0;

  /**
  * This function returns the number of elements in the structure, aka the size of the path.
  * @return
  * An <i>int</i> value corresponding to the size of the path.
  */
  virtual int GetSize() = 0;

  /**
  * This function returns the whole path.
  *
  * <br><b>Role</b>: It returns a list of pointer to CATBaseUnknown elements..
  *
  * @param oList [out]
  *   The path. Elements must be released.
  *
  * @return S_OK
  *
  */
  virtual HRESULT GetWholePath(CATListPtrCATBaseUnknown &oList) = 0;

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

//------------------------------------------------------------------




#endif