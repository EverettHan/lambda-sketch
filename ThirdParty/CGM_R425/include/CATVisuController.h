#ifndef CATVisuController_H
#define CATVisuController_H
/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/
/*
//**********************************************************************
//  CATIA Version 5 Release 1 Framework VFW2
//  Copyright Dassault Systemes 1996
//**********************************************************************
//  Abstract:
//  ---------
//    This object is the masterpiece of the MVC architecture and ensures that
//    communication between the model and the vues are made possible.
//
//**********************************************************************
//  Usage:   
//  ------
//
//**********************************************************************
//  Inheritance:
//  ------------
//                CATVisuController
//                  CATEventSubscriber (SYSTEM Framework).
//
//**********************************************************************
//  Main Methods:
//  -------------
//            Set and Get evaluation primitive mode
//               SetPrimitiveEvaluationMode
//               GetprimitiveEvaluationMode
//            Visualization runtime settings (LODs, Textures, Edges)
//            Editing methods
//               New
//               Delete
//               Modify
//               SetHighlightMode
//               SetShowMode
//               ModifyColor
//               BuildRep
//               AddManip
//               AddManipOnPath
//               RemoveManip
//               RemoveManipOnPath
//            Multi viewer management
//               AddViewer
//               RemoveViewer
//            Decode graphic management (selection)
//               static DecodeNextGraphicElement
//               (protected) DecodeGraphic
//            Class information
//               InitClassList()
//               GetNextClassElement()
//----------------------------------------------------------------------------
//       
*/

#include "SceneGraphManager.h"
#include "list.h"
#include "CATEventSubscriber.h"
//#include "CATVue.h"
#include "CATRepPath.h"
#include "CATDisplayType.h"

class CAT4x4Matrix;
class CAT3x3Matrix;
class CATRep;
//class CATRepTable;
class CATViewer;
class CATModelIdentificator;
class CATManipulator;
class CATRepPath;
class CATViewer;
class CATPickPath;
class CATPSO;
class CATHSO;
class CATNotificationDispatcher;
class CATPathElement;
class CATPathElementRep;
class CATHLRVisuOutputMaker;
class CATHLRPlaneView;
class CATColorMap;
class CATVisuController;
class CATBaseUnknown;

//   useful define
#define DIRECT_ACCESS_TABLE  1

#include "DefineCst.h"
#include "CATGenerativeAttribute.h"


class ExportedBySceneGraphManager CATVisuController : public CATEventSubscriber
{
  friend class CATMarshallableVisuController ;
  CATDeclareClass;

  public:
  ///////


  CATVisuController();
  virtual ~CATVisuController();


  //  Set/Get Controller type 3D or 2D for instance
  //  ---------------------------------------------
  virtual void  SetType(VisuType itype);
  virtual VisuType GetType() const;
  

  // Current Set of Object management
  // --------------------------------
  virtual void AttachToPSO (CATPSO *);
  virtual void DetachFromPSO (CATPSO *);
  virtual void AttachToHSO (CATHSO *);
  virtual void DetachFromHSO (CATHSO *);
  virtual void CsoAddElements(const ::list<CATPathElement> &, CATInteractiveContext);
  virtual void CsoAddElement (const CATPathElement &, CATInteractiveContext);
  virtual void CsoRemoveElement (const CATPathElement &, CATInteractiveContext);
  virtual void CsoRemoveElements(const ::list<CATPathElement> &, CATInteractiveContext);
  virtual CATRepPath * CreateOperationElementRepresentation ( const CATPathElement &,
                                                      CATInteractiveContext,
                                                      CATGenerativeAttribute);
  virtual HRESULT BuildHighlightLook ( CATRep &iRep,
                              const CATPathElement	&iPathElement,
		                          CATRepPath &oRepPath );

  virtual HRESULT BuildRepPath ( CATRep &iRep,
                        const CATPathElement &iPathElement,
		                    CATRepPath &oRepPath );
 
  virtual CATPathElement GetModelLocalization ( CATBaseUnknown * );

