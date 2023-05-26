// COPYRIGHT DASSAULT SYSTEMES 2007, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : L. Marini 
//
// DESCRIPTION  : Face selection operator for CATIA Live Shape.
//                It detect logicaly the depresion and the protrusion.
//
//=============================================================================
// Creation LAP July 2007
//
//=============================================================================
#ifndef CATGMLiveShapeSelectFaceOpe_H
#define CATGMLiveShapeSelectFaceOpe_H

#include "AdvTrimOpe.h" // pour access dans la dll

#include "CATGMLiveShapeSelectFacePropagateMode.h"
#include "CATGMLiveShapeSelectFaceBasicOpe.h"

#include "ListPOfCATFace.h"
//#include "CATCollec.h" // for ListPOfCATFace
#include "CATBoolean.h"
#include "CATMathPoint.h"
#include "CATMathDirection.h"

class CATGMLiveShapeSelectFaceImpl;
class CATSoftwareConfiguration;
class CATBody;
class CATPersistentBody;
class CATPersistentCellInfra;
class CATTopData;
class CATFaceHashTable;
class CATFace;
/*
// In order to update GMOperatorsInterfaces/ProtectedInterfaces/CATIPGMLiveShapeSelectFaceOpe.h:
class CATGMLiveShapeSelectFacePropagateMode;
class CATAngle;
*/

/**
* This class is used to select faces with.<br>
**/
class ExportedByAdvTrimOpe CATGMLiveShapeSelectFaceOpe : public CATGMLiveShapeSelectFaceBasicOpe
{
  CATCGMVirtualDeclareClass(CATGMLiveShapeSelectFaceOpe);

public:

  //==============================================================================
  // constructor: do not use, use CATCreateLiveSelectFaceOpe
  //==============================================================================
  /**
  * Constructor : do not use, use CATCreateLiveSelectFaceOpe.<br>
  * <b>Legal Values</b>:<br>
  * <ul>
  *   <li> <tt>iTopData</tt> : It represents the information about the configuration and
  *            the journal. If iTopData is NULL , the operator create it.<br>
  *   <li> <tt>iBody</tt> : The body of the face selection<br>
  *   <li> <tt>iInputFaceList</tt> : The list of the fisrt faces selected<br>
  *   <li> <tt>iPropagationMode</tt> : The type of propagation :<br>
  *   <ul>
  *     <li> PointContinuityPropagationMode,<br>
  *     <li> TangencyContinuityPropagationMode,<br>
  *     <li> DepressionPropagationMode,<br>
  *     <li> ProtrusionPropagationMode,<br>
  *   </ul>
  *   <li> <tt>iStoppingFaces</tt> : It's optional. The list of the face not to pass through. (Ribbon faces for exemple)<br>
  *  </ul>
  **/
  // @nocgmitf
  CATGMLiveShapeSelectFaceOpe(CATGeoFactory               * iFactory,
    CATTopData                    * iTopData,
    CATGMLiveShapeSelectFaceImpl  * iImp);

  //==============================================================================
  // destructor 
  //==============================================================================
  /**
  * Standard destructor.<br>
  **/
  // @nocgmitf
  virtual ~CATGMLiveShapeSelectFaceOpe();

  // @nocgmitf
  //==============================================================================
  // Modify the definition of smooth edge with a max rad angle.
  // It's designed for the mode CLSSF_TANGENCY_CONTINUITY
  // For 2.3 degree, set 0.04 rad
  // For 0.5 degree, set 0.0087 rad
  //==============================================================================
  void SetTangencyMaxRadAngle(CATAngle iRadAngle);
  //Same as previous one but the max angle depends on convexity
  // @nocgmitf
  void SetTangencyMaxRadAngleWithConvexity(CATAngle iRadConvexAngle, CATAngle iRadConcavAngle);

	// Set math transformation (for extended selection mode)
	void SetMathTransformation(const CATMathTransformation *ipTransfo);

