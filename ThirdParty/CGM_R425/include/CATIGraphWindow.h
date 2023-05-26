//===================================================================
// COPYRIGHT Dassault Systemes 2007
//===================================================================

/** 
  * @CAA2Level L1
  * @CAA2Usage U3
  */ 

#ifndef CATIGraphWindow_H
#define CATIGraphWindow_H

#include "CATInteractiveInterfaces.h"
#include "CATBaseUnknown.h"

class CATPathElement;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATInteractiveInterfaces IID IID_CATIGraphWindow;
#else
extern "C" const IID IID_CATIGraphWindow ;
#endif


/** 
 * Enumerates the different level of Graph expansion.
 * <b>Role</b>: It is used in functions provided by this interface.
 * @param CATGraphLevel_All
 * Use this enum to expand all level.
 * @param CATGraphLevel_1
 * Use this enum to collapse all level.
 * @param CATGraphLevel_2
 * Use this enum to expand first level.
 * @param CATGraphLevel_3
 * Use this enum to expand second level.
 */
enum CATGraphLevel {CATGraphLevel_All, CATGraphLevel_1, CATGraphLevel_2, CATGraphLevel_3};

/** 
 * Enumerates the visibility of Graph.
 * <b>Role</b>: It is used in functions provided by this interface.
 * @param CATGraphWindow_Show
 * Use this enum to show the Graph.
 * @param CATGraphWindow_Hide
 * Use this enum to hide the Graph.
 */
enum CATGraphVisibility {CATGraphWindow_Show, CATGraphWindow_Hide};

//------------------------------------------------------------------

/**
 * Interface to manage the graph.
 * <b>Role</b>:
 * This interface gives an access to a graph.
 * <br>It provides the basic methods to manage the graph
 */
class ExportedByCATInteractiveInterfaces CATIGraphWindow: public CATBaseUnknown
{
   CATDeclareInterface;

   public:

    /**
     * Changes the root path.
     * Deletes the current root then adds the new root.
     * @param iRootPath
     *    New root.
     */
     virtual HRESULT ChangeRoot (CATPathElement * iRootPath) = 0;

    /**
     * Expands the graph node.
     * @param iNodePath
     *    Graph node to expand.
     * @param iLevel
     *    Graph expansion level.
     *    <br><b> Legal values</b>:
     *    <li><tt>CATGraphLevel_All</tt> to expand all level</li>
     *    <li><tt>CATGraphLevel_1</tt> to collapse all level</li>
     *    <li><tt>CATGraphLevel_2</tt> to expand first level</li>
     *    <li><tt>CATGraphLevel_3</tt> to expand second level</li>
     */
     virtual HRESULT Expand(CATPathElement * iNodePath, CATGraphLevel iLevel = CATGraphLevel_1) = 0;

    /**
     * Collapses the graph node.
     * @param iNodePath
     *    Graph node to collapse.
     */
     virtual HRESULT Collapse(CATPathElement * iNodePath) = 0;

    /**
     * Shows/Hides the graph.
     * @param iVisibility
     *    Graph visibility.
     *    <br><b> Legal values</b>:
     *    <li><tt>CATGraphWindow_Show</tt> graph is visible</li>
     *    <li><tt>CATGraphWindow_Hide</tt> graph is not visible</li>
     */
     virtual HRESULT SetGraphVisibility(CATGraphVisibility iVisibility) = 0;

    /**
     * Returns the Show/Hide status of graph.
     * @param oVisibility
     *    Graph visibility.
     *    <br><b> Legal values</b>:
     *    <li><tt>CATGraphWindow_Show</tt> graph is visible</li>
     *    <li><tt>CATGraphWindow_Hide</tt> graph is not visible</li>
     */
     virtual HRESULT SetGraphVisibility(CATGraphVisibility & oVisibility) = 0;

  // --------------------------------------------------------------
};

#endif
