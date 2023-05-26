#ifndef CATExtIVisuInterfaces_H
#define CATExtIVisuInterfaces_H

// Copyright Dassault Systemes 2004

#include "CATIVisuInterfaces.h"
#include "CATGraphicProperties.h"
#include "list.h"

class ExportedByCATGraphicProperties  CATExtIVisuInterfaces: public CATIVisuInterfaces
{
  CATDeclareClass;
  
public:
    
  // Construction and destruction:
  // -----------------------------
    
  CATExtIVisuInterfaces();
  virtual ~CATExtIVisuInterfaces();
    
  virtual list<IID> *GetVisuInterface();
  virtual void SetVisuInterface(IID * iid);
  virtual void AddVisuInterface(IID * iid);
  virtual void RemVisuInterface(IID * iid);

protected:
  
  list<IID > *_IIDList;
};

#endif //CATExtIVisuInterfaces_H
