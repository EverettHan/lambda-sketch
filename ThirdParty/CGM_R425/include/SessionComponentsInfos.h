#ifndef SessionComponentsInfos_h
#define SessionComponentsInfos_h

#include "CATPLMIntegrationInterfaces.h"

/**
 * @level Protected
 * @usage U1
 */

/**
 * Class of data which contains quantities of different PLM Components
 */

class ExportedByCATPLMIntegrationInterfaces SessionComponentsInfos
{
  friend class CATPLMPhotoEngine;

 public :
  /**
   * @return the quantity of References
   */
  unsigned int GetNbRef() const;
  /**
   * @return the quantity of RepReferences
   */
  unsigned int GetNbRepRef() const ;
  /**
   * @return the quantity of Instaces
   */
  unsigned int GetNbInst() const;
  /**
   * @return the quantity of RepInstances
   */
  unsigned int GetNbRepInst() const;
  /**
   * @return the quantity of Port
   */
  unsigned int GetNbPort() const;
  /**
   * @return the quantity of Connection
   */
  unsigned int GetNbCnx() const;


 protected :
  SessionComponentsInfos(const int nbRef,
			 const int nbRepRef,
			 const int nbInst,
			 const int nbRepInst,
			 const int nbPort,
			 const int nbCnx);

  virtual ~SessionComponentsInfos();

 private :
  unsigned int _Ref, _RepRef, _Inst, _RepInst, _Port, _Cnx;
 
};


#endif
