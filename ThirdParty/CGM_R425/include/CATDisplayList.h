#ifndef CATDisplayList_H
#define CATDisplayList_H
//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract : CATDisplayList Management
//             
//------------------------------------------------------------------------------
// Usage : 
//     
//------------------------------------------------------------------------------
// Main methods :
//               Add a graphic primitive in a CATDisplayList
//                      AddElem
//                      
//------------------------------------------------------------------------------
// Inheritance : CATDisplayList
//------------------------------------------------------------------------------

#include "SGInfra.h"
#include "CATDataType.h"

#define NB_LIST_3D_WITH_ZDEPTH 12     // Occlusion volume
                                      // Occlusion skin 
                                      // Light Source
                                      // Volume
                                      // Skin
                                      // AlphaTest
                                      // Volume/Skin Transparent
                                      // Outline
                                      // Sparse
                                      // Edge
                                      // Hidden Edge
                                      // Edge Transparent
#define NB_LIST_3D_WITHOUT_ZDEPTH 34  // Other 3D element in 2D mode plane
                                      // Priority 0
                                      // Priority 0+
                                      // Priority 1
                                      // Priority 1+
                                      // Priority 2
                                      // Priority 2+
                                      // Priority 3
                                      // Priority 3+
                                      // Priority 4
                                      // Priority 4+
                                      // Priority 5
                                      // Priority 5+
                                      // Priority 6
                                      // Priority 6+
                                      // Priority 7
                                      // Priority 7+
                                      // Priority 8
                                      // Other 3D elements
                                      // Priority 8+
                                      // Priority 9
                                      // Priority 9+
                                      // Priority 10
                                      // Priority 10+
                                      // Priority 11
                                      // Priority 11+
                                      // Priority 12
                                      // Priority 12+
                                      // Priority 13
                                      // Priority 13+
                                      // Priority 14
                                      // Priority 14+
                                      // Priority 15
                                      // Priority 15+
#define NB_LIST_3D_HIGHLIGHT 2        // Highlight other
                                      // Highlight edge
#define NB_LIST_FURTIVE 2             // Furtive edge
                                      // Furtive elements
#define NB_LIST_2D 17                 // Other 2D elements 
                                      // Transpar Priority 0
                                      // Transpar Priority 1
                                      // Transpar Priority 2
                                      // Transpar Priority 3
                                      // Transpar Priority 4
                                      // Transpar Priority 5
                                      // Transpar Priority 6
                                      // Transpar Priority 7
                                      // Transpar Priority 8
                                      // Transpar Priority 9
                                      // Transpar Priority 10
                                      // Transpar Priority 11
                                      // Transpar Priority 12
                                      // Transpar Priority 13
                                      // Transpar Priority 14
                                      // Transpar Priority 15
#define NB_LIST_SPECIAL 2             // GPGPU //UO4++ 15:04:30 IR-330136 GPPGU DL Added as SPECIAL. This manages its own data unlike other DLs. Only _data[GPPGU].
                                      // Default //Default Moved out of 2D into SPECIAL.

#define NB_LIST_EDGES_WITH_ZDEPTH 3   // Edge
                                      // Hidden Edge
                                      // Edge Transparent

#define NB_ALL_LIST_3D NB_LIST_3D_WITH_ZDEPTH+NB_LIST_3D_WITHOUT_ZDEPTH+NB_LIST_3D_HIGHLIGHT+NB_LIST_FURTIVE
#define NB_LIST 67 // is used to allocate an array  
                   // any modification on this constant 
                   // must be reported to the equivalent constant
                   // defined in CATCullingRender.h
#define NB_LIST_TOTAL NB_LIST+(NB_LIST_SPECIAL-1) //UO4++ 15:04:30 IR-330136 GPPGU DL; 16:03:22 UMR-3292216,17 allocate _data[] for 2D + 3D + GPGPU and not Default
#define NB_BEGIN_LIST_2D (NB_LIST-1)-NB_LIST_2D //UO4++ 15:04:30 IR-330136 GPPGU DL 

enum DisplayListType { DisplayList3D, DisplayList2D };

