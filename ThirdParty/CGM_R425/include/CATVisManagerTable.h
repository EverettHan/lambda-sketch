#ifndef CATVisManagerTable_h
#define CATVisManagerTable_h

#include "SceneGraphManager.h"
#include "CATBaseUnknown.h"
#include "CATPathElement.h"
#include "CATLayerFilter.h"
#include "CATNotificationDispatcher.h"
#include "SortedList.h"
#include "CATRepPath.h"
#include "CATVisCrossHighlight.h"

 
class CATViewer;
class CATPathElementRep;
class CATManipulator;
class CATCellTableVisManager;
class CATXSOTable;
class CATViewpointTable;
class CATVisManagerTable;
class CATXSO;
class CAT2DBagRep;
class CAT2DCustomRep;
class CATUnicodeString;
class CATSelector;

/*
 *  @quickReview cdt 02:08:07
 */


//
//********************************************************************
// CATIA Version 5 Release 2 Framework Visualization
// Copyright Dassault Systemes 1997
//********************************************************************
//
//  Abstract:
//  ---------
/**
 *    This is the master structure of the Visu Manager
 *
 */
//
//********************************************************************
//
//  Usage:  is used to manage a graphic vue from a container
//  ------ 
//
//********************************************************************
//
//  Inheritance:
//  ------------
//                CATTableVisManager
//                  
//
//********************************************************************
//
//  Main Methods:
//  -------------
//
//********************************************************************
//
//History : SRX april 2001 changed initialisation of _HSOConnected to 1
//                         and of _PSOConnected to 1.



enum CATVisManagerCellState {CATVisShowOnly, CATVisShowAndNoshow, CATVisNoshowOnly};

enum CATVisManagerCellComparison { COMPARE_IID_LIST };


// enlever cette remarque pour avoir le SetCurrentCell en mode debug/verbose
//#define _DEBUG_CURRENT_CELL

// WeakRef
class CATCellTableVisManagerWeakRef;

/**
* Class used to create a sorted list to keep all links Model/Visu
* managed by the visu manager
* 
* This class must be used only by CATVisManagerTable
*
*/
class CATCellTableVisManager
{

  /** @nodoc */
  friend class CATCellTableVisManagerWeakRef;

public:

  CATCellTableVisManager ( CATBaseUnknown*   iRootModel,
                           CATPathElement*   iTreeRoot,
                           CATBaseUnknown* i_pViewObject,
                           list<IID>&  	     iVisuList,
                           int iFurtive = 0,
                           int iLocalMatrix = 0,
                           int iLocalGraphicAttributs = 0,
                           CATVisCrossHighlight iCrossHighlight = 0,
                           int iEmbedded = 0);


  ~CATCellTableVisManager ();


  void SetState(CATVisManagerCellState iState);

  int IsEqualTo(const CATCellTableVisManager& iCell, CATVisManagerCellComparison eComparison) const;

   /**
   * @nodoc 
   * Returns a weak reference on the CATCellTableVisManagerWeakRef.
   * The <tt>Release</tt> method must be called on the weak reference when useless.
   * @return
   * A pointer to a <tt>CATCellTableVisManagerWeakRef</tt>.
   */
   CATCellTableVisManagerWeakRef* GetWeakRef( void );
  
  // Key of the cell
  CATBaseUnknown*   _RootModel;
  CATBaseUnknown*   _Viewpoint;
  list<IID>         _VisuList;

  // informations
  CATSelector*      _Selector;
  CATPathElement*   _TreeRoot;
  CATRep*	    _GraphicModel;
  CATLayerFilter*   _LayerFilter;
  
  // pso/hso 
  CATXSO *          _Hso;
  CATXSO *          _Pso;

  //State of the cell
  CATVisManagerCellState _State;

  // evenements
  CATCallback                 _ModelCallback;
  CATNotificationDispatcher*  _ModelDispatcher;

