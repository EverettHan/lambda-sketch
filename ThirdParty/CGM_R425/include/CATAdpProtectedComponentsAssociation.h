/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2012

#ifndef CATAdpProtectedComponentsAssociation_H
#define CATAdpProtectedComponentsAssociation_H

/**
 * @level Protected
 * @usage U1
 */

#include "CATPLMIntegrationAccess.h"
#include "CATAdpProtectedComponentsAssociationIterator.h"
#include "CATBaseUnknown.h"
class CATIAdpPLMIdentificator;
class CATAdpComponentsAssociationImpl;
class CATPLMID;

/*-----------------------------------------------------------------------
 * Class defining a component association collection.
 *<br><b>Role</b> : Provides a way to associate two components : the source and the one related to the source, related by any kind of operation.
 *                  This object is a collection, it can hold multiple associations.
 */
class ExportedByCATPLMIntegrationAccess CATAdpProtectedComponentsAssociation
{
public:

/**
* Empty constructor.
*/
CATAdpProtectedComponentsAssociation ();

/**
* Copy constructor.
*/
CATAdpProtectedComponentsAssociation (const CATAdpProtectedComponentsAssociation &);
/**
* Assignment operator.
*/

CATAdpProtectedComponentsAssociation& operator=(const CATAdpProtectedComponentsAssociation&);

virtual ~CATAdpProtectedComponentsAssociation ();

/**
* Get the associated element from a source component.
* <br><b>Role</b>: Get element associated to the source AdpId. The related component may have been created by various operations.
*                  See operation used for more details on the kind of related component.
* @param iSource
* Element from with searching the association.
* @param oRelated
* Element found, associated to the input.
* @return
* <dl>
* <dt><code>S_OK</code> Element found and returned.<dd>
* <dt><code>S_FALSE</code> Element not found.<dd>
* <dt><code>E_FAIL</code> Error encountered. Nothing was done during the operation.<dd>
* <dt><code>E_UNEXPECTED</code> Error encountered. Nothing was done during the operation.<dd>
* </dl>
*/
HRESULT GetAssociated(CATIAdpPLMIdentificator *iSource, CATIAdpPLMIdentificator *& oRelated) ;
HRESULT GetAssociated(const CATPLMID & iSource, CATPLMID & oRelated) ;


/**
* Get the total number of elements in this collection.
* @return
* Number of elements.
*/
unsigned int Size() const;


/**
* Get an iterator on every elements
* <br><b>Role</b>: The iterator is used to iterate through every components.
* @return
* Iterator on this collection. 
* @see CATAdpProtectedComponentsAssociationIterator
*/
CATAdpProtectedComponentsAssociationIterator GetIterator();

protected:

CATAdpComponentsAssociationImpl *_pImpl;

};

//-----------------------------------------------------------------------

#endif
