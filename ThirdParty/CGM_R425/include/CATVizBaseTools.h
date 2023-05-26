// COPYRIGHT DASSAULT SYSTEMES 1999

#ifndef CATVizBaseTools_H
#define CATVizBaseTools_H

#include "SGInfra.h"
#include "CAT3DBagRep.h"
#include "CAT2DBagRep.h"
#include "CAT3DRep.h"
#include "CAT2DRep.h"
#include "CATRep.h"
#include "CAT3DBoundingSphere.h"
#include "CAT2DBoundingBox.h"

#include "CATReadWriteCgr.h"

#include "CATErrorDef.h" // pour le HRESULT

#include "CATIAV5Level.h" 

#include "IUnknown.h"    
#include <sys/types.h>

// System FW
#include "CATWTypes.h"
#include "DSYSysIsPointerNull.h"

class CATRender;

#define EPSILON_ABS_F0R_2DMODE 0.005f

#define REMOVE_FIXED_SIZE (1<<1)

#define REMOVE_EMPTY (1<<2)

#define REMOVE_INFINITE (1<<3)

#define REMOVE_CATAFR3DCOMPASSBAGREP (1<<4)

#define REMOVE_CATLIVESHAPEREFERENT3DBAGREP (1<<5)

// Function that gives an unicode string's length
#ifndef DSwcslen
#ifdef _WINDOWS_SOURCE
#define DSwcslen wcslen
#else
static size_t DSwcslen(const WCHAR * s)
{
  size_t n;
  for (n = 0; *s != (WCHAR)0; s++)
    n++;
  return n;
}
#endif
#endif

class CATMathVectorf;
class CATMathPointf;
class CATMathPoint2Df;
class CATMathDirectionf;
class CAT4x4Matrix;
class CAT3DRep;
class CATRep;
class CATViewer;
class CATVizViewer;
class CATSupport;
class CAT3DBoundingGP;
class CAT3DViewpoint;
class CATCgrHeader;
class CAT3DFaceGP;
class CATMathVector;
class CATMathDirectionf;
class CATMathPointf;
class CATMathPoint;
class CATMathDirection;

extern int ExportedBySGInfra IsSameDirectionVector(const CATMathVectorf& iU, const CATMathVectorf& iV, const float& iAngleResolution);
extern int ExportedBySGInfra IsSameDirectionVector(const CATMathVectorf& iU, const CATMathVectorf& iV, const float& iAngleResolution, CATMathVectorf& oVectorialProduct);
extern int ExportedBySGInfra IsColinearVector(const CATMathVectorf& iU, const CATMathVectorf& iV, const float& iAngleResolution);
extern int ExportedBySGInfra IsColinearVector(const CATMathVectorf& iU, const CATMathVectorf& iV, const float& iAngleResolution, CATMathVectorf& oVectorialProduct);
extern int ExportedBySGInfra IsOrthogonalVector(const CATMathVectorf& iU, const CATMathVectorf& iV, const float& iAngleResolution);
extern int ExportedBySGInfra IsOrthogonalVector(const CATMathVectorf& iU, const CATMathVectorf& iV, const float& iAngleResolution, float& oScalarProduct);
extern int ExportedBySGInfra IsSameDirection(const CATMathDirectionf& iU, const CATMathDirectionf& iV, const float& iAngleResolution);
extern int ExportedBySGInfra IsSameDirection(const CATMathDirectionf& iU, const CATMathDirectionf& iV, const float& iAngleResolution, CATMathVectorf& oVectorialProduct);
extern int ExportedBySGInfra IsColinearDirection(const CATMathDirectionf& iU, const CATMathDirectionf& iV, const float& iAngleResolution);
extern int ExportedBySGInfra IsColinearDirection(const CATMathDirectionf& iU, const CATMathDirectionf& iV, const float& iAngleResolution, CATMathVectorf& oVectorialProduct);
extern int ExportedBySGInfra IsOrthogonalDirection(const CATMathDirectionf& iU, const CATMathDirectionf& iV, const float& iAngleResolution);
extern int ExportedBySGInfra IsOrthogonalDirection(const CATMathDirectionf& iU, const CATMathDirectionf& iV, const float& iAngleResolution, float& oScalarProduct);
extern int ExportedBySGInfra AreDirectionsColinears(CATMathDirectionf& i_direction1, CATMathDirectionf& i_direction2, float i_absoluteEpsilon = 1e-3);
extern int ExportedBySGInfra AreDirectionsOrthogonal(CATMathDirectionf& i_direction1, CATMathDirectionf& i_direction2, float i_absoluteEpsilon = 1e-3);
extern int ExportedBySGInfra IsIdenticalPoint(const CATMathPointf& iPt1, const CATMathPointf& iPt2, const float& iLengthResolution);

