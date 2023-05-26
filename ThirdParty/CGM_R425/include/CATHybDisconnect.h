#ifndef CATHybDisconnect_h
#define CATHybDisconnect_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @level Protected
 * @usage U1
 */ 

#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
#include "CATHybBoolean.h"
#include "BOHYBOPELight.h"
#include "CATCGMOperatorDebug.h"
 
 
class CATExtHybDisconnect;

/** @nocgmitf */
ExportedByBOHYBOPELight CATHybDisconnect * CATCreateTopDisconnect(CATGeoFactory*     iFactory,
                                                             CATTopData*        iData,
                                                             CATBody*           iBodyToDisconnect,
                                                             CATBody*           iDisconnectingBody,
                                                             CATBody*           iCuttingBody);

/**
 * Class defining the operator that inserts vertices in a wire or skin body, or
 * inserts edges in a skin body.
 * It follows the general frame of all operators and satisfies the smart mechanism: the
 * input bodies are not modified. A new resulting body is created, 
 * possibly sharing data with the input bodies.
 *<ul>
 * <li>CATHybDisconnect is created with the <tt>CATCreateTopDisconnect</tt> global function.
 * It must be
 * directly deleted with the usual C++ <tt>delete</tt> operator after use.
 * It is not streamable. 
 * <li>The intersection can be restricted to a given domain on each body with the methods
 * <tt>SetFirstDomainToIntersect</tt> and <tt>SetSecondDomainToIntersect</tt>
 *<li>The result is accessed with the <tt>GetResult</tt> method. If you do not want 
 * to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
 * geometric factory.
 *</ul>
 * @see CATCreateTopDisconnect
 */
class ExportedByBOHYBOPELight CATHybDisconnect : public CATHybBoolean
{

   friend ExportedByBOHYBOPELight CATHybDisconnect * CATCreateTopDisconnect(CATGeoFactory*     iFactory,
                                                             CATTopData*        iData,
                                                             CATBody*           iBodyToDisconnect,
                                                             CATBody*           iDisconnectingBody,
                                                             CATBody*           iCuttingBody);
  CATCGMVirtualDeclareClass(CATHybDisconnect);
protected :
   
   /** @nodoc */
   CATHybDisconnect(CATGeoFactory* iFactory, CATTopData* iTopData, CATExtHybDisconnect* iExtensible,
      CATBody* iBodyToDisconnect,CATBody* iDisconnecttingBody, CATBody* iCuttingBody);	

public :
   
   //  Destructor
   ~CATHybDisconnect();     

   /** @nodoc  */
   #ifdef CATIACGMV5R20
   #define CATHybDisconnectDefineRunOperator
   #endif
   // (Empty macro in customer release mode; no effect on generated code)
    #ifdef CATCGMOperatorDebugMode
   #define CATHybDisconnectDefineRunOperator
    #endif
   #ifdef CATHybDisconnectDefineRunOperator
   virtual int Run() ;
  /** @nodoc @nocgmitf */
   virtual int RunOperator() ;
   #endif

   
   /** 
    * Activates the query mode.
    * <br>To be called before the <tt>Run</tt> method.
    * @param iQueryMode
    * The activation of the query mode.
    * <br><b>Legal values</b>: 1 for rank + location activated (default value), 2 for rank activated, 0 for deactivated. 
    * The deactivation gives better performance.
    */
   void SetQueryMode(int iQueryMode=1);
   /** 
    * Returns the state of the query mode.
    * @return
    * The activation of the query mode.
    * <br><b>Legal values</b>: 1 for rank + location activated (default value), 2 for rank activated, 0 for deactivated. 
   */
   int  GetQueryMode() const;
   
   /** 
   * Returns the location of the created cell.
   * <br>To be called after the <tt>Run</tt> method, if the query mode is activated.
   * @param iCell
   * The pointer to a created cell.
   * @return
   * The location of the cell with regards to the cutting body.
   * <br><b>Legal values</b>: <tt>1</tt> if it is at the left side, 
   * <tt>-1</tt> if it is at the right side.
   */
   int GetCorrespondingSide(CATCell* iCell);  

   /** 
   * Returns the rank of a created cell.
   * <br>To be called after the <tt>Run</tt> method, if the query mode is activated.
   * @param iCell
   * The pointer to a created cell.
   * @return
   * The corresponding rank. It may happen that several cells are generated on the same side of the
   * cutting object. If these cells are not directly connected, they are labelled by this method.
   */
   int GetCorrespondingPackNumber(CATCell* iCell);                
        
  /**
   * @nodoc
   * Query to the operator (internal use only).
   */
   CATCell* GetCorrespondingCell(CATCell* OriginalCell);                

  /**
   * @nodoc
   * To be called before the <tt>Run</tt> method.
   * Activate cutting edges report (internal use only).
   */
   void ReportInternalEdges();

#ifdef CATIACGMR418CAA
   /**
   * @nodoc
   * This option is available only for the disconnect shell
   * and should be called before the <tt>Run</tt> method.
   *
   *   @param iResultCleaning
   *     Input flag to activate the disconnect result cleaning.
   *   @param iTolerance
   *     Input tolerance used in the cleaning.
   */
   void SetResultCleaning(CATBoolean iResultCleaning, double iTolerance);
#endif

#ifdef CATIACGMR421CAA
   /**
   * @nodoc
   * Activate or deactivate  the imprint follow up mode.
   */
   virtual void SetImprintFollowUpMode(CATBoolean iImprintFollowUpMode);

   /**
   * @nodoc
   * Check if the imprint follow up mode is active or not.
   */
   virtual CATBoolean GetImprintFollowUpMode() const;
#endif

   /** @nodoc  */
   inline CATExtHybDisconnect* GetHybDisconnectExtensible() const;

   /** @nodoc  */
   void DumpOutput(CATCGMOutput& os);

#ifdef CATIACGMR217CAA
   /**
   * Activates tracking of disconnecting cells.
   * Before calling Run, must be set to TRUE to be able to call GetDisconnectingCells after Run.
   * @param iTrackDisconnectingCells
   * <br><b>Legal values</b>:
   * <tt>TRUE</tt> to activate tracking of disconnecting cells, 
   * <tt>FALSE</tt> to deactivate tracking of disconnecting cells (default value).
   */
   void SetTrackDisconnectingCells(CATBoolean iTrackDisconnectingCells);

   /**
   * Retrieve input disconnecting cells that lead to the construction of result cell.
   * To be called after Run, only if SetTrackDisconnectingCells(TRUE) was called before Run.
   * @param iResultCell
   * If the disconnecting element is a wire and the body to disconnect is a shell,
   * iResultCell must be an edge of the result body.
   * If the disconnecting element is a vertex and the body to disconnect is a wire,
   * iResultCell must be a vertex of the result body.
   * @param oDisconnectingCells
   * The output list.
   * If the disconnecting element is a wire and the body to disconnect is a shell,
   * oDisconnectingCells will contain all edges of the input disconnecting body that
   * lead to the construction of iResultCell.
   * If the disconnecting element is a vertex and the body to disconnect is a wire,
   * oDisconnectingCells will contain all vertices of the input disconnecting body that
   * lead to the construction of iResultCell
   */
   void GetDisconnectingCells(CATCell * iResultCell, ListPOfCATCell & oDisconnectingCells);
#endif
   
};

/** @nodoc  */
inline CATExtHybDisconnect* CATHybDisconnect::GetHybDisconnectExtensible() const
{
   if (!_Extensible) CATThrowForNullPointerReturnValue(NULL);
   return (CATExtHybDisconnect*) _Extensible;      
}
#endif
