#pragma once

#include "brickpch.hpp"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace BrickEngine {

	class Log
	{
	public:
		Log() = delete;
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

#ifndef BRICKENGINE_DIST

		template<typename... Args>
		static void CoreTrace(const char* fmt, Args&&...args) { s_CoreLogger->trace(fmt, std::forward<Args>(args)...); }
		template<typename... Args>
		static void CoreInfo(const char* fmt, Args&&...args) { s_CoreLogger->info(fmt, std::forward<Args>(args)...); }
		template<typename... Args>
		static void CoreWarn(const char* fmt, Args&&...args) { s_CoreLogger->warn(fmt, std::forward<Args>(args)...); }
		template<typename... Args>
		static void CoreError(const char* fmt, Args&&...args) { s_CoreLogger->error(fmt, std::forward<Args>(args)...); }
		template<typename... Args>
		static void CoreFatal(const char* fmt, Args&&...args) { s_CoreLogger->critical(fmt, std::forward<Args>(args)...); }

		template<typename... Args>
		static void Trace(const char* fmt, Args&&...args) { s_ClientLogger->trace(fmt, std::forward<Args>(args)...); }
		template<typename... Args>
		static void Info(const char* fmt, Args&&...args) { s_ClientLogger->info(fmt, std::forward<Args>(args)...); }
		template<typename... Args>
		static void Warn(const char* fmt, Args&&...args) { s_ClientLogger->warn(fmt, std::forward<Args>(args)...); }
		template<typename... Args>
		static void Error(const char* fmt, Args&&...args) { s_ClientLogger->error(fmt, std::forward<Args>(args)...); }
		template<typename... Args>
		static void Fatal(const char* fmt, Args&&...args) { s_ClientLogger->critical(fmt, std::forward<Args>(args)...); }

#else

		// The compiler will remove these functions
		template<typename... Args>
		static void CoreTrace(const char* fmt, Args&&...args) {}
		template<typename... Args>
		static void CoreInfo(const char* fmt, Args&&...args) {}
		template<typename... Args>
		static void CoreWarn(const char* fmt, Args&&...args) {}
		template<typename... Args>
		static void CoreError(const char* fmt, Args&&...args) {}
		template<typename... Args>
		static void CoreFatal(const char* fmt, Args&&...args) {}

		template<typename... Args>
		static void Trace(const char* fmt, Args&&...args) {}
		template<typename... Args>
		static void Info(const char* fmt, Args&&...args) {}
		template<typename... Args>
		static void Warn(const char* fmt, Args&&...args) {}
		template<typename... Args>
		static void Error(const char* fmt, Args&&...args) {}
		template<typename... Args>
		static void Fatal(const char* fmt, Args&&...args) {}

#endif
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}
