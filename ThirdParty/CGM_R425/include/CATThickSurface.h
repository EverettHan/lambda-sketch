#ifndef CATThickSurface_H
#define CATThickSurface_H

// COPYRIGHT DASSAULT SYSTEMES  2001

#include "CATTopOperator.h"
#include "CATString.h"
#include "Thick.h"
#include "ListPOfCATFace.h"
#include "CATTopDefine.h"
#include "CATBoolean.h"

class CATTopData;
class CATBody;
class CATEdge;
class CATFace;
class CATShell;
class CATOpThickSurface;
class CATlsoProgressBarManager;

/**
	* Class defining the operator to thicken a body in two opposite directions
	* according to the offsets specified for the thickening operation.
	* <br>
	* <ul>
	* <li>A CATThickSurface operator is created with the 
	* <tt>CATCreateThickSurface</tt> global function:
	* It must be directly deleted with the usual C++ <tt>delete</tt> operator after use.
	* It is not streamable. 
	*<li>Options must be specified with the appropriate methods, before
	* asking for the computation with the <tt>Run</tt> method. 
	*<li>The result is accessed with the <tt>GetResult</tt> method. If you do not want 
	* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
	* geometric factory.
	*</ul>
 */  
class ExportedByThick CATThickSurface : public CATTopOperator
{

  CATCGMVirtualDeclareClass(CATThickSurface);
public:

 /**
    * @nodoc
	* Virtual constructor of a CATThickSurface operator.<br>
	* Cannot be called. Use the <tt>CATCreateThickSurface</tt> global function
	* to create a CATThickSurface operator.
	*/
  CATThickSurface(CATTopData * iTopData, 
                  CATBody    * iBodyToThick,
                  double       iOffset_1,
                  double       iOffset_2,
                  short        iDefaultSideForAllShells);


 /**
    * @nodoc
	* Destructor.
	*/
  virtual ~CATThickSurface();

  
	/**
   * Specifies the orientation of a shell belonging to the body to be thickened.
   * @param iShellToThick
   * The shell the orientation is to be specified.
   * @param iCoefOriVsOffsetValues
   * The value to be specified for the iCoefOriVsOffsetValues argument are
   * (other values to be rejected)
   * <ul>
   * <li>iCoefOriVsOffsetValues = +1 - Reference orientations of the iOffset_1 and iOffset_2 values.
   * <li>iCoefOriVsOffsetValues = -1 - Orientation opposite to the offset orientation.
   * </ul>
   * <br>
   * Given Vn the normal vector of the CATShell and
     * given VOffset_1 the offset vector to obtain the Offset_1 skin.
   * <br>VOffset_1 = (iCoefOriVsOffsetValues x iOffset_1 ) . Vn
     * <br>Given VOffset_2 the offset vector to obtain the Offset_2 skin.
   * VOffset_2 = (iCoefOriVsOffsetValues x iOffset_2 ) . Vn
   */
  void SetCoefOriForShellToThick(CATShell * iShellToThick,
                               short iCoefOriVsOffsetValues);

  /**
   * iG1HealingMode = TRUE or FALSE.
   */
  void SetG1HealingMode(CATBoolean iG1HealingMode);

  /**
   * iG1HealingTolerance if iG1HealingMode is TRUE.
   */
  void SetG1HealingTolerance(double iG1HealingTolerance);

  /**
  * iG1TargetAngle if iG1HealingMode is TRUE. Sets a target angle for lateral faces to smooth. Min angle = 0.5 degrees, Max angle = 5 degrees.
  */
  void SetG1TargetAngle(double iG1TargetAngle);

  /**
	 * Retrieves the body to be thickened. 
	 */
  CATBody * GetBodyToThick();

  /**
	 * Retrieves the first offset
	 */
  double GetOffset_1();

	/**
   * Retrieves the second offset
   */
  double GetOffset_2();

  /**
  * @nodoc
  * Defines specific values for a given face.
  * @param iFace
  * The face whose offsets are different from those specified at the operator creation.
   * 
   */
  void Append(CATFace *iFace, double iOffset1, double iOffset2);

  /**
  * @nodoc 
  * To activate/deactivate tangency propagation for faces with special offset values.
  * If not set, there is no propagation.
  */
  void SetSpecialOffsetFacesPropagation(short iPropagation);

  /**
   * @nodoc
   * @param iFacesToRemove
   * @param iOffsetIndex (0/1)
   * 
   */
  void SetMandatoryFacesToRemove( const CATLISTP(CATFace) &iFacesToRemove,
                                  short iOffsetIndex );

  /**
   * @nodoc
   * @param oTrickyFaces
   * @param iOffsetIndex (0/1)
   * 
   */
  void GetTrickyFaces(CATLISTP(CATFace) &oTrickyFaces);

