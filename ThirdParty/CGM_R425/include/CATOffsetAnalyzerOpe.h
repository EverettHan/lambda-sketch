// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATOffsetAnalyzerOpe.cpp
// Header definition of CATOffsetAnalyzerOpe
//
//===================================================================

//===================================================================
//
//  MNJ - August 2011
//===================================================================
#ifndef CATOffsetAnalyzerOpe_H
#define CATOffsetAnalyzerOpe_H

#include "Thick.h"

#include "CATTopOperator.h"
#include "CATOffsetAnalyzerOpe.h"
#include "CATOffsetAnalyzerType.h"
#include "ListPOfCATFace.h"


class CATOffsetAnalyzerImpl;



class ExportedByThick CATOffsetAnalyzerOpe : public CATTopOperator
{

  CATCGMVirtualDeclareClass(CATOffsetAnalyzerOpe);
	
public:
	
	//==============================================================================
	// constructor: do not use, use CATCreateCATOffsetAnalyzerOpe
	//==============================================================================
	/**
  * Constructor : do not use, use CATCreateCATOffsetAnalyzerOpe.<br>
  * <b>Legal Values</b>:<br>
  *	<ul>
  *	  <li> <tt>iTopData</tt> : It represents the information about the configuration and
  *								the journal. If iTopData is NULL , the operator create it.<br>
  *	  <li> <tt>iBody</tt> : The body of the face selection<br>
  *	</ul>
  **/   
  CATOffsetAnalyzerOpe(CATGeoFactory *iFactory,
                       CATTopData *iTopData,
                       CATOffsetAnalyzerImpl *iOffsetAnalyzerImpl);

	//==============================================================================
	// destructor 
	//==============================================================================
	/**
	* Standard destructor.<br>
	**/
	virtual ~CATOffsetAnalyzerOpe();

	//==============================================================================
	// SetSheetMetalMode
	//==============================================================================
	/**
	* SheetMetal optimized run .<br>
	**/
  void SetSheetMetalMode(int iSheetMetalMode=1);

  //==============================================================================
	// SetGeometricalTolerance
	//==============================================================================
	/**
	* Tolerance for geometrical recognition. Default is 0.1mm. <br>
	**/
  void SetGeometricalTolerance(double iTolerance);

  //==============================================================================
  // GetOffsetType
  //==============================================================================
  CATOffsetAnalyzerType GetOffsetType();

  //==============================================================================
  // GetComputationMode
  //==============================================================================
  CATComputationMode GetComputationMode();

  //==============================================================================
  // GetDefaultOffsetValues
  //==============================================================================
  /**
  * Returns one (surface case) or two (volumic case) default offset values
  * oriented towards ref skin.
  **/
  int GetDefaultOffsetValues(double oDefaultOffsetValues[2]);

  //==============================================================================
  // GetNbOffsetValues
  //==============================================================================
  /**
  * Returns the number of offset values.
  **/
  int GetNbOffsetValues();

  //==============================================================================
  // GetDecomposition
  //==============================================================================
  /**
  * Returns lists of faces composing volumic body Skin A Skin B and lateral ribbon
  **/
  int GetDecomposition(CATLISTP(CATFace) &oSkinAFaces, CATLISTP(CATFace) &oSkinBFaces, CATLISTP(CATFace) &oLateralFaces);

  //==============================================================================
  // GetComputedRefSkin
  //==============================================================================
  /**
  * Returns computed ref skin in volumic case.
  **/
  CATBody * GetComputedRefSkin();

  //==============================================================================
  // GetImageOfInputCell
  //==============================================================================
  /**
  * Returns the lists of image cells from input cell. 
  * iOffsetValueNum = 1 in skin case, 1 or 2 in volumic case, 0 if iCell is a border edge. 
  **/
  int GetImageOfInputCell(CATCell *iCell, int iOffsetValueNum, CATLISTP(CATCell) &oImageCellList);

  //==============================================================================
  // GetFaceKind
  //==============================================================================
  /**
  * iFace belongs to iInputBody to analyze.
  * Returns 0 if iFace belongs to lateral ribbon, 1 if it belongs to offset of 
  * first value, 2 if it belongs to offset of second value, else return -1.
  **/
  int GetFaceKind(CATFace *iFace);

  //==============================================================================
  // GetFacesOnOtherSide
  //==============================================================================
  /**
  * iFace belongs to iInputBody to analyze.
  * Returns the list of corresponding faces on the other offset side of the body.
  * applies in volumic case only.
  * 1 if ok else 0.
  **/
  int GetFacesOnOtherSide(CATFace *iFace, CATLISTP(CATFace) &oOtherSideFaces);

  //==============================================================================
  //
  // CGMREPLAY METHODES
  //
  //==============================================================================
  /** @nodoc @nocgmitf */
  void RequireDefinitionOfInputAndOutputObjects();
  /** @nodoc @nocgmitf */
  CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);
  /** @nodoc @nocgmitf */
  const CATString * GetOperatorId();
  /** @nodoc @nocgmitf */
  static const CATString * GetDefaultOperatorId();
  /** @nodoc @nocgmitf */
  void DumpOutput(CATCGMOutput &os);
  /** @nodoc @nocgmitf */
  virtual void WriteInput(CATCGMStream  & os);
  /** @nodoc @nocgmitf */
  virtual void ReadInput(CATCGMStream  & ioStream,int VersionOfStream, short iNumReplayVersion=1);
  /** @nodoc @nocgmitf */
  virtual void Dump( CATCGMOutput& os ) ;
  /** @nodoc @nocgmitf */
  virtual int RunOperator();
  /** @nodoc @nocgmitf */
  void WriteOutput(CATCGMStream & Str);
  /** @nodoc @nocgmitf */
  virtual CATBoolean ValidateOutput(CATCGMStream& Str, CATCGMOutput& os, int VersionNumber=1);

  // constructor only for CGMReplay
  CATOffsetAnalyzerOpe(CATTopData* iTopData, CATBody* iBody, CATBody *iRefBody=NULL);

protected:
  CATOffsetAnalyzerImpl * GetCATOffsetAnalyzerImpl() const;

private :

  //==============================================================================
  // copy constructor
  //==============================================================================
  /**
  * Copy constructor: Not implemented. <br>
  **/
  CATOffsetAnalyzerOpe (CATOffsetAnalyzerOpe &);


  //==============================================================================
  // Equal operator
  //==============================================================================
  /**
  * Equal operator : Not implemented. <br>
  **/
  CATOffsetAnalyzerOpe& operator=(CATOffsetAnalyzerOpe&);

};

//==============================================================================
// CATCreateCATOffsetAnalyzerOpe
//==============================================================================
/**
* Create operator, it call the constructor.<br>
* <b>Legal Values</b>:<br>
*	<ul>
*	  <li> <tt>iTopData</tt> : It represents the information about the configuration and
*								the journal. If iTopData is NULL , the operator create it.<br>
*	  <li> <tt>iBody</tt> : The body to analyze<br>
*	  <li> <tt>iRefBody</tt> : The surfacic reference body if iBody is surfacic <br>
*	  <li> <tt>iRefFace</tt> : The reference face if body is volumic (optionnal, reference is computed if not provided) <br>
*	</ul>
**/   
ExportedByThick CATOffsetAnalyzerOpe * CATCreateCATOffsetAnalyzerOpe(CATTopData *iTopData,
                                                                     CATBody *iBody, 
                                                                     CATBody *iRefBody=NULL,
                                                                     CATFace *iRefFace=NULL);



#endif

