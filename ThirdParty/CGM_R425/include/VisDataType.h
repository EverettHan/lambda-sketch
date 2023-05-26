#ifndef VISDATATYPE_H
#define VISDATATYPE_H

// COPYRIGHT DASSAULT SYSTEMES 2009

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

/**
 * Defines the variable that handles Visualization objects size.
 */
typedef unsigned int VisSize;

/**
 * Defines the types of variables that can be handled by Visualization objects.
 * @param VIS_UNSIGNED_CHAR
 * Corresponds to an unsigned char variable.
 * @param VIS_UNSIGNED_SHORT
 * Corresponds to an unsigned short variable.
 * @param VIS_UNSIGNED_INT
 * Corresponds to an unsigned int variable.
 * @param VIS_CHAR
 * Corresponds to a char variable.
 * @param VIS_SHORT
 * Corresponds to a short variable.
 * @param VIS_INT
 * Corresponds to an int variable.
 * @param VIS_FLOAT
 * Corresponds to a float variable.
 * @param VIS_DOUBLE
 * Corresponds to a double variable.
 * @param VIS_UNSIGNED_CHAR_2
 * Corresponds to an array of two unsigned char variables: unsigned char[2].
 * @param VIS_UNSIGNED_SHORT_2
 * Corresponds to an array of two unsigned short variables: unsigned short[2].
 * @param VIS_UNSIGNED_INT_2
 * Corresponds to an array of two unsigned int variables: unsigned int[2].
 * @param VIS_CHAR_2
 * Corresponds to an array of two char variables: char[2].
 * @param VIS_SHORT_2
 * Corresponds to an array of two short variables: short[2].
 * @param VIS_INT_2
 * Corresponds to an array of two int variables: int[2].
 * @param VIS_FLOAT_2
 * Corresponds to an array of two float variables: float[2].
 * @param VIS_DOUBLE_2
 * Corresponds to an array of two double variables: double[2].
 * @param VIS_UNSIGNED_CHAR_3
 * Corresponds to an array of three unsigned char variables: unsigned char[3].
 * @param VIS_UNSIGNED_SHORT_3
 * Corresponds to an array of three unsigned short variables: unsigned short[3].
 * @param VIS_UNSIGNED_INT_3
 * Corresponds to an array of three unsigned int variables: unsigned int[3].
 * @param VIS_CHAR_3
 * Corresponds to an array of three char variables: char[3].
 * @param VIS_SHORT_3
 * Corresponds to an array of three short variables: short[3].
 * @param VIS_INT_3
 * Corresponds to an array of three int variables: int[3].
 * @param VIS_FLOAT_3
 * Corresponds to an array of three float variables: float[3].
 * @param VIS_DOUBLE_3
 * Corresponds to an array of three double variables: double[3].
 * @param VIS_UNSIGNED_CHAR_4
 * Corresponds to an array of four unsigned char variables: unsigned char[4].
 * @param VIS_UNSIGNED_SHORT_4
 * Corresponds to an array of four unsigned short variables: unsigned short[4].
 * @param VIS_UNSIGNED_INT_4
 * Corresponds to an array of four unsigned int variables: unsigned int[4].
 * @param VIS_CHAR_4
 * Corresponds to an array of four char variables: char[4].
 * @param VIS_SHORT_4
 * Corresponds to an array of four short variables: short[4].
 * @param VIS_INT_4
 * Corresponds to an array of four int variables: int[4].
 * @param VIS_FLOAT_4
 * Corresponds to an array of four float variables: float[4].
 * @param VIS_DOUBLE_4
 * Corresponds to an array of four double variables: double[4].
 * @param VIS_FLOAT_9
 * Corresponds to an array of nine float variables: float[9].
 * @param VIS_DOUBLE_9
 * Corresponds to an array of nine double variables: double[9].
 * @param VIS_MATRIX_3x3
 * Corresponds to an instance of a CAT3x3Matrix object.
 * @param VIS_FLOAT_16
 * Corresponds to an array of sixteen float variables: float[16].
 * @param VIS_DOUBLE_16
 * Corresponds to an array of sixteen double variables: double[16].
 * @param VIS_MATRIX_4x4
 * Corresponds to an instance of a CAT4x4Matrix object.
 */

