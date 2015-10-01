import os
import platform
from subprocess import call
from io_util import *


# Prints out system information
def start():
    print "Target Platform: ", platform.system(), platform.release()
    print "Configuration starting"

# Prepares the project for auto configuration.
def prepare():
    if not os.path.isdir('lib'):
        os.makedirs('lib')


# Installs a standardly formatted git repository to the specified directory.
# workingDir the working directory
# targetDir the target directory to install to
# name the name of the project
# repo the git repository url
# pattern is the regex pattern to search for when copying the build files
# subDir is the subdirectory in the repository to change navigate to before building
def installGit(workingDir, targetDir, name, repo, pattern=None, subDir=None):
    print 'Obtaining: ', name
    
    # Change to working directory
    if not os.path.isdir(workingDir):
        os.makedirs(workingDir)
    os.chdir(workingDir)
    baseDir = '..'

    # Clone/Update Repository
    success = 0
    if not os.path.isdir(name):
        success = call(['git', 'clone', repo])
    
    if success != 0:
        print 'Failed to clone repository'
        return False
    
    os.chdir(name)
    baseDir = os.path.join(baseDir, '..')
    
    success = call(['git', 'pull'])
    if success != 0:
        print 'Failed to update repository'
        return False
    
    if subDir != None:
        os.chdir(subDir)
        baseDir = os.path.join(baseDir, '..')
    
    # Copy Includes
    if os.path.isdir('include'):
        copyTree('include', os.path.join(baseDir, 'include'))
    
    # Build dependency
    if not os.path.isdir('build'):
        os.makedirs('build')
    
    os.chdir('build')
    baseDir = os.path.join(baseDir, '..')
    
    success = call(['cmake', '..'])
    if success != 0:
        print 'Failed to configure dependency'
        return False
    
    success = call(['make'])
    if success != 0:
        print 'Failed to build dependency'
        return False

    # Copy dependency
    copyDir(os.getcwd(), os.path.join(os.path.join(baseDir, targetDir), name), pattern)
    
    # Reset to default directory
    os.chdir(baseDir)
    
    print 'Acquired: ', name
    return True

