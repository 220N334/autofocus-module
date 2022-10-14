workspace "AutoFocus"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}

include "AutoFocus/AutoFocus.lua"
include "AutoFocus/vendor/LCCV/LCCV.lua"

include "Sandbox/Sandbox.lua"