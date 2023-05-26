/**
 * @fullreview SCA-ERS 02:04:18
 * @error MISC Y pas de constructeur par copie et pas d'operateur =
*/
#include "CATAfrFoundation.h"

#ifndef CATSDO_h
#define CATSDO_h
//
// CATIA Version 5 Release 1 Framework Model
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
//  Abstract : contains objects to visualize in toolbars
//             
//------------------------------------------------------------------------------
//  Usage :    
//
//------------------------------------------------------------------------------
//  Inheritance : CATSDO
//                  CATCallbackManager (Framework System)
//------------------------------------------------------------------------------
//  Main Methods :
//             AddElement ( const CATExtendable * );
//             RemoveElement ( const CATExtendable * );
//
//------------------------------------------------------------------------------

#include "CATCollec.h"
#include "CATCallbackManager.h"
#include "CATLISTP_CATBaseUnknown.h"

class CATBaseUnknown;
class CATSO;
class CATSDONotification;

class ExportedByCATAfrFoundation CATSDO : public CATCallbackManager
{
//------------------------------------------------------------------------------
     
public:

  CATDeclareClass;

  CATSDO();
  
  virtual ~CATSDO();
  
  virtual void AddElement( CATBaseUnknown * ,int iDispatchChange=1);
  virtual void RemoveElement( CATBaseUnknown * ,int iDispatchChange=1);
  virtual void Empty();
  
  CATBaseUnknown * GetElement(int num);
  int GetSize();
  
  void InitElementList();
  CATBaseUnknown * GetNextElement();
  void DispatchChange();

  
private:
  
  CATSDO (const CATSDO &);
  CATSDO & operator= (const CATSDO &);
  
  int current;
  CATLISTP(CATBaseUnknown) _List;
  CATSDONotification * _ChangeNotification;
};

#endif
