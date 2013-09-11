#pragma once

#include <string>
#include <utility>
#include <SDL.h>

namespace RescueHim {
    enum class Category {
        Application = SDL_LOG_CATEGORY_APPLICATION,
        Error = SDL_LOG_CATEGORY_ERROR,
        System = SDL_LOG_CATEGORY_SYSTEM,
        Audio = SDL_LOG_CATEGORY_AUDIO,
        Video = SDL_LOG_CATEGORY_VIDEO,
        Render = SDL_LOG_CATEGORY_RENDER,
        Input = SDL_LOG_CATEGORY_INPUT
    };

    enum class Severity {
        Verbose = SDL_LOG_PRIORITY_VERBOSE,
        Debug = SDL_LOG_PRIORITY_DEBUG,
        Info = SDL_LOG_PRIORITY_INFO,
        Warn = SDL_LOG_PRIORITY_WARN,
        Error = SDL_LOG_PRIORITY_ERROR,
        Critical = SDL_LOG_PRIORITY_CRITICAL
    };

    template<Category category, Severity severity>
    class Logger {
        public:
            template<typename... Args>
            static void log(const std::string& str, Args&&... args) {
                SDL_LogMessage((int)category, (SDL_LogPriority)severity, str.c_str(), std::forward<Args>(args)...);
            }
    };

    template<Severity S>
    using AppLog = Logger<Category::Application, S>;
}

