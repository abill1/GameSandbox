import os
import sys
import subprocess

if __name__ == "__main__":
    subprocess.run(("./Vendor/bin/premake/premake5.exe", "vs2019"))