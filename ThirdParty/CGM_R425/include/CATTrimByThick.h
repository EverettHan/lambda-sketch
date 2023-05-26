#ifndef CATTrimByThick_H
#define CATTrimByThick_H

// COPYRIGHT DASSAULT SYSTEMES  2001

#include "CATDRepOperator.h"
#include "CATString.h"
#include "Thick.h"
#include "CATTopDefine.h"
#include "CATCGMJournal.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATCell.h"
#include "CATBoolean.h"

class CATTopData;
class CATBody;
class CATEdge;
class CATFace;
class CATSurface;
class CATShell;
class CATOpTrimByThick;
class CATCGMJournalInfo;

/**
	* Class defining the operator to thicken a body in two opposite directions
	* and trim another body according to the offsets specified for the thickening 
	* operation.
	* <br>The body to be thickened relies on a two-manifold supporting body
	* whose shells are contained in the body to be trimmed.
	* <ul>
	* <li>A CATTrimByThick operator is created with the 
	* <tt>CATCreateTrimByThick</tt> global function:
	* It must be directly deleted with the usual C++ <tt>delete</tt> operator after use.
	* It is not streamable. 
	*<li>Options must be specified with the appropriate methods, before
	* asking for the computation with the <tt>Run</tt> method. 
	*<li>The result is accessed with the <tt>GetResult</tt> method. If you do not want 
	* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
	* geometric factory.
	*</ul>
 */  
class ExportedByThick CATTrimByThick : public CATDRepOperator
{

  CATCGMVirtualDeclareClass(CATTrimByThick);
public:

 /**
    * @nodoc
	* Virtual constructor of a CATTrimByThick operator.<br>
	* Cannot be called. Use the <tt>CATCreateTrimByThick</tt> global function
	* to create a CATTrimByThick operator.
	*/
  CATTrimByThick(CATTopData * iTopData, 
                 CATBody    * iBodyToThick,
                 CATBody    * iBodyToTrim,
                 CATBody    * iBodySupport,
                 double       iOffset_1,
                 double       iOffset_2);


 /**
    * @nodoc
	* Destructor.
	*/
  virtual ~CATTrimByThick();

   /**
	 * Specifies the side of the shell which is to be kept in the trim operation.
	 * <br>The reference orientations are those of the splitting edge and shell.
	 * @param iSplittingEdge
	 * The edge lying on and splitting the supporting body.
     * @param iShellSupport
	 * The shell of the supporting body which is to be split.
     * @param iSideToKeepOnShell
	 * The side of the shell to be kept after the CATTrimByThick operation.
     * @param iSharpLyingOn
	 * Specifies the case where the splitting edge is a boundary not G1 with its support
   * -> 0 (G1) / 1 (not G1) / 2 (Unknown : research G1 to compute by operator)
	 */
   void SetSideForSplittingEdge(CATEdge  * iSplittingEdge,
                                CATShell * iShellSupport,
                                CATSide    iSideToKeepOnShell,
                                short      iSharpLyingOn=0);


   /**
	 * Specifies the type of journal in disconnect operation.
	 * <br>The reference orientations are those of the disconnecting edge and shell.
	   * @param iDisconnectingEdge
	 * The edge lying on and disconnecting the supporting body.
     * @param iShellSupport
	 * The shell of the supporting body which is to be disconnected.
     * @param iLeftType
	 * The type of journal order for the disconnected left part
     * @param ipLeftInfo
	 * The additional info in case of creation journal order for the disconnected right part
     * @param iRightType
	 * The type of journal order for the disconnected left part
     * @param ipRightInfo
	 * The additional info in case of creation journal order for the disconnected right part
     * @param iDeleteCGMJournalInfoAfterUse 
     * >>>>>>>> PRIVATE USE ONLY <<<<<<<<<<
   * The additional Info parameters ipLeftInfo and ipLeftInfo have to be deleted by This
	 */
   void SetDisconnectingEdge(CATEdge  * iDisconnectingEdge,
                             CATShell * iShellSupport, 
                             CATCGMJournal::Type iLeftType =CATCGMJournal::Modification,
                             CATCGMJournalInfo  *ipLeftInfo =NULL,
                             CATCGMJournal::Type iRightType=CATCGMJournal::Modification,
                             CATCGMJournalInfo  *ipRightInfo=NULL,
                             short               iDeleteCGMJournalInfoAfterUse=0);

