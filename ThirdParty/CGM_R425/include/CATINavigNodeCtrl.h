/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATINavigNodeCtrl_h
#define CATINavigNodeCtrl_h

// COPYRIGHT DASSAULT SYSTEMES  2000

/**
 * @CAA2Level L1
 * @CAA2Usage U4 CATNodeExtension
 */

#include "CATBaseUnknown.h"
#include "CATOmnMain.h"

extern ExportedByCATOmnMain IID IID_CATINavigNodeCtrl;

class CATNavigInstance;

/**
 * Interface to manage tree node expansion.
 * <b>Role:</b> This interface enables you to override the default expansion behaviour.<br>
 * <p><b>BOA information</b>: this interface CANNOT be implemented
 * using the BOA (Basic Object Adapter).
 * To know more about the BOA, refer to the CAA Encyclopedia home page.
 * Click Middleware at the bottom left, then click the Object Modeler tab page.
 * Several articles deal with the BOA.</p>
 */

class ExportedByCATOmnMain CATINavigNodeCtrl: public CATBaseUnknown
{
  CATDeclareInterface;
public:
  // Gestion du deferencement

  /**
   * Looks for children and creates child nodes and expands them if necessary.
   * @param iDepth
   *   The depth until which expands the graph.
   */
  virtual void Dereference(int iDepth)=0;

  /**
   * Collapses the node.
   */
  virtual void Undereference()=0;
  
  // Gestion de l'instance associee

  /**
   * @nodoc 
   */
  virtual void PutAssociatedInstance(CATNavigInstance* inst)=0;

  /**
   * Mode of expansion of a node.
   * @param NotExpandable
   *   Children are never looked for. There's no activator (+)/(-) shown on the left of the node.
   * @param Expandable
   *   Children are not looked for as long as the node is collapsed.
   *   The activator (+) is shown on the left of the node. Once the node is expanded, the node is treated like with <tt>ExpandableIfWithChild</tt>.
   * @param ExpandableIfWithChild
   *   The children are looked for.<ul>
   *   <li>If no child has been found, no activator is shown.</li>
   *   <li>If at least one child has been found, an activator (+) is shown if the node is collapsed,
   *   and an activator (-) is shown if the node is expanded.</li></ul>
   */
  enum ExpansionMode {NotExpandable, Expandable, ExpandableIfWithChild};
  
  /**
   * Gets the expansion mode.<br>
   * The expansion mode is taken into account by @href #Dereference .
   * @param oExpansionMode
   *   The expansion mode.
   */
  virtual void GetExpansionMode(CATINavigNodeCtrl::ExpansionMode &oExpansionMode) const = 0;
};

// Declaration du handler

CATDeclareHandler (CATINavigNodeCtrl, CATBaseUnknown);

#endif
