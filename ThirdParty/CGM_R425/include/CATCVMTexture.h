#ifndef CATCVMTexture_h
#define CATCVMTexture_h

#include "CATCVMAttribute.h"
#include "CATCVMTextureRef.h"
#include "CATCVMGeoObjects.h"
#include "CATCVMSysStream.h"
#include "CATMathTransformation.h"
#include "CATMathTransformation2D.h"
#include "CATMathPoint2D.h"
#include "CATUnicodeString.h"
#include "CATCGMNewArray.h"

class CATMathTransformation2D;
class CATCVMImage;
class CATCVMTextureSkewData;
class CATCVMTransfoUV;

class ExportedByCATCVMGeoObjects CATCVMTexture : public CATCVMAttribute
{
public:
  CATCVMTexture (CATCVMObject * iOwner, CATCVMTextureRef * iTextureRef = NULL);
  CATCGMNewClassArrayDeclare; // Pool allocation
  virtual ~CATCVMTexture();

  // Get/Set divers
  CATCVMTextureRef * GetTextureRef();
  HRESULT SetTextureRef(CATCVMTextureRef * iTextureRef);

  //------------------------------------------------------------------------------
  // Be carefull : Two mapping are managed : 
  //     projective 3D and mapping UV 
  //------------------------------------------------------------------------------
  HRESULT GetTextureAxis (double oCoord[12], CATBoolean iForceOriginalTexture=FALSE) const ;
  HRESULT SetTextureAxis (double iCoord[12]) ;

  HRESULT RightMultiply (const CATMathTransformation2D & iTransfo );

  HRESULT GetScale (double &oScale) const ;
  HRESULT SetScale (double iScale) ;

  HRESULT GetRatio (double &oRatio) const ;
  HRESULT SetRatio (double iRatio) ;

  HRESULT GetRepeat (unsigned char &oU, unsigned char &oV) const ;
  HRESULT SetRepeat (unsigned char iU, unsigned char iV) ;

  HRESULT GetOrientation (CATAngle &oOrientation) const ;
  HRESULT SetOrientation (CATAngle iOrientation) ;

  HRESULT GetUseTexture (unsigned char &oTexture) const ;
  HRESULT SetUseTexture (unsigned char iTexture) ;

  // Pour positionnement absolu de la texture
  HRESULT UpdateTransfo (const CATMathTransformation& iTransfo );
  CATMathTransformation GetAbsTransfo() const;

  // Skewed image
  CATCVMImage * GetSkewedImage () const;
  HRESULT SetSkewedImage (CATCVMImage * iSkewedImage, CATBoolean Replace=FALSE); // replace is not allowed by default
  HRESULT GetSourceSkewPoints (CATMathPoint2D oSourcePoints[4]) const ;
  HRESULT SetSourceSkewPoints (CATMathPoint2D iSourcePoints[4]);
  HRESULT GetDestinationSkewPoints (CATMathPoint2D oDestinationPoints[4]) const ;
  HRESULT SetDestinationSkewPoints (CATMathPoint2D iDestinationPoints[4]);

  HRESULT SetSkewImageTransfo(const CATMathTransformation2D & iTransfo2D);  // PKC ++
  HRESULT GetSkewImageTransfo(CATMathTransformation2D & oTransfo2D) const;  // PKC ++
  HRESULT SetSkewHomoGraphicTransfoData(const CATMath3x3Matrix &iMatrix);
  HRESULT GetSkewHomoGraphicTransfoData(CATMath3x3Matrix& oMatrix);

  // to delete very soon PKC
  HRESULT SetSkewHomoGraphicTransfoData(const CATMath3x3Matrix &iMatrix, const CATMathVector& iVector);

  // Stream/Unstream
  void Stream(CATCVMSysStream * iStream);
  void Unstream(CATCVMSysStream * iStream); 

  //------------------------------------------------------------------------------
  // Integration UV Mapping (equivalent to Transfo2 TransfoUV)
  //------------------------------------------------------------------------------
  HRESULT    GetTransfoUV(CATMathTransformation2D & oTransfo2D) const;  
 
  // Copy
  CATCVMAttribute * CopyCVMAttribute(CATCVMObject * iOwner);

  // Inits des donnees de la texture
  static void InitAxis(double * TextureAxis);
  static void InitScale(double & Scale);
  static void InitOrientation(CATAngle & Orientation);
  static void InitUseTexture(unsigned char & UseTexture);
  static void InitRepeat(unsigned char & URepeat, unsigned char & VRepeat);

  // Init des données de Skewed image
  static void InitSkewPoints(CATMathPoint2D * Points);

public:
  void RemoveSkewedImage();

private:

  void       UnsetManagedByTransfoUV();
  HRESULT    InitializeTransfoUV(const CATMathTransformation2D & iTransfo2D);   
  HRESULT    UnsetTransfoUVUpdated();  


  //CATCVMTexture(CATCVMTexture&);
  //void operator =(CATCVMTexture&);
  double _TextureAxis[12];
  double _Scale;
//  double _Ratio;
  unsigned char _URepeat, _VRepeat;
  CATAngle _Orientation;
  CATMathTransformation _AbsTransfo;


  //  For UV Mapping 
  CATMathTransformation2D  _TransfoUV;

  // _IsManagedByTransfoUV : TRUE : gestion par mapping UV
  CATBoolean               _IsManagedByTransfoUV;

  // _IsTransfoUVUpdated : TRUE : need an update (Inputs of computation have changed) 
  CATBoolean               _IsTransfoUVUpdated;

  // _IsTransfoUVFromTextureAxis  : TRUE : value is directly managed from Texture Axis
  CATBoolean               _IsTransfoUVFromTextureAxis;


private:
    /*
  CATCVMImage * _SkewedImage;
  CATMathPoint2D _SourceSkewPoints[4];
  CATMathPoint2D _DestinationSkewPoints[4];
  CATMathTransformation2D _SkewImageTransfo;   // ajout PKC
  CATMath3x3Matrix _SkewHomographicTransfoMatrix;
  */
    CATBoolean _HasBeenSkewed;
    CATCVMTextureSkewData * _SkewData;


  friend class CATCVMTransfoUV;

};
#endif

