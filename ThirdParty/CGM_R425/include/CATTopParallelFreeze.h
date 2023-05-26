#ifndef CATTopParallelFreeze_H
#define CATTopParallelFreeze_H

// COPYRIGHT DASSAULT SYSTEMES  1999


#include "ParallelLight.h"
#include "CATTopParallel.h"
#include "CATMathDef.h"
//
class CATWire;
class CATBody;
class CATDistanceTool;
class CATLaw;
class CATSimplifyParallelTool;
class CATICGMExtrapolParallelTool;

class ExportedByParallelLight CATTopParallelFreeze : public CATTopParallel
{
  CATCGMVirtualDeclareClass(CATTopParallelFreeze);
public :

  //CATTopParallelFreeze(CATGeoFactory* iFactory, CATCGMJournalList* iJournal=0);
  CATTopParallelFreeze(CATGeoFactory* iFactory, CATTopData* iData=0);
  
  virtual              ~CATTopParallelFreeze() 		;

  // valeur 1 pas de trim realise. Le body resultant est invalide et doit etre detruit
  // utiliser cette valeur uniquement pour de la visu et optimiser ces perfos
  // valeur 0 traitement normal
  virtual void SetNoTrim(CATLONG32 notrim); 

  // valeur 1 traitement des twists
  // valeur 0 traitement normal
  void TwistedAuthorized(CATLONG32 twisted); 
  
  // Allow the use of G0Law - 1 on / 0 off
  void UseG0LawAuthorized( CATLONG32 AllowG0Law );
  CATLONG32 GetUseG0LawAuthorized();
  
  virtual CATLONG32 SetSimplifyTool(CATSimplifyParallelTool * CurSimplif);

  // 1 = simplification des PLines
  // 0 = pas de simplification des PLines
  virtual void SetPLineSimplif(CATLONG32 simplif);  
  virtual void GetPLineSimplif(CATLONG32 & simplif) ;  

  void Freeze(int iFreeze);

  // utilitaire : recuperation de lois de mapping sur un wire
  static void GetMappings(CATGeoFactory * Facto, CATTopData * iData, CATBody * iWire, CATLONG32  & nblaws, CATLaw **& MapLaws);

  virtual void SetLayDownTolerance(double Tolerance);
  virtual void GetLayDownTolerance(double &Tolerance);

  // Start : SUH : 2003:5:21
  virtual void SetSimplifOn(int);
  // End : SUH : 2003:5:21

  // S9L : Parallel Extrapolation : Start
    
  /**
  * Set the extrapolation mode
  * for the extrapolation of the parallel result wire on the support shell (Optional)
  * @param iExtrapolationMode
  * <br><b>Legal values</b>:
  * <dl><dt><tt>0</tt><dd> No Extrapolation.
  *     <dt><tt>1</tt><dd> Extrapolation in tangency continuity. 
  *     <dt><tt>2</tt><dd> Extrapolation in curvature continuity. </dl>
  */
  virtual void SetExtrapolationMode(short iExtrapolationMode = 0);

  /**
  * Set the direction to extrapolate result up to support boundary (Optional)
  * @param iExtrapolationDirection
  * <br><b>Legal values</b>:
  * <dl><dt><tt>-1</tt><dd> Extrapolate result backward up to support boundary from start vertex.
  *     <dt><tt>0</tt><dd> No Extrapolation. 
  *     <dt><tt>1</tt><dd> Extrapolate result forward up to support boundary from end vertex. 
  *     <dt><tt>2</tt><dd> Extrapolate result both directions up to support boundary. </dl>
  */
  virtual void SetExtrapolationDirection(short iExtrapolationDirection = 0);

  /**
  * Get the extrapolation mode
  * for the extrapolation of the parallel result wire on the support shell
  */
  virtual void GetExtrapolationMode(short &oExtrapolationMode);

  /**
  * Get the direction to extrapolate result up to support boundary 
  */
  virtual void GetExtrapolationDirection(short &oExtrapolationDirection);

  // S9L : Parallel Extrapolation : End
  
  virtual void CompleteSolutionForPlanarSupport();
  
protected :

  int _IsFrozen;
  CATLONG32 _NoTrim;
  CATLONG32 _Twisted;
  CATLONG32 _Simplif;
  CATSimplifyParallelTool * _CurSimplTool;
  double _LayDownTolerance;
  CATLONG32 _AllowG0Law;
  short _ExtrapolMode;
  short _ExtrapolDirection;
  CATBoolean _CompleteSolForPlanarSupp;

  // Start : SUH : 2003:5:22
  CATBoolean _DoFaceSimplif;
  // End : SUH : 2003:5:22

  CATBody * _Support;
  CATBody * _Curve;
};

/** @nodoc */
ExportedByParallelLight
CATTopParallelFreeze * CreateNONL1Parallel(CATExtrapolParallelTool * iOption, CATBody * iCurve);

/** @nodoc */
ExportedByParallelLight
CATTopParallelFreeze * CreateNONL1ParallelLight(CATExtrapolParallelTool * iOption, CATBody * iCurve);

ExportedByParallelLight
CATTopParallelFreeze * CreateNONL1Parallel(CATICGMExtrapolParallelTool * iOption, CATBody * iCurve);

/** @nodoc */
ExportedByParallelLight
CATTopParallelFreeze * CreateNONL1ParallelLight(CATICGMExtrapolParallelTool * iOption, CATBody * iCurve);

#endif


