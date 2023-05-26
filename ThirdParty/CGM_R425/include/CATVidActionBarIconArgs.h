#ifndef CATVidActionBarIconArgs__H
#define CATVidActionBarIconArgs__H

#include <VisuDialogEx.h>
#include <CATSYPEventArgs.h>
#include <CATUnicodeString.h>

class CATSYPEvent;

/**
 * Class to communicate with the icon look up algorithm for ActionBar V3.
 * It allows to supply to the algorithm the icon name to look for and also
 * gives access to the result of the look up.
 */
class ExportedByVisuDialogEx CATVidActionBarIconArgs : public CATSYPEventArgs
{
public:
  /**
   * Constructor
   *
   * @param i_pEvent event associated to this argument (not used for the icons
   * look up).
   * @param i_iconName name of the icon to get its full path.
   */
  CATVidActionBarIconArgs(CATSYPEvent * i_pEvent, const CATUnicodeString & i_iconName);
  /**
   * Destructor
   */
  virtual ~CATVidActionBarIconArgs();

  /**
   * Get the name of the icon to look for.
   *
   * @return the name of the icon to look for.
   */
  const CATUnicodeString & GetIconName() const;
  /**
   * Set the computed full path of the icon to look for.
   *
   * @param i_iconFullPath the computed full path found for the icon.
   */
  void SetIconFullPath(const CATUnicodeString & i_iconFullPath);
  /**
   * Get the computed full path of the icon.
   *
   * @return the computed full path of the icon.
   */
  const CATUnicodeString & GetIconFullPath() const;

private:
  // Not implemented
  CATVidActionBarIconArgs(const CATVidActionBarIconArgs &);
  CATVidActionBarIconArgs & operator=(const CATVidActionBarIconArgs &);

  // Name of the icon to look for
  CATUnicodeString _iconName;
  // Computed full path of the icon
  CATUnicodeString _iconFullPath;
};

#endif