  // binaries informations (don't explode this group !)
  unsigned int      _VisuConnected           : 1;
  unsigned int      _ShowMode                : 1;
  unsigned int      _HSOConnected            : 1;
  unsigned int      _PSOConnected            : 1;
  unsigned int      _FurtiveMode             : 1;
  unsigned int      _LocalMatrix             : 1;
  unsigned int      _LocalGraphicAttributs   : 1;
  unsigned int      _IsViewpoint3D           : 1;
  unsigned int      _InhibFurtiveDraw        : 1;
  unsigned int      _IsVisuMode              : 1;
  unsigned int      _IsEmbedded              : 1;
  

  // links to others cells
  CATCellTableVisManager* _PreviousCell;
  CATCellTableVisManager* _NextCell;


  // pour debugger
  list<CATUnicodeString> * Trace (int withHeader = 0 );
  CATVisCrossHighlight _crossHighlight;

protected:

  CATCellTableVisManagerWeakRef* _pWeakRef;


private:  
  
  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATCellTableVisManager ();
  CATCellTableVisManager (const CATCellTableVisManager &);
  CATCellTableVisManager & operator= (const CATCellTableVisManager &);

  /** @nodoc */
  void UnreferenceWeakRef( void );

};

#include "CATWeakRefTemplate.h"
#define NoExport 
// NoExport est vide car la classe n'est pas exportee au niveau de la dll.
// Dans le cas contraire, mettre ExportedByXXX en parametre dans la macro.
DeclareWeakRef(CATCellTableVisManager, NoExport);
#undef NoExport


///////////////////////////////////////////////////////////


/**
*
* Class that manage a list of adresses of viewpoints to access
* quickly to all the entries of the Visu Manager for a given viewpoint
*
* This class must be used only by CATVisManagerTable
*
*/
class CATViewpointTable
{

public:
  CATViewpointTable ();

  ~CATViewpointTable ();


  // !! on ne verifie pas que la cellule y est deja
  // c'est voulu pour des raisons de perfos
  void operator += (CATCellTableVisManager* iCell);
  void operator -= (CATCellTableVisManager* iCell);

  list<CATCellTableVisManager>*  GetAssociatedListOfCells (CATBaseUnknown* i_pViewObject);

  CATCellTableVisManager*        GetAssociatedFirstCell (CATBaseUnknown* i_pViewObject);

  //permet de savoir si il y a eu plusieurs viewpoint d'attaches.
  //Souvent plusieurs viewpoint signifient qu'il y a plusieurs fenetres.
  int HasSeveralVpt();
  //permet de recuperer la liste de toutes les cellules sans exception.
  HRESULT GiveAllCells(list<CATCellTableVisManager> & oListeCell);

  //permet de recuperer la liste de toutes les cellules sans exception.
  HRESULT GiveAllListeningCells(list<CATCellTableVisManager> & oListeCell);

  HRESULT GiveEmbeddedCells(list<CATCellTableVisManager> & oListeCell);
  // pour debugger
  void Trace ();
  CAT2DCustomRep* BuildRep (float iX=0, float iY=0);

private:
  int Search (CATBaseUnknown* i_pViewObject);
  int SearchExact (CATBaseUnknown* i_pViewObject);

  CATViewpointTable (const CATViewpointTable &);
  CATViewpointTable & operator= (const CATViewpointTable &);

  CATBaseUnknown** _Viewpoints;
  list<CATCellTableVisManager>** _Cells;
  int _Size;
  int _MemSize;
};

///////////////////////////////////////////////////////////

/**
*
* Class that manage a list of adresses of hso/pso to access
* quickly to all the entries of the Visu Manager for a given hso/pso
*
* This class must be used only by CATVisManagerTable
*
*/
class CATXSOTable
{
public:
  CATXSOTable();
  ~CATXSOTable();

  int Add(CATXSO *iXso, CATCellTableVisManager* iCell);
  int Rem(CATXSO *iXso, CATCellTableVisManager* iCell);
  list<CATCellTableVisManager>*  GetAssociatedListOfCells (CATXSO *iXso);

  // pour debugger
  CAT2DCustomRep* BuildRep (float iX=0, float iY=0);

  int SearchExact (CATXSO* iXso);

private:
  int Search(CATXSO *iXso);
  

  CATXSOTable (const CATXSOTable &);
  CATXSOTable & operator= (const CATXSOTable &);

