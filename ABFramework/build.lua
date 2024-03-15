CreateProject("ABFramework")
SetStaticLib()
forceincludes { "%{wks.location}/MemoryTracker/Include/MemoryTracker.h" }
links "MemoryTracker"