
function CreateProject( projectname )
	project(projectname)
		kind "ConsoleApp"
		language "C++"
		cppdialect "C++14"

		flags
	{
		"MultiProcessorCompile"
	}

		targetdir "%{wks.location}/build/bin/%{cfg.architecture}-%{cfg.buildcfg}/"
		objdir "%{wks.location}/build/obj/%{cfg.architecture}-%{cfg.buildcfg}/%{prj.name}/"

		location("%{wks.location}/" .. projectname)
		files
		{
			"%{prj.location}/**.h", "%{prj.location}/**.hpp", "%{prj.location}/**.hh", "%{prj.location}/**.hxx",  
            "%{prj.location}/**.c", "%{prj.location}/**.cpp", "%{prj.location}/**.cc", "%{prj.location}/**.cxx",
            "%{prj.location}/**.lua", "%{prj.location}/**.txt", "%{prj.location}/**.md", "%{prj.location}/**.ini",
		}

		includedirs { "%{wks.location}", "%{prj.location}" }

		filter "configurations:Debug"
			defines {"DEBUG", "_DEBUG"}
			symbols "On"
		filter {}

		filter "configurations:Release"
			defines {"NDEBUG"}
			optimize "On"
		filter {}
		
end

function SetStaticLib( )
	kind "StaticLib"
end

