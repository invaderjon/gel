# io.py
# Provides io util functions
import os
import re
from shutil import copyfile

# Lists the files in a directory that match a pattern
def listDir(path, pattern=None):
    matched = []
    files = os.listdir(path)
    
    if pattern == None:
        return files
    
    for f in files:
        if re.match(pattern, f) != None:
            matched.append(f)
    
    return matched

# Copies the files from a source to a destination, overwriting files if they 
# already exists. This function does not copy subdirectories or their contents.
# This does nothing if the specified source is not a directory.
def copyDir(src, dest, pattern=None):
    files = []
    if os.path.isdir(src):
        if not os.path.isdir(dest):
            os.makedirs(dest)
        files = listDir(src, pattern)
    for f in files:
        copyfile(os.path.join(src, f), os.path.join(dest, f))

# Recursively copies from a source to a destination, overwriting files if they
# already exist.
def copyTree(src, dest, pattern=None):
    if os.path.isdir(src):
        if not os.path.isdir(dest):
            os.makedirs(dest)
        files = listDir(src, pattern)
    else:
        files = []
        copyfile(src, dest)
    for f in files:
        copyTree(os.path.join(src, f), os.path.join(dest, f), pattern)
