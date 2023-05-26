#ifndef CATTopPartingLine_H
#define CATTopPartingLine_H

#include "CATTopOperator.h"       // derivation
#include "AdvThickness.h"         // exportation
//#include "CATTopPartingLineType.h" // enum

#include "CATBoolean.h"
#include "CATSysBoolean.h"
#include "ListPOfCATFace.h"
#include "CATListOfInt.h"

class CATTopPartingLineImpl;
class CATMathPoint;
class CATMathDirection;
class CATMathPlane;
class CATBody;
class CATDomain;


class ExportedByAdvThickness CATTopPartingLine : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopPartingLine);

public:

  /** @nodoc 
  * cannot be called
  */
  // Constructor
  // Please, call CATCreateTopPartingLine() method to create an instance
  CATTopPartingLine(CATGeoFactory         * iFactory,
                    CATTopData            * iTopData,
                    CATTopPartingLineImpl * iImpl   );


  // Destructor
  virtual ~CATTopPartingLine();

  // ----------------------------------------------------------------------------
  // 1. View definition 
  
  // -> The caller has to choose exclusively between perspective and parallel view


  // PERSPECTIVE VIEW (conical view)
  // ----------------
  //
  // This call defines EXPLICITLY the conical view by the point of view from which the observer can see the 3D scene.
  // In this case, the 3D scene has to be totally contained by one half of the full 3D space around the view point.
  //
  /** @nodoc 
  */
  void                SetViewPoint          (const CATMathPoint      & iPt);


  // PARALLEL VIEW (cylindrical view)
  // -------------
  //
  // This call defines EXPLICITLY the cylindrical view by the direction used to observe the 3D scene.
  // This set is NOT MANDATORY : another way to define IMPLICITLY the cylindrical view consists in 
  // calling SetShadowScreen() method, setting the "iViewSide" option to +1 or -1. 
  //
  /** @nodoc 
  */
  void                SetViewDirection      (const CATMathDirection  & iDir);

  void                SetJournalList        (      CATCGMJournalList & ioJournalList);

  CATCGMJournalList * GetJournalList        ();

  // To be used for Volumetric Sweep context
  //
  /** @nodoc 
  */
  void                SetVolumetricSweepMode(const CATMathVector     & iFirstVector,
                                             const CATMathVector     & iSecondVector);
  //
  /** @nodoc 
  */
  void                GetListOfFacesAndSides(      CATLISTP(CATFace) & ioListOfFaces,
                                                   CATListOfInt      & ioListOfSides);
  
  // ----------------------------------------------------------------------------
  // Runs the operator
  /** @nodoc
   * @nocgmitf
  */
  virtual int RunOperator();
  
  // ------------------
  // CGMReplay Methodes
  // ------------------
  /** @nodoc
   * @nocgmitf
  */
  static const CATString *GetDefaultOperatorId();
  /** @nodoc
   * @nocgmitf
  */
  const CATString * GetOperatorId();
  /** @nodoc
   * @nocgmitf
  */
  CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);
  /** @nodoc
   * @nocgmitf
  */
  void WriteInput(CATCGMStream  & Str);
  /** @nodoc
   * @nocgmitf
  */
  void Dump( CATCGMOutput& os ) ;
    /** @nodoc
   * @nocgmitf
  */
  void DumpOutput( CATCGMOutput& os ) ;
  /** @nodoc
   * @nocgmitf
  */
  void RequireDefinitionOfInputAndOutputObjects();


protected:


  /** @nodoc 
  * cannot be called
  */
  // Internal implementation
  CATTopPartingLineImpl * GetTopPartingLineImpl();
};

/**
 * Creates a CATTopPartingLine operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iBody
 * The pointer to the body whose PartingLine needs to be computed.
 * @return [out, delete]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByAdvThickness
CATTopPartingLine * CATCreateTopPartingLine(CATGeoFactory * iFactory,
                                            CATTopData    * iTopData,
                                            CATBody       * iBody   );

#endif

