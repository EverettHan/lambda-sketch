/**
 *  Large Range compatibility certified by DNR (2014-05-21)
 */
//==============================================================================================================
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2005
//==============================================================================================================
// CATCloudProjection:
//==============================================================================================================
// Usage notes:
//==============================================================================================================
// 30-Aug-2010 - DNR - Ajout d'un destructeur virtual dans la classe T_Mesh pour MLK si destructeur d'une classe
//                     qui derive de T_Mesh..
// 15-Jan-2007 - DNR - Passage du champs _NbRuns en static pour permettre à plusieurs instances du projecteur
//                     sur un même maillage de fonctionner sans problème.
// 23-Oct-2006 - DNR - Report changement de signature GetResult booelan -> enum CATCldProjectionPosition
// 04-Sep_2006 - DNR - Projection suivant direction.
// ..-...-2005 - JLH - Reprise par JLH.
// 03-May-2004 - BHV - Creation.
//==============================================================================================================

#ifndef CATCloudProjection_H
#define CATCloudProjection_H

#include "ExportedByCATCloudBasicResources.h"
#include "CATBooleanDef.h"

class CATCloudPartition;
class CATCldPrjTriangle;

class ExportedByCATCloudBasicResources CATCloudProjection
{

//==============================================================================================================
// Public Part.
//==============================================================================================================

public :

  enum CATCldPrjResultType {
    Unknown,
    OnMesh,
    Exact,
    LinearApprox,
    CubicApprox
  } ;

  enum CATCldPrjProjectionType {
    OnNothing,
    OnPoint,
    OnVertex,
    OnEdge,
    OnTriangle
  } ;

  enum CATCldProjectionPosition {
    NoProjection,
    OnBoundary,
    OnTarget // OnSurface
  };

  enum CATCldPrjProjectionMode {
    Normal,             // Normal to the surface, set by default.
    AlongOneDirection,  // Along a direction computation made by pixelisation
    AlongDirections     // Along a direction computation made using voxelisation.
  } ;

  class ExportedByCATCloudBasicResources T_Mesh {

    public:
      virtual ~T_Mesh(){};
      //
      virtual boolean IsACloudType () const = 0 ;
      virtual boolean IsAScanType () const = 0 ;
      virtual boolean IsAPolygonType () const = 0 ;
      //
      virtual int GetNbPoints () const = 0 ;
      virtual void GetCoords ( const int iNoPoint,
                               double    oCoords[3]) const = 0 ;
      //
      virtual int GetNbTriangles () const = 0 ;
      virtual void GetTriangle ( const int   iNoTriangle,
                                 int         oNoVertices[3],
                                 int       oNoConnexes[3]) const = 0 ;
      virtual int IsTriangleToBeTreated (int NoTri) const = 0 ;

      virtual void GetBoundingBox ( double& oXmin,double& oYmin,double& oZmin,
                                    double& oXmax,double& oYmax,double& oZmax) const = 0 ;
      //
      inline void ComputeTriangleNormal (const int        iNoTriangle,
                                         double           oNormal[3]) const
      {
        oNormal[0] = 0. ;
        oNormal[1] = 0. ;
        oNormal[2] = 0. ;

        int TriangleVtx[3];
        int Connexes[3];
        GetTriangle(iNoTriangle, TriangleVtx,Connexes);
        double Vtx1[3], Vtx2[3], Vtx3[3], V12[3], V13[3], Nor[3];

        GetCoords(TriangleVtx[0] , Vtx1);
        GetCoords(TriangleVtx[1] , Vtx2);
        GetCoords(TriangleVtx[2] , Vtx3);

        V12[0] = Vtx2[0] - Vtx1[0] ;
        V12[1] = Vtx2[1] - Vtx1[1] ;
        V12[2] = Vtx2[2] - Vtx1[2] ;
        V13[0] = Vtx3[0] - Vtx1[0] ;
        V13[1] = Vtx3[1] - Vtx1[1] ;
        V13[2] = Vtx3[2] - Vtx1[2] ;
        Nor[0] = V12[1]*V13[2] - V12[2]*V13[1] ;
        Nor[1] = V12[2]*V13[0] - V12[0]*V13[2] ;
        Nor[2] = V12[0]*V13[1] - V12[1]*V13[0] ;

        double Norme = Nor[0]*Nor[0] + Nor[1]*Nor[1] + Nor[2]*Nor[2] ;
        if (Norme > 0.) {
          oNormal[0] = Nor[0];
          oNormal[1] = Nor[1];
          oNormal[2] = Nor[2];
        } else {
          oNormal[0] = 0. ;
          oNormal[1] = 0. ;
          oNormal[2] = 0. ;
        }
      }
  };
  //
  // Pour Gestion des attributs utilisés pour stocker les Proj on Triangles.
  // DNR : Je ne vois pas comment gérer les attribut de la même manière qu'avant
  //       sans l'heritage du CATICGMObject
  //
  class ExportedByCATCloudBasicResources T_MeshAttributes {
    public :
      //
      // Constructeur. 
      //
      T_MeshAttributes(T_Mesh* themesh);
      virtual ~T_MeshAttributes();
      //
      // Return the array of attributes (CATCldPrjTriangle)
      //
      virtual CATCldPrjTriangle** GetPrjAttributes() ;
      //
      // Detruction des attributs.
      //
      virtual void DeleteAttributes();

