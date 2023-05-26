// COPYRIGHT Dassault Systemes 2004
#ifndef CATTextOverlayViewItem_H
#define CATTextOverlayViewItem_H

#include <CATView.h>
#include <CATListOfInt.h>
#include <CATPathElement.h>
#include <CATListOfCATString.h>
#include <CATListOfCATUnicodeString.h>

/**
 * CATTextOverlayViewItem
 * Model for CATTextOverlayView
 **/

class ExportedByCATView CATTextOverlayViewItem : public CATBaseUnknown
{
	CATDeclareClass;
public:
	CATTextOverlayViewItem(CATPathElement *iPath) : _lx(0.0), _ly(0.0), _tx(0.0), _ty(0.0), _lbx(0.0), _lby(0.0), _lbw(0.0), _lbh(0.0), _layout(Center), _item(iPath), _Command(FALSE) {}
	CATPathElement *_item;
	/*
	 * Icon and label
	 */
	CATListOfCATUnicodeString _icon;
	CATListOfInt _lineHeight;
	CATListOfCATUnicodeString _label;
	/*
	 * HyperLinks
	 */
	CATListOfCATUnicodeString _Lnks;
	/*
	 * Commands
	 */
	CATListOfInt _Cmds;
	CATBoolean _Command;
	CATBaseUnknown_var _spLabel;
	/*
	 * Layout
	 */
	enum Layout
	{
		Left= 0,
		Center= 1,
		Right= 2,
		Hidden= 3
	};
	Layout _layout;
	/*
	 * Arrow origin
	 */
	float _lx, _ly;
	/*
	 * Arrow Target (Left or Right layout)
	 */
	float _tx, _ty;
	/*
	 * Label box
	 */
	float _lbx, _lby, _lbw, _lbh;
};

#endif
