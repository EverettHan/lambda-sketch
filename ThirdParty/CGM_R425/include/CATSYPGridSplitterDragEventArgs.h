//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2013/08/21
//===================================================================
// CATSYPGridSplitterDragEventArgs.cpp
// Header definition of class CATSYPGridSplitterDragEventArgs
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2013/08/21 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATSYPGridSplitterDragEventArgs_H
#define CATSYPGridSplitterDragEventArgs_H

#include "VisuDialog.h"
#include "CATSYPEventArgs.h"
class CATSYPEvent;
//-----------------------------------------------------------------------

class ExportedByVisuDialog  CATSYPGridSplitterDragEventArgs: public CATSYPEventArgs
{
public:
// Standard constructors and destructors
// -------------------------------------
CATSYPGridSplitterDragEventArgs (CATSYPEvent *i_pEvent,float i_translation);
virtual ~CATSYPGridSplitterDragEventArgs ();

/**
* Get drag value
*/
float GetTranslation()const;

private:
// Copy constructor and equal operator
// -----------------------------------
CATSYPGridSplitterDragEventArgs (CATSYPGridSplitterDragEventArgs &);
CATSYPGridSplitterDragEventArgs& operator=(CATSYPGridSplitterDragEventArgs&);

float _translation;
};

//-----------------------------------------------------------------------

#endif
