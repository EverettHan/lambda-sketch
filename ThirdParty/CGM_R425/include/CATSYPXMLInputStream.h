#ifndef  CATSYPXMLInputStream_h  
#define  CATSYPXMLInputStream_h  

#include  "CATIXMLInputStream.h"  
#include  "CATStyleProcessor.h"  
class CATSYPInputStream;
/**
 * Implementation of  CATIXMLInputStream that encapsulates a CATSYPInputStream.
 * It is used by the CATSYPXMLDomBuilder.
 */
class ExportedByCATStyleProcessor CATSYPXMLInputStream:  public  CATIXMLInputStream  {  
  CATDeclareClass;  
public:  
  /** Constructor
   * @param i_pInputStream the CATSYPInputStream encapsulated. Asserts if NULL.
   * The i_pInputStream must remain alive during life cycle of the CATSYPXMLInputStream.
   * @param i_size the size of the input stream. Assert if <=0
   */
  CATSYPXMLInputStream(CATSYPInputStream* i_pInputStream, int i_size);
  /** Destructor*/
  ~CATSYPXMLInputStream();  
  /** 
   * @copydoc CATIXMLInputStream#Read
   * Asserts and resets the o_sizeRead if io_pByteArray is NULL, 
   * or i_byteArrayCapacity is 0 
   */
  HRESULT  Read(  
    unsigned  char* io_pByteArray,
    unsigned  int   i_byteArrayCapacity,
    unsigned  int&  o_sizeRead);
private:
  CATSYPInputStream* _pInputStream;
  int _size;
};  

#endif  //  CATSYPXMLInputStream_h  
