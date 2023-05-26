#ifndef CATLISTOFCATPIXELIMAGE_H
#define CATLISTOFCATPIXELIMAGE_H

// COPYRIGHT DASSAULT SYSTEMES 2007

/**
 * @collection CATLISTP(CATPixelImage)
 * Collection class for pointers to <tt>CATPixelImage</tt>.
 * All the methods of pointer collection classes are available.
 * Refer to the articles dealing with collections in the encyclopedia.
 * @see CATPixelImage
 */

#include "CATLISTP_Clean.h"

#define CATLISTP_Append
#define CATLISTP_RemovePosition
#define CATLISTP_RemoveAll
#define CATLISTP_Swap

#include "CATPixelImage.h"
#include "CATLISTP_Declare.h"

#undef  CATCOLLEC_ExportedBy
//#define CATCOLLEC_ExportedBy ExportedByCATVisFoundation
#define CATCOLLEC_ExportedBy ExportedByCATMMediaPixelImage

CATLISTP_DECLARE(CATPixelImage);

#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy

#endif
