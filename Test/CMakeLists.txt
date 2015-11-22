include_directories( include )

add_executable(Test main.cpp RenderSystem.cpp Triangle.cpp)
SET(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin/")    #可执行生成后存放的目录(CMAKE_SOURCE_DIR是cmake目录)

#静态库生成后存放的目录
SET(LIBRARY_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/lib/")   


target_link_libraries( Test Engine ${OPENGL_LIBRARIES} ${GLEW_LIBRARY} ${GLFW_LIBRARY} ${FREEIMAGE_LIBRARY})