// COPYRIGHT Dassault Systemes 2004
#ifndef CATListView_H
#define CATListView_H

#include <CATView.h>
#include <CATScrollableView.h>
#include <CATGraphicAttributeSet.h>
#include <CATListOfCATString.h>
#include <CATIListViewModel.h>
#include <CATIColumnModel.h>
#include <CATBaseUnknown.h>
#include <CATString.h>
#include <CATBoolean.h>

// Dialog framework
#include "CATDlgUtility.h"

/*
 * Style to have a list header up to the right. Without it, the list header ends a last column
 */
#define CATListHeaderFullWidth		0x02000
/*
 * Style to display the list header even on empty list
 */
#define CATListHeaderAlwaysVisible	0x04000
/*
 * Style to allow sort
 */
#define CATListSortable			0x08000
/**
 * Use this style to disable preselection behavior.
 * This style is activated automatically when the user move the cursor
 * using the keyboard
 **/
#define CATListPreselectionDisabled	0x10000
/**
 * Use this style to include column title in column auto-sizing (default is cells only)
 **/
#define CATListAutoSizeWithHeader	0x20000
/**
 * To get 45° rotated column headers
 **/
#define CATListItalicHeaders		0x40000

/**
 * CATListView
 **/
class ExportedByCATView CATListView: public CATScrollableView
{
    CATDeclareClass;
public:
    /**
     * Constructor
     **/
    CATListView( CATCommand *iFather, const CATString &iName, int iStyle= CATRightScroll|CATListSortable );
    /**
     * Destructor
     **/
    virtual ~CATListView( void );

    /**
     * Retrieve an interface to the column definition model for this viewer.  The CATIColumnModel
     * will manage the definitions and order of the columns to display in the table.  <br>
     * If no  SetColumnModel has ever been set, a basic CATColumnModel will be generated and returned
     * from this method.  This column model may then be used to set up the columns. However,
     * since the AddColumn method is not available on the CATIColumnModel interface, a cast is
     * required.<br>
     * The preferred approach, though, is to instantiate and initialize a model (CATColumnModel may
     * be used in most cases) then call SetColumnModel to declare it when initilizing the CATListView.
     */
    void GetColumnModel(CATIColumnModel_var& oColMdl);

    /**
     * Set the column definitions for this ListView.
     */
    void SetColumnModel(CATIColumnModel_var& iColMdl);

    /**
     * Add a column
     * @deprecated
     * Use GetColumnModel, then call this method on that object.
     **/
    void AddColumn( const CATString &iID, const CATUnicodeString &iTitle, int iWidth );

    /**
     * Remove a column
     * @deprecated
     * Use GetColumnModel, then call this method on that object.
     **/
    void RemoveColumn( const CATString &iID );
    /**
     * Set columns order
     * @deprecated
     * Use GetColumnModel, then call this method on that object.
     **/
    void SetColumnOrder( const CATListOfCATString &iIDs );
    /**
     * Get columns order
     * @deprecated
     * Use GetColumnModel, then call this method on that object.
     **/
    void GetColumnOrder( CATListOfCATString &oIDs );
    /**
     * Get column width
     * @deprecated
     * Use GetColumnModel, then call this method on that object.
     **/
    int GetColumnWidth( const CATString &iID );
    /**
     * Set column width
     * @deprecated
     * Use GetColumnModel, then call this method on that object.
     **/
    void SetColumnWidth( const CATString &iID, int iWidth );
    /**
     * Set sort definition
     * @deprecated
     * Use GetColumnModel, then call this method on that object.
     **/
    void SetSortDefinition( const CATString &iColumnID, int iReverse= 0 );
    /**
     * Get sort definition
     * @deprecated
     * Use GetColumnModel, then call this method on that object.
     **/
    void GetSortDefinition( CATString &oColumnID, int &oReverse );

