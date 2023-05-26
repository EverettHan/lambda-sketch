// COPYRIGHT DASSAULT SYSTEMES 2005, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMeshComponentOper.h
//
//===================================================================
// September 2005  Creation: NDO
//===================================================================
#ifndef CATPolyMeshComponentOper_H   
#define CATPolyMeshComponentOper_H   

#include "CATPolyAnalyzeOper.h"
#include "CATPolyAnalyzeOperators.h"

class CATPolyAttributeDomains;


/**
 * This operator decomposes a mesh into connected components.
 * This class  is deprecated. Used instead CATPolySurfaceContiguousFacetExtractor.
 *
 * @see CATPolySurfaceContiguousFacetExtractor
 */
class ExportedByCATPolyAnalyzeOperators CATPolyMeshComponentOper : public CATPolyAnalyzeOper
{

public :

  /**
   * Constructor.
   */
  CATPolyMeshComponentOper () {_Domains = 0;}

  /**
   * Destructor.
   */
  virtual ~CATPolyMeshComponentOper () {_Domains = 0;}

public:

  /**
   * Sets the domains to be calculated by the operator.
   * The triangles from a domain are part of the same connected component.
   * The domains must be set prior to running this operator.
   */
  inline void SetDomains (CATPolyAttributeDomains* iDomains) {_Domains = iDomains;}

  /**
   * Decomposes the mesh into list of connected components.  Calculates the domains.
   */
  HRESULT Run ();

private :

  CATPolyAttributeDomains* _Domains;

};

#endif
