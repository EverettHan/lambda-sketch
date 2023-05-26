#ifndef CATK3DTree_h
#define CATK3DTree_h
//==========================================================================
// COPYRIGHT DASSAULT SYSTEMES 2020
//==========================================================================
//
//==========================================================================
// Usage Notes
//==========================================================================
// Simple usage 3d tree for fast searching of points in a fixed data base
// in 3-dimensional Euclidean space.
// Based on free licensed works from Matthew B. Kennel, Institute for Nonlinear Science
//
// 05/2020: FAA2 Creation
//========================================================================== 
//

//#define NOMINMAX

#include "MathMarsh.h"
#define KDTreeImp

#if defined(_AIX_SOURCE)
#undef KDTreeImp
#endif

#ifdef KDTreeImp
#include <vector>
#include <algorithm>
#include <array>
#include <limits>

typedef std::vector< std::array<double,3> >  CATK3DTreeArray;

typedef struct {
  double lower, upper;
} interval;


class CATK3DTreeNode;
class CATK3DSearchRecord;

struct CATK3DTreeResult {
public:
  double dis;  // its square Euclidean distance
  int idx;    // which neighbor was found
}; 

//=======================================================================
// Class CATK3DTreeResultVector 
//=======================================================================
class ExportedByMathMarsh CATK3DTreeResultVector : public std::vector<CATK3DTreeResult> {
public:

  //  
  // Adds one new element to the list of results, and
  // keep it in heap order.  To keep it in ordinary, as inserted,
  // order, then simply use push_back() as inherited
  // via std::vector<> 

  void push_element_and_heapify(CATK3DTreeResult&);
  double replace_maxpri_elt_return_new_maxpri(CATK3DTreeResult&);

  double max_value(); 
  // return the distance which has the maximum value of all on list, 
  // assuming that ALL insertions were made by
  // push_element_and_heapify() 
};



//=======================================================================
// Class CATK3DTree
//=======================================================================
class ExportedByMathMarsh CATK3DTree {
public: 
  const CATK3DTreeArray& the_data;   
  // "the_data" is a reference to the underlying multi_array of the
  // data to be included in the tree.
  //
  // NOTE: this structure does *NOT* own the storage underlying this.
  // Hence, it would be a very bad idea to change the underlying data
  // during use of the search facilities of this tree.
  // Also, the user must deallocate the memory underlying it.


  const int N;   // number of data points
  int dim; //
  bool sort_results;  // USERS set to 'true'. 
  const bool rearrange; // are we rearranging? 

public:

  //
  // constructor, has optional 'dim_in' feature, to use only
  // first 'dim_in' components for definition of nearest neighbors.
  //

  CATK3DTree(CATK3DTreeArray& data_in,bool rearrange_in = true,int dim_in=-1);

  // destructor
  ~CATK3DTree();
  

public:

  void n_nearest_brute_force(std::vector<double>& qv, int nn, CATK3DTreeResultVector& result);


  void n_nearest(std::vector<double>& qv, int nn, CATK3DTreeResultVector& result);


// search for 'nn' nearest to point [idxin] of the input data, excluding
// neighbors within correltime 
  void n_nearest_around_point(int idxin, int correltime, int nn,
			      CATK3DTreeResultVector& result);

// search for 'nn' nearest to point [idxin] of the input data, excluding
// neighbors in outliers_in (which are consistent point indexes from data) 
  void n_nearest_around_point_exclusion_list(int idxin, int correltime, int nn, CATK3DTreeResultVector& result, std::vector<int>* outliers_in);

 
// search for all neighbors in ball of size (square Euclidean distance)
// r2.   Return number of neighbors in 'result.size()', 
  void r_nearest(std::vector<double>& qv, double r2,CATK3DTreeResultVector& result);


// like 'r_nearest', but around existing point, with decorrelation
// interval.
  void r_nearest_around_point(int idxin, int correltime, double r2,
			      CATK3DTreeResultVector& result);


// count number of neighbors within square distance r2.
  int r_count(std::vector<double>& qv, double r2);

// like r_count, c
  int r_count_around_point(int idxin, int correltime, double r2);


