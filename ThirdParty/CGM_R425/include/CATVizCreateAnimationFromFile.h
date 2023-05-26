#ifndef CATVIZCREATEANIMATIONFROMFILE_H
#define CATVIZCREATEANIMATIONFROMFILE_H

//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2016
//------------------------------------------------------------------------------
// Abstract : This provides services around Animated files
//------------------------------------------------------------------------------
//  Usage : 
//
//   CreateAnimationFromMNGFile :
//   A animation is created from MNG file.
//   OR
//   CreateAnimationFromGIFFile :
//   A animation is created from GIF file.
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
	ExportedByCATMMediaPixelImage CATVizPixelImageAnimation* CreateAnimationFromFile(const CATUnicodeString& iFilePath);

	
#endif



