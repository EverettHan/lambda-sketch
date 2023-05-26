#ifndef CATSysDEFINELAPRJ_H
#define CATSysDEFINELAPRJ_H

#include "CATIAV5ReleaseInfo.h"
#include "CATIAV5Level.h"
#include "CATLib.h"
#include "JS0LIB0.h"


/*--------------------------------------------------------------------------------

THE TEXT BELOW DESCRIBES THE MACRO OF THE CURRENT HEADER, DESIGNED TO ALLOW 
CONDITIONAL ACTIVATION OF SOURCE CODE. 

YOU SHOULD ONLY RELY ON THESE SERVICES WHEN REQUESTED TO DO SO BY YOUR IMPLEMENT 
LEADER AND/OR DEFINE LEADER.

SHOULD YOU NEED MORE INFORMATION, PLEASE GET IN TOUCH WITH THEM TO GET ACCESS TO
A MORE COMPLETE PRESENTATION.

--------------------------------------------------------------------------------

AIM
===
This mechanism was designed to allow the conditional activation of some portions
of source code, in a context of cross Brands developments, involving several
functions and development teams, all targeted:
 ° for the same customer (and not accessible to other customers);
 ° on the same level of code (and generally a post GA delivery);
 ° functions managed are initially considered LA (Limited availability) 
   but turn generally available to all customers at the same time (by default 
   on the following release but this can be parameterized).

The mechanism relies:
 ° on a local environment variable (Local_Env_Var)
     - Selected by the developer of each function involved.
     - Which will allow to activate/de-activate functions on a per function basis
     - Generally the targeted customer does not need to know about these local
       environment variables
 ° On a project name for internal use (Project_Name)
     - Which is not an environment variable, but identifies the level of code and
       customer targeted
 ° A global environment variable (GLOBAL_Env_Var)
     - Provided to targeted customer
     - Allows him to activate all functions subscribing to this mechanism and
       project, at once.

EXTERNAL VIEW & EXAMPLE
=======================
 ° Project Name = DEV_DassaultAviation_V6R2012x_FD1
 ° GLOBAL_Env_Var = ADA_1211
 ° Local_Env_Var = ActivateSpecificDev
     - If ADA_1211 is not set
          + No new function is active
          + If ActivateSpecificDev=1, developments conditioned by
            ActivateSpecificDev are activated.
     - If customer sets ADA_1211 environment variable:
          + All functions associated with project DEV_DassaultAviation_V6R2012x_FD1 
            will be activated at the same time
          + If, in addition, ActivateSpecificDev=0 then All functions are activated
            BUT the function conditioned by ActivateSpecificDev ("anti-variable"
            capability on local environment variable; not that value of local
            environment variable is "0"  to get the anti-variable behavior).

INTERNAL VIEW
=============
At a central level in V6 source code (System Framework):
    The global environment variable is associated to the project internal name. 
    Setting of that global environment variable will activate all developments 
    associated to the project, at the same time.

At the level of FW involved in the deliveries of the new functions:
    The local environment variable is associated to the project name
    New function activation is conditioned by a test of the project and the local
    environment variable.
    The local environment variable also plays a role of "anti-variable. See
    example above.

Declarations performed at central level (System FW)
DEFINE_LA_PRJ(Project_Name, GLOBAL_Env_Var, Level)
IMPL_PRJ_VAR(Project_Name, GLOBAL_Env_Var, Level)
 ° Associate "GLOBAL_Env_Var" environment variable with project "Project_Name"
 ° "Level" defines the release where all functions associated with this project 
   "Project_Name" get activated by default

Macros accessible to Developers
USE_LA_VAR(Project_Name, Local_Env_Var)
 ° Associates condition on "Local_Env_Var" environment variable with project 
   "Project_Name"
DEV_LA_ISACTIVE(Project_Name, Local_Env_Var)
 ° Evaluates whether project "Project_Name" is active, or if Local_Env_Var is set
   or not.

Note that GLOBAL_Env_Var string should not be used by developers (besides ODT shell
scripts).

Conditional activation of a given development would then turn from:
         if (CATGetEnv("Local_Env_Var"))

Into:
         #include "CATSysDevLA.h"
         USE_LA_VAR(Project_Name,Local_Env_Var);
         ...
         if (DEV_LA_ISACTIVE(Project_Name,Local_Env_Var))

--------------------------------------------------------------------------------*/