  CATXSO** _Xso;
  list<CATCellTableVisManager>** _Cells;
  int _Size;
  int _MemSize;



};

///////////////////////////////////////////////////////////

/**
*
* For one cell of the VisManager, this class holds in some informations 
* about all the fathers of one element along with the corresponding reppathes
* 
* This class must only be used by CATVisManager
*
*/
class CATFatherTable
{
public:
  CATFatherTable();
  int Add(CATBaseUnknown  *ifather,CATRepPath *irp);
  int Add(CATCellTableVisManager *iCell);
  int Rem(CATCellTableVisManager *iCell);
  void Reset();
   /*
  *
  *RETURN :  the disconnected cell of the VisManager 
  *       
  */
  inline CATBaseUnknown *GetFather(void);
   /*
  *
  *RETURN :  the disconnected cell of the VisManager 
  *       
  */
  inline CATRepPath *GetRepPath(void);
  /*
  *
  *RETURN :  the disconnected cell of the VisManager 
  *       
  */
  inline CATCellTableVisManager *GetCell(void);


private:

  CATFatherTable (const CATFatherTable &);
  CATFatherTable & operator= (const CATFatherTable &);

  CATBaseUnknown * _Father;
  CATRepPath * _RepPath;
  CATCellTableVisManager *_DisconnectedCell;
};

inline CATBaseUnknown *CATFatherTable::GetFather(void){ return _Father;}
inline CATRepPath *CATFatherTable::GetRepPath(void){ return _RepPath;}
inline CATCellTableVisManager *CATFatherTable::GetCell(void){ return _DisconnectedCell;}



///////////////////////////////////////////////////////////

/**
*
* For one element, this class holds in the list of cells where it is drawn in furtive mode
*
* 
* This class must only be used by CATVisManager
*
*/
class CATFurtiveCellTable  : public  SortedList
{
};



/**
*
* This class holds in the list of elements that are drawn in furtive mode
*
* 
* This class must only be used by CATVisManager
*
*/
class CATDrawFurtiveTable  : public  SortedList
{
};




///////////////////////////////////////////////////////////


/**
*
* Class that manage a list of adresses of CATNotificationDispatcher to access
* quickly to all the entries of the Visu Manager for a given Dispatcher
*
* This class must be used only by CATVisManagerTable
*
*/
class CATModelCallbackTable
{

public:
  CATModelCallbackTable ();

  ~CATModelCallbackTable ();


  void operator += (CATCellTableVisManager* iCell);
  void operator -= (CATCellTableVisManager* iCell);

  CATCellTableVisManager* operator [] (CATCallback& iCallback);

  
  // pour debugger
  void Trace ();
  CAT2DCustomRep* BuildRep (float iX=0, float iY=0);


private:
  //int Search (CATNotificationDispatcher* iDispatcher);
  //int SearchExact (CATNotificationDispatcher* iDispatcher);
  int Search (CATCallback& iCallback);
  int SearchExact (CATCallback& iCallback);
  CATModelCallbackTable (const CATModelCallbackTable &);
  CATModelCallbackTable & operator= (const CATModelCallbackTable &);


 // CATNotificationDispatcher** _Dispatchers;
  CATCallback*                _Callbacks;
  CATCellTableVisManager**   _Cells;
  int _Size;
  int _MemSize;
};


///////////////////////////////////////////////////////////

/**
*
* Class that manage a list of manipulators added for a given viewer 
*
*
*/
class CATManipulatorOnPathTable
{
public:
  CATManipulatorOnPathTable();
  ~CATManipulatorOnPathTable();

  int Add (CATViewer* iViewer, CATPathElementRep* iPathElementRep);
  int Rem (CATViewer* iViewer, CATPathElementRep* iPathElementRep);
  int Rem (CATViewer* iViewer, CATPathElement& iPathElement, CATManipulator* iManipulator, CATPathElementRep*& oPathRep);
  int Rem (CATPathElementRep* iPathElementRep);

  int Exist (CATViewer* iViewer, CATPathElement& iPathElement, CATManipulator* iManipulator=NULL);

  list<CATPathElementRep>* GiveAll ();

