#ifndef SessionComponentsAndSizeInfos_h
#define SessionComponentsAndSizeInfos_h

#include "SessionComponentsInfos.h"


/**
 * @level Protected
 * @usage U1
 */

/**
 * Class of data which contains quantities of different PLM Components and sizes of associated Authoring streams
 */



class ExportedByCATPLMIntegrationInterfaces SessionComponentsAndSizeInfos : public SessionComponentsInfos
{
  friend class CATPLMPhotoEngine;

 public :
  /**
   * @return the size of the authoring stream of the RepReferences in kBytes
   */
  unsigned int GetRepRefSize() const;

  /**
   * @return the size of the authoring stream of the Connections in kBytes
   */
  unsigned int GetCnxSize() const;

  /**
   * @return the size of the authoring stream of the Ports in kBytes
   */
  unsigned int GetPortSize() const;

 private:

  SessionComponentsAndSizeInfos(const int nbRef,
				const int nbRepRef,
				const int nbInst,
				const int nbRepInst,
				const int nbPort,
				const int nbCnx);

  ~SessionComponentsAndSizeInfos();

  unsigned int _RepRefSize, _CnxSize, _PortSize;

};

#endif
