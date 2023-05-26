#ifndef CATThickSurfacePlus_H
#define CATThickSurfacePlus_H

// COPYRIGHT DASSAULT SYSTEMES  2006

#include "CATMathDef.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATEdge.h"
#include "CATListOfCATCells.h"
#include "CATListOfDouble.h"
#include "CATListOfInt.h"
#include "CATCleverOffset.h"
#include "CATGeoToTopOperator.h"
#include "CATTopOperator.h"
#include "CATDynOperator.h"

class CATTopData;
class CATBody;
class CATShell;
class CATFace;
class CATThickSurface;
class CATRegul;
class CATThicken;
class CATlsoProgressBarManager;
class CATString;

/**
	* Class defining the operator to thicken a body in two opposite directions
	* according to the offsets specified for the thickening operation.
	* <br>
	* <ul>
	* <li>A CATThickSurfacePlus operator is created with the 
	* <tt>CATCreateThickSurface</tt> global function:
	* It must be directly deleted with the usual C++ <tt>delete</tt> operator after use.
	* It is not streamable. 
	*<li>Options must be specified with the appropriate methods, before
	* asking for the computation with the <tt>Run</tt> method. 
	*<li>The result is accessed with the <tt>GetResult</tt> method. If you do not want 
	* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
	* geometric factory.
	* </ul>
 */  