  //==============================================================================
  // GetFaceListResult
  //==============================================================================
  void GetFaceListResult(ListPOfCATFace & oResultFaceList);

  static const char * GetPropagationName(CATGMLiveShapeSelectFacePropagateMode iPropagationMode);

  //==============================================================================
  //
  // CGMREPLAY METHODES
  //
  //==============================================================================
  ///** @nodoc @nocgmitf declaration integre au CGMReplay */
  //void RequireDefinitionOfInputAndOutputObjects();
  /** @nodoc @nocgmitf */
  CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);
  /** @nodoc @nocgmitf */
  virtual const CATString * GetOperatorId();
  /** @nodoc @nocgmitf */
  static const CATString * GetDefaultOperatorId();
  ///** @nodoc @nocgmitf */
  //void DumpOutput(CATCGMOutput &os);
  ///** @nodoc @nocgmitf */
  //virtual void WriteInput(CATCGMStream  & os);
  ///** @nodoc @nocgmitf */
  //virtual void ReadInput(CATCGMStream  & ioStream,int VersionOfStream, short iNumReplayVersion=1);
  /** @nodoc @nocgmitf */
  virtual void Dump( CATCGMOutput& os ) ;
  /** @nodoc @nocgmitf */
  virtual int RunOperator();

protected:
  CATGMLiveShapeSelectFaceImpl *GetCATGMLiveShapeSelectFaceImpl() const;

  // @nocgmitf
  void SetMinAndMaxRadiusForGlobalRangeRibbons(double iMinRadius, double iMaxRadius);

  friend ExportedByAdvTrimOpe 
    HRESULT CATGMLiveShapeSelectFacesInRangeRibbons(CATSoftwareConfiguration *iConfig, CATBody *iBody, double iMinRadius, double iMaxRadius, ListPOfCATFace &oResultFaceList, const ListPOfCATFace *iSubBodyFaceList);

private :

  // For CGMReplay
  /*void SetInputFaceList(ListPOfCATFace & iInputFaceList);
  void SetPropagationMode(CATGMLiveShapeSelectFacePropagateMode iPropagationMode);
  void SetStoppingFacesList(ListPOfCATFace & iStoppingFaces);
  void SetSubBodyFilterFaceList(ListPOfCATFace & iSubBodyFilterFaceList);*/

  //==============================================================================
  // copy constructor
  //==============================================================================
  /**
  * Copy constructor: Not implemented. <br>
  **/
  CATGMLiveShapeSelectFaceOpe (CATGMLiveShapeSelectFaceOpe &);


  //==============================================================================
  // Equal operator
  //==============================================================================
  /**
  * Equal operator : Not implemented. <br>
  **/
  CATGMLiveShapeSelectFaceOpe& operator=(CATGMLiveShapeSelectFaceOpe&);


  //==============================================================================
  // Data
  //==============================================================================

};

//==============================================================================
// CATGMLiveShapeSelectFaces
//==============================================================================
/**
* static methode to get the directly the ResultFaceList<br>
* <b>Legal Values</b>:<br>
*  <ul>
*    <li> <tt>iBody</tt> : The body of the face selection<br>
*   <li> <tt>iInputFaceList</tt> : The list of the fisrt faces selected<br>
*   <li> <tt>iPropagationMode</tt> : The type of propagation :<br>
*     <ul>
*     <li> PointContinuityPropagationMode,<br>
*     <li> TangencyContinuityPropagationMode,<br>
*     <li> DepressionPropagationMode,<br>
*     <li> ProtrusionPropagationMode,<br>
*      </ul>
*   <li> <tt>oResultFaceList</tt> : It's the result The list of the faces selected after propagation<br>
*   <li> <tt>iStoppingFaces</tt> : It's optional. The list of the face not to pass through. (Ribbon faces for exemple)<br>
*  </ul>
**/   

