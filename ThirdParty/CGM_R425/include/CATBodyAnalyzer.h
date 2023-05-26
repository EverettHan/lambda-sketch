// COPYRIGHT DASSAULT SYSTEMES 2014, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : RR
//
// DESCRIPTION  : Operator dedicated to analyze Bodies
//
//=============================================================================
// Creation RR April 201
//=============================================================================
#ifndef CATBodyAnalyzer_H
#define CATBodyAnalyzer_H

#include "AdvOpeInfra.h"
#include "CATPGMBodyAnalyzer.h"
#include "ListPOfCATBody.h"
#include "ListPOfCATDeclarativeManifold.h"
#include "ListPOfCATFace.h"
#include "ListPOfListPOfCATFace.h"
#include "CATLISTV_CATMathLine.h"
#include "CATLISTV_CATMathVector.h"
#include "CATLISTV_CATMathTransformation.h"
#include "CATListOfCATUnicodeString.h"
#include "CATListOfDouble.h"
#include "CATCGMNewArray.h"
class CATBodyAnalyzer;
class CATBodyAnalyzerImpl;
class CATGeoFactory;
class CATTrdSSet;
class CATBSVGraph;
class CATBSDic;
class CATTrdReport;
class CATTrdOptions;
class CATVTGraph;
class CATUfrReport;
class CATMathTransformation;
class CATSoftwareConfiguration;
class CATUnicodeString;

//----------------------------------------------------------------------------
// Public section
//----------------------------------------------------------------------------
/** 
	* Creates a CATBodyAnalyzer operator.
	* @param iFactory
  * Factory in which objects may be created.
	* @param iConfig
  * CATSoftwareConfiguration to manage upward compatibility of changes in the implementation.
	* @param iBodies
	* List of bodies to be analyzed. 
 * @return [out, delete]
 */
ExportedByAdvOpeInfra CATBodyAnalyzer* CATCreateBodyAnalyzer(CATGeoFactory& iFactory, CATSoftwareConfiguration& iConfig, ListPOfCATBody& iBodies);

class ExportedByAdvOpeInfra CATBodyAnalyzer: public CATPGMBodyAnalyzer
{
public:

  ~CATBodyAnalyzer(); 

 /**
	* Returns S_OK whenever a Similarity exists so that Body2 = oTransfoFrom1To2(iBody1).
  * <br>iBody1 && iBody2 are the indexes of the bodies to be analyzed.
  * <br>iRequiredSimilarity is the required percentage of area (approximated for cylindrical holes) of similar faces for both bodies (between 0. & 1.).
  * <br>Negative similarity may be returned only if no positive similarity is found.
  * <br>Manage various options with iOptions. Default Options are available in CATTrdDefaultOptions.
  * <br>if S_OK, oReport contains information regarding detailed mapping & Transformation from iBody1 to iBody2. oReport must be a CATTrdReportBody to benefit from interruptibility.
	*/
  HRESULT AreSimilar(const int iBody1, const int iBody2, const double iRequiredSimilarity, const CATTrdOptions& iOptions, CATTrdReport& oReport); 

  /**
	* Returns S_OK whenever a Similarity exists so that Bodies2 = oTransfoFrom1To2(iBodies1).
  * <br>iBodies1 && iBodies2 are the indexes of the bodies to be analyzed.
  * <br>iRequiredSimilarity is the required percentage of area (approximated for cylindrical holes) of similar faces for both bodies (between 0. & 1.).
  * <br>Negative similarity may be returned only if no positive similarity is found.
  * <br>Manage various options with iOptions. Default Options are available in CATTrdDefaultOptions.
  * <br>if S_OK, oReport contains information regarding detailed mapping & Transformation from iBodies1 to iBodies2.
	*/
  HRESULT AreSimilar(const CATListOfInt& iBodies1, const CATListOfInt& iBodies2, const double iRequiredSimilarity, const CATTrdOptions& iOptions, CATTrdReport& oReport); 

  /**
	* Restrict search on iBody to iSubset.
  * If iSubset is empty or this method is not called then the full Body is used.
  * Search will not found similar subset whenever iSubset is made of only coaxial cylinders, cone, torii or sphere.
	*/
  HRESULT SetPartialSearch(const int iBody, const ListPOfCATFace& iSubset);

