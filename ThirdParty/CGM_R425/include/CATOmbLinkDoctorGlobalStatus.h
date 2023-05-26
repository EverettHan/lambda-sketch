/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2007

#ifndef CATOmbLinkDoctorGlobalStatus_h
#define CATOmbLinkDoctorGlobalStatus_h

/**
 * @level Protected
 * @usage U1       
 */


#include "CATObjectModelerBase.h"
#include "CATOmbLinkDoctorErrorStatus.h"


class CATOmbLinkDoctorErrorImpl;
class CATOmbLinkInterface ;
class CATSymbolProperty ;
class CATOmbExternalLinkSnapshot ;

class ExportedByCATObjectModelerBase CATOmbLinkDoctorGlobalStatus
{
  friend class CATOmbLinkDoctorImpl;

public:
   /**
    * This method is a shortcut in order to
    * know if the doctor is not able
    * to manage all errors
    * If it is able to manage all error, the listener can
    * do nothing and accept all defaults.
    */
   CATBoolean isThereErrorWithoutProposal() ;
   
   /**
    * This method is for statistic purpose.
    * It gives the numbers of links checked in the session
    */
   CATULONG32 numberOfLinkChecked() ;
   
   /**
    * This method is for statistic purpose.
    * It gives the numbers of errors found on links in the session
    */
   CATULONG32 numberOfErrors() ;


   /**
    * This method allows to know if the doctor was able
    * to repair all errors
    */
   CATBoolean areAllErrorRepaired() ;
   /**
    * This method is for statistic purpose.
    * It gives the numbers of errors successfully repaired
    */
   CATULONG32 numberOfLinkRepaired() ;





   /**
    * With this method, you can iterate through all the (solution/error)
    */
   CATOmbLinkDoctorErrorStatus* nextError() ;

private:
  CATOmbLinkDoctorGlobalStatus();
  ~CATOmbLinkDoctorGlobalStatus();
  void Clean( );
  void AddError (CATOmbLinkDoctorErrorStatus::TypeOfError, CATOmbLinkDoctorErrorStatus::TypeOfRepair) ;
  void AddError(CATOmbLinkInterface& iLink, CATOmbLinkDoctorErrorStatus::TypeOfError iErrorType);
  void AddError(CATSymbolProperty& iSymb, CATOmbLinkDoctorErrorStatus::TypeOfError iErrorType);
  CATOmbLinkDoctorErrorImpl * AddError(CATOmbExternalLinkSnapshot * ipSnapshot, 
          CATOmbLinkDoctorErrorStatus::TypeOfError iErrorType, CATOmbLinkDoctorErrorImpl * ipPreviousError = NULL) ;
  void _AddError (CATOmbLinkDoctorErrorImpl *) ;

  // WARNING !! after this call, parameter do not contain any error.
  void IntegrateIn (CATOmbLinkDoctorGlobalStatus &) ;

	//Not Implemented
	CATOmbLinkDoctorGlobalStatus (const CATOmbLinkDoctorGlobalStatus& );
  CATOmbLinkDoctorGlobalStatus & operator=(const CATOmbLinkDoctorGlobalStatus &);

  //Members
  CATOmbLinkDoctorErrorImpl* m_firstError;
  CATOmbLinkDoctorErrorImpl* m_lastError;
  CATOmbLinkDoctorErrorImpl* m_currentError;

  CATULONG32 m_linksCount;
  CATULONG32 m_foundErrorsCount;
  CATULONG32 m_correctedErrorsCount;


};
#endif
