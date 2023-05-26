// COPYRIGHT DASSAULT SYSTEMES 2007, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : L. Marini 
//
// DESCRIPTION  : Create a journal of CATManifold from PerviousBodyList to CurrentBodyList 
//
//=============================================================================
// Creation LAP July 2014
//
//=============================================================================
#ifndef CATExtractCellsOpe_H
#define CATExtractCellsOpe_H

#include "TopPersistentLight.h"
#include "CATPersistentOperator.h"
#include "ListPOfCATCell.h"
#include "ListPOfCATDomain.h"
// #include "IUnknown.h" // For HRESULT

class CATExtractCellsImpl;
class CATSoftwareConfiguration;
class CATGeoFactory;
class CATTopData;
class CATCGMStream;
class CATCGMOutput;
class CATBody;
class CATCellHashTable;

/**
   * @enum  EfficiencyMode
   * @brief Values that represent efficiency modes
   *        BASIC_EXTRACT
   *          cells extraction suitable for general cases
   *          - Single body as input
   *        FAST_EXTRACT
   *          optimized (time consumming) cells extraction
   *          - Multi-bodies input
   *          /!\ WARNING - PERMANENT RESTRICTION /!\
   *          Use this mode with manifold input bodies ONLY.
   *          Make sure result is a valid MONO-DOMAIN single Body.
   *
   *          Invalid case on a NON-MANIFOLD body
   *           x : selected face
   *          |-----------------------|------------x----------|
   *          |                       |            |          |
   *          |                       |                       |
   *          |                     <-x-> ! invalid           |
   *          |          |            |     orientation       |
   *          |----------x------------|-----------------------|
   */
   // @nocgmitf
enum EfficiencyMode { BASIC_EXTRACT, FAST_EXTRACT };

/**
* This class is used to select faces with.<br>
**/
class ExportedByTopPersistentLight CATExtractCellsOpe : public CATPersistentOperator
{
  CATCGMVirtualDeclareClass(CATExtractCellsOpe);

public:

  

  //==============================================================================
  // destructor 
  //==============================================================================
  /**
  * Standard destructor.<br>
  **/
  // @nocgmitf
  virtual ~CATExtractCellsOpe();


  // =========================================================
  // Set Methods ( before Run )
  // =========================================================
  /**
  * Set a list of CATDomain for priority orientation.
  * @param iDomainList
  * The pointer list of Domains to append.
  */
  void SetDomainsOrientationPriority(const CATLISTP(CATDomain) &iDomainList);

  /**
  * Enable 'reverse' selection of all other cells on the body that are not in the given input cells.
  * @param iValue
  *<dl>
  *<dt><tt>FALSE</tt></dt><dd> This mode is used by default at the creation of the operator.
  *<dt><tt>TRUE</tt></dt><dd>  Create a body with all cells that are NOT in <tt>iInputCellList</tt>.
  *</dl>
  */
  void SetComplementaryMode(CATBoolean iValue=TRUE);
        

  /**
  * Enable volum body result of selected cells in FAST mode 
  * @param iValue
  *<dl>
  *<dt><tt>FALSE</tt></dt><dd> This mode is used by default at the creation of the operator.
  *<dt><tt>TRUE</tt></dt><dd>  Create a volumic body with all cells (only in FAST mode)
  *</dl>
  */
  // @nocgmitf
  void SetVolumicResult(CATBoolean iValue = TRUE);

 /**
  * - Set Required Dimension -
  * Do not extract the input cells but their boundary cells correponsding the given dimension.
  * Example with CATFace as input:
  *   if iLowerDimension=1, their boundary edges will be extracted instead.
  *
  * @param iLowerDimension 
  *   Has to be lower than the given InputCell dimension. 
  * @return 
  *  S_OK , if the given dimension is lower
  *  S_FALSE, if the given dimension is equal
  *  E_FAIL otherwise.
  */
  HRESULT SetRequiredDimension(unsigned short iLowerDimension);


// ==========================================================================
// Officlal Append Methods
// ==========================================================================
  /**
  * Appends input persistent body for extract
  * @param ipBody 
  *   It can be multi-domains but must be manifolds
  * @param ipCellHT 
  *   It must contain cells belonging to ipBody.
  * @param iComplementaryMode 
  *   Enables 'reverse' selection of all other cells on the body that are not in the given input cells.
  *<dl>
  *<dt><tt>FALSE</tt></dt><dd> This mode is used by default at the creation of the operator.
  *<dt><tt>TRUE</tt></dt><dd>  Create a body with all cells that are NOT in <tt>iInputCellList</tt>.
  *</dl>
  @nocgmitf*/
  int Append(CATPersistentBody                    * ipPersistentBody,
             const CATCellHashTable               * ipCellHT=NULL,
              CATBoolean                            iComplementaryMode = FALSE);

