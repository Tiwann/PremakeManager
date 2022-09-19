workspace "PremakeManager"
	architecture "x64"
	configurations { "Debug", "Release" }
	flags "MultiProcessorCompile"
	startproject "PremakeManager"

	binaries = "%{wks.location}/Binaries/%{cfg.buildcfg}"
	objs = "%{wks.location}/Intermediate"

	include "Vendor/Premake5/Clean.lua"
	include "PremakeManager/PremakeManager.lua"
	include "Vendor/glfw/glfw.lua"
	include "Vendor/glad/glad.lua"
	include "Vendor/imgui/imgui.lua"