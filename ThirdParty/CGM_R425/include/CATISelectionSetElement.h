// COPYRIGHT Dassault Systemes 2002
//===================================================================
//
// CATISelectionSetElement.h
// Define the CATISelectionSetElement interface
//
//===================================================================
//
// Usage notes:
//   Compute CATPathElement, compare element of a Selection Set Elements
//
//===================================================================
/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */
#ifndef CATISelectionSetElement_H
#define CATISelectionSetElement_H

#include "UIModelInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATLISTV_CATBaseUnknown.h"

class CATPathElement;
class CATListPtrCATPathElement;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByUIModelInterfaces IID IID_CATISelectionSetElement;
#else
extern "C" const IID IID_CATISelectionSetElement ;
#endif

//------------------------------------------------------------------

/**
 * Interface to handle a Selection Set element.
 * <br><b>Role:</b> A Selection Set element is managed by @href CATISelectionSet .
 *                  <br>A Selection Set contains elements. An element is a feature 
 *                  or a sub-element (face, edge, vertex, ...) and is refered by a CATPathElement. As the element
 *                  can change with the design, the path can be modified. So the path that is used the first 
 *                  time to create the Selection Set element is named initial path. 
 */
class ExportedByUIModelInterfaces CATISelectionSetElement: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

  /**
    *   Computes the initial path of the Selection Set element.
    *   @param oElementPath
    *      The initial path of this.
    *      <br>The path can be relative to the document or an absolute path, depending on the content of the value
    *          of iDocInstancePath.

    *   @param iDocInstancePath
    *       The path of the instance of the document containing the Selection Set which includes this, or NULL.
    *      <ul> 
    *         <li> NULL (the default value) if you want that the returned path is relative to the document. </li>
    *         <li> the path of the instance of the document containing the Selection Set if you want that
    *              the returned path of the element is an absolute path in the Product context. </li>
    *      </ul>
    *   @return
    *   Error code.
    *   <br><b>Legal values</b>: <ul>
    *   <li><tt>E_FAIL</tt>: if the path is not computed.</li>
    *   <li><tt>S_OK</tt>: if the path is computed.</li></ul>
    */
  virtual HRESULT ComputePath (CATPathElement *& oElementPath,
                               CATPathElement * iDocInstancePath=NULL) = 0 ;

  /**
    *   Computes the updated path of the Selection Set element.
    *   <br><b>Role:</b>  The @href #ComputePath method returns the initial path of the Selection Set element
    *   (the one used in the @href CATISelectionSet#AddElement method) while the 
    *   <tt>ComputePathWithContext</tt> method returns the path in the last feature containing the element.
    *   For example if a face has been created in a feature and this feature has been absorbed by another feature, 
    *   this method retrieves the path of the element in the last feature.
    *   @param oListElementPath
    *      The paths of this, updated with the context.
    *      <br>Note that it is possible to have several paths for a Selection Set element : for example if a face is pointed by a
    *      Selection Set element and this face is divided in several faces by a pocket or another feature
    *      this method returns the paths of all the faces.
    *      <br>If the Selection Set element is not visible, the path is nul.
    *      <br>Release is needed on each element of the list except if nul.
    *      <br>The path can be relative to the document or an absolute path, depending on the content of the value
    *          of iDocInstancePath.
    *   @param iDocInstancePath
    *       The path of the instance of the document containing the Selection Set which includes this, or NULL.
    *      <ul> 
    *         <li> NULL (the default value) if you want that the returned path is relative to the document. </li>
    *         <li> the path of the instance of the document containing the Selection Set if you want that
    *              the returned path of the element is an absolute path in the Product context. </li>
    *      </ul>
    *   @return
    *   Error code.
    *   <br><b>Legal values</b>: <ul>
    *   <li><tt>E_FAIL</tt>: if the path is not computed. In this case, you can retrieve the error 
    *        using the CATError::CATGetLastError method. On this error, you can get the message using 
    *        the GetNLSMessage on the error to have more information.
    *        Do not forget to release the error then.</li>
    *   <li><tt>S_OK</tt>: if the path is computed.</li></ul>
    */
  virtual HRESULT ComputePathWithContext (CATLISTP(CATPathElement) & oListElementPath,
                                          CATPathElement * iDocInstancePath=NULL) = 0;

  /**
    * Compares this with another Selection Set element.
    * <br><b>Role</b>:
    * Returns the result of the comparison of the two Selection Set elements.
    * This comparison is made on the initial paths returned by @href #ComputePath.
    * The elements can be identical even if they are not in the same Selection Set.
    * @param iSetElement
    *   The Selection Set element to be compared with.
    * @return
    *   The status.
    *   <br><b>Legal values</b>: <ul>
    *   <li><tt>0</tt>: the two Selection Set element are identical.</li>
    *   <li><tt>1</tt>: the two Selection Set element are different.</li></ul>
    */
  virtual int Compare (const CATISelectionSetElement * iSetElement) = 0 ;

  /**
    * Compares the path of this and another path.
    * <br><b>Role</b>:
    * This method compares the initial path of this and another path.
    * @param iPathElement
    *   The path of the element to be compared with.
    * @return
    *   The status.
    *   <br><b>Legal values</b>: <ul>
    *   <li><tt>0</tt>: the two paths are identical.</li>
    *   <li><tt>1</tt>: the two paths are different.</li></ul>
    */
  virtual int Compare (const CATPathElement * iPathElement) = 0 ;


  /**
    * Returns pointed element.
    * <br><b>Role</b>: This method retrieves the element pointed by <tt>this</tt> (only if in same document).
    * @return 
    *   Error code.
    *   <br><b>Legal values</b>: <ul>
    *   <li><tt>E_FAIL</tt>: the pointed element has not been retrieved.</li>
    *   <li><tt>S_OK</tt>: the pointed element has been retrieved.</li></ul>
    */
  virtual HRESULT GetPointedElement(CATBaseUnknown* & oPointedElement) =0;
};
CATDeclareHandler (CATISelectionSetElement, CATBaseUnknown);
#endif
