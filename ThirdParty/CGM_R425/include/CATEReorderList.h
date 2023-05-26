/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2000
#ifndef _CATEReorderList_h
#define _CATEReorderList_h

#include "CATBaseUnknown.h"

/**
 * Adaptor for CATIReorderList interface
 */
#include "CATInteractiveInterfaces.h"

class CATUnicodeString;
class CATBaseUnknown_var;
class CATListValCATBaseUnknown_var;
class CATListValCATUnicodeString;

class ExportedByCATInteractiveInterfaces CATEReorderList : public CATBaseUnknown
{ 
public:
  /**
  * Constructor
  */
  CATEReorderList();

  /**
  * Ask if an element can be moved in the graph
  * @param oToMove
  * The element to move (this element is a member retrieve from CATINavigateObject->GetChildren).
  * @param iPosition
  * The position in the list where to move the 
  * @param oWhyMoveImpossible
  * Explain here why move is impossible
  * @param ioListToReorder
  * The list to reorder
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK if move is possible, E_FAIL otherwise
  */
  HRESULT CanMoveToPosition(const int iOldPosition,
                            const int NewPosition,
                            const CATListValCATBaseUnknown_var& ioListToReorder,
                            CATUnicodeString& oWhyMoveImpossible);

  /**
  * Ask if an element can be moved in the graph
  * @param oToMove
  * The element to move (this element is a member retrieve from CATINavigateObject->GetChildren).
  * @param iPosition
  * The position in the list where to move the 
  * @param ioListToReorder
  * The list to reorder
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK if move has succeeded, E_FAIL otherwise
  */
  HRESULT MoveToPosition(const int iOldPosition,
                         const int NewPosition,
                         CATListValCATBaseUnknown_var& ioListToReorder);  

  /**
  * Retrieve the possible quick rorders
  * @param ioListQuickReorder
  * The list of quick reorders : example "alphabet", "update"
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK , E_FAIL 
  */
  HRESULT GetQuickReorders(CATListValCATUnicodeString & oListQuickReorders);  



  /**
  * Quick reorders the list
  * @param ioListToReorder
  * The list to reorder
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK if QuickReorder has succeeded, E_FAIL otherwise
  */
  HRESULT QuickReorder(const CATUnicodeString& iReorder,CATListValCATBaseUnknown_var& ioListToReorder);  


private:


  CATEReorderList(const CATEReorderList&);
  CATEReorderList& operator=(const CATEReorderList&);

};

#endif      