#include "CATElementType.h"
#include "CATGraphicAttributeSet.h"
#include "CATDisplayListElement.h"
#include <string.h>

#include "list.h"
#include <stdlib.h>


class CATViewpoint;
class CATGraphicMaterial ;
class VisMaterial;
class vIVertexAssembly;
#if defined(_IRIX_SOURCE) || defined(_WINDOWS_SOURCE)
#include "CATListOfInt.h"			
class CATBoundingElement;
#endif

class ExportedBySGInfra CATDisplayList 
{
  //----------------------------------------------------------
public :

  CATDisplayList();
  CATDisplayList(DisplayListType);
  ~CATDisplayList(); 

  // Use AddSpecialState only with following types : CAT_DLE_PUSH_4X4_MATRIX, CAT_DLE_POP_MATRIX, CAT_DLE_PUSH_3X3_MATRIX, CAT_DLE_GRAPHIC_ATTRIBUTE_RGBA, CAT_DLE_GRAPHIC_ATTRIBUTE_SET, CAT_DLE_EYE_POINT
  inline void AddSpecialState(void *elem,const int type);
  inline void AddSpecialState(const int list,void *elem,const int type);

  inline void AddState(void *elem,const int type);
  inline void AddState(const int list,void *elem,const int type);
  inline void AddSpecialGeometry (void *elem, const int type);
  inline void AddSpecialGeometry (const int list,void *elem, const int type);
  inline void AddGeometry (const int list, void *elem, const int type);
  inline void AddGeometries (const int list, void **elem, const int nelem, const int type);
  inline void AddDialogState(const int iSate);
  inline void AddGPGPU(void *elem, const int type); //UO4+ 15:04:30 IR-330136 GPPGU DL  

  void AddStateInheritAttribute (void *elematt1, void *eleminhatt1, void *eleminhatt2);
  void EndStateInheritAttribute(const int list);
  void UpdateStateInheritAttribute(const int list);

  void * DuplicateElem (void *elem, const int elem_size);

  void AddValue (const int list, const int value);

  inline int GetNbElem (const int list);
  inline void **GetList (const int list , const int index);
  inline int *GetTypes (const int list , const int index);

  inline int ContainsGeometry(const int liste);
  inline void SetContainsGeometry(const int liste, const int containsGeometry);

  void Reset();
  inline void * IncreaseSize (const int);

  inline DisplayListType GetDisplayListType() const;
  CATVizElementType GetDefaultList(unsigned int flag = 0) const;

  inline void SetViewpoint(CATViewpoint *);
  inline CATViewpoint *GetViewpoint() ;

  inline CATGraphicAttributeSet *GetLastAttribute (const int liste);
  inline void SetLastAttribute (const int liste, CATGraphicAttributeSet *attr);

  // to manage the texture/material in the culling Draw
  void InitDLForMaterial(int iMatRepSeen,CATGraphicMaterial *iMatRoot);
  CATGraphicMaterial * GetCurrentMaterial(const int iIndDL) const ;
  void SetCurrentMaterial(const int iIndDL, CATGraphicMaterial *iMat) ;

  // to manage the texture/material in the culling Draw
  void InitDLForVisMaterial(int iMatRepSeen,VisMaterial *iMatRoot);
  VisMaterial * GetCurrentVisMaterial(const int iIndDL) const ;
  void SetCurrentVisMaterial(const int iIndDL, VisMaterial *iMat) ;

  inline vIVertexAssembly const* GetCurVAssembly(const int iIndDL) const{return (_data[iIndDL].CurrentAssembly);}
  inline void SetCurVAssembly(const int iIndDL, vIVertexAssembly const* iAss) {_data[iIndDL].CurrentAssembly = iAss;}

