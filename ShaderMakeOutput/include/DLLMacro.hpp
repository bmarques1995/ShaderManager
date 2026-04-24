#pragma once

#ifdef SHADER_MAKE_OUTPUT_SHARED
	#ifdef SHADER_MANAGER_EXPORTS
		#define SHADER_MAKE_OUTPUT_API __declspec(dllexport)
	#else
		#define SHADER_MAKE_OUTPUT_API __declspec(dllimport)
	#endif
#else
	#define SHADER_MAKE_OUTPUT_API
#endif