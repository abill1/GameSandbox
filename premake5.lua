include "GameSandbox.lua"

workspace "GameSandbox"
	configurations {"Debug", "Release"}
	architecture "x64"
	location "./"
	startproject "GameSandbox"

	include "./GameSandbox/build.lua"
	include "./Engine/build.lua"
