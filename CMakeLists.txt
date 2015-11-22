CMAKE_MINIMUM_REQUIRED(VERSION 2.8 FATAL_ERROR)

# бу?б└???
SET(Visual_VERSION_MAJOR 0)
SET(Visual_VERSION_MINOR 1)

PROJECT( Visuail)
INCLUDE_DIRECTORIES(${Visuail_SOURCE_DIR}/External/include )
INCLUDE_DIRECTORIES(${Visuail_SOURCE_DIR}/Engine/include )
INCLUDE_DIRECTORIES(${Visuail_SOURCE_DIR}/Asset)

MESSAGE(STATUS "operation system is ${CMAKE_SYSTEM}")

IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
	MESSAGE(STATUS "current platform: Linux ")
      LINK_DIRECTORIES( 
	/usr/lib64/)

ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
	MESSAGE(STATUS "current platform: Windows")
    find_package(OpenGL REQUIRED)
    include_directories(${OpenGL_INCLUDE_DIRS})
    link_directories(${OpenGL_LIBRARY_DIRS})
    add_definitions(${OpenGL_DEFINITIONS})

    if(NOT OpenGL_FOUND)
            message(Error "OpenGL not found")
    endif(NOT OpenGL_FOUND)
       find_library( GLEW_LIBRARY glew32.lib External/lib)
       find_library( GLFW_LIBRARY glfw3.lib External/lib)
       find_library( FREEIMAGE_LIBRARY FreeImage.lib External/lib)
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
	MESSAGE(STATUS "current platform: FreeBSD")
ELSE ()
	MESSAGE(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")

SUBDIRS( Engine Test)