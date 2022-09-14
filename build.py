import os
import platform


if platform.system() == "Linux":
	print("Building Makefile...")
	success = os.system("./Vendor/Premake5/premake5 gmake2")
elif platform.system() == "Windows":
	print("Building Visual Studio 2022 Solution...")
	success = os.system("Vendor\Premake5\premake5.exe vs2022")

if success != 0:
	print("An Error occurred")
quit()