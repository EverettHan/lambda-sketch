// COPYRIGHT DASSAULT SYSTEMES 1999

#ifndef CATManageDefaultAttributesRepository_H
#define CATManageDefaultAttributesRepository_H

#include "CATVisItf.h"      
#include "CATIVisProperties.h"
#include "CATRenderingAttribut.h"
#include "CATErrorDef.h"


//----------------------------------------------------------------------------
// activation generale

extern ExportedByCATVisItf int CATGetDefaultVPActivation();
extern ExportedByCATVisItf void CATSetDefaultVPActivation(const unsigned int iActivation);

//----------------------------------------------------------------------------
// color

extern ExportedByCATVisItf int CATGetColor(const CATVisGeomType,
                                                  unsigned int *,
                                                  unsigned int *,
                                                  unsigned int *);
extern ExportedByCATVisItf void CATSetColor(const CATVisGeomType,
                                                   const unsigned int,
                                                   const unsigned int,
                                                   const unsigned int);

extern ExportedByCATVisItf void CATGetDefaultCreationColor( 
                                                  unsigned int& oRed,
                                                  unsigned int& oGreen,
                                                  unsigned int& oBlue,
                                                  unsigned int& oActivation);
extern ExportedByCATVisItf void CATSetDefaultCreationColor(
                                                   unsigned int iRed,
                                                   unsigned int iGreen,
                                                   unsigned int iBlue,
                                                   unsigned int iActivation);

//----------------------------------------------------------------------------
// linetype

extern ExportedByCATVisItf int CATGetDashed(const CATVisGeomType,
                                                   unsigned int *);
extern ExportedByCATVisItf void CATSetDashed(const CATVisGeomType,
                                                    const unsigned int);

extern ExportedByCATVisItf void CATGetDefaultCreationLineType( 
                                                  unsigned int& oLineType,
                                                  unsigned int& oActivation);
extern ExportedByCATVisItf void CATSetDefaultCreationLineType(
                                                   unsigned int iLineType,
                                                   unsigned int iActivation);

//----------------------------------------------------------------------------
// Width
    
extern ExportedByCATVisItf int CATGetWeight(const CATVisGeomType,
                                                   unsigned int *);
extern ExportedByCATVisItf void CATSetWeight(const CATVisGeomType,
                                                    const unsigned int);

extern ExportedByCATVisItf void CATGetDefaultCreationWidth( 
                                                  unsigned int& oWidth,
                                                  unsigned int& oActivation);
extern ExportedByCATVisItf void CATSetDefaultCreationWidth(
                                                   unsigned int iWidth,
                                                   unsigned int iActivation);

//----------------------------------------------------------------------------
// SymbolType  

extern ExportedByCATVisItf int CATGetSymbol(const CATVisGeomType,
                                                   unsigned int *);
extern ExportedByCATVisItf void CATSetSymbol(const CATVisGeomType,
                                                    const unsigned int);

extern ExportedByCATVisItf void CATGetDefaultCreationSymbolType( 
                                                  unsigned int& oSymbolType,
                                                  unsigned int& oActivation);
extern ExportedByCATVisItf void CATSetDefaultCreationSymbolType(
                                                   unsigned int iSymbolType,
                                                   unsigned int iActivation);

//----------------------------------------------------------------------------
// Opacity
    
extern ExportedByCATVisItf int CATGetOpacity(const CATVisGeomType,
                                                    unsigned int *);
extern ExportedByCATVisItf void CATSetOpacity(const CATVisGeomType,
                                                     const unsigned int);

extern ExportedByCATVisItf void CATGetDefaultCreationOpacity( 
                                                  unsigned int& oOpacity,
                                                  unsigned int& oActivation);
extern ExportedByCATVisItf void CATSetDefaultCreationOpacity(
                                                   unsigned int iOpacity,
                                                   unsigned int iActivation);

//----------------------------------------------------------------------------
// RenderingStyle

extern ExportedByCATVisItf void CATGetDefaultCreationRS(CATRenderingAttribut& oRS, unsigned int& oActivation);
extern ExportedByCATVisItf void CATSetDefaultCreationRS(CATRenderingAttribut iRS, unsigned int iActivation);



//----------------------------------------------------------------------------
// Layer

extern ExportedByCATVisItf unsigned int CATGetLayer();
extern ExportedByCATVisItf  void CATSetLayer(const unsigned int, int iComputeVisu=1);

extern ExportedByCATVisItf unsigned int CATGetLayerLight();
extern ExportedByCATVisItf  void CATSetLayerLight(const unsigned int, int iComputeVisu=1);


extern ExportedByCATVisItf void CATSaveDefaultAttributesRepository();
extern ExportedByCATVisItf void CATCommitDefaultAttributesRepository();
extern ExportedByCATVisItf void CATInitializeDefaultAttributesRepository();
extern ExportedByCATVisItf void CATRollbackDefaultAttributesRepository();

#endif