  /** @nodoc */
  inline void GetSavedAttrib(CATGraphicAttributeSet& oOut);
  /** @nodoc */
  inline int GetClippingPlanes(float **oPoint, float **oNormal, int *oCappingPlaneFlags);
  /** @nodoc */
  void SetClippingPlanes(int iNbPlanes,float *iPoint, float *iNormal, int iCappingPlaneFlags = 1);
  /** @nodoc */
  inline void SetRepViewMode(int iRVM); //UO4+ 16:09:23 IR-360692 Extended Rep View Modes for TMC using Filter
  /** @nodoc */
  inline void AddRepViewMode(const int liste); //UO4+ 16:09:23 IR-360692 Extended Rep View Modes for TMC using Filter

  /** @nodoc */  

  inline list<void> & GetListOfPrimitive(void);
  //----------------------------------------------------------

  CATULONG32 GetSizeInBytes();


private :

  void ResetDL(int i, bool bConstruct = 0); //UO4+ 15:04:30 IR-330136 GPPGU DL 

  typedef struct DisplayListData
  {
    void**                  Elements;
    CATGraphicMaterial*     CurrentMaterial;
    VisMaterial*            CurrentVisMaterial;
    vIVertexAssembly const* CurrentAssembly;
    int*                    Types;
    int                     NbElements;
    int                     MemNbElements;
    int                     ContainsGeometry;
    int                     HighlightLFlag;
    int                     ColorLFlag;
    int                     LinewidthLFlag;
    int                     LinetypeLFlag;
    int                     BackgroundLFlag;
    int                     AsmColorLFlag;
    int                     AlphaLFlag;
    int                     FilterLFlag;
    int                     TopPriorityLFlag;
    int                     Mode2DLFlag;
  } DISPLAYLISTDATA;

  DISPLAYLISTDATA        _data[NB_LIST_TOTAL];  //UO4+ 15:04:30 IR-330136 :NB_LIST_TOTAL to include GPGPU DL
  CATGraphicAttributeSet _LastAttribute[NB_LIST];
  int                    _InheritanceStateFlag[NB_LIST]; 
  int                    _oldelemInherit1[NB_LIST];
  int                    _oldelemInherit2[NB_LIST];
  int                    _lastAppliedAtt1[NB_LIST];
  int                    _lastAppliedAtt2[NB_LIST];
  int                    _lastNotAppliedAtt1[NB_LIST];
  int                    _lastNotAppliedAtt2[NB_LIST];
  int                    _lastAppliedPriority[NB_LIST];
  int                    _lastNotAppliedPriority[NB_LIST];
  int                    _stateRepViewMode[NB_LIST]; //UO4 RepViewModeExt 22 Aug 2016

  CATGraphicAttributeSet _saveatt;
  int _currentelemInherit1;
  int _currentelemInherit2;
  int _HighlightGFlag;
  int _ColorGFlag;
  int _LinewidthGFlag;
  int _LinetypeGFlag;
  int _BackgroundGFlag;
  int _AsmColorGFlag;
  int _AlphaGFlag;
  int _FilterGFlag;
  int _TopPriorityGFlag;
  int _Mode2DGFlag;
  int _highlight;
  int _color;
  int _linewidth;
  int _linetype;
  int _background;
  int _asmcolor;
  int _alpha;
  int _filter;
  int _toppriority;
  int _2Dmode;
  int _nb_ptr;
  int _max_ptr;
  void **_dupElemPtrs;
  int *_dupElemSizes;
  int _poolOffset, _poolSize;
  char *_pool;
  int   _outOfPoolSize;

  DisplayListType type_;

  CATViewpoint *_viewpoint;

  int   _Clipping;
  int   _ClippingFlags;
  int   _ID;
  float _Clip_point[18];
  float _Clip_normal[18]; 
  
  int _geometryType;
  int _stateRVM; //UO4 RepViewModeExt 22 Aug 2016
  int _RepVM; //UO4 RepViewModeExt 22 Aug 2016
};

//----------------------------------------------------------
//UO4++ RepViewModeExt 22 Aug 2016
inline void CATDisplayList::SetRepViewMode(int iRVM) //Called to set/unset for each Parent Rep with RepViewMode 
{ 
  _RepVM = iRVM; 
  if(0 > iRVM ) 
  {
    _stateRVM = 0; //ToPop
    int nblist = NB_LIST; //NB_ALL_LIST_3D
    int i = 0;
    for (i = 0; i < nblist; i ++)
    {
      if( 1 == _stateRepViewMode[i])
      {
        AddState(i,    (void *) (CATINTPTR)_RepVM, CAT_DLE_REP_VIEW_MODE);
        _stateRepViewMode[i] = 0;
      }
    }
  }
  else 
    _stateRVM = 1; //ToPush
}

