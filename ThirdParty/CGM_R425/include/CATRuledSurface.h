/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
// CATRuledSurface Interface
//-----------------------------------------------------------------------------
// Jul. 97   Creation                                     S. Royer
// Dec. 97   Documentation                                C. Keribin
//=============================================================================
//
// Usage notes:
//
//=============================================================================
#ifndef CATRuledSurface_h
#define CATRuledSurface_h
/**
 * Interface representing a ruled surface.
 *<br> The CATRuledSurface is created by the <tt>CreateRuledSurface</tt>
 * method of the <tt>CATGeoFactory</tt> interface. 
 *<br>A CATRuledSurface is the surface generated by a cone sliding on a
 * profile.
 * It is defined with:
 *<table>
 * <tr><td>CATCurve</td><td><tt> Profile </tt></td>
 *                <td> The profile on which the cone slides (first direction) </td></tr>
 * <tr><td>CATMathDirection</td><td><tt> Direction </tt></td>
 *                <td> The cone direction </td></tr>
 * <tr><td>CATAngle</td><td><tt> Angle </tt></td>
 *                <td> The angle between the direction and the draft surface
 *                      normal.</td></tr>
 * <tr><td>double</td><td><tt> StartLength </tt></td>
 *                 <td>The low limitation in the second direction</td></tr>
 * <tr><td>double</td><td><tt> EndLength </tt></td>
 *                 <td>The high limitation in the second direction</td></tr>
 *</table>
 *Note that <tt>StartLength < EndLength </tt> and may be negative.
 */

#include "CATSurface.h"

class CATCurve;
class CATGeoFactory;

#include "ExportedByCATGMGeometricInterfaces.h"
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATGMGeometricInterfaces IID IID_CATRuledSurface ;
#else
extern "C" const IID IID_CATRuledSurface ;
#endif

class ExportedByCATGMGeometricInterfaces CATRuledSurface : public CATSurface
{
  CATDeclareInterface;

 public:
/**
 * Creates the isoparametric profiles on which the CATRuledSurface lays.
 * @param oStartProfile
 * The pointer to the isoparametric curve of
 * <tt>V = oStartInitLength</tt>
 * @param oStartInitLength
 * The low limitation on the rule direction at the CATRuledSurface creation.
 * @param oEndProfile
 * The pointer to the isoparametric curve of
 * <tt>V = oEndInitLength</tt>
 * @param ondInitLength
 * The high limitation on the rule direction at the CATRuledSurface creation.
 */
  virtual void CreateProfiles(CATGeoFactory * iWhere,
			      CATCurve * & oStartProfile,
			      double & oStartInitLength,
			      CATCurve * & oEndProfile,
			      double & oEndInitLength) const=0;

};
  CATDeclareHandler(CATRuledSurface, CATSurface);

#endif