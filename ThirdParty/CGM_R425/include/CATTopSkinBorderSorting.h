#ifndef CATTopSkinBorderSorting_H
#define CATTopSkinBorderSorting_H

// COPYRIGHT DASSAULT SYSTEMES  2004

#include "BODYNOPE.h"
#include "CATTopOperator.h"
#include "ListPOfCATEdge.h"


//

/**
 * Class defining the operator that computes the list of edges bording a smooth skin.
 *<br>
 * The CATTopSkinBorderSorting follows the global frame of the topological operators and satisfies the smart mechanism: 
 * the input bodies are not modified. A new resulting body is created, 
 * possibly sharing data with the input bodies.
 *<ul>
 * <li>A CATTopSmoothSkinBorderComputer is created with the <tt>CATCreateSmoothSkinBorderComputer</tt> global method:
 * It must be directly <tt>delete</tt>d after use. It is not streamable. 
 *<li>The result is accessed with the <tt>GetResultListEdges</tt> method. 
 *</ul>
 */

class ExportedByBODYNOPE CATTopSkinBorderSorting : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopSkinBorderSorting);
protected:
  /**
* @nodoc
* Constructor - not to be used
*/
	CATTopSkinBorderSorting    (CATGeoFactory* iContainer, CATTopData* iData);

public :
	virtual              ~CATTopSkinBorderSorting();
/**
* @nodoc
*/
 // CATCGMNewClassArrayDeclare;
  
/**
* Runs the operator
*/
  virtual int Run() = 0;
  
/**
* Returns the list of cells .
*/
  virtual void GetResultListEdges(CATLISTP(CATEdge) & oListEdges) = 0;

   /**
* 
*/
  virtual CATBoolean IsBoundaryOrderStable() = 0;
};

#endif