extern ExportedBySGInfra CATMathDirectionf GetOrthogonalDirection(const CATMathDirectionf& iDir);

struct CATScissorStruct
{
  float _x, _y, _dx, _dy;
};

extern int ExportedBySGInfra Special_angle(const CATMathVectorf&, const CATMathVectorf&, const double &);

extern double ExportedBySGInfra Value_angle(const CATMathVectorf&, const CATMathVectorf&, const CATMathVectorf&);

extern float ExportedBySGInfra CATDistPtLn(const CATMathPointf&, const CATMathPointf&, const CATMathDirectionf&, CATMathPointf&);
extern float ExportedBySGInfra CATDistLnLn(const CATMathPointf&, const CATMathDirectionf&, const CATMathPointf&, const CATMathDirectionf&, CATMathPointf&, CATMathPointf&);

extern int ExportedBySGInfra CATInterPlnLn(const CATMathPointf&, const CATMathDirectionf&, const CATMathPointf&, const CATMathDirectionf&, CATMathPointf&);
extern int ExportedBySGInfra CATInterPlnLn(const CATMathPoint&, const CATMathDirection&, const CATMathPoint&, const CATMathDirection&, CATMathPoint&);

ExportedBySGInfra CATVizViewer* CATVizGetVizViewer(CATViewer*);
typedef CATVizViewer* (*PtrFuncForViewerAccess)(CATViewer*);
ExportedBySGInfra int CATVizSetViewerAccessFunc(PtrFuncForViewerAccess);

extern void ExportedBySGInfra CalculateParametricPlane(CATMathPointf iv1, CATMathPointf iv2, CATMathPointf iv3, CATMathVectorf &on, float &oc);
extern int ExportedBySGInfra WhichSideOfPlane(CATMathPointf point, CATMathVectorf normal, float constant);
extern int ExportedBySGInfra IsZerof(float ivalue);
extern int ExportedBySGInfra IsGreaterf(float ivalue1, float ivalue2);
extern int ExportedBySGInfra IsLesserf(float ivalue1, float ivalue2);
extern void ExportedBySGInfra IntersectLineAndPlane(CATMathPointf ip1, CATMathVectorf ip1p2, CATMathVectorf inormal, float iconstant, CATMathPointf &ointersectionPoint, float &olambda, int &oparallel, int &ocounfounded);
extern void ExportedBySGInfra IntersectLines(CATMathPointf a, CATMathVectorf d, CATMathPointf b, CATMathVectorf e, CATMathPointf &ointersectionPoint, float &olambda, int &oparallel, int &ocounfounded);
extern int ExportedBySGInfra IntersectPolygones(CATMathPointf *ipoly1, CATMathPointf *ipoly2, int in1, int in2, CATMathPointf &opoint1, CATMathPointf &opoint2);
extern void ExportedBySGInfra RotateVector(CATMathDirectionf i_axe, float i_angle, CATMathVectorf i_origin, CATMathVectorf o_result);
extern HRESULT ExportedBySGInfra ComputeBoundingBoxFromRep(CATSupport &i_support, CATRep &i_rep, CATMathPointf &o_minPoint, CATMathPointf &o_maxPoint);
extern int ExportedBySGInfra Compare2Faces(CAT3DBoundingGP *fref1, CAT3DBoundingGP *fref2);

extern int ExportedBySGInfra IsPointOnPlane(const CATMathPointf& i_point, const CATMathPointf& i_planeOrigin, const CATMathVectorf& i_planeNormal, float i_absoluteEpsilon = 1e-3);

