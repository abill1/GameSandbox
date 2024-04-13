CreateProject("Engine")
SetStaticLib()
forceincludes { 
 
}
includedirs {
"%{wks.location}/Engine/Vendor/",
}
libdirs {
	"%{wks.location}/build/bin/%{cfg.architecture}-%{cfg.buildcfg}/",
	"%{wks.location}/Engine/Vendor/libs/"
}
links {
	"opengl32.lib",
	"SDL2.lib",
	"SDL2main.lib"
}
