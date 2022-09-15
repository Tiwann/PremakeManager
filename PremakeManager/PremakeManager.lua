project "PremakeManager"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"

	targetdir(binaries)
	objdir(objs)

	files {
		"Source/**.cpp",
		"Source/**.h",
		"Source/**.inl"
	}

	includedirs {
        "%{wks.location}/Vendor/glfw/include",
        "%{wks.location}/Vendor/glad/include",
        "%{wks.location}/Vendor/spdlog/include",
        "%{wks.location}/Vendor/imgui",
	}

	defines {

	}

	links {
        "glfw",
        "glad",
        "spdlog",
        "imgui"
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