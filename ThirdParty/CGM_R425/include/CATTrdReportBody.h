/* -*-C++-*- */
#ifndef CATTrdReportBody_H
#define CATTrdReportBody_H
// COPYRIGHT DASSAULT SYSTEMES 2014

//===================================================================
//===================================================================
//
// CATTrdReportBody: information of Trd mapping as Body
//
//===================================================================
//===================================================================
// Oct 2014    Creation                         R. Rorato
//===================================================================
#include "CATPGMTrdReportBody.h"
#include "AdvOpeInfra.h"
#include "ListPOfCATBody.h"
class CATBody;
class CATGeoFactory;
class CATSoftwareConfiguration;
class CATCGMJournalList;
class CATTrdReportBody;
class CATCGMProgressBar;

 /**
  * @nodoc
  */
ExportedByAdvOpeInfra CATTrdReportBody* CATCreateTrdReportBody();

class ExportedByAdvOpeInfra CATTrdReportBody : public CATPGMTrdReportBody
{
public:
  /**
  * @nodoc
  * Get Rep fully mapped from Body1 and Body2
  * iMappedRep1 and iMappedRep2 are synchronized by Index (iMappedRep1[x] is mapped to iMappedRep2[x])
  * The caller is responsible for cleaning iMappedRep1 and iMappedRep2
  */
  HRESULT GetFullyMappedRep(ListPOfListPOfCATCell &oMappedRep1, ListPOfListPOfCATCell &oMappedRep2);

  /**
  * @nodoc
  * Get Rep partially mapped from Body1 and Body2
  * iMappedRep1 and iMappedRep2 are synchronized by Index (iMappedRep1[x] is mapped to iMappedRep2[x])
  * The caller is responsible for cleaning iMappedRep1 and iMappedRep2
  */
  HRESULT GetPartiallyMappedRep(ListPOfListPOfCATCell &oMappedRep1, ListPOfListPOfCATCell &oMappedRep2);

  /**
  * @nodoc
  * Get Rep not mapped from Body1 and Body2
  */
  HRESULT GetNotMappedRep(ListPOfCATCell &oNotMappedCells1, ListPOfCATCell &oNotMappedCells2);

   /**
  * @nodoc
  * iFactory[2] are the factories to create Bodies into.
  * If succeeded,
  * oBodies[2] are the 2 lists of 3 Bodies each.
  * The first body contains fully similar faces, the second one contains partially similar faces, and the third one contains dissimilar faces.
  * Whenever there is no face matching the criteria, the corresponding body is null.
  * The BodyAnalyzer who filled this report must be still alive.
	*/
  HRESULT CreateSimilarBodies(CATSoftwareConfiguration* iConfig, CATGeoFactory* iFactory[2], ListPOfCATBody oBodies[2]);

 /**
  * @nodoc
  * Deprecated, use previous method.
	* If succeeded, oBodySimilar1 (resp oBodySimilar2) contains Body1 (resp Body2) faces similar to Body2 (resp Body1) faces
  * and oBodyDissimilar1 (resp oBodyDissimilar2) the rest of faces.
  * oBodyDissimilar1 (resp oBodyDissimilar2) is null whenever no face is dissimilar.
  * oBodySimilar1 (resp oBodySimilar2) and oBodyDissimilar1 (resp oBodyDissimilar2) are created into iFactory1 (resp iFactory2).
  * The BodyAnalyzer who filled this report must be still alive.
	*/
  HRESULT CreateSimilarBodies(CATSoftwareConfiguration* iConfig, CATGeoFactory* iFactory1, CATBody*& oBodySimilar1, CATBody*& oBodyDissimilar1, CATGeoFactory* iFactory2, CATBody*& oBodySimilar2, CATBody*& oBodyDissimilar2);

 /**	@nodoc @nocgmitf */
 HRESULT CreateSimilarBodies(CATGeoFactory* iFactory, CATBody*& oBody1, CATBody*& oBody2);

  //------------------------------------------------------------------------------
  // CGM private. Do not use.
  //------------------------------------------------------------------------------
 /**
 /**	@nodoc @nocgmitf */
  HRESULT ApplyColors(CATCGMJournalList& Journal1, CATCGMJournalList& Journal2);

  /**	@nodoc @nocgmitf */
  CATTrdReportBody();
  virtual ~CATTrdReportBody();
  //------------------------------------------------------------------------------

private:
  /**	@nodoc @nocgmitf */
  void ListOfTrdRepAsListOfCell(ListPOfCATTrdRep &iTrdReps, ListPOfCATCell &oCells);
  /**	@nodoc @nocgmitf */
  void ListOfTrdRepAsListOfListOfCell(ListPOfCATTrdRep &iTrdReps, ListPOfListPOfCATCell &oCells);

  /**	@nodoc @nocgmitf */
  HRESULT MatchAdjacentReps(CATSoftwareConfiguration &iConfig, const double iTolForAngleTest, const double iTolForSquareLengthTest);

  /**	@nodoc @nocgmitf */
  HRESULT FindOutInitialBodies(CATBody*& oBody1, CATBody*& oBody2, CATBoolean& oIsBodyExact1, CATBoolean& oIsBodyExact2);

  /**	@nodoc @nocgmitf */
  void CreateSimilarBodies(CATSoftwareConfiguration* iConfig, CATGeoFactory* iFactory);

  /**	@nodoc @nocgmitf */
  virtual void SetProgress(const double iValue, const double iTotalValue);

  virtual CATTrdReport* Clone() const;
};

//------------------------------------------------------------------------------

#endif
