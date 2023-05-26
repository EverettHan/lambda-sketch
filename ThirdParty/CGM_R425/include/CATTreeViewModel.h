// COPYRIGHT Dassault Systemes 2004
#ifndef CATTreeViewModel_H
#define CATTreeViewModel_H

#include <CATView.h>
#include <CATViewModel.h>
#include <CATITreeViewModel.h>
/** VR2 - C14N - 03/31/2021

Above include is need for CATView fw compilation but may be replaced by the 2 following lines:
#include <CATLISTV_CATBaseUnknown.h>
typedef  CATLISTV(CATBaseUnknown_var)  CATListOfCATBaseUnknown_var; 

But for other fwks (outside UI organization), removing this include impacts the build
*/
class CATCmdContainer;

/**
 * CATTreeViewModel - Abstract class for tree model implementation
 **/
class ExportedByCATView CATTreeViewModel: public CATViewModel
{
	CATDeclareClass;
public:
	/**
	 * Constructor
	 **/
	CATTreeViewModel( void );
	/**
	 * Destructor
	 **/
	virtual ~CATTreeViewModel( void );
	/**
	 * Get children of a node
	 **/
	virtual void GetChildren( CATBaseUnknown_var iNode, CATListOfCATBaseUnknown_var &oNodes ) = 0;
	/**
	 * Get label
	 **/
	virtual CATUnicodeString GetLabel( CATBaseUnknown_var iNode ) = 0;
	/**
	 * Get Icon
	 **/
	virtual CATUnicodeString GetIcon( CATBaseUnknown_var iNode ) = 0;
	/**
	 * Get Icon mask
	 **/
	virtual int GetIconMask( CATBaseUnknown_var iNode, int iIndex, CATUnicodeString &oMask, int &oX, int &oY ) { return 0; };
	/**
	 * Return node style.
	 * Use the CATTreeNodeStyleXXX constants to define node style
	 **/
	virtual int GetStyle( CATBaseUnknown_var iNode );
	/**
	 * Is a leaf node (no child) ?
	 * Default implementation calls GetChildren
	 **/
	virtual int IsLeaf( CATBaseUnknown_var iNode );
protected:
	/**
	 * Ask for update of views from model change
	 **/
	HRESULT Update( CATBaseUnknown_var iNode );
};

#endif
