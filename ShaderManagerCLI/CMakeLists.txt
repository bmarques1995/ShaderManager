set(TARGET_NAME ShaderManagerCLI)

file(GLOB_RECURSE SHADER_MANAGER_CLI_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.cpp")

add_executable(${TARGET_NAME} ${SHADER_MANAGER_CLI_SOURCES})
target_link_libraries(${TARGET_NAME} PRIVATE ShaderManager)

set_cxx_project_standards(${TARGET_NAME} 20 FALSE)
target_installation_behaviour(
	CONFIG_FILE ${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.cmake.in
	TARGET_NAME ${TARGET_NAME}
	VERSION ${PROJECT_VERSION}
	PROJECT_NAME ${PROJECT_NAME}
	NAMESPACE "ShaderManager"
	COMPONENT "ShaderManager")