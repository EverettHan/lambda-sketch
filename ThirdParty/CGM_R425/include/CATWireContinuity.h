// COPYRIGHT DASSAULT SYSTEMES 2000
//=============================================================================
//
// CATWireContinuity
// -----------------
// Compute continuity informations at the vertices of a body wire.
// The body wire has a single wire domain that may be opened or closed.
// Operator returns :
// - the G order of continuity at each vertex ( G0, G1 or G2 )
// - the distance gap between incident edges at each vertex
// - the angular gap between tangents to edges at each vertex, in degrees.
//
// Vertex index ranges from 1 to NbVertex() value.
//   
// Point and tangent gaps are computed independently of continuity order.
//
//=============================================================================
// Usage notes:
// sample of use :
//
// CATBody* Body = .... ; // mono wire-domain body
// CATGeoFactory* Factory = ... ;
// ...
// CATWireContinuity* ContinuityOpe = new CATWireContinuity(Factory,Body);
// if ( ContinuityOpe )
// {
//   ...
//   int runstatus = ContinuityOpe->Run();
//   int NbVertex = ContinuityOpe-<NbVertex();
//   ...
//   int iVertex = 1; // range [1..NbVertex] 
//   CATLONG32 status = 0;
//   ...
//   CATFrFContinuity Gorder;
//   status = ContinuityOpe->GetGOrder(iVertex);
//   ...
//   CATLength G0gap; // distance between edge extremities
//   status = ContinuityOpe->GetDeltaPt(iVertex); 
//   ...
//   CATAngle G1gap; // G1gap in degree
//   status = ContinuityOpe->GetDeltaTg(iVertex); 
//   ...
//   delete ContinuityOpe;
//   ContinuityOpe = NULL;
//   ...
// } 
//
//=============================================================================
//
//=============================================================================
#ifndef CATWireContinuity_H
#define CATWireContinuity_H

// eh merde il y a encore un soft qui fait chier
// en etant a la fois sur ce vieil operateur et sur son vieux constructeur
// c'est CATCoreCavitySeparationUI/CATCCSServicesUI.m/src/CATCCSFilletUtils.cpp
// qui appelle CATPGMCreateWireContinuity(iFactory->GetImplicitGeoFactory(),iBodyWire);
// #define CATWireContinuity_ShuntOldConstructor "NLD100118"

// pour branchement effectif des méthodes SetTol* anciennement inactives
// mais qui si on les active vont arriver via la filière CATIPGMWireContinuity
// par exemple sous CATGSOJunctionServices::DisconnecWire
// dans laquelle on passe les valeurs GetResolution(CatC0), GetResolution(CatC1), GetResolution(CatC2)
// or si l'on regarde CATTopWireContinuityCx7, on voit que
// - _iTolPt      est bien GetResolution(CatC0)
// - _iTolTgDeg   est la conversion en degrés de GetResolution(CatC1)
//   (l'appel de SetTolTg qui demande des degrés, depuis CATGSOJunctionServices est mauvais)
// - _iTolCvMode1 est bien GetResolution(CatC2)
// Donc l'activation de ce define aurait bel et bien un impact
// On trouve aussi une tolérance en tangence de 0.0087266462599716477 dans la migration V4
// et qui est issue d'une conversion de degré en radian (ne convenant donc pas du tout)
// 
// en fait il faudrait versionner mais le plus sage est de laisser en l'état
// ou alors de fournir de nouvelles signatures faisant le travail
// et d'encourager les applications à utiliser directement CATTopWireContinuity via CATIPGMTopWireContinuity
// #define CATWireContinuity_SetTolXXX "NOT TO ACTIVATE"

#include "AdvTopoUtil.h"
#include "CATFreeFormDef.h"
#include "CATTopOperator.h"
#include "CATTopWireContinuity.h"
  
class CATGeoFactory;
class CATBody;
class CATTopData;