ExportedByAdvTrimOpe HRESULT CATGMLiveShapeSelectFaces(
                             CATBody                                 * iBody,
                             const ListPOfCATFace                    & iInputFaceList,
                             CATGMLiveShapeSelectFacePropagateMode     iPropagationMode,
                             ListPOfCATFace                          & oResultFaceList,
                             ListPOfCATFace                          * iStoppingFaces/*=NULL*/,
                             CATBoolean                                iLiveBodyAllowed/*=TRUE*/,
                             CATSoftwareConfiguration                * iConfig/*=NULL*/,
                             CATBoolean                                iTestTypeMode=FALSE);// VB7 - for Protrusion or depression test. Throw an error if propagated faces are added to input face list.

// CATGMLiveShapeSelectFaces With SubBodyFilterFaceList
// @nocgmitf
ExportedByAdvTrimOpe HRESULT CATGMLiveShapeSelectFaces(
                             CATBody                                 * iBody,
                             const ListPOfCATFace                    & iInputFaceList,
                             CATGMLiveShapeSelectFacePropagateMode     iPropagationMode,
                             ListPOfCATFace                          & oResultFaceList,
                             const ListPOfCATFace                    & iSubBodyFilterFaceList,// List to limit the propogation to this list of face
                             CATBoolean                                iLiveBodyAllowed/*=TRUE*/,
                             CATSoftwareConfiguration                * iConfig/*=NULL*/);       

// @nocgmitf
ExportedByAdvTrimOpe HRESULT CATGMLiveShapeSelectFaces(
                               CATPersistentBody                     * iPersistentBody,
                               CATPersistentCellInfra                & iInfra,
                               const ListPOfCATFace                  & iInputFaceList,
                               CATGMLiveShapeSelectFacePropagateMode   iPropagationMode,
                               ListPOfCATFace                        & oResultFaceList,
                               ListPOfCATFace                        * iStoppingFaces/*=NULL*/,
                               CATBoolean                              iLiveBodyAllowed/*=TRUE*/,
                               CATSoftwareConfiguration              * iConfig/*=NULL*/,
                               CATBoolean                              iTestTypeMode=FALSE);

//==============================================================================
// CATGMLiveShapeSelectFacesWithAnglePropagation
// For 2.3 degree, set 0.04 rad
// For 0.5 degree, set 0.0087 rad
// For 90  degree, set 1.57 rad
//==============================================================================
ExportedByAdvTrimOpe HRESULT CATGMLiveShapeSelectFacesWithAnglePropagation(
                             CATBody                                 * iBody,
                             const ListPOfCATFace                    & iInputFaceList,
                             CATAngle                                  iPropagationMaxRadAngle,
                             ListPOfCATFace                          & oResultFaceList,
                             CATSoftwareConfiguration                * iConfig,
                             CATBoolean                                iLiveBodyAllowed=FALSE,
                             ListPOfCATFace                          * iStoppingFaces=NULL);

//==============================================================================
// CATGMLiveShapeSelectFacesWithAngleByConvexityPropagation
//==============================================================================
ExportedByAdvTrimOpe HRESULT CATGMLiveShapeSelectFacesWithAngleByConvexityPropagation(
                             CATBody                                 * iBody,
                             const ListPOfCATFace                    & iInputFaceList,
                             CATAngle                                  iPropagationMaxRadConvexAngle,
                             CATAngle                                  iPropagationMaxRadConcaveAngle,
                             ListPOfCATFace                          & oResultFaceList,
                             CATSoftwareConfiguration                * iConfig,
                             CATBoolean                                iLiveBodyAllowed=FALSE,
                             ListPOfCATFace                          * iStoppingFaces=NULL);

