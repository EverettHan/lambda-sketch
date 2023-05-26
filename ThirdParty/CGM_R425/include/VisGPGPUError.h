#ifndef VISGPGPUERROR_H_
#define VISGPGPUERROR_H_


#define GPGPU_E_FIRST 0x8004E030L
#define GPGPU_E_LAST 0x8004E031L

//
// MessageId: E_GPGPU_NO_DEVICE_FOUND
//
// MessageText:
//
//  There were no device that match with the asked type
//
#define E_GPGPU_NO_DEVICE_FOUND _HRESULT_TYPEDEF_(0x8004E030L)

//
// MessageId: E_GPGPU_BINARIES_FAILURE
//
// MessageText:
//
//  The binaries has not being created. 
//
#define E_GPGPU_BINARIES_FAILURE _HRESULT_TYPEDEF_(0x8004E031L)






#endif /* VISGPGPUERROR_H_ */
