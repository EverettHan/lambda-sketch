//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2013/07/04
//===================================================================
// CATAdapterAfrCtxBar.cpp
// Header definition of class CATAdapterAfrCtxBar
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2013/07/04 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATAdapterAfrCtxBar_H
#define CATAdapterAfrCtxBar_H

/**
 * @level Protected
 * @CAA2Usage U2
 */

#include "CATAfrItf.h"
#include "CATIAfrCtxBar.h"

#include "CATString.h"

class CATICAfrComponent;


/**
 * Adaptor class for the CATIAfrCtxBar interface. 
 * <b>Role:</b> This class enables you to implement the 
 *  @href CATIAfrCtxBar interface. Your implementation must derive 
 * from this class. 
*/
class ExportedByCATAfrItf CATAdapterAfrCtxBar: public CATIAfrCtxBar
{
  CATDeclareClass;

  public:
    // Standard constructors and destructors
    // -------------------------------------
    CATAdapterAfrCtxBar ();
    virtual ~CATAdapterAfrCtxBar ();

	  /**
	    * @nodoc deprecated
      */
    virtual void FillContextBar(){}

	  /**
	    * Adds commands to the context bar.
      * @param iId
      *   The ID corresponding to the trigger cliked
      * @return
      *   An HRESULT value 
	    */
    virtual HRESULT FillCtxBar(const CATString iId);//{return E_NOTIMPL;}

	
	  /**
      * Adds commands to a contextual menu.
      * @param iId
      *   The ID corresponding to the trigger clicked
      * @return
      *   An HRESULT value 
      */
    virtual HRESULT FillCtxMenu(const CATString iId){return E_NOTIMPL;}

	  /**
	    * Retrieves the context component for which you want to add commands.
	    * @param iComponentInstanceName
      *   The type of the component to retrieve
	    *   <br><b>Legal values</b>:
	    *		<ul>
	    *			<li><tt>AfrContextBarRow1</tt></li>
	    *			<li><tt>AfrContextBarRow2</tt></li>
	    *     <li><tt>AfrContextBarRow3</tt></li>
      *     <li><tt>AfrContextBarMenu</tt></li>
	    *   </ul>
	    *
	    * @param opiAfrComponent
      *   The context component [out, CATICAfrComponent#Release]
      * @return
      *   An HRESULT value 
      */
    HRESULT GetComponent( const CATString& iComponentInstanceName, CATICAfrComponent** opiAfrComponent );

    /**
	    * Set a model to fill the contextual component.
      * Used in particular cases like when a model comes from JS world
      * @param iId
      *   model used by the actor
	    */
    void SetModel(const CATUnicodeString & iModel,const CATUnicodeString & iArgument2 = CATUnicodeString("")){};

	/**
	* Callback called when an element of the contextual bar is preselected
	* @param iEmitter
	*   Object emitter of the event
	*/
	virtual void PreselectedItemEventCB(CATBaseUnknown* iEmitter){}


  private:
    // Copy constructor and equal operator
    // -----------------------------------
    CATAdapterAfrCtxBar (CATAdapterAfrCtxBar &);
    CATAdapterAfrCtxBar& operator=(CATAdapterAfrCtxBar&);

};

//-----------------------------------------------------------------------

#endif