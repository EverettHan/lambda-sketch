#ifndef CATHybAssemble_h
#define CATHybAssemble_h

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
* @CAA2Level L1
* @CAA2Usage U1
*/

#include "CATIAV5Level.h"
#include "CATIACGMLevel.h"

#define AssembleInterfaceCleaned

#include "CATHybOperatorImp.h"
#include "CATCGMOperatorDebug.h"
#include "BOHYBOPELight.h"
#include "CATCreateTopAssemble.h"
#include "CATMathDef.h"
#include "ListPOfCATBody.h"
#include "ListPOfCATCell.h"
#include "CATBoolean.h"

class CATExtHybAssemble;

/**
*  ***********************************************************************
*  *******                         WARNING                         *******
*  ***********************************************************************
*  *******
*  *******  This class is Not supported any longer.
*  *******  it has been replaced by CATICGMHybAssemble
*  *******
*  *******
*  ***********************************************************************
*  ***********************************************************************
*  CATHybAssemble class has been removed from CAA in 3DEXPERIENCE level and
*  has been replaced by CATICGMHybAssemble.
*  We recommend you to use only CATICGMHybAssemble, in order you will  be  
*  able to easily migrate your CAA code from  V5 to 3DEXPERIENCE level
*
*  **************************************************************************
*
* Class defining the operator that assembles two bodies.
*<br>
* This operator operates on the 2D (CATShell), 1D (CATWire) and 0D (CATVertexInVolume)
* domains of a CATBody.
* It follows the general frame of all operator and satisfies to the smart mechanism: the
* input bodies are not modified. A new resulting body is created, 
* possibly sharing data with the input bodies.
*<ul>
* <li>CATHybAssemble is created with the CATCreateTopAssemble global function. 
* It must be
* directly deleted with the usual C++ <tt>delete</tt> operator after use.
* It is not streamable. 
*<li>The result is accessed with the <tt>GetResult</tt> method. If you do not want 
* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
* geometric factory.
*</ul>
* @see CATCreateTopAssemble
*/

class ExportedByBOHYBOPELight CATHybAssemble : public CATHybOperatorImp
{
  CATCGMVirtualDeclareClass(CATHybAssemble);
  
public:

   virtual ~CATHybAssemble();

   /** @nodoc  */
   #define CATHybAssembleDefineRunOperator

   // (Empty macro in customer release mode; no effect on generated code)
   virtual int Run() ;
   /* @nocgmitf */
   virtual int RunOperator() ;


   /** 
   * @nodoc
   * No longer available.
   */
   void SetBorderMode(int yes_or_no=1);

   /**
   * @nodoc
   * No longer available.
   */
   int  GetBorderMode() const;

   /** 
   * @nodoc
   * No longer available.
   */
   void SetFirstPassMode(int yes_or_no=1);

   /**
   * @nodoc
   * No longer available.
   */
   int  GetFirstPassMode() const;

   /**
   * Activates simplify mode: operator tries to simplify result.
   * <br> This option is not activated by default.
   * @param yes_or_no
   * <br><b>Legal values</b>:
   * <dl><dt><tt>0</tt><dd> No simplification of result.
   *     <dt><tt>1</tt><dd> Simplification of result.</dl>
   */
   void SetSimplifyMode(int yes_or_no=1);

   /**
   * Returns simplify mode.
   * @return 
   * <br><b>Legal values</b>:
   * <dl><dt><tt>0</tt><dd> No simplification of result.
   *     <dt><tt>1</tt><dd> Simplification of result.</dl>
   */
   int  GetSimplifyMode() const;
   
   /**
   * Activates suppress mode : in the case of invalid cells, 
   * operator does a second pass after having removed them.
   * Invalid cells may be retrieved with method GetSupressBody.
   * <br> This option is not activated by default.
   * @param yes_or_no
   * <br><b>Legal values</b>:
   * <dl><dt><tt>0</tt><dd> No assemble with invalid cells.
   *     <dt><tt>1</tt><dd> Force assemble with invalid cells.</dl>
   */
   void SetSuppressMode(int yes_or_no=1);

   /**
   * Returns the suppress mode.
   * @return 
   * <br><b>Legal values</b>:
   * <dl><dt><tt>0</tt><dd> suppress mode not active.
   *     <dt><tt>1</tt><dd> suppress mode is active.</dl>
   */
   int  GetSuppressMode() const;

