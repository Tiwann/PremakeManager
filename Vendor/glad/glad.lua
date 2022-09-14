project "glad"
    kind "StaticLib"
    language "C"
    staticruntime "On"
    targetdir(binaries)
    objdir(objs)

    files {
        "glad.lua",
        "%{prj.location}/src/gl.c",
        "%{prj.location}/include/glad/gl.h",
        "%{prj.location}/include/KHR/khrplatform.h",
    }

    includedirs "%{prj.location}/include"

    	filter "configurations:Debug"
    		runtime "Debug"
    		symbols "On"

    	filter "configurations:Release"
    		runtime "Release"
    		optimize "On"
    		symbols "Off"
