#ifndef CATFrFCompositeCurveHandler_H
#define CATFrFCompositeCurveHandler_H
// COPYRIGHT DASSAULT SYSTEMES 2012
//==========================================================================
//
// CATFrFCompositeCurveHandler: handler for CATFrFCompositeCurve object
// (ensures the objet remains alive as long as the handler is alive)
//
//==========================================================================
//
// Usage notes:
//
//==========================================================================
// 15/11/12 NLD Creation
//=============================================================================

class CATFrFCompositeCurve;
class CATFrFCompositeCurveHandler
  {
   private:
   CATFrFCompositeCurve* _CCV;
   public:
                                 CATFrFCompositeCurveHandler             (                                                          );
                                 CATFrFCompositeCurveHandler             (      CATFrFCompositeCurve       *  iCCV                  );
                                 CATFrFCompositeCurveHandler             (const CATFrFCompositeCurveHandler & iCompositeCurveHandler);
                                 CATFrFCompositeCurveHandler& operator = (const CATFrFCompositeCurveHandler & iCompositeCurveHandler);
   virtual                      ~CATFrFCompositeCurveHandler             (                                                          );
           void                  SetCompositeCurve                       (      CATFrFCompositeCurve       *  iCCV                  );
           CATFrFCompositeCurve* GetCompositeCurve                       (                                                          );

  };
#endif
