//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2017/02/23
//===================================================================
// CATVidMdlHeaderClickedEventArgs.h
// Header definition of class CATVidMdlHeaderClickedEventArgs
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2017/02/23 Creation: Code generated by the 3DS wizard  ISP
//===================================================================

#ifndef CATVidMdlHeaderClickedEventArgs_H
#define CATVidMdlHeaderClickedEventArgs_H

#include <VisuDialog.h>
#include <CATSYPEventArgs.h>
#include <CATString.h>


class CATSYPEvent;

/**
 * Argument class dispatched by a view class to indicate that a column header has
 * been clicked by a user. 
 */
class ExportedByVisuDialog CATVidMdlHeaderClickedEventArgs : public CATSYPEventArgs
{
  CATDeclareClass;
public:
  /** Default constructor */
  CATVidMdlHeaderClickedEventArgs (CATSYPEvent * i_pEvent, const CATString & columnID, const int & columnIndex);
  
  /** Destructor */
  virtual ~CATVidMdlHeaderClickedEventArgs ();
  
  /**
  * Get the column ID of the column in whose column header has been clicked.
  *
  * @returns the ID of the column.
  */
  const CATString GetColumnID();

  /**
  * Get the column Index of the column in whose column header has been clicked.
  *
  * @returns the Index of the column.
  */
  const int GetColumnIndex();

private:
  // Copy constructor and assignement operator are disabled
  CATVidMdlHeaderClickedEventArgs (CATVidMdlHeaderClickedEventArgs &);
  CATVidMdlHeaderClickedEventArgs& operator=(CATVidMdlHeaderClickedEventArgs&);
  
  CATString _columnID;
  int _columnIndex;

};

#endif
