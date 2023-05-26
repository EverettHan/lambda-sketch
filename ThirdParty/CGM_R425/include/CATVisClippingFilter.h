#ifndef CATVisClippingFilter_H
#define CATVisClippingFilter_H
//
// CATIA Version 5 Release 15 Framework Visualization
// Copyright Dassault Systemes 2004

#include "SGInfra.h"
#include "CATVisFilter.h"
#include "VisClipPlaneDesc.h"
//++ SGCAAPlan
class IVisSGClippingFilter;
//-- SGCAAPlan

class VisSGFilterVisitor;

class ExportedBySGInfra CATVisClippingFilter : public CATVisFilter
{
  CATDeclareVisFilter(CATVisClippingFilter);

public:
  //++ SGCAAPlan
  CATVisDeclarePublicInterfaceAdhesion(CATVisClippingFilter, IVisSGClippingFilter, CATVisClippingFilterIVisSGClippingFilterBOAImpl);
  //-- SGCAAPlan
/**
   * The defaultFlags is appended to all individual clippingPlaneFlags, it is a convinient way
   * to set multiple flags on a plane.
   * This was added to avoid regression however, because the existing code
   * need not be changed with this addition. Applications will have the option from
   * now on to selectively clip objects based on certain properties of the object.
   * By default all objects are clipped by clipping filter.
   * check @VisClipPlaneDesc for more information.
   */
  static CATVisClippingFilter* Create(const int nb_planes, const float *point, const float *normal,
    const int *cappingPlaneFlags, const int *sectionningGenerated = NULL,
    unsigned int defaultFlags = VisClipPlaneDesc::fDefaultOnFlags);

  void SetClippingPlane(const int nb_planes, const float *point, const float *normal,
    const int *CappingPlaneFlags,
    const int *sectionningGenerated = NULL,
    unsigned int defaultFlags = VisClipPlaneDesc::fDefaultOnFlags);

  void GetClippingPlane(int **nb_planes, float **point, float **normal, int **CappingPlaneFlags,
    int **sectionningGenerated = NULL);

  virtual void Visit(VisSGFilterVisitor& iVisitor) const;

  virtual unsigned char GetType() const;

  //D6F IR-743589 Option for picking of capping ++
  void ActivateCappingPicking();
  void DeactivateCappingPicking();
  bool IsCappingPickingActivated() const;
  //D6F IR-743589 Option for picking of capping --

  // FUN099945 Picking of Section Profile ++
  void ActivateContourPicking();
  void DeactivateContourPicking();
  bool IsContourPickingActivated() const;
  // FUN099945 Picking of Section Profile --
protected:
  CATVisClippingFilter(const int nb_planes, const float *point, const float *normal, const int *CappingPlaneSeen, const int *sectionningGenerated = NULL, unsigned int defFlags = VisClipPlaneDesc::fDefaultOnFlags);
  virtual ~CATVisClippingFilter();
};
#endif 


