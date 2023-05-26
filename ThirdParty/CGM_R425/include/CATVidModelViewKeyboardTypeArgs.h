#ifndef CATVidModelViewKeyboardTypeArgs_H
#define CATVidModelViewKeyboardTypeArgs_H

#include <VisuDialog.h>
#include <CATSYPEventArgs.h>
#include <CATVidMdlIndex.h>
#include <CATUnicodeString.h>
#include <CATVidGridViewColumn.h>

//-----------------------------------------------------------------------------

/**
 * 
 * Dispatching arguments of @ref CATVidCtlAbstractItemsView#KeyboardType on model/view keyboard typing.
 * 
 */
class ExportedByVisuDialog CATVidModelViewKeyboardTypeArgs: public CATSYPEventArgs
{
  CATDeclareClass;
public:
  /** 
   * Build this class.
   *
   * @param i_pEvent the event dispatched. Cannot be @c NULL. Only a weak reference is kept.
   * @param i_TypedString the string currently typed on keyboard.
   * @param pMdlColumn the column listening the keyboard events.
   * @param i_ModelColumn the column model index represented by pMdlColumn.
   * @param currentIndex the current index (last selected).
   */
  CATVidModelViewKeyboardTypeArgs(CATSYPEvent * i_pEvent, CATUnicodeString i_TypedString, 
	CATVidGridViewColumn * pMdlColumn, int i_ModelColumn, CATVidMdlIndex currentIndex);
  /** 
   * Destroy this class. 
	 */
	virtual ~CATVidModelViewKeyboardTypeArgs();
	
	/*
	*Get the GridViewColumn listening the keyboard.
	*/
	CATVidGridViewColumn * GetGridViewColumnListeningKeyboard() const;

	/*
	*Get the column model index represented by pMdlColumn
	*/
	int GetModelColumn() const;

	/*
	*Get the the string currently typed on keyboard.
	*/
	CATUnicodeString GetTypedString() const;

	/*
	*Get the current index (last selected one).
	*/
	CATVidMdlIndex GetStartingIndex() const;

	/*
	*Get the index set as matching index.
	*/
	CATVidMdlIndex GetMatchingIndex() const;

	/*
	*Set given index as matching index. (Matching current keyboard typed string)
	*/
	void SetMatchingIndex(CATVidMdlIndex & i_index);
 

private:
  /** Copy constructor. */
  CATVidModelViewKeyboardTypeArgs (CATVidModelViewKeyboardTypeArgs &);
  /** Equal operator. */
  CATVidModelViewKeyboardTypeArgs& operator=(CATVidModelViewKeyboardTypeArgs&);

	CATUnicodeString _typedString;
	CATVidGridViewColumn * _gridViewColumn;
	int _modelColumn;
	CATVidMdlIndex _currentIndex;
	CATVidMdlIndex _foundIndex;

private:
 
};

//------------------------------------------------------------------------------

#endif
