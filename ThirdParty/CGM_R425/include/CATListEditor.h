// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATListEditor.h
// Header definition of CATListEditor
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2005  Creation: Code generated by the CAA wizard  mok
//  Jul 2005  Moved from CATListEdit to CATListEditor.
//===================================================================
#ifndef CATListEditor_H
#define CATListEditor_H

#include "CATViewEdit.h"
#include "CATListView.h"
#include "CATCommand.h"
#include "CATString.h"
#include "CATBoolean.h"
#include "CATDlgUtility.h"
#include "CATDlgFrame.h"

class CATInsetCellTextEditorDlg;
class CATInsetCellComboDlg;
//-----------------------------------------------------------------------

/**
 * Specialization of CATListView to allow for the editing of individual
 * cells of the table.  Extensions allow for in-cell editing.
 * Must use a model which implements CATIListEditModel for this implementation
 * to work properly.
 */
class ExportedByCATViewEdit CATListEditor: public CATListView
{
  CATDeclareClass;

     // for ODT purpose - be carefull : CATViewTestListEdit02 is accessing private members of this class to test their values
     friend class CATViewTestListEdit02;
     friend class CATInsetCellDlg;

  public:

     // Standard constructors and destructors
     // -------------------------------------
     CATListEditor ( CATVizViewer* iViewer, const CATString &iName, int iStyle= CATRightScroll|CATListSortable );
     CATListEditor ( CATDlgFrame* iViewer, const CATString &iName, int iStyle= CATRightScroll|CATListSortable );
     CATListEditor ( CATCommand* iViewer, const CATString &iName, int iStyle= CATRightScroll|CATListSortable );
     virtual ~CATListEditor ();

     // Copy constructor and equal operator
     // -----------------------------------
     CATListEditor (CATListEditor &);
     CATListEditor& operator=(CATListEditor&);

     virtual void OnEdit( CATBaseUnknown_var iObject, const CATString &iColumnID );
     virtual void OnEditDlgUpdated();
     virtual void SetViewer( CATVizViewer *iViewer );

     virtual CATBoolean IsQuickEditMode( );
     CATBoolean IsQuickEditModeAndShiftPressed( );
     void EndEditionContext( );

  protected:
     //Replay gets the values from the "CATListCellRecordReplay" and calls the appropriate controller
     //Uses the method CATListView::GetReplayValues on the CATListCellRecordReplay object, since it is not externally availables
     virtual HRESULT Replay( const char *iEvent, CATBaseUnknown_var iObject );
     virtual void GetRowBounds(const CATBaseUnknown_var iItem, int& oYTop, int& oDepth);
     virtual void AdjustColumnBounds(int& oXLeft, int& oWidth);
     virtual HRESULT HideDialog( );

  private:
    void GetAbsoluteCellCoords(int iRelX, int iCellWidth, int iRelY, int iCellDepth,
                                           DRECT& oAbsCellRect) ;
    int GetMaxLine();
    void UpdateLabel();
    void GetColumnBounds(const CATString& iColumnID, int& oXLeft, int& oWidth);
    CATBoolean GetItemLineNumber(const CATBaseUnknown_var iItem, int& oLineNum);
    HRESULT UpDateMultiSelection( const CATUnicodeString& iText );

    CATDialog* _pDialog;
    CATInsetCellTextEditorDlg* _EditorDlg;
    CATInsetCellComboDlg* _ComboDlg;
    CATBoolean _ComboMode;

    CATBaseUnknown_var _ItemBeingEdited;
    CATString _ColumnBeingEdited;

    // SCA : RI 41745 & 41836. Versionnement en Capture-Replay.
    int IR41745_IR41836;
    CATBoolean     _bEditionContext;
};

//-----------------------------------------------------------------------

#endif
