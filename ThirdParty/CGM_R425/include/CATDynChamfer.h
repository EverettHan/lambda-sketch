#ifndef CATDynChamfer_h_
#define CATDynChamfer_h_

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * @level Protected
 * @usage U1
 */ 

#include "CATDynOperator.h"
#include "CATDynChamferRibbon.h"
#include "CATIACGMLevel.h"

class CATGeoFactory;
class CATTopData;
class CATBody;
class CATContextForFastRun;
class CATDynChamferContextForFastRun;

/**
 * Class defining the operator to chamfer edges of a 3D body or a skin body.
 * <br>Several chamfering operations (called ribbons, <tt>CATDynChamferRibbon</tt>) 
 * can be defined in the same operator. 
 * By default, a ribbon is automatically propagated by following the tangential
 * continuity of its support, but this propagation can be switched off.
 *<br>
 * The CATDynChamfer operator follows the global frame of the topological operators and satisfies the smart mechanism: the
 * input bodies are not modified. A new resulting body is created, 
 * possibly sharing data with the input bodies.
 *<ul>
 * <li>A CATDynChamfer operator is created with the <tt>CATCreateDynChamfer</tt> global function:
 * It must be directly deleted with the usual C++ <tt>delete</tt> operator after use. It is not streamable. 
 *<li>Options can be precised (such as the faces or edges to chamfer) with the <tt>SetXxx</tt> 
 * or <tt>Append</tt> methods, before
 * asking for the computation with the <tt>Run</tt> method. 
 *<li>In both cases, the result is accessed with the <tt>GetResult</tt> method. If you do not want 
 * to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
 * geometric factory.
 *</ul>
 */

class ExportedByBODYNOPE  CATDynChamfer: public CATDynOperator
{
  CATCGMVirtualDeclareClass(CATDynChamfer);
public:
/**
 * @nodoc
 * Virtual constructor of a CATDynChamfer operator.<br>
 * Cannot be called. Use the <tt>CATDynCreateChamfer</tt> global function
 * to create a CATDynChamfer operator.
 */
  CATDynChamfer(CATGeoFactory* iContainer, 
                CATTopData* iData,
                CATExtTopOperator* iExtensible);

  
  virtual ~CATDynChamfer();

/**
 * Appends a ribbon to <tt>this</tt> chamfering operator.
 * @param iRibbonToAppend
 * The pointer to the ribbon to add to <tt>this</tt> operator.
 */
  virtual void Append (CATDynChamferRibbon* iRibbonToAppend);

/**
 * Asks for the computation of the construction paths of the chamfer, even though the chamfering operation
 * cannot be completely run.
 * <br>To use in debug purpose, in order to understand the configuration.
 */
  virtual void SetPrevisualizationOnly ();


  /**
  * @nodoc
  * Defines a face or connected faces to stop the chamfer. 
  * @param iBody
  * The body which contains the shell used as a limiting element.
  * @param iSkin
  * The shell to be used as a limiting element.
  * @param iOrientation
  * The orientation of the edge with respect to the limiting element.
  */
  virtual void AddLimitingElement(CATBody* iBody, CATDomain* iSkin, const CATOrientation iOrientation);

  /**
   * Defines the type of computation in case of multi ribbons configurations.
   * By default, the <tt>Run</tt> method compute all the ribbons and then intersect them
   * together. Moreover, if this computation failed, another computation is launched, taken one ribbon 
   * after the other.
   * If called, this method only allows the <tt>Run</tt> method to execute the first step.
   */
  virtual void SetTrueMultiRibbonOnly ();

/**
 * @nodoc
 */
  virtual void GetSplittingElements (int iSupport, CATLISTP(CATGeometry)&oElementsList, CATListOfInt& oSides);

  /**
   * @nodoc
   * @return [out, CATBaseUnknown#Release]
  */
  virtual CATContextForFastRun* GetContextForFastRun(CATBoolean iGetOnly = FALSE);

  /**
   * @nodoc
   * @return [out, CATBaseUnknown#Release]
  */
  virtual CATDynChamferContextForFastRun* GetDynChamferContextForFastRun(CATBoolean iGetOnly = FALSE);

  // -----------------------------------------------------------------------------------
  // CGM Internal Use
  // -----------------------------------------------------------------------------------
  private:
        /** 
     * @nodoc 
         */
  virtual int  RunOperator();

        /** 
     * @nodoc 
         */
  CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);

        /** 
     * @nodoc 
         */
  void WriteInput(CATCGMStream  & ioStream);

        /** 
     * @nodoc 
         */
  void RequireDefinitionOfInputAndOutputObjects();

        /** 
     * @nodoc 
         */
  void Dump(CATCGMOutput& os);

};


/**
 * Creates a CATDynChamfer operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iPart
 * The pointer to the body to chamfer.
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator after use.
 */
ExportedByBODYNOPE CATDynChamfer* CATCreateDynChamfer (CATGeoFactory*     Container,
                                                       CATTopData*        iData,
            						                               CATBody*           iPart) ; 
  

#endif
