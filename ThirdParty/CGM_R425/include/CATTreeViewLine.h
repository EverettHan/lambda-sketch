#ifndef _CATTreeViewLine_H
#define _CATTreeViewLine_H

#include <CATBaseUnknown.h>
#include <CATView.h>
#include <CATUnicodeString.h>

/*
 * Data structure to store visible nodes information
 * used during Paint process of CATTreeView
 */
class ExportedByCATView CATTreeViewLine
{
public:
	enum ExpanderIcon
	{
		NoIcon,
		Plus,
		Minus,
		Partial
	};
	CATTreeViewLine(void) : _indent(0), _expanderIcon(NoIcon), _verticalline(0), _style(0), _iconwidth(0.0), _textwidth(0.0)
	{
	}
	CATBaseUnknown_var _object;
	CATUnicodeString _image;
	CATUnicodeString _label;
	int _indent;
	ExpanderIcon _expanderIcon;
	int _verticalline;
	int _style;
	float _iconwidth;
	float _textwidth;
	int operator != ( const CATTreeViewLine &iLine ) const;
};

#include <CATLISTV_Clean.h>
#define CATLISTV_InsertAt
#define CATLISTV_RemovePostion
#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATView
#include <CATLISTV_Declare.h>

CATLISTV_DECLARE( CATTreeViewLine );
typedef CATLISTV( CATTreeViewLine ) CATListOfCATTreeViewLine;

#endif
