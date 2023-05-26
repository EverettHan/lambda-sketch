// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATVidContainer.h
// Header definition of CATVidContainer
//
//===================================================================
//
//  Jun 2007  Creation: jov
//===================================================================
#ifndef CATVidContainer_H
#define CATVidContainer_H

#include <VisuDialog.h>
#include <CATVidModelWidget.h>
#include <CATSYPDeclareEnumFactory.h>
// To be able to remove #include <CATSYPEnumFactory.h> to prevent include of <nlohmann/json.hpp>
// following include is mandatory else a lot of client fws do not compile...
#include <CATBasicBoxing.h>

/**
 * @ingroup VIDCore
 */
/**
 * Base class to contain one or more widgets.
 * This is the base class of all the controls and layout.
 * It handle the life cycle of its children, depending on the property
 * #SetChildrenLifeCyclePolicy.
 */
class ExportedByVisuDialog CATVidContainer: public CATVidModelWidget
{
  CATDeclareClass;
public:
  /**
   * The way the life cycle of the children is managed.
   */
  enum ChildrenLifeCyclePolicy{
    /** 
     * The children will be destroyed at the destruction of the object, 
     * by calling RequestDelayedDestruction on them.
     */
    DestroyChildren=0, 
    /** The children will not be destroyed at the destruction of the object*/
    DontDestroyChildren
  };
  /** Constructor*/
  CATVidContainer ();
  /** Constructor.@see CATVidWidget#CATVidWidget*/
  CATVidContainer (CATCommand *i_pParent, const CATString & i_pIdentifier);
  /**
   * Update the computed minimum dimension of the object, 
   * from the minimum dimensions of its children, and call #UpdateContainer
   */
  virtual void Update();
  /**
   * Modify the children life cycle policy.
   * @param i_childrenLifeCyclePolicy the children life cycle policy.
   */
  void SetChildrenLifeCyclePolicy(CATVidContainer::ChildrenLifeCyclePolicy i_childrenLifeCyclePolicy);
  /** @return the children life cycle policy.*/
  CATVidContainer::ChildrenLifeCyclePolicy GetChildrenLifeCyclePolicy() const;
protected:
  /** Constructor*/
  CATVidContainer (CreateLetterFunc i_pCreateLetterFunc);
  /** Constructor.@see CATVidWidget#CATVidWidget*/
  CATVidContainer (CATCommand *i_pParent, const CATString & i_pIdentifier, CreateLetterFunc i_pCreateLetterFunc);
	/** Destructor*/
  virtual ~CATVidContainer ();
  /** 
   * Update dimension of the widget from a direct modification of the dimensions of a child.
   * If the dimensions of a child are updated by another way than UpdateContainer, 
   * it can involve on its widget hierarchy a grow of its dimensions.
   * @param i_pWidget the child widget what has just modified its dimension. 
   * @see CATVidLayConstraints#SetCompactFlag
   */
  void FitToChildDimension(CATVidWidget* i_pWidget);
  /** Compute dimensions and positions of the children widgets.Overloaded by inherited objects.*/
  virtual void UpdateContainer()=0;
  /**
   * Determine during #TunnelInformation if a child must recieve the information or not.
   * CATVidFatherPositionChange, CATVidConnectionChange and CATVidClippingUse 
   * are dispatched to a child when itself or one of this child has been called on #SetEmbedExternalDialogFlag(1)
   * @see CATVidWidget#SetEmbedExternalDialogFlag
   */
  int GetBroadcastToChildFlag(const CATVidWidget& i_widget, const CATVidInformation& i_information, CATVidInformation& o_updatedInformation) const;

private:
  CATVidContainer& operator=(CATVidContainer&);
  ChildrenLifeCyclePolicy _childrenLifeCyclePolicy;
  friend class l_CATVidContainer;
};
CATSYP_DECLARE_ENUMFACTORY (ExportedByVisuDialog, CATVidContainer__ChildrenLifeCyclePolicy);


//-----------------------------------------------------------------------

#endif