	/**
	 * Specifies the orientation of a shell belonging to the supporting body.
     * @param iShellSupport
	 * The shell the orientation is to be specified.
	 * @param iCoefOriVsOffsetValues
	 * The value to be specified for the iCoefOriVsOffsetValues argument are
	 * (other values to be rejected):
	 * <ul>
	 * <li>iCoefOriVsOffsetValues = +1 - Reference orientations of the iOffset_1 and iOffset_2 values.
	 * <li>iCoefOriVsOffsetValues = -1 - Orientation opposite to the offset orientation.
	 * </ul>
	 * <br>Note:
	 * <br>
	 * Given Vn the normal vector of the CATShell and
     * given VOffset_1 the offset vector to obtain the Offset_1 skin.
	 * VOffset_1 = (iCoefOriVsOffsetValues X iOffset_1 ) . Vn
     * Given VOffset_2 the offset vector to obtain the Offset_2 skin.
	 * VOffset_2 = (iCoefOriVsOffsetValues X iOffset_2 ) . Vn
	 */
   void SetCoefOriForShellSupport(CATShell * iShellSupport,
                                  short iCoefOriVsOffsetValues);

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
	 * Specifies the correspondance between a face of the supporting body
	 * and its matching faces in the volumes of the body to be trimmed.
	 * @param iInitFace
	 * The face of the supporting body.
     * @param iOffsetFace_1
	 * The face corresponding to the first offset on the body to be trimmed.
	 * @param iOffsetFace_2
	 * The face corresponding to the second offset on the body to be trimmed.
	 */
  void SetOffsetFaces(CATFace * iInitFace,
                      CATFace * iOffsetFace_1,
                      CATFace * iOffsetFace_2);

  
	/**
	 * Specifies the correspondance between a lateral edge of the supporting body
	 * and its matching lateral face in the volumes of the body to be trimmed.
     * @param iInitBdEdge
	 * The edge of the supporting body.
     * @param iLateralFace
	 * The matching lateral face on the body to be trimmed.
  */
   void SetSideFaceFromEdge(CATEdge * iInitBdEdge,
                            CATFace * iLateralFace);

	/**
	 * Specifies a surface for the future side face
   * to build from the current edge of BodyToThick
   * @param iSideEdgeToThick
   * @param iSpecSurface
   */
   void SetSpecSideSurface(CATEdge * iSideEdgeToThick,
                           CATSurface * iSpecSurface);

   /**
   * Defines if procedural Offset surfaces must be approximated and
   * replaced by NurbsSurface
	 * @param iApproxOffsetMode
	 * <br><b>Legal values:</b>
   * <dl><dt>0</dt><dd>Approximation not required
   * <dt>1</dt><dd>Approximation required in C1 mode
   * <dt>2</dt><dd>Approximation required in C2 mode
	 * </dl>
   */
   void SetApproxOffsetMode(short iApproxOffsetMode);

   /**
	 * Specifies the simplification between the image face of 
   * a face bounded by a "lying on edge" and the image face of
   * the face support of this same edge, in corner cases for example
   * <br><b>Legal values:</b>
   * <dl><dt>0</dt><dd>Simplification not required
   * <dt>1</dt><dd>Simplification required 
   *
   * Added developements for new levels of simplification
   * concerning vertices and edges created from a LyingOn
   * <dt>2</dt><dd>Simplification of edges
   * <dt>1</dt><dd>Simplification of edges and vertices
	 * </dl>
   */
   void SetSimplifyAroundBorderLyingOn(short iSimplifyOption);

   /**
   * iG1HealingMode = TRUE or FALSE.
   */
   void SetG1HealingMode(CATBoolean iG1HealingMode);

   /**
   * iG1HealingTolerance if iG1HealingMode is TRUE.
   */
   void SetG1HealingTolerance(double iG1HealingTolerance);

   /**
	 * Retrieves the body to be thickened. 
	 */
   CATBody * GetBodyToThick();

  	/**
	 * Retrieves the body to be trimmed.
	 */
   CATBody * GetBodyToTrim();

  	/**
	 * Retrieves the supporting body.
	 */
  CATBody * GetBodySupport();

