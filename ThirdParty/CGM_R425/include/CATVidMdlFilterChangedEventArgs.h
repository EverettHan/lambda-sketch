#ifndef CATVidMdlFilterChangedEventArgs_h
#define CATVidMdlFilterChangedEventArgs_h

// COPYRIGHT DASSAULT SYSTEMES 2014

// VisuImmersiveDialog framework
#include <VisuDialog.h>
#include <CATVidMdlIndex.h>

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
class ExportedByVisuDialog CATVidMdlFilterChangedEventArgs : public CATSYPEventArgs
{
  CATDeclareClass;

public:

  /** Constructor */
  CATVidMdlFilterChangedEventArgs(
      CATSYPEvent * i_pEvent, 
      const CATUnicodeString& i_filteringString, 
      const CATSYPDynArray<CATVidMdlIndex> & i_matchingIndexes);

  /** Destructor */
  virtual ~CATVidMdlFilterChangedEventArgs();

  /**
   * @return the current filtering string.
   */
  INLINE CATUnicodeString GetFilteringString() const {return _filteringString;};

  /**
   * @return the number of the indexes matching the current filtering string.
   */
  INLINE int GetNumberOfMatchingIndexes() const {return _matchingIndexes.GetLength();};

  /**
   * @return the @c i_index -th index matching the current filtering string.
   */
  CATVidMdlIndex GetMatchingIndex(int i_index) const;

private:

  // Copy constructor and assignement operator are disabled
  CATVidMdlFilterChangedEventArgs (CATVidMdlFilterChangedEventArgs &);
  CATVidMdlFilterChangedEventArgs& operator=(CATVidMdlFilterChangedEventArgs&);

  CATUnicodeString _filteringString;
  CATSYPDynArray<CATVidMdlIndex> _matchingIndexes;
};

#endif // CATVidMdlFilterChangedEventArgs_h
