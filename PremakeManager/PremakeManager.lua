project "PremakeManager"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "On"

	targetdir(binaries)
	objdir(objs)

	files {
		"Source/**.cpp",
		"Source/**.h",
		"Source/**.inl",
	}

	includedirs {
		"%{wks.location}/Vendor/glfw/include",
		"%{wks.location}/Vendor/glad/include",
		"%{wks.location}/Vendor/imgui",
		"%{wks.location}/Vendor/imgui/backends",
		"%{wks.location}/Vendor/fmt/include",
	}

	defines {
	}

	links {
		"glfw",
		"glad",
		"imgui",
		"fmt"
	}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"
		defines "PREMAN_DEBUG"

	filter "configurations:Release"
		runtime "Release"
		optimize "On"
		symbols "Off"

	filter "system:windows"
		defines "_CRT_SECURE_NO_WARNINGS"