CreateProject("GLFW")
SetStaticLib()
characterset("MBCS") 
includedirs { "%{prj.location}/include/", "%{prj.location}/include/GLFW/" }
buildoptions "-D _GLFW_WIN32"