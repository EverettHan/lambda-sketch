#ifndef _catgmpolyvars_h
#define _catgmpolyvars_h

//______________________________________________________________________
#include "GMPolyTopTools.h"

//______________________________________________________________________
// WMN20220302 pb : initialiser les variables via GetVariables/TraceVariables impacte l'ensemble des odts PHM (init via la factory)
//                  pour s'en affranchir, il faudrait que chaque init de variable soit indépendante.
#define mac_gmpoly_init_var_int(classnam,varnam,defval) \
  static const char * varnam##_str = CATGetEnv(#varnam); \
  int classnam::varnam = varnam##_str ? atoi(varnam##_str) : defval;

#define mac_gmpoly_init_var_chr(classnam,varnam,defval) \
  static const char * varnam##_str = CATGetEnv(#varnam); \
  char * classnam::varnam = (char*)(varnam##_str ? varnam##_str : defval);

//______________________________________________________________________
#define GMPOLYVAR2P2P "::"
#define GMPOLYVAR(mavar) CATGMPolyVars::mavar // WMNXLATOR4EVER

//______________________________________________________________________
#define GMPolyIntVarDef(varname) GMPOLYVAR(varname) = GetVarInt(#varname,GMPOLYVAR(varname));
#define GMPolyChrVarDef(varname) GMPOLYVAR(varname) = GetVarChr(#varname,GMPOLYVAR(varname));
#define GMPolyDoubleVar(varname) GMPOLYVAR(varname) = GetVarDouble(#varname,GMPOLYVAR(varname));

//______________________________________________________________________
#define GMPolyIntVarTra(varname) GMPOLYTRA("CATGMPoly%s%s = %d\n",GMPOLYVAR2P2P,#varname,GMPOLYVAR(varname)) // manque valeur par defaut, besoin d'un objet var... XlatorToolsEnvs...
#define GMPolyChrVarTra(varname) GMPOLYTRA("CATGMPoly%s%s = %s\n",GMPOLYVAR2P2P,#varname,GMPOLYVAR(varname))
#define GMPolyDoubleTra(varname) GMPOLYTRA("CATGMPoly%s%s = %f\n",GMPOLYVAR2P2P,#varname,GMPOLYVAR(varname))

//______________________________________________________________________
#define GMPOLY_DEFINE_VARS \
  static double gmpolydouble;\
  static char*  gmpolychar;\
  static int    gmpolytracesactive;\
  static int    gmpolytessxfactory;\
  static int    gmpolychkcmp; \
  static int    gmpolywireoptimmapping; \
  static int    gmpolychktess; \
  static int    gmpolywireoptimedgetag; \
  static int    gmpolywireoptimAAPUT; \
  static int    gmpolyperf; \
  static int    gmpolyfacetpernode_cellbvh; \
  static int    gmpolyfacetpernode_distance; \
  static int    gmpolyfacetpernode_intersect; \
  static int    gmpolypublish; \
  static int    gmpolycelldivpreview; \
  static int    gmpolycelldivnpq; \
  static int    gmpolyextremumboolean; \
  static int    gmpolychkncgm; \
  static int    gmpolychkinput; \
  static int    gmpoly_extrusion_contactchk; \
  static int    gmpolytestbodychecker; \
  static int    gmpolytessicbr; \
  static int    GMPolyWireOptimizer_CrossingSimplif; \
  static int    gmpolychkheal; \
  static int    gmpolyxscale; \
  static int    gmpolyxscale_clone_noerr; \
  static char*  CATDevelopmentStage; \
  static int    gmpolyfaceneighborhood; \
  static int    gmpolyforcev5;

//______________________________________________________________________
#define macprntvarenv cgmout << "CATGMPolyVars" << GMPOLYVAR2P2P << mavarname << " : varchar=" << (mavarchar?mavarchar:"NULL") << " varval=" << mavarres << " (default=" << defaultvalue << ")\n"

//______________________________________________________________________
enum CATGMPolyVar_t
{
  UNDEFINED = -1,
  NODEFAULTVALUE = 0,
  PCHARWITHDEFAULT = 1,
  INTWITHDEFAULT = 2,
  DOUBLEWITHDEFAULT = 3
};

//______________________________________________________________________
class CATGMPolyVar
{
private:

  CATGMPolyVar_t _vartyp;

  char* _varnam;
  void* _varval;
  void* _vardft;

  double* _varvaldouble;
  double* _vardftdouble;
};

//______________________________________________________________________
class ExportedByGMPolyTopTools CATGMPolyVars
{
public:
  CATGMPolyVars();
  ~CATGMPolyVars();

public:
  void TraceVariables();

private:
  void   GetVariables();

public:
  static void CATGMPolyVars_Init();
  static int  CATGMPolyVars_DeleteAtExit();
  static inline CATGMPolyVars* GetStaticGMPolyVars() { return _GMPolyVars; }

  static char*  GetVarEnv(char* mavarname);
  static int    GetVarInt(char* mavarname,int defaultvalue);
  static char*  GetVarChr(char* mavarname,char* defaultvalue);
  static double GetVarDouble(char* mavarname,double defaultvalue);

private:
  static CATGMPolyVars* _GMPolyVars;

public:
  GMPOLY_DEFINE_VARS;

};

#endif