   // model events management
   // -----------------------
   virtual void AttachToModelDispatcher (CATNotificationDispatcher *);
   virtual void DetachFromModelDispatcher (CATNotificationDispatcher *);
   virtual void SomethingHappensInPSO(CATCallbackEvent, void *, 
                                      CATNotification *, CATSubscriberData, 
                                      CATCallback);
   virtual void SomethingHappensInHSO(CATCallbackEvent, void *, 
                                      CATNotification *, CATSubscriberData, 
                                      CATCallback);
   virtual void SomethingHappens(CATCallbackEvent, void *, CATNotification *, 
                                 CATSubscriberData, CATCallback);
  
  
  // Settings for usage of some important parameters:
  // ------------------------------------------------
  //   At this point, decision may be taken whether to use data corresponding
  //   to the managed parameter or not. If the data is not used, the parameter
  //   won't be accessible for the whole session duration, unless .cgr files are
  //   loaded again entirely, or the parameter is generated again. 1: OK, 0: NO.
  
  static void SetLODUsageMode     (int use_mode);
  static void SetTextureUsageMode (int use_mode);
  static void SetEdgeUsageMode    (int use_mode);
  static int GetLODUsageMode     (void);
  static int GetTextureUsageMode (void);
  static int GetEdgeUsageMode    (void);
  
  
  //  graphic model
  //  -------------
  virtual  CATRep * GetGraphicModel() const;
  virtual void SetGraphicModel(CATRep *iRep);


  //  graphic table
  //  -------------
  //virtual void SetAssociatedGraphicTable(CATRepTable *iTable);
  //virtual CATRepTable * GetAssociatedGraphicTable() const;
  virtual void SetRepInGraphicTable(CATRep *iRep,CATModelIdentificator &iIdent);
  virtual CATRep *GetRepFromGraphicTable(CATModelIdentificator &iIdent ) const;
  virtual CATRep * IsRepExisting(const CATModelIdentificator &iIdent);
  virtual void SetNewIdentificator(CATRep *ioRep);


  //  dynamic behavior
  //  ----------------
  virtual void UnreferenceRep(CATModelIdentificator &iIdent);
  virtual CATRep *GetRep(const CATModelIdentificator &iIdent) const; 
  virtual CATRep * BuildRep(CATModelIdentificator &iIdent);
  virtual void New( CATModelIdentificator &son, CATModelIdentificator &object);
  virtual void Delete ( CATModelIdentificator &iIdent);
  virtual void Modify (CATModelIdentificator &iIdent);
  virtual void ModifyMatrix(CATModelIdentificator &iIdent,CAT4x4Matrix &iMat);
  virtual void ModifyMatrix(CATModelIdentificator &iIdent,CAT3x3Matrix &iMat);
  virtual void SetHighlightMode ( CATModelIdentificator &iIdent, int mode);
  virtual void SetShowMode      ( CATModelIdentificator &iIdent, int showmode);
  virtual void ModifyColor(CATModelIdentificator &iIdent,unsigned int iColor); 
  virtual void AddManipOnPath(CATManipulator *manip, CATPathElement &path);
  virtual void AddManip(CATManipulator *manip, CATModelIdentificator &ident);
  virtual void RemoveManip(CATManipulator *manip, CATModelIdentificator &ident);
  virtual void RemoveManipOnPath(CATManipulator *manipulator, 
                                 CATPathElement &path);
  virtual void FlushManipulators();
  virtual void UnreferenceManipulator(CATManipulator *manipulator);


  //  display
  //  -------
  virtual void DrawElement ( CATViewer &, CATRep &, int draw = 1 );
  virtual void DrawElements( CATViewer &, ::list<CATRep> &, int draw = 1 );
  virtual void UndrawElement ( CATViewer &, CATRep &, int draw = 1 );
  virtual void UndrawElements( CATViewer &, ::list<CATRep> &, int draw = 1 );
  virtual void AddRep ( CATViewer &, CATRep & );
  virtual void RemoveRep ( CATViewer &, CATRep & );
  virtual int Display(void);
  virtual void AddChild ( CATRep &father, CATRep &son );
  virtual void RemoveChild ( CATRep &father, CATRep &son );


  //  viewer management
  //  -----------------
  virtual void AddViewer(CATViewer &iView);
  virtual void RemoveViewer(CATViewer &iView);
  void InitViewerList();
  CATViewer *GetNextViewer();

  //  for end of application -> viewers are destroyed before by dialog FW
  //  -------------------------------------------------------------------
  virtual void DisconnectFromViewers(CATViewer *viewer = NULL);


  //  current controller
  //  ------------------
  static CATVisuController * GetCurrentController();
  static void SetCurrentController(CATVisuController *iCntl);

