// COPYRIGHT DASSAULT SYSTEMES 1999

#ifndef CATGroundRep_H
#define CATGroundRep_H

#include "SGInfra.h"

#include "CAT3DRep.h"

#include "CATMathPointf.h"
#include "CATMathDirectionf.h"

class CAT3DPlanarFaceGP;
class CAT3DLineGP;

class CATRender;

class ExportedBySGInfra CATGroundRep : public CAT3DRep
{
    friend class vImplDrawable_CATGroundRep;

 public :

   static CATGroundRep* CreateRep(const CATGroundRep &);
   static CATGroundRep* CreateRep(const CATMathPointf &iCenter, const CATMathDirectionf &, const float, const int fill = 1, 
      const int fixed = 0, const int iAxis=0, const int iProjectOrigin=0, const int iVersoDisplayed=1);

protected:

   /** @deprecated R417 : Use CreateRep instead.*/
   CATGroundRep (const CATMathPointf &iCenter, const CATMathDirectionf &, const float, const int fill = 1, 
     const int fixed = 0, const int iAxis=0, const int iProjectOrigin=0, const int iVersoDisplayed=1);
   /** @deprecated R417 : Use CreateRep instead.*/
   CATGroundRep (const CATGroundRep &);

public:    


    virtual ~CATGroundRep();

    // AZX: (A2X migration) Making draw functions final 
    virtual void DrawShading(CATRender&, int) override final;
    virtual void DrawPath(CATRender& iRender, int iInside, CATRepPath& iRepPath) override final;
    virtual void Draw(CATRender& iRender, int iInside) override final;
    virtual int IsOkToDraw(CATRender& ioRender, int ioInside) override final;

    void Translate (const float);
    
    void SetOrigin (const CATMathPointf &);
    CATMathPointf & GetNewOrigin();

    void SetVertical (const CATMathDirectionf &);
    CATMathDirectionf & GetVertical();

protected:
  virtual const vDrawInformation* GetDrawInformation();


 private :

    int _fill, _ProjectOrigin, _VersoDisplayed;
    float _radius;

    CATGraphicAttributeSet groundAtt, groundAttTrans, groundAttVolume;
    CATGraphicAttributeSet _ULinesAtt, _VLinesAtt, _ZeroLinesAtt;
    CATMathPointf _first_origine, _current_origine, _new_origine;
    CATMathDirectionf _vertical, _U, _V;

    CAT3DPlanarFaceGP *ground, *ground_xor;
    CAT3DLineGP *_ULines, *_VLines, *_ZeroLines;
 
};

#endif
