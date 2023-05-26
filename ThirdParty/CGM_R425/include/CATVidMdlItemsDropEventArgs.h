#ifndef CATVidMdlItemsDropEventArgs_H
#define CATVidMdlItemsDropEventArgs_H

#include <VisuDialog.h>
#include <CATVidMdlStructureChangedEventArgs.h>
#include <CATVidMdlIndex.h>
#include <CATSYPArray.h>

// LD5 TODO Erase

class CATSYPEvent;

/**
 * Arguments class for a modification of structure of a model.
 *
 * When a row or a column is inserted or removed from a model, an event
 * is dispatched using this class.
 * This class indicates which rows or columns have been modified.
 */
class ExportedByVisuDialog CATVidMdlItemsDropEventArgs : public CATVidMdlStructureChangedEventArgs
{
  CATDeclareClass;
public:
  /** Constructor */
  CATVidMdlItemsDropEventArgs (CATSYPEvent * i_pEvent, const CATVidMdlIndex & i_parent, const CATSYPDynArray<CATVidMdlIndex> & i_modifiedIndexes);

  /** Destructor */
  virtual ~CATVidMdlItemsDropEventArgs ();

private:
  // Copy constructor and assignement operator are disabled
  CATVidMdlItemsDropEventArgs (CATVidMdlItemsDropEventArgs &);
  CATVidMdlItemsDropEventArgs& operator=(CATVidMdlItemsDropEventArgs&);
};

#endif