inline void CATDisplayList::AddRepViewMode(const int liste) //Called for per DLtype when a geometry is added and _stateRVM != 0
{ 
  if(1== _stateRVM  && 0 == _stateRepViewMode[liste]) 
  {
  AddState(liste,    (void *) (CATINTPTR)_RepVM, CAT_DLE_REP_VIEW_MODE);
  _stateRepViewMode[liste] = 1;
  }
}
//UO4-- RepViewModeExt 22 Aug 2016

// GF8: PLM View mode inheritance fix
inline void CATDisplayList::GetSavedAttrib(CATGraphicAttributeSet& oOut)
{
  oOut=_saveatt;
}
// GF8: PLM View mode inheritance fix
inline CATGraphicAttributeSet *CATDisplayList::GetLastAttribute (const int liste)
{
  return (&(_LastAttribute[liste]));
}

inline void CATDisplayList::SetLastAttribute (const int liste, CATGraphicAttributeSet *attribut)
{
  _LastAttribute[liste] = *attribut;
}

inline DisplayListType CATDisplayList::GetDisplayListType() const
{
  return (type_);
}

inline int CATDisplayList::GetNbElem ( const int liste )
{
  return _data[liste].NbElements;
}

inline int* CATDisplayList::GetTypes( const int liste, const int index )
{
  return (&(_data[liste].Types[index]));
}

inline void ** CATDisplayList::GetList ( const int liste, const int index )
{
  return (&(_data[liste].Elements[index]));
}

inline int CATDisplayList::ContainsGeometry(const int liste)
{
  return (_data[liste].ContainsGeometry);
}

inline void CATDisplayList::SetContainsGeometry(const int liste, const int containsGeometry)
{
  _data[liste].ContainsGeometry = containsGeometry;
}


inline void CATDisplayList::SetViewpoint(CATViewpoint *viewpoint)
{
  _viewpoint = viewpoint;
}

inline CATViewpoint * CATDisplayList::GetViewpoint() 
{
  return _viewpoint;
}

inline void CATDisplayList::AddState ( const int liste, void *elem, const int type)
{
  if (_data[liste].NbElements == _data[liste].MemNbElements)
  {
    void *ret=IncreaseSize (liste);
    if (!ret) return;
  }

  int index = _data[liste].NbElements;
  _data[liste].Elements[index] = elem;
  _data[liste].Types[index] = type;
  _data[liste].NbElements++;

}

inline void CATDisplayList::AddState (void *elem, const int type)
{
  if ( type_ == DisplayList3D )
  {
    int nblist = NB_ALL_LIST_3D;
    // On n'ajoute rien dans la liste des LIGHT_SOURCE
    int i = 0;
    for (i = VOLUME; i < nblist; i ++)
    {
      if (_data[i].NbElements == _data[i].MemNbElements)
      {
        void *ret=IncreaseSize (i);
        if (!ret) return;
      }

      int index = _data[i].NbElements;
      _data[i].Elements[index] = elem;
      _data[i].Types[index] = type;
      _data[i].NbElements++;
    }
  }
  else
  {
    for ( int i = NB_BEGIN_LIST_2D; i < NB_LIST; i ++)//UO4 15:04:30 IR-330136 GPPGU DL
    {
      if (_data[i].NbElements == _data[i].MemNbElements)
      {
        void *ret=IncreaseSize (i);
        if (!ret) return;
      }

      int index = _data[i].NbElements;
      _data[i].Elements[index] = elem;
      _data[i].Types[index] = type;
      _data[i].NbElements++;
    }
  }
}

