
#ifndef __CATSessionProtection_H
#define __CATSessionProtection_H

#include "CATOme.h"
#include "CATOmeAbendObject.h"
#include "CATOmxSet.h"
#include "CATOmxSR.h"
#include "CATOmxSharable.h"
#include "CATIOmeAbendPanel.h"
#include "CATAbendInfo.h"

class CATOmeAbendInfo: public CATAbendInfo
{
public : 
  CATOmeAbendInfo(const char* iToDump) : CATAbendInfo(CAT_ABEND_OMB_INFO){ _toDump=iToDump;}

  char * Dump(){return (char*)_toDump;}

private :
  const char* _toDump;
};



class ExportedByCATOme CATOmeManageSaveProtection 
{
public :
  inline void SetErrorPanel(CATIOmeAbendPanel* iPanel){ m_errorPanel=iPanel; }
  inline CATIOmeAbendPanel* GetErrorPanel(){ return m_errorPanel; }
  inline void AddObject(CATOmeAbendObject* iInfo){ m_setAbendObject.Insert(iInfo); }

  void InformAboutDataCorruption(CATOmeAbendObject::Identifier iFrom);
private:
  //void GetInfosFromObjects();

  CATOmxSR<CATIOmeAbendPanel> m_errorPanel;
  CATOmxSet<CATOmeAbendObject, sharable_manager> m_setAbendObject;
};

ExportedByCATOme CATOmeManageSaveProtection* GetSaveProtection();


#endif
