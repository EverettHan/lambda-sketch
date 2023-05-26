/*
=============================================================================

 COPYRIGHT   : DASSAULT SYSTEMES 2008
 
 DESCRIPTION : 

=============================================================================
*/

// <ClassName>: CATTopShellUnfoldTransfer
//
//=============================================================================
// Usage Notes: Do not use this directly. Call CATCreateTopShellUnfoldTransfer
//              instead.
//            
//=============================================================================
// Jan 2008 Creation                   SUH
//=============================================================================

//BUGBUG document well

#ifndef CATTopShellUnfoldTransfer_H
#define CATTopShellUnfoldTransfer_H

#include "FrFTopologicalOpe.h" // exported by

#include "CATTopOperator.h"
#include "ListPOfCATFace.h"

class ExportedByFrFTopologicalOpe CATTopShellUnfoldTransfer : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopShellUnfoldTransfer);

public:
  virtual ~CATTopShellUnfoldTransfer();

  virtual void SetTransfertTolerance(double iTol) = 0;  

  //Cleaning of transferred wire is on by default
  virtual void SetClean(CATBoolean iClean) = 0;
  //virtual void SetMaxDeviationForClean(double iMaxCleanDeviation) = 0; //BUGBUG shall go
  virtual void SetAssemblyTolerance(double iAsslyTol) = 0; //quite useful when the Clean is off

  // S9L : Start : 10 Feb 2012
  virtual void SetIgnoreVerticesMerging(CATBoolean iIgnoreVerticesMerging) = 0;
  // S9L : End : 10 Feb 2012

  virtual int RunTransfer(const CATLISTP (CATBody) & iBodiesToTransfer  ,
                                CATLISTP (CATBody) & ioBodiesTransferred,
                                CATCGMJournalList *  iReport            ,             //Not filled if NULL
                                CATBoolean           iReverse           = FALSE) = 0; //TRUE to transfer from result body to input body
  
  virtual int RunTransfer(      CATBody           *  iBody              ,
                                CATBody           *& oBody              ,
                                CATCGMJournalList *  iReport            ,
                                CATBoolean           iReverse           = FALSE) = 0;

  // SZR3: Start: 28 May 2020
  /**
   * Checks if the input flattened shell is the result of unfolding
   * the input body. The link between the bodies can be noted if
   * the flattened shell was created using FrFShellUnfold
   * and CreateUnfoldedShellTrackingAttribute method was
   * set to TRUE.
   *
   * @return
   * <ul>
   *   <li> <tt>-1</tt> if the relationship is unknown
   *   <li> <tt>0</tt> if they are not related
   *   <li> <tt>1</tt> if they are related
   * </ul>
   */
  virtual int IsInputShellFlattenedInputBody() const = 0;
  // SZR3: End: 28 May 2020

protected:  
  CATTopShellUnfoldTransfer(CATGeoFactory     * iFactory,
                            CATTopData        * iTopData);
};

//Note that this API is only to support curve transfer between provided bodies.
//Hence, the only methods supported by the returned interface are the two overloads of
//RunTransfer. Calling other methods can generate an error
//
//Either or both iListOfInputFaces and iListOfFlattenedFaces can be empty. They are then filled up
// from all the faces from iBody and iFlattenedBody respectively. After this, if iListOfInputFaces
// and iListOfFlattenedFaces have different sizes, the API will fail. 
// Hence, it shall be always ensured that:
// - If iListOfInputFaces and iListOfFlattenedFaces both are not empty, their sizes should be the same.
// - If either or both iListOfInputFaces and iListOfFlattenedFaces are empty, the sizes computed inside 
//   the API should be the same.
//extern "C" 
ExportedByFrFTopologicalOpe CATTopShellUnfoldTransfer * CATCreateTopShellUnfoldTransfer(
                                CATGeoFactory    *  iFactory,
                                CATTopData       *  iTopData,
                                CATBody          *  iBody   ,               //the body to flatten , Must have only one shell
                                CATBody          *  iFlattenedBody,         //Must be the result of free form unfold for iBody
                          const CATLISTP(CATFace) & iListOfInputFaces,      //all the faces of input body. If empty, fetched from iBody
                          const CATLISTP(CATFace) & iListOfFlattenedFaces); //corresponding faces in flattened body. If empty, fetched from iFlattenedBody
                                                                         
#endif
