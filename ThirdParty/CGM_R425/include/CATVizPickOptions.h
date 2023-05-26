#ifndef CATVizPickOptions_H
#define CATVizPickOptions_H


// COPYRIGHT DASSAULT SYSTEMES 2008

#include "SGInfra.h"
#include "CATPickOptions.h"
#include "CATViewerUtility.h"
class CATEPickingAlgo;


/**
* Class representing the pick options within a visualized viewer.
* <br><b>Role</b> : it describes the pick options associated to a viewer.
* 
*/
class ExportedBySGInfra CATVizPickOptions : public CATPickOptions
{
public :

  /**
   * Default constructor.
  */
  CATVizPickOptions ();

  /**
  * Constructor.
  * <br><b>Role</b> : create a pickPath and add the first
  * <br>graphic representation in it.
  *
  * @param iSimplePickingStyle
  *        The picking style for simple selection.
  * @param iSimplePickWindowSize
  *        The picking window size for simple selection.
  */
//  CATVizPickOptions ( const CATPickingStyle iSimplePickingStyle, int iSimplePickWindowSize = 0);

  virtual ~CATVizPickOptions ();
  
  /**
  * Sets the picking algorithm.
  * <br><b>Role</b> : sets the picking algorithm.
  *
  * @param i_pPickingAlgo
  *        The picking algorithm.
  */
  void SetPickingAlgo (CATEPickingAlgo*  i_pPickingAlgo);

  /**
  * Gets the picking algorithm.
  * <br><b>Role</b> : gets the picking algorithm.
  *
  * @param o_pPickingAlgo
  *        The picking algorithm.
  */
  void GetPickingAlgo (CATEPickingAlgo*&  o_pPickingAlgo);

  /** @nodoc */
  void SetPickMode (const CATPickingStyle iStyle);
  CATPickingStyle GetPickMode () const;

  /** @nodoc */
  void SetPickWindowSize (int iPixelSize, int iFromSettings=1);
  int  GetPickWindowSize () const;

  /** @nodoc */
  void SetAccuratePickWindowSize (int iPixelSize, int iFromSettings=1);
  int  GetAccuratePickWindowSize () const;

  /** @nodoc */
  void SetAccuratePickMode (int iOnOff, int iFromSettings=1);
  int  GetAccuratePickMode () const;

   /** @nodoc */
  void SetAccuratePickOnDlgMode (int iOnOff);
  int  GetAccuratePickOnDlgMode () const;

  /** @nodoc */
  void SetPickOOCPointCloud( bool iDoPick );
  bool GetPickOOCPointCloud() const;

  /** @nodoc */
  void SetGPUPickingMode(bool iGPUPicking);
  bool GetGPUPickingMode() const;

  /** @nodoc */
  void SetGraphPickingMode(bool iOnOff);
  bool GetGraphPickingMode() const;

private :
  
  /**
  * Copy constructor.
  *
  * @param iPickOptions
  *        The pick options to copy.
  */
  CATVizPickOptions (const CATVizPickOptions& iPickOptions);

  /**
  * Operator of assignment.
  *
  * @param iPickOptions
  *        The pick options use to create a new one identical.
  *
  * @return
  *        The new pick options created by assignment.
  */
  CATVizPickOptions & operator = (const CATVizPickOptions& iPickOptions);

  CATEPickingAlgo* _pPickingAlgo;

  unsigned int  _uiPickWndSizeSettingsCtrl    :  1;
  unsigned int  _uiAccPickWndSizeSettingsCtrl :  1;
  unsigned int  _uiAccPickModeSettingsCtrl    :  1;
  unsigned int  _uiAccPickMode                :  1;
  unsigned int  _uiPickWndSize                :  14;
  unsigned int  _uiAccPickWndSize             :  14;
  unsigned int  _uiAccPickOnDLGMode           :  1;
  bool          _uiPickOOCPC;

  CATPickingStyle _pickStyle;
  bool _gpuPickingMode;
  bool _graphPickingMode;
};

#endif
