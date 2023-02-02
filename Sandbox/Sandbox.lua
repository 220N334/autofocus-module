project "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")
	
	links
	{
		"opencv_core", "opencv_highgui", "opencv_imgproc", "opencv_imgcodecs", "AutoFocus",  "raspicam", "raspicam_cv", "wiringPi", "pthread"
	}

	files
	{
		"src/**.h",
		"src/**.cpp",
		"src/**.hpp"
	}

	includedirs
	{
		"%{wks.location}/AutoFocus/src",
		"%{wks.location}/AutoFocus/vendor/RaspiCam/src/",
		"/usr/local/include/opencv4"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	filter "system:linux"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	filter "configurations:Debug"
		defines "AUTO_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AUTO_RELEASE"
		optimize "On"
