
workspace "AerideusMem"
    architecture "x64"
    configurations { "Debug", "Release", "Dist" }

    filter "system:windows"
        defines { "AE_WINDOWS" }

    filter "system:macosx"
        defines { "AE_MACOS" }

    filter "system:linux"
        defines { "AE_LINUX" }

    filter "configurations:Debug"
        defines { "AE_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "AE_RELEASE" }
        optimize "On"

    filter "configurations:Dist"
        defines { "AE_DIST" }
        optimize "Speed"
        symbols "Off"

    filter "action:vs*"
        startproject "Sandbox"

project "AerideusLog1_0"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    targetdir "bin/%{cfg.buildcfg}"
    objdir "obj/%{cfg.buildcfg}"
    
    files { "AerideusLog1_0/src/*.c", "AerideusLog1_0/include/*.h", "AerideusLog1_0/internal/*.h" }


project "AerideusMem"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    targetdir "bin/%{cfg.buildcfg}"
    objdir "obj/%{cfg.buildcfg}"

    files { "AerideusMem/src/*.c", "AerideusMem/include/*.h", "AerideusMem/internal/*.h" }

    includedirs { "AerideusLog1_0/include" }
    links { "AerideusLog1_0" }

project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    targetdir "bin/%{cfg.buildcfg}"
    objdir "obj/%{cfg.buildcfg}"
  
    files { "Sandbox/src/*.c", "Sandbox/src/*.h" }

    includedirs { "AerideusMem/include", "AerideusLog1_0/include" }
    links { "AerideusMem", "AerideusLog1_0" }
