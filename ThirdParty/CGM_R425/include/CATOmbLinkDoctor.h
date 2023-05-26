/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2007

#ifndef CATOmbLinkDoctor_h
#define CATOmbLinkDoctor_h


/**
 * @level Protected
 * @usage U1       
 */



#include "CATObjectModelerBase.h"
#include "CATDataType.h"
#include "CATOmbLinkDoctorGlobalStatus.h"


class CATOmbLinkDoctorImpl ;
class CATOmbLinkDoctorListener;

/** 
 * Link checker and corrector
 */
class ExportedByCATObjectModelerBase CATOmbLinkDoctor
{
public:
  CATOmbLinkDoctor();
  ~CATOmbLinkDoctor();

  /**
   * Runs a link check and correction
   */
  HRESULT Run ( CATOmbLinkDoctorListener& iListener) ;

private:

  //Not Implemented
  CATOmbLinkDoctor (const CATOmbLinkDoctor& );
  CATOmbLinkDoctor & operator=(const CATOmbLinkDoctor &);

  // Data members
  static CATOmbLinkDoctorImpl* m_doctor;
};

#endif