#ifdef __cplusplus 
extern "C" {
#endif 

int ExportedByJS0LIB0 DSYDevLACheckLevel(int iLevel); 


#ifdef _WINDOWS_SOURCE 
#ifdef __JS0LIB0 
#define DEFINE_LA_PRJ(project,IntCode,level) int ExportedByJS0LIB0 DSY_PRJ_LA_ISACTIVE_##project();   \
                                             int ExportedByJS0LIB0 DSYSet_##project(int);
#else 
#define DEFINE_LA_PRJ(project,IntCode,level) int ExportedByJS0LIB0 DSY_PRJ_LA_ISACTIVE_##project();   \
                                             int ExportedByJS0LIB0 DSYSet_##project(int); 
#endif 
#else //Unix
#define DEFINE_LA_PRJ(project,IntCode,level)  int ExportedByJS0LIB0 DSY_PRJ_LA_ISACTIVE_##project();    \
                                              int ExportedByJS0LIB0 DSYSet_##project(int);  
#endif

#ifdef __cplusplus
};
#endif




#ifdef _WINDOWS_SOURCE
#ifdef __JS0LIB0
#define IMPL_LA_PRJ(project,IntCode, level)                          \
int ExportedByJS0LIB0 DSY_PRJ_LA_ISACTIVE_##project()           \
{                                                                    \
  static int DSY_active_##IntCode = DSYDevLACheckLevel(level);       \
  if ( DSY_active_##IntCode ==-1)                                    \
    {                                                                \
      if ( CATGetEnv((char*) #IntCode))                              \
	DSY_active_##IntCode  = 1;                                   \
      else                                                           \
	DSY_active_##IntCode = 0;                                    \
    }                                                                \
  return DSY_active_##IntCode;                                       \
}                                                                    \
 static int _DSYUnset##IntCode=0;                                    \
int ExportedByJS0LIB0 DSYSet_##project(int i)                   \
{                                                                    \
 _DSYUnset##IntCode=i;                                               \
 return  _DSYUnset##IntCode;                                         \
}
#else
#define IMPL_LA_PRJ(project,IntCode,level)			     \
int ExportedByJS0LIB0 DSY_PRJ_LA_ISACTIVE_##project()           \
{                                                                    \
  static int DSY_active_##IntCode =DSYDevLACheckLevel(level);        \
  if ( DSY_active_##IntCode ==-1)                                    \
    {                                                                \
      if ( CATGetEnv((char*) #IntCode))                              \
	DSY_active_##IntCode  = 1;                                   \
      else                                                           \
	DSY_active_##IntCode = 0;                                    \
    }                                                                \
  return DSY_active_##IntCode;                                       \
}                                                                    \
  static int _DSYUnset##IntCode=0;                                   \
int ExportedByJS0LIB0 DSYSet_##project (int i)                  \
{                                                                    \
 _DSYUnset##IntCode=i;                                               \
 return  _DSYUnset##IntCode;                                         \
}                                     
#endif
#else //Unix
#define IMPL_LA_PRJ(project,IntCode,level)			     \
int  ExportedByJS0LIB0 DSY_PRJ_LA_ISACTIVE_##project()                                \
{                                                                    \
  static int DSY_active_##IntCode = DSYDevLACheckLevel(level);       \
  if ( DSY_active_##IntCode ==-1)                                    \
    {                                                                \
      if ( CATGetEnv((char*) #IntCode))                              \
	DSY_active_##IntCode  = 1;                                   \
      else                                                           \
	DSY_active_##IntCode = 0;                                    \
    }                                                                \
  return DSY_active_##IntCode;                                       \
}                                                                    \
  static int _DSYUnset##IntCode=0;                             \
int ExportedByJS0LIB0 DSYSet_##project(int i)                                          \
{                                                                    \
 _DSYUnset##IntCode=i;                                               \
 return  _DSYUnset##IntCode;                                         \
}                                     
#endif




// anti-var variation
#ifdef _WINDOWS_SOURCE
#ifdef __JS0LIB0
#define IMPL_LA_PRJ_EXT(project,IntCode,level)          	     \
 static int _DSYUnset##IntCode=0;                                    \
int ExportedByJS0LIB0 DSY_PRJ_LA_ISACTIVE_##project()           \
{                                                                    \
  static int DSY_active_##IntCode = -1;                              \
  if ( DSY_active_##IntCode ==-1)                                    \
    {                                                                \
      int active = DSYDevLACheckLevel(level);			     \
      if (active == -1)						     \
	{							     \
	  if ( CATGetEnv((char*) #IntCode))			     \
	    DSY_active_##IntCode  = 1;				     \
	  else							     \
	    DSY_active_##IntCode = 0;				     \
	}							     \
      else if (active == 2)					     \
	{							     \
	  if ( _DSYUnset##IntCode)               		     \
	    DSY_active_##IntCode  = 0;				     \
	  else							     \
	    DSY_active_##IntCode = 1;				     \
	}							     \
    }								     \
  return DSY_active_##IntCode;                                       \
}                                                                    \
int ExportedByJS0LIB0 DSYSet_##project(int i)                   \
{                                                                    \
 _DSYUnset##IntCode=i;                                               \
 return  _DSYUnset##IntCode;                                         \
}                                                               
#else
#define IMPL_LA_PRJ_EXT(project,IntCode,level)	                     \
 static int _DSYUnset##IntCode=0;                                    \
int ExportedByJS0LIB0 DSY_PRJ_LA_ISACTIVE_##project()           \
{                                                                    \
  static int DSY_active_##IntCode = -1;                              \
  if ( DSY_active_##IntCode ==-1)                                    \
    {                                                                \
      int active = DSYDevLACheckLevel(level);			     \
      if (active == -1)						     \
	{							     \
	  if ( CATGetEnv((char*) #IntCode))			     \
	    DSY_active_##IntCode  = 1;				     \
	  else							     \
	    DSY_active_##IntCode = 0;				     \
	}							     \
      else if (active == 2)					     \
	{							     \
	  if ( _DSYUnset##IntCode)          	        	     \
	    DSY_active_##IntCode  = 0;				     \
	  else							     \
	    DSY_active_##IntCode = 1;				     \
	}							     \
    }								     \
  return DSY_active_##IntCode;                                       \
}                                                                    \
int ExportedByJS0LIB0 DSYSet_##project(int i)                   \
{                                                                    \
 _DSYUnset##IntCode=i;                                               \
 return  _DSYUnset##IntCode;                                         \
}                               
#endif
#else //Unix
#define IMPL_LA_PRJ_EXT(project,IntCode,level)			     \
 static int _DSYUnset##IntCode=0;                                    \
int  ExportedByJS0LIB0 DSY_PRJ_LA_ISACTIVE_##project()                                \
{                                                                    \
  static int DSY_active_##IntCode = -1;                              \
  if ( DSY_active_##IntCode ==-1)                                    \
    {                                                                \
      int active = DSYDevLACheckLevel(level);			     \
      if (active == -1)						     \
	{							     \
	  if ( CATGetEnv((char*) #IntCode))			     \
	    DSY_active_##IntCode  = 1;				     \
	  else							     \
	    DSY_active_##IntCode = 0;				     \
	}							     \
      else if (active == 2)					     \
	{							     \
	  if ( _DSYUnset##IntCode)         		             \
	    DSY_active_##IntCode  = 0;				     \
	  else							     \
	    DSY_active_##IntCode = 1;				     \
	}							     \
    }								     \
  return DSY_active_##IntCode;                                       \
}                                                                    \
int ExportedByJS0LIB0 DSYSet_##project(int i)                                         \
{                                                                    \
 _DSYUnset##IntCode=i;                                               \
 return  _DSYUnset##IntCode;                                         \
}   
#endif





// La variable d'environnement est le premier argument de la macro
// Le second est le nom de code interne et donc celui de la variable 
// d'environnement associe au projet 
// Le troisieme level est le niveau sur lequel la variable devient active par defaut
// Si level=210 alors le dev est pilote par variable sur R209 et inferieur et est 
// actif tout le temps en 210 et suivantes
// DEFINE_LA_PRJ(PRJ_RENAULT,PRJXXX,level) 
// Pour activer le PRJ_RENAULT faire export PRJXXX=1
// En cas d'ajout d'un nouveau projet PRJZZZ ne pas oublier d'aller mettre à jour
// System/JS0LIB0.m/src/DevLA.cpp pour y ajouter la macro IMPL_PRJ_VAR(PRJ_NEWCLIENT,PRJZZZ,level)
DEFINE_LA_PRJ(DEV_Renault_V6R2010x_FP2,RA_1012,209)
DEFINE_LA_PRJ(DEV_Renault_V6R2010x_FP3,RA_1013,209) 
DEFINE_LA_PRJ(DEV_Renault_V6R2011_FP1,RA_1101,210) 
DEFINE_LA_PRJ(DEV_DassaultAviation_V6R2011_FP1,ADA_1101,210)

DEFINE_LA_PRJ(DEV_Renault_V6R2011x_FD1,RA_1111,211)
DEFINE_LA_PRJ(DEV_Michelin_V6R2011x_FD1,MP_1111,211) 
DEFINE_LA_PRJ(DEV_DassaultAviation_V6R2011x_FD1,ADA_1111,211)
DEFINE_LA_PRJ(DEV_DassaultAviation_V6R2011x_FD2,ADA_1112,211)
DEFINE_LA_PRJ(DEV_Asus_V6R2011x_FD1,AC_1111,211)
DEFINE_LA_PRJ(DEV_Renault_V6R2011x_FD00,RA_1110,211)

DEFINE_LA_PRJ(DEV_DassaultAviation_V6R2011x_FD00,ADA_1110,211)
DEFINE_LA_PRJ(DEV_DassaultAviation_V6R2012_FD00,ADA_1200,212)

DEFINE_LA_PRJ(DEV_Renault_V6R2012_FD00,RA_1200,212)

DEFINE_LA_PRJ(DEV_Renault_V6R2011x_FD2,RA_1112,211)
DEFINE_LA_PRJ(DEV_MeyerWerft_V6R2011x_FD2,MWS_1112,211)

DEFINE_LA_PRJ(DEV_Renault_V6R2012x_FD00,RA_1210,213);
DEFINE_LA_PRJ(DEV_DassaultAviation_V6R2012x_FD00,ADA_1210,213);

DEFINE_LA_PRJ(DEV_Renault_V6R2012_FD1,RA_1201,212);
DEFINE_LA_PRJ(DEV_Renault_V6R2012_FD2,RA_1202,212);
DEFINE_LA_PRJ(DEV_DassaultAviation_V6R2012_FD1,ADA_1201,212);
DEFINE_LA_PRJ(DEV_DassaultAviation_V6R2012_FD2,ADA_1202,212);

DEFINE_LA_PRJ(DEV_Renault_V6R2012x_FD1,RA_1211,213);
DEFINE_LA_PRJ(DEV_Renault_V6R2012x_FD2,RA_1212,213);
DEFINE_LA_PRJ(DEV_DassaultAviation_V6R2012x_FD1,ADA_1211,213);
DEFINE_LA_PRJ(DEV_DassaultAviation_V6R2012x_FD2,ADA_1212,213);
DEFINE_LA_PRJ(DEV_DassaultAviation_V6R2013_FD00,ADA_1300,214);


DEFINE_LA_PRJ(DEV_Renault_V6R2013_FD1,RA_1301,214);
DEFINE_LA_PRJ(DEV_Renault_V6R2013_FD2,RA_1302,214);

DEFINE_LA_PRJ(DEV_Renault_V6R2013x_FD1,RA_1311,215);
DEFINE_LA_PRJ(DEV_Renault_V6R2013x_FD2,RA_1312,215);

DEFINE_LA_PRJ(V6Signature,DS_3DEXUx_1400,215);

#endif
