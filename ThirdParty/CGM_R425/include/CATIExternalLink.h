/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2000
#ifndef _CATIExternalLink_h
#define _CATIExternalLink_h

/**
 * @level Private
 * @usage U3
 */

#include "CATBaseUnknown.h"

/**
 * Interface to describe a external link.
 * <b>Role</b>: A external link is a model link between two elements
 *              which are in different documents.
 */
#include "AC0XXLNK.h"
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByAC0XXLNK IID IID_CATIExternalLink;
#else
extern "C" const IID IID_CATIExternalLink;
#endif

class CATUnicodeString;
class _SEQUENCE_octet;

class ExportedByAC0XXLNK CATIExternalLink : public CATBaseUnknown
{ 
public:
  CATDeclareInterface;

  /**
  * Retrieves the owner of the link.
  * @param oOwner [out, CATBaseUnknown#Release]
  * The owner of the link.  
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT GetOwner(CATBaseUnknown** oOwner) = 0;

  /**
  * Retrieves the type of link.
  * @param oType
  * The type of the link.  
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT GetType(CATUnicodeString& oType) = 0;

  /**
  * Retrieves the pointing element.
  * @param oPointingElement [out, CATBaseUnknown#Release]
  * The pointing element.
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT GetPointingElement(CATBaseUnknown** oPointingElement) = 0;

  /**
  * Retrieves the pointed element.
  * @param oPointedElement [out, CATBaseUnknown#Release]
  * The pointed element (for instance, a feature or a document).
  * @param iLoad
  * if iLoad is valued to 1, the pointed document
  * must be loaded in order to be sure to retrieve
  * the pointedElement. In this case, use the CATFlavorParam::ANYWHERE argument
  * to solve your link.
  * if iLoad is valued to 0, the element must be returned only 
  * if the pointed document is loaded. Do not load the pointed document 
  * in that case. For this, use the CATFlavorParam::IN_SESSION argument
  * to solve your link.
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT GetPointedElement(CATBaseUnknown** oPointedElement,  const int iForceLoad=0) = 0;

  /**
  * Retrieves the pointing attribute.
  * @param oPointingAttribute
  * The pointing attribute.  
  * An element can point another one with two different pointing attributes.
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT GetPointingAttribute(CATUnicodeString& oPointingAttribute) = 0;

  /**
  * Retrieves the associated sequence of octet.
  * @param oModelLink
  * The sequence of octet which corresponds to the link in the model.  
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT GetModelLink(_SEQUENCE_octet& oModelLink) = 0;

  /**
   * Retrieves the visu status.
   * @param oVisuStatus
   * The visu status.
   * <br><b>Legal values </b>:
   * <br>0 : the link is hidden to the user.
   * <br>1 : the link is displayed to the user.
   * @return
   * The status call
   * <br><b>Legal values</b>: S_OK, E_FAIL
   */
  virtual HRESULT VisuStatus(int& oDisplayed) = 0;

  /**
   * Retrieves the relay link (advanced use).
   * @param oRelayLink [out, CATBaseUnknown#Release]
   * The relay link.
   * A user link (one selection) can be modelized by two external
   * links that merged. For instance, a link (link 1) from document A to document B
   * and a second one (link 2) from document B to document C. Link 2 is the relay 
   * link of link 1.
   * @return
   * The status call
   * <br><b>Legal values</b>: S_OK, E_FAIL
   */
  virtual HRESULT GetRelayLink(CATIExternalLink** oRelayLink) = 0;
  
};

#endif      

