#pragma once

#ifdef SHADER_MANAGER_SHARED
	#ifdef SHADER_MANAGER_EXPORTS
		#define SHADER_MANAGER_API __declspec(dllexport)
	#else
		#define SHADER_MANAGER_API __declspec(dllimport)
	#endif
#else
	#define SHADER_MANAGER_API
#endif