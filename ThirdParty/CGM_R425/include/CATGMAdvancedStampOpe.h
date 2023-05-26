// COPYRIGHT DASSAULT SYSTEMES 2017, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : VB7
//
// DESCRIPTION  : This operator creates a AdvancedStamp shape.
//                A AdvancedStamp shape is defined by its Shape, a fillet radius,
//                a draft angle and a Draft direction.
//                It provides a result body which contains the AdvancedStamp shape.
//                It can be volumic or surfacic.
//
// INPUT DATA   : 
//                - input shape : must be monodomain and surfacic
//                - iInputEdgeList : edge list
//                                   optional
//                                   must be connex
//                                   provide open curve definition
//                                   these edges must belong to the input body
//                - iFilletRadius : radius of the fillet to create between input shape
//                                  and drafted faces
//                                  >= 0
//                - iPullDir : draft direction
//                - iDraftAngle : draft angle
//                                > 0, < 0 or ==0
//                - iAdvancedStampHeight : minimum height of result shape through the iPullDir direction
//                                   > iFilletRadius so > 0                     
//
// OPTIONS      : 
//                - Output dimension      : Surfacic or Volumic.
//                                          By default : Surfacic
//                - TrimSupport           : By default : TRUE
//                - Fillet Representation : By default : TRUE
//
//=============================================================================
// Creation VB7 September 2017
//=============================================================================

#ifndef CATGMAdvancedStampOpe_H
#define CATGMAdvancedStampOpe_H

#include "AdvTrimOpe.h"
#include "CATPersistentOperator.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATFace.h"
#include "CATTopDefine.h"

class CATGeoFactory;
class CATTopData;
class CATGMAdvancedStampImpl;
class CATlsoAdvancedStampInputSpecificData;


class ExportedByAdvTrimOpe CATGMAdvancedStampOpe : public CATPersistentOperator
{
  CATCGMVirtualDeclareClass(CATGMAdvancedStampOpe);

public:

  /**
  * Destructor
  */
  virtual ~CATGMAdvancedStampOpe();

  //------------------
  // Set methods
  //------------------
  //Output dimension
  void SetVolumicMode();
  void SetSurfacicMode();
  void SetLineicMode();

  //Trim support or not
  void SetTrimSupportMode(CATBoolean iTrimSupportMode);

  //Fillet representation in the output or not
  void SetFilletRepresentationMode(CATBoolean iFilletRepresentationMode);

  //For Surfacic/NoTrim/NoFillet Rep only
  void SetAdvancedStampL2Value(double iL2Value);

  //Input Curve representation in the output or not
  void SetCurveRepresentationMode(CATBoolean iCurveRepresentationMode);

  //Smooth Internal Curve
  void SetSmoothInternalCurve(CATBoolean iSmoothInternalCurve=TRUE, double iTangencyThreshold=0.5/*deg*/, double iMaximumDeviation=0.001/*mm*/);// @NumValidated (VB7 - W10 2019)

  //Smooth Input Curve
  void SetSmoothInputCurve(CATBoolean iSmoothInputCurve=TRUE, double iTangencyThreshold=0.5/*deg*/, double iMaximumDeviation=0.001/*mm*/);// @NumValidated (VB7 - W10 2019)

  //Up To
  void SetUpToBody(CATBody * iUpToBody);

  //Fillet Type
  void SetFilletType(int iFilletType);//CATGMAdvancedStamp_FilletType_FromCenterCurve / CATGMAdvancedStamp_FilletType_FromCircularProfile (By Default)

  //For CGM use only
  // @nocgmitf
  void GetOutputDraftedFaceList(ListPOfCATFace & oDraftedFaceList);
  // @nocgmitf
  void GetOutputFilletedFaceList(ListPOfCATFace & oFilletedFaceList);

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

  // @nocgmitf
  void RequireDefinitionOfInputAndOutputObjects();

protected:

  CATGMAdvancedStampImpl * GetGMAdvancedStampImpl();

  /**
  * Protected constructor : Do not call directly.
  * Use CATCreateGMAdvancedStampOpe() instead.
  */
  CATGMAdvancedStampOpe( CATGeoFactory         * iFactory,
                        CATTopData            * iTopData,
                        CATGMAdvancedStampImpl * iImpl );