typedef enum _VisDataType
{
  VIS_UNSIGNED_CHAR,
  VIS_UNSIGNED_SHORT,
  VIS_UNSIGNED_INT,
  VIS_CHAR,
  VIS_SHORT,
  VIS_INT,
  VIS_FLOAT,
  VIS_DOUBLE,
  VIS_UNSIGNED_CHAR_2,
  VIS_UNSIGNED_SHORT_2,
  VIS_UNSIGNED_INT_2,
  VIS_CHAR_2,
  VIS_SHORT_2,
  VIS_INT_2,
  VIS_FLOAT_2,
  VIS_DOUBLE_2,
  VIS_UNSIGNED_CHAR_3,
  VIS_UNSIGNED_SHORT_3,
  VIS_UNSIGNED_INT_3,
  VIS_CHAR_3,
  VIS_SHORT_3,
  VIS_INT_3,
  VIS_FLOAT_3,
  VIS_DOUBLE_3,
  VIS_UNSIGNED_CHAR_4,
  VIS_UNSIGNED_SHORT_4,
  VIS_UNSIGNED_INT_4,
  VIS_CHAR_4,
  VIS_SHORT_4,
  VIS_INT_4,
  VIS_FLOAT_4,
  VIS_DOUBLE_4,
  VIS_FLOAT_9,
  VIS_DOUBLE_9,
  VIS_MATRIX_3x3,
  VIS_FLOAT_16,
  VIS_DOUBLE_16,
  VIS_MATRIX_4x4,
  VIS_RAWBUFFER_PTR
} VisDataType;

/** 
 * Get the number of component of a VisDataType object.
 */
inline VisSize GetVisDataTypeComponentCount(VisDataType iDataType)          
{                                             
  VisSize NbComponents = 0;                   
                                              
  switch (iDataType)                          
  {                                           
  case VIS_UNSIGNED_CHAR:                     
  case VIS_UNSIGNED_SHORT:                    
  case VIS_UNSIGNED_INT:                      
  case VIS_CHAR:                              
  case VIS_SHORT:                             
  case VIS_INT:                               
  case VIS_FLOAT:                             
  case VIS_DOUBLE:                            
  case VIS_RAWBUFFER_PTR:
    NbComponents = 1;                         
    break;                                    
                                              
  case VIS_UNSIGNED_CHAR_2:                   
  case VIS_UNSIGNED_SHORT_2:                  
  case VIS_UNSIGNED_INT_2:                    
  case VIS_CHAR_2:                            
  case VIS_SHORT_2:                           
  case VIS_INT_2:                             
  case VIS_FLOAT_2:                           
  case VIS_DOUBLE_2:                          
    NbComponents = 2;                         
    break;                                    
                                              
  case VIS_UNSIGNED_CHAR_3:                   
  case VIS_UNSIGNED_SHORT_3:                  
  case VIS_UNSIGNED_INT_3:                    
  case VIS_CHAR_3:                            
  case VIS_SHORT_3:                           
  case VIS_INT_3:                             
  case VIS_FLOAT_3:                           
  case VIS_DOUBLE_3:                          
    NbComponents = 3;                         
    break;                                    
                                              
  case VIS_UNSIGNED_CHAR_4:                   
  case VIS_UNSIGNED_SHORT_4:                  
  case VIS_UNSIGNED_INT_4:                    
  case VIS_CHAR_4:                            
  case VIS_SHORT_4:                           
  case VIS_INT_4:                             
  case VIS_FLOAT_4:                           
  case VIS_DOUBLE_4:                          
    NbComponents = 4;                         
    break;                                    
                                              
  case VIS_FLOAT_9:                           
  case VIS_DOUBLE_9:                          
    NbComponents = 9;                         
    break;                                    
                                              
  case VIS_FLOAT_16:                          
  case VIS_DOUBLE_16:                         
    NbComponents = 16;                        
    break;                                    
                                              
  }                                           
                                              
  return NbComponents;                        
};

/** 
 * Computes the size of a VisDataType object.
 */