  //  persistent identificator management
  //  -----------------------------------
  virtual void ChangeAllId();
  virtual int ComputePersistentIntId(int iVal);
  virtual int GetIdentificators(CATModelIdentificator ***oTab);
  virtual void SetPersistentId(CATModelIdentificator &iId,
                               CATModelIdentificator &iPersId);
 

  //  marshalling 
  //  -----------
  static void SetUnmarshallingController(CATVisuController *iCntl);
  static CATVisuController * GetUnmarshallingController();
  static CATVisuController * RestoreFromFile(char * filename);

  //  find the next representation from a model path
  //  ( this is used for BuildHighlightLook an BuildRepPath )
  //  -------------------------------------------------------
  virtual CATRep * FindNextRep ( const CATPathElement &, int &valid );

  //  decode graphic
  //  --------------
  // This one is to be called from the CATSelector, it look for the 
  // Next Rep in the pick path, find its controller, and call the 
  // DecodeGraphic on it. Do a PickPath->InitToTopRep before calling it.
  // (see also DecodeGraphic protected method)
   static HRESULT DecodeNextGraphicElement(const CATPickPath &iPickPath,CATPathElement &oPathElt);


  //  class information
  //  -----------------
  static void InitClassList();
  static CATVisuController *GetNextClassElement();

  // color map 
  virtual CATColorMap *GetColorMap();
  virtual void SetColorMap( CATColorMap * iColMap);

  // ressources for HLR display mode
  virtual CATHLRVisuOutputMaker *GetHLRVisuOutputMaker();
  virtual CATHLRPlaneView * GetHLRPlaneView (CATRep *rep);

  //  internal method to encapsulate the job done before and after
  //  deleting rep during modification
  //  ------------------------------------------------------------
  virtual void BeginModify();
  virtual void EndModify();

  protected:
  //////////

  // controller type for instance 2D, 3D (3D is the default value)
  // confer to define TYPE_2D, TYPE_3D
  VisuType _Type;

  //  overload this method to adapt it to your modelisation. If the
  //  model element do not know how to answer the question, ever call
  // DecodeNextGraphicElement if the Rep is a bag. or return NULL
  virtual HRESULT DecodeGraphic ( const CATPickPath &iRepPath,
                         CATPathElement &oPathElement );

 
  // List of modified representation paths
  ::list <CATRepPath> _pathToRedraw;

  // list of edited representation
  ::list <CATRep> _editedRep;
  ::list <CATBaseUnknown> _to_put_in_hso;

  // list of manipulator to add
  ::list <CATManipulator> _Manipulators;

  // list of identificator where manipulator has to be added
  ::list <CATModelIdentificator> _Identificators;

  //  Graphic table 
  //CATRepTable *   _GraphicTable;

  // the graphic model 
  CATRep * _GraphicModel;

// Color map
  CATColorMap *_ColorMap;

  // viewer
  ::list <CATViewer> _Viewers;

  //  the current controller identificator
  static CATVisuController * _CurrentCntl;

 // Type of Display
  CATDisplayType _layout;

  
  // Parameters for the loading configuration:
  // -----------------------------------------
  static char _lod_usage_mode;
  static char _texture_usage_mode;
  static char _edge_usage_mode;
  
  
  //  marhalling:
  // ------------
  int   _SizeTable;
  int _PersistentIdResquest;
  static CATVisuController *_CntlUnmarshalling;
  static int _LoadToCharge;
  static int _Version;

  // furtivity
  int _inhibFurtiveDraw;
  CATPSO *_pso;
  CATHSO *_hso;
  CATPSO *_lastPSO;
  CATHSO *_lastHSO;

  //  visu des manipulateurs sur sous elements
  ::list<CATPathElementRep> _pathManipulators;
  ::list<CATPathElementRep> _path;

  //  cso visualization
  ::list<CATRep> _csoElements;

  //  internal flag for modification
  //  ------------------------------
  int _everModify;

  private:
  ////////

  //  vue connexion
  CATCallback _vueConnexion;
  //CATVueInteractiveState _vueState;

  //  model
  CATCallback _modelConnexion;
  CATNotificationDispatcher *_modelDispatcher;

  CATCallback _psoConnexion;
  CATCallback _hsoConnexion;

  //  class information
  static ::list<CATVisuController> _classList;
  
};
#endif 

