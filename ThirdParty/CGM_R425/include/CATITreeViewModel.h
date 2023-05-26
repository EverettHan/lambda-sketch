// COPYRIGHT Dassault Systemes 2004
#ifndef CATITreeViewModel_H
#define CATITreeViewModel_H

#include <CATAfrItf.h>
#include <CATUnicodeString.h>
#include <CATBaseUnknown.h>
#include <CATBaseUnknown_var.h>
#include <CATLISTV_CATBaseUnknown.h>
typedef  CATLISTV(CATBaseUnknown_var)  CATListOfCATBaseUnknown_var; 

extern ExportedByCATAfrItf IID IID_CATITreeViewModel;

/*
 * Node style constants
 * CATTreeNodeStyleHidden : icon is lowlighted
 * CATTreeNodeStyleActive : node is underlined
 * CATTreeNodeStyleInWork : node has a solid background
 * CATTreeNodeStyleParExp : node is partially expanded (GetChildren is not returning the full children list)
 */
#define CATTreeNodeStyleNormal	0x0000
#define CATTreeNodeStyleHidden	0x0001
#define CATTreeNodeStyleActive	0x0002
#define CATTreeNodeStyleInWork  0x0004
#define CATTreeNodeStyleParExp  0x0008

/**
 * CATITreeViewModel. Interface to display a model in a tree view.
 **/
class ExportedByCATAfrItf CATITreeViewModel: public CATBaseUnknown
{
	CATDeclareInterface;
public:
	/**
	 * Get children of a node.
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
	 * Get Icon masks.
	 * iIndex is the index of the mask to retreive (starting from 0).
	 * Return 0 if no mask exist for this index, 1 otherwise.
	 * oMask is the icon file name (no path, no extension)
	 * oX and oY are offset coordinates from standard icon origin (use 0,0 to put mask on top of standard icon)
	 **/
	virtual int GetIconMask( CATBaseUnknown_var iNode, int iIndex, CATUnicodeString &oMask, int &oX, int &oY ) = 0;
	/**
	 * Return node style.
	 * Use the CATTreeNodeStyleXXX constants to define node style
	 **/
	virtual int GetStyle( CATBaseUnknown_var iNode ) = 0;
	/**
	 * Is a leaf node (no child) ?
	 * Default implementation calls GetChildren
	 **/
	virtual int IsLeaf( CATBaseUnknown_var iNode ) = 0;
};

CATDeclareHandler(CATITreeViewModel, CATBaseUnknown);

#endif