//==============================================================================
// CATGMLiveShapeSelectFacesWithAngleByConvexityPropagation
//==============================================================================
ExportedByAdvTrimOpe HRESULT CATGMLiveShapeSelectFacesWithAngleByConvexityPropagation(
                             CATBody                                 * iBody,
                             const ListPOfCATFace                    & iInputFaceList,
                             CATAngle                                  iPropagationMaxRadConvexAngle,
                             CATAngle                                  iPropagationMaxRadConcaveAngle,
                             ListPOfCATFace                          & oResultFaceList,
                             const ListPOfCATFace                    & iSubBodyFilterFaceList,// List to limit the propogation to this list of face
                             CATSoftwareConfiguration                * iConfig,
                             CATBoolean                                iLiveBodyAllowed=FALSE);

//==============================================================================
// CATGMLiveShapeSelectFacesInRangeRibbons
/**
* Static method to get the directly the ResultFaceList
* @Param iBody
*    Mandatory : Must be a CATLiveBody. 
*
* CATGMLiveShapeSelectFacesRangeRibbons operates on all faces of the body and doesn't compute any propagation.
* It returns a list of ribbbon faces with radiuses between iMinRadius and iMaxRadius.
* 
* @Param iSubBodyFaceList 
*		 Optional. If set, only thoses faces will be considered for the computation. 
*/ 
//==============================================================================
ExportedByAdvTrimOpe HRESULT CATGMLiveShapeSelectFacesInRangeRibbons( CATSoftwareConfiguration                * iConfig,
                                                                      CATBody																	* iBody,																																		
                                                                      double																    iMinRadius,
                                                                      double																    iMaxRadius,
                                                                      ListPOfCATFace                          & oResultFaceList,
                                                                      const ListPOfCATFace                    * iSubBodyFaceList = NULL// List to limit the scope to this list of faces
                                                                      );
                                                                    
//==============================================================================
// CATGMLiveShapeSelectFacesWithMoveExtension
/**
* Static method to get the directly the ResultFaceList
* 
* @Param	iBody
*    Mandatory : Must be a CATLiveBody.
* @Param	iInputFaceList
*		List of input selected faces.
* @Param	ipMathTransformation
*		Mandatory : input math transformation applied to selected faces.
* @Param	oResultFaceList
*		List of suggested faces to be added to the selection.
*
* CATGMLiveShapeSelectFacesWithMoveExtension extends the selection to faces which 
* can be impacted by the math transformation.
* 
* The selected and suggested face are returned in an output list of faces (oResultFaceList).
* 
* @author YSY2
* @date		w06-y2020
*/
//==============================================================================
ExportedByAdvTrimOpe HRESULT CATGMLiveShapeSelectFacesWithMoveExtension( CATSoftwareConfiguration               * iConfig,
																																				 CATBody																* iBody,
																																				 const ListPOfCATFace										& iInputFaceList,
																																				 const CATMathTransformation						* ipMathTransformation,
																																				 ListPOfCATFace                         & oResultFaceList
);

//==============================================================================
// CATCreateLiveSelectFaceOpe
//==============================================================================
/**
* Create operator, it call the constructor.<br>
* <b>Legal Values</b>:<br>
*  <ul>
*    <li> <tt>iTopData</tt> : It represents the information about the configuration and
*                the journal. If iTopData is NULL , the operator create it.<br>
*    <li> <tt>iBody</tt> : The body of the face selection<br>
*   <li> <tt>iInputFaceList</tt> : The list of the fisrt faces selected<br>
*   <li> <tt>iPropagationMode</tt> : The type of propagation :<br>
*     <ul>
*     <li> PointContinuityPropagationMode,<br>
*     <li> TangencyContinuityPropagationMode,<br>
*     <li> DepressionPropagationMode,<br>
*     <li> ProtrusionPropagationMode,<br>
*      </ul>
*   <li> <tt>iStoppingFaces</tt> : It's optional. The list of the face not to pass through. (Ribbon faces for exemple)<br>
*  </ul>
**/
ExportedByAdvTrimOpe CATGMLiveShapeSelectFaceOpe * CATCreateLiveSelectFaceOpe(CATTopData                             * iTopData,
                                                                               CATBody                               * iBody,
                                                                               const ListPOfCATFace                  & iInputFaceList,
                                                                               CATGMLiveShapeSelectFacePropagateMode   iPropagationMode,
                                                                               ListPOfCATFace                        * iStoppingFaces=NULL);

