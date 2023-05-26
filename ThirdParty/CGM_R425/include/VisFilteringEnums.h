#ifndef VisFilteringEnums_H
#define VisFilteringEnums_H

//For CATVisPolygonOffsetFilter
static constexpr unsigned int kPolyOffsetFilterNoOverride = 0x40000000;
static constexpr unsigned int kPolyOffsetFilterOverride = 0x20000000;
static constexpr unsigned int kPolyOffsetFilterRestore = 0x10000000;
enum class EPolyOffsetFilterMode : unsigned int
{
  eFilterPolyOffsetDisable = kPolyOffsetFilterOverride | 0,   //DepthBias(0) DepthSlopeFactor(0) 
  eFilterPolyOffsetMode1 = kPolyOffsetFilterOverride | 1,   //DepthBias(1) DepthSlopeFactor(1.1) 
  eFilterPolyOffsetMode2 = kPolyOffsetFilterOverride | 2    //DepthBias(3) DepthSlopeFactor(2.2) 
};

enum class VisFilteringEnums
{
  eNonAF_NotFiltered = 0,
  eNonAF_Filtered,
  //Related to Annotation Filter Visiting
  //Purpose of visit is to retrieve
  eAF_NoPurpose,
  eAF_GetFilters,
  eAF_GetAllPaths,
  eAF_GetPathAdded,
  eAF_GetPathRemoved,
  eAF_GetPathModified,
  //Related to Annotation Filtering
  eAF_Filtered,
  eAF_Filtered_PathInvisible,
  eAF_NotFiltered_NoPath,
  eAF_NotFiltered_PathVisible,
  eAF_NotFiltered_Leaf,
  eAF_NotFiltered_NoParent,
  eAF_NotFiltered_NoData,
  //Related to Annotation Filtering AFForceShowMode
  eAF_FS_START, //(e)num (A)nnotation (F)ilter (F)orce (S)how (START)
  eAF_FS_Filtered_PathInvisible = eAF_Filtered_PathInvisible + eAF_FS_START,
  eAF_FS_NotFiltered_NoPath = eAF_NotFiltered_NoPath + eAF_FS_START,
  eAF_FS_NotFiltered_PathVisible = eAF_NotFiltered_PathVisible + eAF_FS_START,
  eAF_FS_NotFiltered_Leaf = eAF_NotFiltered_Leaf + eAF_FS_START,
  eAF_FS_NotFiltered_NoParent = eAF_NotFiltered_NoParent + eAF_FS_START,
  eAF_FS_NotFiltered_NoData = eAF_NotFiltered_NoData + eAF_FS_START,
  eAF_FS_END, //(e)num (A)nnotation (F)ilter (F)orce (S)how (END)
  //Related to Annotation path Editions
  eAF_Path_Failed,
  eAF_Path_Added,
  eAF_Path_Removed,
  eAF_Path_ValueChanged,
  eAF_Path_ValueNotObserved,
  eAF_Path_UnResolved,
  eAF_Path_Resolved,
  //return codes for VisSGAnnotationValueFeature::ModifyAnnoteInfo
  eAF_InvalidArgs,
  eAF_AValueNotFound,
  eAF_AValueNotChanged,
  eAF_AValueChanged,
  eAF_Erase_AVF
};

enum class AnnoteValueUpdateEnum
{
  eAV_NoUpdate = 0,
  eAV_UpdateEnum_MIN = eAV_NoUpdate,
  eAV_Overload,
  eAV_Value,
  eAV_Inherit,
  eAV_Value_Inherit,
  eAV_WinnerAF,
  eAV_Value_WinnerAF,
  eAV_Value_Inherit_WinnerAF,
  eAV_Reset_Recurse,
  eAV_All,
  eAV_UpdateEnum_MAX = eAV_All
};

enum eComputeBEMode
{
  NoShowSpace = 0,//0 NoShow Space ComputeBE only for Invalid elements INCluding hidden 
  ShowSpaceInvalidNonHidden,//1 Default. Show Space ComputeBE only for Invalid elements EXCluding hidden 
  ShowSpaceAll,//2 Show Space ComputeBE for ALL elements INCluding  hidden
  ShowSpaceAllNonHidden//3 Show Space ComputeBE for ALL elements EXCluding  hidden
};

enum class ZModeFilterEnum
{
  eNoFilter = -1,
  eFilter_ON,
  eFilter_OFF
};

//moved from l_CATVisFilter
enum VisFilterResult {
  eCompletelyInside = 0,
  eCompletelyOutside = 1,
  eIntersecting = 2,
  eIntersectionTestNotSupported = -1,
};

//enum to describe State of Matrix
enum class MatrixState
{
  eMatrix_NoInit = 0, //Not a state of matrix but can be used it this enum is used but not computed
  eMatrix_Null,       //Null matrix is matrix with all entries 0
  eMatrix_Identity,   // Identity matrix, a[i][j]=1.0 if i=j else 0
  eMatrix_TranslateOnly, // Matrix with only translaton component
  eMatrix_ReflectionOnly, // Matrix with reflection only
  eMatrix_ScaleOnly,  //Matrix with only Scale component and no Translation , a[i][j]!=0 if i=j else 0
  eMatrix_ShearOnly,  // shear matrix: No Translation and  Principal diagonal is all 1 atleast one other entry is non-zero
  eMatrix_TranslateScale, //matrix with translation and scale
  eMatrix_TranslateShear, //Shear matrix as defined above but with translation component
  eMatrix_3x3General, //Non-Identity 3x3 matrix, i.e. 
  eMatrix_RotateOnly,     // Rotation component
  eMatrix_ShearScale,     //Shear and Scale component
  eMatrix_RotateScale,    //Rotation with scale
  eMatrix_TranslateRotate,    //Rotation with Translation
  eMatrix_General     //having all the components- rotation, scale, translation
};

//enum to describe the type of scaling Matrix has.
enum class MatrixScaling
{
  eScaleNoInit = 0,
  eNoScale,
  eUniformScale,
  eNonUniformScale
};

#endif
