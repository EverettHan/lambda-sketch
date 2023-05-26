#ifndef CATSkinExtrapolThickPlus_h
#define CATSkinExtrapolThickPlus_h

// COPYRIGHT DASSAULT SYSTEMES 2006

/**
 * Class representing an operator that extrapolates a shell body.
 *<br>The edges to extrapolate must be on the boundary of the shell, or 
 * must lie on a bounding edge of the shell.
 *<br>The extrapolation values can be different for each edge. A positive
 * value defines an extrapolation along the outside direction of the shell.
 *<br>The extrapolation gives a result that is continuous in curvature.
 * To use it:
 * <ul>
 * <li>Create it with the <tt>CATCreateSkinExtrapol</tt> global function.
 * <li>Tune it with appropriate options, using the <tt>SetXxx</tt> methods. 
 * <li>Run it
 * <li>Get the resulting body, using the <tt>GetResult</tt> method. If you do not want 
 * to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
 * geometric factory, after the operator deletion.
 *<li>Delete it after use  with the usual C++ <tt>delete</tt> operator.
 *</ul> 
 */

#include "CATMathDef.h"
#include "CATMathInline.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATFace.h"
#include "CATListOfCATCells.h"
#include "CATListOfDouble.h"
#include "Thick.h"
#include "CATGeoToTopOperator.h"
#include "CATTopOperator.h"
#include "CATString.h"
#include "CATThick.h"

class CATThick;
class CATRegul;
class CATBody;
class CATFace;
class CATEdge;
class CATGeoFactory;
class CATCGMJournalList;
class CATCGMJournalInfo;
class CATCGMOutput;
class CATTopData;
class CATlsoProgressBarManager;

