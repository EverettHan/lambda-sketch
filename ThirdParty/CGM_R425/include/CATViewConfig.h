#ifndef CATViewConfig_H
#define CATViewConfig_H

// COPYRIGHT DASSAULT SYSTEMES 2002

#include "CATVisController.h"
#include "CATCommand.h"
#include "CATListPV.h"
#include "CATListOfFloat.h"
#include "CATI3DMultiViewpointViewer.h"
class CATViz3DViewer;
class CATMathAxis2D;
class CATMathDirection2D;
class CATRep;
class CAT2DRep;
class CAT2DManipulator;
class CAT2DViewpoint;
class CATExtI3DMultiViewpointViewer;


//===============================================================================================
class ExportedByCATVisController CATViewConfig : public CATCommand
{
  friend CATExtI3DMultiViewpointViewer;

  CATDeclareClass;

public :

  CATViewConfig(CATViz3DViewer * ipVizViewer);
  virtual ~CATViewConfig();

  // Get/Set number of rows and columns in the config
  // The table of row and column position must be allocated by caller. Otherwise, they will not be used.
  // These tables represent the end position of each rows and columns in the config in relative coordinate
  // (between 0.0 and 1.0). The last position must be equal to 1.0.
  void SetRowAndCol(const int iNbRow = 2, const int iNbCol = 2, const float * iRowPos = NULL, const float * iColPos = NULL);
  void GetRowAndCol(int * oNbRow, int * oNbCol, float * oRowPos = NULL, float * oColPos = NULL);

  void GetConfigPos(int * oRow, int * oCol, float * oSize = NULL);

  CATListPV GetConfigList();
  CATListPV GetDefinedVPList();
  DefinedVP * GetDefinedVP();

private :
      
  void SetConfigPos(const int iRow, const int iCol, const float* iSize = NULL);

  void SetDefinedVP(DefinedVP* defvp);

  void UpdateConfig();

  void ResetConfig();

  void BuildConfigSeparator(); 
  void DestroyConfigSeparator(); 

  CATRep * BuildManipulatorRep(const int iHor, const float iPos); 
  CAT2DManipulator * BuildManipulator(CAT2DRep * rep, const CATMathAxis2D & position, const CATMathDirection2D & transdir, int num = 0);

  void CATPreactivateCB(CATCommand* manip, CATNotification* notif, CATCommandClientData data);
  void CATEndPreactivateCB(CATCommand* manip, CATNotification* notif, CATCommandClientData data);
  
  void BeginManipulateCB( CATCommand * cmd, CATNotification * notif, CATCommandClientData data);
  void ManipulateCB     ( CATCommand * cmd, CATNotification * notif, CATCommandClientData data);
  void EndManipulateCB  ( CATCommand * cmd, CATNotification * notif, CATCommandClientData data);

  float GetManipPosition(const CATCommand * manip, const int num);

  void GraphicSizeChangeCB(CATCallbackEvent evt, void*, CATNotification* notif, CATSubscriberData data, CATCallback cb);
  void ViewerDestroyedCB(CATCallbackEvent, void*, CATNotification*, CATSubscriberData, CATCallback);

  CATListPV      _2DRepList;
  CATListPV      _2DManipList;
  CATRep       * _tmpRep; 

  int _row; // the row number in outer config
  int _col; // the column number in outer config

  // the size of config
  float _xmin, _xmax, _ymin, _ymax;

  DefinedVP * _defvp;

  // Sub-config management
  CATListPV      _viewConfigList;

  CATViz3DViewer* _p3DVizViewer;

  int _nbRow; //Number of rows in config
  int _nbCol; //Number of columns in config

  CATListOfFloat _rowList;
  CATListOfFloat _colList;

  CAT2DViewpoint * _manipViewpoint;

	CATCallback _ViewerDestroyedCB;
  CATCallback _GraphicWindowResizeCB;
};
#endif
