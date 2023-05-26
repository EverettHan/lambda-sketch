#ifndef CATImplicitBodyQuery_H
#define CATImplicitBodyQuery_H

#include "GMScalarFieldsOperators.h"

#include "CATBoolean.h"
#include "CATUnicodeString.h"

// CGM


// Scalar Fields
#include "SFTypes.h"

// GMScalarFieldsObjects
#include "CATImplicitResource.h"
#include "ListPOfCATImplicitVolume.h"
#include "ListPOfCATGeoImplicitSurface.h"
#include "CATImplicitExpressionQuery.h"

// CGM
class CATBody;
class CATICGMObject;
class CATGeoImplicitSurface;

/**
 * CATImplicitBodyQuery provides services to get information back from a partitioned
 * body with volume that might have associated implicit specification. 
 * For example it allows you to get back lists of volumes of the partitioned body to which
 * CATGeoImplicitSurfaces have been associated.
 */
class ExportedByGMScalarFieldsOperators CATImplicitBodyQuery
{

public:
  /**
   * ctor
   *
   * Need to pass a pointer to the body that you want to introspect. CATImplicitBodyQuery doesn't make
   * any attempt at managing the LF of the specified body instead it assumes from the caller that the body
   * will remain valid while this instance of CATImplicitBodyQuery remains valid and in use.
   *
   * @param[in] iBody, a pointer to a valid (partitioned) body. CATImplicitBodyQuery makes no attempts at
   *  managing it's LF.
   *
   */
  CATImplicitBodyQuery(CATBody* iBody);

  /**
   * dtor
   */
  virtual ~CATImplicitBodyQuery();

  /**
   * GetAssociations will return a list of volumes along with the list of associated implicit surfaces (volume at index idx associated
   * with surface at index idx). As an implicit surface can be associated with several volumes of the partitioned body you might found the same implicit surface
   * several time in oSurfaces.
   *
   * @param[out] oVolumes, list of volumes that are associated with CATGeoImplicitSurface(s)
   * @param[out] oSurfaces, list of surfaces associated with volumes in oVolumes. oVolumes[i] is associated
   *  with oSurfaces[i] with i in [1..oVolumes.Size()], as a CATGeoImplicitSurface might be associated 
   *  to several volumes you might encounter the same CATGeoImplicitSurface several time in oSurfaces.
   *
   * @return S_OK if everything went all right.
   */
  HRESULT GetAssociations(ListPOfCATImplicitVolume& oVolumes, ListPOfCATGeoImplicitSurface& oSurfaces);

  /**
   * GetLightExpressionQuery will return an expression query that let you introspect the DAG but not the resourceToSF nodes,
   * it is equivalent to calling GetExpressionQuery(nullptr, iImplicitSurface, CATImplicitExpressionQuery::State::unresolvedRef),
   * if you are only interested in the Graph structure this is the way to go as it is much lighter than requiring the resolution
   * of the resource to the resolver.
   */
  CATImplicitExpressionQuery::Ptr GetLightExpressionQuery(CATGeoImplicitSurface* iImplicitSurface);

  /**
   * GetExpression will return a pointer a CATImplicitExpressionQuery object which allow you to navigate the expression
   * Direct Acyclic Graph. You can specify if you want to have all dependencies and resources of the DAG to be fully resolved or if you
   * are fine with a having those nodes in unresolved state. 
   *
   * If you want to just get the expression structure, to inspect node types, get expressionIds and any usage that don't require that 
   * you retrieve the pointers to CGM objects dependencies or resources, you should call this method with 
   * iDesiredState = CATImplicitExpressionQuery::State::unresolvedRef as it will be much quicker. 
   *
   * But if you want to retrieve pointers to the associated CGM objects or pointers to resources you will have
   * to ask for a fully resolved CATImplicitExpressionQuery. In thy case you should pass:
   * iDesiredState = CATImplicitExpressionQuery::State::fullyResolved
   *
   * @param[in] iImplicitSurface, the implicit surface for which you want to get a CATImplicitExpressionQuery that will let
   *  you query information related to the implicit DAG in the context of that CATGeoImplicitSurface.
   * @param[in] iDesiredState, see discussion above, leaving DAG nodes associated with dependencies and resource in an unresolved
   *  state is better if you don't need to access the pointers of the CGM object dependencies and of the resources because 
   *  it doesn't make the effort to resolve this and for some of them it might be costly as for some of them at least
   *  associated signed distance fields for those dependencies and resources are going to be built when you resolve them. 
   *
   * @return S_OK if everything went all right.
   */
  CATImplicitExpressionQuery::Ptr GetExpressionQuery(CATSoftwareConfiguration* iSWConfig, CATGeoImplicitSurface* iImplicitSurface, const CATImplicitExpressionQuery::State iDesiredState);


private:
  CATBody*  _body;
};

#endif // CATImplicitBodyQuery_H
