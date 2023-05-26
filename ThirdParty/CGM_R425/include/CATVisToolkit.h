#ifndef CATVisToolkit_H
#define CATVisToolkit_H

// COPYRIGHT DASSAULT SYSTEMES 2005

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


//------------------------------------------------------------------------------
// Abstract: Provide services for 
//             - retrieving the size in millimeter of line thickness within a given
//                viewer.
//             - retrieving the size in pixel of line thickness within a given
//                viewer.
//           
//
//------------------------------------------------------------------------------
// Usage:    Line Thickness is stored within the graphical properties of V5 objects.
//             Line thickness is defined by an index which refers to a contextual
//             table. This table is a mapping table defining:
//                - the pixel width used for displaying a given line thickness onto
//                   the screen.
//                - the millimeter width used for plotting a given line thickness onto
//                   printers.
//           This mapping table is contextual since it can be different for each documents.
//           Contextual means 'related to a given window' that is to say the window which
//           is displaying a given document.
//------------------------------------------------------------------------------
// Inheritance: None
//------------------------------------------------------------------------------
// Main methods:    
//
//           sCATGetMMThicknessFromViewer
//           sCATGetPixelThicknessFromViewer
//=============================================================================
// Function:
//
//=============================================================================
// Usage Notes:
//
//=============================================================================

#include "IUnknown.h"
#include "CATVisController.h"

class CATViewer;

/**
 * Maximum Number of line thicknesses.
 */ 
#define NB_VISU_LINETHICKNESS 63


/**
 * Gets the millimeter width of a given line thickness.
 * @param iViewer 
 *   The viewer which defines the 'display context' of a document.
 * @param iIndex 
 *   The index value defining a line thickness (defined within graphical properties of V5 objects).
 * @param oMMWidth
 *   The returned value in millimeter of line thickness.
 * @return 
 *   <dl>
 *   <dt><tt>S_OK</tt>      <dd>if the query succeeds
 *   <dt><tt>E_FAILED</tt>  <dd>if the query fails.
 *   </dl>
 * @see CATViewer
 */
 extern  ExportedByCATVisController HRESULT sCATGetMMThicknessFromViewer(CATViewer & iViewer, const int iIndex, float &oMMWidth);
 
 /**
 * Gets the pixel width of a given line thickness.
 * @param iViewer 
 *   The viewer which defines the 'display context' of a document.
 * @param iIndex 
 *   The index value defining a line thickness (defined within graphical properties of V5 objects).
 * @param oPixelWidth
 *   The returned value in pixel of line thickness.
 * @return 
 *   <dl>
 *   <dt><tt>S_OK</tt>      <dd>if query succeeds
 *   <dt><tt>E_FAILED</tt>  <dd>if query fails.
 *   </dl>
 * @see CATViewer
 */
 extern  ExportedByCATVisController HRESULT sCATGetPixelThicknessFromViewer(CATViewer & iViewer, const int iIndex, int &oPixelWidth);


 
 /**
 * Force dyanmic mode's activation on a CATViewer.
 * When dynamic mode is activated, various rendering quality options (like Full Scene Antialiasing
 * or SSAO) are deactivated or degraded to improve visualization frame rate.
 * @param iViewer 
 *   The viewer which defines the 'display context' of a document.
 * @param iOnOff 
 *   Flag to activate or deactivate dynamic mode on a viewer. 
 *   Each call to "sCATVisForceDynamicMode(1)" has to be followed later by a call to "sCATVisForceDynamicMode(0)"
 *   to restore previous configuration.
 * @return 
 *   <dl>
 *   <dt><tt>S_OK</tt>      <dd>if query succeeds
 *   <dt><tt>E_FAILED</tt>  <dd>if query fails.
 *   </dl>
 * @see CATViewer
 */
 extern  ExportedByCATVisController HRESULT sCATVisForceDynamicMode(CATViewer & iViewer, int iOnOff);




#endif