// new constructor (I) with cells.
ExportedByAdvTrimOpe CATGMLiveShapeSelectFaceOpe * CATCreateLiveSelectFaceOpe(CATTopData                             * iTopData,
                                                                               CATBody                               * iBody,
                                                                               const ListPOfCATFace                  & iInputFaceList,
                                                                               CATGMLiveShapeSelectFacePropagateMode   iPropagationMode,
                                                                               const ListPOfCATCell                  * iStoppingCells); // could be edges or faces.

// Constructor with HashTable
ExportedByAdvTrimOpe CATGMLiveShapeSelectFaceOpe * CATCreateLiveSelectFaceOpe(CATTopData                            * iTopData,
                                                                              CATBody                               * iBody,                                                                                
                                                                              const CATFaceHashTable                & iInputFaceHT,
                                                                              CATGMLiveShapeSelectFacePropagateMode   iPropagationMode,
                                                                              const CATCellHashTable                * iStoppingCells=NULL); // could be edges or faces.


// Constructor with a "Limiting Body" for CLSSF_DFT_LIMITING_DETECTION
ExportedByAdvTrimOpe CATGMLiveShapeSelectFaceOpe * CATCreateLiveSelectFaceOpe(CATTopData                            * iTopData,
                                                                              CATBody                               * iInputBody,
                                                                              CATBody                               * iLimitingBody,
                                                                              CATGMLiveShapeSelectFacePropagateMode   iPropagationMode=CLSSF_DFT_LIMITING_DETECTION,
                                                                              const ListPOfCATFace                  * iInputFaceList=NULL);

//==============================================================================
// CATLiveSelectFaceReverseDepressionProtrusion
//
//    October 2018
//    IT'S A PROTOTYPE FOR  A PATTERN. DON'T CALL IT.
//
//==============================================================================
// If return TRUE, the application should invert the notion of Depression and Protrusion
// when it calls the LiveShapeSelectFaceOpe.
//
// Parameters
//   i3DClickPoint   : It's the last point (x,y,z) of the click associated with the selected ipFace.
//   iSightDirection : Should comes from GetSightDirection().
//
// Example
//   1) The User wants a Depression propagation.
//   2) CATLiveSelectFaceReverseDepressionProtrusion returns TRUE.
//   3) The application calls the LiveShapeSelectFaceOpe with CLSSF_PROTRUSION.
// -----------------------------------------------------------------------------
ExportedByAdvTrimOpe CATBoolean CATLiveSelectFaceReverseDepressionProtrusion(CATBody                  * ipBody,
                                                                             CATFace                  * ipFace,
                                                                             CATSoftwareConfiguration * ipConfig,
                                                                             CATMathPoint             & i3DClickPoint,
                                                                             CATMathDirection         & iSightDirection);



// with SubBodyFilterFaceList
// @nocgmitf
ExportedByAdvTrimOpe CATGMLiveShapeSelectFaceOpe * CATCreateLiveSelectFaceOpe(
                             CATTopData                            * iTopData,
                             CATBody                               * iBody,
                             const ListPOfCATFace                  & iInputFaceList,
                             CATGMLiveShapeSelectFacePropagateMode   iPropagationMode,
                             const ListPOfCATFace                  & iSubBodyFilterFaceList);

// @nocgmitf
ExportedByAdvTrimOpe CATGMLiveShapeSelectFaceOpe * CATCreateLiveSelectFaceOpe(
                              CATTopData                            * iTopData,
                              CATPersistentBody                     * iPersistentBody,
                              CATPersistentCellInfra                & iInfra,
                              const ListPOfCATFace                  & iInputFaceList,
                              CATGMLiveShapeSelectFacePropagateMode   iPropagationMode,
                              ListPOfCATFace                        * iStoppingFaces);


#endif