  /**
	* Returns S_OK whenever exists one or several plane the Body is symmetric with regards to.
  * oDirections contains symmetry planes definitions.
	*/
  HRESULT IsSymmetric(const int iBody, CATLISTV(CATMathLine)& oDirections); 
  
 /**	@nodoc @nocgmitf */
 HRESULT AreSimilar(const int iBody1, const int iBody2, const double iRequiredSimilarity, CATTrdReport& oReport); 

 /**	@nodoc @nocgmitf */
 HRESULT AreIsometric(const int iBody1, const int iBody2, CATMathTransformation& oTransfoFrom1To2, const double iRequiredSimilarity, CATTrdReport* ioReport=NULL); 

 /**
  * @nodoc
  * Finds out extrusion directions and their areas (with regards to whole Body Area), sorted in decreasing order.
	*/
  HRESULT IsExtruded(const int iBody, CATLISTV(CATMathVector)& oDirections, CATListOfDouble& oAreas); 
  HRESULT IsExtruded(const int iBody, CATLISTV(CATMathVector)& oDirections, CATListOfDouble& oAreas, ListPOfListPOfCATFace& oContributors); 

 /**
  * @nodoc
  * Finds out extrusion directions and their areas (with regards to Bodies Area), sorted in decreasing order.
	*/
  HRESULT IsExtruded(const CATListOfInt& iBodies, const CATLISTV(CATMathTransformation)& iPositions, CATLISTV(CATMathVector)& oDirections, CATListOfDouble& oAreas); 
  HRESULT IsExtruded(const CATListOfInt& iBodies, const CATLISTV(CATMathTransformation)& iPositions, CATLISTV(CATMathVector)& oDirections, CATListOfDouble& oAreas, ListPOfListPOfCATFace& oContributors); 

 /**
  * @nodoc
  * Finds out directions of revolution and their areas (with regards to whole Body Area), sorted in decreasing order.
	*/
  HRESULT IsTurned(const int iBody, CATLISTV(CATMathLine)& oDirections, CATListOfDouble& oAreas); 
  HRESULT IsTurned(const int iBody, CATLISTV(CATMathLine)& oDirections, CATListOfDouble& oAreas, ListPOfListPOfCATFace& oContributors); 
  HRESULT IsTurned(const int iBody, const CATIsTurnedOptions& iOptions, CATLISTV(CATMathLine)& oDirections, CATListOfDouble& oAreas, ListPOfListPOfCATFace& oContributors);

 /**
  * @nodoc
  * Finds out directions of revolution and their areas (with regards to Bodies Area), sorted in decreasing order.
	*/
  HRESULT IsTurned(const CATListOfInt& iBodies, const CATLISTV(CATMathTransformation)& iPositions, CATLISTV(CATMathLine)& oDirections, CATListOfDouble& oAreas);
  HRESULT IsTurned(const CATListOfInt& iBodies, const CATLISTV(CATMathTransformation)& iPositions, CATLISTV(CATMathLine)& oDirections, CATListOfDouble& oAreas, ListPOfListPOfCATFace& oContributors);
  HRESULT IsTurned(const CATListOfInt& iBodies, const CATLISTV(CATMathTransformation)& iPositions, const CATIsTurnedOptions& iOptions, CATLISTV(CATMathLine)& oDirections, CATListOfDouble& oAreas, ListPOfListPOfCATFace& oContributors);

 /**
  * @nodoc
  * Finds out planar areas and their areas (with regards to whole Body Area), sorted in decreasing order. Directions are oriented toward material.
	*/
  HRESULT IsPlanar(const int iBody, CATLISTV(CATMathLine)& oDirections, CATListOfDouble& oAreas); 
  HRESULT IsPlanar(const int iBody, CATLISTV(CATMathLine)& oDirections, CATListOfDouble& oAreas, ListPOfListPOfCATFace& oContributors); 

