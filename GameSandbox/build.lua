CreateProject("GameSandbox")
forceincludes { 
"%{wks.location}/MemoryTracker/Include/MemoryTracker.h", 
"%{wks.location}/ABFramework/Include/ABFramework.h" 
}
includedirs {
"%{wks.location}/Engine/",
"%{wks.location}/glm/", 
"%{wks.location}/GLFW/include/", 
"%{wks.location}/ABFramework/", 
"%{wks.location}/MemoryTracker/"
}
links {
"MemoryTracker", 
"ABFramework", 
"GLFW", 
"glm",
"Engine"
}
characterset("MBCS")