/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1999
//------------------------------------------------------------------------------
//
// class for Hybrid Intersection Shell Shell
//
//------------------------------------------------------------------------------
// Usage Notes:
//------------------------------------------------------------------------------
// Inheritance:
//------------------------------------------------------------------------------
//
#ifndef CATHybIntersectShellShell_h
#define CATHybIntersectShellShell_h

#include "CATHybIntersect.h"
#include "CATExtHybIntersect.h"
//#include "ExportedByCATTopImpl.h"
#include "ExportedByPBELight.h"
#include "ListPOfListPOfCATEdge.h"
#include "CATIAV5Level.h"

class CATCGMJournal;

class ExportedByPBELight CATHybIntersectShellShell : public CATExtHybIntersect
{
public :

   //  Constructor
   CATHybIntersectShellShell(CATGeoFactory* iFactory, CATTopData* iData, CATBody* iBody1, CATBody* iBody2);

   // Surcharge du new/delete
   CATCGMNewClassArrayDeclare;

   //  Destructor
   ~CATHybIntersectShellShell();

   //  Methods
   int RunOperator();

   int Run();

#ifdef CATIAR419
   // Poly/Exact Config Management 
   virtual CATBoolean Is_PolyInputs_Allowed();
   virtual CATBoolean Is_MixedPolyExactInputs_Allowed();
#endif

   static const CATString* GetDefaultOperatorId() { return &_OperatorId; }

   /** @nodoc @nocgmitf */
   inline void SetFillConfusionBordersList(CATBoolean iFillConfusionBordersList) {_FillConfusionBordersList = iFillConfusionBordersList;}

   void GetConfusionBordersList(ListPOfListPOfCATEdge & oConfusionBorders);


   /** @nodoc
   * Extrapolation mode
   * for the extrapolation of the intersetion result wire on the SupportSurface
   * @param iExtrapolationMode
   * <br><b>Legal values</b>:
   * <dl><dt><tt>0</tt><dd> No Extrapolation.
   *     <dt><tt>1</tt><dd> Extrapolation in tangency continuity. </dl>
   *     <dt><tt>2</tt><dd> Extrapolation in curvature continuity. </dl>
   */
   void SetExtrapolationMode(short iExtrapolationMode = 0);
   void GetExtrapolationMode(short &oExtrapolationMode);

   /** @nodoc
   * Extrapolation mode
   * for the extrapolation of the intersetion result wire on the SupportSurface
   * @param iShellExtrapolationllSupport
   * <br><b>Legal values</b>:
   * <dl><dt><tt>0</tt><dd> No Extrapolation.
   *     <dt><tt>1</tt><dd> Extrapolation on first support. </dl>
   *     <dt><tt>2</tt><dd> Extrapolation on second support. </dl>
   *     <dt><tt>3</tt><dd> Extrapolation on two supports. </dl>
   */
   void SetExtrapolationShellSupport(short iShellExtrapolationSupport = 0);
   void GetExtrapolationShellSupport(short &oShellExtrapolationSupport);

protected :
  
#ifdef CATIAR419
   //============================
   // Poly/Exact Config Management 
   //============================
   virtual int RunPolyOperator();
#endif

   const CATString * GetOperatorId() const;

   void CheckTangentDesignShell();

   void FilterCurveGeometry(
      CATBody      *iBody,
      CATBody      *iReferenceBody );

   //extrapolation intersection wire result on each support

   //Extrapolation intersection wire mode
   CATBoolean AreIntersected(CATLISTP(CATBody) * BodiesToAsemmble);
   int ISinIntersWire( CATBody *  BodyExtrapol,CATBody *  BodySupport2);
   CATBody * GetWireAssembleResult(CATBody * WireRes, CATBody *  BodyExtrapol1,CATBody *  BodyExtrapol2);
   CATBody * GetWireInt(CATBody * WireRes, CATBody *  BodyExtrapol, int iType,int &oPosition);
   void GetSupportEdgeOnBoudary(CATVertex * StartVx1, CATBody *Body2ToIntersect, CATLISTP(CATCell) & oEdgesBorderList );
   void JournalAfterExtrapol(CATBody * Body2ToIntersect);

private :

   static CATString _OperatorId;

   CATBoolean              _FillConfusionBordersList;
   ListPOfListPOfCATEdge * _ConfusionBorders;

   ////Extrapolation intersection wire mode
   //CATBoolean AreIntersected(CATLISTP(CATBody) * BodiesToAsemmble);
   //CATBoolean ISinIntersWire( CATBody *  BodyExtrapol,CATBody *  BodySupport2);
   //CATBody * GetWireAssembleResult(CATBody * WireRes, CATBody *  BodyExtrapol1,CATBody *  BodyExtrapol2);
   //CATBody * GetWireInt(CATBody * WireRes, CATBody *  BodyExtrapol, int iType);
   //void GetSupportEdgeOnBoudary(CATVertex * StartVx1, CATBody *Body2ToIntersect, CATLISTP(CATCell) & oEdgesBorderList );
   //void JournalAfterExtrapol(CATBody * Body2ToIntersect);
};
#endif
