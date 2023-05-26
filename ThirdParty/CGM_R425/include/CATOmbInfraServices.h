#ifndef CATOmbInfraServices_H
#define CATOmbInfraServices_H

/**
 * @level Private
 * @usage U1
 */

#include "CATInterfaceDeclarations.h"

/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2003

#include "ExportedByAC0XXLNKForInfraOnly.h"

class CATBaseUnknown;
class CATDocument;
class CATILinkableObject;

/**   
 * Object modeler base internal service. 
 * <b>Role</b>: This session service provides helper methods used internally by ObjectModelerBase.<br>
 * These methods are not exported, they are accessible only to the source included in CATObjectModelerBase.<br>
 */

class ExportedByAC0XXLNKForInfraOnly CATOmbInfraServices
{

public:

  /**
  * Retrieves the document corresponding to a container component.
  * <br><b>Role:</b>This service enables navigation from a container to its document without
  * using a CATILinkableObject interface, which is forbidden within cluster documents.
  *
  * @param ipContainer
  *		A non-null pointer to the container component, seen through any of its interfaces
  * @param opDocument
  *		The retrieved document for this container, if successful
  **/
  static HRESULT RetrieveDocFromContainer( const CATBaseUnknown *ipContainer, CATDocument* &opDocument );


  /**
  * Retrieves the document corresponding to a given linkable.
  * <br><b>Role:</b>This service replaces CATILinkableObject::GetDocument().<br>
  * In a TP (cluster) context, it exposes the underlying documents.<br>
  * It can be used only in infrastructure frameworks.
  *
  * @param ipLinkable
  *		A non-null pointer a CATILinkableObject
  * @param opDocument
  *		The retrieved document for this linkable, if successful
  **/

  static HRESULT RetrieveDocumentFromLinkable( const CATILinkableObject *ipLinkable, CATDocument* &opDocument );

};


#endif