class ExportedByThick CATSkinExtrapolThickPlus : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATSkinExtrapolThickPlus);
public:

  // constructeur
  CATSkinExtrapolThickPlus(CATBody * iSkin, CATTopData * iTopData);

  // destructeur
  ~CATSkinExtrapolThickPlus();

  /**
  * Sets the ability to later modify the resulting body.
  * @param iFreezeMode
  * The freeze mode.
  */
  void SetFreezeMode(CATBodyFreezeMode iFreezeMode);

  /**
  * Appends a list of edges to extrapolate.
  * It replaces the current value of an already selected edges by <tt>iExtrapolValue</tt>.
  * @param iBoundaryEdges
  * The list of edges to append.
  * @param iExtrapolValue
  * The common extrapolation value for all the edges of the <tt>iBoundaryEdges</tt> list.
  */
  void Append( CATLISTP(CATEdge) & iBoundaryEdges, CATLength iExtrapolValue ) ;

  /**
  * Appends an edge to extrapolate.
  * It replaces the current value of an already selected edges by <tt>iExtrapolValue</tt>.
  * @param iBoundaryEdge
  * The edge to append.
  * @param iExtrapolValue
  * The extrapolation value for the <tt>iBoundaryEdge</tt> edge.
  */
  void Append(CATEdge* iBoundaryEdge, CATLength iExtrapolValue ) ;

  /**
  * Selects all the edges of the shell boundary and sets to them a common extrapolation value.
  * @param iExtrapolValue
  * The new current extrapolation value of the already selected edges.
  */
  void SetDefaultExtrapolationValue( CATLength iExtrapolValue );

  /**
  * Defines the propagation mode of the extrapolation value.
  * @param iPropagationMode
  *<dl>
  *<dt><tt>0</tt></dt><dd> No propagation of the extrapolation value.
  *<dt><tt>1</tt></dt><dd> Defines the automatic definition of the extrapolation value on an edge
  * to the one of its tangential adjacent edges.
  * This mode is used by default at the creation of the operator.
  *</dl>
  */
  void SetPropagationMode(short iPropagationMode);

  /**
  * @nodoc
  * Defines the relimitation mode from all boundary extremities in SkinExtrapolation operator.
  * @param iExtremitiesMode
  *<dl>
  *<dt><tt>0</tt></dt><dd> Extrapolate adjacent edges to cut the offset boundary.
  * This mode is used by default at the creation of the operator.
  *<dt><tt>1</tt></dt><dd> Add junction edges in normal direction of boundary extremities
  *</dl>
  */
  void SetExtremitiesMode(short iExtremitiesMode);

  /**
  * @nodoc
  * Keep geometry of edges to relimit
  * (not compatible with Normal mode or propagation OFF)
  */
  void SetKeepBorderEdgeCurves();

  /**
  * @nodoc
  * To obtain a partial result when all edges cannot be extrapolated.
  * Edges that couldn't be extrapolated can be retrieved with GetTrickyEdges method.
  * @param iPartialExtrapolationAllowed
  *<dl>
  *<dt><tt>0</tt></dt><dd> No partial extrapolation.
  * This mode is used by default at the creation of the operator.
  *<dt><tt>1</tt></dt><dd> Partial Extrapolation allowed.
  *</dl>
  */
  void SetPartialExtrapolationAllowed(short iPartialExtrapolationAllowed);

  /**
  * @nodoc
  * Defines the level of approximation allowed for the boundary of the result skin (robustness mode).
  * @param iApproximateExtrapolationLevel
  *<dl>
  *<dt><tt>0</tt></dt><dd> No Approximation.
  * This mode is used by default at the creation of the operator.
  *<dt><tt>1</tt></dt><dd> Approximation allowed (level 1).
  *</dl>
  */
  void SetApproximateExtrapolationLevel(short iApproximateExtrapolationLevel);

  /**
  * @nodoc
  * Defines whether the result should contain the whole extrapolated surface or only the extrapolated area.
  * @param iKeepOnlyExtrapolatedArea
  *<dl>
  *<dt><tt>0</tt></dt><dd> The whole extrapolated surface is returned.
  * This mode is used by default at the creation of the operator.
  *<dt><tt>1</tt></dt><dd> The result contains the extrapolated area only.
  *</dl>
  */
  void SetKeepOnlyExtrapolatedArea(short iKeepOnlyExtrapolatedArea);

  /**
  * @nodoc
  * Enables or disables twist detection.
  * @param iTwistDetection
  *<dl>
  *<dt><tt>0</tt></dt><dd> Twist detection is disabled : result skin may lie on twisted surfaces.
  * This mode is used by default at the creation of the operator.
  *<dt><tt>1</tt></dt><dd> Twist detection is enabled : extrapolation is not possible if a twist is detected.
  *</dl>
  */
  void SetTwistDetection(short iTwistDetection);

  /**
  * @nodoc
  * Enables or disables deviation checking.
  * @param iWithDeviation
  * <dl>
  * <dt><tt>1</tt><dd> Check if surface deviations are below maximum value.
  * This value can be provided by the user through <tt>SetDeviationAllowed</tt> method.
  * Default value is the factory resolution
  * <dt><tt>0</tt><dd> No deviation checking is performed
  * This mode is used by default at the creation of the operator.
  * </dl>
  **/
  void SetDeviationMode(short iDeviationMode);

  /**
  * @nodoc
  * Defines the maximum deviation value allowed by the user.
  * @param iDeviation
  * The value of the deviation. This value must be positive.
  */
  void SetDeviationAllowed(CATLength iMaxDeviation);

  /**
  * @nodoc
  * Set Implicit Geometric Factory for CGMReplay
  */
  INLINE void SetCGMMode(short iCGMMode);

  /**
  * @nodoc
  * Get list of faces for which Matter side has been reversed.
  * @param oReverseMatterOutputFaces
  *   The list of Reversed Faces.
  */
  void GetReverseMatterOutputFaces(CATLISTP(CATFace) & oReverseMatterOutputFaces);

  /**
  * Returns the pointer to the resulting body.
  */
  CATBody * GetResult();

  /**
  * Runs <tt>this</tt> operator.
  */
  int Run();

  /** @nodoc @nocgmitf */
  virtual int RunOperator();

  /**
  * @nodoc
  * Get list of faces that couldn't be extrapolated.
  * @param oTrickyFaces
  *   The list of Tricky Faces.
  */
  void GetTrickyFaces(CATLISTP(CATFace) &oTrickyFaces);

  /**
  * @nodoc
  * Get list of edges that couldn't be extrapolated.
  * @param oTrickyEdges
  *   The list of Tricky Edges.
  */
  void GetTrickyEdges(CATLISTP(CATEdge) &oTrickyEdges);

  /**
  * @nodoc
  * Get list of edges that couldn't be extrapolated.
  * @param iThick
  *   The CATThick operator.
  * @param oTrickyEdges
  *   The list of Tricky Edges.
  */
  void GetLocalTrickyEdges(CATThick *iThick, CATLISTP(CATEdge) &oTrickyEdges, 
    short iUpdateLists=0);

  //-----------------------------------------------------------------------
  //- Gestion pour CGMReplay
  //-----------------------------------------------------------------------  
  /** @nodoc @nocgmitf definition des Objets  ...*/
  void RequireDefinitionOfInputAndOutputObjects();

  /** @nodoc @nocgmitf declaration integre au CGMReplay */
  CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);

  /** @nodoc @nocgmitf ID pour CGMReplay */
  virtual void WriteInput(CATCGMStream  & ioStr);

  /** @nodoc @nocgmitf */
  virtual void ReadInput(CATCGMStream  & ioStr,int VersionOfStream, short iNumReplayVersion=1);

  /** @nodoc @nocgmitf ID pour CGMReplay */
  virtual void Dump( CATCGMOutput& s ) ;

  /** @nodoc @nocgmitf ID pour CGMReplay */
  virtual void DumpOutput(CATCGMOutput &os);

  /** @nodoc @nocgmitf ID pour CGMReplay */
  static const CATString * GetDefaultOperatorId() { return & _OperatorName; };