  // Retour de la liste exhaustive des faces posant probleme, 
  // accompagnee de la liste parallele de diagnostics
  void GetAllTrickyFaces(CATLISTP(CATFace) &ioAllTrickyFaces, 
    CATListOfInt      &ioAllDiag);

  /**
   * @nodoc
   * @param oFacesToIgnore 
   * @param iOffsetIndex (0/1)
   * 
   */
  void GetFacesToIgnore(CATLISTP(CATFace) &oFacesToIgnore, short iOffsetIndex);
    
  /**
   * @nodoc
   * @param oFacesToRegularise
   * @param oDiag
   * <br><b>Legal values:</b>
   * <dl><dt>0</dt><dd>Regularisation not required [forbidden output value]
   * <dt>1</dt><dd>Optimization required for local curvature problem
   * <dt>2</dt><dd>Optimization required for singular point
   * <dt>3</dt><dd>Optimization required for extrapolation failure
   * </dl>
   */
  void GetFacesToRegularise(CATLISTP(CATFace) &oFacesToRegularise, CATListOfInt &oDiag);

  /**
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
    * Defines the tolerance for C1 approximation 
	  * @param iTolC1
    * </dl>
    */
  void SetToleranceForApproxC1(double iTolC1);

  /**
    * Defines the tolerance for C2 approximation 
	  * @param iTolC2
    * </dl>
    */
  void SetToleranceForApproxC2(double iTolC2);

   /**
   * If TRUE, side ribbons are simplified
   * Default value is FALSE.
   */
  void SetRibbonSimplification(CATBoolean iRibbonSimplification);

  /**
  * @nodoc
  * same rules as TrimByThick when iAlignOnTrimByThickBehavior is set to 1
  * (allow unsolved topology...).
  */
  void SetAlignOnTrimByThickBehavior(short iAlignOnTrimByThickBehavior=1);

  // Execution de l'operation ThickSurface OneStepVolume  (RunOperator ne doit servir qu'en mode
  // CGMReplay)
  int Run();

  //-----------------------------------------------------------------------
  //- Gestion pour CGMReplay
  //-----------------------------------------------------------------------  
   /** @nodoc @nocgmitf definition des Objets  ...*/
   void RequireDefinitionOfInputAndOutputObjects();

   /** @nodoc @nocgmitf declaration integre au CGMReplay */
  CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);

   /** @nodoc @nocgmitf ID pour CGMReplay */
  virtual void WriteInput(CATCGMStream  & os);

   /** @nodoc @nocgmitf ID pour CGMReplay */
  virtual void Dump( CATCGMOutput& os ) ;

   /** @nodoc @nocgmitf ID pour CGMReplay */
  void DumpOutput(CATCGMOutput &os);

   /** @nodoc @nocgmitf ID pour CGMReplay */
  static const CATString * GetDefaultOperatorId() { return & _OperatorName; };



  /** @nodoc @nocgmitf */
  virtual void ReadInput(CATCGMStream  & ioStream,int VersionOfStream, short iNumReplayVersion=1);

  /** @nodoc @nocgmitf */
  virtual int RunOperator();

  short _CurrentThickIndex;



protected:
 
  CATOpThickSurface * _OpImpl;
  
  /**
	 * @nodoc
	 * Internal use.
	 */
  friend CATCGMOutput& operator<< (CATCGMOutput& s, const CATThickSurface& iOpe);

  /** @nodoc  */
  virtual CATCellManifoldsManager* CreateCellManifoldsManager(ListPOfCATBody &iListOfCopyInputBodies, ListPOfCATBody &iListOfNoCopyInputBodies,
    CATBody * iOutputBody, CATCGMJournalList* iTopOpJournal);

  // A ProgressBar manager
  CATlsoProgressBarManager * _ProgressBarManager;

private:

  // Operator generic name 
  static CATString _OperatorName;


/**
 * @nodoc 
 * Copy constructor. Not implemented
 */
  CATThickSurface(CATThickSurface& iOperator);

/**
 * @nodoc 
 * Affectation operator. Not implemented
 */
  CATThickSurface& operator=(const CATThickSurface & iOperator);

};

/** 
	* Creates a CATThickSurface operator.
	* @param iTopData
  * Contains a CATSoftwareConfiguration and a CATCGMJournalList
	* @param iBodyToThick
	* The pointer to the body (p CATShells) to be thickened. 
	* @param iOffset_1
  * first offset value for iBodyToThick
	* @param iOffset_2
  * second offset value for iBodyToThick
  * There are 2 conditions about iOffset_1 and iOffset_2 :
	* <ul>
  * <li>they have the same orientation reference
  * <li>Second, they have to be different.
	*</ul>
  */
  ExportedByThick CATThickSurface * CATCreateThickSurface(CATTopData * iTopData, 
                                                          CATBody    * iBodyToThick,
                                                          double       iOffset_1,
                                                          double       iOffset_2,
                                                          short        iDefaultSideForAllShells=1);

#endif
