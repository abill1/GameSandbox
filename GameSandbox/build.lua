CreateProject("GameSandbox")
forceincludes { 

}
includedirs {
	"%{wks.location}/Engine/Vendor/"
}
links {
	"opengl32.lib",
	"SDL2.lib",
	"SDL2main.lib",
	"Engine"
}
libdirs {
	"%{wks.location}/build/bin/%{cfg.architecture}-%{cfg.buildcfg}/",
	"%{wks.location}/Engine/Vendor/libs/"
}
dependson  {"Engine"}

postbuildcommands {
	"{COPY} %[%{wks.location}/Engine/Vendor/libs/*.dll] %[%{wks.location}/GameSandbox/]",
	"{COPY} %[%{wks.location}/Engine/Vendor/libs/*.dll] %[%{wks.location}/build/bin/%{cfg.architecture}-%{cfg.buildcfg}/]",
	"{COPY} %[%{wks.location}/Engine/Vendor/libs/*.lib] %[%{wks.location}/build/bin/%{cfg.architecture}-%{cfg.buildcfg}/]",

}