  	/**
	 * Retrieves the first offset
	 */
  double GetOffset_1();

  	/**
	 * Retrieves the second offset
	 */
  double GetOffset_2();

  /**
	 * Retrieves the face mappings after disconnect
   * @param iInitFace
   * The face of the supporting body (iBodySupport).
   * @param oOffsetFacesList1
   * The ordered set of offset faces from iInitFace for iOffset_1
   * @param oOffsetFacesList2
   * The ordered set of offset faces from iInitFace for iOffset_2
  */ 
  HRESULT GetOffsetMappings(CATFace * iInitFace,
                            CATLISTP(CATFace) & oOffsetFacesList1, 
                            CATLISTP(CATFace) & oOffsetFacesList2);

  /**
	 * @nodoc
	 * Internal use.
	 */
  HRESULT CheckOutputOffsetMappings();

  // Recuperation des cellules a probleme
  // Le second argument permet de renseigner le type de diagnostic, suivant
  // la nomenclature suivante :
  // 0 : aucun diagnostic
  // 1 : pb de courbure locale (surface non offsetable pour la valeur demandee)
  // 2 : pointe dite plate
  // 3 : pb d'extrapolation
  // cellules appartenant a BodyToThick
  void GetTrickyCellsToThick(CATLISTP(CATCell) & oTrickyCellsToThick, CATListOfInt & oDiagInfo);
  // cellules appartenant a BodyToTrim (a priori vide)
  void GetTrickyCellsToTrim(CATLISTP(CATCell) & oTrickyCellsToTrim, CATListOfInt & oDiagInfo);


  // Execution de l'operation TrimByThick (RunOperator ne doit servir qu'en mode
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

  /** @nodoc @nocgmitf : CATCGMReplay  / Dump du resultat de l'execution l'operateur (Body,Journal) + affinite */
  /**                        + Dump des mappings de subdivisions */
  virtual void DumpOutput(CATCGMOutput &os);

  /** @nodoc @nocgmitf ID pour CGMReplay */
  static const CATString * GetDefaultOperatorId() { return & _OperatorName; };

  /** @nodoc @nocgmitf */
  virtual void ReadInput(CATCGMStream  & ioStream,int VersionOfStream, short iNumReplayVersion=1);

  /** @nodoc @nocgmitf */
  virtual int RunOperator();

  virtual void SetLiveBodyAllowed(CATBoolean iLiveBodyAllowed);



protected:
 
  CATOpTrimByThick * _OpImpl;
  
  /**
	 * @nodoc
	 * Internal use.
	 */
  friend CATCGMOutput& operator<< (CATCGMOutput& s, const CATTrimByThick& iOpe);

  /** @nodoc  */
  virtual CATCellManifoldsManager* CreateCellManifoldsManager(ListPOfCATBody &iListOfCopyInputBodies, ListPOfCATBody &iListOfNoCopyInputBodies,
    CATBody * iOutputBody, CATCGMJournalList* iTopOpJournal);

private:

  // Operator generic name 
  static CATString _OperatorName;

/**
 * @nodoc 
 * Copy constructor. Not implemented
 */
  CATTrimByThick(CATTrimByThick& iOperator);

/**
 * @nodoc 
 * Affectation operator. Not implemented
 */
  CATTrimByThick& operator=(const CATTrimByThick & iOperator);

};

/** 
	* Creates a CATTrimByThick operator.
	* @param iTopData
    * Contains a CATSoftwareConfiguration and a CATCGMJournalList
	* @param iBodyToThick
	* The pointer to the body (p CATWires + q CATShells) to be thickened. 
	* @param iBodyToTrim
	* The pointer to the body (n CATVolumes) to be trimmed by the iBodyToThick offsets.
    * iBodyToTrim is the offset image of iBodySupport.
	* @param iBodySupport
	* The pointer to the body (n CATShells) iBodyToThick is lying on
    * iBodySupport is the surfacic view of CATTrimByThick
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
ExportedByThick CATTrimByThick * CATCreateTrimByThick(CATTopData * iTopData, 
                                                      CATBody    * iBodyToThick,
                                                      CATBody    * iBodyToTrim,
                                                      CATBody    * iBodySupport,
                                                      double       iOffset_1,
                                                      double       iOffset_2);

#endif
