#ifndef CATVidMdlSortChangedEventArgs_h
#define CATVidMdlSortChangedEventArgs_h

// COPYRIGHT DASSAULT SYSTEMES 2014

// VisuImmersiveDialog framework
#include <VisuDialog.h>
#include <CATVidMdlIndex.h>
#include <CATVid.h>

// UIVCoreTools framework
#include <CATSYPEventArgs.h>
#include <CATSYPArray.h>
#include <UIVCoreToolsInline.h>

// System framework
#include <CATUnicodeString.h>

class CATSYPEvent;

/**
 * Arguments class for a modification of a model filtering.
 *
 * @see CATVidMdlCompletionProxy
 */
class ExportedByVisuDialog CATVidMdlSortChangedEventArgs : public CATSYPEventArgs
{
  CATDeclareClass;

public:

  /** Constructor */
  CATVidMdlSortChangedEventArgs(
      CATSYPEvent * i_pEvent, 
      const CATUnicodeString& i_sortedProperty, 
      const CATVid::SortOrder i_sortOrder);

  /** Destructor */
  virtual ~CATVidMdlSortChangedEventArgs();

  /**
   * @return the current filtering string.
   */
  INLINE CATUnicodeString GetSortedProperty() const {return _sortedProperty;};

  /**
   * @return the number of the indexes matching the current filtering string.
   */
  CATVid::SortOrder GetSortOrder() const {return _sortOrder;};


private:

  // Copy constructor and assignement operator are disabled
  CATVidMdlSortChangedEventArgs(CATVidMdlSortChangedEventArgs &);
  CATVidMdlSortChangedEventArgs& operator=(CATVidMdlSortChangedEventArgs&);

  CATUnicodeString _sortedProperty;
  CATVid::SortOrder _sortOrder;
};

#endif // CATVidMdlSortChangedEventArgs_h
