project "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/AutoFocus/src"
	}

	links
	{
		"AutoFocus"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	filter "system:linux"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		links
		{
			"opencv_core",
			"opencv_highgui",
			"opencv_imgproc"
		}

		linkoptions { "`pkg-config opencv4 --libs`" }

	filter "configurations:Debug"
		defines "AUTO_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AUTO_RELEASE"
		optimize "On"