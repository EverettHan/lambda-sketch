#ifndef CATMMRASTERSERVICES_H
#define CATMMRASTERSERVICES_H

#include "CATBaseUnknown.h"
#include "CATMMPITypeDesc.h"
#include "CATMMPIPixelColorSpec.h"


#define MAX_TAB_SIZE 16

enum SpecificChannelValues {
  scv_DftA = -3, //Default alpha value
  scv_DftC = -2, //Default color value
  scv_NDef = -1  //Not defined
};

  template <class cDst, class cSrc>
using typCvr = void(*)(void*, const void*, int);

template <typename dstType> struct CATMMPIDefaultValues {
  static dstType GetDefaultAlpha() { dstType val = 0; return val; };
  static dstType GetDefaultColor() { dstType val = 0; return val; };
};

template <> struct CATMMPIDefaultValues<uchar> {
  static uchar   GetDefaultAlpha() { uchar val = 0xFF; /* 0x00 (0)=transparent, 0xFF (255)=opaque.*/ return val; };
  static uchar   GetDefaultColor() { uchar val=0x00; /* 0x00 (0)=black      , 0xFF (255)=white. */ return val; };
};

  template <class cDst, class cSrc>
void Convert(void* oVal, const void* iVal, int iDefault) {
  if(!oVal)
    return;
  if(!iVal)
  {
    if(iDefault==scv_DftA)
      ((cDst*)oVal)[0]= CATMMPIDefaultValues<cDst>::GetDefaultAlpha();
    else if(iDefault==scv_DftC) 
      ((cDst*)oVal)[0]= CATMMPIDefaultValues<cDst>::GetDefaultColor();
    return; 
  }
  cSrc val=*((cSrc*)iVal);
  ((cDst*)oVal)[0]=val;
  return;
};

/**
 * CATMMPIChannelsIndex is a service to compute the shift on the pointer for next channel.
 */
class CATMMPIChannelsShift
{
public:
  CATMMPIChannelsShift()                                                { Reset(_b); Reset(_B); };
  CATMMPIChannelsShift(const CATMMPIPixelColorSpec* ipPCS)              { SetPixelColorSpec(ipPCS); };
  ~CATMMPIChannelsShift()                                               {};
  static void Reset(int tab[MAX_TAB_SIZE])                              {
    for(int i=0;i<MAX_TAB_SIZE;i++)
      tab[i]=0;}
  bool SetPixelColorSpec(const CATMMPIPixelColorSpec* ipPCS)            {
    Reset(_b);
    Reset(_B);
    if(!ipPCS)return 0;
    const CATMMPITypeDesc* pTD=ipPCS->HomogeneousFormats();
    if(!pTD)return 0;
    _b[0]=_B[0]=ipPCS->ChannelsGetNB();
    for(int i=_b[0]; i>0; i--)
    {
      _b[i] = pTD->_nBits;
      if(i<15)
        _b[i]+=_b[i+1];
      _B[i]=_b[i] / 8;
    }
    return 1;
  };
  bool IsByteAligned()                                                  {
    if(_b[0]==0||_B[0]==0||_b[0]!=_B[0])return 0;
    for(int i=_b[0];i>0;i--)
    {
      if(_b[i]%8>0||_B[i]!=(_b[i]/8))
        return 0;
    }
    return 1;
  };
  bool IsHomogeneous()/*On bits*/                                       {
    if(_b[0]==0 || _B[0]==0 || _b[0]!=_B[0])return 0;
    if(_b[0]==1)return 1;
    int b=_b[1];
    int B=_B[1];
    for(int i=_b[0]-1; i>0; i--)
    { if(_b[i]%_b[_b[0]]>0) return 0; }
    return 1;
  };
  
  //                                   ____________________ n: Channels count
  //                                  |     _______________ S: Size in bits/bytes of a pixel (so give the shift for next pixel).
  //                                  |    |      _________ Position of n-1 channel
  //                                  |    |     |    _____ Position of n-2 channel
  //                                  |    |     |   |      ...
  int _b[MAX_TAB_SIZE];// in bits : [ 3 , 24 , 16 ,  8 ,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 ]
  int _B[MAX_TAB_SIZE];// in bytes: [ 3 ,  3 ,  2 ,  1 ,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 ]
};

/**
 * Store:
 * - the shifts to apply on input pixel
 * - the shifts to apply on output pixel
 * - the mapping of the output channel form an inupt channel
 * Those data are provided to the pixel converter function.
 */
class CATPixelConverterParameters
{
public:
  CATPixelConverterParameters()                                         { CATMMPIChannelsShift::Reset(_oB); CATMMPIChannelsShift::Reset(_iB); CATMMPIChannelsShift::Reset(_map); };
  ~CATPixelConverterParameters()                                        {};
  bool IsValid()                                                        {if(_iB[0]==0||_oB[0]==0||_map[0]==0)return 0; return 1;};
  void Seti(const int* iSrc)                                            {Set(_iB ,iSrc);};
  void Seto(const int* iDst)                                            {Set(_oB ,iDst);};
  void Setm(const int* iMap)                                            {Set(_map,iMap);};
  int  Geti(const int idx)                                              {if(_iB[0]<1||idx<0||idx>=_iB[0]||idx>=MAX_TAB_SIZE)return -1;return _iB[_iB[0]+1-idx]; }
  int  Geto(const int idx)                                              {if(_oB[0]<1||idx<0||idx>=_oB[0]||idx>=MAX_TAB_SIZE)return -1;return _oB[_oB[0]+1-idx]; }

  static void Set(int* iDst,const int* iSrc)                            { if(!iSrc||!iDst)return;CATMMPIChannelsShift::Reset(iDst);
                                                                          for(int i=0; i<MAX_TAB_SIZE; i++)
                                                                          {
                                                                            if(i<=iSrc[0])
                                                                              iDst[i]=iSrc[i];
                                                                            else iDst[i]=0;
                                                                          }
                                                                        };

  int _oB [MAX_TAB_SIZE];
  int _iB [MAX_TAB_SIZE];
  int _map[MAX_TAB_SIZE];//Get channel index of input pixel color from channel index for output color
};

  template <class cDst, class cSrc>
int ConvertPixel(void* oPixelVal, const void* iPixelVal, CATPixelConverterParameters& iPrm)
{
  if( !oPixelVal || !iPrm.IsValid() )
    return -1;
//const cSrc* iVals = (const cSrc*)iPixelVal;
//cDst* oVals = (cDst*)oPixelVal;
  for(int i=0; i<iPrm._oB[0]; i++)
  {
    const void* ptrIN = static_cast<const char*>(iPixelVal) + iPrm.Geti(iPrm._map[i+1]);
    void*       ptrOUT= static_cast<      char*>(oPixelVal) + iPrm.Geto(i);
//  ptrIN += ;
//  ptrOUT+= ;
    if(ptrIN && 0<=iPrm._map[i+1] && iPrm._map[i+1]<iPrm._iB[0])
      Convert<cDst, cSrc>(ptrOUT, ptrIN, iPrm._map[i+1]);
    else                   
      Convert<cDst, cSrc>(ptrOUT, NULL , iPrm._map[i+1]);
  }
  return 1;
}



class CATMMRasterServices : public CATBaseUnknown
{
public:
  CATMMRasterServices() {};
  virtual ~CATMMRasterServices() {};

  virtual bool GetConverter(FuncPixelConverter &oPixelConverter, TypeConverter &oTypeConverter, CATMMPITypeDesc oType, CATMMPITypeDesc iType) = 0;
};


#endif
