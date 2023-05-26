#ifndef CATDragAndDrop_h
#define CATDragAndDrop_h

//
// CATIA Version 5 Release 1 Framework VFW2
// Copyright Dassault Systemes 1997
//------------------------------------------------------------------------------
// Abstract :   defines the notification used for drag and drop
// ----------  
//
//------------------------------------------------------------------------------
// Usage :      is used by manipulator
// ------
//
//------------------------------------------------------------------------------
// Class :      CATBeginPreDrop
// -------      CATPreDrop
//              CATEndPreDrop
//              CATDrop
//                CATVueNotification
//                  CATNotification
//------------------------------------------------------------------------------

#include "CATVueNotification.h"
#include "CATVisFoundation.h"

class ExportedByCATVisFoundation CATBeginPreDrop : public CATVueNotification
{
  CATDeclareClass;

  public:
    CATBeginPreDrop(CATNotification *iNotification, CATNotification *basic);
    virtual ~CATBeginPreDrop();
    CATNotification *GetBasicDragNotification() const;

  private:
    CATNotification *_basicDragNotif;
};

class ExportedByCATVisFoundation CATPreDrop : public CATVueNotification
{
  CATDeclareClass;

  public:
    CATPreDrop(CATNotification *iNotification, CATNotification *basic);
    virtual ~CATPreDrop();
    CATNotification *GetBasicDragNotification() const;
    
  private:
    CATNotification *_basicDragNotif;
};

class ExportedByCATVisFoundation CATEndPreDrop : public CATVueNotification
{
  CATDeclareClass;

  public:
    CATEndPreDrop(CATNotification *iNotification, CATNotification *basic);
    virtual ~CATEndPreDrop();
    CATNotification *GetBasicDragNotification() const;
    
  private:
    CATNotification *_basicDragNotif;
};

class ExportedByCATVisFoundation CATDrop : public CATVueNotification
{
  CATDeclareClass;

  public:
    CATDrop(CATNotification *iNotification, CATNotification *basic);
    virtual ~CATDrop();
    CATNotification *GetBasicDragNotification() const;
    
  private:
    CATNotification *_basicDragNotif;
};

#endif
