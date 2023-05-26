#ifndef CATCVMColorRef_h
#define CATCVMColorRef_h

#include "CATCVMAttrRef.h"
#include "CATCVMSysObjects.h"
#include "CATCVMSysStream.h"
#include "CATCGMNewArray.h"

class ExportedByCATCVMSysObjects CATCVMColorRef : public CATCVMAttrRef
{
public:
  // Seule methode de creation autorisee !!!!!!!!!!
  static CATCVMColorRef * GetOrCreateCVMColorRef(CATCVMContainer * iContainer, 
                                                                 double iRed, double iGreen, double iBlue, 
                                                                 double iAlpha);

  CATCVMColorRef (CATCVMContainer * iContainer);
  CATCGMNewClassArrayDeclare;

  protected:
  virtual ~CATCVMColorRef();

  // Get/Set divers
  public:
	HRESULT GetRVBAlpha (double &oR, double &oG, double &oB, double &oAlpha) const ;
	HRESULT SetRVBAlpha (double iR, double iG, double iB, double iAlpha)  ;

  // Stream/Unstream
  void Stream(CATCVMSysStream * iStream);
  void Unstream(CATCVMSysStream * iStream, CATCVMContainer * iContainer); 

  // Inits des donnees
  static void InitRVBAlpha(double & Red, double & Green, double & Blue, double & Alpha);

  // Comparaison
  CATBoolean IsEqualTo(CATCVMAttrRef * iAttrRef);

private:
 	//CATCVMColorRef(CATCVMColorRef&);
 	//void operator =(CATCVMColorRef&);

	double _Red, _Green, _Blue, _Alpha;

};
#endif