   /**
   * Retrieves the suppressed cells in a body.
   * @return
   * The suppressed body: the body contains all suppressed cells.
   */
   CATBody* GetSuppressBody();  
   
   /** 
   * @nodoc
   * Activates angle mode: operator checks that angle value is lower than a maximum value.
   * <br> This option is not activated by default and only concerns assemble of wires.
   * @param yes_or_no
   * <br><b>Legal values</b>:
   * <dl><dt><tt>0</tt><dd> angle mode not active.
   *     <dt><tt>1</tt><dd> angle mode is active.</dl>
   */
   void SetAngleMode(int yes_or_no=1);

   /** 
   * @nodoc
   * Returns the angle mode.
   * @return 
   * <br><b>Legal values</b>:
   * <dl><dt><tt>0</tt><dd> angle mode not active.
   *     <dt><tt>1</tt><dd> angle mode is active.</dl>
   */
   int  GetAngleMode() const;

   /** 
   * @nodoc
   * Sets the maximum value of angle for angle mode.
   * <br> The value by default is 180°.
   * @param iMaxAngle
   * Maximum value of angle.
   */
   void SetAngleValue(CATAngle iMaxAngle);   // in degree

   /** 
   * @nodoc
   * Returns maximum value of angle.
   * @return 
   * Maximum value of angle.
   */
   CATAngle  GetAngleValue() const;

   /** 
   * @nodoc
   * No longer available
   */
   void SetAllAngleErrorInOneShot(int yes_or_no=1);

   /** 
   * @nodoc
   * No longer available
   */
   int GetAllAngleErrorInOneShotMode() const;

   /** 
   * @nodoc
   * No longer available
   */
   void SetQuickMode(int yes_or_no=1);
 
   /** 
   * Retrieves merged cells in a body (to use after run).
   * @return
   * The body containing all merged edges.
   */
   CATBody* GetAllMergedEdges();

   /**
   * Specifies a list of cells to be merged in a local join.
   * @param iCellsToMerge
   * The cells to be merged.
   */
   void SetCellsToMerge(ListPOfCATCell iCellsToMerge);
   
   /**
   * Specifies border cells of different skins to assemble to match up,
	 * in order to avoid unnecessary calculations.
	 * @param iMatchingCells
   * The border cells of the skins that are matching together.
   */	  
	 void  SetMatchingCells(const ListPOfCATCell & iMatchingCells);

   /**
   * @nodoc
   * Specifies border cells of different skins to assemble to match up,
	 * in order to avoid unnecessary calculations.
	 * @param iMatchingCells
   * The border cells of the skins that are matching together.
   */	  
	 void  SetMatchingCells(ListPOfCATCell * iMatchingCells);

   /**
   * Activates Volume creation mode: if the resulting skin is closed,
   * operator creates and returns the volume bounded by this skin.
	 * @param iVolumeCreation
   * <br><b>Legal values</b>:
   * <dl><dt><tt>FALSE</tt><dd> No volume creation.
   *     <dt><tt>TRUE</tt><dd> Volume creation if result is closed.</dl>
   */	  
	 void  SetVolumeCreationMode(CATBoolean iVolumeCreation = FALSE);

   /**
   * @nodoc
   * Asks operator not to remove small edges.
   * @param yes_or_no
   * <br><b>Legal values</b>:
   * <dl><dt><tt>0</tt><dd> Small edges are removed.
   *     <dt><tt>1</tt><dd> Small edges are not removed.</dl>
   */
   void SetKeepSmallEdges(int yes_or_no=1);

   /** 
   * @nodoc
   * Returns small edges mode.
   * @return 
   * <br><b>Legal values</b>:
   * <dl><dt><tt>0</tt><dd> mode not active: small edges are removed.
   *     <dt><tt>1</tt><dd> mode is active: small edges are not removed.</dl>
   */
   int  GetKeepSmallEdgesMode() const;  
   
  /** @nodoc  
   * Internal use.
   */
   inline CATExtHybAssemble* GetHybAssembleExtensible() const; 

   /** @nodoc */
   CATHybAssemble(CATGeoFactory*, CATTopData* iTopData, CATExtHybAssemble* iExtensible, ListPOfCATBody* toAssemble);

