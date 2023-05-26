// COPYRIGHT Dassault Systemes 2000
//===================================================================
//
// CATTypeDictionaryListenerAdapter.h
// Provide implementation to interface
//    CATITypeDictionaryListener
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//CAA2 Wizard Generation Report
//   IMPLEMENTATION
//   TIE: CATITypeDictionaryListener
//End CAA2 Wizard Generation Report
//
//  Jul 2000  Creation: Code generated by the CAA wizard  FCV
//===================================================================
#ifndef CATTypeDictionaryListenerAdapter_H
#define CATTypeDictionaryListenerAdapter_H

#include "CATLifSpecs.h"
#include "CATBaseUnknown.h"
#include "CATIType.h"
#include "CATIInstance.h"

//-----------------------------------------------------------------------

/**
 * Class Object modeler implementation class.
 * <br>
 * It implements the interfaces :
 *  <ol>
 *  <li>@see KnowledgeInterfaces.CATITypeDictionaryListener
 *  </ol>
 * Using this prefered syntax will enable mkdoc to document your class.
 */
class ExportedByCATLifSpecs CATTypeDictionaryListenerAdapter: public CATBaseUnknown
{
  CATDeclareClass;

  public:

  // Standard constructors and destructors for an implementation class
  // -----------------------------------------------------------------
     CATTypeDictionaryListenerAdapter ();
     virtual ~CATTypeDictionaryListenerAdapter ();

    /**
     * Implements a function from an interface.
     * @see KnowledgeInterfaces.CATITypeDictionaryListener#Instanciated
     */
     virtual HRESULT Instanciated( const CATIType_var & iType , const CATIInstance_var & iInstance );

    /**
     * Implements a function from an interface.
     * @see KnowledgeInterfaces.CATITypeDictionaryListener#TypeAdded
     */
     virtual HRESULT TypeAdded( const CATIType_var & iType );

    /**
     * Implements a function from an interface.
     * @see KnowledgeInterfaces.CATITypeDictionaryListener#TypeUpdated
     */
		 virtual HRESULT TypeUpdated(const CATIType_var & iType );

	 /**
     * Implements a function from an interface.
     * @see KnowledgeInterfaces.CATITypeDictionaryListener#TypeRemoved
     */
     virtual HRESULT TypeRemoved( const CATIType_var & iType );

	 /**
     * Implements a function from an interface.
     * @see KnowledgeInterfaces.CATITypeDictionaryListener#MethodAdded
	 */
	 virtual HRESULT MethodAdded( const CATBaseUnknown_var &iMethod );
	 
	 /**
     * Implements a function from an interface.
     * @see KnowledgeInterfaces.CATITypeDictionaryListener#MethodRemoved
	 */
	 virtual HRESULT MethodRemoved( const CATBaseUnknown_var &iMethod );
	 
	 /**
     * Implements a function from an interface.
     * @see KnowledgeInterfaces.CATITypeDictionaryListener#MustBeSynchronized
     */
     virtual HRESULT MustBeSynchronized();
	 
	 
  private:
	  // The copy constructor and the equal operator must not be implemented
	  // -------------------------------------------------------------------
	  CATTypeDictionaryListenerAdapter (CATTypeDictionaryListenerAdapter &);
	  CATTypeDictionaryListenerAdapter& operator=(CATTypeDictionaryListenerAdapter&);
	  
};

//-----------------------------------------------------------------------

#endif
