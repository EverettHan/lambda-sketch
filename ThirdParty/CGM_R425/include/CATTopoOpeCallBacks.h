// COPYRIGHT DASSAULT SYSTEMES 2004
//=============================================================================
//
// CATTopoOpeCallBacks:
// Utility for topology calls from GeometricOperators
//
//                                                    Nicolas LOCHARD
//=============================================================================
// Usage notes:
//
// instance au niveau topologique de la classe de callbacks topologiques pour geometricoperators
// (transmettre un objet de la classe à l'operateur géométrique concerné)
//=============================================================================
// 22 02 05 NLD Creation par découpage de CATAdvTopoOpeCallBacks
//              ConstructsBodyFromGeometry()
//              CreateTopoOpInError()
// 08 08 05 JSX Ajout de AddWarning
// 11 10 06 NLD Ajout de GetWarning() et rapatriement du code de CATAdvTopoOpeCallBacks
//              pour AddWarning() et GetWarning() ainsi que de _Diagnosis
// 12 10 06 NLD _DiagnosisList remplace _Diagnosis pour gestion de warnings multiples
// 28/03/13 NLD Ajout de _ReferenceCounter, AddRef(), Release()
//              Le destructeur n'est plus accessible (il faut utiliser Release())
// 03/07/19 NLD Ajout CurvesReduction()
//=============================================================================

#ifndef CATTopoOpeCallBacks_H
#define CATTopoOpeCallBacks_H

#include <BO0SWEEP.h>
#include <CATTopologyCallBacks.h>

class CATBody ;
class CATFrFCompositeCurve ;
class CATCGMDiagnosis ;
#include <CATCollec.h> // pour CATListPV
#include <CATListPV.h>
class CATLISTP(CATCrvLimits);
class CATLISTP(CATCurve);

class ExportedByBO0SWEEP CATTopoOpeCallBacks  : public CATTopologyCallBacks
{
 protected:
   virtual                  ~CATTopoOpeCallBacks() ;
 public:
 
                             CATTopoOpeCallBacks() ;
 
   // Construction d'un body à partir d'un element geometrique
   // Voir implementation pour types acceptes
   // rend un body nul si type non accepté
 
           void              ConstructsBodyFromGeometry (CATGeoFactory            *  iFactory,
                                                         CATSoftwareConfiguration *  iConfig ,
                                                         CATGeometry              *  iGeom   ,
                                                         CATBody                  *& oBody   ) ;

   // Creation d'une erreur de type CATTopOpInError
   // arguments supplementaires optionnels pour aide au diagnostic
   // les geometries sont converties en bodies
           CATError        * CreateTopOpInError   (const char                     *  msgId         ,
                                                         CATGeoFactory            *  iFactory      = NULL,
                                                         CATSoftwareConfiguration *  iConfig       = NULL,
                                                         CATLISTP(CATGeometry)    *  iLocationList = NULL,
                                                         CATLISTP(CATGeometry)    *  iContextList  = NULL) ;

   // Ajout d'un Warning
           void              AddWarning(CATCGMDiagnosis* iDiag);
   // Recuperation d'un warning
           CATCGMDiagnosis * GetWarning();

   // Add    a reference to this object (and give back reference counter)
   virtual int               AddRef (void* iDebugPointingObject = 0);

   // Delete a reference to this object (and give back reference counter) (delete the object if reference counter decreased to 0)
   virtual int               Release(void* iDebugPointingObject = 0);

   // Deformation dediée Fillet NLD pour SMT1
   // RESTRICTED USE. DEDICATED PARAMETERIZATION
   // Arguments may change according to needs
   virtual void              CurvesReduction(CATGeoFactory           * iFactory              ,
                                             CATSoftwareConfiguration* iSoftwareConfiguration,
                                             CATLISTP(CATCurve)      & iCurves               ,
                                             CATLISTP(CATCrvLimits)  & iLims                 ,
                                             CATListOfInt            & iOris                 ,
                                             double                    iG1Threshold          , // in degree
                                             double                    iDeformationTol       ,
                                             CATLISTP(CATCurve)      & oResultCrvs           );


 private:
   //CATCGMDiagnosis    * _Diagnosis;
   CATListPV            _DiagnosisList ;
   int                  _ReferenceCounter ;
} ;
#endif 
