// COPYRIGHT DASSAULT SYSTEMES 2000
/** @required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/

#define CATLISTPP_LittleSize 5
#define CATLISTPP_NormalSize 10

// Permet de resoudre les problemes de dependance entre methodes
// pour la compilation des fichiers ListOfCAThvo...
// --------------------------------------------------------------

#define CATLISTPP_Append

#ifdef CATLISTPP_RemoveList
#define CATLISTPP_RemoveValue
#endif

#ifdef CATLISTPP_RemoveValue
#define CATLISTPP_Locate
#define CATLISTPP_RemovePosition
#endif

#ifdef CATLISTPP_RemoveNulls
#define CATLISTPP_RemovePosition
#endif

#ifdef CATLISTPP_RemoveDuplicates
#define CATLISTPP_RemovePosition
#endif

#ifdef CATLISTPP_Intersection
#define CATLISTPP_AppendList
#endif

// Listes des methode que l'on peut rajouter
// dans les fichiers header.
// -----------------------------------------

//#define CATLISTPP_AppendList
//#define CATLISTPP_InsertAt
//#define CATLISTPP_ReSize
//#define CATLISTPP_Storage
//#define CATLISTPP_Locate
//#define CATLISTPP_RemoveValue
//#define CATLISTPP_RemoveList
//#define CATLISTPP_RemovePosition
//#define CATLISTPP_RemoveAll
//#define CATLISTPP_RemoveNulls
//#define CATLISTPP_RemoveDuplicates
//#define CATLISTPP_Compare
//#define CATLISTPP_Swap
//#define CATLISTPP_QuickSort
//#define CATLISTPP_FillArrayPtrs
//#define CATLISTPP_NbOccur
//#define CATLISTPP_Intersection