//    Return: >0 for P2 left of the line through P0 and P1
//            =0 for P2  on the line
//            <0 for P2  right of the line
extern int ExportedBySGInfra IsLeft(const CATMathPoint2Df& P0, const CATMathPoint2Df& P1, const CATMathPoint2Df& P2);

extern bool ExportedBySGInfra IsInsidePolygon2D(const CATMathPoint2Df& point, const float* polygon, int nVertices);

// If the segment intersects the furstum: clamps the segment on the frustum and return true
//   ioPoint1 and ioPoint2 are the segment ends.
//   a, b, c, d arrays contain the parameters of the iNbPlanes planes of the frustum
extern bool ExportedBySGInfra IntersectLineFrustum(const float* a, const float* b, const float* c, const float* d, int iNbPlanes, CATMathPointf& ioPoint1, CATMathPointf& ioPoint2 );

// Eigen Coodinate System of a cloud of points in 3D.
//iArray   : vertex array.
//iNbPoint : number of points in the cloud.
//oMatrix  : returned matrix with the 3 eigen vectors and inertia center.
//oEigenValues   : eigen value for each eigen vector.
//oNbEigenValues : number of eigen values.
extern HRESULT ExportedBySGInfra ComputeEigen3DCoordinateSystem(const float *iArray, int iNbPoint, CAT4x4Matrix &oMatrix, double*& oEigenValues, int &oNbEigenValues);
//DO NOT USE : UNDER CODING.
extern HRESULT ExportedBySGInfra CATVizGetOrientedBoundingBox(CAT3DRep *iRep, CATMathPointf &oMinPoint, CATMathPointf &oMaxPoint, CAT4x4Matrix &oMatrix);

// P is in the plane normal to the viewpoint sight vector, holding the viewpoint target. The line
// from C to the viewpoint origin is parallel to the viewpoint projection direction. Thus, C always appears
// at the screen center, and is the viewpoint target if the viewpoint is symetric..
void ExportedBySGInfra GetVizAssymTarget(const CAT3DViewpoint& vp, CATMathPointf& P);

enum CGRSettingContext {
  CATPARTCGRSTREAMCONTEXT = 0x0,
  CATPRODUCTCGRCONTEXT = 0x1
};

extern int ExportedBySGInfra CATVisGenerateCgr(char *iBuffer, int iLength, char*& oBuffer, int& oLength, CATSettingCgr iSetting);
extern HRESULT ExportedBySGInfra CompareCgrHeaderWithSession(CATCgrHeader * iHeader, CATBoolean lookForOverridenSettings = FALSE);

// --- semantic filtering services -----------------------------------------------------------------
extern HRESULT ExportedBySGInfra CATVisSetSemanticFilter(CATRep *iRep, unsigned char iType, unsigned int iFilterValue);

extern ExportedBySGInfra CAT3DFaceGP * CATVizCreate3DFaceGPWithStripsAndFansGeneration(float vertices[],
  int   verticesArraySize,
  float normals[],
  int   normalsArraySize,
  int   triangleIndice[],
  int   nbTriangle,
  int   bIsThisPlanarFace);
// Compute the version of the cgr cache 
// return values 
// 1 : the cgr includes CAT3DEdgeGP
// 0 : the cgr includes CAT3DLineGP

extern ExportedBySGInfra unsigned int ComputeCacheVersionFromCGR(CATRep & iRep);

// Unicode to char * and char * to unicode.
// WARNING : Works only for ASCII code page
extern ExportedBySGInfra WCHAR * ConvertCharPtrToUnicode(const char *string);
extern ExportedBySGInfra char *  ConvertUnicodeToCharPtr(WCHAR * ucsString);
// IIX => 
// GetPolylinesFormEllipse function returns number of points and 3D polylines
// to be needed to form a circle / ellipse
extern int ExportedBySGInfra GetPolylinesFormEllipse(CATRender& Render, const CATMathPointf& iCenter, float iXRadius,
  float iYRadius, const CATMathVectorf& iNormal, const CATMathVectorf& iAxis, const float iBeginAngle,
  const float iEndAngle, const int iSagmax, float*& oLine, int& iSizeLine, const unsigned int iIsGPFixed);
// <= IIX

