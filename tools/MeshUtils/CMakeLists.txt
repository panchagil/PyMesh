# Include this directory
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

# Enumerate source files
FILE(GLOB SRC_FILES *.cpp)
FILE(GLOB INC_FILES *.h)

ADD_LIBRARY(lib_MeshUtils SHARED ${SRC_FILES})
SET_TARGET_PROPERTIES(lib_MeshUtils PROPERTIES OUTPUT_NAME "MeshUtils")
TARGET_LINK_LIBRARIES(lib_MeshUtils Mesh)

set(SWG_FILES PyMeshUtils.i)

# Generate wrapper for python
SET_SOURCE_FILES_PROPERTIES(${SWG_FILES} PROPERTIES CPLUSPLUS ON)
SET_SOURCE_FILES_PROPERTIES(${SWG_FILES} PROPERTIES CMAKE_SWIG_FLAGS "-includeall")
SWIG_ADD_MODULE(PyMeshUtils python ${SWG_FILES})
SWIG_LINK_LIBRARIES(PyMeshUtils ${PYTHON_LIBRARIES} lib_MeshUtils Mesh)

# Boudle lib, swig wrapper into a single target.
# Usage: make MeshUtils
ADD_CUSTOM_TARGET(MeshUtils DEPENDS lib_MeshUtils _PyMeshUtils)