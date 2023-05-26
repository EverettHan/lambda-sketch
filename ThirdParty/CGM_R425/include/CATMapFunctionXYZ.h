#ifndef CATMapFunctionXYZ_H
#define CATMapFunctionXYZ_H

// COPYRIGHT DASSAULT SYSTEMES 2000
//==========================================================================
// 09/12/09 NLD Definition de nomenclature pour les #define partages:
//              OffsetMap devient CATMapFunctionXYZ_OffsetMap
// 14/12/09 PMG Supprime ce #define!
//==========================================================================

#include "FrFObjects.h"
#include "CATMathPoint.h"
#include "CATMathVector.h"
#include "CATMathTransformation.h"
#include "CATGeoFactory.h"
#include "CATNurbsCurve.h"
#include "CATGSDBase.h"
#include "CATCGMVirtual.h"


                    
/**
 * Class defining the map of a deformation.
 * <br>The map of a deformation is a C2 continuous function from <tt>R^3</tt> to <tt>R^3</tt>.
 */
class ExportedByFrFObjects CATMapFunctionXYZ : public CATCGMVirtual
{
  public:

  
  /**
   * Tests the type of <tt>this</tt> map.
   * @param iMapTypeName
   * The name of the class to test
   * @return
   * The result of the test.
   * <br><b>Legal values</b>: <tt>TRUE</tt> if <tt>this</tt> is of type <tt>iMapClassName</tt>,
   * <tt>FALSE</tt> otherwise.
   */ 
  virtual CATBoolean IsAKindOf(const char* iMapClassName) const = 0;

  /**
   * Tests whether <tt>this</tt> map is linear.
   * @return
   * The result of the test.
   * <br><b>Legal values</b>: <tt>TRUE</tt> if <tt>this</tt> is linear,
   * <tt>FALSE</tt> otherwise.
   */ 
  virtual CATBoolean IsALinearMap() const = 0;

  /**
   * Retrieves the corresponding linear transformation in case of a linear map.
   * @param ioTransformation
   * The corresponding linear transformation if <tt>this</tt> is linear.
   */
  virtual CATLONG32 GetMathTransformation(CATMathTransformation & ioTransformation) const = 0;

  /**
   * Evaluates <tt>this</tt> map.
   * @param iInitialPoint
   * The point where to evaluate <tt>this</tt> map.
   * @param oDeltaP
   * The corresponding deformation for this point.
   */
  virtual CATLONG32 Eval(const CATMathPoint& iInitialPoint, CATMathPoint &oDeltaP) const = 0 ;

  /**
   * Evaluates the first derivatives of <tt>this</tt> map.
   * @param iInitialPoint
   * The point where to evaluate <tt>this</tt> map.
   * @param ioDu
   * The u derivative.
   * @param ioDv
   * The v derivative.
   * @param ioDw
   * The w derivative.
   */
  virtual CATLONG32 EvalFirstDeriv(const CATMathPoint& iInitialPoint, 
                  CATMathVector& ioDu, CATMathVector& ioDV,CATMathVector& ioDw) const = 0;