  friend class CATK3DTreeNode;
  friend class CATK3DSearchRecord;

private:

  CATK3DTreeNode* root; // the root pointer

  const CATK3DTreeArray* data;

// the index for the tree leaves.  Data in a leaf with bounds [l,u] are
// in  'the_data[ind[l],*] to the_data[ind[u],*]
  std::vector<int> ind;


// if rearrange is true then this is the rearranged data storage. 
  CATK3DTreeArray rearranged_data;  


  static const int bucketsize = 12;  // global constant. 

private:
  void set_data(CATK3DTreeArray& din); 
  void build_tree(); // builds the tree.  Used upon construction. 
  CATK3DTreeNode* build_tree_for_range(int l, int u, CATK3DTreeNode* parent);
  void select_on_coordinate(int c, int k, int l, int u); 
  int select_on_coordinate_value(int c, double alpha, int l, int u); 
  void spread_in_coordinate(int c, int l, int u, interval& interv);
};



//=======================================================================
// Class CATK3DTreeNode
//=======================================================================
class ExportedByMathMarsh CATK3DTreeNode {
public:
  // constructor
  CATK3DTreeNode(int dim);

  // destructor
  ~CATK3DTreeNode();

private:
  // visible to self and CATK3DTree.
  friend class CATK3DTree;

  int cut_dim;                                 // dimension to cut; 
  double cut_val, cut_val_left, cut_val_right;  //cut value
  int l,u;  // extents in index array for searching

  std::vector<interval> box; // [min,max] of the box enclosing all points
  
  CATK3DTreeNode *left, *right;  // pointers to left and right nodes. 

 // recursive innermost core routine for searching.. 
  void search(CATK3DSearchRecord& sr); 

// return true if the bounding box for this node is within the
// search range given by the searchvector and maximum ballsize in 'sr'.
  bool box_in_search_range(CATK3DSearchRecord& sr);
 

  void check_query_in_bound(CATK3DSearchRecord& sr); // debugging only


  // for processing final buckets. 
  void process_terminal_node(CATK3DSearchRecord& sr);
  void process_terminal_node_fixedball(CATK3DSearchRecord& sr);


};



//=======================================================================
// Class CATK3DSearchRecord
// Search record substructure
// One per search
//=======================================================================
//
class ExportedByMathMarsh CATK3DSearchRecord {

private:
    friend class CATK3DTree;
    friend class CATK3DTreeNode;

    std::vector<double>& qv;
    int dim;
    bool rearrange;
    unsigned int nn; // , nfound;
    double ballsize;
    int centeridx, correltime;

    CATK3DTreeResultVector& result;  // results
    const CATK3DTreeArray* data;
    const std::vector<int>& ind;
    const std::vector<int>* outliers;

    // constructor

public:
    CATK3DSearchRecord(std::vector<double>& qv_in, CATK3DTree& tree_in,
        CATK3DTreeResultVector& result_in, std::vector<int>* outliers_in = NULL) :
        qv(qv_in),
        result(result_in),
        data(tree_in.data),
        ind(tree_in.ind),
        outliers(outliers_in)
    {
        dim = tree_in.dim;
        rearrange = tree_in.rearrange;
        ballsize = (std::numeric_limits<double>::max)();
        nn = 0;
    };

};


// Utilities

inline double squared(const double x) {
    return(x*x);
}

inline void swap(int& a, int&b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

inline void swap(double& a, double&b) {
    double tmp;
    tmp = a;
    a = b;
    b = tmp;
}

inline bool operator<(const CATK3DTreeResult& e1, const CATK3DTreeResult& e2) {
    return (e1.dis < e2.dis);
}

inline double dis_from_bnd(double x, double amin, double amax) {
    if (x > amax) {
        return(x - amax);
    }
    else if (x < amin)
        return (amin - x);
    else
        return 0.0;


}
#endif

#endif

