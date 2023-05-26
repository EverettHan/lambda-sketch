// COPYRIGHT Dassault Systemes 2014
//===================================================================
//
// CATVidCtlDecoratorBase.h
// Header definition of CATVidCtlDecoratorBase
//
//===================================================================
// March 2014 Creation: 
//===================================================================

#ifndef CATVidCtlDecoratorBase_H
#define CATVidCtlDecoratorBase_H

#include "VisuDialog.h"
#include "CATVidCtl.h"

class CATSysWeakRef;
class CATVidLaySideAttach;
class CATSYPDataBlock;

class ExportedByVisuDialog CATVidCtlDecoratorBase: public CATVidCtl
{
  CATDeclareClass;

public:
  /**
   * Constructs a CATVidCtlDecoratorBase instance.
   */
  CATVidCtlDecoratorBase();
  /**
   * Set DecoratedWidget
   */ 
  void SetDecoratedWidget(CATVidWidget* i_pWidget);
  /**
   * Set Last GP Activated
   */ 
  void SetLastGPActivated(CATVidWidget* i_pWidget);
   /**
   * Get Last GP Activated
   */ 
  CATVidWidget* GetLastGPActivated();
  /**
   * @return the DecoratorStyleSheet property of the instance
   */
  //CATUnicodeString GetDecoratorStyleSheet() const;
  /**
   * Set the DecoratorStyleSheet property of the instance
   */
  //void SetDecoratorStyleSheet(const CATUnicodeString& iDecoratorStyleSheet);
   

protected: 
  /**
   * Destructor.
   */
  ~CATVidCtlDecoratorBase();
  /**
   * Template Data Updated
   */
  virtual void TemplateDataUpdated();
  /**
   * Get Decorated Widget Position
   */ 
  CATMathPoint2Df GetDecoratedWidgetPosition(); 
  /**
   * Get Decorated Widget Dimension
   */
  CATMathPoint2Df GetDecoratedWidgetDimension();
   /**
   * Get Last Mouse Position
   */ 
  CATMathPoint2Df GetLastMousePosition(); 
  /**
   * Get Decorated Widget
   */
  CATVidWidget* GetDecoratedWidget();
   /**
   * Get Decorator Datablock
   */
  CATSYPDataBlock* GetDecoratorDataBlock() { return _pDecoratorDB; }
  /** 
   * Configure Decorators
   */
  virtual CATSYPDataBlock* CreateDecoratorDataBlock();
  virtual void ConfigureDecorator(const CATUnicodeString& i_DecoratorName, CATSYPTemplateData* i_TemplateData, CATMathPoint2Df* o_Position, unsigned int& o_FlushPrevious);
  virtual void OnDrag(CATBaseUnknown* i_pSender, CATVidMouseEventArgs* i_spArgs){}
  virtual void OnRelease(CATBaseUnknown* i_pSender, CATVidMouseEventArgs* i_spArgs){}
  /*
   * We can add more registery event specific to a decorator @see CATVidCtlSlider_Decorator for example 
   */
  virtual void RegisterCustomHandlers();
  /**
   * Get Decorator
   */
  CATVidWidget* GetDecorator(const CATUnicodeString& iDecoratorName);

  CATMathPoint2Df ComputeSidePosition(CATVidWidget* iDecorator, CATVid::Side iSide = CATVid::Right, CATVid::AlignmentPolicy iAlignment = CATVid::Center, unsigned int iClockwise=1);
  void FlushDecorators(CATVidWidget* iExcludedWidget=NULL);

private: 

  void HandleMouseEvent(CATBaseUnknown* i_pSender, CATVidMouseEventArgs* i_spArgs);

  CATVidWidget* CreateDecorator(const CATUnicodeString& i_DecoratorName, CATMathPoint2Df* o_Position, unsigned int& o_FlushPrevious);
  CATMathPoint2Df ComputeDecoratorPosition(CATVidWidget* iDecorator, const CATMathPoint2Df& iDecoratedWidgetPos, const CATMathPoint2Df& iDecoratedWidgetDim, CATVid::Side iSide, CATVid::AlignmentPolicy iAlignment, unsigned int iClockwise);
  static CATMathPoint2Df ComputeDecoratorDefaultSidePosition(CATVidWidget* iDecorator, const CATMathPoint2Df& iViewerDim, const CATMathPoint2Df& iDecoratedWidgetPos, const CATMathPoint2Df& iDecoratedWidgetDim, CATVid::Side iSide, CATVid::AlignmentPolicy iAlignment);


private: 
  // Copy constructor and equal operator
  // -----------------------------------
  CATVidCtlDecoratorBase (CATVidCtlDecoratorBase&);
  CATVidCtlDecoratorBase& operator=(CATVidCtlDecoratorBase& original);

  CATSysWeakRef* _pDecoratedWidgetWR;
  CATSysWeakRef* _pLastGPActivatedWR;

  CATSYPDataBlock* _pDecoratorDB;
  
  CATVidWidget* _pPressDecorator;
  CATVidWidget* _pHoldDecorator;
  CATVidWidget* _pLongHoldDecorator;

  CATSYPHashMap<CATUnicodeString, CATVidWidget*> _pDecorators;

  CATVidLaySideAttach* _pContainer;
  CATUnicodeString _decoratorStyleSheet;

};
#endif
