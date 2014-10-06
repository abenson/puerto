solution "puerto"
   configurations { "Debug", "Release" }

project "puerto"
   kind "ConsoleApp"
   language "C"
   files { "src/**.h", "src/**.c" }

   configuration "Debug"
      flags { "Symbols" }
      defines { "_DEBUG" }

   configuration "Release"
      flags { "Optimize" }
      defines { "NDEBUG" }

