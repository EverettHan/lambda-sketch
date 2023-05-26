// COPYRIGHT DASSAULT SYSTEMES 2020, ALL RIGHTS RESERVED.
//=================================================================================
// CATMultiConeSupportFillet:
//  Interface of fillet operator around multiple cones or cylinders supports for additive manufacturing 
//=================================================================================
// 10 07 2020 TAT3 Creation 

#ifndef CATMultiConeSupportFillet_H
#define CATMultiConeSupportFillet_H

#include "CATMultiSupportFillet.h"
#include "AdvTopoOpeItf.h"



/** @class Operator that builds a list of fillets from a list of cone supports.

This operator follows the general scheme of the topological operators producing several resulting bodies :

Create the operator with the global function CATPGMCreateMultiConeSupportFillet
Set the parameters(Cone List, Fillet Radii, Tesselation SAG)
Run,
Get the resulting bodies(in this case, use the iterator on the resulting bodies, because several bodies can be solution of the computation).

<pre>
CATIPGMMultiConeSupportFillet * pOp = CATPGMCreateMultiConeSupportFillet(pGeoFactory, pTopData, config);
pOp->SetTopConesList(NbCones, ListOfTopCenter, ListOfBottomCenter, ListOfInnerAngle, ListOfConeRadii);
pOp->SetOutpuMeshSAG(0.01);
pOp->SetFilletRadius(filletRadius);

pOp->Run();

pOp->BeginningResult();

for (int i = 0; i < pMultiFilletOp->GetNbOfFillets(); i++) {
  pOp->NextResult();
  CATIPolyMesh *pCurrentMeshRes = pOp->GetMeshResult();
}
pOp->Release()
< / pre >
*/
class ExportedByAdvTopoOpeItf CATMultiConeSupportFillet : public CATMultiSupportFillet {
  CATCGMVirtualDeclareClass(CATMultiConeSupportFillet);
public:
  /**
   *
   * WARNING: DO NOT USE this constructor
   * USE CATCreateMultiConeSupportFillet to create class object
   *
   * Constructs a MultiConeSupportFillet operator.
   * @param iFactory
   * The pointer to the factory of the geometry.
   * @param config
   * The pointer to the Softwareconfiguration.
   */
  CATMultiConeSupportFillet(CATGeoFactory *iFactory, CATSoftwareConfiguration *config);

  virtual ~CATMultiConeSupportFillet();

  /** @brief Define the Input list of cone upper supports to fillet at the joint with the tray.
* @param iNbOfPoints Total of suoports to fillet. Defines the size of all the other arguments
* @param iListOfTopCenter Upper limit of the cone on the axis.
* @param iListOfBottomCenter Lower Limit of the cone on the axis.
* @param iListOfInnerAngle Inner angle of the cone. 0 < iListOfInnerAngle <= CATPIBY2. If equal to CATPIBY2, the support is a Cylinder.
* @param iConeRadii List of the radii of each cone taken orthogonal to cone axis around TopCenter point.
<pre>
    +------------------------------------------------------------+
    |                                             --/  /         |
    |                          InnerAngle       -/   -/          |
    |                              |         --/    /            |
    |                              |      --/      /             |
    |                              |    -/        /              |
    |                              V --/         /               |
    |                              / )         _/                |
    |                           -\    )        /                 |
    |                         -/   \ )        /                  |
    |------------------------/       o _     / ------------------| Joint between fillet and cone support
    |                    -/             \ <-------- TopRadius    |
    |                 --/  TopCenter     /                       |
    |               -/                  /                        |
    |            --/                   /                         |
    |         --/                     /                          |
    |       -/                       /                           |
    |    --/           BottomCenter /                            |
    |  -/            o            /                              |
    +------------------------------------------------------------+ Tray
    </pre>
*/
  virtual void SetTopConesList(int iNbOfPoints, const CATMathPoint* iListOfTopCenter, const CATMathPoint* iListOfBottomCenter, const CATAngle * iListOfInnerAngle, const double *iConeRadii) = 0;

  /**
   * Runs <tt>this</tt> operator.
   * <br>To retrieve the resulting bodies, use the iterator on the bodies provided by @href CATTopMultiResult.
   */
  int Run();

  /**
  * @nodoc Summary. 
  */
  void Summary();

protected:
  // Input Cone Informations
  CATMathPoint * _ListOfTopCenter;
  CATMathPoint *_ListOfBottomCenter;
  CATAngle *_ListOfInnerAngle;
  double *_ListOfConeRadii; // Radius orthogonal to cone axis, around the Top Center
  //std::vector< double> _ListOfConeRadii;

  //---------------------------------------------------------------
  // For CGMReplay
  //---------------------------------------------------------------
  /** @nodoc */
  static CATString _OperatorId;

  const CATString * GetOperatorId() { return &_OperatorId; };

  /** @nodoc */
  CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);

  /** @nodoc */
  void WriteInput(CATCGMStream  & ioStream);

  /** @nodoc */
  void Dump(CATCGMOutput& os);

  /** @nodoc */
  void RequireDefinitionOfInputAndOutputObjects();

  /** @nodoc */
  void DumpOutput(CATCGMOutput& os);

  /** @nodoc */
  CATCGMOperator::CATCheckDiagnostic  CheckOutput(CATCGMOutput & os);

  //---------------------------------------------------------------
};


// Global create defined in MultiConeSupportFilletImpl.cpp
/** @brief Global function to create instance of MultiConeSupportFillet.
* @param iFactory Pointer to the geometry factory that create the result bodies.
* @param iConfig Pointer to the software configuraiton.
*/
ExportedByAdvTopoOpeItf CATMultiConeSupportFillet *CATCreateMultiConeSupportFillet(CATGeoFactory *iFactory,  CATSoftwareConfiguration *config);


#endif

