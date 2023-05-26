/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2000
#ifndef _CATIActivate_h
#define _CATIActivate_h

/**
 * @level Private
 * @usage U3
 */

#include "CATBaseUnknown.h"

/**
 * Interface to activate/deactivate an element.
 * <br> The new methodology to activate/ deactivate a feature is the following:
 * <ul>
 *  <li>Use the <tt>GetItemFromFeature</tt> method of the <tt>CATxPDMSessionServices</tt> class 
 *   to retrieve the item associated with the document containing your feature</li>
 *  <li>Use the <tt>SetExternalLinksStatus</tt> method of the <tt>CATxPDMSessionServices</tt> class
 *   to modify the status of all features of the document. You could not anymore modify the 
 *    status of one feature. With this replacement method, the modification is globale 
 *    to the document.</li>
 * </ul>
 */
#include "CATInteractiveInterfaces.h"
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATInteractiveInterfaces IID IID_CATIActivate;
#else
extern "C" const IID IID_CATIActivate;
#endif
 
class ExportedByCATInteractiveInterfaces CATIActivate : public CATBaseUnknown
{
public:
  CATDeclareInterface;

  /**
   * Retrieves the break status.
   * @param oActivateStatus
   * The activate status.
   * <br><b>Legal values </b>:
   * <br>0 : the element is activated. 
   * <br>1 : the element is deactivated. 
   * <br>2 : the status is unknown. 
   */
  virtual HRESULT ActivateStatus(int* oActivateStatus) = 0;

  /**
   * Activate the element.
   */
  virtual HRESULT Activate() = 0;

   /**
   * Deactivate the element.
   */
  virtual HRESULT Deactivate() = 0;
  
};

#endif