   /**
   * Activates SeparateBodies mode : in the case of more than one resulting domain,
   * each domain is returned in a different body.
   * Resulting bodies may be retrieved calling <tt>NextResult</tt> before each call to GetResult.
   * <br> This option is not activated by default.
   * @param iSeparateBodiesMode
   * <br><b>Legal values</b>:
   * <dl><dt><tt>FALSE</tt><dd> All domains will be in the same body.
   *     <dt><tt>TRUE</tt><dd> One body for each domain.</dl>
   */
   virtual void SetReturnSeparateBodies(CATBoolean iSeparateBodiesMode);

   /** @nodoc
   * Decide if 2 edges belonging to the same input CATShell can be stitched together or not.
   * This option shouldn't be used in the case of wire assembly.
   * @param iMergeEdgesFromSameShell
   * <br><b>Legal values</b>:
   * <tt>1</tt> to allow 2 edges from the same shell to be stitched together, 
   * <tt>0</tt> to forbid 2 edges from the same shell to be stitched together.
   */
   virtual void SetMergeEdgesFromSameShell(short iMergeEdgesFromSameShell);

   /** @nodoc
   * Use this function to decide which CATCurve must be used when trying to stitch an edge with the other edges.
   * By default, the operator uses the CATPCurve that represents the edge on its face.
   * By calling SetUseEdgeCurveForMerge(1) before run, the CATEdgeCurve of the edge will be used instead.
   * This can have an effect on the final result,
   * especially in cases where the geometric gap of the CATEdgeCurve is big.
   */
   virtual void SetUseEdgeCurveForMerge(short iUseEdgeCurveForMerge);

   /**
   * Option to split edges according to the convexity.  
   * <br> This option is activated by default.  Deactivating it improves performance.
   * @param iConvexitySplitter
   * <br><b>Legal values</b>:
   * <dl><dt><tt>FALSE</tt><dd> Edges will not be split according to the convexity.  This should improve performance.
   *     <dt><tt>TRUE</tt><dd>  Edges will be split according to the convexity.</dl>
   */
   virtual void SetConvexitySplitter(CATBoolean iConvexitySplitter);

   /**
   * Option to populate output journals.
   * <br> This option is activated by default.  Deactivating it improves performance.
   * @param iJournalsRequired
   * <br><b>Legal values</b>:
   * <dl><dt><tt>FALSE</tt><dd> We will not populate the output journals.  This should improve performance.
   *     <dt><tt>TRUE</tt><dd>  We populate the output journals.</dl>
   */
   virtual void SetJournalsRequired(CATBoolean iJournalsRequired);

   /*
   * Option to record the merged edges.
   * <br> This option is activated by default.  Deactivating it improves performance.   
   * @param iAllMergedEdgesRequired
   * <br><b>Legal values</b>:
   * <dl><dt><tt>FALSE</tt><dd> We will not record the merged edges.  This should improve performance.
   *     <dt><tt>TRUE</tt><dd>  We record edges that have been merged.</dl>
   */
   virtual void SetAllMergedEdgesRequired(CATBoolean iAllMergedEdgesRequired);
#ifdef CATIACGMR424CAA 
   /** @nodoc
   // set treatment with Simplification of the Result (to use before run)
   // default value is : 0  --> No Simplification of the Result
   // other value : 1 --> simplification only between 2 modified faces of 2 different bodies.
   // other value : 2 --> simplification between faces of 2 different bodies including merged faces with common edge on the 2 bodies
   */
   virtual void SetSimplifyModeForNoChange(int yes_or_no = 2) ;

   /** @nodoc
   // get if Simplification of the Result has been activated
   // default value is : 0  --> No Simplification of the Result
   // other value : 1 --> simplification only between 2 modified faces of 2 different bodies.
   // other value : 2 --> simplification between faces of 2 different bodies including merged faces with common edge on the 2 bodies
   */
   virtual int  GetSimplifyModeForNoChange() const;
#endif

protected:

#ifdef CATIACGMR419CAA   
  /** @nodoc @nocgmitf */
  virtual int RunExactOperator();
  /** @nodoc @nocgmitf */
  virtual int RunPolyOperator();
#endif

};

/** @nodoc  */
inline CATExtHybAssemble* CATHybAssemble::GetHybAssembleExtensible() const
{
   if (!_Extensible)  CATThrowForNullPointerReturnValue(NULL);
   return (CATExtHybAssemble*) _Extensible;      
}

#endif
