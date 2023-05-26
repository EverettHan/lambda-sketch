#ifndef CATVisuTextureData_H
#define CATVisuTextureData_H

#include "CATVizBaseIUnknown.h"

#include "SGInfra.h"

enum CATTextureFormat {
  VIS_RED=0, 
  VIS_GREEN, 
  VIS_BLUE, 
  VIS_ALPHA, 
  VIS_RGB, 
  VIS_RGBA, 
  VIS_LUMINANCE, 
  VIS_INTENSITY, 
  VIS_LUMINANCE_ALPHA, 
  VIS_DEPTH,
  VIS_DEPTH_STENCIL
};


class ExportedBySGInfra CATVisuTextureData : public CATVizBaseIUnknown
{
public :

  //On met cela ici pour ne pas faire doublon avec VisDataType.
  //On ne peut plus utiliser VisDataType a cause de VIS_UNSIGNED_INT_24_8, qui n'a pas lieu d'etre dans VisDataType
  enum CATTextureType 
  {
    VIS_UNSIGNED_CHAR,
    VIS_CHAR,
    VIS_UNSIGNED_SHORT,
    VIS_SHORT,
    VIS_UNSIGNED_INT,
    VIS_INT,
    VIS_FLOAT,
    VIS_UNSIGNED_INT_24_8
  };



public:
  static CATVisuTextureData* Create(int i_width, int i_height, 
                                    CATTextureFormat iFormat, 
                                    CATTextureType iType=VIS_UNSIGNED_CHAR,
                                    int iCubeMapMode=0);

  //-------------------------------------
  // Dimension / Parametres

  inline int              GetWidth()  const;
  inline int              GetHeight() const;
  inline CATTextureFormat GetFormat() const;
  inline CATTextureType   GetType()   const;
  inline int              IsCubeMapMode() const;

  void*                   GetBuffer(unsigned int iID=0);

  unsigned int            GetPicSize() const;
  unsigned int            GetSize() const;
  unsigned int            GetTypeSize() const;
  unsigned int            GetFormatSize() const;


 private:
  CATVisuTextureData(int i_width, int i_height, 
                     CATTextureFormat i_format, 
                     CATTextureType iType,
                     int iCubeMapMode);
  CATVisuTextureData(const CATVisuTextureData & i_texture){};
  virtual ~CATVisuTextureData();


  int                       _width;
  int                       _height;
  CATTextureFormat          _dataFormat;
  CATTextureType            _dataType;
  unsigned char*            _data;
  int                       _cubeMapMode;
};

inline int CATVisuTextureData::GetWidth() const
{
  return _width;
}

inline int CATVisuTextureData::GetHeight() const
{
  return _height;
}

inline CATTextureFormat CATVisuTextureData::GetFormat() const
{
  return _dataFormat;
}

inline CATVisuTextureData::CATTextureType CATVisuTextureData::GetType() const
{
  return _dataType;
}

inline int CATVisuTextureData::IsCubeMapMode() const
{
  return _cubeMapMode;
}

#endif // CATVisuTextureData_H
