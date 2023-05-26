// COPYRIGHT DASSAULT SYSTEMES 2000
//==========================================================================
//
// Objet d'extraction de peigne : cas d'une courbe sans contrainte G1 - 
//                                gestion avec des voisins en contact G1.
//
// JSX : Les limites sont definies par le premier et dernier parametre de iSetOfParams
//==========================================================================
//    04 00 NDN Creation
// 02 12 09 JSX Ajout de LocalEvalG1direction et de Get/SetExtrudeDir
// 19 10 10 JSX ajout ier a ComputeDeformDataFromDir et EvalLocalCoordSystem
// 23 12 11 NLD Ajout Update()
//==========================================================================

#ifndef CATFrF3DComb_H
#define CATFrF3DComb_H

#include "CATFrFComb.h"

#include "CATMathVector.h"
#include "CATMathDirection.h"
#include "FrFOpeCrv.h"

class CATCurve;
class CATGeoFactory;
class CATMathSetOfPointsND;
class CATCrvParam;

//--------------------------------------------------------------------------
class ExportedByFrFOpeCrv CATFrF3DComb : public CATFrFComb
{
 public:
  //--------------------
  // Constructor
  //--------------------
  CATFrF3DComb(      CATGeoFactory        * iFactory,
               const CATCurve             * iCurve,
               const CATMathSetOfPointsND * iSetOfParams,
               const CATMathSetOfPointsND * iSetOfVectors);

  //--------------------
  // Destructor
  //--------------------
  virtual ~CATFrF3DComb();

  //To get the type of Comb.
  virtual CATBoolean IsATypeOf(const CATTypeOfComb &iType) const;
  //To choose the way the comb is constructed : normalized direction law
  //give better results (i.e. iNormalize=1) but it is not possible if one
  //of the imposed directions have null norm.
          void       SetNormalizeDirection(CATLONG32 iNormalize);
          CATLONG32  IsDirectionNormalized() const;
  //To add or replace a reference vector.
          void       SetDirection(const CATCrvParam &iParam,const CATMathVector &iVect);
  //To be defined, it should have at least one imposed non zero direction at its extremities.
          CATBoolean IsDefined();

  // To get maximal angular deformation. The result is expressed in radian.
  virtual double GetAngularDeviation(const CATCrvLimits *iLim = NULL);

  //To get the minimal and maximal length of the comb.
  virtual void GetMinMaxCombLength(double &oMinLength,
                                   double &oMaxLength);

  //To impose a cross derivative. Only at ends.
          void SetCrossDerivative(const CATCrvParam &iParam,const CATMathVector &iVect);

  virtual void ComputeDeformDataFromDir(      CATError     *&ier,
                                        const CATCrvParam   &iParam,
                                        const CATMathVector &iDir,
                                              double        &iLength,
                                              double        &iAngleDir,
                                              double        &iAngleDef);

  void Dump() const;

  void SetExtrudeDir(CATMathVector &dir);
  CATLONG32 GetExtrudeDir(CATMathVector *&dir);

  //Private method.To get informations.
private:
  void LocalEvalG1Direction(double iparam,double *iDefaultDirForG1,double *iFirstDerivDefaultDirForG1);
  void Update(); // Update des derivées et derivées secondes selon la valeur de _IsUpToDate

 protected:
  virtual void EvalLocalCoordSystem(CATError *& oer,
                                    double      iparam,
                                    double   *  iDefaultDirForG1,
                                    double   *  iDerCrv,
                                    double   *  iNormal,
                                    double   *  iFirstDerivDefaultDirForG1 = NULL,
                                    double   *  iDer2Crv                   = NULL,
                                    double   *  iDerNormal                 = NULL);
  virtual void EvalDirectionForG2(double iparam, double *iDirForG2);

  //Datas
  CATLONG32                              _IsUpToDate;
  CATMathSetOfPointsND                  *_Param;
  CATMathSetOfPointsND                  *_Dir;
  CATMathSetOfPointsND                  *_Tg;
  CATMathSetOfPointsND                  *_Ds;
  CATLONG32                             *_Impo;
  CATLONG32                              _Normalize;
  CATMathDirection                       _DirExtrude;    // For NormalMode Only
  CATLONG32                              _DirExtrudeISet;// For NormalMode Only
};
#endif