inline void * CATDisplayList::IncreaseSize (const int liste)
{
  void *ret=NULL;
  int new_max_elem = _data[liste].MemNbElements*2;

  ret = realloc(_data[liste].Elements, new_max_elem*sizeof(void *));

  if (ret)
  {
    _data[liste].Elements = (void **) ret;
  }
  else
  {
    return NULL;
  }

  ret = realloc(_data[liste].Types, new_max_elem*sizeof(int));

  if (ret)
  {
    _data[liste].Types = (int *) ret;
  }
  else
  {
    return NULL;
  }

  _data[liste].MemNbElements = new_max_elem;

  return ret;
}

inline void CATDisplayList::AddSpecialState (void *elem, const int type)
{
  if ( type_ == DisplayList3D )
  {
    //Pas de priority dans les displaylist 3D
    if (type == CAT_DLE_PRIORITY) return;

    // On n'ajoute rien dans la liste des LIGHT_SOURCE
    for (int i = VOLUME; i < NB_ALL_LIST_3D; i ++)
    {
      AddSpecialState (i, elem, type);
    }
  }
  else
  {
    for ( int i = NB_BEGIN_LIST_2D; i < NB_LIST; i ++)//UO4 15:04:30 IR-330136 GPPGU DL
    {
      AddSpecialState (i, elem, type);
    }
  }
}

inline void CATDisplayList::AddSpecialState ( const int liste, void *elem, const int type )
{
  if (_data[liste].NbElements == _data[liste].MemNbElements)
  {
    void *ret=IncreaseSize (liste);
    if (!ret) return;
  }

#ifdef DEBUG
  if(liste == 4)
  {
    if(_data[liste].NbElements > 0)
    {
      printf("%d %d %d\n", _data[liste].NbElements, type, _data[liste].Types[_data[liste].NbElements-1]);
    }
    else
    {
      printf("%d %d\n", _data[liste].NbElements, type);
    }
  }
#endif

  // Cas du PopMatrix et des elements precedents
  if (type == CAT_DLE_POP_MATRIX)
  {
    // PushMatrix2D/3D (CAT_DLE_PUSH_4X4_MATRIX ou CAT_DLE_PUSH_3X3_MATRIX)
    if (_data[liste].Types[(_data[liste].NbElements - 1)] == CAT_DLE_PUSH_4X4_MATRIX || _data[liste].Types[(_data[liste].NbElements - 1)] == CAT_DLE_PUSH_3X3_MATRIX)
    {
      _data[liste].NbElements--;
      return;
    }
    else if (_data[liste].Types[(_data[liste].NbElements - 1)] == CAT_DLE_EYE_POINT )
    {
      if ( _data[liste].NbElements >= 2 && _data[liste].Types[(_data[liste].NbElements - 2)] == CAT_DLE_PUSH_4X4_MATRIX )
      {
        _data[liste].NbElements -= 2;
        return;
      }
    }
    else if (_data[liste].Types[(_data[liste].NbElements - 1)] == CAT_DLE_EYE_POINT && _data[liste].Types[(_data[liste].NbElements - 2)] == CAT_DLE_PUSH_4X4_MATRIX)
    {
      _data[liste].NbElements -= 2;
      return;
    }
  }
  else if ( _data[liste].NbElements >= 0 )
  {
    // On supprime les attributs qui precedent un attribut
    if ( type == CAT_DLE_GRAPHIC_ATTRIBUTE_RGBA  )
    {
      _lastNotAppliedAtt1[liste] = CATPtrToINT32(elem);
      return;

    }
    else if ( type == CAT_DLE_GRAPHIC_ATTRIBUTE_SET  )
    {
      _lastNotAppliedAtt2[liste] = CATPtrToINT32(elem);
      return;

    }
    else if ( type == CAT_DLE_PRIORITY )
    {
      _lastNotAppliedPriority[liste] = CATPtrToINT32(elem);
      return;
    }
    // On supprime les vertexbuffer qui precedent un vertexbuffer
    else if ( type == CAT_DLE_VERTEX_BUFFER &&  _data[liste].NbElements > 0 )
    {
      if ( _data[liste].Types[(_data[liste].NbElements - 1)] == CAT_DLE_VERTEX_BUFFER )
      {
        _data[liste].NbElements--;
      }
    }
  }

  int index = _data[liste].NbElements;
  _data[liste].Elements[index] = elem;
  _data[liste].Types[index] = type;
  _data[liste].NbElements++;
}

