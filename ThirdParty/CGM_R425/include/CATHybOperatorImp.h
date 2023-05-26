#ifndef CATHybOperatorImp_h
#define CATHybOperatorImp_h

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
* @level Protected
* @usage U1
*/ 

#include "BOHYBOPELight.h"
//------------------------------------------------------------------------------
#include "CATTopDef.h"
#include "CATHybDef.h"
#include "CATHybOperator.h"
#include "CATCGMOperatorDebug.h"
#include "CATIAV5Level.h"
#include "CATCGMJournal.h"
#include "ListPOfCATCell.h"

class CATTopCheckJournal;
class CATTopBooleanOperator;
class CATString;
class CATExtHybOperatorImp;

#define NEW_DEV_CAA

/**
* Class defining the operators operating with surfacic and wireframe entities.
*<br>
* These operators operate on the 2D (CATShell), 1D (CATWire) and 0D (CATVertexInVolume)
* domains of a CATBody.
* They follow the global frame of all operator and satisfy to the smart mechanism: the
* input bodies are not modified. A new resulting body is created, 
* possibly sharing data with the input bodies.
*<ul>
* <li>A CATHybOperator is created with a global function:
* <ul>
* <li> <tt>CATCreateTopAssemble</tt>: for an operator that assembles CATShell domains or CATWire domains
* <li> <tt>CATCreatTopDisconnect</tt>: for an operator that inserts a vertex in a wire or loop, or an edge in a shell
* <li> <tt>CATCreatTopIntersect</tt>: for an operator that intersects two bodies
* <li> <tt>CATCreateTopSplit</tt>: for an operator that splits a domain by
* another one
* <li> <tt>CATCreateTopTrim</tt>: for an operator that trims a domain by
* another one 
* together
* <li> <tt>CATCreateTopProject</tt>: for an operator that projects a domain on 
* another domain.
* </ul>
* It must be
* directly deleted with the usual C++ <tt>delete</tt> operator after use.
* It is not streamable. 
*<li>Options can be precised with the <tt>SetXxx</tt> methods, before
* asking for the computation with the <tt>Run</tt> method. 
*<li>In both cases, the result is accessed with the <tt>GetResult</tt> method. If you do not want 
* to keep the resulting body, use the @href CATICGMContainer#Remove method to remove it from the 
* geometric factory.
*</ul>
*/
class ExportedByBOHYBOPELight CATHybOperatorImp : public CATHybOperator
{
   
   
  CATCGMVirtualDeclareClass(CATHybOperatorImp);
protected:
   /** @nodoc */	
   CATHybOperatorImp(CATGeoFactory*, CATTopData* TopData, CATExtHybOperatorImp* iExtensible);
   
   
public:
   
   // Destructor
   virtual ~CATHybOperatorImp();

   /**
   * @nodoc
   * Returns a pointer to the resulting CATBody of <tt>this</tt> CATHybOperator.
   * <br> Must be called after the <tt>Run</tt> method only once. A second call returns a <tt>NULL</tt>
   * pointer.
   * @param iJournal
   * The pointer to the journal that must be filled.
   * @return
   * The pointer to the resulting body. Use @href CATICGMContainer#Remove if you do not want to keep it.
   */
   virtual CATBody* GetResult(CATCGMJournalList* iJournal);
   /**
   * Returns a pointer to the resulting CATBody of <tt>this</tt> CATHybOperator.
   * <br> Must be called after the <tt>Run</tt> method only once. A second call returns a <tt>NULL</tt>
   * pointer.
   * @return
   * The pointer to the resulting body. Use @href CATICGMContainer#Remove if you do not want to keep it.
   */
   virtual CATBody* GetResult();
   
   // @nocgmitf
   /**
   * Returns the state of the resulting body.
   * @return
   * The state of the resulting body. 
   * <br><b>Legal values</b>:
   * <dl>
   * <dt>0</dt><dd>The resulting CATBody is not frozen: it can be modified afterwards.
   * <dt>1</dt><dd>The resulting CATBody is frozen: it cannot be modified afterwards.
   * </dl>
   */
   short GetFreezeMode() const;
   
   // @nocgmitf
   /**
   * Defines the state of the resulting body.
   * @param iMode
   * The state of the resulting body. 
   * <br><b>Legal values</b>:
   * <dl>
   * <dt>0</dt><dd>The resulting CATBody is not frozen: it can be modified afterwards.
   * <dt>1</dt><dd>The resulting CATBody is frozen: it cannot be modified afterwards.
   * </dl>
   */
   void  SetFreezeMode(short mode=1);
   
   /** 
   * Defines the tolerance of the geometrically coincident elements to be taken 
   * into acccount by <tt>this</tt> operator.
   * <br>Very sensitive point. The default value is the factory resolution, 
   * and it is strongly recommended to keep it.
   * @param iTol
   * The tolerance.
   */
   void SetTolerance(double iTol);
   /** 
   * Returns the tolerance of the geometrically coincident elements to be taken 
   * into acccount by <tt>this</tt> operator.
   * @return
   * The tolerance.
   */
   double GetTolerance() const;
   
   
   /** @nodoc  */
   // Non necessaire en R20 CATCGMOperatorDebugDeclareRun(CATHybOperatorImp,CATCGMOperator);
   // car Run() toujours declare
   int Run() ;

   /** @nodoc @nocgmitf */
   virtual int RunOperator();  
   
   /** @nodoc */
   //   int IsDeprecated() const;
   
   /** @nodoc */
   void  SetCheckReport(short mode=1);
   /** @nodoc */
   short GetCheckReport() const;
   
   /** @nodoc @nocgmitf */
   CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);
   
   /** @nodoc @nocgmitf */
   void WriteInput(CATCGMStream  & ioStream);
   
   /** @nodoc @nocgmitf */
   void RequireDefinitionOfInputAndOutputObjects();
   
   /** @nodoc @nocgmitf */
   void Dump(CATCGMOutput& os);
   
   
   /** @nodoc  */
   inline CATExtHybOperatorImp* GetHybOperatorImpExtensible() const;
   
};


/** @nodoc  */
inline CATExtHybOperatorImp* CATHybOperatorImp::GetHybOperatorImpExtensible() const
{
   if (!_Extensible) CATThrowForNullPointerReturnValue(NULL);
   return (CATExtHybOperatorImp*) _Extensible;
}
   
#endif
