/* -*-C++-*-*/
#ifndef CATConvertBodyToGeoPolyBody_H
#define CATConvertBodyToGeoPolyBody_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2022
//
// CATConvertBodyToGeoPolyBody 
//
// DESCRIPTION :
// Utility class to convert CATBody with matrix into CATGeoPolyBody instance
// The conversion of a same entity with several matrices will lead to generate
// several CATGeoPolyBody instances referencing a common shared CATPolyBody
//
//=============================================================================

// For Windows NT export
#include "CATPGMConvertBodyToGeoPolyBody.h" // derivation
#include "GMPolyImportExport.h"       // ExportedBy

#include "CATErrorDef.h"              // HRESULT
#include "CATSysDataType.h"           // NULL
#include "CATTopDefine.h"             // CATOrientation

#include "CATBoolean.h" 
#include "CATSysBoolean.h" 

#include "CATCollec.h"
#include "CATListPV.h"
#include "CATListOfInt.h"
#include "ListPOfCATCell.h"
#include "CATListOfCATCells.h"

class CATGeoFactory;
class CATSoftwareConfiguration;
class CATMathTransformation;
class CATMapOfIntToInt;

class CATBody;
class CATPolyBody;
class CATGeoPolyBody;
class CATIPolySurface;


/**
* Please, note that the convention of matter side for a CATShell bounding a CATVolume is INWARD,
* opposite to the PolyBody convention  which is always OUTWARD.
* So, importing a volumic set of PolyFaces obviously leads to reverse the global side of the imported CATDomain.
* The default behavior in case of surfacic set of faces consists in reversing the original sides as if the domain was volumic.
*/

class ExportedByGMPolyImportExport CATConvertBodyToGeoPolyBody : public CATPGMConvertBodyToGeoPolyBody
{
protected:

  /**
  * Protected constructor for derivation (private use only)
  * Please use CATCreateConvertBodyToGeoPolyBody
  */
  CATConvertBodyToGeoPolyBody();

public:

  /**
  * Destructor
  */
  virtual ~CATConvertBodyToGeoPolyBody();


  //=============================================================================
  // Settings
  //=============================================================================
   

  /** @nodoc @nocgmitf */
  // Please, note here that the convention of matter side for a CATShell bounding a CATVolume is INWARD,
  // opposite to the PolyBody convention  which is always OUTWARD.
  // So, importing a volumic set of PolyFaces obviously leads to reverse the global side of the imported CATDomain.
  // The default behavior in case of surfacic set of faces consists in reversing the original sides as if the domain was volumic.
  // The following option allows the user to keep (Positive) or not (Negative) the global orientation of surfacic shells only.
  // Default is Positive if this API is not called
  virtual void SetMeshOrientationVsSurfacicShell(CATOrientation iOriMeshVsShell) = 0;


  //=============================================================================
  // Computation
  //=============================================================================


  /**
  * @param iBodyToConvert
  * The input CATBody to convert into a CATGeoPolyBody
  * In case of continuous (exact) CATBody, a default tessellation will be applied.
  * @param iMatrix
  * The optional matrix associated to iBodyToConvert which will be included in the output CATGeoPolyBody.
  * @param iExclusiveMode
  * In default mode (not exclusive), the converter will retain the input CATBody and its associated CATPolyBody 
  *    in order to reuse it if the Run is recalled with another matrix associated to the same input CATBody.
  * In exclusive mode, the data won't be retained by the converter, the association won't be recorded, 
  *    a new CATPolyBody will be generated and won't be shared with any other CATGeoPolyBody.
  * @return [CATGeoPolyBody*]
  * The pointer to the generated CATGeoPolyBody,
  * to be removed after use from the CATGeoFactory with its Remove() API.
  */
  virtual CATGeoPolyBody * Run(CATBody * iBodyToConvert, const CATMathTransformation * iMatrix=NULL, CATBoolean iExclusiveMode=FALSE) = 0;


private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATConvertBodyToGeoPolyBody(const CATConvertBodyToGeoPolyBody & iOneOf); 
  CATConvertBodyToGeoPolyBody & operator =(const CATConvertBodyToGeoPolyBody & iOneOf);

};

/**
* Creates a CATPGMConvertBodyToGeoPolyBody.
* @param iTargetFactory
* The factory used to build the output CATGeoPolyBody
* can be different from the factory attached to the CATBody to convert
* @param iSoftwareConfig
* The pointer to the SoftwareConfiguration in order to drive the versionning of future modifications
* opened configuration (CGMVersion=LastCGMLevel) will be considered if iSoftwareConfig is set to null
* @return [out]
* The pointer to the created operator. To be deleted after use.
*/
ExportedByGMPolyImportExport CATConvertBodyToGeoPolyBody * CATCreateConvertBodyToGeoPolyBody(CATGeoFactory * iTargetFactory, CATSoftwareConfiguration * iSoftwareConfig); 

#endif
