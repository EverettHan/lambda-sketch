/* -*-C++-*-*/
#ifndef CATGeoPolyBodyBuilder_H
#define CATGeoPolyBodyBuilder_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2022
//
// CATGeoPolyBodyBuilder 
//
// DESCRIPTION :
// Utility class to convert CATPolyBody / CATIPolySurface instances ...
// ... with matrix into CATGeoPolyBody instances
// The conversion of a same entity with several matrices will lead to generate
// several CATGeoPolyBody instances referencing a common shared CATPolyBody
//
//=============================================================================

// For Windows NT export
#include "CATPGMGeoPolyBodyBuilder.h" // derivation
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

class CATPolyBody;
class CATGeoPolyBody;
class CATIPolySurface;



class ExportedByGMPolyImportExport CATGeoPolyBodyBuilder : public CATPGMGeoPolyBodyBuilder
{
protected:

  /**
  * Protected constructor for derivation (private use only)
  * Please use CATCreateGMGeoPolyBodyBuilder
  */
  CATGeoPolyBodyBuilder();

public:

  /**
  * Destructor
  */
  virtual ~CATGeoPolyBodyBuilder();


  //=============================================================================
  // Settings
  //=============================================================================
   

  //=============================================================================
  // Computation
  //=============================================================================

  /**
  * @param iPolyBodyToConvert
  * The input CATPolyBody to convert into a CATGeoPolyBody
  * If the input CATPolyBody is not native, a duplication will be applied into a native one.
  * @param iMatrix
  * The optional matrix associated to iPolyBodyToConvert which will be included in the output CATGeoPolyBody.
  * @param iExclusiveMode
  * In default mode (not exclusive), if the input CATPolyBody is not native, 
  *    the builder will retain the input CATPolyBody and its associated native CATPolyBody 
  *    in order to reuse it if the Run is recalled with another matrix.
  * In exclusive mode, the data won't be retained by the builder, the association won't be recorded, 
  *    a new CATPolyBody will be generated and won't be shared with any other CATGeoPolyBody.
  * The exclusive mode will be ignored in case of native CATPolyBody.
  * @return [CATGeoPolyBody*]
  * The pointer to the generated CATGeoPolyBody,
  * to be removed after use from the CATGeoFactory with its Remove() API.
  */
  virtual CATGeoPolyBody * Run(CATPolyBody * iPolyBodyToConvert, const CATMathTransformation * iMatrix=NULL, CATBoolean iExclusiveMode=FALSE) = 0;

    
  /**
  * @param iPolySurfaceToConvert
  * The input mesh to convert into a CATGeoPolyBody
  * If the input CATIPolySurface is not native, a duplication will be applied into a native one.
  * @param iMatrix
  * The optional matrix associated to iPolySurfaceToConvert which will be included in the output CATGeoPolyBody.
  * @param iExclusiveMode
  * In default mode (not exclusive), the builder will retain the input CATIPolySurface and its associated CATPolyBody 
  *    in order to reuse it if the Run is recalled with another matrix associated to the same input CATIPolySurface.
  * In exclusive mode, the data won't be retained by the builder, the association won't be recorded, 
  *    a new CATPolyBody will be generated and won't be shared with any other CATGeoPolyBody.
  * @return [CATGeoPolyBody*]
  * The pointer to the generated CATGeoPolyBody,
  * to be removed after use from the CATGeoFactory with its Remove() API.
  */
  virtual CATGeoPolyBody * Run(CATIPolySurface * iPolySurfaceToConvert, const CATMathTransformation * iMatrix=NULL, CATBoolean iExclusiveMode=FALSE) = 0;


private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGeoPolyBodyBuilder(const CATGeoPolyBodyBuilder & iOneOf); 
  CATGeoPolyBodyBuilder & operator =(const CATGeoPolyBodyBuilder & iOneOf);

};

/**
* Creates a CATPGMGeoPolyBodyBuilder.
* @param iTargetFactory
* The factory used to build the output CATGeoPolyBody
* @param iSoftwareConfig
* The pointer to the SoftwareConfiguration in order to drive the versionning of future modifications
* opened configuration (CGMVersion=LastCGMLevel) will be considered if iSoftwareConfig is set to null
* @return [out]
* The pointer to the created operator. To be deleted after use.
*/
ExportedByGMPolyImportExport CATGeoPolyBodyBuilder * CATCreateGeoPolyBodyBuilder(CATGeoFactory * iTargetFactory, CATSoftwareConfiguration * iSoftwareConfig); 

#endif