  //------------------------------------------------------------------------------
  // Forbidden (Declared but not Defined) : Copy constructor & assignment operator
  //------------------------------------------------------------------------------
  CATGMAdvancedStampOpe ( const CATGMAdvancedStampOpe & );            // Not Implemented
  CATGMAdvancedStampOpe & operator=( const CATGMAdvancedStampOpe & ); // Not Implemented

  //-----------------
  // Friend functions
  //-----------------
  // Deprecated W42 2018
  friend ExportedByAdvTrimOpe CATGMAdvancedStampOpe * CATCreateGMAdvancedStampOpe( CATGeoFactory    & iFactory, 
                                                                                 CATTopData       & iTopData, 
                                                                                 CATBody          & iBody, 
                                                                                 double             iFilletRadius, 
                                                                                 CATMathDirection & iPullDir, 
                                                                                 CATAngle         & iDraftAngle, 
                                                                                 double             iAdvancedStampHeight);

  // Deprecated W42 2018
  friend ExportedByAdvTrimOpe CATGMAdvancedStampOpe * CATCreateGMAdvancedStampOpe( CATGeoFactory    & iFactory, 
                                                                                 CATTopData       & iTopData, 
                                                                                 CATBody          & iBody,
                                                                                 ListPOfCATEdge   & iInputEdgeList,
                                                                                 double             iFilletRadius, 
                                                                                 CATMathDirection & iPullDir, 
                                                                                 CATAngle         & iDraftAngle, 
                                                                                 double             iAdvancedStampHeight);

  // Deprecated W42 2018
  friend ExportedByAdvTrimOpe CATGMAdvancedStampOpe * CATCreateGMAdvancedStampOpe( CATGeoFactory    & iFactory, 
                                                                                   CATTopData       & iTopData, 
                                                                                   CATBody          & iBody,
                                                                                   CATBody          & iOpenCurveBody,//wire body. each edge has to belong to iBody
                                                                                   double             iFilletRadius, 
                                                                                   CATMathDirection & iPullDir, 
                                                                                   CATAngle         & iDraftAngle, 
                                                                                   double             iAdvancedStampHeight);

  //New constructor - W42 2018
  friend ExportedByAdvTrimOpe CATGMAdvancedStampOpe * CATCreateGMAdvancedStampOpe( CATGeoFactory            & iFactory,
                                                                                   CATTopData               & iTopData,
                                                                                   CATBody                  & iBody,
                                                                                   CATOrientation             iKeepTopOrBottom,
                                                                                   double                     iFilletRadius, 
                                                                                   CATMathDirection         & iPullDir, 
                                                                                   CATAngle                 & iDraftAngle, 
                                                                                   double                     iAdvancedStampHeight);

  //New constructor - W42 2018
  friend ExportedByAdvTrimOpe CATGMAdvancedStampOpe * CATCreateGMAdvancedStampOpe( CATGeoFactory            & iFactory,
                                                                                   CATTopData               & iTopData,
                                                                                   CATBody                  & iBody,
                                                                                   CATOrientation             iKeepTopOrBottom,
                                                                                   CATBody                  & iOpenCurveBody,
                                                                                   CATOrientation             iKeepRightOrLeft,
                                                                                   double                     iFilletRadius, 
                                                                                   CATMathDirection         & iPullDir, 
                                                                                   CATAngle                 & iDraftAngle, 
                                                                                   double                     iAdvancedStampHeight);

  //For CGMReplay only
  // @nocgmitf
  friend ExportedByAdvTrimOpe CATGMAdvancedStampOpe * CATCreateGMAdvancedStampOpe( CATGeoFactory    & iFactory, 
                                                                                 CATTopData       & iTopData, 
                                                                                 CATBody          & iBody);

