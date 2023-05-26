// COPYRIGHT Dassault Systemes 2021
//===================================================================
//
// CATCSMultiCurve.h
// Header definition of CATCSMultiCurve
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//

#ifndef CATCSMultiCurve_H
#define CATCSMultiCurve_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSCurve.h"
#include "CATCDSArray.h"

//-----------------------------------------------------------------------

/**
 * A geometry representing a multicurve in three-dimensional space.
 */
class ExportedBySolverInterface CATCSMultiCurve : public CATCSCurve
{
public:

  struct MultiCurveElement
  {
    enum Type {
      mcLine,
      mcCircle
    };

    Type _type;

    MultiCurveElement(Type iType) : _type(iType){}
    virtual void Evaluate(double iT, double* oaPoint, double* oaFirstDeriv, double* oaSecondDeriv, double* oaThirdDeriv) = 0;
  };

  struct MultiCurveLine : MultiCurveElement
  {
    double _aPoint1[3];
    double _aPoint2[3];

    MultiCurveLine(double iOriginX, double iOriginY, double iOriginZ, double iDestinX, double iDestinY, double iDestinZ) : MultiCurveElement(mcLine)
    {
      _aPoint1[0] = iOriginX;
      _aPoint1[1] = iOriginY;
      _aPoint1[2] = iOriginZ;
      _aPoint2[0] = iDestinX;
      _aPoint2[1] = iDestinY;
      _aPoint2[2] = iDestinZ;
    }
    
void Evaluate(double iT, double* oaPoint, double* oaFirstDeriv, double* oaSecondDeriv, double* oaThirdDeriv) CATCDSOverride;
  };

  struct MultiCurveCircle : MultiCurveElement
  {
    double _center[3];
    double _abscissa[3];
    double _ordinate[3];
    double _radius;
    double _params[2];

    MultiCurveCircle(double iOriginX, double iOriginY, double iOriginZ, double iAbsciX, double iAbsciY, double iAbsciZ, double iOrdX, double iOrdY, double iOrdZ, double iRadius, double iParamBegin, double iParamEnd) : MultiCurveElement(mcCircle), _radius(iRadius)
    {
      _center[0] = iOriginX;
      _center[1] = iOriginY;
      _center[2] = iOriginZ;
      _abscissa[0] = iAbsciX;
      _abscissa[1] = iAbsciY;
      _abscissa[2] = iAbsciZ;
      _ordinate[0] = iOrdX;
      _ordinate[1] = iOrdY;
      _ordinate[2] = iOrdZ;
      _params[0] = iParamBegin;
      _params[1] = iParamEnd;
    }
    void Evaluate(double iT, double* oaPoint, double* oaFirstDeriv, double* oaSecondDeriv, double* oaThirdDeriv) CATCDSOverride;
  };
  /**
   * Constructs an instance of the geometry.
   */
  CATCSMultiCurve();

	CATCSMultiCurve(double iOriginX, double iOriginY, double iOriginZ,
                  double iDestinX, double iDestinY, double iDestinZ);

  CATCSMultiCurve(double iOriginX, double iOriginY, double iOriginZ,
                  double iAbsciX, double iAbsciY, double iAbsciZ,
                  double iOrdX, double iOrdY, double iOrdZ,
                  double iRadius, double iParamBegin, double iParamEnd);

  virtual ~CATCSMultiCurve();

  /**
   * Retrieves type of the geometry.
   * @return
   *   Type of the geometry.
   * @see #IsMatched
   */
  virtual CATCSType GetType() const CATCDSOverride;

  /**
   * Checks whether the geometry is matched to a specific type. The geometry
   * can be casted to a corresponding class if the matching is successful.
   * @param iType
   *   A specific type.
   * @return
   *   <ul>
   *     <li><tt>TRUE</tt> - if the matching is successful,
   *     <li><tt>FALSE</tt> - otherwise.
   *   </ul>
   */
  virtual CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;

  virtual void AddLine(double iOriginX, double iOriginY, double iOriginZ,
                       double iDestinX, double iDestinY, double iDestinZ);

  virtual void AddCircle(double iOriginX, double iOriginY, double iOriginZ,
                         double iAbsciX, double iAbsciY, double iAbsciZ,
                         double iOrdX, double iOrdY, double iOrdZ,
                         double iRadius, double iParamBegin, double iParamEnd);

  CATParamType GetLimits(double& oLow, double& oUp) CATCDSOverride;

  /**
  * Evaluate the curve point or/and derivative at given parameter's value
  * @param iT
  *    Evaluation parameter
  * @param oaPoint
  *    Evaluated coordinates (no evaluation is done if null)
  * @param oaFirstDeriv
  *    Evaluated first derivative (no evaluation is done if null)
  * @param oaSecondDeriv
  *    Evaluated second derivative (no evaluation is done if null)
  * @param oaThirdDeriv
  *    Evaluated third derivative (no evaluation is done if null)
  */
  void Evaluate(double iT,
    double* oaPoint,
    double* oaFirstDeriv,
    double* oaSecondDeriv,
    double* oaThirdDeriv) CATCDSOverride;

private:
  void GlobalToLocalParam(double iGlobalT, double& oLocalT, int& oCurveNumber) const;
  void LocalToGlobalParam(double iLocalT, int iCurveNumber, double& oGlobalT) const;

private:
	int _NbCurves;
  CATCDSArray<MultiCurveElement*> _curveTable; //List of the initial curves
	//CATCrvLimits* _pCurveLimitTable;       //List of the initial CurveLimit
  CATCDSArray<double> _localHighParamTable;   //List of the local high param of every subcurve
  CATCDSArray<double> _localLowParamTable;    //List of the local low param of every subcurve
  CATCDSArray<double> _globalParamTable;
  CATCDSArray<int> _orientationTable; //List of the initial orientation;
};

//-----------------------------------------------------------------------

#endif
