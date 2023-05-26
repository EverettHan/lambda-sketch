// COPYRIGHT Dassault Systemes 2007
//======================================================================

#ifndef CATOmbNavigationTools_H
#define CATOmbNavigationTools_H

/**
* @level Private
* @usage U3
*/

// List of authorized infrastructure modules 

#define AuthorizedModule              999
#define CATOmbLinkApplicativeAccess   AuthorizedModule
#define CATOmbLinkNavigationAccess    AuthorizedModule
#define CATOmbRelationIntegrity       AuthorizedModule
#define CATPLMStreamDescriptor        AuthorizedModule
#define CATOmbTestLib_PLM             AuthorizedModule
#define CATPLMClientCoreModel         AuthorizedModule
#define CATOmbLinks                   AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden Access To CATIOmbNavigationTools
#endif

#undef AuthorizedModule
#undef CATOmbLinkApplicativeAccess
#undef CATOmbLinkNavigationAccess
#undef CATOmbRelationIntegrity
#undef CATPLMStreamDescriptor
#undef CATOmbTestLib_PLM
#undef CATPLMClientCoreModel
#undef CATOmbLinks

#include "CATObjectModelerBase.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"


class CATOmbRelationSnapshotIterator;
class CATOmbRelationSnapshotSpecificationIterator;
class CATOmbRelationSnapshot;
class CATOmbRelationSnapshotSpecification;
class CATOmbRelationsFilter;
class CATOmbLinkInterface;
class CATISpecAttrAccess_var;
class CATISpecAttrKey_var;
class CATISpecAttrAccess;
class CATISpecAttrKey;
class CATIPLMComponent;
class CATUnicodeString;
class CATOmbLink;

/**
* @nodoc
* For CATOmbLinkNavigationAccess internal use only.
*/
class ExportedByCATObjectModelerBase CATOmbNavigationTools
{
public:
  static CATOmbRelationSnapshotIterator * GetRelationsSnapshot(CATBaseUnknown * ipiCBU, CATOmbRelationsFilter * ipRelationsFilter);
  static CATOmbRelationSnapshotIterator * GetRelationsSnapshotForPathName(CATBaseUnknown * ipiCBU, const CATUnicodeString& iPathName);

  static CATOmbRelationSnapshotIterator * GetInverseRelationsSnapshot(CATBaseUnknown * ipiCBU, CATOmbRelationsFilter * ipRelationsFilter);

  static CATOmbRelationSnapshotSpecificationIterator * GetRelationSnapshotSpecifications(CATBaseUnknown * ipiCBU, CATOmbRelationsFilter * ipRelationsFilter);

  static CATOmbRelationSnapshotSpecificationIterator * GetRelationSnapshotSpecifications(CATOmbRelationSnapshotSpecificationIterator & iIterator, CATOmbRelationSnapshotIterator & iRelationSnapshots);

  static CATOmbRelationSnapshotSpecification * GetRelationSnapshotSpecification(CATOmbRelationSnapshotSpecificationIterator & iIterator, CATOmbRelationSnapshot & iRelationSnapshot);

  static HRESULT GetRelationSnapshot(const CATOmbLink &, CATOmbRelationSnapshot * &);

  static CATOmbRelationSnapshotIterator * CreateSnapshotIterator(CATOmbRelationSnapshot & iRelationSnapshot);

private:

  static HRESULT GetRelationSnapshot(const CATOmbLinkInterface &, CATOmbRelationSnapshot * &);
};

#endif
