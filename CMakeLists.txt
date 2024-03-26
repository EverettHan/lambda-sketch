cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_INSTALL_PREFIX "/home/zhn/install" CACHE STRING " " FORCE )
SET(CMAKE_MODULE_PATH "/home/zhn/install/lib64" CACHE STRING " " FORCE )
project(demo LANGUAGES CXX)
find_package(aws-lambda-runtime)
find_package(AWSSDK COMPONENTS core)


add_library(CATBasicTopologicalOpe SHARED IMPORTED)  # or STATIC instead of SHARED
set_target_properties(CATBasicTopologicalOpe PROPERTIES
  IMPORTED_NO_SONAME TRUE
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/ThirdParty/CGM_R425/linux_a64/code/bin/libCATBasicTopologicalOpe.so"
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/ThirdParty/CGM_R425/include"
)

add_library(CATMathStream SHARED IMPORTED)  # or STATIC instead of SHARED
set_target_properties(CATMathStream PROPERTIES
  IMPORTED_NO_SONAME TRUE
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/ThirdParty/CGM_R425/linux_a64/code/bin/libCATMathStream.so"
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/ThirdParty/CGM_R425/include"
)

add_library(CATMathematics SHARED IMPORTED)
set_target_properties(CATMathematics PROPERTIES
  IMPORTED_NO_SONAME TRUE
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/ThirdParty/CGM_R425/linux_a64/code/bin/libCATMathematics.so"
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/ThirdParty/CGM_R425/include"
)

add_library(CATGeometricObjects SHARED IMPORTED)
set_target_properties(CATGeometricObjects PROPERTIES
  IMPORTED_NO_SONAME TRUE
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/ThirdParty/CGM_R425/linux_a64/code/bin/libCATGeometricObjects.so"
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/ThirdParty/CGM_R425/include"
)

add_library(CATGMModelInterfaces SHARED IMPORTED)
set_target_properties(CATGMModelInterfaces PROPERTIES
  IMPORTED_NO_SONAME TRUE
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/ThirdParty/CGM_R425/linux_a64/code/bin/libCATGMModelInterfaces.so"
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/ThirdParty/CGM_R425/include"
)

add_library(CATGMGeometricInterfaces SHARED IMPORTED)
set_target_properties(CATGMGeometricInterfaces PROPERTIES
  IMPORTED_NO_SONAME TRUE
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/ThirdParty/CGM_R425/linux_a64/code/bin/libCATGMGeometricInterfaces.so"
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/ThirdParty/CGM_R425/include"
)

add_library(CATGMOperatorsInterfaces SHARED IMPORTED)
set_target_properties(CATGMOperatorsInterfaces PROPERTIES
  IMPORTED_NO_SONAME TRUE
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/ThirdParty/CGM_R425/linux_a64/code/bin/libCATGMOperatorsInterfaces.so"
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/ThirdParty/CGM_R425/include"
)

add_library(CATSGMOperatorsInterfaces SHARED IMPORTED)
set_target_properties(CATSGMOperatorsInterfaces PROPERTIES
  IMPORTED_NO_SONAME TRUE
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/ThirdParty/CGM_R425/linux_a64/code/bin/libCATSGMOperatorsInterfaces.so"
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/ThirdParty/CGM_R425/include"
)

add_library(CATSysTS SHARED IMPORTED)
set_target_properties(CATSysTS PROPERTIES
  IMPORTED_NO_SONAME TRUE
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/ThirdParty/CGM_R425/linux_a64/code/bin/libCATSysTS.so"
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/ThirdParty/CGM_R425/include"
)

add_library(CATTopologicalOperators SHARED IMPORTED)  # or STATIC instead of SHARED
set_target_properties(CATTopologicalOperators PROPERTIES
  IMPORTED_NO_SONAME TRUE
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/ThirdParty/CGM_R425/linux_a64/code/bin/libCATTopologicalOperators.so"
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/ThirdParty/CGM_R425/include"
)

add_library(JS0GROUP SHARED IMPORTED)
set_target_properties(JS0GROUP PROPERTIES
  IMPORTED_NO_SONAME TRUE
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/ThirdParty/CGM_R425/linux_a64/code/bin/libJS0GROUP.so"
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/ThirdParty/CGM_R425/include"
)

