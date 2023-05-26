// ===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2000
// ===================================================================
// Nov.  2004. Documentation                                 ppb
// ===================================================================

/**
  @level Protected
  @usage U3
  */

/* -*-c++-*- */
#ifndef _CATIReorderList_h
#define _CATIReorderList_h

#include "CATBaseUnknown.h"

/**
 * Interface to move an object to a given position in the Graph.
 * <b>Role</b>: Works with CATINavigateObject interface.
 *              
 */
#include "UIModelInterfaces.h"

class CATUnicodeString;
class CATBaseUnknown_var;
class CATListValCATBaseUnknown_var;
class CATListValCATUnicodeString;

class ExportedByUIModelInterfaces CATIReorderList : public CATBaseUnknown
{ 
public:
 /**
  * Asks if an element can be moved in the Graph.
  *
  * @param oToMove
  * The element to move (this element is a member retrieved by CATINavigateObject->GetChildren).
  * @param iPosition
  * The position in the list where to move the element.
  * @param oWhyMoveImpossible
  * Explain here why move is impossible.
  * @param ioListToReorder
  * The list to reorder.
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK if move is possible, E_FAIL otherwise
  */
  virtual HRESULT CanMoveToPosition(const int iOldPosition,
                                    const int NewPosition,
                                    const CATListValCATBaseUnknown_var& ioListToReorder,
                                    CATUnicodeString& oWhyMoveImpossible) = 0;

 /**
  * Asks if an element can be moved in the Graph.
  *
  * @param oToMove
  * The element to move (this element is a member retrieved by CATINavigateObject->GetChildren).
  * @param iPosition
  * The position in the list where to move the element.
  * @param ioListToReorder
  * The list to reorder.
  *
  * @return
  *   <b>Legal values:</b>
  *   <dl><dt><tt>S_FALSE</tt></dt><dd>Move encountered an unexpected problem.</dd>
  *   <dt><tt>S_OK</tt></dt><dd>Move succeeded.</dd>
  *   <dt><tt>E_FAIL</tt></dt><dd>Otherwise.</dd></dl>
  *
  */
  virtual HRESULT MoveToPosition(const int iOldPosition,
                                 const int NewPosition,
                                 CATListValCATBaseUnknown_var& ioListToReorder) = 0;  

 /**
  * Retrieves the possible quick rorders.
  *
  * @param ioListQuickReorder
  * The list of quick reorders : example "alphabet", "update".
  *
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL 
  */
  virtual HRESULT GetQuickReorders(CATListValCATUnicodeString& oListQuickReorders) = 0;  



 /**
  * Quick reorders the list.
  *
  * @param ioListToReorder
  * The list to reorder.
  *
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK if QuickReorder has succeeded, E_FAIL otherwise
  */
  virtual HRESULT QuickReorder(const CATUnicodeString& iReorder,CATListValCATBaseUnknown_var& ioListToReorder) = 0;  
};

#endif      

