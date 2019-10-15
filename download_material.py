"""
    
    If supposed to be crossplatform 
    solution. Python is crossplatform
    so to download the material all
    you need is to run this python 
    script. This script will choose 
    the right routine for your operating 
    system.

"""

import platform
import subprocess
import sys


if __name__ == "__main__":
    if platform.system() == 'Linux':
        subprocess.call(
            [
                'sh',
                'download_material.sh'
            ],
            stdout=sys.stdout,
            stderr=sys.stderr
        )