    private :
      T_Mesh*             _TheMesh ;
      int                 _NbAttributes;
      CATCldPrjTriangle** _Attributes;
  };

  CATCloudProjection () ;
  virtual ~CATCloudProjection () ;

  void SetParameters (const boolean iNormal,
                      const boolean iOnlyActive,
                      const double  iTolerance,
                      const double  iSag) ;
  //=====================================================================
  // iMode = 0 -> Normal projection
  //         1 -> Along a direction computation made by pixelisation
  //         2 -> Along a direction computation made using voxelisation.
  //=====================================================================
  void SetProjectionMode(int imode);

  void SetProjectionDirection(double iDirX, double iDirY, double iDirZ);

  boolean LoadTargets (int iNbObjects, CATCloudProjection::T_Mesh** iObjects, CATBoolean iSortActiveTriangles = FALSE) ;

  boolean Run (const double iCoords[3]) ;

  CATCldProjectionPosition GetResult (double oCoords[3]) ;

   boolean GetNormal (double oNormal[3]) ;

  void OnMeshProjection() ;

  void GetInfos(int *NumLocal, int *NumGlobal, T_Mesh** Support, CATCldPrjProjectionType *Type) const;

  inline CATCldPrjProjectionType Type() const;
	inline int NumGlobal() const;
	inline int NumLocal() const;
  inline T_Mesh* Support() const;
  inline void UVW(double UVW[3]);

  // Modification of the Target Polygon.
  boolean RemoveTriangle(T_Mesh* iTarget,int iNoTriangle);
  boolean AddTriangle(T_Mesh* iTarget,int iNoTriangle);


//==============================================================================================================
// Private Part.
//==============================================================================================================

private:

  boolean Run() ;

  void QueueSearch (const int     iNbVoxels,
                    const double  iToProj[3],
                    double       &ioDistMin) ;

  static int CompareParamCroissant (const void* iP1,
                                    const void* iP2) ;

  boolean ProjectionInVoxel (const int     iIJK[3],
                             const double  iToProj[3],
                             double        oProjec[3],
                             double       &ioDistMin) ;

  void SetInfos (T_Mesh*                       iSupport,
                 const CATCldPrjProjectionType iType,
                 const int                     iNumGlobal,
                 const int                     iNumLocal,
                 const double                  iUVW[3]) ;

  boolean IsItOrthogonal() ;
  boolean TopologicalDisk (T_Mesh*      iMesh,
                           const int       iNoTri,
                           const int       iNoVtx,
                           int **          oNoTri,
                           int             &oNbTri,
                           boolean         &oClosed) ;

  void DeleteArgumentsList() ;

  void computeAxis();

  CATCldPrjTriangle** GetPrjAttributes(T_Mesh* iMesh);

  inline static int _Next (const int iIdx) ;
  inline static int _Prev (const int iIdx) ;
  inline static int _OppositeEdge (const int iIVtx) ;
  inline static int _OppositeVertex (const int iIEdg) ;

//--------------------------------------------------------------------------------------------------------------------

  struct TArgument {
    T_Mesh*        _Entity ;     // Maillage associé (ou entité Cld si l'argument en est une).
    T_MeshAttributes* _Attributes ; // Mesh Attributes.
    TArgument*        _Next ;
  } ; 

