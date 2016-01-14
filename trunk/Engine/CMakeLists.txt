cmake_minimum_required(VERSION 2.8)

project(Engine)
#��̬�����ɺ��ŵ�Ŀ¼
SET(LIBRARY_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/lib/")             

IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	# Mac OS X

	# Support only desktop
	
    SET(Processor "x64")
    SET(OperatingSystem "Darwin")
    SET(Compiler "GCC")

	set(ENV_DIR ${Processor}/${OperatingSystem}/${Compiler})
	
	include_directories(${ENGINE_SOURCE_DIR}/../External/include)

ELSEIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	# Linux

	IF(${CMAKE_SYSTEM_PROCESSOR} MATCHES "arm")
		# Raspberry Pi and i.MX6
		
		SET(OpenGL "ES2")
		
		add_definitions(-DGLUS_ES2)

		IF(${SoC} MATCHES "iMX6")
			# i.MX6

			# Everything is in /usr/include

		ELSE()
			# Raspberry Pi

			include_directories(/opt/vc/include /opt/vc/include/interface/vcos/pthreads /opt/vc/include/interface/vmcs_host/linux)		

		ENDIF()
		
	ELSE()
		# Support only desktop
	
		SET(Processor "x64")
		SET(OperatingSystem "Linux")
		SET(Compiler "GCC")
		
		set(ENV_DIR ${Processor}/${OperatingSystem}/${Compiler})

		# External directories
		include_directories(${ENGINE_SOURCE_DIR}/../External/include)		
		
	ENDIF()
	
ELSEIF(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	# Windows
	
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
	
	IF(${OpenGL} MATCHES "ES31")
		# Desktop OpenGL ES 3.1

		add_definitions(-DGLUS_ES31)
	
		include_directories(${ENGINE_SOURCE_DIR}/../External/include)	

	ELSEIF(${OpenGL} MATCHES "ES2")
		# Desktop OpenGL ES 2.0

		add_definitions(-DGLUS_ES2)
	
		include_directories(${ENGINE_SOURCE_DIR}/../External/include)	

	ELSEIF(${OpenGL} MATCHES "ES")
		# Desktop OpenGL ES 3.0

		add_definitions(-DGLUS_ES)
	
		include_directories(${ENGINE_SOURCE_DIR}/../External/include)	

	ELSE()
		# Desktop

		SET(Processor "x86")
		SET(OperatingSystem "Windows")
		SET(Compiler "MSVC")
		
		set(ENV_DIR ${Processor}/${OperatingSystem}/${Compiler})
		
		include_directories(${ENGINE_SOURCE_DIR}/../External/include)	
	
	ENDIF()
		
ENDIF()

# Source files
file(GLOB_RECURSE CPP_FILES ${Engine_SOURCE_DIR}/src/*.cpp)


# Header files
file(GLOB_RECURSE H_FILES ${Engine_SOURCE_DIR}/include/*.h)

# ע�⣬����ָ������·����  
INCLUDE_DIRECTORIES(${ENGINE_SOURCE_DIR}/include)  
#�Ƕ��幤�̵Ŀ��ļ������д���ſ��ļ�
#LINK_DIRECTORIES(${EXTERNAL_SOURCE_DIR}/lib)

#SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
#SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

add_library(Engine ${CPP_FILES} ${H_FILES})