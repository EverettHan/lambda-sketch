/* -*-C++-*-*/
#ifndef CATGMPolyOperUtil_H
#define CATGMPolyOperUtil_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2015
//
// CATGMPolyOperUtil 
//
// DESCRIPTION :
// 
// 
// 
//
//
// History
//
// January. 2016 KY1 Creation
// Oct. 2016 DPS Add ConvertPolyBodyToExactBody
// Oct. 2019 DPS Add EstimateTopoAreaOrientation
//
//=============================================================================

#include "GMPolyImportExport.h" // ExportedBy
#include "IUnknown.h"
#include "CATTopData.h"
#include "CATTopDefine.h"
#include "CATCGMJournal.h"
#include "CATCollec.h"
#include "CATErrorDef.h"


class CATGeoFactory;
class CATBody;
class CATGeometry;
class CATMathDirection;
class CATMathAdvancedBox;
class CATSoftwareConfiguration;
class CATTopology;
class CATPolyBody;
class CATGeoPolyBody;


/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyImportExport CATGMPolyOperUtil
{
public:

  
  /**
  * @nodoc
  * @nocgmitf
  * Convert an Exact CATBody to a polyhedral CATBody. 
  * <br>Limitation :  allowed only on specific factory that wear a dedicated flag
  * <br>Remarks : ..... 
  */
  static CATBody *ConvertExactBodyToPolyBody(CATGeoFactory *piFactory, CATTopData &iTopData, CATBody *piExactBody, const CATCGMJournal::Type & iJournalType = CATCGMJournal::Creation);

  /**
  * @nodoc
  * @nocgmitf
  * Convert a CATBody (exact or polyhedral) to a CATGeoPolyBody.
  * iTargetFactory can be different from the one containing iBodyToConvert (choosen by default if null)
  * <br>Limitation :  allowed only on specific factory that wear a dedicated flag
  * <br>Remarks : ..... 
  */
  static CATGeoPolyBody * ConvertBodyToGeoPolyBody(CATBody * iBodyToConvert, CATGeoFactory * iTargetFactory=NULL, CATSoftwareConfiguration * iConfig = NULL);

  /**
  * @nodoc
  * @nocgmitf
  * Convert a CATPolyBody (native or not) into a CATGeoPolyBody.
  * iTargetFactory is a mandatory argument
  * <br>Limitation :  allowed only on specific factory that wear a dedicated flag
  * <br>Remarks : ..... 
  */
  static CATGeoPolyBody * ConvertPolyBodyToGeoPolyBody(CATPolyBody * iPolyBodyToConvert, CATGeoFactory * iTargetFactory, CATSoftwareConfiguration * iConfig = NULL);

  /**
  * @nodoc
  * @nocgmitf
  * Convert a polyhedral body into an exact Body. 
  * <br>Limitation : each bar of input polylines will generate an exact linear edge, surfacic & volumic bodies are not supported
  * <br>Remarks : ..... 
  */
  static CATBody *ConvertPolyBodyToExactBody(CATGeoFactory *piFactory, CATTopData &iTopData, CATBody *piPolyhedralBody, const CATCGMJournal::Type & iJournalType = CATCGMJournal::Creation, 
                                             CATLISTP(CATGeometry) * oReportedImages=NULL);


  /**
  * @nodoc @nocgmitf
  * See also TopologicalOperatorsLight\ProtectedInterfaces\TopologicalUtilities.h for the CGM integration and interfacing.
  * The main purpose of this static function consists in guessing the global orientation of a topological object in regards with a given direction.
  * This function will compute signed areas from the boundary of the object and won't depend on any local evaluation of normal, 
  * avoiding this way many unstabilities due to the randomly choice of one reference point from the topological object.
  * The caller is supposed to use this service for open surfacic bodies, faces or closed wire bodies (according to the 'turns left' convention), 
  * defining a closed area from their boundaries unfold in a mathematical plane (whose the normal is the input direction)
  * In case of conflict between positive and negative areas, the biggest one will give its sign to the returned orientation.
  * In case of perfect balance between negative and positive areas, or if no area can be computed (vertical face asking its orientation in Z direction),
  * the output orientation will be CATOrientationUnknown !
  * This service is available for both exact and polyhedral objects.
  * @param iConfig
  * The pointer to the software configuration driving the versionning of code modifications
  * @param iTopObject
  * The topological object defining a closed oriented area : 
  * open CATShell, open CATFace, CATLoop (if not full), closed CATWire, or CATBody containing open Shells or closed Wires
  * all other types of topological objects (like points or volumes) will be refused (returning E_FAIL)
  * @param iRefDirection
  * The reference direction used to compute the signed area onto a plane (whose the normal is this direction)
  * @param oTopoAreaOrientation
  * CATOrientationPositive if the sum of positive areas is bigger than the negative one(s),
  * CATOrientationNegative if the sum of negative areas is bigger than the positive one(s),
  * CATOrientationUnknown if the computed area is null or perfectly balanced between negative and positive areas,
  * @return 
  * E_FAIL if the request doesn't make sense because the input topological object doesn't define any oriented area,
  * S_FALSE if the returned orientation is Unknown after computation on a valid input,
  * S_OK if a positive or negative orientation has been computed and returned
  */
  static HRESULT EstimateTopoAreaOrientation(CATSoftwareConfiguration * iConfig, CATTopology * iTopObject, const CATMathDirection & iRefDirection, 
                                             CATOrientation & oTopoAreaOrientation);

  /**
  * @nodoc @nocgmitf
  * See also TopologicalOperatorsLight\ProtectedInterfaces\TopologicalUtilities.h for the CGM integration and interfacing.
  * The main purpose of this function consists in computing the advanced bounding box of a topological object.
  * The optional direction allows the caller to force the output box to be an extrusion of a 2D-Box in this input direction
  * The returned AdvancedBox might wrap an OBB, an OBBCloud or an AABB according to the specification of the smallest bounding box.
  * see CATMathAdvancedBoxTypeEnum.h for the different types, CATMathOBB2DType is not supported by this function
  * This service is available for both exact and polyhedral objects.
  * @param iConfig
  * The pointer to the software configuration driving the versionning of code modifications
  * @param iTopObject
  * The topological object defining a bounding box : 
  * CATBody, CATDomain, CATCell
  * @return 
  * The pointer to the computed CATMathAdvancedBox, to be deleted by the caller after use
  * Null if the request doesn't make sense because the input topological object doesn't define any bounding box (empty body ?)
  * 3 possible types (CATMathAdvancedBoxType) for the returned CATMathAdvancedBox
  * CATMathAABBType     Axis Aligned Bounding Box
  * CATMathOBBType      Oriented Bounding Box
  * CATMathOBBCloudType Oriented Bounding Box Tree
  *(CATMathOBB2DType    not supported by this function)
  */
  static CATMathAdvancedBox * ComputeTopMathAdvancedBox(CATSoftwareConfiguration * iConfig, CATTopology * iTopObject);
};


#endif
