workspace "AutoFocus"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}

include "AutoFocus/Autofocus.lua"
include "Sandbox/Sandbox.lua"