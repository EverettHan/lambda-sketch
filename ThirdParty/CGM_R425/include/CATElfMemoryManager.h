#ifndef CATElfMemoryManager_H
#define CATElfMemoryManager_H

#include "CATELFMathKernel.h"
#include "CATElfBasicTypes.h"
#include "CATElfTypeEncapMemory.h"
#include <stdio.h>


class ExportedByCATELFMathKernel CATElfMemoryManager 
{

  public :

    CATElfMemoryManager(int TailleExtension=100);     // constructeur
    virtual ~CATElfMemoryManager();                   // destructeur


    /**
    * Allocation with encapsulated type : will determine automatically
    * the type of the array to allocate.
    *
    * // ----------------------
    * // Source code example  :
    * // ----------------------
    *
    * // sizes of the arrays
    *
    * int NtDeg(xxx), NtCin(xxx) ;
    * const int Array2Size(44), Array4Size(110), Array5Size(10) ;
    *
    * // arrays
    *
    * char **tabSTRUCT=NULL;
    * int    *Array1=NULL, *Array3=NULL ;
    * float  *Array2=NULL ;
    * double *Array4=NULL ;
    * char   *Array5=NULL ;
    * 
    * // allocation
    *
    * CATElfMemoryManager Memory;
    * int indall(0);
    *
    * hr = Memory.Allocation(indall,
    *                        tabSTRUCT,5,
    *                        Array1,NtDeg,
    *                        Array2,Array2Size,
    *                        Array3,NtCin,
    *                        Array4,Array4Size,
    *                        Array5,Array5Size);
    * if (hr != S_OK) return hr ;
    * 
    **/

    HRESULT Allocation(
        int&  oIndice, 
        CATElfTypeEncapMemory p1                                      , int iN1   ,
        CATElfTypeEncapMemory p2 =CATElfTypeEncapMemory::EmptyEncapMem, int iN2 =0,
        CATElfTypeEncapMemory p3 =CATElfTypeEncapMemory::EmptyEncapMem, int iN3 =0,
        CATElfTypeEncapMemory p4 =CATElfTypeEncapMemory::EmptyEncapMem, int iN4 =0,
        CATElfTypeEncapMemory p5 =CATElfTypeEncapMemory::EmptyEncapMem, int iN5 =0,
        CATElfTypeEncapMemory p6 =CATElfTypeEncapMemory::EmptyEncapMem, int iN6 =0,
        CATElfTypeEncapMemory p7 =CATElfTypeEncapMemory::EmptyEncapMem, int iN7 =0,
        CATElfTypeEncapMemory p8 =CATElfTypeEncapMemory::EmptyEncapMem, int iN8 =0,
        CATElfTypeEncapMemory p9 =CATElfTypeEncapMemory::EmptyEncapMem, int iN9 =0,
        CATElfTypeEncapMemory p10=CATElfTypeEncapMemory::EmptyEncapMem, int iN10=0,
        CATElfTypeEncapMemory p11=CATElfTypeEncapMemory::EmptyEncapMem, int iN11=0
        );

    /**
    * Allocation without encapsulated type : give the address of a char* and the real length of allocation
    *
    * // ----------------------
    * // Source code example  :
    * // ----------------------
    *
    * // sizes of the arrays
    *
    * int NtDeg(xxx), NtCin(xxx) ;
    * const int Array2Size(44), Array4Size(110), Array5Size(10) ;
    *
    * // arrays
    *
    * char **tabSTRUCT=NULL;
    * int    *Array1=NULL, *Array3=NULL ;
    * float  *Array2=NULL ;
    * double *Array4=NULL ;
    * char   *Array5=NULL ;
    * 
    * // arrays necessary for allocation
    *
    * char *tabtabSTRUCT=NULL, *tabArray1=NULL, *tabArray2=NULL, *tabArray3=NULL, *tabArray4=NULL, *tabArray5=NULL;
    *
    * // allocation
    *
    * CATElfMemoryManager Memory;
    * int indall(0);
    *
    * hr = Memory.Allocation(6,indall,
    *                        tabtabSTRUCT,5      *sizeof(char*),
    *                        tabArray1,NtDeg     *sizeof(int),
    *                        tabArray2,Array2Size*sizeof(float),
    *                        tabArray3,NtCin     *sizeof(int),
    *                        tabArray4,Array4Size*sizeof(double),
    *                        tabArray5,Array5Size*sizeof(char));
    * if (hr != S_OK) return hr ;
    *
    * // copy of the address
    *
    * tabSTRUCT= (char**) tabtabSTRUCT ;
    * Array1= (int*)    tabArray1 ;
    * Array3= (int*)    tabArray3 ;
    * Array2= (float*)  tabArray2 ;
    * Array4= (double*) tabArray4 ;
    * Array5= (char*)   tabArray5 ;
    *
    **/
    
    HRESULT Allocation(int NbTab,  int& oIndice, 
        char** tab1, LongInt N1,
        char** tab2 = NULL,  LongInt N2 = 0, 
        char** tab3 = NULL,  LongInt N3 = 0, 
        char** tab4 = NULL,  LongInt N4 = 0,
        char** tab5 = NULL,  LongInt N5 = 0,
        char** tab6 = NULL,  LongInt N6 = 0,
        char** tab7 = NULL,  LongInt N7 = 0, 
        char** tab8 = NULL,  LongInt N8 = 0,
        char** tab9 = NULL,  LongInt N9 = 0,
        char** tab10 = NULL, LongInt N10 = 0, 
        char** tab11 = NULL, LongInt N11 = 0
        );
    

    /**
    *
    *
    **/

    HRESULT Allocation(int NbTab, int& oIndice, char**& tab1, LongInt* iSizes);

    /**
    *
    *
    **/


    HRESULT Desallocation(int indice);
    HRESULT Desallocation(int size, int* indice);
    HRESULT Desallocation(int iIndice, char**& iTab);

    /**
    *
    *
    **/

    void SetModeWarning(int WarnID = 1026);

    /**
    *
    *
    **/

    void ResetModeWarning();

    /**
    *
    *
    **/

    int     GetIndiceAllocation();

    /**
    *
    *
    **/

    HRESULT Reallocation( int indice, char*& Tableau, LongInt taille);

    /**
    *
    *
    **/
    HRESULT ManualReallocation( int &indice, char* &Tableau, LongInt taille, LongInt taille_agrandie);

    /**
    *
    *
    **/

    float GetMemoryUsed();




    // -------------------------------------------------------------
    // ----------------------------- PRIVATE -----------------------
    // -------------------------------------------------------------

private :

    HRESULT DestructionElement(char*& iListe);

    HRESULT ExtensionTable();

    /**
    * _TableAllocations : 
    * adresses de bases des zones allouees
    **/

    char**               _TableAllocations;

    /**
    * _TableTailles : 
    * tailles des zones alloues
    **/

    LongInt*                 _TableTailles;

    /**
    * _PtrDeFinPourUnIndice : 
    * pointeurs de fin dans _TableAllocations et _TableTailles 
    * quand les zones sont allouees allouees separement
    **/

    int*                 _PtrDeFinPourUnIndice;

    /**
    * _TailleTable : 
    * taille allouee de _TableAllocations et _TableTailles
    **/

    int                  _TailleTable;             

    int                  _IndiceCourant;
    int                  _IndiceMax;
    LongInt                  _TailleExtension;
    LongInt                  _TailleDejaAllouee;
    LongInt                  _TailleMaxAllouee;
    int                  _ModeWarning;
    int                  _ModeAllocMultiple;

};


#endif