    /**
     * Sort definition changed by user
     **/
    CATNotification *GetSortDefinitionNotification(void);
    /**
     * Get tooltip
     **/
    CATUnicodeString GetTooltip(void);
    /*
    * If enabled, row headers are drawn on the left side
    * They are disabled by default
    */
    void SetRowHeadersEnabled(CATBoolean enabled);
    /**
     * Resize a column automatically from cell width
     **/
    void AutoSizeColumn( const CATString &iColumnID );
    /**
     * Resize all columns
     **/
    void AutoSizeColumns( void );
    /**
     * Get row count of an item. Item should be visible for the method to work
     * => use it only on response to user interactions
     * Returns 0 if item not found (first row is 1).
     **/
    int GetItemRow( CATBaseUnknown_var iItem );
    /**
     * Get row position
     **/
    HRESULT GetRowPosition( int iRow, float &oX, float &oY, float &oW, float &oH );

	/**
	* Get the coordinates relative to an associated viewer of a header 
	**/
	void  GetColumnHeaderCoordsRelativeToAssociatedViewer(const CATString& iColID, DRECT & oHeaderRect);

    virtual void OnRightClick( float iX, float iY );

    virtual CATPathElement *CreateObjectPath(void);

    bool isColWidthChanging() { if (_resizecolumn =="") return false; else return true;}
    virtual CATBoolean IsQuickEditModeAndShiftPressed( );
    virtual void EndEditionContext( );

protected:
    virtual void OnClick( float iX, float iY );
    virtual void OnMoveOver( float iX, float iY );
    virtual void OnLeave(void);
    virtual void OnKey( const CATKeybdEvent &iEvent );
    virtual void DrawItem( int iY, CATBaseUnknown_var iItem, int iRedraw, int iRow );
    virtual HRESULT AnalysePosition( float iX, float iY, CATBaseUnknown_var &oObject, CATString &oColumn, int &oInHeader, int &oInHeaderSplitter );
    virtual HRESULT AnalysePosition( float iX, float iY, CATBaseUnknown_var &oObject, CATString &oColumn, int &oInHeader, int &oInHeaderSplitter, int &oInRowHeader );
    virtual HRESULT AnalysePosition( float iX, float iY, int &oCursorCol, int &oCursorRow );
    virtual HRESULT OnKeyboardAction( const CATKeybdEvent &iEvent, unsigned int& oReturn );
    virtual CATBoolean GetLowlight( );



    void UpdateState(void);
    void SelectCell( const CATBaseUnknown_var &iObject, const CATString &iColumn );
    void ActivateCell( const CATBaseUnknown_var &iObject, const CATString &iColumn );

    CATListOfCATBaseUnknown_var _items;
    int _rowCount;
    /**
     * Set cursor position (used for keyboard management)
     * List is scrolled so that cursor is always visible
     * Cursor is displayed by a light rectangle around cell
     **/
    HRESULT SetCursor( int iCol, int iRow );
    /**
     * Check that a cell is visible, scroll the view to make it visible if it is not
     **/
    HRESULT ShowCell( int iCol, int iRow );
    /**
     * Get cursor position
     **/
    HRESULT GetCursor( CATString &oColumn, CATBaseUnknown_var &oRow );

    /**
     * Row set
     */
    CATBoolean _rowHeadersEnabled;
    int _xRowStart;
    int _yRowStart;
    int _xRowWidth;
    int _yRowHeight;
    int _numberRowsVisible;
    void RefreshRowHeaderState();

    class Dimensions
    {
    public:
        float _line;
        float _text;
        float _textheight;
        float _icon;
        float _header;
    };
    Dimensions _dims;

    class Colors
    {
    public:
        CATGraphicAttributeSet _back;
        CATGraphicAttributeSet _back2;
        CATGraphicAttributeSet _text;
        CATGraphicAttributeSet _low;
        CATGraphicAttributeSet _high;
        CATGraphicAttributeSet _headerback;
        CATGraphicAttributeSet _headerborder;
        CATGraphicAttributeSet _headertext;
    };
    Colors _colors;

    /**
     * Record integration, available for child classes
     *
     **/

