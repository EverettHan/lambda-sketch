/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2012

#ifndef CATAdpProtectedComponentsAssociationIterator_H
#define CATAdpProtectedComponentsAssociationIterator_H

/**
 * @level Protected
 * @usage U1
 */

#include "CATPLMIntegrationAccess.h"
#include "CATSysErrorDef.h"
class CATAdpComponentsAssociationImpl;
class CATIAdpPLMIdentificator;
class CATPLMIDMapAdpIter;
/*-----------------------------------------------------------------------
 * Class defining an iterator on an association of components.
 * <br><b>Role</b> : Provides a way to iterate on every association of components.
 */
class ExportedByCATPLMIntegrationAccess CATAdpProtectedComponentsAssociationIterator
{
    CATPLMIDMapAdpIter *_pMapIter;
public:


/**
* Copy constructor.
*/
CATAdpProtectedComponentsAssociationIterator (const CATAdpProtectedComponentsAssociationIterator &);
/**
* Copy constructor.
*/
CATAdpProtectedComponentsAssociationIterator& operator=(const CATAdpProtectedComponentsAssociationIterator&);

virtual ~CATAdpProtectedComponentsAssociationIterator ();

/**
* Retrieves the component associated to another component.
* <br><b>Role</b>: Get the pair of components as @href CATIAdpPLMIdentificator from operations making derived components (eg. duplicate...)
* @param oSource
* The key, the component which the association is based upon.
* @param oRelated
* The related component, the component associated which is derived from the source.
* @return
* <dl>
* <dt><code>S_OK</code> This iteration is ok.<dd>
* <dt><code>S_FALSE</code> There isn't any more element, iteration is now finished.<dd>
* <dt><code>E_FAIL</code> An error was encountered. Nothing was done during the operation.<dd>
* </dl>
*/
HRESULT NextComponent(CATIAdpPLMIdentificator *& oSource, CATIAdpPLMIdentificator *& oRelated) ;

private:
friend class CATAdpProtectedComponentsAssociation;
/**
* @nodoc
*/
CATAdpProtectedComponentsAssociationIterator (CATAdpComponentsAssociationImpl *ipCollecImpl);


};

//-----------------------------------------------------------------------

#endif
