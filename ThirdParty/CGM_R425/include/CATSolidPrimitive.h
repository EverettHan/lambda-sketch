#ifndef SolidPrimitive_h
#define SolidPrimitive_h

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * @level Protected
 * @usage U1
 */ 

#include "PrimitivesLight.h"
#include "CATTopOperator.h"

class CATBody;
class CATGeoFactory;
class CATTopData;

class CATCGMJournalList;

#ifndef NULL
#define NULL 0
#endif

/**
 * Base class for the operators that create basic topological primitives.
 * <br>Use the derived class <tt>CATSolidXxx</tt> to create the basic topological primitive <tt>Xxx</tt>.
 * <br><tt>CATSolidXxx</tt> follows the global frame of the topological operators.
 *<ul>
 * <li>Create it with the <tt>CATCreateSolidXxx</tt> global function 
 * <li>Run it 
 * <li>Get the result
 * <li>Delete with the usual C++ <tt>delete</tt> operator after use.
 *</ul>
 */
class ExportedByPrimitivesLight CATSolidPrimitive : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATSolidPrimitive);
public:

  /** @nodoc */
  CATSolidPrimitive(CATGeoFactory*, CATTopData*);

  /** @nodoc */
  CATSolidPrimitive(CATGeoFactory*,CATCGMJournalList *report=NULL);

  virtual ~CATSolidPrimitive();

  /** @nodoc */
  operator           CATBody * ();

	/**
	 * Returns a pointer to the factory of the geometry used in <tt>this</tt> operator.
	 * @return
	 * The pointer to the factory.
	 */
  CATGeoFactory *    GetFactory();

	/**
	 * Returns a pointer to the resulting body created by <tt>this</tt> operator.
	 * @return
	 * The pointer to the body. If you do not want to keep it, use the @href CATICGMContainer#Remove method
	 *  to remove it from the container after the deletion of the operator. 
	 */
  CATBody       *    GetResult();
  
  /**
   * Returns the pointer to the journal.
	 * @return 
	 * The pointer to the journal.
	 */
  CATCGMJournalList * GetReport ();
  
protected:
     /** @nodoc */
  CATGeoFactory    * _factory;
     /** @nodoc */
  CATBody          * _body;
     /** @nodoc */
  CATCGMJournalList * _report;   
};


#endif