add_library(SWXSvSolverAPI SHARED IMPORTED)
set_target_properties(SWXSvSolverAPI PROPERTIES
  IMPORTED_NO_SONAME TRUE
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/ThirdParty/CGM_R425/linux_a64/code/bin/libSWXSvSolverAPI.so"
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/ThirdParty/CGM_R425/include"
)

add_library(SWXMathematics SHARED IMPORTED)
set_target_properties(SWXMathematics PROPERTIES
  IMPORTED_NO_SONAME TRUE
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/ThirdParty/CGM_R425/linux_a64/code/bin/libSWXMathematics.so"
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/ThirdParty/CGM_R425/include"
)

add_library(SWXUtGeneral SHARED IMPORTED)
set_target_properties(SWXUtGeneral PROPERTIES
  IMPORTED_NO_SONAME TRUE
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/ThirdParty/CGM_R425/linux_a64/code/bin/libSWXUtGeneral.so"
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/ThirdParty/CGM_R425/include"
)


add_library(SWXUtMemory SHARED IMPORTED)
set_target_properties(SWXUtMemory PROPERTIES
  IMPORTED_NO_SONAME TRUE
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/ThirdParty/CGM_R425/linux_a64/code/bin/libSWXUtMemory.so"
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/ThirdParty/CGM_R425/include"
)

set(HEADER_FILES 
    ${CMAKE_SOURCE_DIR}/ECBodyUtilities.h   
    ${CMAKE_SOURCE_DIR}/ECEdgeUtilities.h  
    ${CMAKE_SOURCE_DIR}/ECSketchConstraint.h  
    ${CMAKE_SOURCE_DIR}/ECSketchEntity.h      
    ${CMAKE_SOURCE_DIR}/ECSkSolverOptions.h   
    ${CMAKE_SOURCE_DIR}/ECWireUtilities.h 
    ${CMAKE_SOURCE_DIR}/ECCurveUtilities.h  
    ${CMAKE_SOURCE_DIR}/ECFaceUtilities.h  
    ${CMAKE_SOURCE_DIR}/ECSketchDataSet.h     
    ${CMAKE_SOURCE_DIR}/ECSurfaceUtilities.h
    ${CMAKE_SOURCE_DIR}/ECSketchSerializer.h
    )
set(SOURCES 
    main.cpp 
    ${HEADER_FILES}
    ECBodyUtilities.cpp   
    ECCurveUtilities.cpp 
    ECEdgeUtilities.cpp   
    ECFaceUtilities.cpp  
    ECSketchDataSet.cpp   
    ECSketchEntity.cpp   
    ECSketchSerializer.cpp 
    ECSkSolverOptions.cpp   
    ECSurfaceUtilities.cpp  
    ECWireUtilities.cpp
    )
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(
  ${PROJECT_NAME} PRIVATE 
  ${CMAKE_SOURCE_DIR}
)

target_link_libraries(
  ${PROJECT_NAME} PRIVATE 
  AWS::aws-lambda-runtime 
  ${AWSSDK_LINK_LIBRARIES} 
  CATBasicTopologicalOpe
  CATMathStream
  CATMathematics
  CATGeometricObjects
  CATGMModelInterfaces
  CATGMGeometricInterfaces
  CATGMOperatorsInterfaces
  CATSGMOperatorsInterfaces
  CATSysTS
  CATTopologicalOperators
  JS0GROUP
  SWXUtGeneral
  SWXMathematics
  SWXSvSolverAPI
  SWXUtMemory
)

target_compile_features(${PROJECT_NAME} PRIVATE "cxx_std_11")
target_compile_options(${PROJECT_NAME} PRIVATE "-Wall" "-Wextra")
target_compile_definitions(${PROJECT_NAME} PUBLIC 
    __CATGeometricObjectsCGM
    _CAT_ANSI_STREAMS
    CAT_ENABLE_NATIVE_EXCEPTION
    PLATEFORME_DS64
)

# this line creates a target that packages your binary and zips it up
aws_lambda_package_target(${PROJECT_NAME} NO_LIBC)
#aws_lambda_package_target(${PROJECT_NAME})