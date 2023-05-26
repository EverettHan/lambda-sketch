#ifndef CATMathVectorMass_H  
#define CATMathVectorMass_H  

// JSX 06:10/22 Add DBG_EVAL3dPts for visu of evaluation
//=============================================================================
class CATMathInterval;
class CATMathSetOfPointsND;
class CATMathAttrList;
class CATMathIntervalND;
class CATMathEvalRecord;
class CATMathPoint;


#include "YN000FUN.h"
#include "CATMathDef.h"
#include "CATMathInterval.h"
#include "CATMathDiagnostic.h"
#include "CATMathFunctionX.h"

#include "CATCGMVirtual.h"
#include "CATMathVectorialFunctionXY.h"
#include "CATSoftwareConfiguration.h"
#include "CATMathFunctionXY.h"
#include "CATMath3DUtils.h"
#include "CATMath.h"

//=============================================================================
//          Fonctions pour �valuer le :
//             1) volume                     [0]
//             2) Centre de gravite  (dim 3) [1 3]
//             3) matrice d'inertie  (dim 6) [4 10]
//             4) aire                       [11]
//=============================================================================
// 2006, creation EZY
// 07/2008, kub : ajout de GetUnits pour connaitre des unit�s des valeurs de sortie
//=================================================================================

class CATSoftwareConfiguration;

//-----------------------------------------------------------------------------
class ExportedByYN000FUN CATMathVectorMass  : public CATMathVectorialFunctionXY
   {
   public:
      CATMathVectorMass(CATSoftwareConfiguration * iConfig,
         const CATMathFunctionXY  * iSX , 
         const CATMathFunctionXY  * iSY, 
         const CATMathFunctionXY  * iSZ,
         CATMathPoint             & iCoordMean, 
         CATBoolean                 iSurfacicMode,
         const CATMathFunctionX   * iVt);

      ~CATMathVectorMass ();

      void Eval(const double t, const double u, double * oFtu) const;

      void GetUnits(int * oUnit) const;

      void DecompositionAlongV();

      // Get methods
      void GetFunctionXY(const CATMathFunctionXY *funcxy[3]) const;
      void GetFunctionX(const CATMathFunctionX *&funcx) const;
      void GetInfo(CATBoolean &osurfacicMode, CATBoolean & oDecompositionAlongV) const;
      void GetMean(double oCoordMean[3]) const;
      void DBG_EVAL3dPts(const double t, const double  u, double* pts);

   protected:

      // Surface global equations.
      const CATMathFunctionXY * _SX, * _SY, * _SZ;
      // PCurve V(t) global equation.
      const CATMathFunctionX * _Vt;
      // Reference Z coordinate for volume evaluation.
      double _CoordMean[3];
      CATBoolean _surfacicMode;
      CATBoolean _DecompositionAlongV;

      CATSoftwareConfiguration * _Config;
   };  
#endif  
