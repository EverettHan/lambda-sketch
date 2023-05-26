// COPYRIGHT Dassault Systemes 2009

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */

//===================================================================
//
// CATEAfrContainerViewFactory.h
// Header definition of CATEAfrContainerViewFactory
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jul 2009  Creation: Code generated by the CAA wizard  LD3
//===================================================================
#ifndef CATEAfrContainerViewFactory_H
#define CATEAfrContainerViewFactory_H

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

//-----------------------------------------------------------------------

class CATAfrContainerView;

/**
* Adapter class to instantiate a CATAfrContainerView object.
* Use this adapter to implement @href CATIAfrContainerViewFactory interface.
* @See CATIAfrContainerViewFactory
*/
class ExportedByCATAfrItf CATEAfrContainerViewFactory: public CATBaseUnknown
{
  CATDeclareClass;

  public:

  // Standard constructors and destructors
  // -------------------------------------
     CATEAfrContainerViewFactory ();
     virtual ~CATEAfrContainerViewFactory ();

  //factory method
  //--------------------------------------

    /**
     *   Creates the container View instance. Example 
     *   <code>
     *   return new MyContainerViewProduct();
     *   </code>
     *   @return
     *      An instance of CATAfrContainerView.
     * 
     */
     virtual CATAfrContainerView * CreateInstanceContainerView(CATBaseUnknown *ipModel); 


    /**
     *   Creates the container View instance. Example 
     *   <code>
     *   return new MyContainerViewProduct();
     *   </code>
     *   @return
     *      An instance of CATAfrContainerView.
     * 
     */
     virtual CATAfrContainerView * CreateInstanceSYPContainerView(CATBaseUnknown *ipModel, const CATUnicodeString & iTemplate, CATBoolean iCreateDialogBox, CATBoolean iHasChilds); 
};

//-----------------------------------------------------------------------

#endif
