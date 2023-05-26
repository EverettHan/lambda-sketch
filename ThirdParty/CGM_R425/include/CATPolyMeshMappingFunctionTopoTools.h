// COPYRIGHT Dassault Systemes 2013
//===================================================================
//
// .h
// The dialog : 
// It is a command.....???
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//  April 2013  Creation: ktu
//===================================================================
#ifndef CATPolyMeshMappingFunctionTopoTools_H
#define CATPolyMeshMappingFunctionTopoTools_H
#include "Polygon2Surface.h"
//#include "CATLISTV_CATMathPoint2D.h"
//#include "CATLISTV_CATMathPoint.h"
#include "CATPolyMeshMappingFunction.h"
#include "CATMathSetOfPointsND.h"
class CATSoftwareConfiguration;
class CATWire;
class CATEdge;
class CATPCurve;
class CATMathTransformation;
class CATPolyMeshMappingFunction;

class ExportedByPolygon2Surface CATPolyMeshMappingFunctionTopoTools
{
public :
    CATPolyMeshMappingFunctionTopoTools(      CATPolyMeshMappingFunction * ipMappingFunction,
                                              CATSoftwareConfiguration   * ipConfig         ,
                                        const double                       iResolution      );
   ~CATPolyMeshMappingFunctionTopoTools( );

   int Eval          (       CATEdge               *  ipEdge3D                   ,
                       const double                   irelativeSag               ,
                             CATMathSetOfPointsND  *& oplEvalMathPoint2D         ,            /*dim=3*/
                             CATMathSetOfPointsND **  opplDiscretizeMathPoint3D  = NULL); /*opt dim=3*/
   int EvalInverse   (       CATEdge               *  ipEdge2D                   ,
                       const double                   irelativeSag               ,
                             CATMathSetOfPointsND  *& oplEvalMathPoint3D         ,            /*dim=3*/
                             CATMathSetOfPointsND **  opplDiscretizeMathPoint3D  = NULL   /*opt dim=3*/);
   int SetTransfoTo2D( const CATMathTransformation *  ipTansfo);


private:

   void DeleteTransfos();
   void ReleaseBuffers();
   int  TesselateEdge (      CATEdge               *  ipEdge      ,
                       const double                   irelativeSag,
                             CATMathSetOfPointsND  *& opSetPoints ,
                             CATMathSetOfPointsND  *& opSetCrv    ,
                             double                 & oSag        )const;
   int  ComputeD2     (      CATPCurve             *  ipPCurve    ,
                       const CATMathSetOfPointsND  *  iSetParam   );
                      //, CATLISTV(CATMathPoint2D) &olDiscretizeMathPoint2D )/*const*/ ;

   const double                       _Resolution;
         CATPolyMeshMappingFunction * _pMappingFunction;
         CATSoftwareConfiguration   * _pConfig;
         CATMathTransformation      * _pTransfoTo2D;
         CATMathTransformation      * _pTransfoToResult2D;
   
         CATMathSetOfPointsND       * _pBufferSetPoints3D;
         CATMathSetOfPointsND       * _pBufferSetParam1D; 
};

#endif 
