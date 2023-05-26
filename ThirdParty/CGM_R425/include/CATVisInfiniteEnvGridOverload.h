// COPYRIGHT Dassault Systemes 2007

#ifndef CATVisInfiniteEnvGridOverload_H
#define CATVisInfiniteEnvGridOverload_H

//-----------------------------------------------------------------------

#include "CATVisFoundation.h"
#include "CATVisInfiniteEnvironmentOverload.h"
#include "CATVisColor.h"
#include "CATMathPointf.h"
#include "CATMathDirectionf.h"
#include "CATMathVector2Df.h"

class ExportedByCATVisFoundation CATVisInfiniteEnvGridOverload : public CATVisInfiniteEnvironmentOverload
{
public:
  static CATVisInfiniteEnvGridOverload* Create(
                                 const CATMathPointf&     iOrigin, 
                                 const CATMathDirectionf& iNormal,
                                 const CATMathDirectionf& iDirection,
                                 float                    iRadius,
                                 unsigned int             iKeepInitialGround=1);

  void SetAutomaticMode         (unsigned int iOnOff);

  void SetPosition              (const CATMathPointf&     iOrigin, 
                                 const CATMathDirectionf& iNormal,
                                 const CATMathDirectionf& iDirection,
                                 float                    iRadius);

  void SetOrigin                (const CATMathPointf&     iOrigin);
  void SetNormal                (const CATMathDirectionf& iNormal);
  void SetDirection             (const CATMathDirectionf& iDirection);
  void SetDeltaPosition         (const CATMathVector2Df&  iDeltaPosition);
  void SetRadius                (float iRadius);
  void SetRadiusRatio           (float iRatio);

  void SetFaddingStrength       (unsigned int             iFaddingStrength);
  void RestoreFaddingStrenght   ();
  void SetRadialFadding         (unsigned int             iRatio);
  void RestoreRadialFadding     ();
  

  void SetGridStepNum           (unsigned int             iGridNum,
                                 unsigned int             iSubGridNum);
  void SetGridStepSize          (float                    iGridStepSize,
                                 unsigned int             iSubGridNum);
  void RestoreGridNum           ();

  // Cette fonction modifie le ground de l'environement
  // sauf si l'on a surcharge la position et demande de garder
  // le background initial
  // Dans ce cas la, ces fonctions modifies la couleur du ground lie a la grille
  // Le ground initial conserve ses proprpietes
  void SetGroundActivation      (unsigned int             iActivation,
                                 unsigned int             iFrontMeshMode=1);
  void RestoreGroundActivation  ();

  void SetColor                 (const CATVisColor&       iGridColor, 
                                 const CATVisColor&       iSubGridColor,
                                 const CATVisColor&       iGroundColor);
  void RestoreColor             ();
  void SetWidth                 (unsigned int             iGridWidth, 
                                 unsigned int             iSubGridWidth);
  void RestoreWidth             ();
  void SetLineType              (unsigned int             iGridLineType, 
                                 unsigned int             iSubGridLineType);
  void RestoreLineType          ();

protected:
  virtual void Overload(CATVisInfiniteEnvironmentExtendedData& ioData) const;

private:
  CATVisInfiniteEnvGridOverload(unsigned int iKeepInitialGround);
  virtual ~CATVisInfiniteEnvGridOverload();

  // general
  CATMathPointf     _origin;
  CATMathDirectionf _normal;
  CATMathDirectionf _direction;
  CATMathVector2Df  _deltaPosition;
  float             _radius;
  float             _radiusRatio;
  unsigned int      _automaticMode          : 2;
  unsigned int      _fadingStrength         : 4;
  unsigned int      _radialRatioFading      : 7;
  unsigned int      _keepInitialGround      : 1;
  //unsigned int      _clippingActivation     : 1;

  // grid
  unsigned int      _gridNumMode            : 1;
  unsigned int      _gridNum                : 12;
  unsigned int      _subGridNum             : 12; 
  unsigned int      _gridWidth              : 8;
  unsigned int      _subGridWidth           : 8;
  unsigned int      _gridLineType           : 8;
  unsigned int      _subGridLineType        : 8;
  float             _gridStepSize;
  CATVisColor       _gridCol;   
  CATVisColor       _subGridCol;

  // ground
  CATVisColor       _groundCol;
  unsigned int      _groundActivation       : 1;
  unsigned int      _groundFrontMeshMode    : 1;


  // Flag de Set
  unsigned int      _fadingStrengthFlag     : 1;
  unsigned int      _radialRatioFadingFlag  : 1;
  //unsigned int      _clippingActivationFlag : 1;

  unsigned int      _gridNumFlag            : 1;
  unsigned int      _groundActivationFlag   : 1;

  unsigned int      _colFlag                : 1;
  unsigned int      _lineTypeFlag           : 1;
  unsigned int      _widthFlag              : 1;

public:
  // obsolete    
  void SetClippingMode          (unsigned int             iOnOff);
  // obsolete
  void RestoreClippingMode      ();
};

//-----------------------------------------------------------------------

#endif