  /**
  * Appends input body for extract
  * @param ipBody 
  *   It must be mono-domain AND manifold.
  * @param ipCellHT 
  *   It must contain cells belonging to ipBody.
  * @param iComplementaryMode 
  @nocgmitf*/
  int Append(CATBody                    * ipBody,
             const CATCellHashTable     * ipCellHT=NULL,
              CATBoolean                  iComplementaryMode = FALSE);
    
  //==========================================================
  // Get Methods  ( Output after Run )
  // =========================================================
  /** 
  * Retrieve all cells whose orientation have been inverted regarding their respective new domain.
  * @param oInvertedCellList
  *   The list of pointer on resulting cells.
  * Restriction : This method will return E_FAIL if input cells are Volume type of Vertex type. 
  *               This method also return E_FAIL if any input cell belong to more than on domain (shell or wire).
  **/
  HRESULT GetInvertedCells(CATLISTP(CATCell) & oInvertedCellList) const;




  //==============================================================================
  //
  // CGMREPLAY METHODES
  //
  //==============================================================================
  /** @nodoc @nocgmitf declaration integre au CGMReplay */
  void RequireDefinitionOfInputAndOutputObjects();
  /** @nodoc @nocgmitf */
  CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);
  /** @nodoc @nocgmitf */
  virtual const CATString * GetOperatorId();
  /** @nodoc @nocgmitf */
  static const CATString * GetDefaultOperatorId();
  /** @nodoc @nocgmitf */
  void DumpOutput(CATCGMOutput& os);
  /** @nodoc @nocgmitf */
  virtual void WriteInput(CATCGMStream  & os);
  /** @nodoc @nocgmitf */
  virtual void ReadInput(CATCGMStream  & ioStream,int VersionOfStream, short iNumReplayVersion=1);
  /** @nodoc @nocgmitf */
  virtual void Dump( CATCGMOutput& os ) ;
  /** @nodoc @nocgmitf */
  virtual int RunOperator();

  /** @nodoc @nocgmitf */
  void DumpOutput(CATCGMStream & Str , CATCGMOutput & os , int VersionNumber);
  /** @nodoc @nocgmitf */
  CATBoolean ReadReferenceOutput(CATCGMStream &Str);
  /** @nodoc @nocgmitf */
  void WriteOutput(CATCGMStream & ioStream);
  /** @nodoc @nocgmitf */
  // CATBoolean ValidateTopOutput(CATTopCheckJournal* iEquivalent, CATCGMOutput& os);
  // @nocgmitf
  // CATCGMOperator::CATCheckDiagnostic CheckOutput(CATCGMOutput & os);
  // @nocgmitf
  CATBoolean ValidateOutput(CATCGMStream & iStr, CATCGMOutput & Os, int VersionNumber=1);

