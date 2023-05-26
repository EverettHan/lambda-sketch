// COPYRIGHT DASSAULT SYSTEMES 2018, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : VB7
//
// DESCRIPTION  : This operator 
//
// INPUT DATA   : 
//                - First body
//                - Second body
//                - Mirror Plane
//
// OPTIONS      : 
//                - Tolerance
//
// OUTPUT DATA  :
//                - List of symmetrical faces on the first body  -- parallel to the following list
//                - List of symmetrical faces on the second body -- parallel to the previous list
//                - List of non-symmetrical faces on the first body
//                - List of non-symmetrical faces on the second body
//
//=============================================================================
// Creation VB7 December 2018
//=============================================================================

#ifndef CATGMBodySymmetryOpe_H
#define CATGMBodySymmetryOpe_H

#include "AdvTrimOpe.h"
#include "CATPersistentOperator.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATEdge.h"

class CATGMBodySymmetryImpl;


class ExportedByAdvTrimOpe CATGMBodySymmetryOpe : public CATPersistentOperator
{
  CATCGMVirtualDeclareClass(CATGMBodySymmetryOpe);

public:

  /**
  * Destructor
  */
  virtual ~CATGMBodySymmetryOpe();

  //------------------
  // Set methods
  //------------------
  void SetTolerance(double iTolerance);

  //------------------
  // Get methods
  //------------------
  //Faces
  void GetSymmetricFaceLists(ListPOfCATFace & oFirstBodySymmetricFaceList, ListPOfCATFace & oSecondBodySymmetricFaceList); //oSecondBodySymmetricFaceList parallel to oFirstBodySymmetricFaceList
  void GetNonSymmetricFaceLists(ListPOfCATFace & oFirstBodyNonSymmetricFaceList, ListPOfCATFace & oSecondBodyNonSymmetricFaceList);

  //Edges
  void GetSymmetricEdgeLists(ListPOfCATEdge & oFirstBodySymmetricEdgeList, ListPOfCATEdge & oSecondBodySymmetricEdgeList); //oSecondBodySymmetricEdgeList parallel to oFirstBodySymmetricEdgeList
  void GetNonSymmetricEdgeLists(ListPOfCATEdge & oFirstBodyNonSymmetricEdgeList, ListPOfCATEdge & oSecondBodyNonSymmetricEdgeList);

  //------------------
  // CGMReplay methods
  //------------------
  // @nocgmitf
  static const CATString * GetDefaultOperatorId();

  // @nocgmitf
  const CATString * GetOperatorId();

  // @nocgmitf
  CATExtCGMReplay * IsRecordable( short & LevelOfRuntime, short &VersionOfStream );

  // @nocgmitf
  void WriteInput( CATCGMStream  & Str );

  // @nocgmitf
  void ReadInput( CATCGMStream  & ioStr, int VersionOfStream);

  // @nocgmitf
  void Dump( CATCGMOutput& os ) ;

  // @nocgmitf
  void DumpOutput( CATCGMOutput &os );

  //@nocgmitf
  void         WriteOutput(CATCGMStream & Str);

  //@nocgmitf
  CATCGMOperator::CATCheckDiagnostic CheckOutput(CATCGMOutput & os);

  //@nocgmitf
  CATBoolean   ValidateTopOutput   (CATTopCheckJournal* iEquivalent, CATCGMOutput& os);

  //@nocgmitf
  CATBoolean   ValidateOutput      (CATCGMStream & Str, CATCGMOutput & os, int VersionNumber=1);

  //@nocgmitf
  CATBoolean   ReadReferenceOutput (CATCGMStream & Str);

  //@nocgmitf
  void         DumpOutput(CATCGMStream & Str , CATCGMOutput & os , int VersionNumber);

  // @nocgmitf
  void RequireDefinitionOfInputAndOutputObjects();

protected:

  CATGMBodySymmetryImpl * GetGMBodySymmetryImpl();

  /**
  * Protected constructor : Do not call directly.
  * Use CATCreateGMBodySymmetryOpe() instead.
  */
  CATGMBodySymmetryOpe( CATGeoFactory         * iFactory,
                        CATTopData            * iTopData,
                        CATGMBodySymmetryImpl * iImpl );

  //------------------------------------------------------------------------------
  // Forbidden (Declared but not Defined) : Copy constructor & assignment operator
  //------------------------------------------------------------------------------
  CATGMBodySymmetryOpe ( const CATGMBodySymmetryOpe & );            // Not Implemented
  CATGMBodySymmetryOpe & operator=( const CATGMBodySymmetryOpe & ); // Not Implemented

  //-----------------
  // Friend functions
  //-----------------
  friend ExportedByAdvTrimOpe CATGMBodySymmetryOpe * CATCreateGMBodySymmetryOpe( CATGeoFactory    & iFactory, 
                                                                                 CATTopData       & iTopData, 
                                                                                 CATBody          & iFirstBody,
                                                                                 CATBody          & iSecondBody,
                                                                                 CATMathPlane     & iMirrorPlane);

};

// ----------------------
// CATCreateGMBodySymmetryOpe
// ----------------------
ExportedByAdvTrimOpe CATGMBodySymmetryOpe * CATCreateGMBodySymmetryOpe( CATGeoFactory    & iFactory, 
                                                                        CATTopData       & iTopData, 
                                                                        CATBody          & iFirstBody,
                                                                        CATBody          & iSecondBody,
                                                                        CATMathPlane     & iMirrorPlane);

#endif /* CATGMBodySymmetryOpe_H */