class ExportedByCATCleverOffset CATThickSurfacePlus : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATThickSurfacePlus);
public:

 /**
  * @nodoc
	* Virtual constructor of a CATThickSurfacePlus operator.<br>
	* Cannot be called. Use the <tt>CATCreateThickSurface</tt> global function
	* to create a CATThickSurfacePlus operator.
	*/
  CATThickSurfacePlus(CATTopData * iTopData, 
                      CATBody    * iBodyToThick,
                      double       iOffset_1,
                      double       iOffset_2);


  /**
  * @nodoc
  * Destructor.
  */
  virtual ~CATThickSurfacePlus();

  /**
  * @nodoc
  * Defines specific values for a given face.
  * @param iFace
  * The face whose offsets are different from those specified at the operator creation.
  */
  void Append(CATFace *iFace, double iOffset1, double iOffset2);

  /**
  * @nodoc 
  * To activate/deactivate tangency propagation for faces with special offset values.
  * If not set, there is no propagation.
  */
  void SetSpecialOffsetFacesPropagation(short iPropagation);

  /** @nodoc 
  * Returns partial result if complete result cannot be computed
  * when iPartialResultMode = 1.
  * Federation is not taken into account */
  void SetPartialResultMode(short iPartialResultMode);

  /**
  * @nodoc
  * @param oTrickyFaces
  * @param iOffsetIndex (0/1)
  * 
  */
  void GetTrickyFaces(CATLISTP(CATFace) &oTrickyFaces);

    /**
  * @nodoc
  * Returns the list of result faces that were smoothed during operation.
  * 
  */
  void GetSmoothedResultFaces(CATLISTP(CATFace) &oSmoothedResultFaces);

  
  /**
  * @nodoc
  * Returns the list of faces which cannot be offsetted.
  * @param oTrickyFaces
  * The list of tricky faces.
  * @param iOffsetIndex (0/1)
  * The face indexes.
  * 
  */
  void GetAllTrickyFaces(CATLISTP(CATFace) &ioAllTrickyFaces, 
    CATListOfInt      &ioAllDiag);

  /**
  * Sets the "mixed offset" options. <br> 
  * @param iWithRegul
  * <dl><dt><tt>1</tt><dd> Regularization of the faces that cannot be offsetted accurately due to their geometry.
  *     <dt><tt>0</tt><dd> No regularization</dl>
  */
  void SetOffsetMixte(CATBoolean iWithRegul); 

  /**
  * Requires a local smoothing of a face when this face cannot be offsetted as a whole.
  * This option can result in additional faces. It can only be activated when the 
  * SetOffsetMixte method is used to ask for a surface "regularization".
  * @param iLocalRegul
  * <dl><dt><tt>TRUE</tt><dd> The local regularization is activated.
  *     <dt><tt>FALSE</tt><dd> The local regularization is not activated.</dl>
  */
  void SetLocalRegularization(CATBoolean iLocalRegul);

  /**
  * Sets the deviation allowed by the user. 
  * @param iDeviation
  * The value of the deviation. This value must be positive.				
  */
  void SetDeviationAllowed(CATLength iDeviation);

  /**
  * Sets the deviation mode.
  * @param iWithDeviation
  * <dl><dt><tt>TRUE</tt><dd> the regularizator uses the deviation value which is specified by the user.
  *     <dt><tt>FALSE</tt><dd> the regularizator does not use the user value (default value). 
  * </dl>
  */
  void SetDeviationMode(CATBoolean iWithDeviation);

  /**
  * Asks for a constant thickness for the resulting shell when one of the offset values is null.
  * Applies only when the regularization is activated (SetOffsetMixte)
  * @param iConstantThickness
  * <dl><dt><tt>TRUE</tt><dd> Default mode: the smoothed/regularized face with null offset is keep in the resulting shell
  *     <dt><tt>FALSE</tt><dd> The input face with null offset is not modified.</dl>
  */
  void SetConstantThickness(CATBoolean iConstantThickness=TRUE);


  /**
  * @nocgmitf
  * Defines if procedural Offset surfaces must be approximated and
  * replaced by NurbsSurface
  * @param iApproxOffsetMode
  * <br><b>Legal values:</b>
  * <dl><dt>0</dt><dd>Approximation not required
  * <dt>1</dt><dd>Approximation required in C1 mode
  * <dt>2</dt><dd>Approximation required in C2 mode
  * @param iPostProRequired
  * <br><b>Legal values:</b>
  * <dl><dt>0</dt><dd>Approximation required during Offset algorithm
  * <dt>1</dt><dd>Approximation required after Offset algorithm
  * </dl>
  */
  void SetApproxOffsetMode(short iApproxOffsetMode, short iPostProRequired=1);

  /**
  * @nocgmitf
  * Defines the tolerance for C1 approximation 
  * @param iTolC1
  * The tolerance for C1 approximation.
  * </dl>
  */
  void SetToleranceForApproxC1(double iTolC1);

  /**
  * @nocgmitf
  * Defines the tolerance for C2 approximation 
  * @param iTolC2
  * The tolerance for C2 approximation.
  * </dl>
  */
  void SetToleranceForApproxC2(double iTolC2);
  
 	/**
   * @nodoc
	 * Defines a Boolean operation between a given body and the result of 
	 * <tt>this</tt> operator.
	 * @param iOpType
	 * The boolean operation type.
	 * @param iOperandBody
	 * The pointer to the body representing the first operand of the Boolean operation. 
	 * The second operand is the result of the thicken.
	 * @param iReport
	 * A pointer to the journal corresponding to the Boolean operation. This journal can be different
	 * from the journal of the thicken operation itself. If <tt>NULL</tt>, the Boolean journal
	 * is not written.
	 */
  void SetBooleanOperation(CATDynBooleanType   iOpType, 
                           CATBody           * iOperandBody, 
                           CATCGMJournalList * iReport=0);

  
  /**
  * Smoothes lateral ribbon and keeps smooth lateral edges where initial border edges
  * were in smooth contact. Lateral faces are no longer normal to input surface.
  * @param iG1HealingMode
  * <dl><dt><tt>TRUE</tt><dd> activates the G1 healing mode.
  *     <dt><tt>FALSE</tt><dd> deactivates the G1 healing mode (default value). 
  * </dl>
  */
  void SetG1HealingMode(CATBoolean iG1HealingMode);

  /**
  * Sets a maximum deviation on lateral faces if the smoothing deviation exceeds the
  * input tolerance, then the lateral edges are not smoothed.
  * @param iG1HealingTolerance
  * The healing tolerance. By default, the thickness value.
  */
  void SetG1HealingTolerance(double iG1HealingTolerance);

  /**
  * iG1TargetAngle if iG1HealingMode is TRUE
  * Sets a target angle for lateral faces to smooth
  * @param iG1TargetAngle
  * The target angle value. Min angle = 0.5 degrees, Max angle = 5 degrees.
  */
  void SetG1TargetAngle(double iG1TargetAngle);

  /**
  * Simplifies geometry and topology of lateral ribbon.
  * @param iRibbonSimplification
  * <dl><dt><tt>TRUE</tt><dd> activates the simplification option.
  *     <dt><tt>FALSE</tt><dd> deactivates the simplification option (default value). 
  */
  void SetRibbonSimplification(CATBoolean iRibbonSimplification);

  /**
  * @nodoc
  * same rules as TrimByThick when iAlignOnTrimByThickBehavior is set to 1
  * (allow unsolved topology...).
  */
  void SetAlignOnTrimByThickBehavior(short iAlignOnTrimByThickBehavior=1);

  /**
  * Runs the operator
  */
  int Run();

  /**
  * Returns the pointer to the resulting body.
  * @return
  * The pointer to the resulting body, <tt>NULL</tt> if the operation failed. 
  * If you do not want to keep the resulting body, 
  * use the @href CATICGMContainer#Remove method to remove it from the 
  * geometric factory, after the operator deletion.
  */
  CATBody* GetResult() ;

  /**
   * @nodoc
	 * Returns the body created from the Boolean operation between a given body and the thickened body.
	 * @return
	 * The pointer to the Boolean result.
	 * If you do not want to keep the resulting body, 
   * use the @href CATICGMContainer#Remove method to remove it from the 
   * geometric factory, after the operator deletion.
	 */
  CATBody * GetBooleanResult();

  //-----------------------------------------------------------------------
  //- Gestion pour CGMReplay
  //-----------------------------------------------------------------------  
  /** @nodoc @nocgmitf definition des Objets  ...*/
  void RequireDefinitionOfInputAndOutputObjects();

  /** @nodoc @nocgmitf declaration integre au CGMReplay */
  CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);

  /** @nodoc @nocgmitf ID pour CGMReplay */
  virtual void DumpOutput(CATCGMOutput &os);

  /** @nodoc @nocgmitf ID pour CGMReplay */
  virtual void WriteInput(CATCGMStream  & os);

  /** @nodoc @nocgmitf ID pour CGMReplay */
  virtual void Dump( CATCGMOutput& os ) ;

  /** @nodoc @nocgmitf ID pour CGMReplay */
  static const CATString * GetDefaultOperatorId();
  
  /** @nodoc @nocgmitf ID pour CGMReplay */
  virtual const  CATString * GetOperatorId();

  /** @nodoc @nocgmitf */
  virtual void ReadInput(CATCGMStream  & ioStream,int VersionOfStream, short iNumReplayVersion=1);

  /** @nodoc @nocgmitf */
  virtual int RunOperator();

  /** @nodoc @nocgmitf */
  inline void SetCGMMode(short iCGMMode);


