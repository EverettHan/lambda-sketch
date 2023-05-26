// COPYRIGHT Dassault Systemes 2015

#ifndef CATVidTabReorderEventArgs_H
#define CATVidTabReorderEventArgs_H

#include <VisuDialog.h>
#include <CATSYPEventArgs.h>
class CATSYPEvent;

//-----------------------------------------------------------------------------
/**
 * Those event arguments are used to transmit tab reorder information.
 */
class ExportedByVisuDialog CATVidTabReorderEventArgs: public CATSYPEventArgs
{
  CATDeclareClass;
public:
  /** 
   * Initializes this class.
   *
   * @param i_pEvent the dispatched event. Can't be @c NULL. 
   * @param i_fromIndex the index of the tab page currently being reordered
   * @param i_toIndex the index of the new place where this tab page must go
   */
  CATVidTabReorderEventArgs(CATSYPEvent * i_pEvent, int i_fromIndex, int i_toIndex);

  /** Destroy this class. */
  virtual ~CATVidTabReorderEventArgs();

  /** @return the index of the tab page currently being reordered */
  int GetFromIndex() const;
  /** @return the index of the new place where this tab page must go */
  int GetToIndex() const;

private:
CATVidTabReorderEventArgs (CATVidTabReorderEventArgs &);
CATVidTabReorderEventArgs& operator=(CATVidTabReorderEventArgs&);

  const int _fromIndex;
  const int _toIndex;

};

//-----------------------------------------------------------------------

#endif