  // pour debugger
  CAT2DCustomRep* BuildRep (float iX=0, float iY=0);

private:
  int Search (CATViewer* iViewer);
  int SearchExact (CATViewer* iViewer);
  CATManipulatorOnPathTable (const CATManipulatorOnPathTable &);
  CATManipulatorOnPathTable & operator= (const CATManipulatorOnPathTable &);

  CATViewer** _Viewers;
  list<CATPathElementRep>** _PathElementRep;
  int _Size;
  int _MemSize;
};


///////////////////////////////////////////////////////////


/**
*
* Class that manage the master table of the Visu manager
* 
* This table keep all links between models and visu, and
* all specifics informations on theses links
*
*/
class ExportedBySceneGraphManager CATVisManagerTable
{

public:

  CATVisManagerTable ();

  ~CATVisManagerTable ();

  // fonction de gestion de la table

  CATCellTableVisManager* Add ( CATBaseUnknown* iRootModel,
                                CATPathElement* iTreeRoot,
                                CATBaseUnknown*	i_pViewObject,
                                list<IID>&      iVisuList,
                                int iFurtive = 0,
                                int iLocalMatrix = 0,
                                int iLocalGraphicAttributs = 0,
                                CATVisCrossHighlight iCrossHighlight = 0,
                                int iEmbedded = 0);

  void SetCallback ( CATCellTableVisManager* iCell, 
                        CATCallback& iModelCallback,
                        CATNotificationDispatcher*  iModelDispatcher );

  HRESULT Remove ( CATPathElement* iTreeRoot,
			      	    CATBaseUnknown*	i_pViewObject );

  HRESULT Remove ( CATCellTableVisManager* iCell );



  HRESULT SetVisuConnected  ( CATPathElement* 	iTreeRoot,
				                     CATBaseUnknown*	  i_pViewObject, int set );

  HRESULT SetShowMode       ( CATBaseUnknown*	  i_pViewObject, int set );

  HRESULT SetHSOConnected   ( CATPathElement* 	iTreeRoot,
				                     CATBaseUnknown*	  i_pViewObject, int set );

  HRESULT SetPSOConnected   ( CATPathElement* 	iTreeRoot,
				                     CATBaseUnknown*	  i_pViewObject, int set );

  HRESULT SetFurtiveMode    ( CATPathElement* 	iTreeRoot,
				                     CATBaseUnknown*	  i_pViewObject, int set );

  HRESULT SetLocalMatrix    ( CATPathElement* 	iTreeRoot,
				                     CATBaseUnknown*	  i_pViewObject, int set );

  HRESULT SetLocalGraphicAttributs ( CATPathElement* 	iTreeRoot,
				                            CATBaseUnknown*	    i_pViewObject, int set );

  HRESULT SetLayerFilter    ( CATBaseUnknown*	  i_pViewObject,
                             CATLayerFilter*	iFilter );



  int GetVisuConnected  ( CATPathElement* 	iTreeRoot,
                          CATBaseUnknown*	    i_pViewObject );

  int GetShowMode       ( CATBaseUnknown*	    i_pViewObject );

  int GetHSOConnected   ( CATPathElement* 	iTreeRoot,
				                  CATBaseUnknown*	    i_pViewObject );

  int GetPSOConnected   ( CATPathElement* 	iTreeRoot,
				                  CATBaseUnknown*	    i_pViewObject );

  int GetFurtiveMode    ( CATPathElement* 	iTreeRoot,
				                  CATBaseUnknown*	    i_pViewObject );

  int GetLocalMatrix    ( CATPathElement* 	iTreeRoot,
				                  CATBaseUnknown*	    i_pViewObject );

  int GetLocalGraphicAttributs ( CATPathElement* 	iTreeRoot,
				                         CATBaseUnknown*	  i_pViewObject );

  CATLayerFilter*	GetLayerFilter     ( CATBaseUnknown*	  i_pViewObject );

  CATRep*	        GetGraphicModel     ( CATPathElement* iTreeRoot,
                                              CATBaseUnknown*   i_pViewObject,
                                              list<IID>*      iVisuList );


  // fonctions de recherche