private:

  int Compute();

  void ThrowConstantThicknessOffThickSurfaceError();

  void GetLocalTrickyFaces(CATThickSurface *iThickSurface, CATLISTP(CATFace) &oTrickyFaces, short iUpdate = 0);

  void UpdateThickSurfaceRegul();

  void ComputeRegulFacesOnResult(CATLISTP(CATFace) &iTrickyFaces);

   // operation booleennes optionnelle
  void BooleanOperation();

  // post-pro de TrimSew avec la skin initiale si option _ConstantThickness a FALSE.
  void ConcatenateWithInitialBody(CATLISTP(CATFace) &iRegulFaces);
  void ConcatenateWithInitialBodyOld(CATLISTP(CATFace) &iRegulFaces);

  // renvoie l'image d'offset iOffsetIndex dans le journal du ThickSurface de la face iInitFace
  // appartenant a _InitialBody 
  CATFace * GetOffsetImageFaceFromJournal(CATFace *iInitFace, CATLONG32 iOffsetIndex);

  void GetOffsetImageFacesFromJournal(CATLISTP(CATFace) & iListInitFaces, CATLONG32 iOffsetIndex, ListPOfCATFace & oListFaces, 
    CATCGMJournalList *iJournal=NULL);

  // recupere le shell contenant iFace dans iBody
  CATShell * GetShellFromFaceInBody(CATBody *iBody, CATFace *iFace); 

  // creation d'un body a partir d'une liste de cellules
  CATBody * CreateSkinFromCells(CATLISTP(CATCell) &iCells, CATBody *iOwningBody=NULL);

  // recupere la liste d'edges mortes bordant iFace dans iBody ainsi 
  // que leur orientation respective.
  void GetListOfFreeEdge(CATFace *iFace, CATBody *iBody,
    ListPOfCATEdge &oListOfFreeEdges, CATListOfInt &oSideSkinOnListOfFreeEdge);

  // Detection de faces C1 dans le body
  int DetectC1Factory();

  CATThickSurface *    _ThickSurface;
  CATRegul *           _RegulOp;
  CATThickSurface *    _SecondThickSurface;

  CATThicken *         _ThickenOp; // temporaire pour supporter le C1

  ListPOfCATFace       _AllTrickyFaces;
  CATListOfInt         _AllDiagList; // liste parallele a _AllTrickyFaces

  CATBody *            _InitialBody;
  CATBody *            _RegularizedBody;
  
  // pour l'operation booleenne.
  CATBody *            _BooleanOperationBody;
  CATBody *            _BooleanOperationResultBody;
  CATCGMJournalList *  _BooleanOperationReport;
  CATDynBooleanType    _BooleanOperationType;

  // valeurs d'offset
  double               _OffsetVals[2];
  ListPOfCATFace       _SpecialOffsetFaces;
  CATListOfDouble      _SpecialOffsetValues1;
  CATListOfDouble      _SpecialOffsetValues2;
  short                _SpecialOffsetPropagationMode;

  // valeur d'offset sur faces regularisees
  CATLISTP(CATFace)    _SpecialRegulFaces;
  // listes des valeurs d'offset, parallele a _SpecialOffsetFaces/_SpecialOffsetRegulFaces
  CATListOfDouble      _SpecialRegulValues1;
  CATListOfDouble      _SpecialRegulValues2;

  CATLISTP(CATFace)    _ResultRegulFaces;
  
  CATBoolean           _WithRegul; // FALSE : Sans. Par defaut
                                   // TRUE : Avec Offset Mixte

  CATBoolean           _LocalRegul; // TRUE : nouveau code de regul qui decoupe les faces
                                    // FALSE : ancien code

                               
  // Variables pour la deviation max autorisée par l'utilisateur
  CATLength            _DeviationAllowed;
  CATBoolean           _WithDeviation;
  CATBoolean           _ConstantThickness; // 1 : epaisseur constante par defaut
                                           // 0 : faces d'offset nul identiques aux faces input.

  // pour le mode approx
  short               _ApproxOffsetMode;
  short               _PostApproxRequired;
  double *            _TolApproxC1;
  double *            _TolApproxC2;

  
  CATBoolean          _G1HealingMode;
  double              _G1HealingTolerance;
  double              _G1TargetAngle;
  short               _G1TargetAngleHasBeenSet;

  CATBoolean          _RibbonSimplification;

  short               _PartialResultMode;

  short               _AlignOnTrimByThickBehavior;

  //Variable de numero de versionning en attendant le context
  int                 _CGMVersionNumber;

  short               _CGMMode;

  // Gestion des progress bars
  CATlsoProgressBarManager * _ProgressBarManager;

/**
 * @nodoc 
 * Copy constructor. Not implemented
 */
  CATThickSurfacePlus(CATThickSurfacePlus& iOperator);

/**
 * @nodoc 
 * Affectation operator. Not implemented
 */
  CATThickSurfacePlus& operator=(const CATThickSurfacePlus & iOperator);

};


// methodes inline

inline void CATThickSurfacePlus::SetCGMMode(short iCGMMode) {
  _CGMMode = iCGMMode; }

#endif
