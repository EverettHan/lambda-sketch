//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2017
//-----------------------------------------------------------------------------
// Class  :  	CATVisClippingSphereFilter
// Date   :  	23/10/17
//-----------------------------------------------------------------------------
#ifndef CATVisClippingSphereFilter_H
#define CATVisClippingSphereFilter_H


#include "SGInfra.h"
#include "CATVisFilter.h"
#include "VisClippingDesc.h"


class IVisSGClippingFilter;
class VisSGFilterVisitor;
class CATVisClippingSphereFilter;


class ExportedBySGInfra CATVisClippingSphereFilter : public CATVisFilter
{
  CATDeclareVisFilter(CATVisClippingSphereFilter);

public:
  CATVisDeclarePublicInterfaceAdhesion(CATVisClippingFilter, IVisSGClippingFilter, CATVisClippingFilterIVisSGClippingFilterBOAImpl);
  static CATVisClippingSphereFilter* Create(unsigned int iFlags = VisClippingDesc::fAllowUncutting);
  HRESULT AddClippingSphere(const CATMathPoint& iPosition, float iRadius);
  HRESULT GetClippingSphere(unsigned int iSphereID, CATMathPoint& oPoint, float& oRadius) const;
  HRESULT SetClippingSphere(unsigned int iSphereID, const CATMathPoint& iPoint, float& iRadius);
  unsigned int GetNumClippingSpheres() const;
  unsigned int GetClippingDescFlags() const;
  HRESULT SetClippingDescFlags(unsigned int iFlags);
  virtual void Visit(VisSGFilterVisitor& iVisitor) const;

protected:
  const unsigned int maxClippingSpheres = 6;
  CATVisClippingSphereFilter(unsigned int iFlags);
  virtual ~CATVisClippingSphereFilter();
};
#endif 


