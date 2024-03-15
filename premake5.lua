include "GameSandbox.lua"

workspace "GameSandbox"
	configurations {"Debug", "Release"}
	architecture "x64"
	location "./"
	startproject "GameSandbox"


	include "./MemoryTracker/build.lua"
	include "./ABFramework/build.lua"
	include "./GLFW/build.lua"
	include "./GLAD/build.lua"
	include "./glm/build.lua"
	include "./Engine/build.lua"
	include "./GameSandbox/build.lua"

	
