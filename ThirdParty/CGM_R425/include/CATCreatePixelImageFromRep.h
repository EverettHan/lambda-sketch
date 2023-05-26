#ifndef CATCreatePixelImageFromRep_H
#define CATCreatePixelImageFromRep_H

// COPYRIGHT DASSAULT SYSTEMES 2002

// Local Framework
#include "CATVisController.h"
// Local Framework
class CATRep;
class CATPixelImage;
class CATVizDisplayContext;
class CATRepPath;
class CATBoundingElement;
class CAT2DBoundingBox;
class CAT3DBoundingSphere;
// Dialog Framework
class CATDialog;
// Mathematics Framework
class CATMathDirectionf;

// Create a CATPixelImage from CATRep
/** @nodoc */
ExportedByCATVisController CATPixelImage* CreatePixelImageFromRep(CATDialog* ipParent, CATRep* ipRep, int iWidth, int iHeight, CATVizDisplayContext* iVdc = NULL);

// Create a CATPixelImage from CATRepPath
/** @nodoc */
ExportedByCATVisController CATPixelImage* CreatePixelImageFromRepPath(CATRepPath* ipRepPath, float iDpi,
																																		CAT2DBoundingBox& oBoundingElement, unsigned int& oPixelImageWidth, unsigned int& oPixelImageHeight, float& oDpi);
/** @nodoc */
ExportedByCATVisController CATPixelImage* CreatePixelImageFromRepPath(CATRepPath* ipRepPath, float iDpi,
																																			CAT3DBoundingSphere& oBoundingElement, unsigned int& oPixelImageWidth, unsigned int& oPixelImageHeight, float& oDpi);
/** @nodoc */
ExportedByCATVisController CATPixelImage* CreatePixelImageFromRepPath(CATRepPath* ipRepPath, const CATMathDirectionf& iLocalNormal, float iDpi, 
																																			CAT3DBoundingSphere& oBoundingElement, unsigned int& oPixelImageWidth, unsigned int& oPixelImageHeight, float& oDpi);

/** @nodoc */
ExportedByCATVisController CATPixelImage* CreatePixelImageFromRepPath(CATRepPath* ipRepPath, 
																																			const CATBoundingElement& iBoundingElement, unsigned int iPixelImageWidth, unsigned int iPixelImageHeight);
/** @nodoc */
ExportedByCATVisController CATPixelImage* CreatePixelImageFromRepPath(CATRepPath* ipRepPath, const CATMathDirectionf& iLocalNormal, 
																																			const CATBoundingElement& iBoundingElement, unsigned int iPixelImageWidth, unsigned int iPixelImageHeight);

#endif

