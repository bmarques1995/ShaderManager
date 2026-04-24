# CMakeList.txt: projeto de CMake para ShaderManager, incluir origem e definir
# lógica específica a um projeto aqui.
#

# Adicione a origem ao executável deste projeto.
set(TARGET_NAME ShaderMakeOutput)
file(GLOB_RECURSE SHADER_MANAGER_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "lib/*.cpp")
file(GLOB_RECURSE SHADER_MANAGER_HEADERS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "include/*.hpp")

add_library(${TARGET_NAME} ${SHADER_MANAGER_SOURCES} ${SHADER_MANAGER_HEADERS})
target_include_directories(${TARGET_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                                                $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/lib>
                                                $<INSTALL_INTERFACE:include/ShaderMakeOutput>)


trace_library(NAME dxcompiler INSTALL_SCRIPT "${PROJECT_SOURCE_DIR}/installers/dxc.cmake.json")
trace_dependency(NAME flatbuffers INSTALL_SCRIPT "${PROJECT_SOURCE_DIR}/installers/flatbuffers.cmake.json")
target_link_libraries(${TARGET_NAME} PRIVATE dxcompiler)

if(BUILD_SHARED_LIBS)
  target_compile_definitions(${TARGET_NAME} PRIVATE SHADER_MAKE_OUTPUT_SHARED)
  if(WIN32)
    target_compile_definitions(${TARGET_NAME} PRIVATE SHADER_MAKE_OUTPUT_EXPORTS)
    target_compile_definitions(${TARGET_NAME} INTERFACE SHADER_MAKE_OUTPUT_IMPORTS)
  endif()
endif()

set_cxx_project_standards(${TARGET_NAME} 20 FALSE)
target_installation_behaviour(
	CONFIG_FILE ${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.cmake.in
	TARGET_NAME ${TARGET_NAME}
	VERSION ${PROJECT_VERSION}
	PROJECT_NAME ${PROJECT_NAME}
	NAMESPACE "ShaderMakeOutput"
	COMPONENT "ShaderMakeOutput"
	HEADER_INPUT ${CMAKE_CURRENT_SOURCE_DIR}/include 
	HEADER_OUTPUT ./include/ShaderMakeOutput)

# TODO: Adicione testes e instale destinos, se necessário.