  struct TVoxel {
    int             _IJK[3] ;
    double          _Distance ;
  } ;

//--------------------------------------------------------------------------------------------------------------------

  boolean                 _Normal ;
  boolean                 _OnlyActive ;
  double                  _Tolerance ;
  double                  _Sag ;

  boolean                 _OnMeshStatus ;
  boolean                 _ProjecStatus ;
  boolean                 _NormalStatus ;

  double                  _CoordsToProj[3] ;
  double                  _CoordsOnMesh[3] ;
  double                  _CoordsProjec[3] ;
  double                  _CoordsNormal[3] ;
  double                  _UDir[3] ;
  double                  _VDir[3] ;
  double                  _WDir[3] ;

  T_Mesh*                  _Support ;
  CATCldPrjProjectionType _Type ;
  CATCldProjectionPosition  _Position  ; // Memroise la position de la projection sur la surface(No,OnBoundary, OnTarget)
  int                     _NumGlobal ;
  int                     _NumLocal ;
  double                  _UVW[3] ;

  TArgument*              _Arguments ;

  CATCloudPartition*      _Partition ;
  TVoxel*                 _Queue ;

  CATCldPrjProjectionMode _ProjectionMode;

  // Pour le debug
  int _NbStep[4], _NbOn[3] ;
  int _NbOuter ;
} ;

//--------------------------------------------------------------------------------------------------------------
// Function : Type
// Purpose  : Returns the _Type value.
//--------------------------------------------------------------------------------------------------------------

inline CATCloudProjection::CATCldPrjProjectionType CATCloudProjection::Type() const
{
  return _Type;
}

//--------------------------------------------------------------------------------------------------------------
// Function : Type
// Purpose  : Returns the _Type value.
//--------------------------------------------------------------------------------------------------------------

inline int CATCloudProjection::NumGlobal() const
{
  return _NumGlobal;
}

//--------------------------------------------------------------------------------------------------------------
// Function : Type
// Purpose  : Returns the _Type value.
//--------------------------------------------------------------------------------------------------------------

inline int  CATCloudProjection::NumLocal() const
{
  return _NumLocal;
}

//--------------------------------------------------------------------------------------------------------------
// Function : Support
// Purpose  : Returns the TMesh object used to projection onto.
//--------------------------------------------------------------------------------------------------------------

inline  CATCloudProjection::T_Mesh*  CATCloudProjection::Support() const
{
  return _Support;
}

//--------------------------------------------------------------------------------------------------------------
// Function : UVW
// Purpose  : Returns the UVW barycentric corrdinates of le projected point.
//--------------------------------------------------------------------------------------------------------------

inline void CATCloudProjection::UVW(double UVW[3])
{
  UVW[0] = _UVW[0]; UVW[1] = _UVW[1]; UVW[2] = _UVW[2]; 
}

//--------------------------------------------------------------------------------------------------------------
// Function : _Next
// Purpose  : Returns the next triangle-indice modulo 3.
//--------------------------------------------------------------------------------------------------------------

inline int CATCloudProjection::_Next (const int iIdx)
{
  return (iIdx + 1) % 3 ; // (I+1)%N
}

//--------------------------------------------------------------------------------------------------------------
// Function : _Prev
// Purpose  : Returns the previous triangle-indice modulo 3.
//--------------------------------------------------------------------------------------------------------------

inline int CATCloudProjection::_Prev (const int iIdx)
{
  return (iIdx + 2) % 3 ; // (I+N-1)%N
}

//--------------------------------------------------------------------------------------------------------------
// Function : _OppositeEdge
// Purpose  : Returns the opposite edge triangle-indice of a vertex given by its triangle-indice.
//--------------------------------------------------------------------------------------------------------------

inline int CATCloudProjection::_OppositeEdge (const int iIVtx)
{
  return (iIVtx + 1) % 3 ; // Dans le cas d'un triangle = Next(iITVertex)
}

//--------------------------------------------------------------------------------------------------------------
// Function : _OppositeVertex
// Purpose  : Returns the opposite vertex triangle-indice of an edge given by its triangle-indice.
//--------------------------------------------------------------------------------------------------------------

inline int CATCloudProjection::_OppositeVertex (const int iIEdg)
{
  return (iIEdg + 2) % 3 ; // Dans le cas d'un triangle = Prev(iITEdge)
}

#endif