  /**
   * Evaluates the second derivatives of <tt>this</tt> map.
   * @param iInitialPoint
   * The point where to evaluate <tt>this</tt> map.
   * @param ioDu2
   * The u derivative.
   * @param ioDv2
   * The v derivative.
   * @param ioDw2
   * The v derivative.
   * @param ioDuv
   * The uv derivative.
   * @param ioDuw
   * The uw derivative.
   * @param ioDvw
   * The vw derivative.
   */
  virtual CATLONG32 EvalSecondDeriv(const CATMathPoint& iInitialPoint, 
                                          CATMathVector& ioD2u, CATMathVector& ioD2v, CATMathVector& ioD2w,
                                          CATMathVector& ioDuv, CATMathVector& ioDuw, CATMathVector& ioDvw) const = 0;

 
  /**
   * Evaluates the third derivatives of <tt>this</tt> map.
   * @param iInitialPoint
   * The point where to evaluate <tt>this</tt> map.
   * @param ioDu3
   * The u derivative.
   * @param ioDv3
   * The v derivative.
   * @param ioDw3
   * The v derivative.
   * @param ioD2uDv
   * The uuv derivative.
   * @param ioD2uDw
   * The uuw derivative.
   * @param ioD2vDu
   * The vvu derivative.
   * @param ioD2wDu
   * The wwu derivative.
   * @param ioD2wDv
   * The wwv derivative.
   * @param ioDuvw
   * The uvw derivative.
   */
/*  virtual CATLONG32 EvalThirdDeriv(const CATMathPoint& iInitialPoint, 
                                           CATMathVector& ioD3u, CATMathVector& ioD3v, CATMathVector& ioD3w,
                                           CATMathVector& ioD2uDv, CATMathVector& ioD2uDw, CATMathVector& ioD2vDu,
                                           CATMathVector& ioD2vDw, CATMathVector& ioD2wDu, CATMathVector& ioD2wDv,
                                           CATMathVector& ioD3uvw) const = 0;*/
  /**
   *@nodoc
   *The map is model dependant if it depends upon the body to deform
   */
  virtual CATBoolean IsModelDependant() const;

  /**
   *@nodoc
   *Return:
   *0  by default
   *1  if the deformation is along the normal and in the positive direction with respect to the skin
   *-1 if the deformation is along the normal and in the negative direction with respect to the skin
   */
  virtual int GetDeformationAlongNormal() const;

  /**
   *@nodoc
   *Return:
   *0  if the deformed surface has not to be checked 
   *1  if the deformed surface has to be checked due to multiple projections on Ref/Targ Surface
   * other  if the deformed surface has to be checked due to other reason 
  */
  virtual int GetHasToBeChecked()  const;
  /**
   *@nodoc
   *Initialize the check detection
  */
  virtual void SetHasToBeChecked(int & iCheckCode)  const ;


  // Pour le MultiThreading
  virtual CATBoolean IsThreadSafe() const;  

  // Clone pour MultiThreading 
  // return 1 : copy impossible
  virtual CATLONG32 Clone(CATMapFunctionXYZ * & oCopyMapFunctionXYZ, CATGeoFactory * ifactory) const;


  /**
   * Increments the reference count of the instance.
   */
   void AddRef();

  /**
   * Decrements the reference count of the instance.  When the counter reaches 0, the instance is deleted.
   */
  void Release();


  protected:

      CATMapFunctionXYZ();
      virtual ~CATMapFunctionXYZ();

  private:

      CATMapFunctionXYZ(const CATMapFunctionXYZ &);
      void operator = (const CATMapFunctionXYZ &);

      int _CountRef;
  };
/* 
ExportedByFrFObjects  CATMapFunctionXYZ* 
CATCreateWrapCurveGeoMap(CATGeoFactory  *iFactory ,
                      const CATNurbsCurve  *iRefSpine, 
                      const CATNurbsCurve  *iRefDirCurve, 
                            CATNurbsCurve **iRefCurves,
                      const CATNurbsCurve  *iTargSpine, 
                      const CATNurbsCurve  *iTargDirCurve, 
                            CATNurbsCurve **iTargCurves,
                      const CATLONG32            iNbCurves);

ExportedByFrFObjects  CATMapFunctionXYZ* 
CATCreateWrapCurveGeoMap(CATGeoFactory  *iFactory ,
                      const CATNurbsCurve  *iRefSpine, 
                      const CATLONG32             DirKind,
                      const CATNurbsCurve  *iRefDirCurve, 
                            CATNurbsCurve **iRefCurves,
                      const CATNurbsCurve  *iTargSpine, 
                      const CATNurbsCurve  *iTargDirCurve, 
                            CATNurbsCurve **iTargCurves,
                      const CATLONG32            iNbCurves);

ExportedByFrFObjects  CATMapFunctionXYZ* 
CATCreateWrapSurfaceGeoMap(CATGeoFactory  *iFactory ,
                      const CATNurbsSurface  *iRefSurf, 
                      const CATNurbsSurface  *iTargSurf);
*/   
#endif