    //Record creates an object "CATListCellRecordReplay" to wrap the rowObject and columnName into one CATBaseUnknown_var
    //Then it calls CATViewBase::Record
    //The CATListCellRecordReplay class is needed because CATViewBase only accepts one CATBaseUnknown_var parameter
    HRESULT Record( const char *iEvent, CATBaseUnknown_var iRowObject, CATString iColumnName);

    //Replay gets the values from the "CATListCellRecordReplay" and calls the appropriate controller
    HRESULT Replay( const char *iEvent, CATBaseUnknown_var iObject );

    //This method is used to get the values from the CATListCellRecordReplay object
    //If iObject is not a CATListCellRecordReplay object, then oRowObject = iObject
    void GetReplayValues(CATBaseUnknown_var &iObject, CATBaseUnknown_var &oRowObject, CATString &oColumnName);

    /**
     * Cursor
     **/
    int _cursorCol, _cursorRow;

    /**
     * Numero de ligne et nom de la derniere cellule selectionnee, pour le deplacement par fleches.
     **/
    int _lastRowIndSel;
    float _lastScrollYSel;
    CATString _lastColIDSel;

    virtual void DrawHeaderRect( float iX, float iY, float iW, float iH );
    virtual void DrawHeaders(void);
    virtual HRESULT GetIconHeaders( const CATString &iColumnID, CATUnicodeString& oIcon );

    /**
     * Modele gerant les couleurs.
     **/
    CATBoolean _modelWithColor;
    CATBoolean _modelWithColorIsInit;

    /**
     * CATListView in a CATVidViewAdaptor
     **/
    CATBoolean _InACATVidViewAdaptor;

private:
    /**
     * Callbacks
     **/
    void OnDoubleClick( float iX, float iY );
    void OnRepeatClick( float iX, float iY );
    void OnDrag( float iOriginX, float iOriginY, float iDX, float iDY, int iStart );
    /**
     * Paint functions
     **/
    void DrawItalicHeaders(void);
    void Paint( void );
    void PaintForPick( void );
    void PaintForHighlight( void );
    void UpdateLook(void);
    void GetBackgroundColor(float& r, float& g, float& b);
    /**
     * Update management
     **/
    void CleanupState(void);
    /**
     * Analyse cursor position
     **/
    HRESULT AnalysePosition( float iX, float iY, CATBaseUnknown_var &oObject );
    /**
     * Column set
     **/
    CATIColumnModel_var _columns;
    CATString _resizecolumn;
    int _resizecolumnwidth;
    /**
     * Sort
     **/
    void ToggleSort(const CATString& iColID);
    /**
     * Record integration, private use
     **/
    CATUnicodeString GetRecordId( CATBaseUnknown_var iRecordObject );
    CATBaseUnknown_var GetReplayObject( const CATUnicodeString &iReplayId );
    CATBaseUnknown_var _lastRecordedObject;
    /**
     * Viewer : CB when the background is changed
     **/
    CATCallback _CBViewerBackgroundChanged;

    static int defaultFontHeight;

protected:
  virtual void AfterToggleSort(const CATString& iColID, const int& iReverse );

private:
  CATBoolean        _OnPaint;
  CATUINT32         _charCode;			 // unicode of character
  int               _keyCodeType;		// 0=character; 1=keycode;

public:
  void DecalToPosition( const int& iDecalX, const int& iDecalY );
  void ActivateCellForEdit( );
  // GetCharCode returns ascii code of a key
  inline CATUINT32   GetCharCode() const   {return _charCode;}    // unicode of character 
  // GetKeyCodeType returns 0=character or 1=keycode;
  inline int         GetKeyCodeType() const{return _keyCodeType;}
  // required by IR-445927-3DEXPERIENCER2017x 
  void SetCharCode(CATUINT32 Code)
  {
	  _charCode = Code;
  }
  // required by IR-445927-3DEXPERIENCER2017x 
  void SetKeyCodeType(int Key)
  {
	  _keyCodeType = Key;
  }
protected:
  virtual HRESULT GetCellSelectedColor(const CATString& iColID, int* oRed, int* oGreen, int* oBlue, int* oAlpha );

};

#endif
