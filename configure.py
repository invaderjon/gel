# configure.py
# This short script obtains the dependencies required to configure CMake, builds them,
# and places them in the proper location in project directory structure.
import platform
import os
from conf.package import *

# Create necessary working directories
if not os.path.isdir('lib'):
    os.makedirs('lib')

# Dependency googletest
if not installGit('.config', 'lib', 'googletest', 'https://github.com/google/googletest', r'(.*\.a)|(.*\.lib)', 'googletest'):
    sys.exit('Failed to get gtest')

# Configuration complete
print 'Configuration complete'
os.chdir('..')