// the array is [x,y,z,u,v,w,s] where s is the scalar component of the quaternion.
// or [u,v,w,s]
extern void ExportedBySGInfra CAT4x4MatrixToQuaternion(const CAT4x4Matrix & iMatrix, float  oV[7]);
extern void ExportedBySGInfra CAT4x4MatrixToQuaternion(const CAT4x4Matrix & iMatrix, CATMathVectorf& T, float  oV[4]);
extern void ExportedBySGInfra QuaternionToCAT4x4Matrix(float iP[7], CAT4x4Matrix & oMatrix);
extern void ExportedBySGInfra QuaternionToCAT4x4Matrix(CATMathVectorf& iV, float iQ[4], CAT4x4Matrix & oMatrix);
extern CATBoolean ExportedBySGInfra QuaternionToRotation(float iQ[4], CATMathVectorf& axis, float& angle);

extern float ExportedBySGInfra CATVisGetSag(CATRep *iRep);
extern float ExportedBySGInfra CATVisGetSag(char *iBuffer, int iLength);
extern void ExportedBySGInfra CATVisGetSag(char **filenamelist, int sizelist, float*& sagList);

extern ExportedBySGInfra HRESULT CATVisGetLayerFilter(const CATRep * iRep, unsigned char oFilter[1024]);

extern ExportedBySGInfra int IsRepValid(CATRep * iRep, const int iMode = REMOVE_FIXED_SIZE | REMOVE_EMPTY | REMOVE_INFINITE | REMOVE_CATAFR3DCOMPASSBAGREP | REMOVE_CATLIVESHAPEREFERENT3DBAGREP);
extern CAT3DBoundingSphere ExportedBySGInfra GetBoundingSphere(CAT3DRep * iRep, const int iMode);

//D6F: ER052520 Volume Clipping Picking ++
// https://en.wikipedia.org/wiki/Möller–Trumbore_intersection_algorithm
// https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-rendering-a-triangle/moller-trumbore-ray-triangle-intersection
extern bool RayTriangleIntersect(const CATMathPoint &orig, const CATMathVector &dir, const CATMathPoint &v0, const CATMathPoint &v1, const CATMathPoint &v2, float &t, float &u, float &v);

// float version
extern bool RayTriangleIntersect(const CATMathPointf &orig, const CATMathVectorf &dir, const CATMathPointf &v0, const CATMathPointf &v1, const CATMathPointf &v2, float &t, float &u, float &v);
//D6F: ER052520 Volume Clipping Picking --

// FUN099945 Picking of Section Profile ++
extern bool RayColinearTriangleIntersect(const CATMathPointf &orig, const CATMathVectorf &dir, const CATMathPointf &v0, const CATMathPointf &v1, const CATMathPointf &v2, float &t1, float &t2);
extern bool IsPointInLineSegment(const CATMathPointf &iLine1, const CATMathPointf &iLine2, const CATMathPointf &iPoint);
// FUN099945 Picking of Section Profile --

// Added by SDY5 to remove ios runtime error in release mode.
#define CATVizPtrIsNull DSYSysIsPointerNull

// JUT : A macro that could be used in order to replace hardcoded lib filenames definitions below.
#ifndef LIBFILENAME
#if defined   (_AIX)
#define LIBFILENAME(iName) "lib" #iName ".a"
#elif defined (_IRIX_SOURCE) 
#define LIBFILENAME(iName) "lib" #iName ".so"
#elif defined (_WINDOWS_SOURCE) 
#define LIBFILENAME(iName) "" #iName ".dll"
#elif defined(_SUNOS_SOURCE)
#define LIBFILENAME(iName) "lib" #iName ".so"
#elif defined(_HPUX_SOURCE)
#define LIBFILENAME(iName) "lib" #iName ".sl"
#elif defined(_LINUX_SOURCE)
#define LIBFILENAME(iName) "lib" #iName ".so"
#elif defined(_DARWIN_SOURCE)
#define LIBFILENAME(iName) "lib" #iName ".dylib"
#elif defined(_ANDROID_SOURCE)
#define LIBFILENAME(iName) "lib" #iName ".so"
#else
#define LIBFILENAME(iName) ""
#endif
#endif

#endif