  CATCellTableVisManager* Search ( CATBaseUnknown* iRootModel );

  CATCellTableVisManager* Search ( CATPathElement* iTreeRoot,
                                    CATBaseUnknown*	  i_pViewObject=NULL,
                                    list<IID>*      iVisuList  = NULL );

  CATCellTableVisManager* SearchGenerate ( CATPathElement* iTreeRoot,
                                    CATBaseUnknown*	  i_pViewObject=NULL,
                                    list<IID>*      iVisuList  = NULL );

 /**  
  *  @nodoc
  *  Retrieves the all cells corresponding to a given PathElement and Viewpoint <br>
  *  <br>
  *  <b>Role</b>: Given i_pViewObject, this method retrieves all the cells whose _TreeRoot is a sub-path of iPath.<br>
  *  <br> 
  *  Note:<br>
  *       <ul>              
  *         <li>This method has been designed in order to be used by GenerateRepPathFromPathElement() when SearchGenerate() fails (e.g. some 2DLayout scenarios).</li>
  *       </ul>
  *       <br>
  *  <br>
  *  @param   iPath
  *         The PathElement which contains the TreeRoot of an attached cell as a sub-path.<br>
  *  <br>
  *  @param   i_pViewObject
  *         The Viewpoint of the cells to search for.<br>
  *  <br>
  *  @param   oCells
  *         The retrieved list of cells.<br>
  *         Note:<br>
  *       <ul>              
  *         <li>If more than one cell is returned, the first one should be used for backwards compatibility with GenerateRepPathFromPatheElement() (i.e. 1 Path -> 1 RepPath).</li>
  *         <li>This list is emptied if the search fails.</li>
  *       </ul>
  *       <br>
  *  <br>         
  *  @return 
  *         <ul>
  *           <li>S_OK if the the cells have been succesfully retrieved.</li>
  *           <li>E_FAIL if no corresponding cell could be retrieved. This may happen if no corresponding cell exists.</li>  
  *           <li>E_INVALIDARG if <tt>iPath</tt> is NULL.</li>
  *           <li>E_INVALIDARG if <tt>i_pViewObject</tt> is NULL.</li>    
  *           <li>E_INVALIDARG if <tt>oCells</tt> is not empty.</li>
  *         </ul>
  *         <br>
  */  
  HRESULT SearchCellsWithTreeRootInPath ( CATPathElement* iPath,
                                          CATBaseUnknown* i_pViewObject,
                                          list<CATCellTableVisManager> & oCells);


  CATCellTableVisManager* Search ( CATCallback&  iCallback );


  CATCellTableVisManager* SearchFirst ( CATBaseUnknown*	i_pViewObject=NULL );

  list<CATCellTableVisManager>*  SearchAll ( CATBaseUnknown*	i_pViewObject );

  HRESULT SearchAll(CATBaseUnknown *iRootModel, list<CATCellTableVisManager> & oListeCell);

  int HasSeveralVpt();
  HRESULT GiveAllCells(list<CATCellTableVisManager> & oListeCell);
  HRESULT GiveAllListeningCells(list<CATCellTableVisManager> & oListeCell);

  
  int AreThereEmbeddedCells();

  HRESULT GiveEmbeddedCells(list<CATCellTableVisManager> & oListeCell);

  // pour debugger
  void Trace ();
  CAT2DBagRep* BuildRep (float iX=0, float iY=0, int iCallbackTable=1, int i_pViewObjectTable=1);
  
#ifdef _DEBUG_CURRENT_CELL
  void VerifyCurrentCell(CATCellTableVisManager * iCell);
#endif

private:

  int CompareListVisu (list<IID>& iId1, list<IID>& iId2);
  CATVisManagerTable (const CATVisManagerTable &);
  CATVisManagerTable & operator= (const CATVisManagerTable &);


  // donnees propres a la liste chainee
  CATCellTableVisManager* _FirstCell;
  CATCellTableVisManager* _LastCell;
  unsigned int             _TableSize;

  // structures complementaires pour accelerer les recherches
  CATViewpointTable        _ViewpointTable;
  CATModelCallbackTable    _CallbackTable;
  int _embeddedCells;

};


#endif