inline VisSize SizeOfVisDataType(VisDataType iDataType)          
{                                             
  VisSize SizeOfComponent = 0;                
                                              
  switch (iDataType)                          
  {                                           
  case VIS_UNSIGNED_CHAR:                     
  case VIS_UNSIGNED_CHAR_2:                   
  case VIS_UNSIGNED_CHAR_3:                   
  case VIS_UNSIGNED_CHAR_4:                   
    SizeOfComponent = sizeof(unsigned char);  
    break;                                    
                                              
  case VIS_UNSIGNED_SHORT:                    
  case VIS_UNSIGNED_SHORT_2:                  
  case VIS_UNSIGNED_SHORT_3:                  
  case VIS_UNSIGNED_SHORT_4:                  
    SizeOfComponent = sizeof(unsigned short); 
    break;                                    
                                              
  case VIS_UNSIGNED_INT:                      
  case VIS_UNSIGNED_INT_2:                    
  case VIS_UNSIGNED_INT_3:                    
  case VIS_UNSIGNED_INT_4:                    
    SizeOfComponent = sizeof(unsigned int);   
    break;                                    
                                              
  case VIS_CHAR:                              
  case VIS_CHAR_2:                            
  case VIS_CHAR_3:                            
  case VIS_CHAR_4:                            
    SizeOfComponent = sizeof(char);           
    break;                                    
                                              
  case VIS_SHORT:                             
  case VIS_SHORT_2:                           
  case VIS_SHORT_3:                           
  case VIS_SHORT_4:                           
    SizeOfComponent = sizeof(short);          
    break;                                    
                                              
  case VIS_INT:                               
  case VIS_INT_2:                             
  case VIS_INT_3:                             
  case VIS_INT_4:                             
    SizeOfComponent = sizeof(int);            
    break;                                    
                                              
  case VIS_FLOAT:                             
  case VIS_FLOAT_2:                           
  case VIS_FLOAT_3:                           
  case VIS_FLOAT_4:                           
  case VIS_FLOAT_9:                           
  case VIS_FLOAT_16:                          
    SizeOfComponent = sizeof(float);          
    break;                                    
                                              
  case VIS_DOUBLE:                            
  case VIS_DOUBLE_2:                          
  case VIS_DOUBLE_3:                          
  case VIS_DOUBLE_4:                          
  case VIS_DOUBLE_9:                          
  case VIS_DOUBLE_16:                         
    SizeOfComponent = sizeof(double);         
    break;  

  case VIS_RAWBUFFER_PTR:
    SizeOfComponent = sizeof(void*);                                  
  }                                           
                                              
  return GetVisDataTypeComponentCount(iDataType) * SizeOfComponent;                     
};

/** 
 * Get base VisDataType of a VisDataType object.
 */
inline VisDataType GetBaseVisDataType(VisDataType iDataType)          
{                                             
  switch (iDataType)                          
  {                                           
  case VIS_UNSIGNED_CHAR:                     
  case VIS_UNSIGNED_CHAR_2:                   
  case VIS_UNSIGNED_CHAR_3:                   
  case VIS_UNSIGNED_CHAR_4:                   
    return VIS_UNSIGNED_CHAR;

  case VIS_UNSIGNED_SHORT:                    
  case VIS_UNSIGNED_SHORT_2:                  
  case VIS_UNSIGNED_SHORT_3:                  
  case VIS_UNSIGNED_SHORT_4:                  
    return VIS_UNSIGNED_SHORT;                                
                                              
  case VIS_UNSIGNED_INT:                      
  case VIS_UNSIGNED_INT_2:                    
  case VIS_UNSIGNED_INT_3:                    
  case VIS_UNSIGNED_INT_4:                    
    return VIS_UNSIGNED_INT;                                   
                                              
  case VIS_CHAR:                              
  case VIS_CHAR_2:                            
  case VIS_CHAR_3:                            
  case VIS_CHAR_4:                            
    return VIS_CHAR;                                   
                                              
  case VIS_SHORT:                             
  case VIS_SHORT_2:                           
  case VIS_SHORT_3:                           
  case VIS_SHORT_4:                           
    return VIS_SHORT;                                  
                                              
  case VIS_INT:                               
  case VIS_INT_2:                             
  case VIS_INT_3:                             
  case VIS_INT_4:                             
    return VIS_INT;                                 
                                              
  case VIS_FLOAT:                             
  case VIS_FLOAT_2:                           
  case VIS_FLOAT_3:                           
  case VIS_FLOAT_4:                           
  case VIS_FLOAT_9:                           
  case VIS_FLOAT_16:                          
    return VIS_FLOAT;                                 
                                              
  case VIS_DOUBLE:                            
  case VIS_DOUBLE_2:                          
  case VIS_DOUBLE_3:                          
  case VIS_DOUBLE_4:                          
  case VIS_DOUBLE_9:                          
  case VIS_DOUBLE_16:                         
    return VIS_DOUBLE;                                  

  case VIS_RAWBUFFER_PTR:
    return VIS_RAWBUFFER_PTR;
  }

  return VIS_UNSIGNED_CHAR;
};

#endif // VISDATATYPE_H
