#ifndef __CATICafTopologySearch_h__
#define __CATICafTopologySearch_h__

// COPYRIGHT DASSAULT SYSTEMES 2005

#include "CATBaseUnknown.h"
#include "UIModelInterfaces.h"

class CATListValCATBaseUnknown_var;
class CATString;


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByUIModelInterfaces IID IID_CATICafTopologySearch;
#else
extern "C" const IID IID_CATICafTopologySearch;
#endif

class ExportedByUIModelInterfaces CATICafTopologySearch : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
   *   Retrieves topological cells from a list of features.
   *   <br><b>Role:</b><br>Retrieves the cells, eventually of a specific dimension, of the topological
   *   bodies associated to a given list of (geometrical) features. 
   *   @param iSelectedElements
   *   List of features for which the topological cells are retrieved.
   *   @param iSearchType
   *   Indicates the type of the topological cells that have to be retrieved.
   *   <b>Legal values:</b><br>
   *   <dl><dt><tt>CGMFace</tt></dt><dd>Faces associated to solid, volume and surface features</dd>
   *   <dt><tt>CGMEdge</tt></dt><dd>Edges associated to solid, volume, surface and wireframe features</dd>
   *   <dt><tt>CGMVertex</tt></dt><dd>Vertices associated to solid, volume, surface, wireframe and point features</dd>
   *   <dt><tt>void</tt></dt><dd>All cells, i.e. combination of the three preceding types</dd>
   *   @param ioBRepResults
   *   List of elements referencing the resulting cells. The path-element of these elements can be
   *   generated using CATIPathAccess interface.
   *   @return 
   *   <b>Legal values:</b><br>
   *   <dl><dt><tt>S_OK</tt></dt><dd>The topological results have been scanned and the list ioBRepResults is filled.</dd>
   *   <dt><tt>E_FAIL</tt></dt><dd>The list iSelectedElements contains unexpected elemnts or
   *   the method has unexpectedly failed.</dd></dl>
   */

   virtual HRESULT Search(const CATListValCATBaseUnknown_var& iSelectedElements,
                          const CATString&                    iSearchType,
                          CATListValCATBaseUnknown_var&       ioBRepResults) = 0;

};

CATDeclareHandler(CATICafTopologySearch, CATBaseUnknown);

#endif