private:

  void PropagateEdgeDeactivation( const CATLISTP(CATEdge) & iAllTrickyEdges, 
                                        CATLISTP(CATEdge) & ioEdgesAfterPropag,
                                        CATListOfDouble   & ioValuesAfterPropag );

  void PropagateSingleEdgeDeactivation(CATEdge *iEdge, CATLISTP(CATEdge) &ioEdgesAfterPropag,
    CATListOfDouble &ioValuesAfterPropag, CATVertex * iNoPropagVertex=NULL);

  void CreateProgressBarManager();
  
  // Operator generic name 
  static CATString _OperatorName;

  CATBody       * _InitialBody;
  CATBody       * _ResultBody;

  // Propagation mode (0 = off, 1 = on)
  short           _Propagation;

  // Extrapolation par defaut
  short           _DefaultExtrapolationValueHasBeenSet;
  double          _DefaultExtrapolation;

  // Liste des edges selectionnes pour une extrapolation de skin
  // liste d'edges a extrapoler parallele a la liste des valeurs d'extrapolation.
  CATLONG32           _BeforePropagSize;
  CATLISTP(CATEdge)   _ExtrapolEdges;
  CATListOfDouble     _ExtrapolValues;

  // Comportements de la relimitation sur les bords
  // pour l'extrapolation :
  short           _ExtrapolExtremMode;    //   0 (default) : Tangent | 1 : Normal | 2 : MaxExtrapol

  // mode special pour AutoFillet : on conserve la geometrie
  // des edges a relimiter
  // ! non compatible avec le mode Normal ni
  // le mode propagation OFF !
  short           _KeepBorderEdgeCurves;

  // mode recursif permettant de relancer l'extrapolation sans
  // les edges ayant ete detectees comme posant probleme 
  // lors d'une passe precedentes (pour AutoFillet)
  short          _PartialExtrapolationAllowed;

  // Mode de reconstruction robuste
  short          _ApproximateExtrapolationLevel;

  // Si active, ne renvoie que la partie extrapolee de la surface
  short          _KeepOnlyExtrapolatedArea;

  // Recherche en post-pro de topologies posees sur des surfaces twistees
  short          _TwistDetection;

  // Tolerance de deviation
  short                        _DeviationMode;
  CATLength                    _MaxDeviation;

  // Main operator
  CATThick      * _Thick;
  CATThick      * _SecondTryThick;

  ListPOfCATEdge _AllTrickyEdges;
  ListPOfCATFace _AllTrickyFaces;

  // Should we freeze the output body?
  CATBodyFreezeMode    _freezeMode;

  // Information to add in topological journal events
  CATCGMJournalInfo * _JournalInfo;

  short               _CGMMode;
  
  CATLONG32           _ThickNum;

  CATlsoProgressBarManager * _ProgressBarManager;  // A ProgressBar manager
};

// methodes INLINE

INLINE void CATSkinExtrapolThickPlus::SetCGMMode(short iCGMMode) {
  _CGMMode = iCGMMode; }


#endif
