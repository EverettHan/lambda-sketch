// COPYRIGHT Dassault Systemes 20011
//=============================================================================
//
// CATVidSystemServices.h
// Header definition of CATVidSystemServices
//
//=============================================================================
//  2011  Creation: LD5
//=============================================================================
#ifndef CATVidSystemServices_H
#define CATVidSystemServices_H

#include <CATUnicodeString.h>
#include <VisuDialog.h>
#include <CATVidURL.h>
#include <CATMathPoint2Df.h>
class CATVizViewer;

/**
 * @ingroup VIDCore
 */
/**
 * Class for all system-related VID services. 
 */
class ExportedByVisuDialog CATVidSystemServices
{
public:
  /**
   * Find the position of the mouse pointer inside a viewer, in dp (device
   * independant pixels = pixels divided by density). Typical use in a
   * @c CATVidWidget or a @c CATVidFraWindow :
   *
   * @code
   * CATMathPoint2Df pos = CATVidSystemServices::GetMousePosition(GetViewer());
   * @endcode
   *
   * @param i_pViewer the viewer to consider.
   *
   * @return the position of the mouse inside the viewer if @c i_pViewer is
   * not @c NULL, <tt>(0, 0)</tt> else.
   */
  static CATMathPoint2Df GetMousePosition(CATVizViewer * i_pViewer);

  /**
   * @param i_pWidget a widget. Must not be @c NULL. @c AddRef will not be 
   * called.
   *
   * @return the current position of the mouse inside the input widget.
   */
  static CATMathPoint2Df GetMousePositionInWidget(CATVidWidget * i_pWidget);

  /**
  * Determins if mouse position is inside a window border. 
  * Note that this service works correctly only on Window
  *
  * @param i_pWindow a window. Must not be @c NULL @c AddRef will not be 
  * called.
  *
  * @return @c TRUE if the current mouse position is inside the input window,
  * @c FALSE else.
  */
  static CATBoolean IsMousePositionInWindow(CATVidFraWindow* i_pWindow);

  /** 
   * Open a URL on Windows or Unix stations. Does not work on MacOS yet.
   *
   * @param i_URL the URL to open
   *
   * @return @c TRUE if the URL has been opened, @c 0 else.
   *
   * @see CATVidURL
   */
  static CATBoolean OpenURL(const CATVidURL& i_URL);

  static int IsRecord();

	/**
	* Get the density of the display.
	*
	* This method is a shortcut to calling @ref #GetDisplay and then
	* @ref CATVidDisplay#GetDensity.
	*
	* @return the density.
	*/
	static float GetDensity(CATVizViewer *i_pVizViewer);

protected:
  /**
   * Destructor. 
   *
   * @c CATVidSystemServices contains exclusively static functions: it is not 
   * meant to be instantiated.
   */
  virtual ~CATVidSystemServices() {}


private:

#ifdef _WINDOWS_SOURCE
  /**
   * Load a file with the default program of the system for this kind of file
   * if we are on a windows station. Does nothing else.
   *
   * @param i_URL the URL to open
   *
   * @return @c TRUE if the file has been loaded, @c 0 else.
   *
   * @see CATVidURL
   */
  static CATBoolean OpenWithDefaultProgramOnWindows(const CATVidURL& i_URL);
#elif defined(_LINUX_SOURCE) || defined(_IRIX_SOURCE) || defined(_HPUX_SOURCE) || defined(_AIX_SOURCE) || defined(_SUNOS_SOURCE)
  /** 
   * Open a URL if we are on a Unix station. Does nothing else.
   *
   * @param i_URL the URL to open
   *
   * @return if the URL has been opened, @c 0 else.
   *
   * @see CATVidURL
   * @see CATVidURL#IsValid
   */
  static CATBoolean OpenURLOnUnix(const CATVidURL& i_URL);
#endif

  /**
   * Constructor. 
   *
   * @c CATVidSystemServices contains exclusively static functions: it is not 
   * meant to be instantiated.
   */
  CATVidSystemServices() {}
  /**
   * Copy constructor. 
   *
   * @c CATVidSystemServices contains exclusively static functions: it is not 
   * meant to be instantiated.
   */
  CATVidSystemServices(const CATVidSystemServices &i_original);
  /**
   * Equal operator. 
   *
   * @c CATVidSystemServices contains exclusively static functions: it is not 
   * meant to be instantiated.
   */
  CATVidSystemServices& operator=(const CATVidSystemServices& i_original);
};
//-----------------------------------------------------------------------------
#endif