  //For Internal Use Only
  // @nocgmitf
  friend ExportedByAdvTrimOpe CATGMAdvancedStampOpe * CATCreateGMAdvancedStampOpe( CATGeoFactory                        & iFactory, 
                                                                                   CATTopData                           & iTopData, 
                                                                                   CATPersistentBody                    & iPersistentBody,
                                                                                   CATlsoAdvancedStampInputSpecificData & iAdvancedStampInputSpecificData,
                                                                                   CATPersistentCellInfra               & iInfra);

};

// ----------------------
// CATCreateGMAdvancedStampOpe
// ----------------------
// Deprecated W42 2018
ExportedByAdvTrimOpe CATGMAdvancedStampOpe * CATCreateGMAdvancedStampOpe( CATGeoFactory    & iFactory, 
                                                                        CATTopData       & iTopData, 
                                                                        CATBody          & iBody, 
                                                                        double             iFilletRadius, 
                                                                        CATMathDirection & iPullDir, 
                                                                        CATAngle         & iDraftAngle, 
                                                                        double             iAdvancedStampHeight);
//For open curve
// Deprecated W42 2018
ExportedByAdvTrimOpe CATGMAdvancedStampOpe * CATCreateGMAdvancedStampOpe( CATGeoFactory    & iFactory, 
                                                                        CATTopData       & iTopData, 
                                                                        CATBody          & iBody,
                                                                        ListPOfCATEdge   & iInputEdgeList,
                                                                        double             iFilletRadius, 
                                                                        CATMathDirection & iPullDir, 
                                                                        CATAngle         & iDraftAngle, 
                                                                        double             iAdvancedStampHeight);

// Deprecated W42 2018
ExportedByAdvTrimOpe CATGMAdvancedStampOpe * CATCreateGMAdvancedStampOpe( CATGeoFactory    & iFactory, 
                                                                          CATTopData       & iTopData, 
                                                                          CATBody          & iBody,
                                                                          CATBody          & iOpenCurveBody,//wire body. each edge has to belong to iBody
                                                                          double             iFilletRadius, 
                                                                          CATMathDirection & iPullDir, 
                                                                          CATAngle         & iDraftAngle, 
                                                                          double             iAdvancedStampHeight);

//New constructor - W42 2018
ExportedByAdvTrimOpe CATGMAdvancedStampOpe * CATCreateGMAdvancedStampOpe( CATGeoFactory            & iFactory,
                                                                          CATTopData               & iTopData,
                                                                          CATBody                  & iBody,
                                                                          CATOrientation             iKeepTopOrBottom,
                                                                          double                     iFilletRadius, 
                                                                          CATMathDirection         & iPullDir, 
                                                                          CATAngle                 & iDraftAngle, 
                                                                          double                     iAdvancedStampHeight);

//New constructor - W42 2018
ExportedByAdvTrimOpe CATGMAdvancedStampOpe * CATCreateGMAdvancedStampOpe( CATGeoFactory            & iFactory,
                                                                          CATTopData               & iTopData,
                                                                          CATBody                  & iBody,
                                                                          CATOrientation             iKeepTopOrBottom,
                                                                          CATBody                  & iOpenCurveBody,
                                                                          CATOrientation             iKeepRightOrLeft,
                                                                          double                     iFilletRadius, 
                                                                          CATMathDirection         & iPullDir, 
                                                                          CATAngle                 & iDraftAngle, 
                                                                          double                     iAdvancedStampHeight);

// ----------------------
// CATCreateGMAdvancedStampOpe
// For CGMReplay Only
// ----------------------
// @nocgmitf
ExportedByAdvTrimOpe CATGMAdvancedStampOpe * CATCreateGMAdvancedStampOpe( CATGeoFactory    & iFactory, 
                                                                        CATTopData       & iTopData, 
                                                                        CATBody          & iBody);

//For Internal Use Only
// @nocgmitf
ExportedByAdvTrimOpe CATGMAdvancedStampOpe * CATCreateGMAdvancedStampOpe( CATGeoFactory                        & iFactory, 
                                                                          CATTopData                           & iTopData, 
                                                                          CATPersistentBody                    & iPersistentBody,
                                                                          CATlsoAdvancedStampInputSpecificData & iAdvancedStampInputSpecificData,
                                                                          CATPersistentCellInfra               & iInfra);

#endif /* CATGMAdvancedStampOpe_H */
