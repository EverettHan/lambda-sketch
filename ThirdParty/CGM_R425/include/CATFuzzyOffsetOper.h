// COPYRIGHT DASSAULT SYSTEMES 2003-2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATFuzzyOffsetOper.h
// Header definition of CATFuzzyOffsetOper
//
// This class contains the function that calculates an offset mesh from 
// an input polygonal mesh. (Polyhedral offset only.)
//===================================================================
/**
* @CAA2Usage U0
**/
//===================================================================
//
// Sept 2003  Creation: LVL, NDO
//===================================================================
#ifndef CATFuzzyOffsetOper_H
#define CATFuzzyOffsetOper_H

#include "CATFuzzyOperators.h"
#include "CATBaseUnknown.h"
#include "CATListOfInt.h"
#include "CATBoolean.h"
#include "CATIACGMLevel.h"

class CATSoftwareConfiguration;
class CATMathPoint;
class CATFuzVolRep;
class CATIPolyMesh;

#ifdef CATIACGMV5R17
class CATCGMProgressBar;
#else
class CATCldPolygon;
class CATGeoFactory;
class CATPolyCallback;
#endif


/**
* This class performs a polyhedral fuzzy offset from a polygonal mesh.<br>
**/

class ExportedByCATFuzzyOperators CATFuzzyOffsetOper : public CATBaseUnknown
{

  CATDeclareClass;
	
public:

  //==============================================================================
  // Constructor 
  //==============================================================================
  /**
  * This is the constructor of the fuzzy offset operator that should be used.
  * @param iSoftwareConfiguration
  *   The software configuration.
  * @param iInputMesh
  *   The input polyhedral mesh from which the offset mesh is calculated.
  * @param oResultMesh
  *   The result mesh.  This should be an empty mesh that will be filled in 
  *   during computation of the offset.
  */
  CATFuzzyOffsetOper (CATSoftwareConfiguration* iSoftwareConfiguration,
                      CATIPolyMesh* iInputMesh, CATIPolyMesh* oResultMesh);

  //==============================================================================
  // Destructor 
  //==============================================================================
  /**
  * Standard destructor.<br>
  **/
  virtual ~CATFuzzyOffsetOper ();
  
  //==============================================================================
  // Public set methods 
  //==============================================================================

  void SetActiveBoundingBox (const CATMathPoint& iMinPoint, const CATMathPoint& iMaxPoint);

  void SetOffsetSize (const double iOffsetSize);

  void SetVoxelSize (const double iVoxelSize);

  /**
  * Sets on or off the post-sharpening corrections of the offset polygonal mesh.
  * @param sharpen
  *   <tt> TRUE </tt> to turn on the correction.
  *   <tt> FALSE </tt> to turn off the correction.
  **/
  void SetSharpeningCorrections (const CATBoolean sharpen);

  /**
  * Sets the callback instance that is called to track progress during the Run () method.
  **/
#ifdef CATIACGMV5R17
  void SetCallback (CATCGMProgressBar* callback);
#else
  void SetCallback (CATPolyCallback* callback);
#endif  

  //==============================================================================
  // Run method 
  //==============================================================================

  /**
  * Performs the polyhedral fuzzy offset. Three modes are available:
  * Mode 0: One-sided offset. No extension of the mesh borders. This is the default mode.
  * Mode 1: Two-sided offset. A closed mesh is calculated as a shell around the input mesh.
  * Mode 2: One-sided offset. The mesh is calculated with extension of its borders (rounded borders.) 
  **/
  CATBoolean Run (const int iMode = 0);

  //==============================================================================
  // Public get methods 
  //==============================================================================

  /**
  * Returns a list of flags (one for each vertex) set to 0 if the vertex is not near a sharp edge and 
  * to 1 if the vertex is a sharp edge.  This list of flags can be used for post-sharpening correction
  * of the offset mesh.
  **/
  CATListOfInt& GetSharpVertexFlags ();

  /**
  * Returns the distance map. 
  * The pointer returned is managed by this class and should not be deleted. 
  */
  const CATFuzVolRep* GetDistanceMap () const;

  /** 
  * Returns the error code when the fuzzy offset fails.
  * See CATFuzError for the definitions of the various errors.
  * Returns CATFuzError::eNoError when there is no error.
  */
  int GetError () const;

	/**
	* Returns the software configuration.
  * This method does not AddRef () to the returned configuration.
	**/
	CATSoftwareConfiguration* GetSoftwareConfiguration () const;
	
#ifndef CATIACGMV5R17

  //==============================================================================
  // CODE ELIMINATED IN R17
  //==============================================================================

  CATFuzzyOffsetOper (CATSoftwareConfiguration* iSoftwareConfiguration,
                      CATCldPolygon * iPoly, CATGeoFactory * iFactory);

  CATFuzzyOffsetOper (CATCldPolygon * iPoly, CATGeoFactory * iFactory);

  void SetPolyInit (CATCldPolygon* iInitialPolygon);  // Deprecated.

  CATCldPolygon* GetResult () const;  // Deprecated.

#endif

private:

  void SetBoundingBox ();

  CATBoolean UpdateProgress (const int progress);

  CATIPolyMesh* _InputMesh;
  CATIPolyMesh* _ResultMesh;

  CATSoftwareConfiguration* _SoftwareConfiguration;

#ifdef CATIACGMV5R17
  CATCGMProgressBar* _Callback;
#else
  CATPolyCallback* _Callback;
#endif


  double _OffsetSize;
  double _VoxelSize;
  
#ifndef CATIACGMV5R17
  CATCldPolygon* _CldInit;  
  CATCldPolygon* _CldResult;  
#endif

  CATMathPoint* _MinPoint;
  CATMathPoint* _MaxPoint;

  CATFuzVolRep* _DistanceMap;

  CATBoolean _Sharpen;
  CATListOfInt _VertexFlags;

  int _ErrorCode;

};

#endif
