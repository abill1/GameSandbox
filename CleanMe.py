# This Python script is used to remove files and directories
# created after a build.  

import os
import shutil

if __name__ == "__main__":
    print("Executing CleanMe.py ...")
    path = os.getcwd();

    buildDir = 'build'
    buildPath = os.path.join(path, buildDir)
    if os.path.exists(buildPath):
        print('Deleting Directory:', buildPath)
        shutil.rmtree(buildPath)

    vsDir = '.vs'
    vsPath = os.path.join(path, vsDir)
    if os.path.exists(vsPath):
        print('Deleting Directory:', vsPath)
        shutil.rmtree(vsPath)

    print("CleanMe.py complete.")
