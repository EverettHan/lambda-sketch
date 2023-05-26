// COPYRIGHT Dassault Systemes 2014

#ifndef CATVisColorGradingData_H
#define CATVisColorGradingData_H

#include "SGInfra.h"
#include "CATString.h"
#include "IVisTexturePtr.h"
#include "CATVisColorf.h"

class CATVisParameters;

//-------------------------------------------------------------------------------------
// Tone Mapping

class ExportedBySGInfra CATVisColorGradingData
{
public:
  CATVisColorGradingData();
  virtual ~CATVisColorGradingData();

  enum EType
  {
    eNone,
    eLUT,
    eSMH
  };
};


class ExportedBySGInfra CATVisColorGradingLUTData : public CATVisColorGradingData
{
public:
  CATVisColorGradingLUTData();
  CATVisColorGradingLUTData(const CATVisColorGradingLUTData& iData);
  const CATVisColorGradingLUTData& operator=(const CATVisColorGradingLUTData& iData);
  virtual ~CATVisColorGradingLUTData();
  
  // lookuptTable to transform color
  // Basicaly, it is a (_size*_size, _size) texture (_size Tiles of _size*_size pixels)
  //
  //          B=0                   B=1.f/_size      ...             B=1.f       
  //     R=0 ------> R=1          R=0 ------> R=1    ...         R=0 ------> R=1
  // G=0                      G=0                    ...     G=0                
  // 0                        0                      ...     0                  
  // |                        |                      ...     |                  
  // |                        |                      ...     |                  
  // |                        |                      ...     |                  
  // V                        V                      ...     V                  
  //                                                 ...                        
  // G=1                      G=1                    ...     G=1   
  //
  CATString       _lookupTable;      

  // if _lookupTableIVisTexture is set, then it is used instead of _lookupTable
  IVisTexturePtr  _lookupTableIVisTexture;

  // size of one chanel (Red, Green, or Blue)
  unsigned int  _size;            

  // num of tile (_size,_size) per line
  // By default, this property is set to -1, in this cas all tiles are one line
  int  _numTilePerLine;  

  // Interplation mode for _lookupTable
  // * linear:  values are interpolated by graphic processor when a value is read in the lookuptable
  // * nearest: no interpolation is computed when a value is read
  enum EInterpolationMode
  {
    eLinear = 0,
    eNearest
  };
  EInterpolationMode _interpolationMode;

  // Flag to activate a correction on linear interpolation of LUT texture
  // it modifies sampling to begin at 0.5 pixel and to finish to (size-0.5) pixel
  bool _correctInterpolation;

  // Flag to invert (along Y axis) green and blue chanel in a 2D texture
  // Red chanel stay the same.
  bool _flipY;

  bool operator!=(const CATVisColorGradingLUTData& iData) const;
  bool operator==(const CATVisColorGradingLUTData& iData) const;
};

class ExportedBySGInfra CATVisColorGradingSMHData : public CATVisColorGradingData
{
public:
  CATVisColorGradingSMHData();
  CATVisColorGradingSMHData(const CATVisColorGradingSMHData& iData);
  const CATVisColorGradingSMHData& operator=(const CATVisColorGradingSMHData& iData);
  virtual ~CATVisColorGradingSMHData();

  CATVisColorf _shadows;
  CATVisColorf _midTones;
  CATVisColorf _highlights;

  void SetParameters(const CATVisParameters& iData);
  void GetParameters(CATVisParameters& oData) const;

  bool operator!=(const CATVisColorGradingSMHData& iData) const;
  bool operator==(const CATVisColorGradingSMHData& iData) const;
};

#endif