class ExportedByAdvTopoUtil CATWireContinuity : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATWireContinuity);
  public:

  //=============
  //  Constructor
  //=============
  CATWireContinuity(CATGeoFactory * iFactory ,
                    CATTopData    * TopData  ,
                    CATBody       * iBodyWire);
  #ifndef CATWireContinuity_ShuntOldConstructor
  CATWireContinuity(CATGeoFactory * iFactory ,
                    CATBody       * iBodyWire);
  #endif
  
  //============
  //  Destructor 
  //============
  ~CATWireContinuity();

  //=========
  // Methods
  //=========
  
  //
  // Run : compute continuity informations on body wire
  //
  int       Run();

  //
  // Get the number of vertex of the wire
  // Vertex index ranges from 1 to NbVertex()
  int       NbVertex();
  
  // GetGOrder : returns G continuity order of vertex iVertex
  // iVertex = [1..NbVertex()]
  // returns 0 if OK, != on error
  CATLONG32 GetGOrder(int iVertex,CATFrFContinuity& oGOrder);

  // GetDeltaPt : returns oL = G0 gap (between points) at vertex iVertex
  // iVertex = [1..NbVertex()]
  // returns 0 if OK, != on error
  CATLONG32 GetDeltaPt(int iVertex,CATLength& oL);
  
  // GetDeltaTg : returns oA = G1 gap (between tangents) at vertex iVertex
  // iVertex = [1..NbVertex()]
  // returns 0 if OK, != on error
  CATLONG32 GetDeltaTg(int iVertex, CATAngle& oA);

  // GetRatioCv : returns oRatioCv = G2 curvature ratio of curvature vectors at vertex iVertex
  // oRatioCv value is in ]0..1]
  // iVertex = [1..NbVertex()]
  // returns 0 if OK, != on error
  CATLONG32 GetRatioCv(int iVertex, double& oRatioCv);

  // ------------------------------------
  //  To disappear
  // ------------------------------------
  // 
  // Get G continuity order of vertex iVertex 
  // WARNING : old style method, to disappear.
  // Use the Run() + GetGOrder(i),GetDeltaPt(i),GetDeltaTg(i) methods
  //
  CATFrFContinuity GetResult(int iVertex);



  // no doc @nocgmitf
  // do not use
  int Run(CATLength iTolPt);

  // Choose curvature measure implementation 
  // iMeasureMode = 1 or 2
  // In both implementations :
  //     - C0 measure based on standard C0 measure corresponding to CatC0
  //     - C1 measure based on standard C1 measure corresponding to CatC1
  // iMeasureMode = 1 to perform a C2 measure by comparison of 
  //                difference between curvature radii and CATEpsg
  // iMeasureMode = 2 to perform a standard C2 measure corresponding to CatC2
  // default (historical) value is 1.
  void SetMeasureMode(CATLONG32 iMeasureMode);
  

  // Get curvature measure implementation 
  // MeasureMode = 1 or 2
  // In both implementations :
  //     - C0 measure based on standard C0 measure corresponding to CatC0
  //     - C1 measure based on standard C1 measure corresponding to CatC1
  // MeasureMode = 1  a C2 measure by comparison of 
  //                difference between curvature radii and CATEpsg
  // iMeasureMode = 2  a standard C2 measure corresponding to CatC2
  // default (historical) value is 1.
  CATLONG32 GetMeasureMode();

  //-----------------------------------------------------------------------------
  // no doc
  //-----------------------------------------------------------------------------
  // CAUTION: SetTol*() methods unplugged; plugging would impact many callers
  // using non default tolerances                                       NLD110123
  //-----------------------------------------------------------------------------
  //  XX  XX                      XXX                                           XXX
  //  XX  XX                       XX                                            XX
  //  XX  XX   XX XXX  XX XXX      XX    XX  XXX   XXXX XX  XXXX XX  XXXXX       XX
  //  XX  XX   XXX XX   XX  XX     XX    XX  XX   XX   XX  XX   XX  XX    X   XXXXX
  //  XX  XX   XX  XX   XX  XX     XX    XX  XX   XX   XX  XX   XX  XXXXXXX  XX  XX
  //  XX  XX   XX  XX   XXXXX      XX    XX  XX    XXXXXX   XXXXXX  XX       XX  XX
  //   XXXX    XX  XX   XX        XXXX    XXX XX       X        X    XXXXX    XXXX X
  //                   XXXX                        XXXXX    XXXXX

#ifdef CATWireContinuity_SetTolXXX
  void SetTolPt(CATLength iTolPt); // see now implementation file
#else
  void SetTolPt(CATLength iTolPt)
 {};
#endif
#ifdef CATWireContinuity_SetTolXXX
  void SetTolTg(CATAngle iTolTgDeg); // see now implementation file
#else
  void SetTolTg(CATAngle iTolTgDeg)
  {};
#endif
#ifdef CATWireContinuity_SetTolXXX
  void SetTolCv(double   iTolCv); // see now implementation file
#else
  void SetTolCv(double   iTolCv)
  {};
#endif



  
  //---------------------------------------------------------
  
  private:

  CATTopWireContinuity* _TopWireContinuity;
  CATTopData            _TopData;  // for constructor without CATTopData
};

#endif
