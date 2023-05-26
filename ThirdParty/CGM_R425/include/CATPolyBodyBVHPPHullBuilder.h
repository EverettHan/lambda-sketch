//==================================================================-*- C++ -*-
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
//  Creation a hull version of the input BVH
//
//=============================================================================
// 2021 GH7 :  Creation 
//=============================================================================

#ifndef CATPolyBodyBVHPPHullBuilder_h
#define CATPolyBodyBVHPPHullBuilder_h

#include "PolyBodyBVHOperators.h"
#include "CATCGMSharedPtr.h"
#include "CATMathTransformation.h"


#include <vector>
#include <map>
#include <string>

class CATBVHTreeSet;
class CATMathBox;
class CATPolyBodyBVHTreeSet;
class CATIPolyMesh;
class CATPolyBody;
class CATSoftwareConfiguration;

/**
 * Shared code between CATPolyBodyBVHPPHullBuilder and  CATPolyVisuBVHPPHullBuilder
 */
class ExportedByPolyBodyBVHOperators CATPolyBVHPPHullBuilderCommon
{
  protected:
    CATPolyBVHPPHullBuilderCommon(){}
  public: 
    virtual ~CATPolyBVHPPHullBuilderCommon(){};

  /**
   * @brief return a bvhtree Body but the rep are replaced by a hull version of the original
   * Set the number of thread to use 
   * if iNbThread is <=0 the number is choose by the algo ( use the number of thread available on the computer )
   * @param[in]  iNbThread number of thread to use.
   * */
  void SetNbThread(int iNbThread=-1) {_NbThread=iNbThread;};

   /**
   * 
  */
  inline double GetLastVoxelSizeUsed() {
    return _LastVoxelSize;
  }

  


  typedef enum 
  {
    NoCluster     = 0,    //! no cluster
    Basic            ,    //! polybody will be group in n cluster arbitrary
    ByNbTriangle     ,  //! clustering try to equilibrate the number of triangle by cluster
    ByBoxCentroid       //! Clustering will group polybody in function of their centroid (using Kmean)
  } ClusteringMethod;

  class ExportedByPolyBodyBVHOperators ClusteringOptions
  {
    public:
    ClusteringOptions();

    ClusteringMethod Method = NoCluster;
    int NbCluster = -1; //! if <0 the algo choose the number of cluster which can depends of the computer
    bool DoFinalMerge = true; // merge the hull of the cluster at the end
  };
  
  void SetClusteringOptions( ClusteringOptions & Opt){
    _ClusterOptions = Opt;
  };

   /**
   * internal method 
   * build the hull of a list of polybody
   * */
  static CATCGMSharedPtr<CATIPolyMesh> DoHull( std::vector<std::pair<CATCGMSharedPtr<CATPolyBody>, CATMathTransformation>> &Bodys,    
    CATMathBox box, int iNx,int iNy, int iNz,int iNbThread,
    unsigned long &oOriginalTriangles, unsigned long &oHullTriangle, CATSoftwareConfiguration & iSoftConfig);
  
  static CATCGMSharedPtr<CATPolyBody> MakeHull(std::vector<std::pair<CATCGMSharedPtr<CATPolyBody>, CATMathTransformation>> &Bodys, double voxelsize, unsigned long &oOriginalTriangles, unsigned long &oHullTriangle, int _NbThread,CATMathBox * iUserFilterBox = nullptr, double iOffset = 0.0, ClusteringOptions opt  = ClusteringOptions());

  static void AutoGroupHull( CATBVHTreeSet &input, std::map<int, std::vector<int>>& idToGroupInHull);
 
  static std::map<int, CATCGMSharedPtr<CATPolyBody>>  MakeHullBVHSet(
    CATPolyBodyBVHTreeSet &input, double voxelsize, unsigned long &oOriginalTriangles, unsigned long &oHullTriangles, std::map<int, std::vector<int>> idToGroupInHull, int nbThread,CATMathBox * iUserFilterBox =nullptr, double iOffset =0.0,ClusteringOptions opt  = ClusteringOptions());

  static void DumpPoly(CATIPolyMesh &iPolyMesh, std::string filename);
  static void DumpPoly(CATPolyBody &iPolyMesh, std::string filename);
  static std::string ODTPathName();

  static int NBRun;

   protected: 
    int _NbThread = -1;
    ClusteringOptions _ClusterOptions;
    
    double _LastVoxelSize;
    

};

/**
 * Create a hull version bvh of the input bvh
 */
class ExportedByPolyBodyBVHOperators CATPolyBodyBVHPPHullBuilder  : public CATPolyBVHPPHullBuilderCommon
{
 public:
  CATPolyBodyBVHPPHullBuilder(){}

  ~CATPolyBodyBVHPPHullBuilder(){}

  
  /**
   * @param iOriginalMovable original bvh
   * @param iVoxelSize [optional] size of voxel if <0 an heuristic chose the size
   * @param iRatioToUseHull [optional] ratio which decide if the hull will be use or not in function 
   * @param[in] iIdToGroupInHull mapping which define how the original ID will be group in the new bvhtree hull.
   * */
  CATPolyBodyBVHTreeSet * Run(CATPolyBodyBVHTreeSet & iOriginalMovable,
   double iVoxelSize=-1 ,
   double iRatioToUseHull=-1,
   std::map<int,std::vector<int>> iIdToGroupInHull=std::map<int,std::vector<int>>(),
   CATMathBox * iUserFilterBox=nullptr,
  double iOffsetToApply = 0.0);


 

};

#endif //CATPolyBodyBVHPPHullBuilder_h
