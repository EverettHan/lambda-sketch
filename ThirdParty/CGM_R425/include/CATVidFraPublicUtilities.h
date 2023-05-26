#ifndef CATVidFraPublicUtilities_h
#define CATVidFraPublicUtilities_h

// COPYRIGHT DASSAULT SYSTEMES 2015

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

// VisuImmersiveDialog framework
#include <VisuDialog.h>

// System framework
#include <CATString.h>

class CATViewer;

/**
 * Docks the window identified by the given name in the given viewer at the expected docking side.
 * @param i_pViewer the viewer containing the window
 * If the passed i_pViewer is NULL, this method will search in all the viewers.
 * @param i_windowName the window name
 * @param i_side the docking side
 *  0 : left
 *  1 : top
 *  2 : right
 *  3 : bottom
 * @return S_OK if the window has been retrieved and succesfully docked, E_FAIL otherwise.
 */
ExportedByVisuDialog HRESULT CATVidDockWindow(CATViewer* i_pViewer, const CATString& i_windowName, unsigned int i_side);

#endif // CATVidFraPublicUtilities_h