inline void CATDisplayList::AddSpecialGeometry ( void *elem, const int type)
{
  if ( type_ == DisplayList3D )
  {
    int nblist = NB_ALL_LIST_3D;
    // On n'ajoute rien dans la liste des LIGHT_SOURCE
    int i = 0;
    for (i = VOLUME; i < nblist; i ++)
    {
      AddSpecialGeometry( i, elem, type);
    }
  }
  else
  {
    for ( int i = NB_BEGIN_LIST_2D; i < NB_LIST; i ++)//UO4 15:04:30 IR-330136 GPPGU DL
    {
      AddSpecialGeometry( i, elem, type);
    }
  }
}

inline void CATDisplayList::AddSpecialGeometry ( const int liste, void *elem, const int
 type)
{

  UpdateStateInheritAttribute(liste);

  if (_data[liste].NbElements == _data[liste].MemNbElements)
  {
    void *ret=IncreaseSize (liste);
    if (!ret) return;
  }

  int index = _data[liste].NbElements;
  _data[liste].Elements[index] = elem;
  _data[liste].Types[index] = type;
  _data[liste].NbElements++;
}

inline void CATDisplayList::AddGeometry ( const int liste, void *elem, const int
 type)
{
  _data[liste].ContainsGeometry = _geometryType;
  if(_stateRVM)
    AddRepViewMode(liste);
  UpdateStateInheritAttribute(liste);

  if (_data[liste].NbElements == _data[liste].MemNbElements)
  {
    void *ret=IncreaseSize (liste);
    if (!ret) return;
  }

  int index = _data[liste].NbElements;
  _data[liste].Elements[index] = elem;
  _data[liste].Types[index] = type;
  _data[liste].NbElements++;
}

inline void CATDisplayList::AddGeometries ( const int liste, void **elemL, const int nelem, const int type )
{
  _data[liste].ContainsGeometry = _geometryType;
  if(_stateRVM)
    AddRepViewMode(liste);
  UpdateStateInheritAttribute(liste);

  while ((_data[liste].NbElements + nelem) >= _data[liste].MemNbElements)
  {
    void *ret = IncreaseSize (liste);
    if (!ret) return;
  }

  int i;
  void** elemi;
  void** elemp;
  int* typep;

  elemi = &(elemL[nelem-1]);
  elemp = &(_data[liste].Elements[_data[liste].NbElements]);
  typep = &(_data[liste].Types[_data[liste].NbElements]);

  for( i = (nelem-1) ; i >= 0 ; i-- )
  {
    *elemp++ = *elemi--;
    *typep++ = type;
  }

  _data[liste].NbElements += nelem;

}

inline int CATDisplayList::GetClippingPlanes(float **oPoint, float **oNormal, int *oCappingPlaneFlags)
{
  *oPoint  = _Clip_point;
  *oNormal = _Clip_normal;

  *oCappingPlaneFlags   = _ClippingFlags;

  return (_Clipping);
}

inline void CATDisplayList::AddDialogState(const int iState)
{
  AddState((void *) (CATINTPTR)iState, CAT_DLE_DIALOG);

  if (iState) 
  {
    _geometryType = 2;
  }
  else
  {
    _geometryType = 1;
  }
}

//UO4+ 15:04:30 IR-330136 GPPGU DL 
inline void CATDisplayList::AddGPGPU (void *elem, const int type)
{
  _data[GPGPU].ContainsGeometry =_geometryType;

  
  if(_data[GPGPU].NbElements == _data[GPGPU].MemNbElements)
  {
    void *ret=IncreaseSize (GPGPU);
    if (!ret) return;
  }

  int index = _data[GPGPU].NbElements;
  _data[GPGPU].Elements[index] = elem;
  _data[GPGPU].Types[index] = type;
  _data[GPGPU].NbElements++;
}
//UO4- 15:04:30 IR-330136 GPPGU DL 

#endif
