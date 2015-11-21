# Copyright (C) 2016 jaccen

# we need features that are 2.6 >= dependent
cmake_minimum_required (VERSION 2.6)

# lets name the project
PROJECT(Jac-3DEngine)

# add the -c and -Wall flags
add_definitions(
	-c
	-Wall
)
add_subdirectory(Engine/include)
add_subdirectory(External/include)
add_subdirectory(Test)
set(CXX_FLAGS
    -g
    -Wall
    #-Werror
)
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")
if ( CMAKE_BUILD_TYPE STREQUAL "" )
	# CMake defaults to leaving CMAKE_BUILD_TYPE empty. This screws up
	# differentiation between debug and release builds.
	set(
		CMAKE_BUILD_TYPE
			"Debug"
		CACHE STRING
			"Choose the type of build, options are: None (CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) \"Debug\" \"Release\" \"RelWithDebInfo\" \"MinSizeRel\"."
		FORCE
	)
endif ( CMAKE_BUILD_TYPE STREQUAL "" )

if ( CMAKE_BUILD_TYPE STREQUAL "Release" )
add_definitions( -O2 )
endif ( CMAKE_BUILD_TYPE STREQUAL "Release" )

