/**
* @level Private 
* @usage U1
*/
#include "CATBaseUnknown.h"
#include "CATListOfInt.h"
#include "AC0CATPL.h"
#include "CATIV4ElementThroughDittoAccess.h"


class ExportedByAC0CATPL CATV4ElementThroughDitto : public CATIV4ElementThroughDittoAccess
{
  CATDeclareClass;
public:
  CATV4ElementThroughDitto(const CATListOfInt& PileDittos, int Jele, int Model);
  ~CATV4ElementThroughDitto();

  void GetPileDitto(CATListOfInt& PileDittos);
  int  GetJele();
  int GetModel();

  private :
    CATListOfInt _PileDittos;
    int _Jele;
    int _Model;
};