protected:

  CATExtractCellsImpl * GetExtractCellsImpl() const;

  friend ExportedByTopPersistentLight CATExtractCellsOpe * CATCreateExtractCellsOpe(CATGeoFactory            * ipFactory,
                                                                                    CATTopData               * ipTopData,
                                                                                    CATBody                  * ipInputBody,
                                                                                    const CATLISTP(CATCell)  & iInputCellList);
  // @nocgmitf
  friend ExportedByTopPersistentLight CATExtractCellsOpe * CATCreateExtractCellsOpe(CATGeoFactory             * ipFactory,
                                                                                    CATTopData                * ipTopData,
                                                                                    CATBody                   * ipInputBody,
                                                                                    const CATCellHashTable    & iInputCellHashTab);

  /**
   * @brief Create an ExtractCells operator in FAST mode
   * @param [in]  ipFactory             The factory.
   * @param [in]  ipTopData             The top Data.
   * @param           iMode             {BASIC_EXTRACT, FAST_EXTRACT} extraction mode
   *                                    - BASIC_EXTRACT   basic extraction on single Body  
   *                                    - FAST_EXTRACT    optimized (time) extraction with multi Body    
   *                                    
   *          /!\ WARNING - PERMANENT RESTRICTION /!\
   *          Use this mode with manifold input bodies ONLY.
   *          Make sure result is a valid MONO-DOMAIN single Body.
   *          
   *          Invalid case on a NON-MANIFOLD body
   *           x : selected face
   *          |-----------------------|------------x----------|
   *          |                       |            |          |
   *          |                       |                       |
   *          |                     <-x-> ! invalid           |
   *          |          |            |     orientation       |
   *          |----------x------------|-----------------------| 
   *          
   * @param [in]  ipPersisentCellInfra  the persisent cell infra.
   * @returns Null if it fails, else a pointer to a CATExtractCellsOpe.
   */
  friend ExportedByTopPersistentLight CATExtractCellsOpe * CATCreateExtractCellsOpe(CATGeoFactory             * ipFactory,
                                                                                    CATTopData                * ipTopData,
                                                                                    EfficiencyMode              iMode,
                                                                                    CATPersistentCellInfra    * ipPersisentCellInfra);

                                                                                  
  //==============================================================================
  // Protectd Constructor: do not use, use CATCreateExtractCellsOpe
  //==============================================================================
  // @nocgmitf
  CATExtractCellsOpe(CATGeoFactory                      * iFactory,
                     CATTopData                         * iTopData,
                     CATExtractCellsImpl                * iImpl);

private :

  //==============================================================================
  // copy constructor
  //==============================================================================
  /**
  * Copy constructor: Not implemented. <br>
  **/
  CATExtractCellsOpe (const CATExtractCellsOpe &);


  //==============================================================================
  // Equal operator
  //==============================================================================
  /**
  * Equal operator : Not implemented. <br>
  **/
  CATExtractCellsOpe& operator=(const CATExtractCellsOpe &);


};


//==============================================================================
// CATCreateExtractCellsOpe 1
//==============================================================================
ExportedByTopPersistentLight CATExtractCellsOpe * CATCreateExtractCellsOpe( CATGeoFactory        * ipFactory,
                                                                        CATTopData               * ipTopData,
                                                                        CATBody                  * ipInputBody,
                                                                        const CATLISTP(CATCell)  & iInputCellList);

//==============================================================================
// CATCreateExtractCellsOpe 2
//==============================================================================
// @nocgmitf
ExportedByTopPersistentLight CATExtractCellsOpe * CATCreateExtractCellsOpe(CATGeoFactory              * ipFactory,
                                                                            CATTopData                * ipTopData,
                                                                            CATBody                   * ipInputBody,
                                                                            const CATCellHashTable    & iInputCellHashTab);



//==============================================================================
// CATCreateExtractCellsOpe 4 - Fast Mode
//==============================================================================
/**
* @brief Create an ExtractCells operator in FAST mode
* @param [in]  ipFactory             The factory.
* @param [in]  ipTopData             The top Data.
* @param           iMode             {BASIC_EXTRACT, FAST_EXTRACT} extraction mode
*                                    - BASIC_EXTRACT   basic extraction on single Body  
*                                    - FAST_EXTRACT    optimized (time) extraction with multi Body    
*                                    
*          /!\ WARNING - PERMANENT RESTRICTION /!\
*          Use this mode with manifold input bodies ONLY.
*          Make sure result is a valid MONO-DOMAIN single Body.
*          
*          Invalid case on a NON-MANIFOLD body
*           x : selected face
*          |-----------------------|------------x----------|
*          |                       |            |          |
*          |                       |                       |
*          |                     <-x-> ! invalid           |
*          |          |            |     orientation       |
*          |----------x------------|-----------------------| 
*          
* @param [in]  ipPersisentCellInfra  the persisent cell infra.
* @returns Null if it fails, else a pointer to a CATExtractCellsOpe.
*/
// @nocgmitf
ExportedByTopPersistentLight CATExtractCellsOpe * CATCreateExtractCellsOpe(CATGeoFactory              * ipFactory,
                                                                            CATTopData                * ipTopData,
                                                                            EfficiencyMode              iMode = FAST_EXTRACT,
                                                                            CATPersistentCellInfra    * ipPersisentCellInfra=NULL);


#endif

