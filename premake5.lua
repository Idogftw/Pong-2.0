workspace "Pong-Game"
    architecture "x64"
    targetdir "build"
    
    configurations
    {
        "Debug", 
        "Release"
    }

    startproject "Pong"

outputdir = "%{cfg.system}-%{cfg.buildcfg}"

Includes = {}
Includes["glad"] = "binary/glad/include"
Includes["glfw"] = "binary/glfw/include"
Includes["glm"] = "binary/glm"
Includes["soil"] = "binary/soil"

include "binary/glfw"
include "binary/glad"

project "Pong"
    location "Pong"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-obj/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.c",
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "../binary",
        "%{Includes.glad}",
        "%{Includes.glfw}",
        "%{Includes.glm}",
        "%{Includes.soil}"
    }

    libdirs
    {
        "%{Includes.soil}"
    }

    links
    {
        "SOIL.lib",
        "glad",
        "glfw",
        "opengl32.lib"
    }