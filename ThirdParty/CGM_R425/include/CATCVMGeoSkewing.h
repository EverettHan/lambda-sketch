/* -*-C++-*- */

#ifndef CATCVMGeoSkewing_H
#define CATCVMGeoSkewing_H

// COPYRIGHT DASSAULT SYSTEMES 2007

//===================================================================
//===================================================================
//
// CATCVMGeoSkewing
//
// creation (dec 2007):                                             KJD
// revue + Matrice3x3 + convergence first shot (jan 2008)           PKC
// ajout ComputeGlobalImage + amelioration perfo                    KJD
//===================================================================

#include "CATCVMGeoOperators.h"
#include "CATCVMSysOperator.h"
#include "CATBoolean.h"
#include "CATMathPoint2D.h"
#include "CATMathBox2D.h"
#include "CATMathTransformation2D.h"
#include "CATMathDiagnostic.h"
#include "CATMath3x3Matrix.h"
#include "CATMathVector.h"

class CATCVMGeoContainer;
class CATMathNxNMatrix;
class CATCVMTexture;
class CATCVMInstancePath;

class ExportedByCATCVMGeoOperators CATCVMGeoSkewing : public CATCVMSysOperator
{
public:
  static CATCVMGeoSkewing *Create(CATCVMGeoContainer *iCVMGeoContainer);
  static CATCVMGeoSkewing *Create(CATCVMInstancePath *iCVMInstancePath);

  //------------------------------------------------------------------------------
  // Constructor, copy constructor and = operator
  //------------------------------------------------------------------------------
protected:
  CATCVMGeoSkewing(CATCVMGeoContainer *iCVMGeoContainer);
  CATCVMGeoSkewing();

private:
  CATCVMGeoSkewing(const CATCVMGeoSkewing &);//Necessary to prevent unwanted automatic creation by compiler
  void operator = (const CATCVMGeoSkewing &);

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
public:
  virtual ~CATCVMGeoSkewing();

public:
  // provide to the operator initial 4 points and final 4 points
  // points coordinates are defined on current texture coordinates
  void SetPoints(CATMathPoint2D iSourcePoints[4], CATMathPoint2D iTargetPoints[4]);

  //
  void SetBoundingBox(CATMathBox2D & iSourceBoundingBox,CATMathBox2D & iTargetBoundingBox);
  
  // Bounding Box of Face suppport of texture
  // given on current texture coordinates
  void SetFaceBoundingBox(CATMathBox2D & iFaceBoundingBox);
  
  // provide inflate ratio that will be applied on each direction of FaceBoundingBox (given through SetFaceBoundingBox) 
  // to obtain definition domain of skewing result 
  // this domain will be the new "period" of the result texture  
  void SetFaceBoundingBoxExpandRatio(double iRatio);   
  
  // provide pointer on CVMTexture to skew (CVMTexture contains informations of previous skew transformations) 
  void SetCVMTexture(CATCVMTexture* iCVMTexture);

public:
  void Run();

public:
  //kjd 07APR2008 : 
 //Compute image for all points
  // ref =image de refernce et Skw=Nouvelle image
 // ixxxWidth (resp. ixxxHeight) = nb pixel selon 1ere direction (resp. seconde)
  //ixxxPixelData : adresse du 1er pixel de l'image
  //ixxxBytesPerPixel : taille memoire d'un pixel
  void ComputeWholeImage( const int& iRefWidth, const int& iRefHeight, unsigned char* iRefPixelData, const int& iRefBytesPerPixel, const int& iSkwWidth, const int& iSkwHeight, unsigned char* ioSkwPixelData, const int& iSkwBytesPerPixel );
  
  // Convention : iInverseTransfo=1 (si iPoint est un point dans le domaine cible, iInverseTransfo=0 sinon
  CATBoolean ComputeImage(CATMathPoint2D & iPoint, CATBoolean iInverseTransfo, CATMathPoint2D & oPoint);

  // Get inverse Target Transfo 
  void GetTransfo2D(CATMathTransformation2D & oTransfo2D);

private:
  CATBoolean ComputeVirtualImage(CATMathPoint2D & iPoint, CATBoolean iInverseTransfo, CATMathPoint2D & oPoint);
  
  // PKC ++ 
  CATBoolean ComputeInverseVirtualImage(CATMathPoint2D & iPoint, const CATMath3x3Matrix &iMatrix, const CATMathVector &iVector, CATMathPoint2D & oPoint);
  CATBoolean ComputeDirectVirtualImage(CATMathPoint2D & iPoint, const CATMath3x3Matrix &iMatrix, const CATMathVector &iVector, CATMathPoint2D & oPoint);

  void ComputeHomographicMatrix(CATMathPoint2D iAntecedent[4], CATMathPoint2D iImage[4], CATMath3x3Matrix & oTransfoMatrix); 
  void ComputeCoeffForHomographicScalar(); 
  void ComputeCoeffForInverseOfHomographicScalar(); 
  CATMathDiagnostic ComputeSourceTransfo();
  void ComputeTargetTransfo();
 
  // PKC 16/01/2008
  // as its name says : compute linear 2D transformation that tranforms iInitBox into iFinalBox
  // internal service for ComputeTargetTransfo
  void ComputeTransfoBetweenBoxes(CATMathBox2D &iInitBox, CATMathBox2D &iFinalBox, CATMathTransformation2D & oTransfo2D);
  
  // Expand box with iRatio in each direction
  void ExpandBox(CATMathBox2D& ioBox, double iRatio);
  
  // first step of run update input points and boxes to be able to compute transformation from initial picture
  // idea is to forget previous skewing steps to insure best quality of result
  void InitializeDataAccordingToPreviousSkewing();


// PRIVATE DATA
private:
  CATCVMTexture* _CVMTexture;
  CATMathBox2D  _FaceBoundingBox;
  CATMathBox2D  _SourceBoundingBox;
  CATMathBox2D  _TargetBoundingBox;
  CATMathPoint2D _SourcePoints[4];
  CATMathPoint2D _TargetPoints[4];  
  CATMathPoint2D _VirtualSourcePoints[4];
  CATMathPoint2D _VirtualTargetPoints[4];

  CATMath3x3Matrix _HomographicMatrix;
  CATMath3x3Matrix _InverseHomographicMatrix;
  CATMathVector _HomoGraphicScalar;   // third raw of _HomographicMatrix
  CATMathVector _InverseHomoGraphicScalar; // third raw of _InverseHomoGraphicScalar

  CATMathTransformation2D _Transfo;
  CATMathTransformation2D _SourceTransfo;
  CATMathTransformation2D _TargetTransfo;

  double _FaceBBExpandRatio; // expand ratio of _FaceBoundingBox, by default 0.2 

};
#endif