 /**
  * @nodoc
  * Finds out planar areas and their wet areas (with regards to Bodies wet Area), sorted in decreasing order. Directions are oriented toward material.
	*/
  HRESULT IsPlanar(const CATListOfInt& iBodies, const CATLISTV(CATMathTransformation)& iPositions, CATLISTV(CATMathLine)& oDirections, CATListOfDouble& oAreas, ListPOfListPOfCATFace& oContributors); 

  /**
  * @nodoc
  * Finds out canonic areas and their areas (with regards to whole Body Area), sorted in decreasing order. Only Planes, Cylinders & Cones are currently detected. Type definition is in CATGeometryType.h.
	*/
  HRESULT IsCanonic(const int iBody, CATListOfInt& oTypes, CATLISTV(CATMathLine)& oLocations, CATListOfDouble oParams[2], CATListOfDouble& oAreas); 

 /**
  * @nodoc
  * Analyze Topology. Not compatible with PartialSearch & non-manifold bodies.
	*/
  HRESULT GetGenus(const int iBody, int& oGenus, int* oVolumesCount, int* oFacesCount, int* oEdgesCount, int* oVerticesCount); 

 /**
  * @nodoc
  * Locate a similar, already known in an alphabet, shape. 
	*/
  HRESULT LocateShape(const int iBody, CATUnicodeString& oShapeName); 

   /**
  * @nodoc
  * Read this operator default shape names.
	*/
  HRESULT GetAlphabet(CATListValCATUnicodeString& oNames);

  /**
  * @nodoc
  * Creates a TrdSSet representing the input body. CATTrdSSet can be streamed & compared to another CATTrdSSet.
	*/
  CATTrdSSet* CreateTrdSSet(const int iBody); 

    /**
  * @nodoc
  * Creates a TrdSSet representing the input bodies. 
  * The CATTrdSSet can be streamed & compared to another CATTrdSSet. 
  * All bodies containers must have the same scale.
	*/
  CATTrdSSet* CreateTrdSSet(const CATListOfInt& iBodies); 

  /**
  * @nodoc
  * Creates a BSVGraph representing the input body. CATBSVGraph can be streamed & compared (IsEqual) to another CATBSVGraph.
	*/
  CATBSVGraph* CreateBSVGraph(const int iBody); 

  /**	@nodoc @nocgmitf 
  * Creates a VGraph representing the input body. CATVGraph can be sought in another CATVGraph & compared (IsEqual) to another CATVGraph..
  */
  CATVTGraph* CreateVTGraph(const int iBody); 

  /**	@nodoc
	* Returns S_OK whenever at least one iLookedForFeatureBodies-like exists in iSearchedBody.
  * <br>iLookedForFeatureBodies are the ordered indexes of the bodies to be looked for.
  * <br>iSearchedBody is the index of the body to be searched.
  * oReport contains detailed information about found features.
	*/
  HRESULT SearchFeatures(const CATListOfInt& iLookedForFeatureBodies, const int iSearchedBody, CATUfrReport& oReport); 
  HRESULT SearchFeatures(const CATListOfInt& iLookedForFeatureBodies, const int iSearchedBody, const CATVGraphOptions& iOptions, CATUfrReport& oReport);


  //----------------------------------------------------------------------------
  // Private section (For test only, do not use)
  //----------------------------------------------------------------------------
/**	@nodoc @nocgmitf */
  CATBodyAnalyzer(CATBodyAnalyzerImpl* iImpl, CATGeoFactory& iFactory);
/**	@nodoc @nocgmitf */
  CATCGMNewClassArrayDeclare; // Pool allocation
/**	@nodoc @nocgmitf */
  HRESULT BuildDictionary(const CATListValCATUnicodeString& iNames); 
/**	@nodoc @nocgmitf */
  CATBSDic* GetDictionary();
/**	@nodoc @nocgmitf */
  CATBodyAnalyzerImpl* GetImpl();

private:
  int RunOperator(); // for CGMReplay
  CATBodyAnalyzer(const CATBodyAnalyzer& iBodyAnalyzerToCopy);
  CATBodyAnalyzer & operator=(const CATBodyAnalyzer& iBodyAnalyzerToCopy);

  // Implementation
  CATBodyAnalyzerImpl*                   _Impl; // To be removed: useless
};

//----------------------------------------------------------------------------

#endif
