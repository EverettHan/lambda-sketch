#ifndef CATVIZCREATEANIMATIONFROMMNGFILE_H
#define CATVIZCREATEANIMATIONFROMMNGFILE_H

//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2007
//------------------------------------------------------------------------------
// Abstract : This provides services around MNG files
//------------------------------------------------------------------------------
//  Usage : 
//
//   CreateAnimationFromMNGFile:
//   A animation is created from MNG file.
//------------------------------------------------------------------------------

#include "CATMMediaPixelImage.h"

// Local Framework
class CATVizPixelImageAnimation;

// System Framework
#include "CATUnicodeString.h"

	/**
	 * Creates an animation from a MNG file.
	 * @param iMNGFilePath
	 *   The file to create the animation from.
	 *   <br>Recognized formats are : MNG.
	 * @return
	 * <dl>
	 *  <dt>A new <tt>CATVizPixelImageAnimation</tt>.</dt>
	 * </dl>
	 */
	ExportedByCATMMediaPixelImage CATVizPixelImageAnimation* CreateAnimationFromMNGFile(const CATUnicodeString& iMNGFilePath);

	
#endif

