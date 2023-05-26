//===================================================================
// COPYRIGHT Dassault Systemes 2013/12/19
//===================================================================
// CATCkeExpressionContextForShow.cpp
// Header definition of class CATCkeExpressionContextForShow
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2013/12/19 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATCkeExpressionContextForShow_H
#define CATCkeExpressionContextForShow_H

#include "CATLifSpecs.h"
#include "CATBaseUnknown.h"
#include "CATListOfCATUnicodeString.h"

//-----------------------------------------------------------------------

class ExportedByCATLifSpecs CATCkeExpressionContextForShow: public CATBaseUnknown
{
public:
// Standard constructors and destructors
// -------------------------------------
CATCkeExpressionContextForShow ();
virtual ~CATCkeExpressionContextForShow ();

static CATListOfCATUnicodeString topVariables;
static CATBoolean showExpression;
static CATBoolean IsTopEditorVariable(const CATUnicodeString& varName);
private:
// Copy constructor and equal operator
// -----------------------------------
CATCkeExpressionContextForShow (CATCkeExpressionContextForShow &);
CATCkeExpressionContextForShow& operator=(CATCkeExpressionContextForShow&);

};

//-----------------------------------------------------------------------

#endif