#ifndef CATVisFilter_H
#define CATVisFilter_H

// CATIA Version 5 Release 15 Framework Visualization
// Copyright Dassault Systemes 2004

#include "SGInfra.h"

#include "CATErrorDef.h"
#include "CATVisFilterType.h"
#include "CATStreamer.h"
#include "CATRepRender.h"
#include "CATFilterNotification.h"

//++ SGCAAPlan
#include "CATVisMacroForInterfaces.h"
class IVisSGFilter;
class CATVisFilterIVisSGFilterBOAImpl;
class VisSGVisitor;
class VisSGFilterVisitor;
//-- SGCAAPlan

//------------------------------------------------------------------------------------
// macro de declaration des filtres

#define CATDeclareVisFilter(ClassName)                                  \
private :                                                               \
  static unsigned int _s##ClassName##Type;                                \
public:                                                                 \
  static unsigned int GetFilterType(){return _s##ClassName##Type;};       \
  virtual int IsATypeOfFilter(unsigned int iType)                    

#define CATImplementVisFilter(ClassName, ParentClassName)                       \
  unsigned int ClassName::_s##ClassName##Type = CATVisFilter::GetNewFilterID();   \
  int ClassName::IsATypeOfFilter(unsigned int iType)                              \
{                                                                               \
  if (_s##ClassName##Type == iType) return 1;                                 \
  \
  return ParentClassName::IsATypeOfFilter(iType);                             \
} 

//------------------------------------------------------------------------------------

class l_CATVisFilter;
class CATVisFilterWeakRef;
class CATVisBeforeDrawData;

class CATRep;
class CATRender;
class CATRepRender;
class CATVisFiltersStack;
class CATVisPublisher;
class CATFilterEventSender;



class ExportedBySGInfra CATVisFilter  
{
  friend class CATVisFilterWeakRef;
  friend class CAT3DFilterBagRep;
  friend class CAT2DFilterBagRep;
  friend class SGCGRStreamerForVisFilter;
  friend class SGCGRNodesFactoryA;
  
  CATDeclareVisFilter(CATVisFilter);

public :
  //++ SGCAAPlan
  CATVisDeclarePublicInterfaceAdhesion(CATVisFilter, IVisSGFilter, CATVisFilterIVisSGFilterBOAImpl);
  HRESULT Push(VisSGVisitor& iVisitor, CATVisFiltersStack& iStack);
  HRESULT Pop(VisSGVisitor& iVisitor, CATVisFiltersStack& iStack);
  //-- SGCAAPlan

	void AddRef(); 
  void Release();
  
  CATVisFilterWeakRef* GetWeakRef();

  void Push(CATRepRender& iRender, CATVisFiltersStack& iStack);
  void Pop(CATRepRender& iRender, CATVisFiltersStack& iStack);

  void Update();

  HRESULT Publish(CATVisPublisher& iPublisher);

  void DesactivateStreaming();
  HRESULT Stream(CATStreamer& oStr,int iSaveType=0);
  void UnStream(CATStreamer& iStr);

  static unsigned int GetNewFilterID() {return _sVisFilterTypeCurrentID++;};  

  virtual void Visit(VisSGFilterVisitor& iVisitor) const;

  virtual unsigned char GetType() const;

protected :
  CATVisFilter();
  virtual ~CATVisFilter();

  void ActivateAutomaticUpdate();
  CATVisBeforeDrawData* GiveUpdateData();

  void SetLetter(l_CATVisFilter * letter);
  inline l_CATVisFilter * GetLetter();

  void SendFilterNotification(CATFilterNotificationType iType);
  inline CATFilterEventSender * GetSender();

  CATVisFilterWeakRef* _weakRef;
  l_CATVisFilter* _letter;
  CATFilterEventSender* _sender;

private :
  unsigned int 	_nRef;
  CATVisBeforeDrawData*	_updateData;

  static unsigned int _sVisFilterTypeCurrentID;

public :
  static void MergeClippingPlanes(CATRepRender::ClippingPlanes* iClip0, CATRepRender::ClippingPlanes* iClip1); 
};

inline l_CATVisFilter * CATVisFilter::GetLetter()
{
  return _letter;
}

inline CATFilterEventSender * CATVisFilter::GetSender()
{
  return _sender;
}

#endif
