// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCSSkinParam.h
// Header definition of CATCSSkinParam
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jul 2005  Creation                    Andrey CHUGUEV
//===================================================================

#ifndef CATCSSkinParam_H
#define CATCSSkinParam_H

#include <cstddef> 
#include "CATCDS.h"
#include "CATCDSBoolean.h"
#include "CATCDSAdvancedEnums.h"
#include "CATCDSInline.h"

class CATCSSkin;
class CATCDSCache;

//-----------------------------------------------------------------------

class ExportedBySolverInterface CATCSSkinParam
{
public:
  CATCSSkinParam(const CATCSSkinParam& iParam);
  virtual ~CATCSSkinParam();

  virtual void CopyFrom(const CATCSSkinParam* ipPointOnSkin);
  virtual CATCSSkinParam* Clone() const;

  virtual CATCSSkin* GetSkin() const;

  virtual CATCSParamType GetParamType() = 0;

  virtual CATCDSBoolean IsParamOnWire() = 0;

  virtual CATCDSBoolean IsParamOnVertex() = 0;

  virtual CATCDSBoolean IsParamOnBorder() = 0;

  virtual int GetInformationOnVertex(int& oNbOfWires, int& oNbOfFaces) = 0;

  virtual int GetNextParamOnWire(CATCSSkinParam* opPointOnSkin) = 0;

  virtual int GetNextParamOnFace(CATCSSkinParam* opPointOnSkin) = 0;

  virtual int GetNextParamOnVertex(CATCSSkinParam* opPointOnSkin) = 0;

  virtual CATCSContinuity GetContinuity() = 0;

  void SetCache(CATCDSCache* ipCache);

  CATCDSInline void SetUserObj(void *iPtr);
  
  CATCDSInline void *GetUserObj() const;

  /* for internal use */
  virtual void Stream(char *& oStreamData, size_t & oLength);

protected:
  CATCSSkinParam(CATCSSkin* ipSkin);

  CATCSSkin* _pSkin;
  CATCDSCache* _pCache;
  void *_pUserObj;
    
private:
  void operator=(const CATCSSkinParam&);
};

CATCDSInline void CATCSSkinParam::SetUserObj(void *iPtr) {
  _pUserObj = iPtr;}
  
CATCDSInline void *CATCSSkinParam::GetUserObj() const {
  return _pUserObj;}

//-----------------------------------------------------------------------

#endif
